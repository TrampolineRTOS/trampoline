#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-0.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Class for element of '@gtlDataList' list                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlDataList : public cCollectionElement {
  public : GALGAS_gtlDataList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlDataList (const GALGAS_gtlData & in_data
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

cCollectionElement_gtlDataList::cCollectionElement_gtlDataList (const GALGAS_gtlData & in_data
                                                                COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_data) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlDataList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlDataList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlDataList (mObject.mAttribute_data COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlDataList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "data" ":" ;
  mObject.mAttribute_data.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlDataList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlDataList * operand = (cCollectionElement_gtlDataList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlDataList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList::GALGAS_gtlDataList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList::GALGAS_gtlDataList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlDataList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::constructor_listWithValue (const GALGAS_gtlData & inOperand0
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlDataList result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlDataList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                    const GALGAS_gtlData & in_data
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlDataList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlDataList (in_data COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::addAssign_operation (const GALGAS_gtlData & inOperand0
                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlDataList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::setter_insertAtIndex (const GALGAS_gtlData inOperand0,
                                               const GALGAS_uint inInsertionIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlDataList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::setter_removeAtIndex (GALGAS_gtlData & outOperand0,
                                               const GALGAS_uint inRemoveIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
      outOperand0 = p->mObject.mAttribute_data ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::setter_popFirst (GALGAS_gtlData & outOperand0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    outOperand0 = p->mObject.mAttribute_data ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::setter_popLast (GALGAS_gtlData & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    outOperand0 = p->mObject.mAttribute_data ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::method_first (GALGAS_gtlData & outOperand0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    outOperand0 = p->mObject.mAttribute_data ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::method_last (GALGAS_gtlData & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    outOperand0 = p->mObject.mAttribute_data ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::add_operation (const GALGAS_gtlDataList & inOperand,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlDataList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_gtlDataList result = GALGAS_gtlDataList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_gtlDataList result = GALGAS_gtlDataList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlDataList result = GALGAS_gtlDataList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList::plusAssign_operation (const GALGAS_gtlDataList inOperand,
                                               C_Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData GALGAS_gtlDataList::getter_dataAtIndex (const GALGAS_uint & inIndex,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  GALGAS_gtlData result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    result = p->mObject.mAttribute_data ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlDataList::cEnumerator_gtlDataList (const GALGAS_gtlDataList & inEnumeratedObject,
                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList_2D_element cEnumerator_gtlDataList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlDataList * p = (const cCollectionElement_gtlDataList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData cEnumerator_gtlDataList::current_data (LOCATION_ARGS) const {
  const cCollectionElement_gtlDataList * p = (const cCollectionElement_gtlDataList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
  return p->mObject.mAttribute_data ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlDataList type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDataList ("gtlDataList",
                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlDataList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDataList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlDataList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDataList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlDataList::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlDataList result ;
  const GALGAS_gtlDataList * p = (const GALGAS_gtlDataList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlDataList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDataList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlVarMap::cMapElement_gtlVarMap (const GALGAS_lstring & inKey,
                                              const GALGAS_gtlData & in_value
                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlVarMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlVarMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlVarMap (mAttribute_lkey, mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlVarMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlVarMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlVarMap * operand = (cMapElement_gtlVarMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (operand->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap::GALGAS_gtlVarMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap::GALGAS_gtlVarMap (const GALGAS_gtlVarMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap & GALGAS_gtlVarMap::operator = (const GALGAS_gtlVarMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap GALGAS_gtlVarMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlVarMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap GALGAS_gtlVarMap::constructor_mapWithMapToOverride (const GALGAS_gtlVarMap & inMapToOverride
                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap GALGAS_gtlVarMap::getter_overriddenMap (C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap::addAssign_operation (const GALGAS_lstring & inKey,
                                            const GALGAS_gtlData & inArgument0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  cMapElement_gtlVarMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlVarMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlVarMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap::setter_put (GALGAS_lstring inKey,
                                   GALGAS_gtlData inArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
  cMapElement_gtlVarMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlVarMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a variable or field named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlVarMap_get = "there is no variable or field named '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap::method_get (GALGAS_lstring inKey,
                                   GALGAS_gtlData & outArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_gtlVarMap_get
                                                                                     COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlVarMap_getResult = "function did not return a value in '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap::method_getResult (GALGAS_lstring inKey,
                                         GALGAS_gtlData & outArgument0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_gtlVarMap_getResult
                                                                                     COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap::setter_del (GALGAS_lstring inKey,
                                   GALGAS_gtlData & outArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "there is no variable or field named '%K' to delete" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_gtlVarMap * p = (cMapElement_gtlVarMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData GALGAS_gtlVarMap::getter_valueForKey (const GALGAS_string & inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) attributes ;
  GALGAS_gtlData result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap::setter_setValueForKey (GALGAS_gtlData inAttributeValue,
                                              GALGAS_string inKey,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlVarMap * p = (cMapElement_gtlVarMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    p->mAttribute_value = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlVarMap * GALGAS_gtlVarMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                             const GALGAS_string & inKey
                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_gtlVarMap * result = (cMapElement_gtlVarMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlVarMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlVarMap::cEnumerator_gtlVarMap (const GALGAS_gtlVarMap & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap_2D_element cEnumerator_gtlVarMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlVarMap) ;
  return GALGAS_gtlVarMap_2D_element (p->mAttribute_lkey, p->mAttribute_value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlVarMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData cEnumerator_gtlVarMap::current_value (LOCATION_ARGS) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlVarMap) ;
  return p->mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @gtlVarMap type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarMap ("gtlVarMap",
                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlVarMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlVarMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap GALGAS_gtlVarMap::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarMap result ;
  const GALGAS_gtlVarMap * p = (const GALGAS_gtlVarMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlExpressionMap::cMapElement_gtlExpressionMap (const GALGAS_lstring & inKey,
                                                            const GALGAS_gtlExpression & in_expression
                                                            COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_expression (in_expression) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlExpressionMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_expression.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlExpressionMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlExpressionMap (mAttribute_lkey, mAttribute_expression COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlExpressionMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "expression" ":" ;
  mAttribute_expression.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlExpressionMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlExpressionMap * operand = (cMapElement_gtlExpressionMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_expression.objectCompare (operand->mAttribute_expression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap::GALGAS_gtlExpressionMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap::GALGAS_gtlExpressionMap (const GALGAS_gtlExpressionMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap & GALGAS_gtlExpressionMap::operator = (const GALGAS_gtlExpressionMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlExpressionMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::constructor_mapWithMapToOverride (const GALGAS_gtlExpressionMap & inMapToOverride
                                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                   const GALGAS_gtlExpression & inArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cMapElement_gtlExpressionMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlExpressionMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlExpressionMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionMap::setter_put (GALGAS_lstring inKey,
                                          GALGAS_gtlExpression inArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_gtlExpressionMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlExpressionMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a field named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlExpressionMap_get = "there is no field named '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionMap::method_get (GALGAS_lstring inKey,
                                          GALGAS_gtlExpression & outArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) performSearch (inKey,
                                                                                                   inCompiler,
                                                                                                   kSearchErrorMessage_gtlExpressionMap_get
                                                                                                   COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    outArgument0 = p->mAttribute_expression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionMap::setter_del (GALGAS_lstring inKey,
                                          GALGAS_gtlExpression & outArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "there is no field named '%K' to delete" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_gtlExpressionMap * p = (cMapElement_gtlExpressionMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    outArgument0 = p->mAttribute_expression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlExpressionMap::getter_expressionForKey (const GALGAS_string & inKey,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) attributes ;
  GALGAS_gtlExpression result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    result = p->mAttribute_expression ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionMap::setter_setExpressionForKey (GALGAS_gtlExpression inAttributeValue,
                                                          GALGAS_string inKey,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlExpressionMap * p = (cMapElement_gtlExpressionMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    p->mAttribute_expression = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlExpressionMap * GALGAS_gtlExpressionMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) {
  cMapElement_gtlExpressionMap * result = (cMapElement_gtlExpressionMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlExpressionMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlExpressionMap::cEnumerator_gtlExpressionMap (const GALGAS_gtlExpressionMap & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap_2D_element cEnumerator_gtlExpressionMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
  return GALGAS_gtlExpressionMap_2D_element (p->mAttribute_lkey, p->mAttribute_expression) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlExpressionMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cEnumerator_gtlExpressionMap::current_expression (LOCATION_ARGS) const {
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
  return p->mAttribute_expression ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlExpressionMap type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpressionMap ("gtlExpressionMap",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlExpressionMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpressionMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlExpressionMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpressionMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionMap result ;
  const GALGAS_gtlExpressionMap * p = (const GALGAS_gtlExpressionMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExpressionMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExpressionMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Class for element of '@gtlInstructionList' list                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlInstructionList : public cCollectionElement {
  public : GALGAS_gtlInstructionList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlInstructionList (const GALGAS_gtlInstruction & in_instruction
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

cCollectionElement_gtlInstructionList::cCollectionElement_gtlInstructionList (const GALGAS_gtlInstruction & in_instruction
                                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_instruction) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlInstructionList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlInstructionList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlInstructionList (mObject.mAttribute_instruction COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlInstructionList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "instruction" ":" ;
  mObject.mAttribute_instruction.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlInstructionList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlInstructionList * operand = (cCollectionElement_gtlInstructionList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlInstructionList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList::GALGAS_gtlInstructionList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList::GALGAS_gtlInstructionList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlInstructionList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::constructor_listWithValue (const GALGAS_gtlInstruction & inOperand0
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionList result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlInstructionList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                           const GALGAS_gtlInstruction & in_instruction
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlInstructionList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlInstructionList (in_instruction COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::addAssign_operation (const GALGAS_gtlInstruction & inOperand0
                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlInstructionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::setter_insertAtIndex (const GALGAS_gtlInstruction inOperand0,
                                                      const GALGAS_uint inInsertionIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlInstructionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::setter_removeAtIndex (GALGAS_gtlInstruction & outOperand0,
                                                      const GALGAS_uint inRemoveIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
      outOperand0 = p->mObject.mAttribute_instruction ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::setter_popFirst (GALGAS_gtlInstruction & outOperand0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    outOperand0 = p->mObject.mAttribute_instruction ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::setter_popLast (GALGAS_gtlInstruction & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    outOperand0 = p->mObject.mAttribute_instruction ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::method_first (GALGAS_gtlInstruction & outOperand0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    outOperand0 = p->mObject.mAttribute_instruction ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::method_last (GALGAS_gtlInstruction & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    outOperand0 = p->mObject.mAttribute_instruction ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::add_operation (const GALGAS_gtlInstructionList & inOperand,
                                                                    C_Compiler * /* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result = GALGAS_gtlInstructionList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result = GALGAS_gtlInstructionList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result = GALGAS_gtlInstructionList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::plusAssign_operation (const GALGAS_gtlInstructionList inOperand,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionList::setter_setInstructionAtIndex (GALGAS_gtlInstruction inOperand,
                                                              GALGAS_uint inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) objectPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mAttribute_instruction = inOperand ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstruction GALGAS_gtlInstructionList::getter_instructionAtIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  GALGAS_gtlInstruction result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    result = p->mObject.mAttribute_instruction ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlInstructionList::cEnumerator_gtlInstructionList (const GALGAS_gtlInstructionList & inEnumeratedObject,
                                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList_2D_element cEnumerator_gtlInstructionList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlInstructionList * p = (const cCollectionElement_gtlInstructionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstruction cEnumerator_gtlInstructionList::current_instruction (LOCATION_ARGS) const {
  const cCollectionElement_gtlInstructionList * p = (const cCollectionElement_gtlInstructionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
  return p->mObject.mAttribute_instruction ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlInstructionList type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInstructionList ("gtlInstructionList",
                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlInstructionList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInstructionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlInstructionList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInstructionList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionList result ;
  const GALGAS_gtlInstructionList * p = (const GALGAS_gtlInstructionList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlInstructionList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInstructionList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlTemplateMap::cMapElement_gtlTemplateMap (const GALGAS_lstring & inKey,
                                                        const GALGAS_gtlTemplate & in_aTemplate
                                                        COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_aTemplate (in_aTemplate) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlTemplateMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_aTemplate.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlTemplateMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlTemplateMap (mAttribute_lkey, mAttribute_aTemplate COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlTemplateMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "aTemplate" ":" ;
  mAttribute_aTemplate.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlTemplateMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlTemplateMap * operand = (cMapElement_gtlTemplateMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_aTemplate.objectCompare (operand->mAttribute_aTemplate) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap::GALGAS_gtlTemplateMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap::GALGAS_gtlTemplateMap (const GALGAS_gtlTemplateMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap & GALGAS_gtlTemplateMap::operator = (const GALGAS_gtlTemplateMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlTemplateMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::constructor_mapWithMapToOverride (const GALGAS_gtlTemplateMap & inMapToOverride
                                                                               COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTemplateMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTemplateMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                 const GALGAS_gtlTemplate & inArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_gtlTemplateMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlTemplateMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlTemplateMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTemplateMap::setter_put (GALGAS_lstring inKey,
                                        GALGAS_gtlTemplate inArgument0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  cMapElement_gtlTemplateMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlTemplateMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a template at path '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlTemplateMap_get = "there is no template at path '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTemplateMap::method_get (GALGAS_lstring inKey,
                                        GALGAS_gtlTemplate & outArgument0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) performSearch (inKey,
                                                                                               inCompiler,
                                                                                               kSearchErrorMessage_gtlTemplateMap_get
                                                                                               COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
    outArgument0 = p->mAttribute_aTemplate ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplate GALGAS_gtlTemplateMap::getter_aTemplateForKey (const GALGAS_string & inKey,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) attributes ;
  GALGAS_gtlTemplate result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
    result = p->mAttribute_aTemplate ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTemplateMap::setter_setATemplateForKey (GALGAS_gtlTemplate inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlTemplateMap * p = (cMapElement_gtlTemplateMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
    p->mAttribute_aTemplate = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlTemplateMap * GALGAS_gtlTemplateMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) {
  cMapElement_gtlTemplateMap * result = (cMapElement_gtlTemplateMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlTemplateMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlTemplateMap::cEnumerator_gtlTemplateMap (const GALGAS_gtlTemplateMap & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap_2D_element cEnumerator_gtlTemplateMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
  return GALGAS_gtlTemplateMap_2D_element (p->mAttribute_lkey, p->mAttribute_aTemplate) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlTemplateMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplate cEnumerator_gtlTemplateMap::current_aTemplate (LOCATION_ARGS) const {
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
  return p->mAttribute_aTemplate ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @gtlTemplateMap type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTemplateMap ("gtlTemplateMap",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlTemplateMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlTemplateMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTemplateMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateMap result ;
  const GALGAS_gtlTemplateMap * p = (const GALGAS_gtlTemplateMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTemplateMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTemplateMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlFuncMap::cMapElement_gtlFuncMap (const GALGAS_lstring & inKey,
                                                const GALGAS_gtlFunction & in_function
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_function (in_function) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlFuncMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_function.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlFuncMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlFuncMap (mAttribute_lkey, mAttribute_function COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlFuncMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "function" ":" ;
  mAttribute_function.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlFuncMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlFuncMap * operand = (cMapElement_gtlFuncMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_function.objectCompare (operand->mAttribute_function) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap::GALGAS_gtlFuncMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap::GALGAS_gtlFuncMap (const GALGAS_gtlFuncMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap & GALGAS_gtlFuncMap::operator = (const GALGAS_gtlFuncMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlFuncMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::constructor_mapWithMapToOverride (const GALGAS_gtlFuncMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_gtlFuncMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_gtlFuncMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlFuncMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_gtlFunction & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_gtlFuncMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlFuncMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlFuncMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlFuncMap::setter_put (GALGAS_lstring inKey,
                                    GALGAS_gtlFunction inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_gtlFuncMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlFuncMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a function named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlFuncMap_get = "there is no function named '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlFuncMap::method_get (GALGAS_lstring inKey,
                                    GALGAS_gtlFunction & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) performSearch (inKey,
                                                                                       inCompiler,
                                                                                       kSearchErrorMessage_gtlFuncMap_get
                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
    outArgument0 = p->mAttribute_function ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunction GALGAS_gtlFuncMap::getter_functionForKey (const GALGAS_string & inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) attributes ;
  GALGAS_gtlFunction result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
    result = p->mAttribute_function ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlFuncMap::setter_setFunctionForKey (GALGAS_gtlFunction inAttributeValue,
                                                  GALGAS_string inKey,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlFuncMap * p = (cMapElement_gtlFuncMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
    p->mAttribute_function = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlFuncMap * GALGAS_gtlFuncMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_gtlFuncMap * result = (cMapElement_gtlFuncMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlFuncMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlFuncMap::cEnumerator_gtlFuncMap (const GALGAS_gtlFuncMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap_2D_element cEnumerator_gtlFuncMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
  return GALGAS_gtlFuncMap_2D_element (p->mAttribute_lkey, p->mAttribute_function) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlFuncMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunction cEnumerator_gtlFuncMap::current_function (LOCATION_ARGS) const {
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
  return p->mAttribute_function ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlFuncMap type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlFuncMap ("gtlFuncMap",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlFuncMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFuncMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlFuncMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlFuncMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlFuncMap result ;
  const GALGAS_gtlFuncMap * p = (const GALGAS_gtlFuncMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlFuncMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlFuncMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlGetterMap::cMapElement_gtlGetterMap (const GALGAS_lstring & inKey,
                                                    const GALGAS_gtlGetter & in_theGetter
                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_theGetter (in_theGetter) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlGetterMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_theGetter.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlGetterMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlGetterMap (mAttribute_lkey, mAttribute_theGetter COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlGetterMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "theGetter" ":" ;
  mAttribute_theGetter.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlGetterMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlGetterMap * operand = (cMapElement_gtlGetterMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_theGetter.objectCompare (operand->mAttribute_theGetter) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap::GALGAS_gtlGetterMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap::GALGAS_gtlGetterMap (const GALGAS_gtlGetterMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap & GALGAS_gtlGetterMap::operator = (const GALGAS_gtlGetterMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlGetterMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::constructor_mapWithMapToOverride (const GALGAS_gtlGetterMap & inMapToOverride
                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetterMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::getter_overriddenMap (C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_gtlGetterMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlGetterMap::addAssign_operation (const GALGAS_lstring & inKey,
                                               const GALGAS_gtlGetter & inArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cMapElement_gtlGetterMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlGetterMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlGetterMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlGetterMap::setter_put (GALGAS_lstring inKey,
                                      GALGAS_gtlGetter inArgument0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  cMapElement_gtlGetterMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlGetterMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a getter named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlGetterMap_get = "there is no getter named '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlGetterMap::method_get (GALGAS_lstring inKey,
                                      GALGAS_gtlGetter & outArgument0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) performSearch (inKey,
                                                                                           inCompiler,
                                                                                           kSearchErrorMessage_gtlGetterMap_get
                                                                                           COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
    outArgument0 = p->mAttribute_theGetter ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetter GALGAS_gtlGetterMap::getter_theGetterForKey (const GALGAS_string & inKey,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) attributes ;
  GALGAS_gtlGetter result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
    result = p->mAttribute_theGetter ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlGetterMap::setter_setTheGetterForKey (GALGAS_gtlGetter inAttributeValue,
                                                     GALGAS_string inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlGetterMap * p = (cMapElement_gtlGetterMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
    p->mAttribute_theGetter = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlGetterMap * GALGAS_gtlGetterMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                   const GALGAS_string & inKey
                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_gtlGetterMap * result = (cMapElement_gtlGetterMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlGetterMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlGetterMap::cEnumerator_gtlGetterMap (const GALGAS_gtlGetterMap & inEnumeratedObject,
                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap_2D_element cEnumerator_gtlGetterMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
  return GALGAS_gtlGetterMap_2D_element (p->mAttribute_lkey, p->mAttribute_theGetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlGetterMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetter cEnumerator_gtlGetterMap::current_theGetter (LOCATION_ARGS) const {
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
  return p->mAttribute_theGetter ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @gtlGetterMap type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGetterMap ("gtlGetterMap",
                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlGetterMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetterMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlGetterMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGetterMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetterMap result ;
  const GALGAS_gtlGetterMap * p = (const GALGAS_gtlGetterMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlGetterMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGetterMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlSetterMap::cMapElement_gtlSetterMap (const GALGAS_lstring & inKey,
                                                    const GALGAS_gtlSetter & in_theSetter
                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_theSetter (in_theSetter) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlSetterMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_theSetter.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlSetterMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlSetterMap (mAttribute_lkey, mAttribute_theSetter COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlSetterMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "theSetter" ":" ;
  mAttribute_theSetter.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlSetterMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlSetterMap * operand = (cMapElement_gtlSetterMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_theSetter.objectCompare (operand->mAttribute_theSetter) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap::GALGAS_gtlSetterMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap::GALGAS_gtlSetterMap (const GALGAS_gtlSetterMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap & GALGAS_gtlSetterMap::operator = (const GALGAS_gtlSetterMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlSetterMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::constructor_mapWithMapToOverride (const GALGAS_gtlSetterMap & inMapToOverride
                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetterMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::getter_overriddenMap (C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_gtlSetterMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlSetterMap::addAssign_operation (const GALGAS_lstring & inKey,
                                               const GALGAS_gtlSetter & inArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cMapElement_gtlSetterMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlSetterMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlSetterMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlSetterMap::setter_put (GALGAS_lstring inKey,
                                      GALGAS_gtlSetter inArgument0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  cMapElement_gtlSetterMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlSetterMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a setter named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlSetterMap_get = "there is no setter named '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlSetterMap::method_get (GALGAS_lstring inKey,
                                      GALGAS_gtlSetter & outArgument0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) performSearch (inKey,
                                                                                           inCompiler,
                                                                                           kSearchErrorMessage_gtlSetterMap_get
                                                                                           COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
    outArgument0 = p->mAttribute_theSetter ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetter GALGAS_gtlSetterMap::getter_theSetterForKey (const GALGAS_string & inKey,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) attributes ;
  GALGAS_gtlSetter result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
    result = p->mAttribute_theSetter ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlSetterMap::setter_setTheSetterForKey (GALGAS_gtlSetter inAttributeValue,
                                                     GALGAS_string inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlSetterMap * p = (cMapElement_gtlSetterMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
    p->mAttribute_theSetter = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlSetterMap * GALGAS_gtlSetterMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                   const GALGAS_string & inKey
                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_gtlSetterMap * result = (cMapElement_gtlSetterMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlSetterMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlSetterMap::cEnumerator_gtlSetterMap (const GALGAS_gtlSetterMap & inEnumeratedObject,
                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap_2D_element cEnumerator_gtlSetterMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
  return GALGAS_gtlSetterMap_2D_element (p->mAttribute_lkey, p->mAttribute_theSetter) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlSetterMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetter cEnumerator_gtlSetterMap::current_theSetter (LOCATION_ARGS) const {
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
  return p->mAttribute_theSetter ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @gtlSetterMap type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSetterMap ("gtlSetterMap",
                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlSetterMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSetterMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlSetterMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSetterMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetterMap result ;
  const GALGAS_gtlSetterMap * p = (const GALGAS_gtlSetterMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlSetterMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSetterMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Class for element of '@gtlVarPath' list                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlVarPath : public cCollectionElement {
  public : GALGAS_gtlVarPath_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlVarPath (const GALGAS_gtlVarItem & in_item
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

cCollectionElement_gtlVarPath::cCollectionElement_gtlVarPath (const GALGAS_gtlVarItem & in_item
                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_item) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlVarPath::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlVarPath::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlVarPath (mObject.mAttribute_item COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlVarPath::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "item" ":" ;
  mObject.mAttribute_item.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlVarPath::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlVarPath * operand = (cCollectionElement_gtlVarPath *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlVarPath) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath::GALGAS_gtlVarPath (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath::GALGAS_gtlVarPath (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlVarPath result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::constructor_listWithValue (const GALGAS_gtlVarItem & inOperand0
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarPath result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlVarPath::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                   const GALGAS_gtlVarItem & in_item
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlVarPath * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlVarPath (in_item COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::addAssign_operation (const GALGAS_gtlVarItem & inOperand0
                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlVarPath (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::setter_insertAtIndex (const GALGAS_gtlVarItem inOperand0,
                                              const GALGAS_uint inInsertionIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlVarPath (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::setter_removeAtIndex (GALGAS_gtlVarItem & outOperand0,
                                              const GALGAS_uint inRemoveIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
      outOperand0 = p->mObject.mAttribute_item ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::setter_popFirst (GALGAS_gtlVarItem & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::setter_popLast (GALGAS_gtlVarItem & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::method_first (GALGAS_gtlVarItem & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::method_last (GALGAS_gtlVarItem & outOperand0,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::add_operation (const GALGAS_gtlVarPath & inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::getter_subListWithRange (const GALGAS_range & inRange,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result = GALGAS_gtlVarPath::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result = GALGAS_gtlVarPath::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result = GALGAS_gtlVarPath::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarPath::plusAssign_operation (const GALGAS_gtlVarPath inOperand,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItem GALGAS_gtlVarPath::getter_itemAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  GALGAS_gtlVarItem result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    result = p->mObject.mAttribute_item ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlVarPath::cEnumerator_gtlVarPath (const GALGAS_gtlVarPath & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath_2D_element cEnumerator_gtlVarPath::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlVarPath * p = (const cCollectionElement_gtlVarPath *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarItem cEnumerator_gtlVarPath::current_item (LOCATION_ARGS) const {
  const cCollectionElement_gtlVarPath * p = (const cCollectionElement_gtlVarPath *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
  return p->mObject.mAttribute_item ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlVarPath type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarPath ("gtlVarPath",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlVarPath::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarPath ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlVarPath::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarPath (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarPath GALGAS_gtlVarPath::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarPath result ;
  const GALGAS_gtlVarPath * p = (const GALGAS_gtlVarPath *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarPath *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarPath", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Class for element of '@gtlExpressionList' list                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlExpressionList : public cCollectionElement {
  public : GALGAS_gtlExpressionList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlExpressionList (const GALGAS_gtlExpression & in_expression
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

cCollectionElement_gtlExpressionList::cCollectionElement_gtlExpressionList (const GALGAS_gtlExpression & in_expression
                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_expression) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlExpressionList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlExpressionList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlExpressionList (mObject.mAttribute_expression COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlExpressionList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "expression" ":" ;
  mObject.mAttribute_expression.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlExpressionList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlExpressionList * operand = (cCollectionElement_gtlExpressionList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlExpressionList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList::GALGAS_gtlExpressionList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList::GALGAS_gtlExpressionList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlExpressionList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::constructor_listWithValue (const GALGAS_gtlExpression & inOperand0
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionList result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlExpressionList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                          const GALGAS_gtlExpression & in_expression
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlExpressionList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlExpressionList (in_expression COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::addAssign_operation (const GALGAS_gtlExpression & inOperand0
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlExpressionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::setter_insertAtIndex (const GALGAS_gtlExpression inOperand0,
                                                     const GALGAS_uint inInsertionIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlExpressionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::setter_removeAtIndex (GALGAS_gtlExpression & outOperand0,
                                                     const GALGAS_uint inRemoveIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
      outOperand0 = p->mObject.mAttribute_expression ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::setter_popFirst (GALGAS_gtlExpression & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    outOperand0 = p->mObject.mAttribute_expression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::setter_popLast (GALGAS_gtlExpression & outOperand0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    outOperand0 = p->mObject.mAttribute_expression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::method_first (GALGAS_gtlExpression & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    outOperand0 = p->mObject.mAttribute_expression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::method_last (GALGAS_gtlExpression & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    outOperand0 = p->mObject.mAttribute_expression ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::add_operation (const GALGAS_gtlExpressionList & inOperand,
                                                                  C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result = GALGAS_gtlExpressionList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result = GALGAS_gtlExpressionList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result = GALGAS_gtlExpressionList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList::plusAssign_operation (const GALGAS_gtlExpressionList inOperand,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlExpressionList::getter_expressionAtIndex (const GALGAS_uint & inIndex,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  GALGAS_gtlExpression result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    result = p->mObject.mAttribute_expression ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlExpressionList::cEnumerator_gtlExpressionList (const GALGAS_gtlExpressionList & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList_2D_element cEnumerator_gtlExpressionList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlExpressionList * p = (const cCollectionElement_gtlExpressionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cEnumerator_gtlExpressionList::current_expression (LOCATION_ARGS) const {
  const cCollectionElement_gtlExpressionList * p = (const cCollectionElement_gtlExpressionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
  return p->mObject.mAttribute_expression ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlExpressionList type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpressionList ("gtlExpressionList",
                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlExpressionList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpressionList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlExpressionList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpressionList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionList result ;
  const GALGAS_gtlExpressionList * p = (const GALGAS_gtlExpressionList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExpressionList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExpressionList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Class for element of '@gtlTypedArgumentList' list                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlTypedArgumentList : public cCollectionElement {
  public : GALGAS_gtlTypedArgumentList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlTypedArgumentList (const GALGAS_type & in_type
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

cCollectionElement_gtlTypedArgumentList::cCollectionElement_gtlTypedArgumentList (const GALGAS_type & in_type
                                                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_type) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlTypedArgumentList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlTypedArgumentList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlTypedArgumentList (mObject.mAttribute_type COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlTypedArgumentList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "type" ":" ;
  mObject.mAttribute_type.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlTypedArgumentList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlTypedArgumentList * operand = (cCollectionElement_gtlTypedArgumentList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlTypedArgumentList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList::GALGAS_gtlTypedArgumentList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList::GALGAS_gtlTypedArgumentList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::constructor_listWithValue (const GALGAS_type & inOperand0
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlTypedArgumentList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                             const GALGAS_type & in_type
                                                             COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlTypedArgumentList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlTypedArgumentList (in_type COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::addAssign_operation (const GALGAS_type & inOperand0
                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlTypedArgumentList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::setter_insertAtIndex (const GALGAS_type inOperand0,
                                                        const GALGAS_uint inInsertionIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlTypedArgumentList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::setter_removeAtIndex (GALGAS_type & outOperand0,
                                                        const GALGAS_uint inRemoveIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
      outOperand0 = p->mObject.mAttribute_type ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::setter_popFirst (GALGAS_type & outOperand0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    outOperand0 = p->mObject.mAttribute_type ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::setter_popLast (GALGAS_type & outOperand0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    outOperand0 = p->mObject.mAttribute_type ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::method_first (GALGAS_type & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    outOperand0 = p->mObject.mAttribute_type ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::method_last (GALGAS_type & outOperand0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    outOperand0 = p->mObject.mAttribute_type ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::add_operation (const GALGAS_gtlTypedArgumentList & inOperand,
                                                                        C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlTypedArgumentList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTypedArgumentList result = GALGAS_gtlTypedArgumentList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTypedArgumentList result = GALGAS_gtlTypedArgumentList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTypedArgumentList result = GALGAS_gtlTypedArgumentList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTypedArgumentList::plusAssign_operation (const GALGAS_gtlTypedArgumentList inOperand,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type GALGAS_gtlTypedArgumentList::getter_typeAtIndex (const GALGAS_uint & inIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  GALGAS_type result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    result = p->mObject.mAttribute_type ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlTypedArgumentList::cEnumerator_gtlTypedArgumentList (const GALGAS_gtlTypedArgumentList & inEnumeratedObject,
                                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList_2D_element cEnumerator_gtlTypedArgumentList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlTypedArgumentList * p = (const cCollectionElement_gtlTypedArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type cEnumerator_gtlTypedArgumentList::current_type (LOCATION_ARGS) const {
  const cCollectionElement_gtlTypedArgumentList * p = (const cCollectionElement_gtlTypedArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
  return p->mObject.mAttribute_type ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlTypedArgumentList type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTypedArgumentList ("gtlTypedArgumentList",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlTypedArgumentList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTypedArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlTypedArgumentList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTypedArgumentList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result ;
  const GALGAS_gtlTypedArgumentList * p = (const GALGAS_gtlTypedArgumentList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTypedArgumentList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTypedArgumentList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Class for element of '@list' list                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_list : public cCollectionElement {
  public : GALGAS_list_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_list (const GALGAS_gtlData & in_value
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

cCollectionElement_list::cCollectionElement_list (const GALGAS_gtlData & in_value
                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_list::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_list::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_list (mObject.mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_list::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_list::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_list * operand = (cCollectionElement_list *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_list) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list::GALGAS_list (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list::GALGAS_list (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_list result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::constructor_listWithValue (const GALGAS_gtlData & inOperand0
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_list result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_list::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                             const GALGAS_gtlData & in_value
                                             COMMA_LOCATION_ARGS) {
  cCollectionElement_list * p = NULL ;
  macroMyNew (p, cCollectionElement_list (in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::addAssign_operation (const GALGAS_gtlData & inOperand0
                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::setter_insertAtIndex (const GALGAS_gtlData inOperand0,
                                        const GALGAS_uint inInsertionIndex,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::setter_removeAtIndex (GALGAS_gtlData & outOperand0,
                                        const GALGAS_uint inRemoveIndex,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_list) ;
      outOperand0 = p->mObject.mAttribute_value ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::setter_popFirst (GALGAS_gtlData & outOperand0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_list) ;
    outOperand0 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::setter_popLast (GALGAS_gtlData & outOperand0,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_list) ;
    outOperand0 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::method_first (GALGAS_gtlData & outOperand0,
                                C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_list) ;
    outOperand0 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::method_last (GALGAS_gtlData & outOperand0,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_list) ;
    outOperand0 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::add_operation (const GALGAS_list & inOperand,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_list result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::getter_subListWithRange (const GALGAS_range & inRange,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_list result = GALGAS_list::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_list result = GALGAS_list::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GALGAS_list result = GALGAS_list::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::plusAssign_operation (const GALGAS_list inOperand,
                                        C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list::setter_setValueAtIndex (GALGAS_gtlData inOperand,
                                              GALGAS_uint inIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cCollectionElement_list * p = (cCollectionElement_list *) objectPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_list) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mAttribute_value = inOperand ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData GALGAS_list::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  GALGAS_gtlData result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_list) ;
    result = p->mObject.mAttribute_value ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_list::cEnumerator_list (const GALGAS_list & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list_2D_element cEnumerator_list::current (LOCATION_ARGS) const {
  const cCollectionElement_list * p = (const cCollectionElement_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_list) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData cEnumerator_list::current_value (LOCATION_ARGS) const {
  const cCollectionElement_list * p = (const cCollectionElement_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_list) ;
  return p->mObject.mAttribute_value ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                     @list type                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_list ("list",
                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_list::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_list ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_list::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_list (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list GALGAS_list::extractObject (const GALGAS_object & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_list result ;
  const GALGAS_list * p = (const GALGAS_list *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_list *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("list", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
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

cTokenFor_gtl_5F_scanner::cTokenFor_gtl_5F_scanner (void) :
mLexicalAttribute_a_5F_string (),
mLexicalAttribute_charValue (),
mLexicalAttribute_floatValue (),
mLexicalAttribute_functionContent (),
mLexicalAttribute_identifierString (),
mLexicalAttribute_intValue (),
mLexicalAttribute_tokenString (),
mLexicalAttribute_uint_33__32_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

C_Lexique_gtl_5F_scanner::C_Lexique_gtl_5F_scanner (C_Compiler * inCallerCompiler,
                                                    const C_String & inDependencyFileExtension,
                                                    const C_String & inDependencyFilePath,
                                                    const C_String & inSourceFileName
                                                    COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inDependencyFileExtension, inDependencyFilePath, inSourceFileName COMMA_THERE),
mMatchedTemplateDelimiterIndex (-1) {
}

//---------------------------------------------------------------------------------------------------------------------*

C_Lexique_gtl_5F_scanner::C_Lexique_gtl_5F_scanner (C_Compiler * inCallerCompiler,
                                                    const C_String & inSourceString,
                                                    const C_String & inStringForError
                                                    COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE),
mMatchedTemplateDelimiterIndex (-1) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                 I N D E X I N G    D I R E C T O R Y                                                                *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::indexingDirectory (void) const {
  return "" ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                        Lexical error message list                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

static const char * gLexicalMessage_gtl_5F_scanner_floatNumberConversionError = "invalid float number" ;

static const char * gLexicalMessage_gtl_5F_scanner_incorrectCharConstant = "incorrect literal character" ;

static const char * gLexicalMessage_gtl_5F_scanner_incorrectHTMLescapeSequence = "Invalid HTML sequence, should be '&...;'" ;

static const char * gLexicalMessage_gtl_5F_scanner_internalError = "internal error" ;

static const char * gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 = "\\u should be followed by exactly four hexadecimal digits" ;

static const char * gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 = "\\U should be followed by exactly eight hexadecimal digits" ;

static const char * gLexicalMessage_gtl_5F_scanner_unassignedUnicodeValue = "this value does not correspond to an assigned Unicode point" ;

static const char * gLexicalMessage_gtl_5F_scanner_unknownHTMLescapeSequence = "Invalid &...; HTML sequence" ;

static const char * gLexicalMessage_gtl_5F_scanner_unterminatedLitteralString = "Unterminated literal string" ;

//---------------------------------------------------------------------------------------------------------------------*
//          Syntax error messages, for every terminal symbol                                                           *
//---------------------------------------------------------------------------------------------------------------------*

//--- Syntax error message for terminal '$identifier$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_identifier = "an identifier" ;

//--- Syntax error message for terminal '$literal_enum$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_literal_5F_enum = "a literal enum value" ;

//--- Syntax error message for terminal '$literal_double$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_literal_5F_double = "a float number" ;

//--- Syntax error message for terminal '$signed_literal_integer_bigint$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_signed_5F_literal_5F_integer_5F_bigint = "a bigint decimal number" ;

//--- Syntax error message for terminal '$-$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2D_ = "the - delimitor" ;

//--- Syntax error message for terminal '$.$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2E_ = "the '.' delimitor" ;

//--- Syntax error message for terminal '$.=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2E__3D_ = "the '.=' delimitor" ;

//--- Syntax error message for terminal '$...$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2E__2E__2E_ = "the '...' delimitor" ;

//--- Syntax error message for terminal '$literal_char$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_literal_5F_char = "a character constant" ;

//--- Syntax error message for terminal '$string$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_string = "literal string" ;

//--- Syntax error message for terminal '$comment$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_comment = "a comment" ;

//--- Syntax error message for terminal '$after$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_after = "the 'after' keyword" ;

//--- Syntax error message for terminal '$before$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_before = "the 'before' keyword" ;

//--- Syntax error message for terminal '$between$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_between = "the 'between' keyword" ;

//--- Syntax error message for terminal '$by$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_by = "the 'by' keyword" ;

//--- Syntax error message for terminal '$default$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_default = "the 'default' keyword" ;

//--- Syntax error message for terminal '$display$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_display = "the 'display' keyword" ;

//--- Syntax error message for terminal '$do$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_do = "the 'do' keyword" ;

//--- Syntax error message for terminal '$down$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_down = "the 'down' keyword" ;

//--- Syntax error message for terminal '$else$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_else = "the 'else' keyword" ;

//--- Syntax error message for terminal '$elsif$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_elsif = "the 'elsif' keyword" ;

//--- Syntax error message for terminal '$emptylist$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_emptylist = "the 'emptylist' keyword" ;

//--- Syntax error message for terminal '$emptymap$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_emptymap = "the 'emptymap' keyword" ;

//--- Syntax error message for terminal '$end$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_end = "the 'end' keyword" ;

//--- Syntax error message for terminal '$error$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_error = "the 'error' keyword" ;

//--- Syntax error message for terminal '$exists$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_exists = "the 'exists' keyword" ;

//--- Syntax error message for terminal '$false$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_false = "the 'false' keyword" ;

//--- Syntax error message for terminal '$for$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_for = "the 'for' keyword" ;

//--- Syntax error message for terminal '$foreach$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_foreach = "the 'foreach' keyword" ;

//--- Syntax error message for terminal '$from$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_from = "the 'from' keyword" ;

//--- Syntax error message for terminal '$func$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_func = "the 'func' keyword" ;

//--- Syntax error message for terminal '$here$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_here = "the 'here' keyword" ;

//--- Syntax error message for terminal '$if$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_if = "the 'if' keyword" ;

//--- Syntax error message for terminal '$in$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_in = "the 'in' keyword" ;

//--- Syntax error message for terminal '$import$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_import = "the 'import' keyword" ;

//--- Syntax error message for terminal '$listof$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_listof = "the 'listof' keyword" ;

//--- Syntax error message for terminal '$let$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_let = "the 'let' keyword" ;

//--- Syntax error message for terminal '$loop$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_loop = "the 'loop' keyword" ;

//--- Syntax error message for terminal '$mapof$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_mapof = "the 'mapof' keyword" ;

//--- Syntax error message for terminal '$mod$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_mod = "the 'mod' keyword" ;

//--- Syntax error message for terminal '$no$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_no = "the 'no' keyword" ;

//--- Syntax error message for terminal '$not$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_not = "the 'not' keyword" ;

//--- Syntax error message for terminal '$or$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_or = "the 'or' keyword" ;

//--- Syntax error message for terminal '$print$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_print = "the 'print' keyword" ;

//--- Syntax error message for terminal '$println$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_println = "the 'println' keyword" ;

//--- Syntax error message for terminal '$repeat$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_repeat = "the 'repeat' keyword" ;

//--- Syntax error message for terminal '$sort$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_sort = "the 'sort' keyword" ;

//--- Syntax error message for terminal '$step$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_step = "the 'step' keyword" ;

//--- Syntax error message for terminal '$tab$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_tab = "the 'tab' keyword" ;

//--- Syntax error message for terminal '$template$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_template = "the 'template' keyword" ;

//--- Syntax error message for terminal '$then$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_then = "the 'then' keyword" ;

//--- Syntax error message for terminal '$to$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_to = "the 'to' keyword" ;

//--- Syntax error message for terminal '$true$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_true = "the 'true' keyword" ;

//--- Syntax error message for terminal '$typeof$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_typeof = "the 'typeof' keyword" ;

//--- Syntax error message for terminal '$up$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_up = "the 'up' keyword" ;

//--- Syntax error message for terminal '$yes$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_yes = "the 'yes' keyword" ;

//--- Syntax error message for terminal '$warning$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_warning = "the 'warning' keyword" ;

//--- Syntax error message for terminal '$while$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_while = "the 'while' keyword" ;

//--- Syntax error message for terminal '$write$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_write = "the 'write' keyword" ;

//--- Syntax error message for terminal '$executable$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_executable = "the 'executable' keyword" ;

//--- Syntax error message for terminal '$variables$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_variables = "the 'variables' keyword" ;

//--- Syntax error message for terminal '$getter$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_getter = "the 'getter' keyword" ;

//--- Syntax error message for terminal '$unlet$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_unlet = "the 'unlet' keyword" ;

//--- Syntax error message for terminal '$setter$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_setter = "the 'setter' keyword" ;

//--- Syntax error message for terminal '$libraries$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_libraries = "the 'libraries' keyword" ;

//--- Syntax error message for terminal '$input$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_input = "the 'input' keyword" ;

//--- Syntax error message for terminal '$break$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_break = "the 'break' keyword" ;

//--- Syntax error message for terminal '$*$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2A_ = "the '*' delimitor" ;

//--- Syntax error message for terminal '$|$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__7C_ = "the '|' delimitor" ;

//--- Syntax error message for terminal '$,$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2C_ = "the ',' delimitor" ;

//--- Syntax error message for terminal '$+$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2B_ = "the '+' delimitor" ;

//--- Syntax error message for terminal '$::$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3A__3A_ = "the '::' delimitor" ;

//--- Syntax error message for terminal '$>$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3E_ = "the '>' delimitor" ;

//--- Syntax error message for terminal '$:$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3A_ = "the ':' delimitor" ;

//--- Syntax error message for terminal '$($' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__28_ = "the '(' delimitor" ;

//--- Syntax error message for terminal '$)$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__29_ = "the ')' delimitor" ;

//--- Syntax error message for terminal '$->$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2D__3E_ = "the '->' delimitor" ;

//--- Syntax error message for terminal '$?$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3F_ = "the '\?' delimitor" ;

//--- Syntax error message for terminal '$==$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3D__3D_ = "the '==' delimitor" ;

//--- Syntax error message for terminal '$!$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__21_ = "the '!' delimitor" ;

//--- Syntax error message for terminal '$:=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3A__3D_ = "the ':=' delimitor" ;

//--- Syntax error message for terminal '$[$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__5B_ = "the '[' delimitor" ;

//--- Syntax error message for terminal '$]$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__5D_ = "the ']' delimitor" ;

//--- Syntax error message for terminal '$+=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2B__3D_ = "the '+=' delimitor" ;

//--- Syntax error message for terminal '$-=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2D__3D_ = "the '-=' delimitor" ;

//--- Syntax error message for terminal '$/$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2F_ = "the '/' delimitor" ;

//--- Syntax error message for terminal '$!=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__21__3D_ = "the '!=' delimitor" ;

//--- Syntax error message for terminal '$>=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3E__3D_ = "the '>=' delimitor" ;

//--- Syntax error message for terminal '$&$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__26_ = "the '&' delimitor" ;

//--- Syntax error message for terminal '$<=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3C__3D_ = "the '<=' delimitor" ;

//--- Syntax error message for terminal '${$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__7B_ = "the '{' delimitor" ;

//--- Syntax error message for terminal '$}$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__7D_ = "the '}' delimitor" ;

//--- Syntax error message for terminal '$<$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3C_ = "the '<' delimitor" ;

//--- Syntax error message for terminal '$^$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__5E_ = "the '^' delimitor" ;

//--- Syntax error message for terminal '$>>$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3E__3E_ = "the '>>' delimitor" ;

//--- Syntax error message for terminal '$~$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__7E_ = "the '~' delimitor" ;

//--- Syntax error message for terminal '$<-$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3C__2D_ = "the '<-' delimitor" ;

//--- Syntax error message for terminal '$<<$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3C__3C_ = "the '<<' delimitor" ;

//--- Syntax error message for terminal '$@$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__40_ = "the '@' delimitor" ;

//--- Syntax error message for terminal '$*=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2A__3D_ = "the '*=' delimitor" ;

//--- Syntax error message for terminal '$/=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__2F__3D_ = "the '/=' delimitor" ;

//--- Syntax error message for terminal '$&=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__26__3D_ = "the '&=' delimitor" ;

//--- Syntax error message for terminal '$|=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__7C__3D_ = "the '|=' delimitor" ;

//--- Syntax error message for terminal '$<<=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3C__3C__3D_ = "the '<<=' delimitor" ;

//--- Syntax error message for terminal '$>>=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__3E__3E__3D_ = "the '>>=' delimitor" ;

//--- Syntax error message for terminal '$mod=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner_mod_3D_ = "the 'mod=' delimitor" ;

//--- Syntax error message for terminal '$^=$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__5E__3D_ = "the '^=' delimitor" ;

//--- Syntax error message for terminal '$@[$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__40__5B_ = "the '@[' delimitor" ;

//--- Syntax error message for terminal '$@($' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__40__28_ = "the '@(' delimitor" ;

//--- Syntax error message for terminal '$@{$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__40__7B_ = "the '@{' delimitor" ;

//--- Syntax error message for terminal '$[!$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__5B__21_ = "the '[!' delimitor" ;

//--- Syntax error message for terminal '$@!$' :
static const char * gSyntaxErrorMessage_gtl_5F_scanner__40__21_ = "the '@!' delimitor" ;

//---------------------------------------------------------------------------------------------------------------------*
//                getMessageForTerminal                                                                                *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::getMessageForTerminal (const int16_t inTerminalIndex) const {
  static const char * syntaxErrorMessageArray [113] = {kEndOfSourceLexicalErrorMessage,
    gSyntaxErrorMessage_gtl_5F_scanner_identifier,
    gSyntaxErrorMessage_gtl_5F_scanner_literal_5F_enum,
    gSyntaxErrorMessage_gtl_5F_scanner_literal_5F_double,
    gSyntaxErrorMessage_gtl_5F_scanner_signed_5F_literal_5F_integer_5F_bigint,
    gSyntaxErrorMessage_gtl_5F_scanner__2D_,
    gSyntaxErrorMessage_gtl_5F_scanner__2E_,
    gSyntaxErrorMessage_gtl_5F_scanner__2E__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__2E__2E__2E_,
    gSyntaxErrorMessage_gtl_5F_scanner_literal_5F_char,
    gSyntaxErrorMessage_gtl_5F_scanner_string,
    gSyntaxErrorMessage_gtl_5F_scanner_comment,
    gSyntaxErrorMessage_gtl_5F_scanner_after,
    gSyntaxErrorMessage_gtl_5F_scanner_before,
    gSyntaxErrorMessage_gtl_5F_scanner_between,
    gSyntaxErrorMessage_gtl_5F_scanner_by,
    gSyntaxErrorMessage_gtl_5F_scanner_default,
    gSyntaxErrorMessage_gtl_5F_scanner_display,
    gSyntaxErrorMessage_gtl_5F_scanner_do,
    gSyntaxErrorMessage_gtl_5F_scanner_down,
    gSyntaxErrorMessage_gtl_5F_scanner_else,
    gSyntaxErrorMessage_gtl_5F_scanner_elsif,
    gSyntaxErrorMessage_gtl_5F_scanner_emptylist,
    gSyntaxErrorMessage_gtl_5F_scanner_emptymap,
    gSyntaxErrorMessage_gtl_5F_scanner_end,
    gSyntaxErrorMessage_gtl_5F_scanner_error,
    gSyntaxErrorMessage_gtl_5F_scanner_exists,
    gSyntaxErrorMessage_gtl_5F_scanner_false,
    gSyntaxErrorMessage_gtl_5F_scanner_for,
    gSyntaxErrorMessage_gtl_5F_scanner_foreach,
    gSyntaxErrorMessage_gtl_5F_scanner_from,
    gSyntaxErrorMessage_gtl_5F_scanner_func,
    gSyntaxErrorMessage_gtl_5F_scanner_here,
    gSyntaxErrorMessage_gtl_5F_scanner_if,
    gSyntaxErrorMessage_gtl_5F_scanner_in,
    gSyntaxErrorMessage_gtl_5F_scanner_import,
    gSyntaxErrorMessage_gtl_5F_scanner_listof,
    gSyntaxErrorMessage_gtl_5F_scanner_let,
    gSyntaxErrorMessage_gtl_5F_scanner_loop,
    gSyntaxErrorMessage_gtl_5F_scanner_mapof,
    gSyntaxErrorMessage_gtl_5F_scanner_mod,
    gSyntaxErrorMessage_gtl_5F_scanner_no,
    gSyntaxErrorMessage_gtl_5F_scanner_not,
    gSyntaxErrorMessage_gtl_5F_scanner_or,
    gSyntaxErrorMessage_gtl_5F_scanner_print,
    gSyntaxErrorMessage_gtl_5F_scanner_println,
    gSyntaxErrorMessage_gtl_5F_scanner_repeat,
    gSyntaxErrorMessage_gtl_5F_scanner_sort,
    gSyntaxErrorMessage_gtl_5F_scanner_step,
    gSyntaxErrorMessage_gtl_5F_scanner_tab,
    gSyntaxErrorMessage_gtl_5F_scanner_template,
    gSyntaxErrorMessage_gtl_5F_scanner_then,
    gSyntaxErrorMessage_gtl_5F_scanner_to,
    gSyntaxErrorMessage_gtl_5F_scanner_true,
    gSyntaxErrorMessage_gtl_5F_scanner_typeof,
    gSyntaxErrorMessage_gtl_5F_scanner_up,
    gSyntaxErrorMessage_gtl_5F_scanner_yes,
    gSyntaxErrorMessage_gtl_5F_scanner_warning,
    gSyntaxErrorMessage_gtl_5F_scanner_while,
    gSyntaxErrorMessage_gtl_5F_scanner_write,
    gSyntaxErrorMessage_gtl_5F_scanner_executable,
    gSyntaxErrorMessage_gtl_5F_scanner_variables,
    gSyntaxErrorMessage_gtl_5F_scanner_getter,
    gSyntaxErrorMessage_gtl_5F_scanner_unlet,
    gSyntaxErrorMessage_gtl_5F_scanner_setter,
    gSyntaxErrorMessage_gtl_5F_scanner_libraries,
    gSyntaxErrorMessage_gtl_5F_scanner_input,
    gSyntaxErrorMessage_gtl_5F_scanner_break,
    gSyntaxErrorMessage_gtl_5F_scanner__2A_,
    gSyntaxErrorMessage_gtl_5F_scanner__7C_,
    gSyntaxErrorMessage_gtl_5F_scanner__2C_,
    gSyntaxErrorMessage_gtl_5F_scanner__2B_,
    gSyntaxErrorMessage_gtl_5F_scanner__3A__3A_,
    gSyntaxErrorMessage_gtl_5F_scanner__3E_,
    gSyntaxErrorMessage_gtl_5F_scanner__3A_,
    gSyntaxErrorMessage_gtl_5F_scanner__28_,
    gSyntaxErrorMessage_gtl_5F_scanner__29_,
    gSyntaxErrorMessage_gtl_5F_scanner__2D__3E_,
    gSyntaxErrorMessage_gtl_5F_scanner__3F_,
    gSyntaxErrorMessage_gtl_5F_scanner__3D__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__21_,
    gSyntaxErrorMessage_gtl_5F_scanner__3A__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__5B_,
    gSyntaxErrorMessage_gtl_5F_scanner__5D_,
    gSyntaxErrorMessage_gtl_5F_scanner__2B__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__2D__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__2F_,
    gSyntaxErrorMessage_gtl_5F_scanner__21__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__3E__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__26_,
    gSyntaxErrorMessage_gtl_5F_scanner__3C__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__7B_,
    gSyntaxErrorMessage_gtl_5F_scanner__7D_,
    gSyntaxErrorMessage_gtl_5F_scanner__3C_,
    gSyntaxErrorMessage_gtl_5F_scanner__5E_,
    gSyntaxErrorMessage_gtl_5F_scanner__3E__3E_,
    gSyntaxErrorMessage_gtl_5F_scanner__7E_,
    gSyntaxErrorMessage_gtl_5F_scanner__3C__2D_,
    gSyntaxErrorMessage_gtl_5F_scanner__3C__3C_,
    gSyntaxErrorMessage_gtl_5F_scanner__40_,
    gSyntaxErrorMessage_gtl_5F_scanner__2A__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__2F__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__26__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__7C__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__3C__3C__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__3E__3E__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner_mod_3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__5E__3D_,
    gSyntaxErrorMessage_gtl_5F_scanner__40__5B_,
    gSyntaxErrorMessage_gtl_5F_scanner__40__28_,
    gSyntaxErrorMessage_gtl_5F_scanner__40__7B_,
    gSyntaxErrorMessage_gtl_5F_scanner__5B__21_,
    gSyntaxErrorMessage_gtl_5F_scanner__40__21_} ;
  return syntaxErrorMessageArray [inTerminalIndex] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                      U N I C O D E    S T R I N G S                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

//--- Unicode string for '$_A_$'
static const utf32 kUnicodeString_gtl_5F_scanner__A_ [] = {
  TO_UNICODE (10),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_21_$'
static const utf32 kUnicodeString_gtl_5F_scanner__21_ [] = {
  TO_UNICODE ('!'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_21__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__21__3D_ [] = {
  TO_UNICODE ('!'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_25_$'
static const utf32 kUnicodeString_gtl_5F_scanner__25_ [] = {
  TO_UNICODE ('%'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_$'
static const utf32 kUnicodeString_gtl_5F_scanner__26_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__26__3D_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_28_$'
static const utf32 kUnicodeString_gtl_5F_scanner__28_ [] = {
  TO_UNICODE ('('),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_29_$'
static const utf32 kUnicodeString_gtl_5F_scanner__29_ [] = {
  TO_UNICODE (')'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2A_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2A_ [] = {
  TO_UNICODE ('*'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2A__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2A__3D_ [] = {
  TO_UNICODE ('*'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2B_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2B__3D_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2C_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2C_ [] = {
  TO_UNICODE (','),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2D__3D_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__3E_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2D__3E_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2E__2E_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2E__2E_ [] = {
  TO_UNICODE ('.'),
  TO_UNICODE ('.'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2F_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__2F__3D_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_X$'
static const utf32 kUnicodeString_gtl_5F_scanner__30_X [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('X'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_x$'
static const utf32 kUnicodeString_gtl_5F_scanner__30_x [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('x'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3A_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A__3A_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3A__3A_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3A__3D_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3B_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3B_ [] = {
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3C_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__2D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3C__2D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('-'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3C_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3C__3C_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3C__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3C__3C__3D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('<'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3C__3D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3D__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3E_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3E__3D_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E__3E_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3E__3E_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E__3E__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3E__3E__3D_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE ('>'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3F_$'
static const utf32 kUnicodeString_gtl_5F_scanner__3F_ [] = {
  TO_UNICODE ('\?'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40_$'
static const utf32 kUnicodeString_gtl_5F_scanner__40_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40__21_$'
static const utf32 kUnicodeString_gtl_5F_scanner__40__21_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('!'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40__28_$'
static const utf32 kUnicodeString_gtl_5F_scanner__40__28_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('('),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40__5B_$'
static const utf32 kUnicodeString_gtl_5F_scanner__40__5B_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('['),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_40__7B_$'
static const utf32 kUnicodeString_gtl_5F_scanner__40__7B_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('{'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5B_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5B_ [] = {
  TO_UNICODE ('['),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5B__21_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5B__21_ [] = {
  TO_UNICODE ('['),
  TO_UNICODE ('!'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5C_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5C_ [] = {
  TO_UNICODE ('\\'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5C__25_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5C__25_ [] = {
  TO_UNICODE ('\\'),
  TO_UNICODE ('%'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5C__5C_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5C__5C_ [] = {
  TO_UNICODE ('\\'),
  TO_UNICODE ('\\'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5C_n$'
static const utf32 kUnicodeString_gtl_5F_scanner__5C_n [] = {
  TO_UNICODE ('\\'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5D_ [] = {
  TO_UNICODE (']'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5E_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5E_ [] = {
  TO_UNICODE ('^'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5E__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5E__3D_ [] = {
  TO_UNICODE ('^'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$after$'
static const utf32 kUnicodeString_gtl_5F_scanner_after [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('f'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$before$'
static const utf32 kUnicodeString_gtl_5F_scanner_before [] = {
  TO_UNICODE ('b'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$between$'
static const utf32 kUnicodeString_gtl_5F_scanner_between [] = {
  TO_UNICODE ('b'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE ('w'),
  TO_UNICODE ('e'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$break$'
static const utf32 kUnicodeString_gtl_5F_scanner_break [] = {
  TO_UNICODE ('b'),
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('a'),
  TO_UNICODE ('k'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$by$'
static const utf32 kUnicodeString_gtl_5F_scanner_by [] = {
  TO_UNICODE ('b'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$default$'
static const utf32 kUnicodeString_gtl_5F_scanner_default [] = {
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
static const utf32 kUnicodeString_gtl_5F_scanner_display [] = {
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
static const utf32 kUnicodeString_gtl_5F_scanner_do [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('o'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$down$'
static const utf32 kUnicodeString_gtl_5F_scanner_down [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('o'),
  TO_UNICODE ('w'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$else$'
static const utf32 kUnicodeString_gtl_5F_scanner_else [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$elsif$'
static const utf32 kUnicodeString_gtl_5F_scanner_elsif [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$emptylist$'
static const utf32 kUnicodeString_gtl_5F_scanner_emptylist [] = {
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
static const utf32 kUnicodeString_gtl_5F_scanner_emptymap [] = {
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
static const utf32 kUnicodeString_gtl_5F_scanner_end [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$error$'
static const utf32 kUnicodeString_gtl_5F_scanner_error [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$executable$'
static const utf32 kUnicodeString_gtl_5F_scanner_executable [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('e'),
  TO_UNICODE ('c'),
  TO_UNICODE ('u'),
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('b'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$exists$'
static const utf32 kUnicodeString_gtl_5F_scanner_exists [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$false$'
static const utf32 kUnicodeString_gtl_5F_scanner_false [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$for$'
static const utf32 kUnicodeString_gtl_5F_scanner_for [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$foreach$'
static const utf32 kUnicodeString_gtl_5F_scanner_foreach [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('h'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$from$'
static const utf32 kUnicodeString_gtl_5F_scanner_from [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('m'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$func$'
static const utf32 kUnicodeString_gtl_5F_scanner_func [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('u'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$getter$'
static const utf32 kUnicodeString_gtl_5F_scanner_getter [] = {
  TO_UNICODE ('g'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$here$'
static const utf32 kUnicodeString_gtl_5F_scanner_here [] = {
  TO_UNICODE ('h'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$if$'
static const utf32 kUnicodeString_gtl_5F_scanner_if [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$import$'
static const utf32 kUnicodeString_gtl_5F_scanner_import [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$in$'
static const utf32 kUnicodeString_gtl_5F_scanner_in [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$input$'
static const utf32 kUnicodeString_gtl_5F_scanner_input [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('p'),
  TO_UNICODE ('u'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$let$'
static const utf32 kUnicodeString_gtl_5F_scanner_let [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$libraries$'
static const utf32 kUnicodeString_gtl_5F_scanner_libraries [] = {
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

//--- Unicode string for '$listof$'
static const utf32 kUnicodeString_gtl_5F_scanner_listof [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('o'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$loop$'
static const utf32 kUnicodeString_gtl_5F_scanner_loop [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('o'),
  TO_UNICODE ('o'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$mapof$'
static const utf32 kUnicodeString_gtl_5F_scanner_mapof [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('o'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$mod$'
static const utf32 kUnicodeString_gtl_5F_scanner_mod [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('o'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$mod_3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner_mod_3D_ [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('o'),
  TO_UNICODE ('d'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$no$'
static const utf32 kUnicodeString_gtl_5F_scanner_no [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$not$'
static const utf32 kUnicodeString_gtl_5F_scanner_not [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$or$'
static const utf32 kUnicodeString_gtl_5F_scanner_or [] = {
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$print$'
static const utf32 kUnicodeString_gtl_5F_scanner_print [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$println$'
static const utf32 kUnicodeString_gtl_5F_scanner_println [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE ('l'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$repeat$'
static const utf32 kUnicodeString_gtl_5F_scanner_repeat [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$setter$'
static const utf32 kUnicodeString_gtl_5F_scanner_setter [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$sort$'
static const utf32 kUnicodeString_gtl_5F_scanner_sort [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$step$'
static const utf32 kUnicodeString_gtl_5F_scanner_step [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$tab$'
static const utf32 kUnicodeString_gtl_5F_scanner_tab [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('b'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$template$'
static const utf32 kUnicodeString_gtl_5F_scanner_template [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$then$'
static const utf32 kUnicodeString_gtl_5F_scanner_then [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('h'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$to$'
static const utf32 kUnicodeString_gtl_5F_scanner_to [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('o'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$true$'
static const utf32 kUnicodeString_gtl_5F_scanner_true [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$typeof$'
static const utf32 kUnicodeString_gtl_5F_scanner_typeof [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('o'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$unlet$'
static const utf32 kUnicodeString_gtl_5F_scanner_unlet [] = {
  TO_UNICODE ('u'),
  TO_UNICODE ('n'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$up$'
static const utf32 kUnicodeString_gtl_5F_scanner_up [] = {
  TO_UNICODE ('u'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$variables$'
static const utf32 kUnicodeString_gtl_5F_scanner_variables [] = {
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

//--- Unicode string for '$warning$'
static const utf32 kUnicodeString_gtl_5F_scanner_warning [] = {
  TO_UNICODE ('w'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE ('n'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('g'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$while$'
static const utf32 kUnicodeString_gtl_5F_scanner_while [] = {
  TO_UNICODE ('w'),
  TO_UNICODE ('h'),
  TO_UNICODE ('i'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$write$'
static const utf32 kUnicodeString_gtl_5F_scanner_write [] = {
  TO_UNICODE ('w'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$yes$'
static const utf32 kUnicodeString_gtl_5F_scanner_yes [] = {
  TO_UNICODE ('y'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7B_$'
static const utf32 kUnicodeString_gtl_5F_scanner__7B_ [] = {
  TO_UNICODE ('{'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7C_$'
static const utf32 kUnicodeString_gtl_5F_scanner__7C_ [] = {
  TO_UNICODE ('|'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7C__3D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__7C__3D_ [] = {
  TO_UNICODE ('|'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7D_$'
static const utf32 kUnicodeString_gtl_5F_scanner__7D_ [] = {
  TO_UNICODE ('}'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7E_$'
static const utf32 kUnicodeString_gtl_5F_scanner__7E_ [] = {
  TO_UNICODE ('~'),
  TO_UNICODE (0)
} ;

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'galgasDelimitorsList'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_gtl_5F_scanner_galgasDelimitorsList = 45 ;

static const C_unicode_lexique_table_entry ktable_for_gtl_5F_scanner_galgasDelimitorsList [ktable_size_gtl_5F_scanner_galgasDelimitorsList] = {
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__21_, 1, C_Lexique_gtl_5F_scanner::kToken__21_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__26_, 1, C_Lexique_gtl_5F_scanner::kToken__26_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__28_, 1, C_Lexique_gtl_5F_scanner::kToken__28_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__29_, 1, C_Lexique_gtl_5F_scanner::kToken__29_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2A_, 1, C_Lexique_gtl_5F_scanner::kToken__2A_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2B_, 1, C_Lexique_gtl_5F_scanner::kToken__2B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2C_, 1, C_Lexique_gtl_5F_scanner::kToken__2C_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2F_, 1, C_Lexique_gtl_5F_scanner::kToken__2F_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3A_, 1, C_Lexique_gtl_5F_scanner::kToken__3A_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3C_, 1, C_Lexique_gtl_5F_scanner::kToken__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3E_, 1, C_Lexique_gtl_5F_scanner::kToken__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3F_, 1, C_Lexique_gtl_5F_scanner::kToken__3F_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40_, 1, C_Lexique_gtl_5F_scanner::kToken__40_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5B_, 1, C_Lexique_gtl_5F_scanner::kToken__5B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5D_, 1, C_Lexique_gtl_5F_scanner::kToken__5D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5E_, 1, C_Lexique_gtl_5F_scanner::kToken__5E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__7B_, 1, C_Lexique_gtl_5F_scanner::kToken__7B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__7C_, 1, C_Lexique_gtl_5F_scanner::kToken__7C_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__7D_, 1, C_Lexique_gtl_5F_scanner::kToken__7D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__7E_, 1, C_Lexique_gtl_5F_scanner::kToken__7E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__21__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__21__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__26__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__26__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2A__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__2A__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2B__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__2B__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2D__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__2D__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2D__3E_, 2, C_Lexique_gtl_5F_scanner::kToken__2D__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__2F__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__2F__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3A__3A_, 2, C_Lexique_gtl_5F_scanner::kToken__3A__3A_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3A__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__3A__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3C__2D_, 2, C_Lexique_gtl_5F_scanner::kToken__3C__2D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3C__3C_, 2, C_Lexique_gtl_5F_scanner::kToken__3C__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3C__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__3C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3D__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__3D__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3E__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__3E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3E__3E_, 2, C_Lexique_gtl_5F_scanner::kToken__3E__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40__21_, 2, C_Lexique_gtl_5F_scanner::kToken__40__21_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40__28_, 2, C_Lexique_gtl_5F_scanner::kToken__40__28_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40__5B_, 2, C_Lexique_gtl_5F_scanner::kToken__40__5B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40__7B_, 2, C_Lexique_gtl_5F_scanner::kToken__40__7B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5B__21_, 2, C_Lexique_gtl_5F_scanner::kToken__5B__21_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5E__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__5E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__7C__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__7C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3C__3C__3D_, 3, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3E__3E__3D_, 3, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_mod_3D_, 4, C_Lexique_gtl_5F_scanner::kToken_mod_3D_)
} ;

int16_t C_Lexique_gtl_5F_scanner::search_into_galgasDelimitorsList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_gtl_5F_scanner_galgasDelimitorsList, ktable_size_gtl_5F_scanner_galgasDelimitorsList) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'goilTemplateKeyWordList'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_gtl_5F_scanner_goilTemplateKeyWordList = 56 ;

static const C_unicode_lexique_table_entry ktable_for_gtl_5F_scanner_goilTemplateKeyWordList [ktable_size_gtl_5F_scanner_goilTemplateKeyWordList] = {
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_by, 2, C_Lexique_gtl_5F_scanner::kToken_by),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_do, 2, C_Lexique_gtl_5F_scanner::kToken_do),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_if, 2, C_Lexique_gtl_5F_scanner::kToken_if),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_in, 2, C_Lexique_gtl_5F_scanner::kToken_in),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_no, 2, C_Lexique_gtl_5F_scanner::kToken_no),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_or, 2, C_Lexique_gtl_5F_scanner::kToken_or),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_to, 2, C_Lexique_gtl_5F_scanner::kToken_to),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_up, 2, C_Lexique_gtl_5F_scanner::kToken_up),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_end, 3, C_Lexique_gtl_5F_scanner::kToken_end),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_for, 3, C_Lexique_gtl_5F_scanner::kToken_for),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_let, 3, C_Lexique_gtl_5F_scanner::kToken_let),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_mod, 3, C_Lexique_gtl_5F_scanner::kToken_mod),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_not, 3, C_Lexique_gtl_5F_scanner::kToken_not),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_tab, 3, C_Lexique_gtl_5F_scanner::kToken_tab),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_yes, 3, C_Lexique_gtl_5F_scanner::kToken_yes),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_down, 4, C_Lexique_gtl_5F_scanner::kToken_down),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_else, 4, C_Lexique_gtl_5F_scanner::kToken_else),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_from, 4, C_Lexique_gtl_5F_scanner::kToken_from),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_func, 4, C_Lexique_gtl_5F_scanner::kToken_func),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_here, 4, C_Lexique_gtl_5F_scanner::kToken_here),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_loop, 4, C_Lexique_gtl_5F_scanner::kToken_loop),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_sort, 4, C_Lexique_gtl_5F_scanner::kToken_sort),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_step, 4, C_Lexique_gtl_5F_scanner::kToken_step),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_then, 4, C_Lexique_gtl_5F_scanner::kToken_then),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_true, 4, C_Lexique_gtl_5F_scanner::kToken_true),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_after, 5, C_Lexique_gtl_5F_scanner::kToken_after),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_break, 5, C_Lexique_gtl_5F_scanner::kToken_break),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_elsif, 5, C_Lexique_gtl_5F_scanner::kToken_elsif),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_error, 5, C_Lexique_gtl_5F_scanner::kToken_error),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_false, 5, C_Lexique_gtl_5F_scanner::kToken_false),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_input, 5, C_Lexique_gtl_5F_scanner::kToken_input),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_mapof, 5, C_Lexique_gtl_5F_scanner::kToken_mapof),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_print, 5, C_Lexique_gtl_5F_scanner::kToken_print),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_unlet, 5, C_Lexique_gtl_5F_scanner::kToken_unlet),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_while, 5, C_Lexique_gtl_5F_scanner::kToken_while),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_write, 5, C_Lexique_gtl_5F_scanner::kToken_write),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_before, 6, C_Lexique_gtl_5F_scanner::kToken_before),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_exists, 6, C_Lexique_gtl_5F_scanner::kToken_exists),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_getter, 6, C_Lexique_gtl_5F_scanner::kToken_getter),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_import, 6, C_Lexique_gtl_5F_scanner::kToken_import),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_listof, 6, C_Lexique_gtl_5F_scanner::kToken_listof),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_repeat, 6, C_Lexique_gtl_5F_scanner::kToken_repeat),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_setter, 6, C_Lexique_gtl_5F_scanner::kToken_setter),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_typeof, 6, C_Lexique_gtl_5F_scanner::kToken_typeof),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_between, 7, C_Lexique_gtl_5F_scanner::kToken_between),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_default, 7, C_Lexique_gtl_5F_scanner::kToken_default),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_display, 7, C_Lexique_gtl_5F_scanner::kToken_display),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_foreach, 7, C_Lexique_gtl_5F_scanner::kToken_foreach),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_println, 7, C_Lexique_gtl_5F_scanner::kToken_println),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_warning, 7, C_Lexique_gtl_5F_scanner::kToken_warning),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_emptymap, 8, C_Lexique_gtl_5F_scanner::kToken_emptymap),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_template, 8, C_Lexique_gtl_5F_scanner::kToken_template),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_emptylist, 9, C_Lexique_gtl_5F_scanner::kToken_emptylist),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_libraries, 9, C_Lexique_gtl_5F_scanner::kToken_libraries),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_variables, 9, C_Lexique_gtl_5F_scanner::kToken_variables),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_executable, 10, C_Lexique_gtl_5F_scanner::kToken_executable)
} ;

int16_t C_Lexique_gtl_5F_scanner::search_into_goilTemplateKeyWordList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_gtl_5F_scanner_goilTemplateKeyWordList, ktable_size_gtl_5F_scanner_goilTemplateKeyWordList) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                          getCurrentTokenString                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_gtl_5F_scanner * ptr = (const cTokenFor_gtl_5F_scanner *) inTokenPtr ;
  C_String s ;
  if (ptr == NULL) {
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
    case kToken_after:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("after") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_before:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("before") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_between:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("between") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_by:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("by") ;
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
    case kToken_down:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("down") ;
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
    case kToken_end:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("end") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_error:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("error") ;
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
    case kToken_for:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("for") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_foreach:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("foreach") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_from:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("from") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_func:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("func") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_here:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("here") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_if:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("if") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_in:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("in") ;
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
    case kToken_loop:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("loop") ;
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
    case kToken_println:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("println") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_repeat:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("repeat") ;
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
    case kToken_tab:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("tab") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_template:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("template") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_then:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("then") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_to:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("to") ;
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
    case kToken_up:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("up") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_yes:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("yes") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_warning:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("warning") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_while:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("while") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_write:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("write") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_executable:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("executable") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_variables:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("variables") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_getter:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("getter") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_unlet:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("unlet") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_setter:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("setter") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_libraries:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("libraries") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_input:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("input") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_break:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("break") ;
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

//---------------------------------------------------------------------------------------------------------------------*
//                           Template Delimiters                                                                       *
//---------------------------------------------------------------------------------------------------------------------*

static const cTemplateDelimiter kTemplateDefinitionArray [1] = {
  cTemplateDelimiter (kUnicodeString_gtl_5F_scanner__25_, 1, kUnicodeString_gtl_5F_scanner__25_, 1, NULL, true)
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                           Template Replacements                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const cTemplateDelimiter kTemplateReplacementArray [3] = {
  cTemplateDelimiter (kUnicodeString_gtl_5F_scanner__5C__25_, 2, kUnicodeString_gtl_5F_scanner__25_, 1, NULL, true),
  cTemplateDelimiter (kUnicodeString_gtl_5F_scanner__5C_n, 2, kUnicodeString_gtl_5F_scanner__A_, 1, NULL, true),
  cTemplateDelimiter (kUnicodeString_gtl_5F_scanner__5C__5C_, 2, kUnicodeString_gtl_5F_scanner__5C_, 1, NULL, true)
} ;

//---------------------------------------------------------------------------------------------------------------------*
//            Terminal Symbols as end of script in template mark                                                       *
//---------------------------------------------------------------------------------------------------------------------*

static const bool kEndOfScriptInTemplateArray [112] = {
  false /* identifier */,
  false /* literal_enum */,
  false /* literal_double */,
  false /* signed_literal_integer_bigint */,
  false /* - */,
  false /* . */,
  false /* .= */,
  false /* ... */,
  false /* literal_char */,
  false /* string */,
  false /* comment */,
  false /* after */,
  false /* before */,
  false /* between */,
  false /* by */,
  false /* default */,
  false /* display */,
  false /* do */,
  false /* down */,
  false /* else */,
  false /* elsif */,
  false /* emptylist */,
  false /* emptymap */,
  false /* end */,
  false /* error */,
  false /* exists */,
  false /* false */,
  false /* for */,
  false /* foreach */,
  false /* from */,
  false /* func */,
  false /* here */,
  false /* if */,
  false /* in */,
  false /* import */,
  false /* listof */,
  false /* let */,
  false /* loop */,
  false /* mapof */,
  false /* mod */,
  false /* no */,
  false /* not */,
  false /* or */,
  false /* print */,
  false /* println */,
  false /* repeat */,
  false /* sort */,
  false /* step */,
  false /* tab */,
  false /* template */,
  false /* then */,
  false /* to */,
  false /* true */,
  false /* typeof */,
  false /* up */,
  false /* yes */,
  false /* warning */,
  false /* while */,
  false /* write */,
  false /* executable */,
  false /* variables */,
  false /* getter */,
  false /* unlet */,
  false /* setter */,
  false /* libraries */,
  false /* input */,
  false /* break */,
  false /* * */,
  false /* | */,
  false /* , */,
  false /* + */,
  false /* :: */,
  false /* > */,
  false /* : */,
  false /* ( */,
  false /* ) */,
  false /* -> */,
  false /* ? */,
  false /* == */,
  false /* ! */,
  false /* := */,
  false /* [ */,
  false /* ] */,
  false /* += */,
  false /* -= */,
  false /* / */,
  false /* != */,
  false /* >= */,
  false /* & */,
  false /* <= */,
  false /* { */,
  false /* } */,
  false /* < */,
  false /* ^ */,
  false /* >> */,
  false /* ~ */,
  false /* <- */,
  false /* << */,
  false /* @ */,
  false /* *= */,
  false /* /= */,
  false /* &= */,
  false /* |= */,
  false /* <<= */,
  false /* >>= */,
  false /* mod= */,
  false /* ^= */,
  false /* @[ */,
  false /* @( */,
  false /* @{ */,
  false /* [! */,
  false /* @! */
} ;


//---------------------------------------------------------------------------------------------------------------------*
//               P A R S E    L E X I C A L    T O K E N                                                               *
//---------------------------------------------------------------------------------------------------------------------*

bool C_Lexique_gtl_5F_scanner::parseLexicalToken (void) {
  cTokenFor_gtl_5F_scanner token ;
  mLoop = true ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    if ((mMatchedTemplateDelimiterIndex >= 0)
     && (kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndStringLength > 0)
     && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      const bool foundEndDelimitor = testForInputUTF32String (kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndString,
                                                              kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndStringLength,
                                                              true) ;
      if (foundEndDelimitor) {
        mMatchedTemplateDelimiterIndex = -1 ;
      }
    }
    while ((mMatchedTemplateDelimiterIndex < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      int32_t replacementIndex = 0 ;
      while (replacementIndex >= 0) {
        replacementIndex = findTemplateDelimiterIndex (kTemplateReplacementArray, 3) ;
        if (replacementIndex >= 0) {
          if (kTemplateReplacementArray [replacementIndex].mReplacementFunction == NULL) {
            token.mTemplateStringBeforeToken << kTemplateReplacementArray [replacementIndex].mEndString ;
          }else{
            C_String s ;
            while (notTestForInputUTF32String (kTemplateReplacementArray [replacementIndex].mEndString,
                                               kTemplateReplacementArray [replacementIndex].mEndStringLength,
                                               kEndOfSourceLexicalErrorMessage
                                               COMMA_HERE)) {
              s.appendUnicodeCharacter (previousChar () COMMA_HERE) ;
            }
            kTemplateReplacementArray [replacementIndex].mReplacementFunction (*this, s, token.mTemplateStringBeforeToken) ;
          }
        }
      }
      mMatchedTemplateDelimiterIndex = findTemplateDelimiterIndex (kTemplateDefinitionArray, 1) ;
      if (mMatchedTemplateDelimiterIndex < 0) {
        token.mTemplateStringBeforeToken.appendUnicodeCharacter (mCurrentChar COMMA_HERE) ;
        advance () ;
      }
    }
    if ((mMatchedTemplateDelimiterIndex >= 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
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
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
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
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          token.mTokenCode = kToken_literal_5F_enum ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner_mod_3D_, 4, true)) {
          token.mTokenCode = kToken_mod_3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3E__3E__3D_, 3, true)) {
          token.mTokenCode = kToken__3E__3E__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3C__3C__3D_, 3, true)) {
          token.mTokenCode = kToken__3C__3C__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__7C__3D_, 2, true)) {
          token.mTokenCode = kToken__7C__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__5E__3D_, 2, true)) {
          token.mTokenCode = kToken__5E__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__5B__21_, 2, true)) {
          token.mTokenCode = kToken__5B__21_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__40__7B_, 2, true)) {
          token.mTokenCode = kToken__40__7B_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__40__5B_, 2, true)) {
          token.mTokenCode = kToken__40__5B_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__40__28_, 2, true)) {
          token.mTokenCode = kToken__40__28_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__40__21_, 2, true)) {
          token.mTokenCode = kToken__40__21_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3E__3E_, 2, true)) {
          token.mTokenCode = kToken__3E__3E_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3E__3D_, 2, true)) {
          token.mTokenCode = kToken__3E__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3D__3D_, 2, true)) {
          token.mTokenCode = kToken__3D__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3C__3D_, 2, true)) {
          token.mTokenCode = kToken__3C__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3C__3C_, 2, true)) {
          token.mTokenCode = kToken__3C__3C_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3C__2D_, 2, true)) {
          token.mTokenCode = kToken__3C__2D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3A__3D_, 2, true)) {
          token.mTokenCode = kToken__3A__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3A__3A_, 2, true)) {
          token.mTokenCode = kToken__3A__3A_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2F__3D_, 2, true)) {
          token.mTokenCode = kToken__2F__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2D__3E_, 2, true)) {
          token.mTokenCode = kToken__2D__3E_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2D__3D_, 2, true)) {
          token.mTokenCode = kToken__2D__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2B__3D_, 2, true)) {
          token.mTokenCode = kToken__2B__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2A__3D_, 2, true)) {
          token.mTokenCode = kToken__2A__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__26__3D_, 2, true)) {
          token.mTokenCode = kToken__26__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__21__3D_, 2, true)) {
          token.mTokenCode = kToken__21__3D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__7E_, 1, true)) {
          token.mTokenCode = kToken__7E_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__7D_, 1, true)) {
          token.mTokenCode = kToken__7D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__7C_, 1, true)) {
          token.mTokenCode = kToken__7C_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__7B_, 1, true)) {
          token.mTokenCode = kToken__7B_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__5E_, 1, true)) {
          token.mTokenCode = kToken__5E_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__5D_, 1, true)) {
          token.mTokenCode = kToken__5D_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__5B_, 1, true)) {
          token.mTokenCode = kToken__5B_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__40_, 1, true)) {
          token.mTokenCode = kToken__40_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3F_, 1, true)) {
          token.mTokenCode = kToken__3F_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3E_, 1, true)) {
          token.mTokenCode = kToken__3E_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3C_, 1, true)) {
          token.mTokenCode = kToken__3C_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3A_, 1, true)) {
          token.mTokenCode = kToken__3A_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2F_, 1, true)) {
          token.mTokenCode = kToken__2F_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2C_, 1, true)) {
          token.mTokenCode = kToken__2C_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2B_, 1, true)) {
          token.mTokenCode = kToken__2B_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2A_, 1, true)) {
          token.mTokenCode = kToken__2A_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__29_, 1, true)) {
          token.mTokenCode = kToken__29_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__28_, 1, true)) {
          token.mTokenCode = kToken__28_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__26_, 1, true)) {
          token.mTokenCode = kToken__26_ ;
          enterToken (token) ;
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__21_, 1, true)) {
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
                mLoop = false ;
              }
            }while (mLoop) ;
            mLoop = true ;
            if (testForInputUTF32Char (TO_UNICODE ('.'))) {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('.')) ;
              do {
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
                  ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
                }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
                }else{
                  mLoop = false ;
                }
              }while (mLoop) ;
              mLoop = true ;
              ::scanner_routine_convertStringToDouble (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_floatValue, gLexicalMessage_gtl_5F_scanner_floatNumberConversionError) ;
              token.mTokenCode = kToken_literal_5F_double ;
              enterToken (token) ;
            }else{
              ::scanner_routine_convertDecimalStringIntoBigInt (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_intValue, gLexicalMessage_gtl_5F_scanner_internalError) ;
              token.mTokenCode = kToken_signed_5F_literal_5F_integer_5F_bigint ;
              enterToken (token) ;
            }
          }else{
            token.mTokenCode = kToken__2D_ ;
            enterToken (token) ;
          }
        }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__30_x, 2, true) || testForInputUTF32String (kUnicodeString_gtl_5F_scanner__30_X, 2, true)) {
          do {
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          ::scanner_routine_convertHexStringIntoBigInt (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_intValue, gLexicalMessage_gtl_5F_scanner_internalError) ;
          token.mTokenCode = kToken_signed_5F_literal_5F_integer_5F_bigint ;
          enterToken (token) ;
        }else if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
          do {
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
            }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          if (testForInputUTF32Char (TO_UNICODE ('.'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('.')) ;
            do {
              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
              }else{
                mLoop = false ;
              }
            }while (mLoop) ;
            mLoop = true ;
            ::scanner_routine_convertStringToDouble (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_floatValue, gLexicalMessage_gtl_5F_scanner_floatNumberConversionError) ;
            token.mTokenCode = kToken_literal_5F_double ;
            enterToken (token) ;
          }else{
            ::scanner_routine_convertDecimalStringIntoBigInt (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_intValue, gLexicalMessage_gtl_5F_scanner_internalError) ;
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
                mLoop = false ;
              }
            }while (mLoop) ;
            mLoop = true ;
            ::scanner_routine_convertStringToDouble (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_floatValue, gLexicalMessage_gtl_5F_scanner_floatNumberConversionError) ;
            token.mTokenCode = kToken_literal_5F_double ;
            enterToken (token) ;
          }else{
            if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__2E__2E_, 2, true)) {
              token.mTokenCode = kToken__2E__2E__2E_ ;
              enterToken (token) ;
            }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__3D_, 1, true)) {
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
                ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                  ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                  if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                    ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                    if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                      ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                      ::scanner_routine_convertUnsignedNumberToUnicodeChar (*this, token.mLexicalAttribute_uint_33__32_value, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_scanner_unassignedUnicodeValue) ;
                    }else{
                      lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                    }
                  }else{
                    lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                  }
                }else{
                  lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                }
              }else{
                lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
              }
            }else if (testForInputUTF32Char (TO_UNICODE ('U'))) {
              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                  ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                  if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                    ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                    if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                      ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                      if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                        ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                          ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                            ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                              ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                              ::scanner_routine_convertUnsignedNumberToUnicodeChar (*this, token.mLexicalAttribute_uint_33__32_value, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_scanner_unassignedUnicodeValue) ;
                            }else{
                              lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                            }
                          }else{
                            lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                          }
                        }else{
                          lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                        }
                      }else{
                        lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                      }
                    }else{
                      lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                    }
                  }else{
                    lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                  }
                }else{
                  lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                }
              }else{
                lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
              }
            }else if (testForInputUTF32Char (TO_UNICODE ('&'))) {
              do {
                if (notTestForInputUTF32String (kUnicodeString_gtl_5F_scanner__3B_, 1, gLexicalMessage_gtl_5F_scanner_incorrectHTMLescapeSequence COMMA_LINE_AND_SOURCE_FILE)) {
                  ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
                }else{
                  mLoop = false ;
                }
              }while (mLoop) ;
              mLoop = true ;
              ::scanner_routine_convertHTMLSequenceToUnicodeCharacter (*this, token.mLexicalAttribute_tokenString, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_scanner_unknownHTMLescapeSequence) ;
            }else{
              lexicalError (gLexicalMessage_gtl_5F_scanner_incorrectCharConstant COMMA_LINE_AND_SOURCE_FILE) ;
            }
          }else if (testForInputUTF32CharRange (TO_UNICODE (' '), TO_UNICODE (65533))) {
            ::scanner_routine_enterCharacterIntoCharacter (*this, token.mLexicalAttribute_charValue, previousChar ()) ;
          }else{
            lexicalError (gLexicalMessage_gtl_5F_scanner_incorrectCharConstant COMMA_LINE_AND_SOURCE_FILE) ;
          }
          if (testForInputUTF32Char (TO_UNICODE ('\''))) {
            token.mTokenCode = kToken_literal_5F_char ;
            enterToken (token) ;
          }else{
            lexicalError (gLexicalMessage_gtl_5F_scanner_incorrectCharConstant COMMA_LINE_AND_SOURCE_FILE) ;
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
                  if (notTestForInputUTF32String (kUnicodeString_gtl_5F_scanner__3B_, 1, gLexicalMessage_gtl_5F_scanner_incorrectHTMLescapeSequence COMMA_LINE_AND_SOURCE_FILE)) {
                    ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_identifierString, previousChar ()) ;
                  }else{
                    mLoop = false ;
                  }
                }while (mLoop) ;
                mLoop = true ;
                ::scanner_routine_convertHTMLSequenceToUnicodeCharacter (*this, token.mLexicalAttribute_identifierString, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_scanner_unknownHTMLescapeSequence) ;
                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, token.mLexicalAttribute_charValue) ;
              }else if (testForInputUTF32Char (TO_UNICODE ('u'))) {
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                  ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                  if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                    ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                    if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                      ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                      if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                        ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                        ::scanner_routine_convertUnsignedNumberToUnicodeChar (*this, token.mLexicalAttribute_uint_33__32_value, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_scanner_unassignedUnicodeValue) ;
                        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, token.mLexicalAttribute_charValue) ;
                      }else{
                        lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                      }
                    }else{
                      lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                    }
                  }else{
                    lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                  }
                }else{
                  lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 COMMA_LINE_AND_SOURCE_FILE) ;
                }
              }else if (testForInputUTF32Char (TO_UNICODE ('U'))) {
                if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                  ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                  if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                    ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                    if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                      ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                      if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                        ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                          ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                            ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                              ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
                                ::scanner_routine_enterHexDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_uint_33__32_value, gLexicalMessage_gtl_5F_scanner_internalError, gLexicalMessage_gtl_5F_scanner_internalError) ;
                                ::scanner_routine_convertUnsignedNumberToUnicodeChar (*this, token.mLexicalAttribute_uint_33__32_value, token.mLexicalAttribute_charValue, gLexicalMessage_gtl_5F_scanner_unassignedUnicodeValue) ;
                                ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, token.mLexicalAttribute_charValue) ;
                              }else{
                                lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                              }
                            }else{
                              lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                            }
                          }else{
                            lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                          }
                        }else{
                          lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                        }
                      }else{
                        lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                      }
                    }else{
                      lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                    }
                  }else{
                    lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                  }
                }else{
                  lexicalError (gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 COMMA_LINE_AND_SOURCE_FILE) ;
                }
              }else{
                lexicalError (gLexicalMessage_gtl_5F_scanner_incorrectCharConstant COMMA_LINE_AND_SOURCE_FILE) ;
              }
            }else if (testForInputUTF32Char (TO_UNICODE (' ')) || testForInputUTF32Char (TO_UNICODE ('!')) || testForInputUTF32CharRange (TO_UNICODE ('#'), TO_UNICODE (65533))) {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_a_5F_string, previousChar ()) ;
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
            token.mTokenCode = kToken_string ;
            enterToken (token) ;
          }else{
            lexicalError (gLexicalMessage_gtl_5F_scanner_unterminatedLitteralString COMMA_LINE_AND_SOURCE_FILE) ;
          }
        }else if (testForInputUTF32Char (TO_UNICODE ('#'))) {
          do {
            if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE ('\t')) || testForInputUTF32Char (TO_UNICODE ('\v')) || testForInputUTF32Char (TO_UNICODE ('\f')) || testForInputUTF32CharRange (TO_UNICODE (14), TO_UNICODE (65533))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          enterDroppedTerminal (kToken_comment) ;
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
    if ((token.mTokenCode > 0) && kEndOfScriptInTemplateArray [token.mTokenCode - 1]) {
      mMatchedTemplateDelimiterIndex = -1 ;
    }
  
  }
  if ((UNICODE_VALUE (mCurrentChar) == '\0') && (token.mTemplateStringBeforeToken.length () > 0)) {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         E N T E R    T O K E N                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

void C_Lexique_gtl_5F_scanner::enterToken (cTokenFor_gtl_5F_scanner & ioToken) {
  cTokenFor_gtl_5F_scanner * ptr = NULL ;
  macroMyNew (ptr, cTokenFor_gtl_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
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

//---------------------------------------------------------------------------------------------------------------------*
//               A T T R I B U T E   A C C E S S                                                                       *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::attributeValue_a_5F_string (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_a_5F_string ;
}

//---------------------------------------------------------------------------------------------------------------------*

utf32 C_Lexique_gtl_5F_scanner::attributeValue_charValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_charValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

double C_Lexique_gtl_5F_scanner::attributeValue_floatValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_floatValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::attributeValue_functionContent (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_functionContent ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::attributeValue_identifierString (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_identifierString ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BigInt C_Lexique_gtl_5F_scanner::attributeValue_intValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_intValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::attributeValue_tokenString (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_tokenString ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_Lexique_gtl_5F_scanner::attributeValue_uint_33__32_value (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_uint_33__32_value ;
}

//---------------------------------------------------------------------------------------------------------------------*
//         A S S I G N    F R O M    A T T R I B U T E                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_gtl_5F_scanner::synthetizedAttribute_a_5F_string (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_a_5F_string) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lchar C_Lexique_gtl_5F_scanner::synthetizedAttribute_charValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_char value (ptr->mLexicalAttribute_charValue) ;
  GALGAS_lchar result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ldouble C_Lexique_gtl_5F_scanner::synthetizedAttribute_floatValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_double value (ptr->mLexicalAttribute_floatValue) ;
  GALGAS_ldouble result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_gtl_5F_scanner::synthetizedAttribute_functionContent (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_functionContent) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_gtl_5F_scanner::synthetizedAttribute_identifierString (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_identifierString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lbigint C_Lexique_gtl_5F_scanner::synthetizedAttribute_intValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_bigint value (ptr->mLexicalAttribute_intValue) ;
  GALGAS_lbigint result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_gtl_5F_scanner::synthetizedAttribute_tokenString (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_tokenString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint C_Lexique_gtl_5F_scanner::synthetizedAttribute_uint_33__32_value (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint value (ptr->mLexicalAttribute_uint_33__32_value) ;
  GALGAS_luint result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         I N T R O S P E C T I O N                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist C_Lexique_gtl_5F_scanner::symbols (LOCATION_ARGS) {
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
  result.addAssign_operation (GALGAS_string ("after") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("before") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("between") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("by") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("default") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("display") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("do") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("down") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("else") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("elsif") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("emptylist") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("emptymap") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("end") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("error") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("exists") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("false") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("for") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("foreach") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("from") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("func") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("here") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("if") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("in") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("import") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("listof") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("let") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("loop") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("mapof") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("mod") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("no") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("not") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("or") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("print") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("println") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("repeat") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("sort") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("step") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("tab") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("template") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("then") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("to") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("true") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("typeof") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("up") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("yes") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("warning") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("while") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("write") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("executable") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("variables") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("getter") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("unlet") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("setter") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("libraries") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("input") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("break") COMMA_THERE) ;
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

//---------------------------------------------------------------------------------------------------------------------*

static void getKeywordLists_gtl_5F_scanner (TC_UniqueArray <C_String> & ioList) {
  ioList.addObject ("gtl_scanner:galgasDelimitorsList") ;
  ioList.addObject ("gtl_scanner:goilTemplateKeyWordList") ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void getKeywordsForIdentifier_gtl_5F_scanner (const C_String & inIdentifier,
                                                     bool & ioFound,
                                                     TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "gtl_scanner:galgasDelimitorsList") {
    ioFound = true ;
    ioList.addObject ("!") ;
    ioList.addObject ("&") ;
    ioList.addObject ("(") ;
    ioList.addObject (")") ;
    ioList.addObject ("*") ;
    ioList.addObject ("+") ;
    ioList.addObject (",") ;
    ioList.addObject ("/") ;
    ioList.addObject (":") ;
    ioList.addObject ("<") ;
    ioList.addObject (">") ;
    ioList.addObject ("\?") ;
    ioList.addObject ("@") ;
    ioList.addObject ("[") ;
    ioList.addObject ("]") ;
    ioList.addObject ("^") ;
    ioList.addObject ("{") ;
    ioList.addObject ("|") ;
    ioList.addObject ("}") ;
    ioList.addObject ("~") ;
    ioList.addObject ("!=") ;
    ioList.addObject ("&=") ;
    ioList.addObject ("*=") ;
    ioList.addObject ("+=") ;
    ioList.addObject ("-=") ;
    ioList.addObject ("->") ;
    ioList.addObject ("/=") ;
    ioList.addObject ("::") ;
    ioList.addObject (":=") ;
    ioList.addObject ("<-") ;
    ioList.addObject ("<<") ;
    ioList.addObject ("<=") ;
    ioList.addObject ("==") ;
    ioList.addObject (">=") ;
    ioList.addObject (">>") ;
    ioList.addObject ("@!") ;
    ioList.addObject ("@(") ;
    ioList.addObject ("@[") ;
    ioList.addObject ("@{") ;
    ioList.addObject ("[!") ;
    ioList.addObject ("^=") ;
    ioList.addObject ("|=") ;
    ioList.addObject ("<<=") ;
    ioList.addObject (">>=") ;
    ioList.addObject ("mod=") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "gtl_scanner:goilTemplateKeyWordList") {
    ioFound = true ;
    ioList.addObject ("by") ;
    ioList.addObject ("do") ;
    ioList.addObject ("if") ;
    ioList.addObject ("in") ;
    ioList.addObject ("no") ;
    ioList.addObject ("or") ;
    ioList.addObject ("to") ;
    ioList.addObject ("up") ;
    ioList.addObject ("end") ;
    ioList.addObject ("for") ;
    ioList.addObject ("let") ;
    ioList.addObject ("mod") ;
    ioList.addObject ("not") ;
    ioList.addObject ("tab") ;
    ioList.addObject ("yes") ;
    ioList.addObject ("down") ;
    ioList.addObject ("else") ;
    ioList.addObject ("from") ;
    ioList.addObject ("func") ;
    ioList.addObject ("here") ;
    ioList.addObject ("loop") ;
    ioList.addObject ("sort") ;
    ioList.addObject ("step") ;
    ioList.addObject ("then") ;
    ioList.addObject ("true") ;
    ioList.addObject ("after") ;
    ioList.addObject ("break") ;
    ioList.addObject ("elsif") ;
    ioList.addObject ("error") ;
    ioList.addObject ("false") ;
    ioList.addObject ("input") ;
    ioList.addObject ("mapof") ;
    ioList.addObject ("print") ;
    ioList.addObject ("unlet") ;
    ioList.addObject ("while") ;
    ioList.addObject ("write") ;
    ioList.addObject ("before") ;
    ioList.addObject ("exists") ;
    ioList.addObject ("getter") ;
    ioList.addObject ("import") ;
    ioList.addObject ("listof") ;
    ioList.addObject ("repeat") ;
    ioList.addObject ("setter") ;
    ioList.addObject ("typeof") ;
    ioList.addObject ("between") ;
    ioList.addObject ("default") ;
    ioList.addObject ("display") ;
    ioList.addObject ("foreach") ;
    ioList.addObject ("println") ;
    ioList.addObject ("warning") ;
    ioList.addObject ("emptymap") ;
    ioList.addObject ("template") ;
    ioList.addObject ("emptylist") ;
    ioList.addObject ("libraries") ;
    ioList.addObject ("variables") ;
    ioList.addObject ("executable") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static cLexiqueIntrospection lexiqueIntrospection_gtl_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_gtl_5F_scanner, getKeywordsForIdentifier_gtl_5F_scanner) ;

//---------------------------------------------------------------------------------------------------------------------*
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_Lexique_gtl_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [113] = {0,
    0 /* gtl_scanner_1_identifier */,
    0 /* gtl_scanner_1_literal_5F_enum */,
    5 /* gtl_scanner_1_literal_5F_double */,
    4 /* gtl_scanner_1_signed_5F_literal_5F_integer_5F_bigint */,
    2 /* gtl_scanner_1__2D_ */,
    2 /* gtl_scanner_1__2E_ */,
    2 /* gtl_scanner_1__2E__3D_ */,
    2 /* gtl_scanner_1__2E__2E__2E_ */,
    8 /* gtl_scanner_1_literal_5F_char */,
    6 /* gtl_scanner_1_string */,
    7 /* gtl_scanner_1_comment */,
    1 /* gtl_scanner_1_after */,
    1 /* gtl_scanner_1_before */,
    1 /* gtl_scanner_1_between */,
    1 /* gtl_scanner_1_by */,
    1 /* gtl_scanner_1_default */,
    1 /* gtl_scanner_1_display */,
    1 /* gtl_scanner_1_do */,
    1 /* gtl_scanner_1_down */,
    1 /* gtl_scanner_1_else */,
    1 /* gtl_scanner_1_elsif */,
    1 /* gtl_scanner_1_emptylist */,
    1 /* gtl_scanner_1_emptymap */,
    1 /* gtl_scanner_1_end */,
    1 /* gtl_scanner_1_error */,
    1 /* gtl_scanner_1_exists */,
    1 /* gtl_scanner_1_false */,
    1 /* gtl_scanner_1_for */,
    1 /* gtl_scanner_1_foreach */,
    1 /* gtl_scanner_1_from */,
    1 /* gtl_scanner_1_func */,
    1 /* gtl_scanner_1_here */,
    1 /* gtl_scanner_1_if */,
    1 /* gtl_scanner_1_in */,
    1 /* gtl_scanner_1_import */,
    1 /* gtl_scanner_1_listof */,
    1 /* gtl_scanner_1_let */,
    1 /* gtl_scanner_1_loop */,
    1 /* gtl_scanner_1_mapof */,
    1 /* gtl_scanner_1_mod */,
    1 /* gtl_scanner_1_no */,
    1 /* gtl_scanner_1_not */,
    1 /* gtl_scanner_1_or */,
    1 /* gtl_scanner_1_print */,
    1 /* gtl_scanner_1_println */,
    1 /* gtl_scanner_1_repeat */,
    1 /* gtl_scanner_1_sort */,
    1 /* gtl_scanner_1_step */,
    1 /* gtl_scanner_1_tab */,
    1 /* gtl_scanner_1_template */,
    1 /* gtl_scanner_1_then */,
    1 /* gtl_scanner_1_to */,
    1 /* gtl_scanner_1_true */,
    1 /* gtl_scanner_1_typeof */,
    1 /* gtl_scanner_1_up */,
    1 /* gtl_scanner_1_yes */,
    1 /* gtl_scanner_1_warning */,
    1 /* gtl_scanner_1_while */,
    1 /* gtl_scanner_1_write */,
    1 /* gtl_scanner_1_executable */,
    1 /* gtl_scanner_1_variables */,
    1 /* gtl_scanner_1_getter */,
    1 /* gtl_scanner_1_unlet */,
    1 /* gtl_scanner_1_setter */,
    1 /* gtl_scanner_1_libraries */,
    1 /* gtl_scanner_1_input */,
    1 /* gtl_scanner_1_break */,
    2 /* gtl_scanner_1__2A_ */,
    2 /* gtl_scanner_1__7C_ */,
    2 /* gtl_scanner_1__2C_ */,
    2 /* gtl_scanner_1__2B_ */,
    2 /* gtl_scanner_1__3A__3A_ */,
    2 /* gtl_scanner_1__3E_ */,
    2 /* gtl_scanner_1__3A_ */,
    2 /* gtl_scanner_1__28_ */,
    2 /* gtl_scanner_1__29_ */,
    2 /* gtl_scanner_1__2D__3E_ */,
    2 /* gtl_scanner_1__3F_ */,
    2 /* gtl_scanner_1__3D__3D_ */,
    2 /* gtl_scanner_1__21_ */,
    2 /* gtl_scanner_1__3A__3D_ */,
    2 /* gtl_scanner_1__5B_ */,
    2 /* gtl_scanner_1__5D_ */,
    2 /* gtl_scanner_1__2B__3D_ */,
    2 /* gtl_scanner_1__2D__3D_ */,
    2 /* gtl_scanner_1__2F_ */,
    2 /* gtl_scanner_1__21__3D_ */,
    2 /* gtl_scanner_1__3E__3D_ */,
    2 /* gtl_scanner_1__26_ */,
    2 /* gtl_scanner_1__3C__3D_ */,
    2 /* gtl_scanner_1__7B_ */,
    2 /* gtl_scanner_1__7D_ */,
    2 /* gtl_scanner_1__3C_ */,
    2 /* gtl_scanner_1__5E_ */,
    2 /* gtl_scanner_1__3E__3E_ */,
    2 /* gtl_scanner_1__7E_ */,
    2 /* gtl_scanner_1__3C__2D_ */,
    2 /* gtl_scanner_1__3C__3C_ */,
    2 /* gtl_scanner_1__40_ */,
    2 /* gtl_scanner_1__2A__3D_ */,
    2 /* gtl_scanner_1__2F__3D_ */,
    2 /* gtl_scanner_1__26__3D_ */,
    2 /* gtl_scanner_1__7C__3D_ */,
    2 /* gtl_scanner_1__3C__3C__3D_ */,
    2 /* gtl_scanner_1__3E__3E__3D_ */,
    2 /* gtl_scanner_1_mod_3D_ */,
    2 /* gtl_scanner_1__5E__3D_ */,
    2 /* gtl_scanner_1__40__5B_ */,
    2 /* gtl_scanner_1__40__28_ */,
    2 /* gtl_scanner_1__40__7B_ */,
    2 /* gtl_scanner_1__5B__21_ */,
    2 /* gtl_scanner_1__40__21_ */
  } ;
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                                            *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_gtl_5F_scanner::styleNameForIndex (const uint32_t inStyleIndex) const {
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
//                                                                                                                     *
//                                    Class for element of '@gtlArgumentList' list                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlArgumentList : public cCollectionElement {
  public : GALGAS_gtlArgumentList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlArgumentList (const GALGAS_bool & in_typed,
                                               const GALGAS_type & in_type,
                                               const GALGAS_lstring & in_name
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

cCollectionElement_gtlArgumentList::cCollectionElement_gtlArgumentList (const GALGAS_bool & in_typed,
                                                                        const GALGAS_type & in_type,
                                                                        const GALGAS_lstring & in_name
                                                                        COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_typed, in_type, in_name) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlArgumentList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlArgumentList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlArgumentList (mObject.mAttribute_typed, mObject.mAttribute_type, mObject.mAttribute_name COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlArgumentList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "typed" ":" ;
  mObject.mAttribute_typed.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "type" ":" ;
  mObject.mAttribute_type.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "name" ":" ;
  mObject.mAttribute_name.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlArgumentList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlArgumentList * operand = (cCollectionElement_gtlArgumentList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlArgumentList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList::GALGAS_gtlArgumentList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList::GALGAS_gtlArgumentList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlArgumentList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::constructor_listWithValue (const GALGAS_bool & inOperand0,
                                                                          const GALGAS_type & inOperand1,
                                                                          const GALGAS_lstring & inOperand2
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlArgumentList result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlArgumentList::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                        const GALGAS_bool & in_typed,
                                                        const GALGAS_type & in_type,
                                                        const GALGAS_lstring & in_name
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlArgumentList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlArgumentList (in_typed,
                                                     in_type,
                                                     in_name COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::addAssign_operation (const GALGAS_bool & inOperand0,
                                                  const GALGAS_type & inOperand1,
                                                  const GALGAS_lstring & inOperand2
                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlArgumentList (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::setter_insertAtIndex (const GALGAS_bool inOperand0,
                                                   const GALGAS_type inOperand1,
                                                   const GALGAS_lstring inOperand2,
                                                   const GALGAS_uint inInsertionIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlArgumentList (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::setter_removeAtIndex (GALGAS_bool & outOperand0,
                                                   GALGAS_type & outOperand1,
                                                   GALGAS_lstring & outOperand2,
                                                   const GALGAS_uint inRemoveIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
      outOperand0 = p->mObject.mAttribute_typed ;
      outOperand1 = p->mObject.mAttribute_type ;
      outOperand2 = p->mObject.mAttribute_name ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::setter_popFirst (GALGAS_bool & outOperand0,
                                              GALGAS_type & outOperand1,
                                              GALGAS_lstring & outOperand2,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    outOperand0 = p->mObject.mAttribute_typed ;
    outOperand1 = p->mObject.mAttribute_type ;
    outOperand2 = p->mObject.mAttribute_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::setter_popLast (GALGAS_bool & outOperand0,
                                             GALGAS_type & outOperand1,
                                             GALGAS_lstring & outOperand2,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    outOperand0 = p->mObject.mAttribute_typed ;
    outOperand1 = p->mObject.mAttribute_type ;
    outOperand2 = p->mObject.mAttribute_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::method_first (GALGAS_bool & outOperand0,
                                           GALGAS_type & outOperand1,
                                           GALGAS_lstring & outOperand2,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    outOperand0 = p->mObject.mAttribute_typed ;
    outOperand1 = p->mObject.mAttribute_type ;
    outOperand2 = p->mObject.mAttribute_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::method_last (GALGAS_bool & outOperand0,
                                          GALGAS_type & outOperand1,
                                          GALGAS_lstring & outOperand2,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    outOperand0 = p->mObject.mAttribute_typed ;
    outOperand1 = p->mObject.mAttribute_type ;
    outOperand2 = p->mObject.mAttribute_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::add_operation (const GALGAS_gtlArgumentList & inOperand,
                                                              C_Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result = GALGAS_gtlArgumentList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result = GALGAS_gtlArgumentList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result = GALGAS_gtlArgumentList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList::plusAssign_operation (const GALGAS_gtlArgumentList inOperand,
                                                   C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_gtlArgumentList::getter_typedAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    result = p->mObject.mAttribute_typed ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type GALGAS_gtlArgumentList::getter_typeAtIndex (const GALGAS_uint & inIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  GALGAS_type result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    result = p->mObject.mAttribute_type ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlArgumentList::getter_nameAtIndex (const GALGAS_uint & inIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    result = p->mObject.mAttribute_name ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlArgumentList::cEnumerator_gtlArgumentList (const GALGAS_gtlArgumentList & inEnumeratedObject,
                                                          const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList_2D_element cEnumerator_gtlArgumentList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlArgumentList * p = (const cCollectionElement_gtlArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cEnumerator_gtlArgumentList::current_typed (LOCATION_ARGS) const {
  const cCollectionElement_gtlArgumentList * p = (const cCollectionElement_gtlArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
  return p->mObject.mAttribute_typed ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type cEnumerator_gtlArgumentList::current_type (LOCATION_ARGS) const {
  const cCollectionElement_gtlArgumentList * p = (const cCollectionElement_gtlArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
  return p->mObject.mAttribute_type ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlArgumentList::current_name (LOCATION_ARGS) const {
  const cCollectionElement_gtlArgumentList * p = (const cCollectionElement_gtlArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
  return p->mObject.mAttribute_name ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @gtlArgumentList type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlArgumentList ("gtlArgumentList",
                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlArgumentList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlArgumentList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlArgumentList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlArgumentList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlArgumentList result ;
  const GALGAS_gtlArgumentList * p = (const GALGAS_gtlArgumentList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlArgumentList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlArgumentList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlProcMap::cMapElement_gtlProcMap (const GALGAS_lstring & inKey,
                                                const GALGAS_gtlProcedure & in_procedure
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_procedure (in_procedure) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_gtlProcMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_procedure.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_gtlProcMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_gtlProcMap (mAttribute_lkey, mAttribute_procedure COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_gtlProcMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "procedure" ":" ;
  mAttribute_procedure.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_gtlProcMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlProcMap * operand = (cMapElement_gtlProcMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_procedure.objectCompare (operand->mAttribute_procedure) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap::GALGAS_gtlProcMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap::GALGAS_gtlProcMap (const GALGAS_gtlProcMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap & GALGAS_gtlProcMap::operator = (const GALGAS_gtlProcMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap GALGAS_gtlProcMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlProcMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap GALGAS_gtlProcMap::constructor_mapWithMapToOverride (const GALGAS_gtlProcMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_gtlProcMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap GALGAS_gtlProcMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_gtlProcMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlProcMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_gtlProcedure & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_gtlProcMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlProcMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlProcMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlProcMap::setter_put (GALGAS_lstring inKey,
                                    GALGAS_gtlProcedure inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_gtlProcMap * p = NULL ;
  macroMyNew (p, cMapElement_gtlProcMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a procedure named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_gtlProcMap_get = "there is no procedure named '%K'" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlProcMap::method_get (GALGAS_lstring inKey,
                                    GALGAS_gtlProcedure & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) performSearch (inKey,
                                                                                       inCompiler,
                                                                                       kSearchErrorMessage_gtlProcMap_get
                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlProcMap) ;
    outArgument0 = p->mAttribute_procedure ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcedure GALGAS_gtlProcMap::getter_procedureForKey (const GALGAS_string & inKey,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) attributes ;
  GALGAS_gtlProcedure result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlProcMap) ;
    result = p->mAttribute_procedure ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlProcMap::setter_setProcedureForKey (GALGAS_gtlProcedure inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_gtlProcMap * p = (cMapElement_gtlProcMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_gtlProcMap) ;
    p->mAttribute_procedure = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_gtlProcMap * GALGAS_gtlProcMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_gtlProcMap * result = (cMapElement_gtlProcMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlProcMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlProcMap::cEnumerator_gtlProcMap (const GALGAS_gtlProcMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap_2D_element cEnumerator_gtlProcMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlProcMap) ;
  return GALGAS_gtlProcMap_2D_element (p->mAttribute_lkey, p->mAttribute_procedure) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_gtlProcMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcedure cEnumerator_gtlProcMap::current_procedure (LOCATION_ARGS) const {
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlProcMap) ;
  return p->mAttribute_procedure ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlProcMap type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlProcMap ("gtlProcMap",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlProcMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlProcMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlProcMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlProcMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap GALGAS_gtlProcMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlProcMap result ;
  const GALGAS_gtlProcMap * p = (const GALGAS_gtlProcMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlProcMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlProcMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                  C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_relation_5F_term_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 39)) ;
      GALGAS_location var_opLocation_1099 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 39)) ;
      GALGAS_gtlExpression var_rightSon_1156 ;
      nt_gtl_5F_relation_5F_term_ (var_rightSon_1156, inCompiler) ;
      outArgument_expression = GALGAS_gtlOrExpression::constructor_new (var_opLocation_1099, outArgument_expression, var_rightSon_1156  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 41)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 43)) ;
      GALGAS_location var_opLocation_1269 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 43)) ;
      GALGAS_gtlExpression var_rightSon_1326 ;
      nt_gtl_5F_relation_5F_term_ (var_rightSon_1326, inCompiler) ;
      outArgument_expression = GALGAS_gtlXorExpression::constructor_new (var_opLocation_1269, outArgument_expression, var_rightSon_1326  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 45)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_relation_5F_term_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 39)) ;
      nt_gtl_5F_relation_5F_term_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 43)) ;
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

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                        C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_relation_5F_factor_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_1 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 59)) ;
      GALGAS_location var_opLocation_1794 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 59)) ;
      GALGAS_gtlExpression var_rightSon_1853 ;
      nt_gtl_5F_relation_5F_factor_ (var_rightSon_1853, inCompiler) ;
      outArgument_expression = GALGAS_gtlAndExpression::constructor_new (var_opLocation_1794, outArgument_expression, var_rightSon_1853  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 61)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_relation_5F_factor_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_1 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 59)) ;
      nt_gtl_5F_relation_5F_factor_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                          C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_simple_5F_expression_ (outArgument_expression, inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_2 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3D__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 75)) ;
    GALGAS_location var_opLocation_2323 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 75)) ;
    GALGAS_gtlExpression var_rightSon_2384 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2384, inCompiler) ;
    outArgument_expression = GALGAS_gtlEqualExpression::constructor_new (var_opLocation_2323, outArgument_expression, var_rightSon_2384  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 77)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 81)) ;
    GALGAS_location var_opLocation_2508 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 81)) ;
    GALGAS_gtlExpression var_rightSon_2569 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2569, inCompiler) ;
    outArgument_expression = GALGAS_gtlNotEqualExpression::constructor_new (var_opLocation_2508, outArgument_expression, var_rightSon_2569  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 83)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 87)) ;
    GALGAS_location var_opLocation_2696 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 87)) ;
    GALGAS_gtlExpression var_rightSon_2757 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2757, inCompiler) ;
    outArgument_expression = GALGAS_gtlLowerOrEqualExpression::constructor_new (var_opLocation_2696, outArgument_expression, var_rightSon_2757  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 89)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 93)) ;
    GALGAS_location var_opLocation_2888 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 93)) ;
    GALGAS_gtlExpression var_rightSon_2949 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2949, inCompiler) ;
    outArgument_expression = GALGAS_gtlGreaterOrEqualExpression::constructor_new (var_opLocation_2888, outArgument_expression, var_rightSon_2949  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 95)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 99)) ;
    GALGAS_location var_opLocation_3081 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 99)) ;
    GALGAS_gtlExpression var_rightSon_3142 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_3142, inCompiler) ;
    outArgument_expression = GALGAS_gtlGreaterThanExpression::constructor_new (var_opLocation_3081, outArgument_expression, var_rightSon_3142  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 101)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 105)) ;
    GALGAS_location var_opLocation_3271 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 105)) ;
    GALGAS_gtlExpression var_rightSon_3332 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_3332, inCompiler) ;
    outArgument_expression = GALGAS_gtlLowerThanExpression::constructor_new (var_opLocation_3271, outArgument_expression, var_rightSon_3332  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 107)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_2 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3D__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 75)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 81)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 87)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 93)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 99)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 105)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                            C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_term_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 123)) ;
      GALGAS_location var_opLocation_3811 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 123)) ;
      GALGAS_gtlExpression var_rightSon_3859 ;
      nt_gtl_5F_term_ (var_rightSon_3859, inCompiler) ;
      outArgument_expression = GALGAS_gtlShiftLeftExpression::constructor_new (var_opLocation_3811, outArgument_expression, var_rightSon_3859  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 125)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 129)) ;
      GALGAS_location var_opLocation_3991 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 129)) ;
      GALGAS_gtlExpression var_rightSon_4039 ;
      nt_gtl_5F_term_ (var_rightSon_4039, inCompiler) ;
      outArgument_expression = GALGAS_gtlShiftRightExpression::constructor_new (var_opLocation_3991, outArgument_expression, var_rightSon_4039  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 131)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 135)) ;
      GALGAS_location var_opLocation_4171 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 135)) ;
      GALGAS_gtlExpression var_rightSon_4219 ;
      nt_gtl_5F_term_ (var_rightSon_4219, inCompiler) ;
      outArgument_expression = GALGAS_gtlAddExpression::constructor_new (var_opLocation_4171, outArgument_expression, var_rightSon_4219  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 137)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 141)) ;
      GALGAS_location var_opLocation_4344 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 141)) ;
      const enumGalgasBool test_1 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.getter_value ()).boolEnum () ;
      if (kBoolTrue == test_1) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        appendFixItActions (fixItArray2, kFixItReplace, GALGAS_string ("+")) ;
        inCompiler->emitSemanticWarning (var_opLocation_4344, GALGAS_string ("'.' operator is deprecated"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 143)) ;
      }
      GALGAS_gtlExpression var_rightSon_4532 ;
      nt_gtl_5F_term_ (var_rightSon_4532, inCompiler) ;
      outArgument_expression = GALGAS_gtlAddExpression::constructor_new (var_opLocation_4344, outArgument_expression, var_rightSon_4532  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 146)) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 150)) ;
      GALGAS_location var_opLocation_4657 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 150)) ;
      GALGAS_gtlExpression var_rightSon_4705 ;
      nt_gtl_5F_term_ (var_rightSon_4705, inCompiler) ;
      outArgument_expression = GALGAS_gtlSubstractExpression::constructor_new (var_opLocation_4657, outArgument_expression, var_rightSon_4705  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 152)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_term_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 123)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 129)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 135)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 141)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 150)) ;
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

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                            C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_factor_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 168)) ;
      GALGAS_location var_opLocation_5172 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 168)) ;
      GALGAS_gtlExpression var_rightSon_5222 ;
      nt_gtl_5F_factor_ (var_rightSon_5222, inCompiler) ;
      outArgument_expression = GALGAS_gtlMultiplyExpression::constructor_new (var_opLocation_5172, outArgument_expression, var_rightSon_5222  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 170)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 174)) ;
      GALGAS_location var_opLocation_5352 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 174)) ;
      GALGAS_gtlExpression var_rightSon_5402 ;
      nt_gtl_5F_factor_ (var_rightSon_5402, inCompiler) ;
      outArgument_expression = GALGAS_gtlDivideExpression::constructor_new (var_opLocation_5352, outArgument_expression, var_rightSon_5402  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 176)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 180)) ;
      GALGAS_location var_opLocation_5532 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 180)) ;
      GALGAS_gtlExpression var_rightSon_5582 ;
      nt_gtl_5F_factor_ (var_rightSon_5582, inCompiler) ;
      outArgument_expression = GALGAS_gtlModulusExpression::constructor_new (var_opLocation_5532, outArgument_expression, var_rightSon_5582  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 182)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_factor_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 168)) ;
      nt_gtl_5F_factor_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 174)) ;
      nt_gtl_5F_factor_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 180)) ;
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

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 195)) ;
  GALGAS_location var_opLocation_6002 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 195)) ;
  GALGAS_gtlExpression var_factorExpression_6062 ;
  nt_gtl_5F_expression_ (var_factorExpression_6062, inCompiler) ;
  outArgument_expression = GALGAS_gtlParenthesizedExpression::constructor_new (var_opLocation_6002, var_factorExpression_6062  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 197)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 201)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 195)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 201)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_not) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 211)) ;
  GALGAS_location var_opLocation_6484 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 211)) ;
  GALGAS_gtlExpression var_notExpression_6537 ;
  nt_gtl_5F_factor_ (var_notExpression_6537, inCompiler) ;
  outArgument_expression = GALGAS_gtlNotExpression::constructor_new (var_opLocation_6484, var_notExpression_6537  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 213)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_not) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 211)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 223)) ;
  GALGAS_location var_opLocation_6928 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 223)) ;
  GALGAS_gtlExpression var_notExpression_6981 ;
  nt_gtl_5F_factor_ (var_notExpression_6981, inCompiler) ;
  outArgument_expression = GALGAS_gtlNotExpression::constructor_new (var_opLocation_6928, var_notExpression_6981  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 225)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7E_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 223)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 235)) ;
  GALGAS_location var_opLocation_7372 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 235)) ;
  GALGAS_gtlExpression var_minusExpression_7427 ;
  nt_gtl_5F_factor_ (var_minusExpression_7427, inCompiler) ;
  outArgument_expression = GALGAS_gtlMinusExpression::constructor_new (var_opLocation_7372, var_minusExpression_7427  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 237)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 235)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 247)) ;
  GALGAS_location var_opLocation_7822 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 247)) ;
  GALGAS_gtlExpression var_plusExpression_7876 ;
  nt_gtl_5F_factor_ (var_plusExpression_7876, inCompiler) ;
  outArgument_expression = GALGAS_gtlPlusExpression::constructor_new (var_opLocation_7822, var_plusExpression_7876  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 249)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 247)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_yes) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 259)) ;
  GALGAS_location var_opLocation_8271 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 259)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (var_opLocation_8271, GALGAS_gtlBool::constructor_new (var_opLocation_8271, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 261)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 261))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 260)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_yes) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 259)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_no) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 272)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 274)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 274)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 274)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 274))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 273)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_no) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 272)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lbigint var_literalInteger_9142 = inCompiler->synthetizedAttribute_intValue () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 285)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 287)), GALGAS_gtlInt::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 287)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 287)), var_literalInteger_9142.getter_bigint (SOURCE_FILE ("gtl_expression_parser.galgas", 287))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 287))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 286)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 285)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_ldouble var_literalFloat_9597 = inCompiler->synthetizedAttribute_floatValue () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_double) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 298)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 300)), GALGAS_gtlFloat::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 300)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 300)), var_literalFloat_9597.getter_double (SOURCE_FILE ("gtl_expression_parser.galgas", 300))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 300))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 299)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_double) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 298)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lstring var_literalString_10045 = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 311)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 313)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 313)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 313)), var_literalString_10045.getter_string (SOURCE_FILE ("gtl_expression_parser.galgas", 313))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 313))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 312)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 311)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lchar var_literalChar_10495 = inCompiler->synthetizedAttribute_charValue () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_char) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 324)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 326)), GALGAS_gtlChar::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 326)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 326)), var_literalChar_10495.getter_char (SOURCE_FILE ("gtl_expression_parser.galgas", 326))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 326))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 325)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_char) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 324)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 338)) ;
  GALGAS_gtlExpression var_target_11029 ;
  nt_gtl_5F_expression_ (var_target_11029, inCompiler) ;
  GALGAS_lstring var_getterName_11069 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 340)) ;
  const enumGalgasBool test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("stringByCapitalizingFirstCharacter").objectCompare (var_getterName_11069.getter_string (SOURCE_FILE ("gtl_expression_parser.galgas", 342)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      appendFixItActions (fixItArray2, kFixItReplace, GALGAS_string ("capitalized")) ;
      inCompiler->emitSemanticWarning (var_getterName_11069.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 343)), GALGAS_string ("stringByCapitalizingFirstCharacter is deprecated"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 343)) ;
    }
  }
  GALGAS_gtlExpressionList var_argumentList_11350 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 347)) ;
  switch (select_gtl_5F_expression_5F_parser_5 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 350)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      GALGAS_gtlExpression var_argument_11444 ;
      nt_gtl_5F_expression_ (var_argument_11444, inCompiler) ;
      var_argumentList_11350.addAssign_operation (var_argument_11444  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 353)) ;
      switch (select_gtl_5F_expression_5F_parser_6 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 355)) ;
      } break ;
      default:
        repeatFlag_3 = false ;
        break ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 358)) ;
  outArgument_expression = GALGAS_gtlGetterCallExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 360)), var_target_11029, var_getterName_11069, var_argumentList_11350  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 359)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 338)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 340)) ;
  switch (select_gtl_5F_expression_5F_parser_5 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 350)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_expression_5F_parser_6 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 355)) ;
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
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 358)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_gtlVarPath var_path_11796 ;
  nt_gtl_5F_variable_ (var_path_11796, inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_7 (inCompiler)) {
  case 1: {
    outArgument_expression = GALGAS_gtlVarRef::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 374)), var_path_11796  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 374)) ;
  } break ;
  case 2: {
    const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_path_11796.getter_length (SOURCE_FILE ("gtl_expression_parser.galgas", 376)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 377)), GALGAS_string ("illegal function name"), fixItArray1  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 377)) ;
    }
    GALGAS_gtlExpressionList var_functionArguments_11982 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 379)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 380)) ;
    switch (select_gtl_5F_expression_5F_parser_8 (inCompiler)) {
    case 1: {
      bool repeatFlag_2 = true ;
      while (repeatFlag_2) {
        GALGAS_gtlExpression var_expression_12079 ;
        nt_gtl_5F_expression_ (var_expression_12079, inCompiler) ;
        var_functionArguments_11982.addAssign_operation (var_expression_12079  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 384)) ;
        switch (select_gtl_5F_expression_5F_parser_9 (inCompiler)) {
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 386)) ;
        } break ;
        default:
          repeatFlag_2 = false ;
          break ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 389)) ;
    GALGAS_lstring var_functionName_12199 = extensionGetter_pathAsFunctionName (var_path_11796, inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 390)) ;
    outArgument_expression = GALGAS_gtlFunctionCallExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 392)), var_functionName_12199, var_functionArguments_11982  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 391)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_7 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 380)) ;
    switch (select_gtl_5F_expression_5F_parser_8 (inCompiler)) {
    case 1: {
      bool repeatFlag_0 = true ;
      while (repeatFlag_0) {
        nt_gtl_5F_expression_parse (inCompiler) ;
        switch (select_gtl_5F_expression_5F_parser_9 (inCompiler)) {
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 386)) ;
        } break ;
        default:
          repeatFlag_0 = false ;
          break ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 389)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 404)) ;
  GALGAS_gtlVarPath var_path_12529 ;
  nt_gtl_5F_variable_ (var_path_12529, inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_default) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 406)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 407)) ;
    GALGAS_gtlExpression var_defaultExpression_12615 ;
    nt_gtl_5F_expression_ (var_defaultExpression_12615, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 409)) ;
    outArgument_expression = GALGAS_gtlExistsDefaultExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 411)), var_path_12529, var_defaultExpression_12615  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 410)) ;
  } break ;
  case 2: {
    outArgument_expression = GALGAS_gtlExistsExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 414)), var_path_12529  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 414)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 404)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_default) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 406)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 407)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 409)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_typeof) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 423)) ;
  GALGAS_gtlVarPath var_path_12970 ;
  nt_gtl_5F_variable_ (var_path_12970, inCompiler) ;
  outArgument_expression = GALGAS_gtlTypeOfExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 424)), var_path_12970  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 424)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_typeof) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 423)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_true) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 432)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 434)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 436)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 437)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 435))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 433)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_true) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 432)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_false) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 448)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 450)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 452)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 453)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 451))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 449)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_false) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 448)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lstring var_enumValue_13736 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 464)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 466)), GALGAS_gtlEnum::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 468)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 469)), var_enumValue_13736.getter_string (SOURCE_FILE ("gtl_expression_parser.galgas", 470))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 467))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 465)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 464)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  GALGAS_lstring var_typeName_14040 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  GALGAS_string var_name_14055 = var_typeName_14040.getter_string (SOURCE_FILE ("gtl_expression_parser.galgas", 481)) ;
  GALGAS_gtlType var_type_14091 ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("int"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 484)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 484)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 484)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("float"))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 486)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 486)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 486)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("string"))).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 488)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 488)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 488)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("bool"))).boolEnum () ;
        if (kBoolTrue == test_3) {
          var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 490)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 490)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 490)) ;
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("struct"))).boolEnum () ;
          if (kBoolTrue == test_4) {
            var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 492)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 492)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 492)) ;
          }else if (kBoolFalse == test_4) {
            const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("list"))).boolEnum () ;
            if (kBoolTrue == test_5) {
              var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 494)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 494)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlList)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 494)) ;
            }else if (kBoolFalse == test_5) {
              const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("map"))).boolEnum () ;
              if (kBoolTrue == test_6) {
                var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 496)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 496)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlMap)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 496)) ;
              }else if (kBoolFalse == test_6) {
                const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("enum"))).boolEnum () ;
                if (kBoolTrue == test_7) {
                  var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 498)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 498)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlEnum)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 498)) ;
                }else if (kBoolFalse == test_7) {
                  const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("type"))).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 500)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 500)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlType)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 500)) ;
                  }else if (kBoolFalse == test_8) {
                    const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("set"))).boolEnum () ;
                    if (kBoolTrue == test_9) {
                      var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 502)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 502)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 502)) ;
                    }else if (kBoolFalse == test_9) {
                      const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("char"))).boolEnum () ;
                      if (kBoolTrue == test_10) {
                        var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 504)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 504)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 504)) ;
                      }else if (kBoolFalse == test_10) {
                        const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, var_name_14055.objectCompare (GALGAS_string ("unconstructed"))).boolEnum () ;
                        if (kBoolTrue == test_11) {
                          var_type_14091 = GALGAS_gtlType::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 506)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 506)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlUnconstructed)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 506)) ;
                        }else if (kBoolFalse == test_11) {
                          TC_Array <C_FixItDescription> fixItArray12 ;
                          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 507)), var_name_14055.add_operation (GALGAS_string (" does not name a type"), inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 507)), fixItArray12  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 507)) ;
                          var_type_14091.drop () ; // Release error dropped variable
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
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (var_typeName_14040.getter_location (SOURCE_FILE ("gtl_expression_parser.galgas", 509)), var_type_14091  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 509)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptylist) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 517)) ;
  const enumGalgasBool test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("@( )")) ;
    inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 519)), GALGAS_string ("emptylist is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 519)) ;
  }
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 522)), GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 524)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 525)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 526))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 523))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 521)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptylist) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 517)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptymap) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 536)) ;
  const enumGalgasBool test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("@[ ]")) ;
    inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 538)), GALGAS_string ("emptymap is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 538)) ;
  }
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 541)), GALGAS_gtlMap::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 543)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 544)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expression_parser.galgas", 545))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 542))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 540)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptymap) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 536)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mapof) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 555)) ;
  GALGAS_gtlExpression var_data_16406 ;
  nt_gtl_5F_expression_ (var_data_16406, inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 558)) ;
    GALGAS_lstring var_key_16459 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 559)) ;
    outArgument_expression = GALGAS_gtlMapOfListExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 561)), var_data_16406, var_key_16459  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 560)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 566)) ;
    outArgument_expression = GALGAS_gtlMapOfStructExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 568)), var_data_16406  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 567)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mapof) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 555)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 558)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 559)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 566)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_listof) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 579)) ;
  GALGAS_gtlExpression var_data_16839 ;
  nt_gtl_5F_expression_ (var_data_16839, inCompiler) ;
  outArgument_expression = GALGAS_gtlListOfExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 581)), var_data_16839  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 581)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 582)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_listof) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 579)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 582)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 590)) ;
  GALGAS_gtlExpressionList var_expressionList_17081 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 591)) ;
  switch (select_gtl_5F_expression_5F_parser_12 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_gtlExpression var_listItem_17162 ;
      nt_gtl_5F_expression_ (var_listItem_17162, inCompiler) ;
      var_expressionList_17081.addAssign_operation (var_listItem_17162  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 595)) ;
      switch (select_gtl_5F_expression_5F_parser_13 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 596)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 600)) ;
  outArgument_expression = GALGAS_gtlLiteralListExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 601)), var_expressionList_17081  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 601)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 590)) ;
  switch (select_gtl_5F_expression_5F_parser_12 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_expression_5F_parser_13 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 596)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 600)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 609)) ;
  GALGAS_gtlExpressionMap var_expressionMap_17482 = GALGAS_gtlExpressionMap::constructor_emptyMap (SOURCE_FILE ("gtl_expression_parser.galgas", 610)) ;
  switch (select_gtl_5F_expression_5F_parser_14 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_key_17548 = inCompiler->synthetizedAttribute_a_5F_string () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 613)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 614)) ;
      GALGAS_gtlExpression var_mapItem_17605 ;
      nt_gtl_5F_expression_ (var_mapItem_17605, inCompiler) ;
      {
      var_expressionMap_17482.setter_put (var_key_17548, var_mapItem_17605, inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 616)) ;
      }
      switch (select_gtl_5F_expression_5F_parser_15 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 617)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 621)) ;
  outArgument_expression = GALGAS_gtlLiteralMapExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 622)), var_expressionMap_17482  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 622)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 609)) ;
  switch (select_gtl_5F_expression_5F_parser_14 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 613)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 614)) ;
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_expression_5F_parser_15 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 617)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 621)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__7B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 630)) ;
  GALGAS_gtlExpressionMap var_expressionMap_17931 = GALGAS_gtlExpressionMap::constructor_emptyMap (SOURCE_FILE ("gtl_expression_parser.galgas", 631)) ;
  switch (select_gtl_5F_expression_5F_parser_16 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_fieldName_18006 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 634)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 635)) ;
      GALGAS_gtlExpression var_structField_18067 ;
      nt_gtl_5F_expression_ (var_structField_18067, inCompiler) ;
      {
      var_expressionMap_17931.setter_put (var_fieldName_18006, var_structField_18067, inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 637)) ;
      }
      switch (select_gtl_5F_expression_5F_parser_17 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 638)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 642)) ;
  outArgument_expression = GALGAS_gtlLiteralStructExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 643)), var_expressionMap_17931  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 643)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__7B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 630)) ;
  switch (select_gtl_5F_expression_5F_parser_16 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 634)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 635)) ;
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_expression_5F_parser_17 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 638)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 642)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__21_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 651)) ;
  GALGAS_gtlExpressionList var_expressionList_18408 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 652)) ;
  switch (select_gtl_5F_expression_5F_parser_18 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_gtlExpression var_setElement_18491 ;
      nt_gtl_5F_expression_ (var_setElement_18491, inCompiler) ;
      var_expressionList_18408.addAssign_operation (var_setElement_18491  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 656)) ;
      switch (select_gtl_5F_expression_5F_parser_19 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 657)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 661)) ;
  outArgument_expression = GALGAS_gtlLiteralSetExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 662)), var_expressionList_18408  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 662)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__21_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 651)) ;
  switch (select_gtl_5F_expression_5F_parser_18 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_expression_5F_parser_19 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 657)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 661)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i32_ (GALGAS_gtlVarPath & outArgument_path,
                                                                                                 C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_path.drop () ; // Release 'out' argument
  outArgument_path = GALGAS_gtlVarPath::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 670)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_lstring var_variableName_18837 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 672)) ;
    switch (select_gtl_5F_expression_5F_parser_21 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 674)) ;
      GALGAS_gtlExpression var_expression_18912 ;
      nt_gtl_5F_expression_ (var_expression_18912, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 676)) ;
      outArgument_path.addAssign_operation (GALGAS_gtlVarItemCollection::constructor_new (var_variableName_18837, var_expression_18912  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 677))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 677)) ;
      switch (select_gtl_5F_expression_5F_parser_22 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 679)) ;
        GALGAS_gtlExpression var_expression_19074 ;
        nt_gtl_5F_expression_ (var_expression_19074, inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 681)) ;
        outArgument_path.addAssign_operation (GALGAS_gtlVarItemSubCollection::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 682)), var_expression_19074  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 682))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 682)) ;
        bool repeatFlag_1 = true ;
        while (repeatFlag_1) {
          switch (select_gtl_5F_expression_5F_parser_23 (inCompiler)) {
          case 2: {
            inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 685)) ;
            GALGAS_gtlExpression var_expression_19256 ;
            nt_gtl_5F_expression_ (var_expression_19256, inCompiler) ;
            inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 687)) ;
            outArgument_path.addAssign_operation (GALGAS_gtlVarItemSubCollection::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 688)), var_expression_19256  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 688))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 688)) ;
          } break ;
          default:
            repeatFlag_1 = false ;
            break ;
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
      outArgument_path.addAssign_operation (GALGAS_gtlVarItemField::constructor_new (var_variableName_18837  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 693))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 693)) ;
    } break ;
    default:
      break ;
    }
    switch (select_gtl_5F_expression_5F_parser_20 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 696)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i32_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 672)) ;
    switch (select_gtl_5F_expression_5F_parser_21 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 674)) ;
      nt_gtl_5F_expression_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 676)) ;
      switch (select_gtl_5F_expression_5F_parser_22 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 679)) ;
        nt_gtl_5F_expression_parse (inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 681)) ;
        bool repeatFlag_1 = true ;
        while (repeatFlag_1) {
          switch (select_gtl_5F_expression_5F_parser_23 (inCompiler)) {
          case 2: {
            inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 685)) ;
            nt_gtl_5F_expression_parse (inCompiler) ;
            inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 687)) ;
          } break ;
          default:
            repeatFlag_1 = false ;
            break ;
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
    switch (select_gtl_5F_expression_5F_parser_20 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 696)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i33_ (GALGAS_gtlVarPath & outArgument_path,
                                                                                                               GALGAS_bool & outArgument_hereInstead,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_path.drop () ; // Release 'out' argument
  outArgument_hereInstead.drop () ; // Release 'out' argument
  switch (select_gtl_5F_expression_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_here) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 707)) ;
    outArgument_path = GALGAS_gtlVarPath::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 707)) ;
    outArgument_hereInstead = GALGAS_bool (true) ;
  } break ;
  case 2: {
    nt_gtl_5F_variable_ (outArgument_path, inCompiler) ;
    outArgument_hereInstead = GALGAS_bool (false) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i33_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  switch (select_gtl_5F_expression_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_here) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 707)) ;
  } break ;
  case 2: {
    nt_gtl_5F_variable_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i34_ (GALGAS_gtlArgumentList & outArgument_arguments,
                                                                                                         C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_arguments.drop () ; // Release 'out' argument
  outArgument_arguments = GALGAS_gtlArgumentList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 719)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 720)) ;
  switch (select_gtl_5F_expression_5F_parser_25 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_argumentName_19978 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 723)) ;
      switch (select_gtl_5F_expression_5F_parser_27 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 725)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 725)) ;
        GALGAS_lstring var_typeName_20043 = inCompiler->synthetizedAttribute_tokenString () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 725)) ;
        outArgument_arguments.addAssign_operation (GALGAS_bool (true), extensionGetter_gtlType (var_typeName_20043, inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 726)), var_argumentName_19978  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 726)) ;
      } break ;
      case 2: {
        outArgument_arguments.addAssign_operation (GALGAS_bool (false), GALGAS_type (& kTypeDescriptor_GALGAS_gtlData), var_argumentName_19978  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 728)) ;
      } break ;
      default:
        break ;
      }
      switch (select_gtl_5F_expression_5F_parser_26 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 730)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 733)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i34_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 720)) ;
  switch (select_gtl_5F_expression_5F_parser_25 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 723)) ;
      switch (select_gtl_5F_expression_5F_parser_27 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 725)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 725)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 725)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      switch (select_gtl_5F_expression_5F_parser_26 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 730)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 733)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Class for element of '@gtlThenElsifStatementList' list                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlThenElsifStatementList : public cCollectionElement {
  public : GALGAS_gtlThenElsifStatementList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlThenElsifStatementList (const GALGAS_gtlExpression & in_condition,
                                                         const GALGAS_gtlInstructionList & in_instructionList
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

cCollectionElement_gtlThenElsifStatementList::cCollectionElement_gtlThenElsifStatementList (const GALGAS_gtlExpression & in_condition,
                                                                                            const GALGAS_gtlInstructionList & in_instructionList
                                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_condition, in_instructionList) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlThenElsifStatementList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlThenElsifStatementList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlThenElsifStatementList (mObject.mAttribute_condition, mObject.mAttribute_instructionList COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlThenElsifStatementList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "condition" ":" ;
  mObject.mAttribute_condition.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "instructionList" ":" ;
  mObject.mAttribute_instructionList.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlThenElsifStatementList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlThenElsifStatementList * operand = (cCollectionElement_gtlThenElsifStatementList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlThenElsifStatementList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList::GALGAS_gtlThenElsifStatementList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList::GALGAS_gtlThenElsifStatementList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlThenElsifStatementList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::constructor_listWithValue (const GALGAS_gtlExpression & inOperand0,
                                                                                              const GALGAS_gtlInstructionList & inOperand1
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlThenElsifStatementList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlThenElsifStatementList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                  const GALGAS_gtlExpression & in_condition,
                                                                  const GALGAS_gtlInstructionList & in_instructionList
                                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlThenElsifStatementList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlThenElsifStatementList (in_condition,
                                                               in_instructionList COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::addAssign_operation (const GALGAS_gtlExpression & inOperand0,
                                                            const GALGAS_gtlInstructionList & inOperand1
                                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlThenElsifStatementList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::setter_insertAtIndex (const GALGAS_gtlExpression inOperand0,
                                                             const GALGAS_gtlInstructionList inOperand1,
                                                             const GALGAS_uint inInsertionIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlThenElsifStatementList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::setter_removeAtIndex (GALGAS_gtlExpression & outOperand0,
                                                             GALGAS_gtlInstructionList & outOperand1,
                                                             const GALGAS_uint inRemoveIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
      outOperand0 = p->mObject.mAttribute_condition ;
      outOperand1 = p->mObject.mAttribute_instructionList ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::setter_popFirst (GALGAS_gtlExpression & outOperand0,
                                                        GALGAS_gtlInstructionList & outOperand1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    outOperand0 = p->mObject.mAttribute_condition ;
    outOperand1 = p->mObject.mAttribute_instructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::setter_popLast (GALGAS_gtlExpression & outOperand0,
                                                       GALGAS_gtlInstructionList & outOperand1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    outOperand0 = p->mObject.mAttribute_condition ;
    outOperand1 = p->mObject.mAttribute_instructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::method_first (GALGAS_gtlExpression & outOperand0,
                                                     GALGAS_gtlInstructionList & outOperand1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    outOperand0 = p->mObject.mAttribute_condition ;
    outOperand1 = p->mObject.mAttribute_instructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::method_last (GALGAS_gtlExpression & outOperand0,
                                                    GALGAS_gtlInstructionList & outOperand1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    outOperand0 = p->mObject.mAttribute_condition ;
    outOperand1 = p->mObject.mAttribute_instructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::add_operation (const GALGAS_gtlThenElsifStatementList & inOperand,
                                                                                  C_Compiler * /* inCompiler */
                                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlThenElsifStatementList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlThenElsifStatementList result = GALGAS_gtlThenElsifStatementList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlThenElsifStatementList result = GALGAS_gtlThenElsifStatementList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_gtlThenElsifStatementList result = GALGAS_gtlThenElsifStatementList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList::plusAssign_operation (const GALGAS_gtlThenElsifStatementList inOperand,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlThenElsifStatementList::getter_conditionAtIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  GALGAS_gtlExpression result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    result = p->mObject.mAttribute_condition ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlThenElsifStatementList::getter_instructionListAtIndex (const GALGAS_uint & inIndex,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  GALGAS_gtlInstructionList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    result = p->mObject.mAttribute_instructionList ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlThenElsifStatementList::cEnumerator_gtlThenElsifStatementList (const GALGAS_gtlThenElsifStatementList & inEnumeratedObject,
                                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList_2D_element cEnumerator_gtlThenElsifStatementList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlThenElsifStatementList * p = (const cCollectionElement_gtlThenElsifStatementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression cEnumerator_gtlThenElsifStatementList::current_condition (LOCATION_ARGS) const {
  const cCollectionElement_gtlThenElsifStatementList * p = (const cCollectionElement_gtlThenElsifStatementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
  return p->mObject.mAttribute_condition ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cEnumerator_gtlThenElsifStatementList::current_instructionList (LOCATION_ARGS) const {
  const cCollectionElement_gtlThenElsifStatementList * p = (const cCollectionElement_gtlThenElsifStatementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
  return p->mObject.mAttribute_instructionList ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlThenElsifStatementList type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlThenElsifStatementList ("gtlThenElsifStatementList",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlThenElsifStatementList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlThenElsifStatementList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlThenElsifStatementList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlThenElsifStatementList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlThenElsifStatementList result ;
  const GALGAS_gtlThenElsifStatementList * p = (const GALGAS_gtlThenElsifStatementList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlThenElsifStatementList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlThenElsifStatementList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Class for element of '@sortingKeyList' list                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_sortingKeyList : public cCollectionElement {
  public : GALGAS_sortingKeyList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_sortingKeyList (const GALGAS_lstring & in_key,
                                              const GALGAS_lsint & in_order
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

cCollectionElement_sortingKeyList::cCollectionElement_sortingKeyList (const GALGAS_lstring & in_key,
                                                                      const GALGAS_lsint & in_order
                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_key, in_order) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_sortingKeyList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_sortingKeyList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_sortingKeyList (mObject.mAttribute_key, mObject.mAttribute_order COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_sortingKeyList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "key" ":" ;
  mObject.mAttribute_key.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "order" ":" ;
  mObject.mAttribute_order.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_sortingKeyList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_sortingKeyList * operand = (cCollectionElement_sortingKeyList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_sortingKeyList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList::GALGAS_sortingKeyList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList::GALGAS_sortingKeyList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_sortingKeyList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                        const GALGAS_lsint & inOperand1
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_sortingKeyList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_sortingKeyList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                       const GALGAS_lstring & in_key,
                                                       const GALGAS_lsint & in_order
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement_sortingKeyList * p = NULL ;
  macroMyNew (p, cCollectionElement_sortingKeyList (in_key,
                                                    in_order COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                 const GALGAS_lsint & inOperand1
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_sortingKeyList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                  const GALGAS_lsint inOperand1,
                                                  const GALGAS_uint inInsertionIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_sortingKeyList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                  GALGAS_lsint & outOperand1,
                                                  const GALGAS_uint inRemoveIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
      outOperand0 = p->mObject.mAttribute_key ;
      outOperand1 = p->mObject.mAttribute_order ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::setter_popFirst (GALGAS_lstring & outOperand0,
                                             GALGAS_lsint & outOperand1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    outOperand0 = p->mObject.mAttribute_key ;
    outOperand1 = p->mObject.mAttribute_order ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::setter_popLast (GALGAS_lstring & outOperand0,
                                            GALGAS_lsint & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    outOperand0 = p->mObject.mAttribute_key ;
    outOperand1 = p->mObject.mAttribute_order ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::method_first (GALGAS_lstring & outOperand0,
                                          GALGAS_lsint & outOperand1,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    outOperand0 = p->mObject.mAttribute_key ;
    outOperand1 = p->mObject.mAttribute_order ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::method_last (GALGAS_lstring & outOperand0,
                                         GALGAS_lsint & outOperand1,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    outOperand0 = p->mObject.mAttribute_key ;
    outOperand1 = p->mObject.mAttribute_order ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::add_operation (const GALGAS_sortingKeyList & inOperand,
                                                            C_Compiler * /* inCompiler */
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sortingKeyList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_sortingKeyList result = GALGAS_sortingKeyList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_sortingKeyList result = GALGAS_sortingKeyList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_sortingKeyList result = GALGAS_sortingKeyList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList::plusAssign_operation (const GALGAS_sortingKeyList inOperand,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_sortingKeyList::getter_keyAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    result = p->mObject.mAttribute_key ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lsint GALGAS_sortingKeyList::getter_orderAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  GALGAS_lsint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    result = p->mObject.mAttribute_order ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_sortingKeyList::cEnumerator_sortingKeyList (const GALGAS_sortingKeyList & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList_2D_element cEnumerator_sortingKeyList::current (LOCATION_ARGS) const {
  const cCollectionElement_sortingKeyList * p = (const cCollectionElement_sortingKeyList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_sortingKeyList::current_key (LOCATION_ARGS) const {
  const cCollectionElement_sortingKeyList * p = (const cCollectionElement_sortingKeyList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
  return p->mObject.mAttribute_key ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lsint cEnumerator_sortingKeyList::current_order (LOCATION_ARGS) const {
  const cCollectionElement_sortingKeyList * p = (const cCollectionElement_sortingKeyList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
  return p->mObject.mAttribute_order ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @sortingKeyList type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sortingKeyList ("sortingKeyList",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sortingKeyList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sortingKeyList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sortingKeyList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sortingKeyList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList GALGAS_sortingKeyList::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_sortingKeyList result ;
  const GALGAS_sortingKeyList * p = (const GALGAS_sortingKeyList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sortingKeyList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sortingKeyList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Class for element of '@gtlBreakpointList' list                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlBreakpointList : public cCollectionElement {
  public : GALGAS_gtlBreakpointList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlBreakpointList (const GALGAS_gtlBreakpoint & in_breakpoint
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

cCollectionElement_gtlBreakpointList::cCollectionElement_gtlBreakpointList (const GALGAS_gtlBreakpoint & in_breakpoint
                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_breakpoint) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlBreakpointList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlBreakpointList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlBreakpointList (mObject.mAttribute_breakpoint COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlBreakpointList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "breakpoint" ":" ;
  mObject.mAttribute_breakpoint.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlBreakpointList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlBreakpointList * operand = (cCollectionElement_gtlBreakpointList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlBreakpointList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList::GALGAS_gtlBreakpointList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList::GALGAS_gtlBreakpointList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlBreakpointList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::constructor_listWithValue (const GALGAS_gtlBreakpoint & inOperand0
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointList result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlBreakpointList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlBreakpointList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                          const GALGAS_gtlBreakpoint & in_breakpoint
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlBreakpointList * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlBreakpointList (in_breakpoint COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlBreakpointList::addAssign_operation (const GALGAS_gtlBreakpoint & inOperand0
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlBreakpointList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlBreakpointList::setter_insertAtIndex (const GALGAS_gtlBreakpoint inOperand0,
                                                     const GALGAS_uint inInsertionIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlBreakpointList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlBreakpointList::setter_removeAtIndex (GALGAS_gtlBreakpoint & outOperand0,
                                                     const GALGAS_uint inRemoveIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
      outOperand0 = p->mObject.mAttribute_breakpoint ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlBreakpointList::setter_popFirst (GALGAS_gtlBreakpoint & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
    outOperand0 = p->mObject.mAttribute_breakpoint ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlBreakpointList::setter_popLast (GALGAS_gtlBreakpoint & outOperand0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
    outOperand0 = p->mObject.mAttribute_breakpoint ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlBreakpointList::method_first (GALGAS_gtlBreakpoint & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
    outOperand0 = p->mObject.mAttribute_breakpoint ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlBreakpointList::method_last (GALGAS_gtlBreakpoint & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
    outOperand0 = p->mObject.mAttribute_breakpoint ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::add_operation (const GALGAS_gtlBreakpointList & inOperand,
                                                                  C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlBreakpointList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlBreakpointList result = GALGAS_gtlBreakpointList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlBreakpointList result = GALGAS_gtlBreakpointList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_gtlBreakpointList result = GALGAS_gtlBreakpointList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlBreakpointList::plusAssign_operation (const GALGAS_gtlBreakpointList inOperand,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpoint GALGAS_gtlBreakpointList::getter_breakpointAtIndex (const GALGAS_uint & inIndex,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) attributes.ptr () ;
  GALGAS_gtlBreakpoint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
    result = p->mObject.mAttribute_breakpoint ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlBreakpointList::cEnumerator_gtlBreakpointList (const GALGAS_gtlBreakpointList & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList_2D_element cEnumerator_gtlBreakpointList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlBreakpointList * p = (const cCollectionElement_gtlBreakpointList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpoint cEnumerator_gtlBreakpointList::current_breakpoint (LOCATION_ARGS) const {
  const cCollectionElement_gtlBreakpointList * p = (const cCollectionElement_gtlBreakpointList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
  return p->mObject.mAttribute_breakpoint ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlBreakpointList type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpointList ("gtlBreakpointList",
                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlBreakpointList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlBreakpointList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpointList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointList result ;
  const GALGAS_gtlBreakpointList * p = (const GALGAS_gtlBreakpointList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlBreakpointList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpointList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Class for element of '@gtlInstructionListContextStack' list                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_gtlInstructionListContextStack : public cCollectionElement {
  public : GALGAS_gtlInstructionListContextStack_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_gtlInstructionListContextStack (const GALGAS_uint & in_nextInstructionIndex,
                                                              const GALGAS_gtlInstructionList & in_instructionList
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

cCollectionElement_gtlInstructionListContextStack::cCollectionElement_gtlInstructionListContextStack (const GALGAS_uint & in_nextInstructionIndex,
                                                                                                      const GALGAS_gtlInstructionList & in_instructionList
                                                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_nextInstructionIndex, in_instructionList) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_gtlInstructionListContextStack::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_gtlInstructionListContextStack::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_gtlInstructionListContextStack (mObject.mAttribute_nextInstructionIndex, mObject.mAttribute_instructionList COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_gtlInstructionListContextStack::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "nextInstructionIndex" ":" ;
  mObject.mAttribute_nextInstructionIndex.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "instructionList" ":" ;
  mObject.mAttribute_instructionList.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_gtlInstructionListContextStack::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlInstructionListContextStack * operand = (cCollectionElement_gtlInstructionListContextStack *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlInstructionListContextStack) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack::GALGAS_gtlInstructionListContextStack (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack::GALGAS_gtlInstructionListContextStack (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_gtlInstructionListContextStack result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::constructor_listWithValue (const GALGAS_uint & inOperand0,
                                                                                                        const GALGAS_gtlInstructionList & inOperand1
                                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionListContextStack result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_gtlInstructionListContextStack::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionListContextStack::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                       const GALGAS_uint & in_nextInstructionIndex,
                                                                       const GALGAS_gtlInstructionList & in_instructionList
                                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlInstructionListContextStack * p = NULL ;
  macroMyNew (p, cCollectionElement_gtlInstructionListContextStack (in_nextInstructionIndex,
                                                                    in_instructionList COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionListContextStack::addAssign_operation (const GALGAS_uint & inOperand0,
                                                                 const GALGAS_gtlInstructionList & inOperand1
                                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlInstructionListContextStack (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionListContextStack::setter_insertAtIndex (const GALGAS_uint inOperand0,
                                                                  const GALGAS_gtlInstructionList inOperand1,
                                                                  const GALGAS_uint inInsertionIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_gtlInstructionListContextStack (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionListContextStack::setter_removeAtIndex (GALGAS_uint & outOperand0,
                                                                  GALGAS_gtlInstructionList & outOperand1,
                                                                  const GALGAS_uint inRemoveIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
      outOperand0 = p->mObject.mAttribute_nextInstructionIndex ;
      outOperand1 = p->mObject.mAttribute_instructionList ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionListContextStack::setter_popFirst (GALGAS_uint & outOperand0,
                                                             GALGAS_gtlInstructionList & outOperand1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    outOperand0 = p->mObject.mAttribute_nextInstructionIndex ;
    outOperand1 = p->mObject.mAttribute_instructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionListContextStack::setter_popLast (GALGAS_uint & outOperand0,
                                                            GALGAS_gtlInstructionList & outOperand1,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    outOperand0 = p->mObject.mAttribute_nextInstructionIndex ;
    outOperand1 = p->mObject.mAttribute_instructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionListContextStack::method_first (GALGAS_uint & outOperand0,
                                                          GALGAS_gtlInstructionList & outOperand1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    outOperand0 = p->mObject.mAttribute_nextInstructionIndex ;
    outOperand1 = p->mObject.mAttribute_instructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionListContextStack::method_last (GALGAS_uint & outOperand0,
                                                         GALGAS_gtlInstructionList & outOperand1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    outOperand0 = p->mObject.mAttribute_nextInstructionIndex ;
    outOperand1 = p->mObject.mAttribute_instructionList ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::add_operation (const GALGAS_gtlInstructionListContextStack & inOperand,
                                                                                            C_Compiler * /* inCompiler */
                                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlInstructionListContextStack result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                      C_Compiler * inCompiler
                                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionListContextStack result = GALGAS_gtlInstructionListContextStack::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                      C_Compiler * inCompiler
                                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionListContextStack result = GALGAS_gtlInstructionListContextStack::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionListContextStack result = GALGAS_gtlInstructionListContextStack::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlInstructionListContextStack::plusAssign_operation (const GALGAS_gtlInstructionListContextStack inOperand,
                                                                  C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_gtlInstructionListContextStack::getter_nextInstructionIndexAtIndex (const GALGAS_uint & inIndex,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    result = p->mObject.mAttribute_nextInstructionIndex ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlInstructionListContextStack::getter_instructionListAtIndex (const GALGAS_uint & inIndex,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
  GALGAS_gtlInstructionList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    result = p->mObject.mAttribute_instructionList ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_gtlInstructionListContextStack::cEnumerator_gtlInstructionListContextStack (const GALGAS_gtlInstructionListContextStack & inEnumeratedObject,
                                                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack_2D_element cEnumerator_gtlInstructionListContextStack::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlInstructionListContextStack * p = (const cCollectionElement_gtlInstructionListContextStack *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cEnumerator_gtlInstructionListContextStack::current_nextInstructionIndex (LOCATION_ARGS) const {
  const cCollectionElement_gtlInstructionListContextStack * p = (const cCollectionElement_gtlInstructionListContextStack *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
  return p->mObject.mAttribute_nextInstructionIndex ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList cEnumerator_gtlInstructionListContextStack::current_instructionList (LOCATION_ARGS) const {
  const cCollectionElement_gtlInstructionListContextStack * p = (const cCollectionElement_gtlInstructionListContextStack *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
  return p->mObject.mAttribute_instructionList ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @gtlInstructionListContextStack type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInstructionListContextStack ("gtlInstructionListContextStack",
                                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlInstructionListContextStack::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInstructionListContextStack ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlInstructionListContextStack::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInstructionListContextStack (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionListContextStack result ;
  const GALGAS_gtlInstructionListContextStack * p = (const GALGAS_gtlInstructionListContextStack *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlInstructionListContextStack *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInstructionListContextStack", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_lstring var_command_1074 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 40)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("c").objectCompare (var_command_1074.getter_string (SOURCE_FILE ("gtl_debugger_parser.galgas", 41)))).operator_or (GALGAS_bool (kIsEqual, GALGAS_string ("cont").objectCompare (var_command_1074.getter_string (SOURCE_FILE ("gtl_debugger_parser.galgas", 41)))) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 41)).operator_or (GALGAS_bool (kIsEqual, GALGAS_string ("continue").objectCompare (var_command_1074.getter_string (SOURCE_FILE ("gtl_debugger_parser.galgas", 41)))) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 41)).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_instruction = GALGAS_gtlContinueInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 43)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 42)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("help").objectCompare (var_command_1074.getter_string (SOURCE_FILE ("gtl_debugger_parser.galgas", 46)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_instruction = GALGAS_gtlHelpInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 48)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 47)) ;
    }else if (kBoolFalse == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 52)), GALGAS_string ("Illegal command: ").add_operation (var_command_1074.getter_string (SOURCE_FILE ("gtl_debugger_parser.galgas", 52)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 52)), fixItArray2  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 52)) ;
      outArgument_instruction.drop () ; // Release error dropped variable
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 40)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 60)) ;
  outArgument_instruction = GALGAS_gtlStepInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 62)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 61)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 60)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_break) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 71)) ;
  switch (select_gtl_5F_debugger_5F_parser_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_not) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 73)) ;
    GALGAS_lbigint var_index_1850 = inCompiler->synthetizedAttribute_intValue () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 74)) ;
    outArgument_instruction = GALGAS_gtlBreakpointDeleteInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 76)), GALGAS_string::makeEmptyString (), var_index_1850  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 75)) ;
  } break ;
  case 2: {
    switch (select_gtl_5F_debugger_5F_parser_1 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_fileName_2007 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 82)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2E_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 83)) ;
      GALGAS_lstring var_fileExtension_2064 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 84)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 85)) ;
      GALGAS_lbigint var_lineNum_2134 = inCompiler->synthetizedAttribute_intValue () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 86)) ;
      outArgument_instruction = GALGAS_gtlBreakpointInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 88)), GALGAS_string::makeEmptyString (), var_fileName_2007.getter_string (SOURCE_FILE ("gtl_debugger_parser.galgas", 90)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 90)).add_operation (var_fileExtension_2064.getter_string (SOURCE_FILE ("gtl_debugger_parser.galgas", 90)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 90)), var_lineNum_2134.getter_bigint (SOURCE_FILE ("gtl_debugger_parser.galgas", 91)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 91))  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 87)) ;
    } break ;
    case 2: {
      GALGAS_lbigint var_lineNum_2363 = inCompiler->synthetizedAttribute_intValue () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 94)) ;
      outArgument_instruction = GALGAS_gtlBreakpointInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 96)), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), var_lineNum_2363.getter_bigint (SOURCE_FILE ("gtl_debugger_parser.galgas", 99)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 99))  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 95)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
    GALGAS_lstring var_fileNameAndLineNum_2547 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 103)) ;
    GALGAS_stringlist var_components_2574 = var_fileNameAndLineNum_2547.getter_string (SOURCE_FILE ("gtl_debugger_parser.galgas", 104)).getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 104)) ;
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, var_components_2574.getter_length (SOURCE_FILE ("gtl_debugger_parser.galgas", 105)).objectCompare (GALGAS_uint ((uint32_t) 2U))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_string var_fileName_2699 = var_components_2574.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 106)) ;
      GALGAS_string var_lineNum_2753 = var_components_2574.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 107)) ;
      outArgument_instruction = GALGAS_gtlBreakpointInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 109)), GALGAS_string::makeEmptyString (), var_fileName_2699, var_lineNum_2753.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 112))  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 108)) ;
    }else if (kBoolFalse == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 115)), GALGAS_string ("Illegal breakpoint location"), fixItArray1  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 115)) ;
      outArgument_instruction.drop () ; // Release error dropped variable
    }
  } break ;
  case 4: {
    outArgument_instruction = GALGAS_gtlBreakpointListInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 119)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 118)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_break) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 71)) ;
  switch (select_gtl_5F_debugger_5F_parser_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_not) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 73)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 74)) ;
  } break ;
  case 2: {
    switch (select_gtl_5F_debugger_5F_parser_1 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 82)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2E_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 83)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 84)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 85)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 86)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 94)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 103)) ;
  } break ;
  case 4: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 130)) ;
  switch (select_gtl_5F_debugger_5F_parser_2 (inCompiler)) {
  case 1: {
    GALGAS_gtlInstruction var_instructionToStepDo_3334 ;
    nt_gtl_5F_step_5F_do_5F_command_ (var_instructionToStepDo_3334, inCompiler) ;
    outArgument_instruction = GALGAS_gtlDoInstInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 134)), GALGAS_string::makeEmptyString (), var_instructionToStepDo_3334  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 133)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_not) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 139)) ;
    GALGAS_lbigint var_num_3505 = inCompiler->synthetizedAttribute_intValue () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 140)) ;
    outArgument_instruction = GALGAS_gtlDoNotInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 142)), GALGAS_string::makeEmptyString (), var_num_3505  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 141)) ;
  } break ;
  case 3: {
    outArgument_instruction = GALGAS_gtlDoInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 148)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 147)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 130)) ;
  switch (select_gtl_5F_debugger_5F_parser_2 (inCompiler)) {
  case 1: {
    nt_gtl_5F_step_5F_do_5F_command_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_not) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 139)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 140)) ;
  } break ;
  case 3: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  outArgument_instruction = GALGAS_gtlStepInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 159)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 158)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_let) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 168)) ;
  GALGAS_gtlVarPath var_variable_4076 ;
  nt_gtl_5F_variable_ (var_variable_4076, inCompiler) ;
  switch (select_gtl_5F_debugger_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 171)) ;
    GALGAS_gtlExpression var_expression_4142 ;
    nt_gtl_5F_expression_ (var_expression_4142, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 174)), GALGAS_string::makeEmptyString (), var_variable_4076, var_expression_4142  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 173)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 180)) ;
    GALGAS_gtlExpression var_expression_4312 ;
    nt_gtl_5F_expression_ (var_expression_4312, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetAddInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 183)), GALGAS_string::makeEmptyString (), var_variable_4076, var_expression_4312  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 182)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 189)) ;
    GALGAS_gtlExpression var_expression_4484 ;
    nt_gtl_5F_expression_ (var_expression_4484, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetSubstractInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 192)), GALGAS_string::makeEmptyString (), var_variable_4076, var_expression_4484  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 191)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 198)) ;
    GALGAS_gtlExpression var_expression_4662 ;
    nt_gtl_5F_expression_ (var_expression_4662, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetMultiplyInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 201)), GALGAS_string::makeEmptyString (), var_variable_4076, var_expression_4662  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 200)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 207)) ;
    GALGAS_gtlExpression var_expression_4839 ;
    nt_gtl_5F_expression_ (var_expression_4839, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetDivideInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 210)), GALGAS_string::makeEmptyString (), var_variable_4076, var_expression_4839  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 209)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod_3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 216)) ;
    GALGAS_gtlExpression var_expression_5016 ;
    nt_gtl_5F_expression_ (var_expression_5016, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetModuloInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 219)), GALGAS_string::makeEmptyString (), var_variable_4076, var_expression_5016  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 218)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 225)) ;
    GALGAS_gtlExpression var_expression_5192 ;
    nt_gtl_5F_expression_ (var_expression_5192, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetShiftLeftInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 228)), GALGAS_string::makeEmptyString (), var_variable_4076, var_expression_5192  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 227)) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 234)) ;
    GALGAS_gtlExpression var_expression_5371 ;
    nt_gtl_5F_expression_ (var_expression_5371, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetShiftRightInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 237)), GALGAS_string::makeEmptyString (), var_variable_4076, var_expression_5371  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 236)) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 243)) ;
    GALGAS_gtlExpression var_expression_5550 ;
    nt_gtl_5F_expression_ (var_expression_5550, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetAndInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 246)), GALGAS_string::makeEmptyString (), var_variable_4076, var_expression_5550  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 245)) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 252)) ;
    GALGAS_gtlExpression var_expression_5722 ;
    nt_gtl_5F_expression_ (var_expression_5722, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetOrInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 255)), GALGAS_string::makeEmptyString (), var_variable_4076, var_expression_5722  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 254)) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 261)) ;
    GALGAS_gtlExpression var_expression_5893 ;
    nt_gtl_5F_expression_ (var_expression_5893, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetXorInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 264)), GALGAS_string::makeEmptyString (), var_variable_4076, var_expression_5893  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 263)) ;
  } break ;
  case 12: {
    outArgument_instruction = GALGAS_gtlLetUnconstructedInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 271)), GALGAS_string::makeEmptyString (), var_variable_4076  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 270)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_let) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 168)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_debugger_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 171)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 180)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 189)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 198)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 207)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod_3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 216)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 225)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 234)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 243)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 252)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E__3D_) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 261)) ;
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

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_unlet) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 282)) ;
  GALGAS_gtlVarPath var_variable_6307 ;
  nt_gtl_5F_variable_ (var_variable_6307, inCompiler) ;
  outArgument_instruction = GALGAS_gtlUnletInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 285)), GALGAS_string::makeEmptyString (), var_variable_6307  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 284)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_unlet) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 282)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i7_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                       C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  nt_gtl_5F_step_5F_do_5F_command_ (outArgument_instruction, inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_step_5F_do_5F_command_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i8_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                         C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_variables) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 302)) ;
  outArgument_instruction = GALGAS_gtlVariablesInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 304)), GALGAS_string::makeEmptyString (), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 303)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_variables) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 302)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i9_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                         C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_display) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 314)) ;
  GALGAS_gtlVarPath var_variable_6999 ;
  nt_gtl_5F_variable_ (var_variable_6999, inCompiler) ;
  outArgument_instruction = GALGAS_gtlDisplayStatementInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 317)), GALGAS_string::makeEmptyString (), var_variable_6999  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 316)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_display) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 314)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i10_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                          C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_print) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 327)) ;
  GALGAS_gtlExpression var_expression_7292 ;
  nt_gtl_5F_expression_ (var_expression_7292, inCompiler) ;
  outArgument_instruction = GALGAS_gtlPrintStatementInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 330)), GALGAS_string::makeEmptyString (), GALGAS_bool (true), var_expression_7292  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 329)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i10_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_print) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 327)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i11_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                          C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_here) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 341)) ;
  outArgument_instruction = GALGAS_gtlHereInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 343)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 342)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_debugger_5F_parser::rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i11_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_here) COMMA_SOURCE_FILE ("gtl_debugger_parser.galgas", 341)) ;
  inCompiler->resetTemplateString () ;
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

cTokenFor_goil_5F_lexique::cTokenFor_goil_5F_lexique (void) :
mLexicalAttribute_a_5F_string (),
mLexicalAttribute_att_5F_token (),
mLexicalAttribute_floatNumber (),
mLexicalAttribute_integerNumber (),
mLexicalAttribute_number () {
}

//---------------------------------------------------------------------------------------------------------------------*

C_Lexique_goil_5F_lexique::C_Lexique_goil_5F_lexique (C_Compiler * inCallerCompiler,
                                                      const C_String & inDependencyFileExtension,
                                                      const C_String & inDependencyFilePath,
                                                      const C_String & inSourceFileName
                                                      COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inDependencyFileExtension, inDependencyFilePath, inSourceFileName COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

C_Lexique_goil_5F_lexique::C_Lexique_goil_5F_lexique (C_Compiler * inCallerCompiler,
                                                      const C_String & inSourceString,
                                                      const C_String & inStringForError
                                                      COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                 I N D E X I N G    D I R E C T O R Y                                                                *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_goil_5F_lexique::indexingDirectory (void) const {
  return "" ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                        Lexical error message list                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

static const char * gLexicalMessage_goil_5F_lexique_decimalNumberTooLarge = "decimal number too large" ;

static const char * gLexicalMessage_goil_5F_lexique_illegalEscape = "Illegal escaped character" ;

static const char * gLexicalMessage_goil_5F_lexique_internalError = "internal error" ;

static const char * gLexicalMessage_goil_5F_lexique_unableToConvertToDouble = "Unable to convert the string to double" ;

static const char * gLexicalMessage_goil_5F_lexique_unterminatedLitteralString = "Unterminated literal string" ;

static const char * gLexicalMessage_goil_5F_lexique_unterminated_comment_error = "unterminated comment" ;

//---------------------------------------------------------------------------------------------------------------------*
//          Syntax error messages, for every terminal symbol                                                           *
//---------------------------------------------------------------------------------------------------------------------*

//--- Syntax error message for terminal '$comment$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_comment = "a comment" ;

//--- Syntax error message for terminal '$idf$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_idf = "identifier" ;

//--- Syntax error message for terminal '$string$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_string = "literal string" ;

//--- Syntax error message for terminal '$g_string$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_g_5F_string = "in search path" ;

//--- Syntax error message for terminal '$uint_number$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_uint_5F_number = "literal unsigned 64 bits integer" ;

//--- Syntax error message for terminal '$float_number$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_float_5F_number = "literal float" ;

//--- Syntax error message for terminal '$set_start_uint_number$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_set_5F_start_5F_uint_5F_number = "literal unsigned 64 bits integer" ;

//--- Syntax error message for terminal '$command$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_command = "command" ;

//--- Syntax error message for terminal '$OIL_VERSION$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_OIL_5F_VERSION = "OIL version" ;

//--- Syntax error message for terminal '$IMPLEMENTATION$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_IMPLEMENTATION = "OIL implementation definition" ;

//--- Syntax error message for terminal '$CPU$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_CPU = "OIL implementation definition" ;

//--- Syntax error message for terminal '$UINT32$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_UINT_33__32_ = "type 'UINT32'" ;

//--- Syntax error message for terminal '$INT32$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_INT_33__32_ = "type 'INT32'" ;

//--- Syntax error message for terminal '$UINT64$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_UINT_36__34_ = "type 'UINT64'" ;

//--- Syntax error message for terminal '$INT64$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_INT_36__34_ = "type 'INT64'" ;

//--- Syntax error message for terminal '$FLOAT$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_FLOAT = "type 'FLOAT'" ;

//--- Syntax error message for terminal '$ENUM$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_ENUM = "type 'ENUM'" ;

//--- Syntax error message for terminal '$STRING$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_STRING = "type 'STRING'" ;

//--- Syntax error message for terminal '$BOOLEAN$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_BOOLEAN = "type 'BOOLEAN'" ;

//--- Syntax error message for terminal '$IDENTIFIER$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_IDENTIFIER = "type 'IDENTIFIER'" ;

//--- Syntax error message for terminal '$STRUCT$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_STRUCT = "type 'STRUCT'" ;

//--- Syntax error message for terminal '$WITH_AUTO$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_WITH_5F_AUTO = "specifier 'WITH_AUTO'" ;

//--- Syntax error message for terminal '$NO_DEFAULT$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_NO_5F_DEFAULT = "specifier 'NO_DEFAULT'" ;

//--- Syntax error message for terminal '$AUTO$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_AUTO = "specifier 'AUTO'" ;

//--- Syntax error message for terminal '$FALSE$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_FALSE = "boolean 'FALSE'" ;

//--- Syntax error message for terminal '$TRUE$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_TRUE = "boolean 'TRUE'" ;

//--- Syntax error message for terminal '$;$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique__3B_ = "';' delimiter" ;

//--- Syntax error message for terminal '$:$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique__3A_ = "':' delimiter" ;

//--- Syntax error message for terminal '$=$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique__3D_ = "'=' delimiter" ;

//--- Syntax error message for terminal '${$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique__7B_ = "'{' delimiter" ;

//--- Syntax error message for terminal '$}$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique__7D_ = "'}' delimiter" ;

//--- Syntax error message for terminal '$..$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique__2E__2E_ = "'..' delimiter" ;

//--- Syntax error message for terminal '$[$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique__5B_ = "'[' delimiter" ;

//--- Syntax error message for terminal '$]$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique__5D_ = "']' delimiter" ;

//--- Syntax error message for terminal '$,$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique__2C_ = "',' delimiter" ;

//--- Syntax error message for terminal '$.$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique__2E_ = "'.' delimiter" ;

//--- Syntax error message for terminal '$+$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique__2B_ = "'+' delimiter" ;

//--- Syntax error message for terminal '$-$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique__2D_ = "'-' delimiter" ;

//--- Syntax error message for terminal '$include$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_include = "command 'include'" ;

//--- Syntax error message for terminal '$includeifexists$' :
static const char * gSyntaxErrorMessage_goil_5F_lexique_includeifexists = "command 'includeifexists'" ;

//---------------------------------------------------------------------------------------------------------------------*
//                getMessageForTerminal                                                                                *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_goil_5F_lexique::getMessageForTerminal (const int16_t inTerminalIndex) const {
  static const char * syntaxErrorMessageArray [41] = {kEndOfSourceLexicalErrorMessage,
    gSyntaxErrorMessage_goil_5F_lexique_comment,
    gSyntaxErrorMessage_goil_5F_lexique_idf,
    gSyntaxErrorMessage_goil_5F_lexique_string,
    gSyntaxErrorMessage_goil_5F_lexique_g_5F_string,
    gSyntaxErrorMessage_goil_5F_lexique_uint_5F_number,
    gSyntaxErrorMessage_goil_5F_lexique_float_5F_number,
    gSyntaxErrorMessage_goil_5F_lexique_set_5F_start_5F_uint_5F_number,
    gSyntaxErrorMessage_goil_5F_lexique_command,
    gSyntaxErrorMessage_goil_5F_lexique_OIL_5F_VERSION,
    gSyntaxErrorMessage_goil_5F_lexique_IMPLEMENTATION,
    gSyntaxErrorMessage_goil_5F_lexique_CPU,
    gSyntaxErrorMessage_goil_5F_lexique_UINT_33__32_,
    gSyntaxErrorMessage_goil_5F_lexique_INT_33__32_,
    gSyntaxErrorMessage_goil_5F_lexique_UINT_36__34_,
    gSyntaxErrorMessage_goil_5F_lexique_INT_36__34_,
    gSyntaxErrorMessage_goil_5F_lexique_FLOAT,
    gSyntaxErrorMessage_goil_5F_lexique_ENUM,
    gSyntaxErrorMessage_goil_5F_lexique_STRING,
    gSyntaxErrorMessage_goil_5F_lexique_BOOLEAN,
    gSyntaxErrorMessage_goil_5F_lexique_IDENTIFIER,
    gSyntaxErrorMessage_goil_5F_lexique_STRUCT,
    gSyntaxErrorMessage_goil_5F_lexique_WITH_5F_AUTO,
    gSyntaxErrorMessage_goil_5F_lexique_NO_5F_DEFAULT,
    gSyntaxErrorMessage_goil_5F_lexique_AUTO,
    gSyntaxErrorMessage_goil_5F_lexique_FALSE,
    gSyntaxErrorMessage_goil_5F_lexique_TRUE,
    gSyntaxErrorMessage_goil_5F_lexique__3B_,
    gSyntaxErrorMessage_goil_5F_lexique__3A_,
    gSyntaxErrorMessage_goil_5F_lexique__3D_,
    gSyntaxErrorMessage_goil_5F_lexique__7B_,
    gSyntaxErrorMessage_goil_5F_lexique__7D_,
    gSyntaxErrorMessage_goil_5F_lexique__2E__2E_,
    gSyntaxErrorMessage_goil_5F_lexique__5B_,
    gSyntaxErrorMessage_goil_5F_lexique__5D_,
    gSyntaxErrorMessage_goil_5F_lexique__2C_,
    gSyntaxErrorMessage_goil_5F_lexique__2E_,
    gSyntaxErrorMessage_goil_5F_lexique__2B_,
    gSyntaxErrorMessage_goil_5F_lexique__2D_,
    gSyntaxErrorMessage_goil_5F_lexique_include,
    gSyntaxErrorMessage_goil_5F_lexique_includeifexists} ;
  return syntaxErrorMessageArray [inTerminalIndex] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                      U N I C O D E    S T R I N G S                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'OILDelimiters'                            *
//---------------------------------------------------------------------------------------------------------------------*

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

int16_t C_Lexique_goil_5F_lexique::search_into_OILDelimiters (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_OILDelimiters, ktable_size_goil_5F_lexique_OILDelimiters) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'boolean'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_goil_5F_lexique_boolean = 2 ;

static const C_unicode_lexique_table_entry ktable_for_goil_5F_lexique_boolean [ktable_size_goil_5F_lexique_boolean] = {
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_TRUE, 4, C_Lexique_goil_5F_lexique::kToken_TRUE),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_FALSE, 5, C_Lexique_goil_5F_lexique::kToken_FALSE)
} ;

int16_t C_Lexique_goil_5F_lexique::search_into_boolean (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_boolean, ktable_size_goil_5F_lexique_boolean) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'commands'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_goil_5F_lexique_commands = 2 ;

static const C_unicode_lexique_table_entry ktable_for_goil_5F_lexique_commands [ktable_size_goil_5F_lexique_commands] = {
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_include, 7, C_Lexique_goil_5F_lexique::kToken_include),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_includeifexists, 15, C_Lexique_goil_5F_lexique::kToken_includeifexists)
} ;

int16_t C_Lexique_goil_5F_lexique::search_into_commands (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_commands, ktable_size_goil_5F_lexique_commands) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'dataTypes'                            *
//---------------------------------------------------------------------------------------------------------------------*

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

int16_t C_Lexique_goil_5F_lexique::search_into_dataTypes (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_dataTypes, ktable_size_goil_5F_lexique_dataTypes) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'miscSpecifiers'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_goil_5F_lexique_miscSpecifiers = 3 ;

static const C_unicode_lexique_table_entry ktable_for_goil_5F_lexique_miscSpecifiers [ktable_size_goil_5F_lexique_miscSpecifiers] = {
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_AUTO, 4, C_Lexique_goil_5F_lexique::kToken_AUTO),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_WITH_5F_AUTO, 9, C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_NO_5F_DEFAULT, 10, C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT)
} ;

int16_t C_Lexique_goil_5F_lexique::search_into_miscSpecifiers (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_miscSpecifiers, ktable_size_goil_5F_lexique_miscSpecifiers) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'oilDefinitions'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_goil_5F_lexique_oilDefinitions = 2 ;

static const C_unicode_lexique_table_entry ktable_for_goil_5F_lexique_oilDefinitions [ktable_size_goil_5F_lexique_oilDefinitions] = {
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_CPU, 3, C_Lexique_goil_5F_lexique::kToken_CPU),
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_IMPLEMENTATION, 14, C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION)
} ;

int16_t C_Lexique_goil_5F_lexique::search_into_oilDefinitions (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_oilDefinitions, ktable_size_goil_5F_lexique_oilDefinitions) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'oilVersion'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_goil_5F_lexique_oilVersion = 1 ;

static const C_unicode_lexique_table_entry ktable_for_goil_5F_lexique_oilVersion [ktable_size_goil_5F_lexique_oilVersion] = {
  C_unicode_lexique_table_entry (kUnicodeString_goil_5F_lexique_OIL_5F_VERSION, 11, C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION)
} ;

int16_t C_Lexique_goil_5F_lexique::search_into_oilVersion (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_goil_5F_lexique_oilVersion, ktable_size_goil_5F_lexique_oilVersion) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                          getCurrentTokenString                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_goil_5F_lexique::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_goil_5F_lexique * ptr = (const cTokenFor_goil_5F_lexique *) inTokenPtr ;
  C_String s ;
  if (ptr == NULL) {
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

bool C_Lexique_goil_5F_lexique::parseLexicalToken (void) {
  cTokenFor_goil_5F_lexique token ;
  mLoop = true ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
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
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        enterDroppedTerminal (kToken_comment) ;
      }else if (testForInputUTF32String (kUnicodeString_goil_5F_lexique__2F__2A_, 2, true)) {
        do {
          if (notTestForInputUTF32String (kUnicodeString_goil_5F_lexique__2A__2F_, 2, gLexicalMessage_goil_5F_lexique_unterminated_comment_error COMMA_LINE_AND_SOURCE_FILE)) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        enterDroppedTerminal (kToken_comment) ;
      }else if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
        do {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_att_5F_token, previousChar ()) ;
          if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
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
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
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
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
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
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        token.mTokenCode = kToken_uint_5F_number ;
        enterToken (token) ;
      }else if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        do {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_number, previousChar ()) ;
          ::scanner_routine_enterDigitIntoUInt64 (*this, previousChar (), token.mLexicalAttribute_integerNumber, gLexicalMessage_goil_5F_lexique_decimalNumberTooLarge, gLexicalMessage_goil_5F_lexique_internalError) ;
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (testForInputUTF32Char (TO_UNICODE ('.'))) {
          if (testForInputUTF32Char (TO_UNICODE ('.'))) {
            token.mTokenCode = kToken_set_5F_start_5F_uint_5F_number ;
            enterToken (token) ;
          }else{
            do {
              ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_number, previousChar ()) ;
              if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
              }else{
                mLoop = false ;
              }
            }while (mLoop) ;
            mLoop = true ;
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
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
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
      }
    }catch (const C_lexicalErrorException &) {
      token.mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }
  if ((UNICODE_VALUE (mCurrentChar) == '\0') && (token.mTemplateStringBeforeToken.length () > 0)) {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         E N T E R    T O K E N                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

void C_Lexique_goil_5F_lexique::enterToken (cTokenFor_goil_5F_lexique & ioToken) {
  cTokenFor_goil_5F_lexique * ptr = NULL ;
  macroMyNew (ptr, cTokenFor_goil_5F_lexique ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
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

//---------------------------------------------------------------------------------------------------------------------*
//               A T T R I B U T E   A C C E S S                                                                       *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_goil_5F_lexique::attributeValue_a_5F_string (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_a_5F_string ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_goil_5F_lexique::attributeValue_att_5F_token (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_att_5F_token ;
}

//---------------------------------------------------------------------------------------------------------------------*

double C_Lexique_goil_5F_lexique::attributeValue_floatNumber (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_floatNumber ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint64_t C_Lexique_goil_5F_lexique::attributeValue_integerNumber (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_integerNumber ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_goil_5F_lexique::attributeValue_number (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_number ;
}

//---------------------------------------------------------------------------------------------------------------------*
//         A S S I G N    F R O M    A T T R I B U T E                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_goil_5F_lexique::synthetizedAttribute_a_5F_string (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_goil_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_a_5F_string) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_goil_5F_lexique::synthetizedAttribute_att_5F_token (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_goil_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_att_5F_token) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ldouble C_Lexique_goil_5F_lexique::synthetizedAttribute_floatNumber (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_goil_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_double value (ptr->mLexicalAttribute_floatNumber) ;
  GALGAS_ldouble result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint_36__34_ C_Lexique_goil_5F_lexique::synthetizedAttribute_integerNumber (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_goil_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint_36__34_ value (ptr->mLexicalAttribute_integerNumber) ;
  GALGAS_luint_36__34_ result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_goil_5F_lexique::synthetizedAttribute_number (void) const {
  cTokenFor_goil_5F_lexique * ptr = (cTokenFor_goil_5F_lexique *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_goil_5F_lexique) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_number) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         I N T R O S P E C T I O N                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

static void getKeywordLists_goil_5F_lexique (TC_UniqueArray <C_String> & ioList) {
  ioList.addObject ("goil_lexique:OILDelimiters") ;
  ioList.addObject ("goil_lexique:boolean") ;
  ioList.addObject ("goil_lexique:commands") ;
  ioList.addObject ("goil_lexique:dataTypes") ;
  ioList.addObject ("goil_lexique:miscSpecifiers") ;
  ioList.addObject ("goil_lexique:oilDefinitions") ;
  ioList.addObject ("goil_lexique:oilVersion") ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void getKeywordsForIdentifier_goil_5F_lexique (const C_String & inIdentifier,
                                                      bool & ioFound,
                                                      TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "goil_lexique:OILDelimiters") {
    ioFound = true ;
    ioList.addObject ("+") ;
    ioList.addObject (",") ;
    ioList.addObject ("-") ;
    ioList.addObject (".") ;
    ioList.addObject (":") ;
    ioList.addObject (";") ;
    ioList.addObject ("=") ;
    ioList.addObject ("[") ;
    ioList.addObject ("]") ;
    ioList.addObject ("{") ;
    ioList.addObject ("}") ;
    ioList.addObject ("..") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "goil_lexique:boolean") {
    ioFound = true ;
    ioList.addObject ("TRUE") ;
    ioList.addObject ("FALSE") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "goil_lexique:commands") {
    ioFound = true ;
    ioList.addObject ("include") ;
    ioList.addObject ("includeifexists") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "goil_lexique:dataTypes") {
    ioFound = true ;
    ioList.addObject ("ENUM") ;
    ioList.addObject ("FLOAT") ;
    ioList.addObject ("INT32") ;
    ioList.addObject ("INT64") ;
    ioList.addObject ("STRING") ;
    ioList.addObject ("STRUCT") ;
    ioList.addObject ("UINT32") ;
    ioList.addObject ("UINT64") ;
    ioList.addObject ("BOOLEAN") ;
    ioList.addObject ("IDENTIFIER") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "goil_lexique:miscSpecifiers") {
    ioFound = true ;
    ioList.addObject ("AUTO") ;
    ioList.addObject ("WITH_AUTO") ;
    ioList.addObject ("NO_DEFAULT") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "goil_lexique:oilDefinitions") {
    ioFound = true ;
    ioList.addObject ("CPU") ;
    ioList.addObject ("IMPLEMENTATION") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "goil_lexique:oilVersion") {
    ioFound = true ;
    ioList.addObject ("OIL_VERSION") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static cLexiqueIntrospection lexiqueIntrospection_goil_5F_lexique
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_goil_5F_lexique, getKeywordsForIdentifier_goil_5F_lexique) ;

//---------------------------------------------------------------------------------------------------------------------*
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                                            *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType::GALGAS_dataType (void) :
mEnum (kNotBuilt) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::constructor_void (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_void ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::constructor_uint_33__32_Number (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_uint_33__32_Number ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::constructor_sint_33__32_Number (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_sint_33__32_Number ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::constructor_uint_36__34_Number (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_uint_36__34_Number ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::constructor_sint_36__34_Number (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_sint_36__34_Number ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::constructor_floatNumber (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_floatNumber ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::constructor_string (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_string ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::constructor_enumeration (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_enumeration ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::constructor_boolean (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_boolean ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::constructor_identifier (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_identifier ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::constructor_objectType (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_objectType ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::constructor_structType (UNUSED_LOCATION_ARGS) {
  GALGAS_dataType result ;
  result.mEnum = kEnum_structType ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_dataType::getter_isVoid (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_void == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_dataType::getter_isUint_33__32_Number (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_uint_33__32_Number == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_dataType::getter_isSint_33__32_Number (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_sint_33__32_Number == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_dataType::getter_isUint_36__34_Number (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_uint_36__34_Number == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_dataType::getter_isSint_36__34_Number (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_sint_36__34_Number == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_dataType::getter_isFloatNumber (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_floatNumber == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_dataType::getter_isString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_string == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_dataType::getter_isEnumeration (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_enumeration == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_dataType::getter_isBoolean (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_boolean == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_dataType::getter_isIdentifier (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_identifier == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_dataType::getter_isObjectType (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_objectType == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_dataType::getter_isStructType (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_structType == mEnum) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_dataType::description (C_String & ioString,
                                   const int32_t /* inIndentation */) const {
  ioString << "<enum @dataType: " << gEnumNameArrayFor_dataType [mEnum] ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @dataType type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_dataType ("dataType",
                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_dataType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_dataType ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_dataType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_dataType (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_dataType::extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_dataType result ;
  const GALGAS_dataType * p = (const GALGAS_dataType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_dataType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("dataType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@uint_33__32_List' list                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_uint_33__32_List : public cCollectionElement {
  public : GALGAS_uint_33__32_List_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_uint_33__32_List (const GALGAS_location & in_location,
                                                const GALGAS_uint & in_value
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

cCollectionElement_uint_33__32_List::cCollectionElement_uint_33__32_List (const GALGAS_location & in_location,
                                                                          const GALGAS_uint & in_value
                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location, in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_uint_33__32_List::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_uint_33__32_List::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_uint_33__32_List (mObject.mAttribute_location, mObject.mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_uint_33__32_List::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mAttribute_location.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_uint_33__32_List::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_uint_33__32_List * operand = (cCollectionElement_uint_33__32_List *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_uint_33__32_List) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List::GALGAS_uint_33__32_List (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List::GALGAS_uint_33__32_List (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_uint_33__32_List result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::constructor_listWithValue (const GALGAS_location & inOperand0,
                                                                            const GALGAS_uint & inOperand1
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_List result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_uint_33__32_List::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_33__32_List::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                         const GALGAS_location & in_location,
                                                         const GALGAS_uint & in_value
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_uint_33__32_List * p = NULL ;
  macroMyNew (p, cCollectionElement_uint_33__32_List (in_location,
                                                      in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_33__32_List::addAssign_operation (const GALGAS_location & inOperand0,
                                                   const GALGAS_uint & inOperand1
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_uint_33__32_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_33__32_List::setter_insertAtIndex (const GALGAS_location inOperand0,
                                                    const GALGAS_uint inOperand1,
                                                    const GALGAS_uint inInsertionIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_uint_33__32_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_33__32_List::setter_removeAtIndex (GALGAS_location & outOperand0,
                                                    GALGAS_uint & outOperand1,
                                                    const GALGAS_uint inRemoveIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
      outOperand0 = p->mObject.mAttribute_location ;
      outOperand1 = p->mObject.mAttribute_value ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_33__32_List::setter_popFirst (GALGAS_location & outOperand0,
                                               GALGAS_uint & outOperand1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_33__32_List::setter_popLast (GALGAS_location & outOperand0,
                                              GALGAS_uint & outOperand1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_33__32_List::method_first (GALGAS_location & outOperand0,
                                            GALGAS_uint & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_33__32_List::method_last (GALGAS_location & outOperand0,
                                           GALGAS_uint & outOperand1,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::getter_subListWithRange (const GALGAS_range & inRange,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uint_33__32_List result = GALGAS_uint_33__32_List::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uint_33__32_List result = GALGAS_uint_33__32_List::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uint_33__32_List result = GALGAS_uint_33__32_List::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_33__32_List::plusAssign_operation (const GALGAS_uint_33__32_List inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_uint_33__32_List::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    result = p->mObject.mAttribute_location ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint_33__32_List::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_33__32_List * p = (cCollectionElement_uint_33__32_List *) attributes.ptr () ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
    result = p->mObject.mAttribute_value ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_uint_33__32_List::cEnumerator_uint_33__32_List (const GALGAS_uint_33__32_List & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List_2D_element cEnumerator_uint_33__32_List::current (LOCATION_ARGS) const {
  const cCollectionElement_uint_33__32_List * p = (const cCollectionElement_uint_33__32_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_uint_33__32_List::current_location (LOCATION_ARGS) const {
  const cCollectionElement_uint_33__32_List * p = (const cCollectionElement_uint_33__32_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
  return p->mObject.mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cEnumerator_uint_33__32_List::current_value (LOCATION_ARGS) const {
  const cCollectionElement_uint_33__32_List * p = (const cCollectionElement_uint_33__32_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_33__32_List) ;
  return p->mObject.mAttribute_value ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @uint32List type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32_List ("uint32List",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_33__32_List::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_List ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_33__32_List::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32_List (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List GALGAS_uint_33__32_List::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_List result ;
  const GALGAS_uint_33__32_List * p = (const GALGAS_uint_33__32_List *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_33__32_List *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32List", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@uint_36__34_List' list                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_uint_36__34_List : public cCollectionElement {
  public : GALGAS_uint_36__34_List_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_uint_36__34_List (const GALGAS_location & in_location,
                                                const GALGAS_uint_36__34_ & in_value
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

cCollectionElement_uint_36__34_List::cCollectionElement_uint_36__34_List (const GALGAS_location & in_location,
                                                                          const GALGAS_uint_36__34_ & in_value
                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location, in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_uint_36__34_List::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_uint_36__34_List::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_uint_36__34_List (mObject.mAttribute_location, mObject.mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_uint_36__34_List::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mAttribute_location.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_uint_36__34_List::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_uint_36__34_List * operand = (cCollectionElement_uint_36__34_List *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_uint_36__34_List) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List::GALGAS_uint_36__34_List (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List::GALGAS_uint_36__34_List (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_uint_36__34_List result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::constructor_listWithValue (const GALGAS_location & inOperand0,
                                                                            const GALGAS_uint_36__34_ & inOperand1
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_List result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_uint_36__34_List::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_List::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                         const GALGAS_location & in_location,
                                                         const GALGAS_uint_36__34_ & in_value
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_uint_36__34_List * p = NULL ;
  macroMyNew (p, cCollectionElement_uint_36__34_List (in_location,
                                                      in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_List::addAssign_operation (const GALGAS_location & inOperand0,
                                                   const GALGAS_uint_36__34_ & inOperand1
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_uint_36__34_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_List::setter_insertAtIndex (const GALGAS_location inOperand0,
                                                    const GALGAS_uint_36__34_ inOperand1,
                                                    const GALGAS_uint inInsertionIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_uint_36__34_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_List::setter_removeAtIndex (GALGAS_location & outOperand0,
                                                    GALGAS_uint_36__34_ & outOperand1,
                                                    const GALGAS_uint inRemoveIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
      outOperand0 = p->mObject.mAttribute_location ;
      outOperand1 = p->mObject.mAttribute_value ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_List::setter_popFirst (GALGAS_location & outOperand0,
                                               GALGAS_uint_36__34_ & outOperand1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_List::setter_popLast (GALGAS_location & outOperand0,
                                              GALGAS_uint_36__34_ & outOperand1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_List::method_first (GALGAS_location & outOperand0,
                                            GALGAS_uint_36__34_ & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_List::method_last (GALGAS_location & outOperand0,
                                           GALGAS_uint_36__34_ & outOperand1,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::getter_subListWithRange (const GALGAS_range & inRange,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_List result = GALGAS_uint_36__34_List::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_List result = GALGAS_uint_36__34_List::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_List result = GALGAS_uint_36__34_List::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_uint_36__34_List::plusAssign_operation (const GALGAS_uint_36__34_List inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_uint_36__34_List::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    result = p->mObject.mAttribute_location ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_List::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_List * p = (cCollectionElement_uint_36__34_List *) attributes.ptr () ;
  GALGAS_uint_36__34_ result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
    result = p->mObject.mAttribute_value ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_uint_36__34_List::cEnumerator_uint_36__34_List (const GALGAS_uint_36__34_List & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List_2D_element cEnumerator_uint_36__34_List::current (LOCATION_ARGS) const {
  const cCollectionElement_uint_36__34_List * p = (const cCollectionElement_uint_36__34_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_uint_36__34_List::current_location (LOCATION_ARGS) const {
  const cCollectionElement_uint_36__34_List * p = (const cCollectionElement_uint_36__34_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
  return p->mObject.mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ cEnumerator_uint_36__34_List::current_value (LOCATION_ARGS) const {
  const cCollectionElement_uint_36__34_List * p = (const cCollectionElement_uint_36__34_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_36__34_List) ;
  return p->mObject.mAttribute_value ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @uint64List type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_List ("uint64List",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_36__34_List::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_List ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_36__34_List::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_List (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List GALGAS_uint_36__34_List::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_List result ;
  const GALGAS_uint_36__34_List * p = (const GALGAS_uint_36__34_List *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_36__34_List *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64List", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@sint_33__32_List' list                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_sint_33__32_List : public cCollectionElement {
  public : GALGAS_sint_33__32_List_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_sint_33__32_List (const GALGAS_location & in_location,
                                                const GALGAS_sint & in_value
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

cCollectionElement_sint_33__32_List::cCollectionElement_sint_33__32_List (const GALGAS_location & in_location,
                                                                          const GALGAS_sint & in_value
                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location, in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_sint_33__32_List::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_sint_33__32_List::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_sint_33__32_List (mObject.mAttribute_location, mObject.mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_sint_33__32_List::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mAttribute_location.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_sint_33__32_List::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_sint_33__32_List * operand = (cCollectionElement_sint_33__32_List *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_sint_33__32_List) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List::GALGAS_sint_33__32_List (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List::GALGAS_sint_33__32_List (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_sint_33__32_List result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::constructor_listWithValue (const GALGAS_location & inOperand0,
                                                                            const GALGAS_sint & inOperand1
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_List result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_sint_33__32_List::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_33__32_List::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                         const GALGAS_location & in_location,
                                                         const GALGAS_sint & in_value
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_sint_33__32_List * p = NULL ;
  macroMyNew (p, cCollectionElement_sint_33__32_List (in_location,
                                                      in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_33__32_List::addAssign_operation (const GALGAS_location & inOperand0,
                                                   const GALGAS_sint & inOperand1
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_sint_33__32_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_33__32_List::setter_insertAtIndex (const GALGAS_location inOperand0,
                                                    const GALGAS_sint inOperand1,
                                                    const GALGAS_uint inInsertionIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_sint_33__32_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_33__32_List::setter_removeAtIndex (GALGAS_location & outOperand0,
                                                    GALGAS_sint & outOperand1,
                                                    const GALGAS_uint inRemoveIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
      outOperand0 = p->mObject.mAttribute_location ;
      outOperand1 = p->mObject.mAttribute_value ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_33__32_List::setter_popFirst (GALGAS_location & outOperand0,
                                               GALGAS_sint & outOperand1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_33__32_List::setter_popLast (GALGAS_location & outOperand0,
                                              GALGAS_sint & outOperand1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_33__32_List::method_first (GALGAS_location & outOperand0,
                                            GALGAS_sint & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_33__32_List::method_last (GALGAS_location & outOperand0,
                                           GALGAS_sint & outOperand1,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::getter_subListWithRange (const GALGAS_range & inRange,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sint_33__32_List result = GALGAS_sint_33__32_List::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sint_33__32_List result = GALGAS_sint_33__32_List::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_sint_33__32_List result = GALGAS_sint_33__32_List::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_33__32_List::plusAssign_operation (const GALGAS_sint_33__32_List inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_sint_33__32_List::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    result = p->mObject.mAttribute_location ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint_33__32_List::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_33__32_List * p = (cCollectionElement_sint_33__32_List *) attributes.ptr () ;
  GALGAS_sint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
    result = p->mObject.mAttribute_value ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_sint_33__32_List::cEnumerator_sint_33__32_List (const GALGAS_sint_33__32_List & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List_2D_element cEnumerator_sint_33__32_List::current (LOCATION_ARGS) const {
  const cCollectionElement_sint_33__32_List * p = (const cCollectionElement_sint_33__32_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_sint_33__32_List::current_location (LOCATION_ARGS) const {
  const cCollectionElement_sint_33__32_List * p = (const cCollectionElement_sint_33__32_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
  return p->mObject.mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint cEnumerator_sint_33__32_List::current_value (LOCATION_ARGS) const {
  const cCollectionElement_sint_33__32_List * p = (const cCollectionElement_sint_33__32_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sint_33__32_List) ;
  return p->mObject.mAttribute_value ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @sint32List type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32_List ("sint32List",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_33__32_List::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_List ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_33__32_List::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32_List (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List GALGAS_sint_33__32_List::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_List result ;
  const GALGAS_sint_33__32_List * p = (const GALGAS_sint_33__32_List *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_33__32_List *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32List", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@sint_36__34_List' list                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_sint_36__34_List : public cCollectionElement {
  public : GALGAS_sint_36__34_List_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_sint_36__34_List (const GALGAS_location & in_location,
                                                const GALGAS_sint_36__34_ & in_value
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

cCollectionElement_sint_36__34_List::cCollectionElement_sint_36__34_List (const GALGAS_location & in_location,
                                                                          const GALGAS_sint_36__34_ & in_value
                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location, in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_sint_36__34_List::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_sint_36__34_List::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_sint_36__34_List (mObject.mAttribute_location, mObject.mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_sint_36__34_List::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mAttribute_location.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_sint_36__34_List::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_sint_36__34_List * operand = (cCollectionElement_sint_36__34_List *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_sint_36__34_List) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List::GALGAS_sint_36__34_List (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List::GALGAS_sint_36__34_List (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_sint_36__34_List result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::constructor_listWithValue (const GALGAS_location & inOperand0,
                                                                            const GALGAS_sint_36__34_ & inOperand1
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_List result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_sint_36__34_List::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_List::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                         const GALGAS_location & in_location,
                                                         const GALGAS_sint_36__34_ & in_value
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_sint_36__34_List * p = NULL ;
  macroMyNew (p, cCollectionElement_sint_36__34_List (in_location,
                                                      in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_List::addAssign_operation (const GALGAS_location & inOperand0,
                                                   const GALGAS_sint_36__34_ & inOperand1
                                                   COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_sint_36__34_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_List::setter_insertAtIndex (const GALGAS_location inOperand0,
                                                    const GALGAS_sint_36__34_ inOperand1,
                                                    const GALGAS_uint inInsertionIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_sint_36__34_List (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_List::setter_removeAtIndex (GALGAS_location & outOperand0,
                                                    GALGAS_sint_36__34_ & outOperand1,
                                                    const GALGAS_uint inRemoveIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
      outOperand0 = p->mObject.mAttribute_location ;
      outOperand1 = p->mObject.mAttribute_value ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_List::setter_popFirst (GALGAS_location & outOperand0,
                                               GALGAS_sint_36__34_ & outOperand1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_List::setter_popLast (GALGAS_location & outOperand0,
                                              GALGAS_sint_36__34_ & outOperand1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_List::method_first (GALGAS_location & outOperand0,
                                            GALGAS_sint_36__34_ & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_List::method_last (GALGAS_location & outOperand0,
                                           GALGAS_sint_36__34_ & outOperand1,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::getter_subListWithRange (const GALGAS_range & inRange,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_List result = GALGAS_sint_36__34_List::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_List result = GALGAS_sint_36__34_List::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_sint_36__34_List result = GALGAS_sint_36__34_List::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sint_36__34_List::plusAssign_operation (const GALGAS_sint_36__34_List inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_sint_36__34_List::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    result = p->mObject.mAttribute_location ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_List::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sint_36__34_List * p = (cCollectionElement_sint_36__34_List *) attributes.ptr () ;
  GALGAS_sint_36__34_ result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
    result = p->mObject.mAttribute_value ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_sint_36__34_List::cEnumerator_sint_36__34_List (const GALGAS_sint_36__34_List & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List_2D_element cEnumerator_sint_36__34_List::current (LOCATION_ARGS) const {
  const cCollectionElement_sint_36__34_List * p = (const cCollectionElement_sint_36__34_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_sint_36__34_List::current_location (LOCATION_ARGS) const {
  const cCollectionElement_sint_36__34_List * p = (const cCollectionElement_sint_36__34_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
  return p->mObject.mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ cEnumerator_sint_36__34_List::current_value (LOCATION_ARGS) const {
  const cCollectionElement_sint_36__34_List * p = (const cCollectionElement_sint_36__34_List *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sint_36__34_List) ;
  return p->mObject.mAttribute_value ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @sint64List type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_List ("sint64List",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_36__34_List::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_List ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_36__34_List::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_List (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List GALGAS_sint_36__34_List::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_List result ;
  const GALGAS_sint_36__34_List * p = (const GALGAS_sint_36__34_List *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_36__34_List *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64List", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Class for element of '@floatList' list                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_floatList : public cCollectionElement {
  public : GALGAS_floatList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_floatList (const GALGAS_location & in_location,
                                         const GALGAS_double & in_value
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

cCollectionElement_floatList::cCollectionElement_floatList (const GALGAS_location & in_location,
                                                            const GALGAS_double & in_value
                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location, in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_floatList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_floatList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_floatList (mObject.mAttribute_location, mObject.mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_floatList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mAttribute_location.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_floatList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_floatList * operand = (cCollectionElement_floatList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_floatList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList::GALGAS_floatList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList::GALGAS_floatList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList GALGAS_floatList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_floatList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList GALGAS_floatList::constructor_listWithValue (const GALGAS_location & inOperand0,
                                                              const GALGAS_double & inOperand1
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_floatList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_floatList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_floatList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const GALGAS_location & in_location,
                                                  const GALGAS_double & in_value
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_floatList * p = NULL ;
  macroMyNew (p, cCollectionElement_floatList (in_location,
                                               in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_floatList::addAssign_operation (const GALGAS_location & inOperand0,
                                            const GALGAS_double & inOperand1
                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_floatList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_floatList::setter_insertAtIndex (const GALGAS_location inOperand0,
                                             const GALGAS_double inOperand1,
                                             const GALGAS_uint inInsertionIndex,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_floatList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_floatList::setter_removeAtIndex (GALGAS_location & outOperand0,
                                             GALGAS_double & outOperand1,
                                             const GALGAS_uint inRemoveIndex,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_floatList) ;
      outOperand0 = p->mObject.mAttribute_location ;
      outOperand1 = p->mObject.mAttribute_value ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_floatList::setter_popFirst (GALGAS_location & outOperand0,
                                        GALGAS_double & outOperand1,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_floatList::setter_popLast (GALGAS_location & outOperand0,
                                       GALGAS_double & outOperand1,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_floatList::method_first (GALGAS_location & outOperand0,
                                     GALGAS_double & outOperand1,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_floatList::method_last (GALGAS_location & outOperand0,
                                    GALGAS_double & outOperand1,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList GALGAS_floatList::getter_subListWithRange (const GALGAS_range & inRange,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_floatList result = GALGAS_floatList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList GALGAS_floatList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_floatList result = GALGAS_floatList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList GALGAS_floatList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_floatList result = GALGAS_floatList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_floatList::plusAssign_operation (const GALGAS_floatList inOperand,
                                             C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_floatList::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    result = p->mObject.mAttribute_location ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_floatList::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_floatList * p = (cCollectionElement_floatList *) attributes.ptr () ;
  GALGAS_double result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_floatList) ;
    result = p->mObject.mAttribute_value ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_floatList::cEnumerator_floatList (const GALGAS_floatList & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList_2D_element cEnumerator_floatList::current (LOCATION_ARGS) const {
  const cCollectionElement_floatList * p = (const cCollectionElement_floatList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_floatList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_floatList::current_location (LOCATION_ARGS) const {
  const cCollectionElement_floatList * p = (const cCollectionElement_floatList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_floatList) ;
  return p->mObject.mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double cEnumerator_floatList::current_value (LOCATION_ARGS) const {
  const cCollectionElement_floatList * p = (const cCollectionElement_floatList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_floatList) ;
  return p->mObject.mAttribute_value ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @floatList type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_floatList ("floatList",
                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_floatList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_floatList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_floatList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList GALGAS_floatList::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_floatList result ;
  const GALGAS_floatList * p = (const GALGAS_floatList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_floatList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("floatList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Class for element of '@numberList' list                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_numberList : public cCollectionElement {
  public : GALGAS_numberList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_numberList (const GALGAS_location & in_location,
                                          const GALGAS_object_5F_t & in_value
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

cCollectionElement_numberList::cCollectionElement_numberList (const GALGAS_location & in_location,
                                                              const GALGAS_object_5F_t & in_value
                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_location, in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_numberList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_numberList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_numberList (mObject.mAttribute_location, mObject.mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_numberList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "location" ":" ;
  mObject.mAttribute_location.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_numberList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_numberList * operand = (cCollectionElement_numberList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_numberList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList::GALGAS_numberList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList::GALGAS_numberList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList GALGAS_numberList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_numberList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList GALGAS_numberList::constructor_listWithValue (const GALGAS_location & inOperand0,
                                                                const GALGAS_object_5F_t & inOperand1
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_numberList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_numberList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_numberList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                   const GALGAS_location & in_location,
                                                   const GALGAS_object_5F_t & in_value
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_numberList * p = NULL ;
  macroMyNew (p, cCollectionElement_numberList (in_location,
                                                in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_numberList::addAssign_operation (const GALGAS_location & inOperand0,
                                             const GALGAS_object_5F_t & inOperand1
                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_numberList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_numberList::setter_insertAtIndex (const GALGAS_location inOperand0,
                                              const GALGAS_object_5F_t inOperand1,
                                              const GALGAS_uint inInsertionIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_numberList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_numberList::setter_removeAtIndex (GALGAS_location & outOperand0,
                                              GALGAS_object_5F_t & outOperand1,
                                              const GALGAS_uint inRemoveIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
      outOperand1.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_numberList) ;
      outOperand0 = p->mObject.mAttribute_location ;
      outOperand1 = p->mObject.mAttribute_value ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_numberList::setter_popFirst (GALGAS_location & outOperand0,
                                         GALGAS_object_5F_t & outOperand1,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_numberList::setter_popLast (GALGAS_location & outOperand0,
                                        GALGAS_object_5F_t & outOperand1,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_numberList::method_first (GALGAS_location & outOperand0,
                                      GALGAS_object_5F_t & outOperand1,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_numberList::method_last (GALGAS_location & outOperand0,
                                     GALGAS_object_5F_t & outOperand1,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    outOperand0 = p->mObject.mAttribute_location ;
    outOperand1 = p->mObject.mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList GALGAS_numberList::getter_subListWithRange (const GALGAS_range & inRange,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_numberList result = GALGAS_numberList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList GALGAS_numberList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_numberList result = GALGAS_numberList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList GALGAS_numberList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_numberList result = GALGAS_numberList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_numberList::plusAssign_operation (const GALGAS_numberList inOperand,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_numberList::getter_locationAtIndex (const GALGAS_uint & inIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
  GALGAS_location result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    result = p->mObject.mAttribute_location ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t GALGAS_numberList::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_numberList * p = (cCollectionElement_numberList *) attributes.ptr () ;
  GALGAS_object_5F_t result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_numberList) ;
    result = p->mObject.mAttribute_value ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_numberList::cEnumerator_numberList (const GALGAS_numberList & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList_2D_element cEnumerator_numberList::current (LOCATION_ARGS) const {
  const cCollectionElement_numberList * p = (const cCollectionElement_numberList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_numberList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cEnumerator_numberList::current_location (LOCATION_ARGS) const {
  const cCollectionElement_numberList * p = (const cCollectionElement_numberList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_numberList) ;
  return p->mObject.mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t cEnumerator_numberList::current_value (LOCATION_ARGS) const {
  const cCollectionElement_numberList * p = (const cCollectionElement_numberList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_numberList) ;
  return p->mObject.mAttribute_value ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @numberList type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_numberList ("numberList",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_numberList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_numberList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_numberList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_numberList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList GALGAS_numberList::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_numberList result ;
  const GALGAS_numberList * p = (const GALGAS_numberList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_numberList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("numberList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}


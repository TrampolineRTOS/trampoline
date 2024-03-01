#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-0.h"

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@gtlDataList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_gtlDataList : public cCollectionElement {
  public: GALGAS_gtlDataList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_gtlDataList (const GALGAS_gtlData & in_data
                                          COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_gtlDataList (const GALGAS_gtlDataList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_gtlDataList::cCollectionElement_gtlDataList (const GALGAS_gtlData & in_data
                                                                COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_data) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_gtlDataList::cCollectionElement_gtlDataList (const GALGAS_gtlDataList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_data) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_gtlDataList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_gtlDataList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_gtlDataList (mObject.mProperty_data COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_gtlDataList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "data" ":" ;
  mObject.mProperty_data.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_gtlDataList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlDataList * operand = (cCollectionElement_gtlDataList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlDataList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList::GALGAS_gtlDataList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList::GALGAS_gtlDataList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList GALGAS_gtlDataList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlDataList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList GALGAS_gtlDataList::constructor_listWithValue (const GALGAS_gtlData & inOperand0
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlDataList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlDataList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_gtlDataList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDataList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                    const GALGAS_gtlData & in_data
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlDataList * p = nullptr ;
  macroMyNew (p, cCollectionElement_gtlDataList (in_data COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDataList::addAssign_operation (const GALGAS_gtlData & inOperand0
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlDataList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDataList::setter_append (const GALGAS_gtlData inOperand0,
                                        C_Compiler * /* inCompiler */
                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlDataList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDataList::setter_insertAtIndex (const GALGAS_gtlData inOperand0,
                                               const GALGAS_uint inInsertionIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_gtlDataList (inOperand0 COMMA_THERE)) ;
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

void GALGAS_gtlDataList::setter_removeAtIndex (GALGAS_gtlData & outOperand0,
                                               const GALGAS_uint inRemoveIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
        outOperand0 = p->mObject.mProperty_data ;
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

void GALGAS_gtlDataList::setter_popFirst (GALGAS_gtlData & outOperand0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    outOperand0 = p->mObject.mProperty_data ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDataList::setter_popLast (GALGAS_gtlData & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    outOperand0 = p->mObject.mProperty_data ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDataList::method_first (GALGAS_gtlData & outOperand0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    outOperand0 = p->mObject.mProperty_data ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDataList::method_last (GALGAS_gtlData & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    outOperand0 = p->mObject.mProperty_data ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList GALGAS_gtlDataList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_gtlDataList result = GALGAS_gtlDataList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList GALGAS_gtlDataList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_gtlDataList result = GALGAS_gtlDataList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList GALGAS_gtlDataList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlDataList result = GALGAS_gtlDataList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDataList::plusAssign_operation (const GALGAS_gtlDataList inOperand,
                                               C_Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDataList::setter_setDataAtIndex (GALGAS_gtlData inOperand,
                                                GALGAS_uint inIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_data = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData GALGAS_gtlDataList::getter_dataAtIndex (const GALGAS_uint & inIndex,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlDataList * p = (cCollectionElement_gtlDataList *) attributes.ptr () ;
  GALGAS_gtlData result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
    result = p->mObject.mProperty_data ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlDataList::cEnumerator_gtlDataList (const GALGAS_gtlDataList & inEnumeratedObject,
                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList_2D_element cEnumerator_gtlDataList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlDataList * p = (const cCollectionElement_gtlDataList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cEnumerator_gtlDataList::current_data (LOCATION_ARGS) const {
  const cCollectionElement_gtlDataList * p = (const cCollectionElement_gtlDataList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlDataList) ;
  return p->mObject.mProperty_data ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlDataList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDataList ("gtlDataList",
                                    nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlDataList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDataList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlDataList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDataList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList GALGAS_gtlDataList::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlDataList result ;
  const GALGAS_gtlDataList * p = (const GALGAS_gtlDataList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlDataList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDataList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@string stringByAppendingPath'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_stringByAppendingPath (const GALGAS_string & inObject,
                                                     const GALGAS_string & constinArgument_pathToAppend,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_string temp_1 = inObject ;
    test_0 = GALGAS_bool (kIsEqual, temp_1.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = constinArgument_pathToAppend ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      const GALGAS_string temp_3 = inObject ;
      test_2 = GALGAS_bool (kIsEqual, temp_3.getter_lastCharacter (inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 193)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        const GALGAS_string temp_4 = inObject ;
        result_result = temp_4.add_operation (constinArgument_pathToAppend, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 194)) ;
      }
    }
    if (kBoolFalse == test_2) {
      const GALGAS_string temp_5 = inObject ;
      result_result = temp_5.add_operation (GALGAS_char (TO_UNICODE (47)).getter_string (SOURCE_FILE ("gtl_types.galgas", 196)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 196)).add_operation (constinArgument_pathToAppend, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 196)) ;
    }
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlVarMap::cMapElement_gtlVarMap (const GALGAS_lstring & inKey,
                                              const GALGAS_gtlData & in_value
                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_gtlVarMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_gtlVarMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_gtlVarMap (mProperty_lkey, mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_gtlVarMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_gtlVarMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlVarMap * operand = (cMapElement_gtlVarMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (operand->mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap::GALGAS_gtlVarMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap::GALGAS_gtlVarMap (const GALGAS_gtlVarMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap & GALGAS_gtlVarMap::operator = (const GALGAS_gtlVarMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap GALGAS_gtlVarMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlVarMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap GALGAS_gtlVarMap::constructor_mapWithMapToOverride (const GALGAS_gtlVarMap & inMapToOverride
                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap GALGAS_gtlVarMap::getter_overriddenMap (C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarMap::addAssign_operation (const GALGAS_lstring & inKey,
                                            const GALGAS_gtlData & inArgument0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  cMapElement_gtlVarMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlVarMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlVarMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap GALGAS_gtlVarMap::add_operation (const GALGAS_gtlVarMap & inOperand,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarMap result = *this ;
  cEnumerator_gtlVarMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_value (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarMap::setter_put (GALGAS_lstring inKey,
                                   GALGAS_gtlData inArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
  cMapElement_gtlVarMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlVarMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a variable or field named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_gtlVarMap_get = "there is no variable or field named '%K'" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarMap::method_get (GALGAS_lstring inKey,
                                   GALGAS_gtlData & outArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) performSearch (inKey,
                                                                                   inCompiler,
                                                                                   kSearchErrorMessage_gtlVarMap_get
                                                                                   COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    outArgument0 = p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_gtlVarMap_getResult = "function did not return a value in '%K'" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarMap::method_getResult (GALGAS_lstring inKey,
                                         GALGAS_gtlData & outArgument0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) performSearch (inKey,
                                                                                   inCompiler,
                                                                                   kSearchErrorMessage_gtlVarMap_getResult
                                                                                   COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    outArgument0 = p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarMap::setter_del (GALGAS_lstring inKey,
                                   GALGAS_gtlData & outArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "there is no variable or field named '%K' to delete" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_gtlVarMap * p = (cMapElement_gtlVarMap *) attributes.ptr () ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    outArgument0 = p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData GALGAS_gtlVarMap::getter_valueForKey (const GALGAS_string & inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) attributes ;
  GALGAS_gtlData result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    result = p->mProperty_value ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarMap::setter_setValueForKey (GALGAS_gtlData inAttributeValue,
                                              GALGAS_string inKey,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_gtlVarMap * p = (cMapElement_gtlVarMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    p->mProperty_value = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlVarMap * GALGAS_gtlVarMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                             const GALGAS_string & inKey
                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_gtlVarMap * result = (cMapElement_gtlVarMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlVarMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlVarMap::cEnumerator_gtlVarMap (const GALGAS_gtlVarMap & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap_2D_element cEnumerator_gtlVarMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlVarMap) ;
  return GALGAS_gtlVarMap_2D_element (p->mProperty_lkey, p->mProperty_value) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_gtlVarMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cEnumerator_gtlVarMap::current_value (LOCATION_ARGS) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlVarMap) ;
  return p->mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlVarMap::optional_searchKey (const GALGAS_string & inKey,
                                           GALGAS_gtlData & outArgument0) const {
  const cMapElement_gtlVarMap * p = (const cMapElement_gtlVarMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_gtlVarMap) ;
    outArgument0 = p->mProperty_value ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlVarMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarMap ("gtlVarMap",
                                  nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlVarMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlVarMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap GALGAS_gtlVarMap::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarMap result ;
  const GALGAS_gtlVarMap * p = (const GALGAS_gtlVarMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlVarMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlVarMap replaceOrCreate'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionSetter_replaceOrCreate (GALGAS_gtlVarMap & ioObject,
                                      const GALGAS_lstring constinArgument_key,
                                      const GALGAS_gtlData constinArgument_data,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_gtlVarMap temp_1 = ioObject ;
    test_0 = temp_1.getter_hasKey (constinArgument_key.readProperty_string () COMMA_SOURCE_FILE ("gtl_types.galgas", 225)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      ioObject.setter_setValueForKey (constinArgument_data, constinArgument_key.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 226)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    {
    ioObject.setter_put (constinArgument_key, constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 228)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlVarMap replaceOrCreateAtLevel'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionSetter_replaceOrCreateAtLevel (GALGAS_gtlVarMap & ioObject,
                                             const GALGAS_lstring constinArgument_key,
                                             const GALGAS_gtlData constinArgument_data,
                                             const GALGAS_uint constinArgument_level,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_gtlVarMap temp_1 = ioObject ;
    test_0 = temp_1.getter_hasKeyAtLevel (constinArgument_key.readProperty_string (), constinArgument_level COMMA_SOURCE_FILE ("gtl_types.galgas", 237)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      GALGAS_gtlData joker_6050 ; // Joker input parameter
      ioObject.setter_del (constinArgument_key, joker_6050, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 238)) ;
      }
    }
  }
  {
  ioObject.setter_put (constinArgument_key, constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 240)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlExpressionMap::cMapElement_gtlExpressionMap (const GALGAS_lstring & inKey,
                                                            const GALGAS_gtlExpression & in_expression
                                                            COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_expression (in_expression) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_gtlExpressionMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_gtlExpressionMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_gtlExpressionMap (mProperty_lkey, mProperty_expression COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_gtlExpressionMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "expression" ":" ;
  mProperty_expression.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_gtlExpressionMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlExpressionMap * operand = (cMapElement_gtlExpressionMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_expression.objectCompare (operand->mProperty_expression) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap::GALGAS_gtlExpressionMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap::GALGAS_gtlExpressionMap (const GALGAS_gtlExpressionMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap & GALGAS_gtlExpressionMap::operator = (const GALGAS_gtlExpressionMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlExpressionMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::constructor_mapWithMapToOverride (const GALGAS_gtlExpressionMap & inMapToOverride
                                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                   const GALGAS_gtlExpression & inArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cMapElement_gtlExpressionMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlExpressionMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlExpressionMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::add_operation (const GALGAS_gtlExpressionMap & inOperand,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionMap result = *this ;
  cEnumerator_gtlExpressionMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_expression (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionMap::setter_put (GALGAS_lstring inKey,
                                          GALGAS_gtlExpression inArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_gtlExpressionMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlExpressionMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a field named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_gtlExpressionMap_get = "there is no field named '%K'" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionMap::method_get (GALGAS_lstring inKey,
                                          GALGAS_gtlExpression & outArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) performSearch (inKey,
                                                                                                 inCompiler,
                                                                                                 kSearchErrorMessage_gtlExpressionMap_get
                                                                                                 COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    outArgument0 = p->mProperty_expression ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionMap::setter_del (GALGAS_lstring inKey,
                                          GALGAS_gtlExpression & outArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "there is no field named '%K' to delete" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_gtlExpressionMap * p = (cMapElement_gtlExpressionMap *) attributes.ptr () ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    outArgument0 = p->mProperty_expression ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlExpressionMap::getter_expressionForKey (const GALGAS_string & inKey,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) attributes ;
  GALGAS_gtlExpression result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    result = p->mProperty_expression ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionMap::setter_setExpressionForKey (GALGAS_gtlExpression inAttributeValue,
                                                          GALGAS_string inKey,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_gtlExpressionMap * p = (cMapElement_gtlExpressionMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    p->mProperty_expression = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlExpressionMap * GALGAS_gtlExpressionMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) {
  cMapElement_gtlExpressionMap * result = (cMapElement_gtlExpressionMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlExpressionMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlExpressionMap::cEnumerator_gtlExpressionMap (const GALGAS_gtlExpressionMap & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap_2D_element cEnumerator_gtlExpressionMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
  return GALGAS_gtlExpressionMap_2D_element (p->mProperty_lkey, p->mProperty_expression) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_gtlExpressionMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cEnumerator_gtlExpressionMap::current_expression (LOCATION_ARGS) const {
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
  return p->mProperty_expression ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlExpressionMap::optional_searchKey (const GALGAS_string & inKey,
                                                  GALGAS_gtlExpression & outArgument0) const {
  const cMapElement_gtlExpressionMap * p = (const cMapElement_gtlExpressionMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_gtlExpressionMap) ;
    outArgument0 = p->mProperty_expression ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlExpressionMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpressionMap ("gtlExpressionMap",
                                         nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlExpressionMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpressionMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlExpressionMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpressionMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap GALGAS_gtlExpressionMap::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionMap result ;
  const GALGAS_gtlExpressionMap * p = (const GALGAS_gtlExpressionMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlExpressionMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExpressionMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@gtlInstructionList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_gtlInstructionList : public cCollectionElement {
  public: GALGAS_gtlInstructionList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_gtlInstructionList (const GALGAS_gtlInstruction & in_instruction
                                                 COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_gtlInstructionList (const GALGAS_gtlInstructionList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_gtlInstructionList::cCollectionElement_gtlInstructionList (const GALGAS_gtlInstruction & in_instruction
                                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_instruction) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_gtlInstructionList::cCollectionElement_gtlInstructionList (const GALGAS_gtlInstructionList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_instruction) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_gtlInstructionList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_gtlInstructionList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_gtlInstructionList (mObject.mProperty_instruction COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_gtlInstructionList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "instruction" ":" ;
  mObject.mProperty_instruction.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_gtlInstructionList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlInstructionList * operand = (cCollectionElement_gtlInstructionList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlInstructionList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList::GALGAS_gtlInstructionList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList::GALGAS_gtlInstructionList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlInstructionList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::constructor_listWithValue (const GALGAS_gtlInstruction & inOperand0
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlInstructionList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_gtlInstructionList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                           const GALGAS_gtlInstruction & in_instruction
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlInstructionList * p = nullptr ;
  macroMyNew (p, cCollectionElement_gtlInstructionList (in_instruction COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionList::addAssign_operation (const GALGAS_gtlInstruction & inOperand0
                                                     COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlInstructionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionList::setter_append (const GALGAS_gtlInstruction inOperand0,
                                               C_Compiler * /* inCompiler */
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlInstructionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionList::setter_insertAtIndex (const GALGAS_gtlInstruction inOperand0,
                                                      const GALGAS_uint inInsertionIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_gtlInstructionList (inOperand0 COMMA_THERE)) ;
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

void GALGAS_gtlInstructionList::setter_removeAtIndex (GALGAS_gtlInstruction & outOperand0,
                                                      const GALGAS_uint inRemoveIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
        outOperand0 = p->mObject.mProperty_instruction ;
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

void GALGAS_gtlInstructionList::setter_popFirst (GALGAS_gtlInstruction & outOperand0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    outOperand0 = p->mObject.mProperty_instruction ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionList::setter_popLast (GALGAS_gtlInstruction & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    outOperand0 = p->mObject.mProperty_instruction ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionList::method_first (GALGAS_gtlInstruction & outOperand0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    outOperand0 = p->mObject.mProperty_instruction ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionList::method_last (GALGAS_gtlInstruction & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    outOperand0 = p->mObject.mProperty_instruction ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result = GALGAS_gtlInstructionList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result = GALGAS_gtlInstructionList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionList result = GALGAS_gtlInstructionList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionList::plusAssign_operation (const GALGAS_gtlInstructionList inOperand,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionList::setter_setInstructionAtIndex (GALGAS_gtlInstruction inOperand,
                                                              GALGAS_uint inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_instruction = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstruction GALGAS_gtlInstructionList::getter_instructionAtIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionList * p = (cCollectionElement_gtlInstructionList *) attributes.ptr () ;
  GALGAS_gtlInstruction result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
    result = p->mObject.mProperty_instruction ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlInstructionList::cEnumerator_gtlInstructionList (const GALGAS_gtlInstructionList & inEnumeratedObject,
                                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList_2D_element cEnumerator_gtlInstructionList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlInstructionList * p = (const cCollectionElement_gtlInstructionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstruction cEnumerator_gtlInstructionList::current_instruction (LOCATION_ARGS) const {
  const cCollectionElement_gtlInstructionList * p = (const cCollectionElement_gtlInstructionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlInstructionList) ;
  return p->mObject.mProperty_instruction ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlInstructionList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInstructionList ("gtlInstructionList",
                                           nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlInstructionList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInstructionList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlInstructionList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInstructionList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlInstructionList::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionList result ;
  const GALGAS_gtlInstructionList * p = (const GALGAS_gtlInstructionList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlInstructionList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInstructionList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlTemplateMap::cMapElement_gtlTemplateMap (const GALGAS_lstring & inKey,
                                                        const GALGAS_gtlTemplate & in_aTemplate
                                                        COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_aTemplate (in_aTemplate) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_gtlTemplateMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_gtlTemplateMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_gtlTemplateMap (mProperty_lkey, mProperty_aTemplate COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_gtlTemplateMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "aTemplate" ":" ;
  mProperty_aTemplate.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_gtlTemplateMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlTemplateMap * operand = (cMapElement_gtlTemplateMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_aTemplate.objectCompare (operand->mProperty_aTemplate) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap::GALGAS_gtlTemplateMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap::GALGAS_gtlTemplateMap (const GALGAS_gtlTemplateMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap & GALGAS_gtlTemplateMap::operator = (const GALGAS_gtlTemplateMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlTemplateMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::constructor_mapWithMapToOverride (const GALGAS_gtlTemplateMap & inMapToOverride
                                                                               COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTemplateMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                 const GALGAS_gtlTemplate & inArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_gtlTemplateMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlTemplateMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlTemplateMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::add_operation (const GALGAS_gtlTemplateMap & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTemplateMap result = *this ;
  cEnumerator_gtlTemplateMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_aTemplate (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateMap::setter_put (GALGAS_lstring inKey,
                                        GALGAS_gtlTemplate inArgument0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  cMapElement_gtlTemplateMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlTemplateMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a template at path '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_gtlTemplateMap_get = "there is no template at path '%K'" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateMap::method_get (GALGAS_lstring inKey,
                                        GALGAS_gtlTemplate & outArgument0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) performSearch (inKey,
                                                                                             inCompiler,
                                                                                             kSearchErrorMessage_gtlTemplateMap_get
                                                                                             COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
    outArgument0 = p->mProperty_aTemplate ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplate GALGAS_gtlTemplateMap::getter_aTemplateForKey (const GALGAS_string & inKey,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) attributes ;
  GALGAS_gtlTemplate result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
    result = p->mProperty_aTemplate ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateMap::setter_setATemplateForKey (GALGAS_gtlTemplate inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_gtlTemplateMap * p = (cMapElement_gtlTemplateMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
    p->mProperty_aTemplate = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlTemplateMap * GALGAS_gtlTemplateMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) {
  cMapElement_gtlTemplateMap * result = (cMapElement_gtlTemplateMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlTemplateMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlTemplateMap::cEnumerator_gtlTemplateMap (const GALGAS_gtlTemplateMap & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap_2D_element cEnumerator_gtlTemplateMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
  return GALGAS_gtlTemplateMap_2D_element (p->mProperty_lkey, p->mProperty_aTemplate) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_gtlTemplateMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplate cEnumerator_gtlTemplateMap::current_aTemplate (LOCATION_ARGS) const {
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
  return p->mProperty_aTemplate ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlTemplateMap::optional_searchKey (const GALGAS_string & inKey,
                                                GALGAS_gtlTemplate & outArgument0) const {
  const cMapElement_gtlTemplateMap * p = (const cMapElement_gtlTemplateMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_gtlTemplateMap) ;
    outArgument0 = p->mProperty_aTemplate ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlTemplateMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTemplateMap ("gtlTemplateMap",
                                       nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlTemplateMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlTemplateMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTemplateMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap GALGAS_gtlTemplateMap::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateMap result ;
  const GALGAS_gtlTemplateMap * p = (const GALGAS_gtlTemplateMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlTemplateMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTemplateMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlTemplateMap getTemplate'
//
//----------------------------------------------------------------------------------------------------------------------

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
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_gtlTemplateMap temp_1 = ioObject ;
    test_0 = temp_1.getter_hasKey (inArgument_path.readProperty_string () COMMA_SOURCE_FILE ("gtl_types.galgas", 286)).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_found = GALGAS_bool (true) ;
      const GALGAS_gtlTemplateMap temp_2 = ioObject ;
      temp_2.method_get (inArgument_path, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 288)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = inArgument_path.readProperty_string ().getter_fileExists (SOURCE_FILE ("gtl_types.galgas", 290)).boolEnum () ;
      if (kBoolTrue == test_3) {
        outArgument_found = GALGAS_bool (true) ;
        GALGAS_gtlInstructionList var_program_7785 ;
        var_program_7785.drop () ;
        cGrammar_gtl_5F_grammar::_performSourceFileParsing_ (inCompiler, inArgument_path, constinArgument_context, ioArgument_lib, var_program_7785  COMMA_SOURCE_FILE ("gtl_types.galgas", 292)) ;
        outArgument_result = GALGAS_gtlTemplate::constructor_new (inArgument_path.readProperty_string (), var_program_7785  COMMA_SOURCE_FILE ("gtl_types.galgas", 296)) ;
        {
        ioObject.setter_put (inArgument_path, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 297)) ;
        }
      }
    }
    if (kBoolFalse == test_3) {
      outArgument_found = GALGAS_bool (false) ;
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = inArgument_ifExists.boolEnum () ;
        if (kBoolTrue == test_4) {
          outArgument_result = GALGAS_gtlTemplate::constructor_new (inArgument_path.readProperty_string (), GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_types.galgas", 301))  COMMA_SOURCE_FILE ("gtl_types.galgas", 301)) ;
        }
      }
      if (kBoolFalse == test_4) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (inArgument_path.readProperty_location (), GALGAS_string ("template file not found at \"").add_operation (inArgument_path.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 303)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 303)), fixItArray5  COMMA_SOURCE_FILE ("gtl_types.galgas", 303)) ;
        outArgument_result.drop () ; // Release error dropped variable
      }
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlFuncMap::cMapElement_gtlFuncMap (const GALGAS_lstring & inKey,
                                                const GALGAS_gtlFunction & in_function
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_function (in_function) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_gtlFuncMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_gtlFuncMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_gtlFuncMap (mProperty_lkey, mProperty_function COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_gtlFuncMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "function" ":" ;
  mProperty_function.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_gtlFuncMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlFuncMap * operand = (cMapElement_gtlFuncMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_function.objectCompare (operand->mProperty_function) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap::GALGAS_gtlFuncMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap::GALGAS_gtlFuncMap (const GALGAS_gtlFuncMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap & GALGAS_gtlFuncMap::operator = (const GALGAS_gtlFuncMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlFuncMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::constructor_mapWithMapToOverride (const GALGAS_gtlFuncMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_gtlFuncMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_gtlFuncMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlFuncMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_gtlFunction & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_gtlFuncMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlFuncMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlFuncMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::add_operation (const GALGAS_gtlFuncMap & inOperand,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_gtlFuncMap result = *this ;
  cEnumerator_gtlFuncMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_function (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlFuncMap::setter_put (GALGAS_lstring inKey,
                                    GALGAS_gtlFunction inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_gtlFuncMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlFuncMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a function named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_gtlFuncMap_get = "there is no function named '%K'" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlFuncMap::method_get (GALGAS_lstring inKey,
                                    GALGAS_gtlFunction & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_gtlFuncMap_get
                                                                                     COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
    outArgument0 = p->mProperty_function ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFunction GALGAS_gtlFuncMap::getter_functionForKey (const GALGAS_string & inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) attributes ;
  GALGAS_gtlFunction result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
    result = p->mProperty_function ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlFuncMap::setter_setFunctionForKey (GALGAS_gtlFunction inAttributeValue,
                                                  GALGAS_string inKey,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_gtlFuncMap * p = (cMapElement_gtlFuncMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
    p->mProperty_function = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlFuncMap * GALGAS_gtlFuncMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_gtlFuncMap * result = (cMapElement_gtlFuncMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlFuncMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlFuncMap::cEnumerator_gtlFuncMap (const GALGAS_gtlFuncMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap_2D_element cEnumerator_gtlFuncMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
  return GALGAS_gtlFuncMap_2D_element (p->mProperty_lkey, p->mProperty_function) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_gtlFuncMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFunction cEnumerator_gtlFuncMap::current_function (LOCATION_ARGS) const {
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
  return p->mProperty_function ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlFuncMap::optional_searchKey (const GALGAS_string & inKey,
                                            GALGAS_gtlFunction & outArgument0) const {
  const cMapElement_gtlFuncMap * p = (const cMapElement_gtlFuncMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_gtlFuncMap) ;
    outArgument0 = p->mProperty_function ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlFuncMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlFuncMap ("gtlFuncMap",
                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlFuncMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFuncMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlFuncMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlFuncMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap GALGAS_gtlFuncMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlFuncMap result ;
  const GALGAS_gtlFuncMap * p = (const GALGAS_gtlFuncMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlFuncMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlFuncMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlGetterMap::cMapElement_gtlGetterMap (const GALGAS_lstring & inKey,
                                                    const GALGAS_gtlGetter & in_theGetter
                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_theGetter (in_theGetter) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_gtlGetterMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_gtlGetterMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_gtlGetterMap (mProperty_lkey, mProperty_theGetter COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_gtlGetterMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "theGetter" ":" ;
  mProperty_theGetter.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_gtlGetterMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlGetterMap * operand = (cMapElement_gtlGetterMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_theGetter.objectCompare (operand->mProperty_theGetter) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap::GALGAS_gtlGetterMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap::GALGAS_gtlGetterMap (const GALGAS_gtlGetterMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap & GALGAS_gtlGetterMap::operator = (const GALGAS_gtlGetterMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlGetterMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::constructor_mapWithMapToOverride (const GALGAS_gtlGetterMap & inMapToOverride
                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetterMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::getter_overriddenMap (C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_gtlGetterMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlGetterMap::addAssign_operation (const GALGAS_lstring & inKey,
                                               const GALGAS_gtlGetter & inArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cMapElement_gtlGetterMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlGetterMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlGetterMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::add_operation (const GALGAS_gtlGetterMap & inOperand,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_gtlGetterMap result = *this ;
  cEnumerator_gtlGetterMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_theGetter (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlGetterMap::setter_put (GALGAS_lstring inKey,
                                      GALGAS_gtlGetter inArgument0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  cMapElement_gtlGetterMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlGetterMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a getter named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_gtlGetterMap_get = "there is no getter named '%K'" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlGetterMap::method_get (GALGAS_lstring inKey,
                                      GALGAS_gtlGetter & outArgument0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) performSearch (inKey,
                                                                                         inCompiler,
                                                                                         kSearchErrorMessage_gtlGetterMap_get
                                                                                         COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
    outArgument0 = p->mProperty_theGetter ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetter GALGAS_gtlGetterMap::getter_theGetterForKey (const GALGAS_string & inKey,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) attributes ;
  GALGAS_gtlGetter result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
    result = p->mProperty_theGetter ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlGetterMap::setter_setTheGetterForKey (GALGAS_gtlGetter inAttributeValue,
                                                     GALGAS_string inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_gtlGetterMap * p = (cMapElement_gtlGetterMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
    p->mProperty_theGetter = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlGetterMap * GALGAS_gtlGetterMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                   const GALGAS_string & inKey
                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_gtlGetterMap * result = (cMapElement_gtlGetterMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlGetterMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlGetterMap::cEnumerator_gtlGetterMap (const GALGAS_gtlGetterMap & inEnumeratedObject,
                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap_2D_element cEnumerator_gtlGetterMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
  return GALGAS_gtlGetterMap_2D_element (p->mProperty_lkey, p->mProperty_theGetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_gtlGetterMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetter cEnumerator_gtlGetterMap::current_theGetter (LOCATION_ARGS) const {
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
  return p->mProperty_theGetter ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlGetterMap::optional_searchKey (const GALGAS_string & inKey,
                                              GALGAS_gtlGetter & outArgument0) const {
  const cMapElement_gtlGetterMap * p = (const cMapElement_gtlGetterMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_gtlGetterMap) ;
    outArgument0 = p->mProperty_theGetter ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlGetterMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGetterMap ("gtlGetterMap",
                                     nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlGetterMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetterMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlGetterMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGetterMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap GALGAS_gtlGetterMap::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetterMap result ;
  const GALGAS_gtlGetterMap * p = (const GALGAS_gtlGetterMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlGetterMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGetterMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlSetterMap::cMapElement_gtlSetterMap (const GALGAS_lstring & inKey,
                                                    const GALGAS_gtlSetter & in_theSetter
                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_theSetter (in_theSetter) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_gtlSetterMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_gtlSetterMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_gtlSetterMap (mProperty_lkey, mProperty_theSetter COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_gtlSetterMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "theSetter" ":" ;
  mProperty_theSetter.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_gtlSetterMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlSetterMap * operand = (cMapElement_gtlSetterMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_theSetter.objectCompare (operand->mProperty_theSetter) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap::GALGAS_gtlSetterMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap::GALGAS_gtlSetterMap (const GALGAS_gtlSetterMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap & GALGAS_gtlSetterMap::operator = (const GALGAS_gtlSetterMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlSetterMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::constructor_mapWithMapToOverride (const GALGAS_gtlSetterMap & inMapToOverride
                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetterMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::getter_overriddenMap (C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_gtlSetterMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlSetterMap::addAssign_operation (const GALGAS_lstring & inKey,
                                               const GALGAS_gtlSetter & inArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cMapElement_gtlSetterMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlSetterMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlSetterMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::add_operation (const GALGAS_gtlSetterMap & inOperand,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_gtlSetterMap result = *this ;
  cEnumerator_gtlSetterMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_theSetter (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlSetterMap::setter_put (GALGAS_lstring inKey,
                                      GALGAS_gtlSetter inArgument0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  cMapElement_gtlSetterMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlSetterMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a setter named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_gtlSetterMap_get = "there is no setter named '%K'" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlSetterMap::method_get (GALGAS_lstring inKey,
                                      GALGAS_gtlSetter & outArgument0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) performSearch (inKey,
                                                                                         inCompiler,
                                                                                         kSearchErrorMessage_gtlSetterMap_get
                                                                                         COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
    outArgument0 = p->mProperty_theSetter ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetter GALGAS_gtlSetterMap::getter_theSetterForKey (const GALGAS_string & inKey,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) attributes ;
  GALGAS_gtlSetter result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
    result = p->mProperty_theSetter ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlSetterMap::setter_setTheSetterForKey (GALGAS_gtlSetter inAttributeValue,
                                                     GALGAS_string inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_gtlSetterMap * p = (cMapElement_gtlSetterMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
    p->mProperty_theSetter = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlSetterMap * GALGAS_gtlSetterMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                   const GALGAS_string & inKey
                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_gtlSetterMap * result = (cMapElement_gtlSetterMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlSetterMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlSetterMap::cEnumerator_gtlSetterMap (const GALGAS_gtlSetterMap & inEnumeratedObject,
                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap_2D_element cEnumerator_gtlSetterMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
  return GALGAS_gtlSetterMap_2D_element (p->mProperty_lkey, p->mProperty_theSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_gtlSetterMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetter cEnumerator_gtlSetterMap::current_theSetter (LOCATION_ARGS) const {
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
  return p->mProperty_theSetter ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlSetterMap::optional_searchKey (const GALGAS_string & inKey,
                                              GALGAS_gtlSetter & outArgument0) const {
  const cMapElement_gtlSetterMap * p = (const cMapElement_gtlSetterMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_gtlSetterMap) ;
    outArgument0 = p->mProperty_theSetter ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlSetterMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSetterMap ("gtlSetterMap",
                                     nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlSetterMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSetterMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlSetterMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSetterMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap GALGAS_gtlSetterMap::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetterMap result ;
  const GALGAS_gtlSetterMap * p = (const GALGAS_gtlSetterMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlSetterMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSetterMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItem::GALGAS_gtlVarItem (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItem::GALGAS_gtlVarItem (const cPtr_gtlVarItem * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlVarItem) ;
}
//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlVarItem class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlVarItem::cPtr_gtlVarItem (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlVarItem generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarItem ("gtlVarItem",
                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlVarItem::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItem ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlVarItem::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarItem (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItem GALGAS_gtlVarItem::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItem result ;
  const GALGAS_gtlVarItem * p = (const GALGAS_gtlVarItem *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlVarItem *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarItem", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlVarItem stringPath'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string callExtensionGetter_stringPath (const cPtr_gtlVarItem * inObject,
                                              const GALGAS_gtlContext in_exeContext,
                                              const GALGAS_gtlData in_vars,
                                              const GALGAS_library in_lib,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (nullptr != inObject) {
    result = inObject->getter_stringPath (in_exeContext, in_vars, in_lib, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlVarItem location'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location callExtensionGetter_location (const cPtr_gtlVarItem * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_location result ;
  if (nullptr != inObject) {
    result = inObject->getter_location (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@gtlVarItem setInContext'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_setInContext (cPtr_gtlVarItem * inObject,
                                       const GALGAS_gtlContext constin_exeContext,
                                       GALGAS_gtlData & io_context,
                                       const GALGAS_gtlData constin_vars,
                                       const GALGAS_library constin_lib,
                                       const GALGAS_gtlVarPath constin_path,
                                       const GALGAS_gtlData constin_newData,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVarItem) ;
    inObject->method_setInContext (constin_exeContext, io_context, constin_vars, constin_lib, constin_path, constin_newData, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlVarItem getInContext'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_getInContext (const cPtr_gtlVarItem * inObject,
                                                 const GALGAS_gtlContext in_exeContext,
                                                 const GALGAS_gtlData in_context,
                                                 const GALGAS_gtlData in_vars,
                                                 const GALGAS_library in_lib,
                                                 const GALGAS_gtlVarPath in_path,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_getInContext (in_exeContext, in_context, in_vars, in_lib, in_path, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlVarItem existsInContext'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_existsInContext (const cPtr_gtlVarItem * inObject,
                                                 const GALGAS_gtlContext in_exeContext,
                                                 const GALGAS_gtlData in_context,
                                                 const GALGAS_gtlData in_vars,
                                                 const GALGAS_library in_lib,
                                                 const GALGAS_gtlVarPath in_path,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_existsInContext (in_exeContext, in_context, in_vars, in_lib, in_path, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@gtlVarItem deleteInContext'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_deleteInContext (cPtr_gtlVarItem * inObject,
                                          const GALGAS_gtlContext constin_exeContext,
                                          GALGAS_gtlData & io_context,
                                          const GALGAS_gtlData constin_vars,
                                          const GALGAS_library constin_lib,
                                          const GALGAS_gtlVarPath constin_path,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVarItem) ;
    inObject->method_deleteInContext (constin_exeContext, io_context, constin_vars, constin_lib, constin_path, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@gtlVarPath' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_gtlVarPath : public cCollectionElement {
  public: GALGAS_gtlVarPath_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_gtlVarPath (const GALGAS_gtlVarItem & in_item
                                         COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_gtlVarPath (const GALGAS_gtlVarPath_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_gtlVarPath::cCollectionElement_gtlVarPath (const GALGAS_gtlVarItem & in_item
                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_item) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_gtlVarPath::cCollectionElement_gtlVarPath (const GALGAS_gtlVarPath_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_item) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_gtlVarPath::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_gtlVarPath::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_gtlVarPath (mObject.mProperty_item COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_gtlVarPath::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "item" ":" ;
  mObject.mProperty_item.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_gtlVarPath::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlVarPath * operand = (cCollectionElement_gtlVarPath *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlVarPath) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath::GALGAS_gtlVarPath (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath::GALGAS_gtlVarPath (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlVarPath::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlVarPath  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlVarPath::constructor_listWithValue (const GALGAS_gtlVarItem & inOperand0
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarPath result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlVarPath (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_gtlVarPath::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarPath::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                   const GALGAS_gtlVarItem & in_item
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlVarPath * p = nullptr ;
  macroMyNew (p, cCollectionElement_gtlVarPath (in_item COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarPath::addAssign_operation (const GALGAS_gtlVarItem & inOperand0
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlVarPath (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarPath::setter_append (const GALGAS_gtlVarItem inOperand0,
                                       C_Compiler * /* inCompiler */
                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlVarPath (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarPath::setter_insertAtIndex (const GALGAS_gtlVarItem inOperand0,
                                              const GALGAS_uint inInsertionIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_gtlVarPath (inOperand0 COMMA_THERE)) ;
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

void GALGAS_gtlVarPath::setter_removeAtIndex (GALGAS_gtlVarItem & outOperand0,
                                              const GALGAS_uint inRemoveIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
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

void GALGAS_gtlVarPath::setter_popFirst (GALGAS_gtlVarItem & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    outOperand0 = p->mObject.mProperty_item ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarPath::setter_popLast (GALGAS_gtlVarItem & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    outOperand0 = p->mObject.mProperty_item ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarPath::method_first (GALGAS_gtlVarItem & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    outOperand0 = p->mObject.mProperty_item ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarPath::method_last (GALGAS_gtlVarItem & outOperand0,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    outOperand0 = p->mObject.mProperty_item ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlVarPath::getter_subListWithRange (const GALGAS_range & inRange,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result = GALGAS_gtlVarPath::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlVarPath::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result = GALGAS_gtlVarPath::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlVarPath::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlVarPath result = GALGAS_gtlVarPath::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarPath::plusAssign_operation (const GALGAS_gtlVarPath inOperand,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarPath::setter_setItemAtIndex (GALGAS_gtlVarItem inOperand,
                                               GALGAS_uint inIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_item = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItem GALGAS_gtlVarPath::getter_itemAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlVarPath * p = (cCollectionElement_gtlVarPath *) attributes.ptr () ;
  GALGAS_gtlVarItem result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
    result = p->mObject.mProperty_item ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlVarPath::cEnumerator_gtlVarPath (const GALGAS_gtlVarPath & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath_2D_element cEnumerator_gtlVarPath::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlVarPath * p = (const cCollectionElement_gtlVarPath *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItem cEnumerator_gtlVarPath::current_item (LOCATION_ARGS) const {
  const cCollectionElement_gtlVarPath * p = (const cCollectionElement_gtlVarPath *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlVarPath) ;
  return p->mObject.mProperty_item ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlVarPath generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarPath ("gtlVarPath",
                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlVarPath::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarPath ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlVarPath::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarPath (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlVarPath::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarPath result ;
  const GALGAS_gtlVarPath * p = (const GALGAS_gtlVarPath *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlVarPath *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarPath", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@gtlVarPath pathAsFunctionName'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring extensionGetter_pathAsFunctionName (const GALGAS_gtlVarPath & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const GALGAS_gtlVarPath temp_0 = inObject ;
  GALGAS_gtlVarItem var_firstItem_22067 = temp_0.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 758)) ;
  if (var_firstItem_22067.isValid ()) {
    if (nullptr != dynamic_cast <const cPtr_gtlVarItemField *> (var_firstItem_22067.ptr ())) {
      GALGAS_gtlVarItemField cast_22145_namedField ((cPtr_gtlVarItemField *) var_firstItem_22067.ptr ()) ;
      result_result = cast_22145_namedField.readProperty_field () ;
    }else{
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlVarItem *) var_firstItem_22067.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 763)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath should not begin with a subcollection"), fixItArray1  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 763)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@gtlVarPath stringPath'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_stringPath (const GALGAS_gtlVarPath & inObject,
                                          const GALGAS_gtlContext & constinArgument_exeContext,
                                          const GALGAS_gtlData & constinArgument_vars,
                                          const GALGAS_library & constinArgument_lib,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  const GALGAS_gtlVarPath temp_0 = inObject ;
  cEnumerator_gtlVarPath enumerator_22637 (temp_0, kENUMERATION_UP) ;
  while (enumerator_22637.hasCurrentObject ()) {
    result_result.plusAssign_operation(callExtensionGetter_stringPath ((const cPtr_gtlVarItem *) enumerator_22637.current_item (HERE).ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 778)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 778)) ;
    if (enumerator_22637.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string ("::"), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 780)) ;
    }
    enumerator_22637.gotoNextObject () ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlVarPath set'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_set (const GALGAS_gtlVarPath inObject,
                          const GALGAS_gtlContext constinArgument_exeContext,
                          GALGAS_gtlData & ioArgument_vars,
                          const GALGAS_library constinArgument_lib,
                          const GALGAS_gtlData constinArgument_data,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_gtlVarPath temp_1 = inObject ;
    test_0 = GALGAS_bool (kIsStrictSup, temp_1.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 793)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_gtlVarPath temp_2 = inObject ;
      GALGAS_gtlVarItem var_item_23096 = temp_2.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 794)) ;
      if (var_item_23096.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlVarItemField *> (var_item_23096.ptr ())) {
          GALGAS_gtlVarItemField cast_23168_itemField ((cPtr_gtlVarItemField *) var_item_23096.ptr ()) ;
          const GALGAS_gtlVarPath temp_3 = inObject ;
          callExtensionMethod_setInContext ((cPtr_gtlVarItemField *) cast_23168_itemField.ptr (), constinArgument_exeContext, ioArgument_vars, ioArgument_vars, constinArgument_lib, temp_3.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 802)), constinArgument_data, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 797)) ;
        }else{
          TC_Array <C_FixItDescription> fixItArray4 ;
          inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlVarItem *) var_item_23096.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 806)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath may not begin with a subcollection"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 806)) ;
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray5 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 809)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath should not be an empty list"), fixItArray5  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 809)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@gtlVarPath get'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData extensionGetter_get (const GALGAS_gtlVarPath & inObject,
                                    const GALGAS_gtlContext & constinArgument_exeContext,
                                    const GALGAS_gtlData & constinArgument_context,
                                    const GALGAS_library & constinArgument_lib,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_variableValue ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_gtlVarPath temp_1 = inObject ;
    test_0 = GALGAS_bool (kIsStrictSup, temp_1.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 822)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_gtlVarPath temp_2 = inObject ;
      GALGAS_gtlVarItem var_item_23895 = temp_2.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 823)) ;
      const GALGAS_gtlVarPath temp_3 = inObject ;
      result_variableValue = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) var_item_23895.ptr (), constinArgument_exeContext, constinArgument_context, constinArgument_context, constinArgument_lib, temp_3.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 824)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 824)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 826)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath should not be an empty list"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 826)) ;
    result_variableValue.drop () ; // Release error dropped variable
  }
//---
  return result_variableValue ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@gtlVarPath exists'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool extensionGetter_exists (const GALGAS_gtlVarPath & inObject,
                                    const GALGAS_gtlContext & constinArgument_exeContext,
                                    const GALGAS_gtlData & constinArgument_context,
                                    const GALGAS_library & constinArgument_lib,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_gtlVarPath temp_1 = inObject ;
    test_0 = GALGAS_bool (kIsStrictSup, temp_1.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 840)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_gtlVarPath temp_2 = inObject ;
      GALGAS_gtlVarItem var_item_24506 = temp_2.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 841)) ;
      const GALGAS_gtlVarPath temp_3 = inObject ;
      result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) var_item_24506.ptr (), constinArgument_exeContext, constinArgument_context, constinArgument_context, constinArgument_lib, temp_3.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 842)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 842)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 844)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath should not be an empty list"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 844)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlVarPath delete'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_delete (const GALGAS_gtlVarPath inObject,
                             const GALGAS_gtlContext constinArgument_exeContext,
                             GALGAS_gtlData & ioArgument_vars,
                             const GALGAS_library constinArgument_lib,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_gtlVarPath temp_1 = inObject ;
    test_0 = GALGAS_bool (kIsStrictSup, temp_1.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 857)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_gtlVarPath temp_2 = inObject ;
      GALGAS_gtlVarItem var_item_25078 = temp_2.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 858)) ;
      const GALGAS_gtlVarPath temp_3 = inObject ;
      callExtensionMethod_deleteInContext ((cPtr_gtlVarItem *) var_item_25078.ptr (), constinArgument_exeContext, ioArgument_vars, ioArgument_vars, constinArgument_lib, temp_3.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 864)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 859)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 867)), GALGAS_string ("INTERNAL ERROR. A @gtlVarPath should not be an empty list"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 867)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@gtlVarPath location'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location extensionGetter_location (const GALGAS_gtlVarPath & inObject,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_location result_where ; // Returned variable
  GALGAS_gtlVarItem var_lastOne_25617 ;
  const GALGAS_gtlVarPath temp_0 = inObject ;
  temp_0.method_last (var_lastOne_25617, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 876)) ;
  result_where = callExtensionGetter_location ((const cPtr_gtlVarItem *) var_lastOne_25617.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 877)) ;
//---
  return result_where ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@gtlExpressionList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_gtlExpressionList : public cCollectionElement {
  public: GALGAS_gtlExpressionList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_gtlExpressionList (const GALGAS_gtlExpression & in_expression
                                                COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_gtlExpressionList (const GALGAS_gtlExpressionList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_gtlExpressionList::cCollectionElement_gtlExpressionList (const GALGAS_gtlExpression & in_expression
                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_expression) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_gtlExpressionList::cCollectionElement_gtlExpressionList (const GALGAS_gtlExpressionList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_expression) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_gtlExpressionList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_gtlExpressionList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_gtlExpressionList (mObject.mProperty_expression COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_gtlExpressionList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "expression" ":" ;
  mObject.mProperty_expression.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_gtlExpressionList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlExpressionList * operand = (cCollectionElement_gtlExpressionList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlExpressionList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList::GALGAS_gtlExpressionList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList::GALGAS_gtlExpressionList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlExpressionList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::constructor_listWithValue (const GALGAS_gtlExpression & inOperand0
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlExpressionList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_gtlExpressionList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                          const GALGAS_gtlExpression & in_expression
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlExpressionList * p = nullptr ;
  macroMyNew (p, cCollectionElement_gtlExpressionList (in_expression COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionList::addAssign_operation (const GALGAS_gtlExpression & inOperand0
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlExpressionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionList::setter_append (const GALGAS_gtlExpression inOperand0,
                                              C_Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlExpressionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionList::setter_insertAtIndex (const GALGAS_gtlExpression inOperand0,
                                                     const GALGAS_uint inInsertionIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_gtlExpressionList (inOperand0 COMMA_THERE)) ;
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

void GALGAS_gtlExpressionList::setter_removeAtIndex (GALGAS_gtlExpression & outOperand0,
                                                     const GALGAS_uint inRemoveIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
        outOperand0 = p->mObject.mProperty_expression ;
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

void GALGAS_gtlExpressionList::setter_popFirst (GALGAS_gtlExpression & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    outOperand0 = p->mObject.mProperty_expression ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionList::setter_popLast (GALGAS_gtlExpression & outOperand0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    outOperand0 = p->mObject.mProperty_expression ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionList::method_first (GALGAS_gtlExpression & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    outOperand0 = p->mObject.mProperty_expression ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionList::method_last (GALGAS_gtlExpression & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    outOperand0 = p->mObject.mProperty_expression ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result = GALGAS_gtlExpressionList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result = GALGAS_gtlExpressionList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_gtlExpressionList result = GALGAS_gtlExpressionList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionList::plusAssign_operation (const GALGAS_gtlExpressionList inOperand,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionList::setter_setExpressionAtIndex (GALGAS_gtlExpression inOperand,
                                                            GALGAS_uint inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_expression = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlExpressionList::getter_expressionAtIndex (const GALGAS_uint & inIndex,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlExpressionList * p = (cCollectionElement_gtlExpressionList *) attributes.ptr () ;
  GALGAS_gtlExpression result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
    result = p->mObject.mProperty_expression ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlExpressionList::cEnumerator_gtlExpressionList (const GALGAS_gtlExpressionList & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList_2D_element cEnumerator_gtlExpressionList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlExpressionList * p = (const cCollectionElement_gtlExpressionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cEnumerator_gtlExpressionList::current_expression (LOCATION_ARGS) const {
  const cCollectionElement_gtlExpressionList * p = (const cCollectionElement_gtlExpressionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlExpressionList) ;
  return p->mObject.mProperty_expression ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlExpressionList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpressionList ("gtlExpressionList",
                                          nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlExpressionList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpressionList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlExpressionList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpressionList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlExpressionList::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionList result ;
  const GALGAS_gtlExpressionList * p = (const GALGAS_gtlExpressionList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlExpressionList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExpressionList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@string gtlType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type extensionGetter_gtlType (const GALGAS_string & inObject,
                                     const GALGAS_location & constinArgument_location,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_type ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_string temp_1 = inObject ;
    test_0 = GALGAS_bool (kIsEqual, temp_1.objectCompare (GALGAS_string ("int"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      const GALGAS_string temp_3 = inObject ;
      test_2 = GALGAS_bool (kIsEqual, temp_3.objectCompare (GALGAS_string ("char"))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        const GALGAS_string temp_5 = inObject ;
        test_4 = GALGAS_bool (kIsEqual, temp_5.objectCompare (GALGAS_string ("float"))).boolEnum () ;
        if (kBoolTrue == test_4) {
          result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_6 = kBoolTrue ;
        if (kBoolTrue == test_6) {
          const GALGAS_string temp_7 = inObject ;
          test_6 = GALGAS_bool (kIsEqual, temp_7.objectCompare (GALGAS_string ("string"))).boolEnum () ;
          if (kBoolTrue == test_6) {
            result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlString) ;
          }
        }
        if (kBoolFalse == test_6) {
          enumGalgasBool test_8 = kBoolTrue ;
          if (kBoolTrue == test_8) {
            const GALGAS_string temp_9 = inObject ;
            test_8 = GALGAS_bool (kIsEqual, temp_9.objectCompare (GALGAS_string ("bool"))).boolEnum () ;
            if (kBoolTrue == test_8) {
              result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool) ;
            }
          }
          if (kBoolFalse == test_8) {
            enumGalgasBool test_10 = kBoolTrue ;
            if (kBoolTrue == test_10) {
              const GALGAS_string temp_11 = inObject ;
              test_10 = GALGAS_bool (kIsEqual, temp_11.objectCompare (GALGAS_string ("struct"))).boolEnum () ;
              if (kBoolTrue == test_10) {
                result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct) ;
              }
            }
            if (kBoolFalse == test_10) {
              enumGalgasBool test_12 = kBoolTrue ;
              if (kBoolTrue == test_12) {
                const GALGAS_string temp_13 = inObject ;
                test_12 = GALGAS_bool (kIsEqual, temp_13.objectCompare (GALGAS_string ("list"))).boolEnum () ;
                if (kBoolTrue == test_12) {
                  result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlList) ;
                }
              }
              if (kBoolFalse == test_12) {
                enumGalgasBool test_14 = kBoolTrue ;
                if (kBoolTrue == test_14) {
                  const GALGAS_string temp_15 = inObject ;
                  test_14 = GALGAS_bool (kIsEqual, temp_15.objectCompare (GALGAS_string ("map"))).boolEnum () ;
                  if (kBoolTrue == test_14) {
                    result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlMap) ;
                  }
                }
                if (kBoolFalse == test_14) {
                  enumGalgasBool test_16 = kBoolTrue ;
                  if (kBoolTrue == test_16) {
                    const GALGAS_string temp_17 = inObject ;
                    test_16 = GALGAS_bool (kIsEqual, temp_17.objectCompare (GALGAS_string ("type"))).boolEnum () ;
                    if (kBoolTrue == test_16) {
                      result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlType) ;
                    }
                  }
                  if (kBoolFalse == test_16) {
                    enumGalgasBool test_18 = kBoolTrue ;
                    if (kBoolTrue == test_18) {
                      const GALGAS_string temp_19 = inObject ;
                      test_18 = GALGAS_bool (kIsEqual, temp_19.objectCompare (GALGAS_string ("enum"))).boolEnum () ;
                      if (kBoolTrue == test_18) {
                        result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlEnum) ;
                      }
                    }
                    if (kBoolFalse == test_18) {
                      enumGalgasBool test_20 = kBoolTrue ;
                      if (kBoolTrue == test_20) {
                        const GALGAS_string temp_21 = inObject ;
                        test_20 = GALGAS_bool (kIsEqual, temp_21.objectCompare (GALGAS_string ("set"))).boolEnum () ;
                        if (kBoolTrue == test_20) {
                          result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet) ;
                        }
                      }
                      if (kBoolFalse == test_20) {
                        enumGalgasBool test_22 = kBoolTrue ;
                        if (kBoolTrue == test_22) {
                          const GALGAS_string temp_23 = inObject ;
                          test_22 = GALGAS_bool (kIsEqual, temp_23.objectCompare (GALGAS_string ("unconstructed"))).boolEnum () ;
                          if (kBoolTrue == test_22) {
                            result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlUnconstructed) ;
                          }
                        }
                        if (kBoolFalse == test_22) {
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




//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@gtlTypedArgumentList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_gtlTypedArgumentList : public cCollectionElement {
  public: GALGAS_gtlTypedArgumentList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_gtlTypedArgumentList (const GALGAS_type & in_type
                                                   COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_gtlTypedArgumentList (const GALGAS_gtlTypedArgumentList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_gtlTypedArgumentList::cCollectionElement_gtlTypedArgumentList (const GALGAS_type & in_type
                                                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_type) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_gtlTypedArgumentList::cCollectionElement_gtlTypedArgumentList (const GALGAS_gtlTypedArgumentList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_type) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_gtlTypedArgumentList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_gtlTypedArgumentList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_gtlTypedArgumentList (mObject.mProperty_type COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_gtlTypedArgumentList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "type" ":" ;
  mObject.mProperty_type.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_gtlTypedArgumentList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlTypedArgumentList * operand = (cCollectionElement_gtlTypedArgumentList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlTypedArgumentList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList::GALGAS_gtlTypedArgumentList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList::GALGAS_gtlTypedArgumentList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlTypedArgumentList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::constructor_listWithValue (const GALGAS_type & inOperand0
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlTypedArgumentList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_gtlTypedArgumentList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTypedArgumentList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                             const GALGAS_type & in_type
                                                             COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlTypedArgumentList * p = nullptr ;
  macroMyNew (p, cCollectionElement_gtlTypedArgumentList (in_type COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTypedArgumentList::addAssign_operation (const GALGAS_type & inOperand0
                                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlTypedArgumentList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTypedArgumentList::setter_append (const GALGAS_type inOperand0,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlTypedArgumentList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTypedArgumentList::setter_insertAtIndex (const GALGAS_type inOperand0,
                                                        const GALGAS_uint inInsertionIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_gtlTypedArgumentList (inOperand0 COMMA_THERE)) ;
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

void GALGAS_gtlTypedArgumentList::setter_removeAtIndex (GALGAS_type & outOperand0,
                                                        const GALGAS_uint inRemoveIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
        outOperand0 = p->mObject.mProperty_type ;
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

void GALGAS_gtlTypedArgumentList::setter_popFirst (GALGAS_type & outOperand0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    outOperand0 = p->mObject.mProperty_type ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTypedArgumentList::setter_popLast (GALGAS_type & outOperand0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    outOperand0 = p->mObject.mProperty_type ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTypedArgumentList::method_first (GALGAS_type & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    outOperand0 = p->mObject.mProperty_type ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTypedArgumentList::method_last (GALGAS_type & outOperand0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    outOperand0 = p->mObject.mProperty_type ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTypedArgumentList result = GALGAS_gtlTypedArgumentList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTypedArgumentList result = GALGAS_gtlTypedArgumentList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_gtlTypedArgumentList result = GALGAS_gtlTypedArgumentList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTypedArgumentList::plusAssign_operation (const GALGAS_gtlTypedArgumentList inOperand,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTypedArgumentList::setter_setTypeAtIndex (GALGAS_type inOperand,
                                                         GALGAS_uint inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_type = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_type GALGAS_gtlTypedArgumentList::getter_typeAtIndex (const GALGAS_uint & inIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlTypedArgumentList * p = (cCollectionElement_gtlTypedArgumentList *) attributes.ptr () ;
  GALGAS_type result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
    result = p->mObject.mProperty_type ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlTypedArgumentList::cEnumerator_gtlTypedArgumentList (const GALGAS_gtlTypedArgumentList & inEnumeratedObject,
                                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList_2D_element cEnumerator_gtlTypedArgumentList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlTypedArgumentList * p = (const cCollectionElement_gtlTypedArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cEnumerator_gtlTypedArgumentList::current_type (LOCATION_ARGS) const {
  const cCollectionElement_gtlTypedArgumentList * p = (const cCollectionElement_gtlTypedArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlTypedArgumentList) ;
  return p->mObject.mProperty_type ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlTypedArgumentList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTypedArgumentList ("gtlTypedArgumentList",
                                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlTypedArgumentList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTypedArgumentList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlTypedArgumentList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTypedArgumentList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList GALGAS_gtlTypedArgumentList::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result ;
  const GALGAS_gtlTypedArgumentList * p = (const GALGAS_gtlTypedArgumentList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlTypedArgumentList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTypedArgumentList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@list' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_list : public cCollectionElement {
  public: GALGAS_list_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_list (const GALGAS_gtlData & in_value
                                   COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_list (const GALGAS_list_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_list::cCollectionElement_list (const GALGAS_gtlData & in_value
                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_list::cCollectionElement_list (const GALGAS_list_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_list::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_list::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_list (mObject.mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_list::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_list::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_list * operand = (cCollectionElement_list *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_list) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list::GALGAS_list (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list::GALGAS_list (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list GALGAS_list::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_list  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list GALGAS_list::constructor_listWithValue (const GALGAS_gtlData & inOperand0
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_list result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_list (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_list::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_list::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                             const GALGAS_gtlData & in_value
                                             COMMA_LOCATION_ARGS) {
  cCollectionElement_list * p = nullptr ;
  macroMyNew (p, cCollectionElement_list (in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_list::addAssign_operation (const GALGAS_gtlData & inOperand0
                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_list::setter_append (const GALGAS_gtlData inOperand0,
                                 C_Compiler * /* inCompiler */
                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_list::setter_insertAtIndex (const GALGAS_gtlData inOperand0,
                                        const GALGAS_uint inInsertionIndex,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_list (inOperand0 COMMA_THERE)) ;
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

void GALGAS_list::setter_removeAtIndex (GALGAS_gtlData & outOperand0,
                                        const GALGAS_uint inRemoveIndex,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_list) ;
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

void GALGAS_list::setter_popFirst (GALGAS_gtlData & outOperand0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_list) ;
    outOperand0 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_list::setter_popLast (GALGAS_gtlData & outOperand0,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_list) ;
    outOperand0 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_list::method_first (GALGAS_gtlData & outOperand0,
                                C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_list) ;
    outOperand0 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_list::method_last (GALGAS_gtlData & outOperand0,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_list) ;
    outOperand0 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list GALGAS_list::getter_subListWithRange (const GALGAS_range & inRange,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_list result = GALGAS_list::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list GALGAS_list::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_list result = GALGAS_list::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list GALGAS_list::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GALGAS_list result = GALGAS_list::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_list::plusAssign_operation (const GALGAS_list inOperand,
                                        C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_list::setter_setValueAtIndex (GALGAS_gtlData inOperand,
                                              GALGAS_uint inIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cCollectionElement_list * p = (cCollectionElement_list *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_list) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_value = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData GALGAS_list::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_list * p = (cCollectionElement_list *) attributes.ptr () ;
  GALGAS_gtlData result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_list) ;
    result = p->mObject.mProperty_value ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_list::cEnumerator_list (const GALGAS_list & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list_2D_element cEnumerator_list::current (LOCATION_ARGS) const {
  const cCollectionElement_list * p = (const cCollectionElement_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_list) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cEnumerator_list::current_value (LOCATION_ARGS) const {
  const cCollectionElement_list * p = (const cCollectionElement_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_list) ;
  return p->mObject.mProperty_value ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @list generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_list ("list",
                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_list::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_list ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_list::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_list (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list GALGAS_list::extractObject (const GALGAS_object & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_list result ;
  const GALGAS_list * p = (const GALGAS_list *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_list *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("list", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_lstringset::cMapElement_lstringset (const GALGAS_lstring & inKey
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_lstringset::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_lstringset::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_lstringset (mProperty_lkey COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_lstringset::description (C_String & /* ioString */, const int32_t /* inIndentation */) const {
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_lstringset::compare (const cCollectionElement * inOperand) const {
  cMapElement_lstringset * operand = (cMapElement_lstringset *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset::GALGAS_lstringset (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset::GALGAS_lstringset (const GALGAS_lstringset & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset & GALGAS_lstringset::operator = (const GALGAS_lstringset & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset GALGAS_lstringset::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_lstringset result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset GALGAS_lstringset::constructor_mapWithMapToOverride (const GALGAS_lstringset & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_lstringset result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset GALGAS_lstringset::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_lstringset result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringset::addAssign_operation (const GALGAS_lstring & inKey,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_lstringset * p = nullptr ;
  macroMyNew (p, cMapElement_lstringset (inKey COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@lstringset insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset GALGAS_lstringset::add_operation (const GALGAS_lstringset & inOperand,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_lstringset result = *this ;
  cEnumerator_lstringset enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringset::setter_put (GALGAS_lstring inKey,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_lstringset * p = nullptr ;
  macroMyNew (p, cMapElement_lstringset (inKey COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "set element named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_lstringset_get = "there is no set element named '%K' to get" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringset::method_get (GALGAS_lstring inKey,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_lstringset * p = (const cMapElement_lstringset *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_lstringset_get
                                                                                     COMMA_THERE) ;
  if (nullptr == p) {
  }else{
    macroValidSharedObject (p, cMapElement_lstringset) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringset::setter_del (GALGAS_lstring inKey,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "there is no set element named '%K' to delete" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_lstringset * p = (cMapElement_lstringset *) attributes.ptr () ;
  if (nullptr == p) {
  }else{
    macroValidSharedObject (p, cMapElement_lstringset) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_lstringset * GALGAS_lstringset::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_lstringset * result = (cMapElement_lstringset *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_lstringset) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_lstringset::cEnumerator_lstringset (const GALGAS_lstringset & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset_2D_element cEnumerator_lstringset::current (LOCATION_ARGS) const {
  const cMapElement_lstringset * p = (const cMapElement_lstringset *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_lstringset) ;
  return GALGAS_lstringset_2D_element (p->mProperty_lkey) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_lstringset::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lstringset::optional_searchKey (const GALGAS_string & inKey) const {
  const cMapElement_lstringset * p = (const cMapElement_lstringset *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_lstringset) ;
  }else{
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @lstringset generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstringset ("lstringset",
                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lstringset::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstringset ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lstringset::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lstringset (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset GALGAS_lstringset::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_lstringset result ;
  const GALGAS_lstringset * p = (const GALGAS_lstringset *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lstringset *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lstringset", p->dynamicTypeDescriptor () COMMA_THERE) ;
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

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_gtl_5F_scanner::C_Lexique_gtl_5F_scanner (C_Compiler * inCallerCompiler,
                                                    const C_String & inSourceFileName
                                                    COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceFileName COMMA_THERE),
mMatchedTemplateDelimiterIndex (-1) {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_gtl_5F_scanner::C_Lexique_gtl_5F_scanner (C_Compiler * inCallerCompiler,
                                                    const C_String & inSourceString,
                                                    const C_String & inStringForError
                                                    COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE),
mMatchedTemplateDelimiterIndex (-1) {
}

//----------------------------------------------------------------------------------------------------------------------
//                        Lexical error message list                                             
//----------------------------------------------------------------------------------------------------------------------

static const char * gLexicalMessage_gtl_5F_scanner_floatNumberConversionError = "invalid float number" ;

static const char * gLexicalMessage_gtl_5F_scanner_incorrectCharConstant = "incorrect literal character" ;

static const char * gLexicalMessage_gtl_5F_scanner_incorrectHTMLescapeSequence = "Invalid HTML sequence, should be '&...;'" ;

static const char * gLexicalMessage_gtl_5F_scanner_internalError = "internal error" ;

static const char * gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition4 = "\\u should be followed by exactly four hexadecimal digits" ;

static const char * gLexicalMessage_gtl_5F_scanner_invalideUnicodeDefinition8 = "\\U should be followed by exactly eight hexadecimal digits" ;

static const char * gLexicalMessage_gtl_5F_scanner_unassignedUnicodeValue = "this value does not correspond to an assigned Unicode point" ;

static const char * gLexicalMessage_gtl_5F_scanner_unknownHTMLescapeSequence = "Invalid &...; HTML sequence" ;

static const char * gLexicalMessage_gtl_5F_scanner_unterminatedLitteralString = "Unterminated literal string" ;

//----------------------------------------------------------------------------------------------------------------------
//                getMessageForTerminal                                                          
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_gtl_5F_scanner::getMessageForTerminal (const int32_t inTerminalIndex) const {
  C_String result = "<unknown>" ;
  if ((inTerminalIndex >= 0) && (inTerminalIndex < 116)) {
    static const char * syntaxErrorMessageArray [116] = {kEndOfSourceLexicalErrorMessage,
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
        "the 'after' keyword",
        "the 'before' keyword",
        "the 'between' keyword",
        "the 'by' keyword",
        "the 'default' keyword",
        "the 'display' keyword",
        "the 'do' keyword",
        "the 'down' keyword",
        "the 'else' keyword",
        "the 'elsif' keyword",
        "the 'emptylist' keyword",
        "the 'emptymap' keyword",
        "the 'end' keyword",
        "the 'error' keyword",
        "the 'exists' keyword",
        "the 'false' keyword",
        "the 'for' keyword",
        "the 'foreach' keyword",
        "the 'from' keyword",
        "the 'func' keyword",
        "the 'here' keyword",
        "the 'if' keyword",
        "the 'in' keyword",
        "the 'import' keyword",
        "the 'listof' keyword",
        "the 'let' keyword",
        "the 'loop' keyword",
        "the 'mapof' keyword",
        "the 'mod' keyword",
        "the 'no' keyword",
        "the 'not' keyword",
        "the 'or' keyword",
        "the 'print' keyword",
        "the 'println' keyword",
        "the 'seed' keyword",
        "the 'repeat' keyword",
        "the 'sort' keyword",
        "the 'step' keyword",
        "the 'tab' keyword",
        "the 'template' keyword",
        "the 'then' keyword",
        "the 'to' keyword",
        "the 'true' keyword",
        "the 'typeof' keyword",
        "the 'up' keyword",
        "the 'yes' keyword",
        "the 'warning' keyword",
        "the 'while' keyword",
        "the 'write' keyword",
        "the 'executable' keyword",
        "the 'variables' keyword",
        "the 'getter' keyword",
        "the 'unlet' keyword",
        "the 'setter' keyword",
        "the 'libraries' keyword",
        "the 'input' keyword",
        "the 'break' keyword",
        "the '__VARS__' keyword",
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
        "the '@!' delimitor",
        "the '@\?' delimitor"
    } ;
    result = syntaxErrorMessageArray [inTerminalIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                      U N I C O D E    S T R I N G S                                           
//----------------------------------------------------------------------------------------------------------------------

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

//--- Unicode string for '$_40__3F_$'
static const utf32 kUnicodeString_gtl_5F_scanner__40__3F_ [] = {
  TO_UNICODE ('@'),
  TO_UNICODE ('\?'),
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

//--- Unicode string for '$_5F__5F_VARS_5F__5F_$'
static const utf32 kUnicodeString_gtl_5F_scanner__5F__5F_VARS_5F__5F_ [] = {
  TO_UNICODE ('_'),
  TO_UNICODE ('_'),
  TO_UNICODE ('V'),
  TO_UNICODE ('A'),
  TO_UNICODE ('R'),
  TO_UNICODE ('S'),
  TO_UNICODE ('_'),
  TO_UNICODE ('_'),
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

//--- Unicode string for '$seed$'
static const utf32 kUnicodeString_gtl_5F_scanner_seed [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
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

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'galgasDelimitorsList'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_gtl_5F_scanner_galgasDelimitorsList = 46 ;

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
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40__3F_, 2, C_Lexique_gtl_5F_scanner::kToken__40__3F_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40__5B_, 2, C_Lexique_gtl_5F_scanner::kToken__40__5B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__40__7B_, 2, C_Lexique_gtl_5F_scanner::kToken__40__7B_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5B__21_, 2, C_Lexique_gtl_5F_scanner::kToken__5B__21_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5E__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__5E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__7C__3D_, 2, C_Lexique_gtl_5F_scanner::kToken__7C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3C__3C__3D_, 3, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__3E__3E__3D_, 3, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_mod_3D_, 4, C_Lexique_gtl_5F_scanner::kToken_mod_3D_)
} ;

int32_t C_Lexique_gtl_5F_scanner::search_into_galgasDelimitorsList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_gtl_5F_scanner_galgasDelimitorsList, ktable_size_gtl_5F_scanner_galgasDelimitorsList) ;
}

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'goilTemplateKeyWordList'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_gtl_5F_scanner_goilTemplateKeyWordList = 58 ;

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
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_seed, 4, C_Lexique_gtl_5F_scanner::kToken_seed),
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
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner__5F__5F_VARS_5F__5F_, 8, C_Lexique_gtl_5F_scanner::kToken__5F__5F_VARS_5F__5F_),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_emptymap, 8, C_Lexique_gtl_5F_scanner::kToken_emptymap),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_template, 8, C_Lexique_gtl_5F_scanner::kToken_template),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_emptylist, 9, C_Lexique_gtl_5F_scanner::kToken_emptylist),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_libraries, 9, C_Lexique_gtl_5F_scanner::kToken_libraries),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_variables, 9, C_Lexique_gtl_5F_scanner::kToken_variables),
  C_unicode_lexique_table_entry (kUnicodeString_gtl_5F_scanner_executable, 10, C_Lexique_gtl_5F_scanner::kToken_executable)
} ;

int32_t C_Lexique_gtl_5F_scanner::search_into_goilTemplateKeyWordList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_gtl_5F_scanner_goilTemplateKeyWordList, ktable_size_gtl_5F_scanner_goilTemplateKeyWordList) ;
}


//----------------------------------------------------------------------------------------------------------------------
//                          getCurrentTokenString                                                
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_gtl_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_gtl_5F_scanner * ptr = (const cTokenFor_gtl_5F_scanner *) inTokenPtr ;
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
    case kToken_seed:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("seed") ;
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
    case kToken__5F__5F_VARS_5F__5F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("__VARS__") ;
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
    case kToken__40__3F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("@\?") ;
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

static const cTemplateDelimiter gtl_5F_scanner_kTemplateDefinitionArray [1] = {
  cTemplateDelimiter (kUnicodeString_gtl_5F_scanner__25_, 1, kUnicodeString_gtl_5F_scanner__25_, 1, nullptr, true)
} ;

//----------------------------------------------------------------------------------------------------------------------
//                           Template Replacements                                               
//----------------------------------------------------------------------------------------------------------------------

static const cTemplateDelimiter gtl_5F_scanner_kTemplateReplacementArray [3] = {
  cTemplateDelimiter (kUnicodeString_gtl_5F_scanner__5C__25_, 2, kUnicodeString_gtl_5F_scanner__25_, 1, nullptr, true),
  cTemplateDelimiter (kUnicodeString_gtl_5F_scanner__5C_n, 2, kUnicodeString_gtl_5F_scanner__A_, 1, nullptr, true),
  cTemplateDelimiter (kUnicodeString_gtl_5F_scanner__5C__5C_, 2, kUnicodeString_gtl_5F_scanner__5C_, 1, nullptr, true)
} ;

//----------------------------------------------------------------------------------------------------------------------
//            Terminal Symbols as end of script in template mark                                 
//----------------------------------------------------------------------------------------------------------------------

static const bool gtl_5F_scanner_kEndOfScriptInTemplateArray [115] = {
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
  false /* seed */,
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
  false /* __VARS__ */,
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
  false /* @! */,
  false /* @? */
} ;

//----------------------------------------------------------------------------------------------------------------------
//               INTERNAL PARSE LEXICAL TOKEN                                         
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique_gtl_5F_scanner::internalParseLexicalToken (cTokenFor_gtl_5F_scanner & token) {
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
    if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_'))) {
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
    }else if (testForInputUTF32String (kUnicodeString_gtl_5F_scanner__40__3F_, 2, true)) {
      token.mTokenCode = kToken__40__3F_ ;
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
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
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
            loop = false ;
          }
        }while (loop) ;
        loop = true ;
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
              loop = false ;
            }
          }while (loop) ;
          loop = true ;
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
                loop = false ;
              }
            }while (loop) ;
            loop = true ;
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
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
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

bool C_Lexique_gtl_5F_scanner::parseLexicalToken (void) {
  cTokenFor_gtl_5F_scanner token ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    if ((mMatchedTemplateDelimiterIndex >= 0)
     && (gtl_5F_scanner_kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndStringLength > 0)
     && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      const bool foundEndDelimitor = testForInputUTF32String (gtl_5F_scanner_kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndString,
                                                              gtl_5F_scanner_kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndStringLength,
                                                              true) ;
      if (foundEndDelimitor) {
        mMatchedTemplateDelimiterIndex = -1 ;
      }
    }
    while ((mMatchedTemplateDelimiterIndex < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      int32_t replacementIndex = 0 ;
      while (replacementIndex >= 0) {
        replacementIndex = findTemplateDelimiterIndex (gtl_5F_scanner_kTemplateReplacementArray, 3) ;
        if (replacementIndex >= 0) {
          if (gtl_5F_scanner_kTemplateReplacementArray [replacementIndex].mReplacementFunction == nullptr) {
            token.mTemplateStringBeforeToken << gtl_5F_scanner_kTemplateReplacementArray [replacementIndex].mEndString ;
          }else{
            C_String s ;
            while (notTestForInputUTF32String (gtl_5F_scanner_kTemplateReplacementArray [replacementIndex].mEndString,
                                               gtl_5F_scanner_kTemplateReplacementArray [replacementIndex].mEndStringLength,
                                               kEndOfSourceLexicalErrorMessage
                                               COMMA_HERE)) {
              s.appendUnicodeCharacter (previousChar () COMMA_HERE) ;
            }
            gtl_5F_scanner_kTemplateReplacementArray [replacementIndex].mReplacementFunction (*this, s, token.mTemplateStringBeforeToken) ;
          }
        }
      }
      mMatchedTemplateDelimiterIndex = findTemplateDelimiterIndex (gtl_5F_scanner_kTemplateDefinitionArray, 1) ;
      if (mMatchedTemplateDelimiterIndex < 0) {
        token.mTemplateStringBeforeToken.appendUnicodeCharacter (mCurrentChar COMMA_HERE) ;
        advance () ;
      }
    }
    if ((mMatchedTemplateDelimiterIndex >= 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      internalParseLexicalToken (token) ;
    }
    if ((token.mTokenCode > 0) && gtl_5F_scanner_kEndOfScriptInTemplateArray [token.mTokenCode - 1]) {
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

void C_Lexique_gtl_5F_scanner::enterToken (cTokenFor_gtl_5F_scanner & ioToken) {
  cTokenFor_gtl_5F_scanner * ptr = nullptr ;
  macroMyNew (ptr, cTokenFor_gtl_5F_scanner ()) ;
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

C_String C_Lexique_gtl_5F_scanner::attributeValue_a_5F_string (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_a_5F_string ;
}

//----------------------------------------------------------------------------------------------------------------------

utf32 C_Lexique_gtl_5F_scanner::attributeValue_charValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_charValue ;
}

//----------------------------------------------------------------------------------------------------------------------

double C_Lexique_gtl_5F_scanner::attributeValue_floatValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_floatValue ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_gtl_5F_scanner::attributeValue_functionContent (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_functionContent ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_gtl_5F_scanner::attributeValue_identifierString (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_identifierString ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BigInt C_Lexique_gtl_5F_scanner::attributeValue_intValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_intValue ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_gtl_5F_scanner::attributeValue_tokenString (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_tokenString ;
}

//----------------------------------------------------------------------------------------------------------------------

uint32_t C_Lexique_gtl_5F_scanner::attributeValue_uint_33__32_value (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_uint_33__32_value ;
}

//----------------------------------------------------------------------------------------------------------------------
//         A S S I G N    F R O M    A T T R I B U T E                                           
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_gtl_5F_scanner::synthetizedAttribute_a_5F_string (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_a_5F_string) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lchar C_Lexique_gtl_5F_scanner::synthetizedAttribute_charValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_char value (ptr->mLexicalAttribute_charValue) ;
  GALGAS_lchar result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ldouble C_Lexique_gtl_5F_scanner::synthetizedAttribute_floatValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_double value (ptr->mLexicalAttribute_floatValue) ;
  GALGAS_ldouble result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_gtl_5F_scanner::synthetizedAttribute_functionContent (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_functionContent) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_gtl_5F_scanner::synthetizedAttribute_identifierString (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_identifierString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint C_Lexique_gtl_5F_scanner::synthetizedAttribute_intValue (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_bigint value (ptr->mLexicalAttribute_intValue) ;
  GALGAS_lbigint result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_gtl_5F_scanner::synthetizedAttribute_tokenString (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_tokenString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint C_Lexique_gtl_5F_scanner::synthetizedAttribute_uint_33__32_value (void) const {
  cTokenFor_gtl_5F_scanner * ptr = (cTokenFor_gtl_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_gtl_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint value (ptr->mLexicalAttribute_uint_33__32_value) ;
  GALGAS_luint result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                         I N T R O S P E C T I O N                                             
//----------------------------------------------------------------------------------------------------------------------

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
  result.addAssign_operation (GALGAS_string ("seed") COMMA_THERE) ;
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
  result.addAssign_operation (GALGAS_string ("__VARS__") COMMA_THERE) ;
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
  result.addAssign_operation (GALGAS_string ("@\?") COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordLists_gtl_5F_scanner (TC_UniqueArray <C_String> & ioList) {
  ioList.appendObject ("gtl_scanner:galgasDelimitorsList") ;
  ioList.appendObject ("gtl_scanner:goilTemplateKeyWordList") ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordsForIdentifier_gtl_5F_scanner (const C_String & inIdentifier,
                                                     bool & ioFound,
                                                     TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "gtl_scanner:galgasDelimitorsList") {
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
    ioList.appendObject ("@\?") ;
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
  if (inIdentifier == "gtl_scanner:goilTemplateKeyWordList") {
    ioFound = true ;
    ioList.appendObject ("by") ;
    ioList.appendObject ("do") ;
    ioList.appendObject ("if") ;
    ioList.appendObject ("in") ;
    ioList.appendObject ("no") ;
    ioList.appendObject ("or") ;
    ioList.appendObject ("to") ;
    ioList.appendObject ("up") ;
    ioList.appendObject ("end") ;
    ioList.appendObject ("for") ;
    ioList.appendObject ("let") ;
    ioList.appendObject ("mod") ;
    ioList.appendObject ("not") ;
    ioList.appendObject ("tab") ;
    ioList.appendObject ("yes") ;
    ioList.appendObject ("down") ;
    ioList.appendObject ("else") ;
    ioList.appendObject ("from") ;
    ioList.appendObject ("func") ;
    ioList.appendObject ("here") ;
    ioList.appendObject ("loop") ;
    ioList.appendObject ("seed") ;
    ioList.appendObject ("sort") ;
    ioList.appendObject ("step") ;
    ioList.appendObject ("then") ;
    ioList.appendObject ("true") ;
    ioList.appendObject ("after") ;
    ioList.appendObject ("break") ;
    ioList.appendObject ("elsif") ;
    ioList.appendObject ("error") ;
    ioList.appendObject ("false") ;
    ioList.appendObject ("input") ;
    ioList.appendObject ("mapof") ;
    ioList.appendObject ("print") ;
    ioList.appendObject ("unlet") ;
    ioList.appendObject ("while") ;
    ioList.appendObject ("write") ;
    ioList.appendObject ("before") ;
    ioList.appendObject ("exists") ;
    ioList.appendObject ("getter") ;
    ioList.appendObject ("import") ;
    ioList.appendObject ("listof") ;
    ioList.appendObject ("repeat") ;
    ioList.appendObject ("setter") ;
    ioList.appendObject ("typeof") ;
    ioList.appendObject ("between") ;
    ioList.appendObject ("default") ;
    ioList.appendObject ("display") ;
    ioList.appendObject ("foreach") ;
    ioList.appendObject ("println") ;
    ioList.appendObject ("warning") ;
    ioList.appendObject ("__VARS__") ;
    ioList.appendObject ("emptymap") ;
    ioList.appendObject ("template") ;
    ioList.appendObject ("emptylist") ;
    ioList.appendObject ("libraries") ;
    ioList.appendObject ("variables") ;
    ioList.appendObject ("executable") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static cLexiqueIntrospection lexiqueIntrospection_gtl_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_gtl_5F_scanner, getKeywordsForIdentifier_gtl_5F_scanner) ;

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                           
//----------------------------------------------------------------------------------------------------------------------

uint32_t C_Lexique_gtl_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [116] = {0,
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
    1 /* gtl_scanner_1_seed */,
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
    1 /* gtl_scanner_1__5F__5F_VARS_5F__5F_ */,
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
    2 /* gtl_scanner_1__40__21_ */,
    2 /* gtl_scanner_1__40__3F_ */
  } ;
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@gtlArgumentList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_gtlArgumentList : public cCollectionElement {
  public: GALGAS_gtlArgumentList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_gtlArgumentList (const GALGAS_bool & in_typed,
                                              const GALGAS_type & in_type,
                                              const GALGAS_lstring & in_name
                                              COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_gtlArgumentList (const GALGAS_gtlArgumentList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_gtlArgumentList::cCollectionElement_gtlArgumentList (const GALGAS_bool & in_typed,
                                                                        const GALGAS_type & in_type,
                                                                        const GALGAS_lstring & in_name
                                                                        COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_typed, in_type, in_name) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_gtlArgumentList::cCollectionElement_gtlArgumentList (const GALGAS_gtlArgumentList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_typed, inElement.mProperty_type, inElement.mProperty_name) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_gtlArgumentList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_gtlArgumentList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_gtlArgumentList (mObject.mProperty_typed, mObject.mProperty_type, mObject.mProperty_name COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_gtlArgumentList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "typed" ":" ;
  mObject.mProperty_typed.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "type" ":" ;
  mObject.mProperty_type.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "name" ":" ;
  mObject.mProperty_name.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_gtlArgumentList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlArgumentList * operand = (cCollectionElement_gtlArgumentList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlArgumentList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList::GALGAS_gtlArgumentList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList::GALGAS_gtlArgumentList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlArgumentList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::constructor_listWithValue (const GALGAS_bool & inOperand0,
                                                                          const GALGAS_type & inOperand1,
                                                                          const GALGAS_lstring & inOperand2
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlArgumentList result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_gtlArgumentList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_gtlArgumentList::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                        const GALGAS_bool & in_typed,
                                                        const GALGAS_type & in_type,
                                                        const GALGAS_lstring & in_name
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlArgumentList * p = nullptr ;
  macroMyNew (p, cCollectionElement_gtlArgumentList (in_typed,
                                                     in_type,
                                                     in_name COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList::addAssign_operation (const GALGAS_bool & inOperand0,
                                                  const GALGAS_type & inOperand1,
                                                  const GALGAS_lstring & inOperand2
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlArgumentList (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList::setter_append (const GALGAS_bool inOperand0,
                                            const GALGAS_type inOperand1,
                                            const GALGAS_lstring inOperand2,
                                            C_Compiler * /* inCompiler */
                                            COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlArgumentList (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList::setter_insertAtIndex (const GALGAS_bool inOperand0,
                                                   const GALGAS_type inOperand1,
                                                   const GALGAS_lstring inOperand2,
                                                   const GALGAS_uint inInsertionIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_gtlArgumentList (inOperand0, inOperand1, inOperand2 COMMA_THERE)) ;
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

void GALGAS_gtlArgumentList::setter_removeAtIndex (GALGAS_bool & outOperand0,
                                                   GALGAS_type & outOperand1,
                                                   GALGAS_lstring & outOperand2,
                                                   const GALGAS_uint inRemoveIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        outOperand2.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
        outOperand0 = p->mObject.mProperty_typed ;
        outOperand1 = p->mObject.mProperty_type ;
        outOperand2 = p->mObject.mProperty_name ;
      }
    }else{
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList::setter_popFirst (GALGAS_bool & outOperand0,
                                              GALGAS_type & outOperand1,
                                              GALGAS_lstring & outOperand2,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    outOperand0 = p->mObject.mProperty_typed ;
    outOperand1 = p->mObject.mProperty_type ;
    outOperand2 = p->mObject.mProperty_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList::setter_popLast (GALGAS_bool & outOperand0,
                                             GALGAS_type & outOperand1,
                                             GALGAS_lstring & outOperand2,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    outOperand0 = p->mObject.mProperty_typed ;
    outOperand1 = p->mObject.mProperty_type ;
    outOperand2 = p->mObject.mProperty_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList::method_first (GALGAS_bool & outOperand0,
                                           GALGAS_type & outOperand1,
                                           GALGAS_lstring & outOperand2,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    outOperand0 = p->mObject.mProperty_typed ;
    outOperand1 = p->mObject.mProperty_type ;
    outOperand2 = p->mObject.mProperty_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList::method_last (GALGAS_bool & outOperand0,
                                          GALGAS_type & outOperand1,
                                          GALGAS_lstring & outOperand2,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    outOperand0 = p->mObject.mProperty_typed ;
    outOperand1 = p->mObject.mProperty_type ;
    outOperand2 = p->mObject.mProperty_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result = GALGAS_gtlArgumentList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result = GALGAS_gtlArgumentList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_gtlArgumentList result = GALGAS_gtlArgumentList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList::plusAssign_operation (const GALGAS_gtlArgumentList inOperand,
                                                   C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList::setter_setTypedAtIndex (GALGAS_bool inOperand,
                                                     GALGAS_uint inIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_typed = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_gtlArgumentList::getter_typedAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  GALGAS_bool result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    result = p->mObject.mProperty_typed ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList::setter_setTypeAtIndex (GALGAS_type inOperand,
                                                    GALGAS_uint inIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_type = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_type GALGAS_gtlArgumentList::getter_typeAtIndex (const GALGAS_uint & inIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  GALGAS_type result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    result = p->mObject.mProperty_type ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList::setter_setNameAtIndex (GALGAS_lstring inOperand,
                                                    GALGAS_uint inIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_name = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlArgumentList::getter_nameAtIndex (const GALGAS_uint & inIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlArgumentList * p = (cCollectionElement_gtlArgumentList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
    result = p->mObject.mProperty_name ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlArgumentList::cEnumerator_gtlArgumentList (const GALGAS_gtlArgumentList & inEnumeratedObject,
                                                          const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList_2D_element cEnumerator_gtlArgumentList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlArgumentList * p = (const cCollectionElement_gtlArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cEnumerator_gtlArgumentList::current_typed (LOCATION_ARGS) const {
  const cCollectionElement_gtlArgumentList * p = (const cCollectionElement_gtlArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
  return p->mObject.mProperty_typed ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cEnumerator_gtlArgumentList::current_type (LOCATION_ARGS) const {
  const cCollectionElement_gtlArgumentList * p = (const cCollectionElement_gtlArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
  return p->mObject.mProperty_type ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_gtlArgumentList::current_name (LOCATION_ARGS) const {
  const cCollectionElement_gtlArgumentList * p = (const cCollectionElement_gtlArgumentList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlArgumentList) ;
  return p->mObject.mProperty_name ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlArgumentList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlArgumentList ("gtlArgumentList",
                                        nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlArgumentList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlArgumentList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlArgumentList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlArgumentList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList GALGAS_gtlArgumentList::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlArgumentList result ;
  const GALGAS_gtlArgumentList * p = (const GALGAS_gtlArgumentList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlArgumentList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlArgumentList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlProcMap::cMapElement_gtlProcMap (const GALGAS_lstring & inKey,
                                                const GALGAS_gtlProcedure & in_procedure
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_procedure (in_procedure) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_gtlProcMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_gtlProcMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_gtlProcMap (mProperty_lkey, mProperty_procedure COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_gtlProcMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "procedure" ":" ;
  mProperty_procedure.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_gtlProcMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_gtlProcMap * operand = (cMapElement_gtlProcMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_procedure.objectCompare (operand->mProperty_procedure) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap::GALGAS_gtlProcMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap::GALGAS_gtlProcMap (const GALGAS_gtlProcMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap & GALGAS_gtlProcMap::operator = (const GALGAS_gtlProcMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap GALGAS_gtlProcMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_gtlProcMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap GALGAS_gtlProcMap::constructor_mapWithMapToOverride (const GALGAS_gtlProcMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_gtlProcMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap GALGAS_gtlProcMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_gtlProcMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlProcMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_gtlProcedure & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_gtlProcMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlProcMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@gtlProcMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap GALGAS_gtlProcMap::add_operation (const GALGAS_gtlProcMap & inOperand,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_gtlProcMap result = *this ;
  cEnumerator_gtlProcMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_procedure (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlProcMap::setter_put (GALGAS_lstring inKey,
                                    GALGAS_gtlProcedure inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_gtlProcMap * p = nullptr ;
  macroMyNew (p, cMapElement_gtlProcMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "a procedure named '%K' is already declared in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_gtlProcMap_get = "there is no procedure named '%K'" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlProcMap::method_get (GALGAS_lstring inKey,
                                    GALGAS_gtlProcedure & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_gtlProcMap_get
                                                                                     COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_gtlProcMap) ;
    outArgument0 = p->mProperty_procedure ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcedure GALGAS_gtlProcMap::getter_procedureForKey (const GALGAS_string & inKey,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) attributes ;
  GALGAS_gtlProcedure result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlProcMap) ;
    result = p->mProperty_procedure ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlProcMap::setter_setProcedureForKey (GALGAS_gtlProcedure inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_gtlProcMap * p = (cMapElement_gtlProcMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_gtlProcMap) ;
    p->mProperty_procedure = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_gtlProcMap * GALGAS_gtlProcMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_gtlProcMap * result = (cMapElement_gtlProcMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_gtlProcMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlProcMap::cEnumerator_gtlProcMap (const GALGAS_gtlProcMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap_2D_element cEnumerator_gtlProcMap::current (LOCATION_ARGS) const {
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlProcMap) ;
  return GALGAS_gtlProcMap_2D_element (p->mProperty_lkey, p->mProperty_procedure) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_gtlProcMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcedure cEnumerator_gtlProcMap::current_procedure (LOCATION_ARGS) const {
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_gtlProcMap) ;
  return p->mProperty_procedure ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlProcMap::optional_searchKey (const GALGAS_string & inKey,
                                            GALGAS_gtlProcedure & outArgument0) const {
  const cMapElement_gtlProcMap * p = (const cMapElement_gtlProcMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_gtlProcMap) ;
    outArgument0 = p->mProperty_procedure ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlProcMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlProcMap ("gtlProcMap",
                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlProcMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlProcMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlProcMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlProcMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap GALGAS_gtlProcMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlProcMap result ;
  const GALGAS_gtlProcMap * p = (const GALGAS_gtlProcMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlProcMap *> (p)) {
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
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__7C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 39)) ;
      GALGAS_location var_opLocation_1096 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 39)) ;
      GALGAS_gtlExpression var_rightSon_1159 ;
      nt_gtl_5F_relation_5F_term_ (var_rightSon_1159, inCompiler) ;
      outArgument_expression = GALGAS_gtlOrExpression::constructor_new (var_opLocation_1096, outArgument_expression, var_rightSon_1159  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 41)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 43)) ;
      GALGAS_location var_opLocation_1276 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 43)) ;
      GALGAS_gtlExpression var_rightSon_1339 ;
      nt_gtl_5F_relation_5F_term_ (var_rightSon_1339, inCompiler) ;
      outArgument_expression = GALGAS_gtlXorExpression::constructor_new (var_opLocation_1276, outArgument_expression, var_rightSon_1339  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 45)) ;
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
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__7C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 39)) ;
      nt_gtl_5F_relation_5F_term_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 43)) ;
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

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_relation_5F_term_indexing (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__7C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 39)) ;
      nt_gtl_5F_relation_5F_term_indexing (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 43)) ;
      nt_gtl_5F_relation_5F_term_indexing (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                                        C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  nt_gtl_5F_relation_5F_factor_ (outArgument_expression, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_gtl_5F_expression_5F_parser_1 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__26_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 59)) ;
      GALGAS_location var_opLocation_1811 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 59)) ;
      GALGAS_gtlExpression var_rightSon_1876 ;
      nt_gtl_5F_relation_5F_factor_ (var_rightSon_1876, inCompiler) ;
      outArgument_expression = GALGAS_gtlAndExpression::constructor_new (var_opLocation_1811, outArgument_expression, var_rightSon_1876  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 61)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_relation_5F_factor_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_gtl_5F_expression_5F_parser_1 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__26_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 59)) ;
      nt_gtl_5F_relation_5F_factor_parse (inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_relation_5F_factor_indexing (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_gtl_5F_expression_5F_parser_1 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__26_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 59)) ;
      nt_gtl_5F_relation_5F_factor_indexing (inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
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
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3D__3D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 75)) ;
    GALGAS_location var_opLocation_2350 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 75)) ;
    GALGAS_gtlExpression var_rightSon_2417 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2417, inCompiler) ;
    outArgument_expression = GALGAS_gtlEqualExpression::constructor_new (var_opLocation_2350, outArgument_expression, var_rightSon_2417  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 77)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__21__3D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 81)) ;
    GALGAS_location var_opLocation_2545 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 81)) ;
    GALGAS_gtlExpression var_rightSon_2612 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2612, inCompiler) ;
    outArgument_expression = GALGAS_gtlNotEqualExpression::constructor_new (var_opLocation_2545, outArgument_expression, var_rightSon_2612  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 83)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C__3D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 87)) ;
    GALGAS_location var_opLocation_2743 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 87)) ;
    GALGAS_gtlExpression var_rightSon_2810 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_2810, inCompiler) ;
    outArgument_expression = GALGAS_gtlLowerOrEqualExpression::constructor_new (var_opLocation_2743, outArgument_expression, var_rightSon_2810  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 89)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E__3D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 93)) ;
    GALGAS_location var_opLocation_2945 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 93)) ;
    GALGAS_gtlExpression var_rightSon_3012 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_3012, inCompiler) ;
    outArgument_expression = GALGAS_gtlGreaterOrEqualExpression::constructor_new (var_opLocation_2945, outArgument_expression, var_rightSon_3012  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 95)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 99)) ;
    GALGAS_location var_opLocation_3148 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 99)) ;
    GALGAS_gtlExpression var_rightSon_3215 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_3215, inCompiler) ;
    outArgument_expression = GALGAS_gtlGreaterThanExpression::constructor_new (var_opLocation_3148, outArgument_expression, var_rightSon_3215  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 101)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 105)) ;
    GALGAS_location var_opLocation_3348 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 105)) ;
    GALGAS_gtlExpression var_rightSon_3415 ;
    nt_gtl_5F_simple_5F_expression_ (var_rightSon_3415, inCompiler) ;
    outArgument_expression = GALGAS_gtlLowerThanExpression::constructor_new (var_opLocation_3348, outArgument_expression, var_rightSon_3415  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 107)) ;
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
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3D__3D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 75)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__21__3D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 81)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C__3D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 87)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E__3D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 93)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 99)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 105)) ;
    nt_gtl_5F_simple_5F_expression_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_2 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3D__3D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 75)) ;
    nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__21__3D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 81)) ;
    nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C__3D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 87)) ;
    nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E__3D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 93)) ;
    nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 99)) ;
    nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 105)) ;
    nt_gtl_5F_simple_5F_expression_indexing (inCompiler) ;
  } break ;
  default:
    break ;
  }
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
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C__3C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 123)) ;
      GALGAS_location var_opLocation_3898 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 123)) ;
      GALGAS_gtlExpression var_rightSon_3952 ;
      nt_gtl_5F_term_ (var_rightSon_3952, inCompiler) ;
      outArgument_expression = GALGAS_gtlShiftLeftExpression::constructor_new (var_opLocation_3898, outArgument_expression, var_rightSon_3952  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 125)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E__3E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 129)) ;
      GALGAS_location var_opLocation_4088 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 129)) ;
      GALGAS_gtlExpression var_rightSon_4142 ;
      nt_gtl_5F_term_ (var_rightSon_4142, inCompiler) ;
      outArgument_expression = GALGAS_gtlShiftRightExpression::constructor_new (var_opLocation_4088, outArgument_expression, var_rightSon_4142  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 131)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 135)) ;
      GALGAS_location var_opLocation_4278 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 135)) ;
      GALGAS_gtlExpression var_rightSon_4332 ;
      nt_gtl_5F_term_ (var_rightSon_4332, inCompiler) ;
      outArgument_expression = GALGAS_gtlAddExpression::constructor_new (var_opLocation_4278, outArgument_expression, var_rightSon_4332  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 137)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 141)) ;
      GALGAS_location var_opLocation_4461 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 141)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.readProperty_value ()).boolEnum () ;
        if (kBoolTrue == test_1) {
          TC_Array <C_FixItDescription> fixItArray2 ;
          appendFixItActions (fixItArray2, kFixItReplace, GALGAS_string ("+")) ;
          inCompiler->emitSemanticWarning (var_opLocation_4461, GALGAS_string ("'.' operator is deprecated"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 143)) ;
        }
      }
      GALGAS_gtlExpression var_rightSon_4655 ;
      nt_gtl_5F_term_ (var_rightSon_4655, inCompiler) ;
      outArgument_expression = GALGAS_gtlAddExpression::constructor_new (var_opLocation_4461, outArgument_expression, var_rightSon_4655  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 146)) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 150)) ;
      GALGAS_location var_opLocation_4784 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 150)) ;
      GALGAS_gtlExpression var_rightSon_4838 ;
      nt_gtl_5F_term_ (var_rightSon_4838, inCompiler) ;
      outArgument_expression = GALGAS_gtlSubstractExpression::constructor_new (var_opLocation_4784, outArgument_expression, var_rightSon_4838  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 152)) ;
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
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C__3C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 123)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E__3E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 129)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 135)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 141)) ;
      nt_gtl_5F_term_parse (inCompiler) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 150)) ;
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

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_term_indexing (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C__3C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 123)) ;
      nt_gtl_5F_term_indexing (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E__3E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 129)) ;
      nt_gtl_5F_term_indexing (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 135)) ;
      nt_gtl_5F_term_indexing (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 141)) ;
      nt_gtl_5F_term_indexing (inCompiler) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 150)) ;
      nt_gtl_5F_term_indexing (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
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
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 168)) ;
      GALGAS_location var_opLocation_5309 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 168)) ;
      GALGAS_gtlExpression var_rightSon_5365 ;
      nt_gtl_5F_factor_ (var_rightSon_5365, inCompiler) ;
      outArgument_expression = GALGAS_gtlMultiplyExpression::constructor_new (var_opLocation_5309, outArgument_expression, var_rightSon_5365  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 170)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2F_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 174)) ;
      GALGAS_location var_opLocation_5499 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 174)) ;
      GALGAS_gtlExpression var_rightSon_5555 ;
      nt_gtl_5F_factor_ (var_rightSon_5555, inCompiler) ;
      outArgument_expression = GALGAS_gtlDivideExpression::constructor_new (var_opLocation_5499, outArgument_expression, var_rightSon_5555  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 176)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_mod COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 180)) ;
      GALGAS_location var_opLocation_5689 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 180)) ;
      GALGAS_gtlExpression var_rightSon_5745 ;
      nt_gtl_5F_factor_ (var_rightSon_5745, inCompiler) ;
      outArgument_expression = GALGAS_gtlModulusExpression::constructor_new (var_opLocation_5689, outArgument_expression, var_rightSon_5745  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 182)) ;
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
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 168)) ;
      nt_gtl_5F_factor_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2F_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 174)) ;
      nt_gtl_5F_factor_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_mod COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 180)) ;
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

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_factor_indexing (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_expression_5F_parser_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 168)) ;
      nt_gtl_5F_factor_indexing (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2F_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 174)) ;
      nt_gtl_5F_factor_indexing (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_mod COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 180)) ;
      nt_gtl_5F_factor_indexing (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 195)) ;
  GALGAS_location var_opLocation_6169 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 195)) ;
  GALGAS_gtlExpression var_factorExpression_6227 ;
  nt_gtl_5F_expression_ (var_factorExpression_6227, inCompiler) ;
  outArgument_expression = GALGAS_gtlParenthesizedExpression::constructor_new (var_opLocation_6169, var_factorExpression_6227  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 197)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 201)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 195)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 201)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 195)) ;
  nt_gtl_5F_expression_indexing (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 201)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 211)) ;
  GALGAS_location var_opLocation_6661 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 211)) ;
  GALGAS_gtlExpression var_notExpression_6715 ;
  nt_gtl_5F_factor_ (var_notExpression_6715, inCompiler) ;
  outArgument_expression = GALGAS_gtlNotExpression::constructor_new (var_opLocation_6661, var_notExpression_6715  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 213)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 211)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_not COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 211)) ;
  nt_gtl_5F_factor_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__7E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 223)) ;
  GALGAS_location var_opLocation_7115 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 223)) ;
  GALGAS_gtlExpression var_notExpression_7169 ;
  nt_gtl_5F_factor_ (var_notExpression_7169, inCompiler) ;
  outArgument_expression = GALGAS_gtlNotExpression::constructor_new (var_opLocation_7115, var_notExpression_7169  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 225)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__7E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 223)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__7E_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 223)) ;
  nt_gtl_5F_factor_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 235)) ;
  GALGAS_location var_opLocation_7569 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 235)) ;
  GALGAS_gtlExpression var_minusExpression_7623 ;
  nt_gtl_5F_factor_ (var_minusExpression_7623, inCompiler) ;
  outArgument_expression = GALGAS_gtlMinusExpression::constructor_new (var_opLocation_7569, var_minusExpression_7623  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 237)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 235)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 235)) ;
  nt_gtl_5F_factor_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                              C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 247)) ;
  GALGAS_location var_opLocation_8029 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 247)) ;
  GALGAS_gtlExpression var_plusExpression_8083 ;
  nt_gtl_5F_factor_ (var_plusExpression_8083, inCompiler) ;
  outArgument_expression = GALGAS_gtlPlusExpression::constructor_new (var_opLocation_8029, var_plusExpression_8083  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 249)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 247)) ;
  nt_gtl_5F_factor_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 247)) ;
  nt_gtl_5F_factor_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_yes COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 259)) ;
  GALGAS_location var_opLocation_8488 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 259)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (var_opLocation_8488, GALGAS_gtlBool::constructor_new (var_opLocation_8488, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 261)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 261))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 260)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_yes COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 259)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_yes COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 259)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_no COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 272)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 274)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 274)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 274)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 274))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 273)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_no COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 272)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_no COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 272)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lbigint var_literalInteger_9355 = inCompiler->synthetizedAttribute_intValue () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 285)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 287)), GALGAS_gtlInt::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 287)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 287)), var_literalInteger_9355.readProperty_bigint ()  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 287))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 286)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 285)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 285)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_ldouble var_literalFloat_9812 = inCompiler->synthetizedAttribute_floatValue () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_literal_5F_double COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 298)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 300)), GALGAS_gtlFloat::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 300)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 300)), var_literalFloat_9812.readProperty_double ()  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 300))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 299)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_literal_5F_double COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 298)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_literal_5F_double COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 298)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lstring var_literalString_10259 = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 311)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 313)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 313)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 313)), var_literalString_10259.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 313))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 312)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 311)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 311)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lchar var_literalChar_10711 = inCompiler->synthetizedAttribute_charValue () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_literal_5F_char COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 324)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 326)), GALGAS_gtlChar::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 326)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 326)), var_literalChar_10711.readProperty_char ()  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 326))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 325)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_literal_5F_char COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 324)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_literal_5F_char COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 324)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 338)) ;
  GALGAS_gtlExpression var_target_11254 ;
  nt_gtl_5F_expression_ (var_target_11254, inCompiler) ;
  GALGAS_lstring var_getterName_11290 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 340)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("stringByCapitalizingFirstCharacter").objectCompare (var_getterName_11290.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_1) {
          TC_Array <C_FixItDescription> fixItArray2 ;
          appendFixItActions (fixItArray2, kFixItReplace, GALGAS_string ("capitalized")) ;
          inCompiler->emitSemanticWarning (var_getterName_11290.readProperty_location (), GALGAS_string ("stringByCapitalizingFirstCharacter is deprecated"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 343)) ;
        }
      }
    }
  }
  GALGAS_gtlExpressionList var_argumentList_11569 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 347)) ;
  switch (select_gtl_5F_expression_5F_parser_5 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 350)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      GALGAS_gtlExpression var_argument_11671 ;
      nt_gtl_5F_expression_ (var_argument_11671, inCompiler) ;
      var_argumentList_11569.addAssign_operation (var_argument_11671  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 353)) ;
      if (select_gtl_5F_expression_5F_parser_6 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 355)) ;
      }else{
        repeatFlag_3 = false ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 358)) ;
  outArgument_expression = GALGAS_gtlGetterCallExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 360)), var_target_11254, var_getterName_11290, var_argumentList_11569  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 359)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 338)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 340)) ;
  switch (select_gtl_5F_expression_5F_parser_5 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 350)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      if (select_gtl_5F_expression_5F_parser_6 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 355)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 358)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 338)) ;
  nt_gtl_5F_expression_indexing (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 340)) ;
  switch (select_gtl_5F_expression_5F_parser_5 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 350)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_indexing (inCompiler) ;
      if (select_gtl_5F_expression_5F_parser_6 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 355)) ;
      }else{
        repeatFlag_0 = false ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 358)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_gtlVarPath var_path_12027 ;
  nt_gtl_5F_variable_ (var_path_12027, inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_7 (inCompiler)) {
  case 1: {
    outArgument_expression = GALGAS_gtlVarRef::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 374)), var_path_12027  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 374)) ;
  } break ;
  case 2: {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (kIsStrictSup, var_path_12027.getter_count (SOURCE_FILE ("gtl_expression_parser.galgas", 376)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 377)), GALGAS_string ("illegal function name"), fixItArray1  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 377)) ;
      }
    }
    GALGAS_gtlExpressionList var_functionArguments_12200 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 379)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 380)) ;
    switch (select_gtl_5F_expression_5F_parser_8 (inCompiler)) {
    case 1: {
      bool repeatFlag_2 = true ;
      while (repeatFlag_2) {
        GALGAS_gtlExpression var_expression_12308 ;
        nt_gtl_5F_expression_ (var_expression_12308, inCompiler) ;
        var_functionArguments_12200.addAssign_operation (var_expression_12308  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 384)) ;
        if (select_gtl_5F_expression_5F_parser_9 (inCompiler) == 2) {
          inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 386)) ;
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
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 389)) ;
    GALGAS_lstring var_functionName_12430 = extensionGetter_pathAsFunctionName (var_path_12027, inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 390)) ;
    outArgument_expression = GALGAS_gtlFunctionCallExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 392)), var_functionName_12430, var_functionArguments_12200  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 391)) ;
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
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 380)) ;
    switch (select_gtl_5F_expression_5F_parser_8 (inCompiler)) {
    case 1: {
      bool repeatFlag_0 = true ;
      while (repeatFlag_0) {
        nt_gtl_5F_expression_parse (inCompiler) ;
        if (select_gtl_5F_expression_5F_parser_9 (inCompiler) == 2) {
          inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 386)) ;
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
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 389)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  nt_gtl_5F_variable_indexing (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_7 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 380)) ;
    switch (select_gtl_5F_expression_5F_parser_8 (inCompiler)) {
    case 1: {
      bool repeatFlag_0 = true ;
      while (repeatFlag_0) {
        nt_gtl_5F_expression_indexing (inCompiler) ;
        if (select_gtl_5F_expression_5F_parser_9 (inCompiler) == 2) {
          inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 386)) ;
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
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 389)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_exists COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 404)) ;
  GALGAS_gtlVarPath var_path_12770 ;
  nt_gtl_5F_variable_ (var_path_12770, inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_default COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 406)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 407)) ;
    GALGAS_gtlExpression var_defaultExpression_12847 ;
    nt_gtl_5F_expression_ (var_defaultExpression_12847, inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 409)) ;
    outArgument_expression = GALGAS_gtlExistsDefaultExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 411)), var_path_12770, var_defaultExpression_12847  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 410)) ;
  } break ;
  case 2: {
    outArgument_expression = GALGAS_gtlExistsExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 414)), var_path_12770  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 414)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_exists COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 404)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_default COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 406)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 407)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 409)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_exists COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 404)) ;
  nt_gtl_5F_variable_indexing (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_default COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 406)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 407)) ;
    nt_gtl_5F_expression_indexing (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 409)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_typeof COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 423)) ;
  GALGAS_gtlVarPath var_path_13217 ;
  nt_gtl_5F_variable_ (var_path_13217, inCompiler) ;
  outArgument_expression = GALGAS_gtlTypeOfExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 424)), var_path_13217  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 424)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_typeof COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 423)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_typeof COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 423)) ;
  nt_gtl_5F_variable_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_true COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 432)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 434)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 436)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 437)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 435))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 433)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_true COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 432)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_true COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 432)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_false COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 448)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 450)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 452)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 453)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 451))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 449)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_false COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 448)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_false COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 448)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  GALGAS_lstring var_enumValue_13978 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 464)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 466)), GALGAS_gtlEnum::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 468)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 469)), var_enumValue_13978.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 467))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 465)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 464)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 464)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  GALGAS_lstring var_typeName_14285 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  GALGAS_string var_name_14308 = var_typeName_14285.readProperty_string () ;
  GALGAS_gtlType var_type_14348 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_name_14308.objectCompare (GALGAS_string ("int"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      var_type_14348 = GALGAS_gtlType::constructor_new (var_typeName_14285.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 484)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 484)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, var_name_14308.objectCompare (GALGAS_string ("float"))).boolEnum () ;
      if (kBoolTrue == test_1) {
        var_type_14348 = GALGAS_gtlType::constructor_new (var_typeName_14285.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 486)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 486)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, var_name_14308.objectCompare (GALGAS_string ("string"))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_type_14348 = GALGAS_gtlType::constructor_new (var_typeName_14285.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 488)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 488)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, var_name_14308.objectCompare (GALGAS_string ("bool"))).boolEnum () ;
          if (kBoolTrue == test_3) {
            var_type_14348 = GALGAS_gtlType::constructor_new (var_typeName_14285.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 490)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 490)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, var_name_14308.objectCompare (GALGAS_string ("struct"))).boolEnum () ;
            if (kBoolTrue == test_4) {
              var_type_14348 = GALGAS_gtlType::constructor_new (var_typeName_14285.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 492)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 492)) ;
            }
          }
          if (kBoolFalse == test_4) {
            enumGalgasBool test_5 = kBoolTrue ;
            if (kBoolTrue == test_5) {
              test_5 = GALGAS_bool (kIsEqual, var_name_14308.objectCompare (GALGAS_string ("list"))).boolEnum () ;
              if (kBoolTrue == test_5) {
                var_type_14348 = GALGAS_gtlType::constructor_new (var_typeName_14285.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 494)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlList)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 494)) ;
              }
            }
            if (kBoolFalse == test_5) {
              enumGalgasBool test_6 = kBoolTrue ;
              if (kBoolTrue == test_6) {
                test_6 = GALGAS_bool (kIsEqual, var_name_14308.objectCompare (GALGAS_string ("map"))).boolEnum () ;
                if (kBoolTrue == test_6) {
                  var_type_14348 = GALGAS_gtlType::constructor_new (var_typeName_14285.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 496)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlMap)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 496)) ;
                }
              }
              if (kBoolFalse == test_6) {
                enumGalgasBool test_7 = kBoolTrue ;
                if (kBoolTrue == test_7) {
                  test_7 = GALGAS_bool (kIsEqual, var_name_14308.objectCompare (GALGAS_string ("enum"))).boolEnum () ;
                  if (kBoolTrue == test_7) {
                    var_type_14348 = GALGAS_gtlType::constructor_new (var_typeName_14285.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 498)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlEnum)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 498)) ;
                  }
                }
                if (kBoolFalse == test_7) {
                  enumGalgasBool test_8 = kBoolTrue ;
                  if (kBoolTrue == test_8) {
                    test_8 = GALGAS_bool (kIsEqual, var_name_14308.objectCompare (GALGAS_string ("type"))).boolEnum () ;
                    if (kBoolTrue == test_8) {
                      var_type_14348 = GALGAS_gtlType::constructor_new (var_typeName_14285.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 500)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlType)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 500)) ;
                    }
                  }
                  if (kBoolFalse == test_8) {
                    enumGalgasBool test_9 = kBoolTrue ;
                    if (kBoolTrue == test_9) {
                      test_9 = GALGAS_bool (kIsEqual, var_name_14308.objectCompare (GALGAS_string ("set"))).boolEnum () ;
                      if (kBoolTrue == test_9) {
                        var_type_14348 = GALGAS_gtlType::constructor_new (var_typeName_14285.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 502)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 502)) ;
                      }
                    }
                    if (kBoolFalse == test_9) {
                      enumGalgasBool test_10 = kBoolTrue ;
                      if (kBoolTrue == test_10) {
                        test_10 = GALGAS_bool (kIsEqual, var_name_14308.objectCompare (GALGAS_string ("char"))).boolEnum () ;
                        if (kBoolTrue == test_10) {
                          var_type_14348 = GALGAS_gtlType::constructor_new (var_typeName_14285.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 504)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 504)) ;
                        }
                      }
                      if (kBoolFalse == test_10) {
                        enumGalgasBool test_11 = kBoolTrue ;
                        if (kBoolTrue == test_11) {
                          test_11 = GALGAS_bool (kIsEqual, var_name_14308.objectCompare (GALGAS_string ("unconstructed"))).boolEnum () ;
                          if (kBoolTrue == test_11) {
                            var_type_14348 = GALGAS_gtlType::constructor_new (var_typeName_14285.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 506)), GALGAS_type (& kTypeDescriptor_GALGAS_gtlUnconstructed)  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 506)) ;
                          }
                        }
                        if (kBoolFalse == test_11) {
                          TC_Array <C_FixItDescription> fixItArray12 ;
                          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 507)), var_name_14308.add_operation (GALGAS_string (" does not name a type"), inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 507)), fixItArray12  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 507)) ;
                          var_type_14348.drop () ; // Release error dropped variable
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
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (var_typeName_14285.readProperty_location (), var_type_14348  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 509)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 480)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_emptylist COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 517)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("@( )")) ;
      inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 519)), GALGAS_string ("emptylist is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 519)) ;
    }
  }
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 522)), GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 524)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 525)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 526))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 523))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 521)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_emptylist COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 517)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_emptylist COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 517)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_emptymap COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 536)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("@[ ]")) ;
      inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 538)), GALGAS_string ("emptymap is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 538)) ;
    }
  }
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 541)), GALGAS_gtlMap::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 543)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 544)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expression_parser.galgas", 545))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 542))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 540)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_emptymap COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 536)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_emptymap COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 536)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_mapof COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 555)) ;
  GALGAS_gtlExpression var_data_16667 ;
  nt_gtl_5F_expression_ (var_data_16667, inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_by COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 558)) ;
    GALGAS_lstring var_key_16721 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 559)) ;
    outArgument_expression = GALGAS_gtlMapOfListExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 561)), var_data_16667, var_key_16721  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 560)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 566)) ;
    outArgument_expression = GALGAS_gtlMapOfStructExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 568)), var_data_16667  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 567)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_mapof COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 555)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_by COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 558)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 559)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 566)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_mapof COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 555)) ;
  nt_gtl_5F_expression_indexing (inCompiler) ;
  switch (select_gtl_5F_expression_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_by COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 558)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 559)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 566)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_listof COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 579)) ;
  GALGAS_gtlExpression var_data_17100 ;
  nt_gtl_5F_expression_ (var_data_17100, inCompiler) ;
  outArgument_expression = GALGAS_gtlListOfExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 581)), var_data_17100  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 581)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 582)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_listof COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 579)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 582)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_listof COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 579)) ;
  nt_gtl_5F_expression_indexing (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 582)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 590)) ;
  GALGAS_gtlExpressionList var_expressionList_17332 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 591)) ;
  switch (select_gtl_5F_expression_5F_parser_12 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_gtlExpression var_listItem_17423 ;
      nt_gtl_5F_expression_ (var_listItem_17423, inCompiler) ;
      var_expressionList_17332.addAssign_operation (var_listItem_17423  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 595)) ;
      if (select_gtl_5F_expression_5F_parser_13 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 596)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 600)) ;
  outArgument_expression = GALGAS_gtlLiteralListExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 601)), var_expressionList_17332  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 601)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 590)) ;
  switch (select_gtl_5F_expression_5F_parser_12 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      if (select_gtl_5F_expression_5F_parser_13 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 596)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 600)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 590)) ;
  switch (select_gtl_5F_expression_5F_parser_12 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_indexing (inCompiler) ;
      if (select_gtl_5F_expression_5F_parser_13 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 596)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 600)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 609)) ;
  GALGAS_gtlExpressionMap var_expressionMap_17738 = GALGAS_gtlExpressionMap::constructor_emptyMap (SOURCE_FILE ("gtl_expression_parser.galgas", 610)) ;
  switch (select_gtl_5F_expression_5F_parser_14 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_key_17814 = inCompiler->synthetizedAttribute_a_5F_string () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 613)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 614)) ;
      GALGAS_gtlExpression var_mapItem_17871 ;
      nt_gtl_5F_expression_ (var_mapItem_17871, inCompiler) ;
      {
      var_expressionMap_17738.setter_put (var_key_17814, var_mapItem_17871, inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 616)) ;
      }
      if (select_gtl_5F_expression_5F_parser_15 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 617)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 621)) ;
  outArgument_expression = GALGAS_gtlLiteralMapExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 622)), var_expressionMap_17738  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 622)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 609)) ;
  switch (select_gtl_5F_expression_5F_parser_14 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 613)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 614)) ;
      nt_gtl_5F_expression_parse (inCompiler) ;
      if (select_gtl_5F_expression_5F_parser_15 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 617)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 621)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 609)) ;
  switch (select_gtl_5F_expression_5F_parser_14 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 613)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 614)) ;
      nt_gtl_5F_expression_indexing (inCompiler) ;
      if (select_gtl_5F_expression_5F_parser_15 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 617)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 621)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__7B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 630)) ;
  GALGAS_gtlExpressionMap var_expressionMap_18191 = GALGAS_gtlExpressionMap::constructor_emptyMap (SOURCE_FILE ("gtl_expression_parser.galgas", 631)) ;
  switch (select_gtl_5F_expression_5F_parser_16 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_fieldName_18270 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 634)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 635)) ;
      GALGAS_gtlExpression var_structField_18333 ;
      nt_gtl_5F_expression_ (var_structField_18333, inCompiler) ;
      {
      var_expressionMap_18191.setter_put (var_fieldName_18270, var_structField_18333, inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 637)) ;
      }
      if (select_gtl_5F_expression_5F_parser_17 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 638)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__7D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 642)) ;
  outArgument_expression = GALGAS_gtlLiteralStructExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 643)), var_expressionMap_18191  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 643)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__7B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 630)) ;
  switch (select_gtl_5F_expression_5F_parser_16 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 634)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 635)) ;
      nt_gtl_5F_expression_parse (inCompiler) ;
      if (select_gtl_5F_expression_5F_parser_17 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 638)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__7D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 642)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__7B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 630)) ;
  switch (select_gtl_5F_expression_5F_parser_16 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 634)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 635)) ;
      nt_gtl_5F_expression_indexing (inCompiler) ;
      if (select_gtl_5F_expression_5F_parser_17 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 638)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__7D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 642)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__21_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 651)) ;
  GALGAS_gtlExpressionList var_expressionList_18671 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 652)) ;
  switch (select_gtl_5F_expression_5F_parser_18 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_gtlExpression var_setElement_18762 ;
      nt_gtl_5F_expression_ (var_setElement_18762, inCompiler) ;
      var_expressionList_18671.addAssign_operation (var_setElement_18762  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 656)) ;
      if (select_gtl_5F_expression_5F_parser_19 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 657)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__21_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 661)) ;
  outArgument_expression = GALGAS_gtlLiteralSetExpression::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 662)), var_expressionList_18671  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 662)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__21_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 651)) ;
  switch (select_gtl_5F_expression_5F_parser_18 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      if (select_gtl_5F_expression_5F_parser_19 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 657)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__21_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 661)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__21_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 651)) ;
  switch (select_gtl_5F_expression_5F_parser_18 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_indexing (inCompiler) ;
      if (select_gtl_5F_expression_5F_parser_19 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 657)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__21_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 661)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i32_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__3F_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 670)) ;
  GALGAS_gtlExpression var_exp_19099 ;
  nt_gtl_5F_expression_ (var_exp_19099, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3F_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 672)) ;
  outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 673)), GALGAS_gtlExpr::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 673)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 673)), var_exp_19099  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 673))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 673)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i32_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__3F_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 670)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3F_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 672)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i32_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40__3F_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 670)) ;
  nt_gtl_5F_expression_indexing (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3F_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 672)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i33_ (GALGAS_gtlExpression & outArgument_expression,
                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5F__5F_VARS_5F__5F_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 681)) ;
  outArgument_expression = GALGAS_gtlAllVarsRef::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 682))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 682)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i33_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5F__5F_VARS_5F__5F_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 681)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i33_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5F__5F_VARS_5F__5F_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 681)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i34_ (GALGAS_gtlVarPath & outArgument_path,
                                                                                                 C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_path.drop () ; // Release 'out' argument
  outArgument_path = GALGAS_gtlVarPath::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 690)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_lstring var_variableName_19577 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 692)) ;
    switch (select_gtl_5F_expression_5F_parser_21 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 694)) ;
      GALGAS_gtlExpression var_expression_19654 ;
      nt_gtl_5F_expression_ (var_expression_19654, inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 696)) ;
      outArgument_path.addAssign_operation (GALGAS_gtlVarItemCollection::constructor_new (var_variableName_19577, var_expression_19654  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 697))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 697)) ;
      switch (select_gtl_5F_expression_5F_parser_22 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 699)) ;
        GALGAS_gtlExpression var_expression_19816 ;
        nt_gtl_5F_expression_ (var_expression_19816, inCompiler) ;
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 701)) ;
        outArgument_path.addAssign_operation (GALGAS_gtlVarItemSubCollection::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 702)), var_expression_19816  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 702))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 702)) ;
        bool repeatFlag_1 = true ;
        while (repeatFlag_1) {
          if (select_gtl_5F_expression_5F_parser_23 (inCompiler) == 2) {
            inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 705)) ;
            GALGAS_gtlExpression var_expression_19998 ;
            nt_gtl_5F_expression_ (var_expression_19998, inCompiler) ;
            inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 707)) ;
            outArgument_path.addAssign_operation (GALGAS_gtlVarItemSubCollection::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 708)), var_expression_19998  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 708))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 708)) ;
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
      outArgument_path.addAssign_operation (GALGAS_gtlVarItemField::constructor_new (var_variableName_19577  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 713))  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 713)) ;
    } break ;
    default:
      break ;
    }
    if (select_gtl_5F_expression_5F_parser_20 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 716)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i34_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 692)) ;
    switch (select_gtl_5F_expression_5F_parser_21 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 694)) ;
      nt_gtl_5F_expression_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 696)) ;
      switch (select_gtl_5F_expression_5F_parser_22 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 699)) ;
        nt_gtl_5F_expression_parse (inCompiler) ;
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 701)) ;
        bool repeatFlag_1 = true ;
        while (repeatFlag_1) {
          if (select_gtl_5F_expression_5F_parser_23 (inCompiler) == 2) {
            inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 705)) ;
            nt_gtl_5F_expression_parse (inCompiler) ;
            inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 707)) ;
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
    if (select_gtl_5F_expression_5F_parser_20 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 716)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i34_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 692)) ;
    switch (select_gtl_5F_expression_5F_parser_21 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 694)) ;
      nt_gtl_5F_expression_indexing (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 696)) ;
      switch (select_gtl_5F_expression_5F_parser_22 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 699)) ;
        nt_gtl_5F_expression_indexing (inCompiler) ;
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 701)) ;
        bool repeatFlag_1 = true ;
        while (repeatFlag_1) {
          if (select_gtl_5F_expression_5F_parser_23 (inCompiler) == 2) {
            inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 705)) ;
            nt_gtl_5F_expression_indexing (inCompiler) ;
            inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 707)) ;
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
    if (select_gtl_5F_expression_5F_parser_20 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 716)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i35_ (GALGAS_gtlVarPath & outArgument_path,
                                                                                                               GALGAS_bool & outArgument_hereInstead,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_path.drop () ; // Release 'out' argument
  outArgument_hereInstead.drop () ; // Release 'out' argument
  switch (select_gtl_5F_expression_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_here COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 727)) ;
    outArgument_path = GALGAS_gtlVarPath::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 727)) ;
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

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i35_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  switch (select_gtl_5F_expression_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_here COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 727)) ;
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

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i35_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  switch (select_gtl_5F_expression_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_here COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 727)) ;
  } break ;
  case 2: {
    nt_gtl_5F_variable_indexing (inCompiler) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i36_ (GALGAS_gtlArgumentList & outArgument_arguments,
                                                                                                         C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_arguments.drop () ; // Release 'out' argument
  outArgument_arguments = GALGAS_gtlArgumentList::constructor_emptyList (SOURCE_FILE ("gtl_expression_parser.galgas", 739)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 740)) ;
  switch (select_gtl_5F_expression_5F_parser_25 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_argumentName_20720 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 743)) ;
      switch (select_gtl_5F_expression_5F_parser_27 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 745)) ;
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 745)) ;
        GALGAS_lstring var_typeName_20793 = inCompiler->synthetizedAttribute_tokenString () ;
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 745)) ;
        outArgument_arguments.addAssign_operation (GALGAS_bool (true), extensionGetter_gtlType (var_typeName_20793, inCompiler COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 746)), var_argumentName_20720  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 746)) ;
      } break ;
      case 2: {
        outArgument_arguments.addAssign_operation (GALGAS_bool (false), GALGAS_type (& kTypeDescriptor_GALGAS_gtlData), var_argumentName_20720  COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 748)) ;
      } break ;
      default:
        break ;
      }
      if (select_gtl_5F_expression_5F_parser_26 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 750)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 753)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i36_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 740)) ;
  switch (select_gtl_5F_expression_5F_parser_25 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 743)) ;
      switch (select_gtl_5F_expression_5F_parser_27 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 745)) ;
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 745)) ;
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 745)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      if (select_gtl_5F_expression_5F_parser_26 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 750)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 753)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_expression_5F_parser::rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i36_indexing (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 740)) ;
  switch (select_gtl_5F_expression_5F_parser_25 (inCompiler)) {
  case 1: {
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 743)) ;
      switch (select_gtl_5F_expression_5F_parser_27 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 745)) ;
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 745)) ;
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 745)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      if (select_gtl_5F_expression_5F_parser_26 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 750)) ;
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
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_expression_parser.galgas", 753)) ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



typeComparisonResult GALGAS_gtlInstruction::objectCompare (const GALGAS_gtlInstruction & inOperand) const {
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

GALGAS_gtlInstruction::GALGAS_gtlInstruction (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstruction::GALGAS_gtlInstruction (const cPtr_gtlInstruction * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_gtlInstruction::readProperty_where (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_location () ;
  }else{
    const cPtr_gtlInstruction * p = (const cPtr_gtlInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlInstruction) ;
    return p->mProperty_where ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cPtr_gtlInstruction::getter_where (UNUSED_LOCATION_ARGS) const {
  return mProperty_where ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_gtlInstruction::readProperty_signature (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_gtlInstruction * p = (const cPtr_gtlInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlInstruction) ;
    return p->mProperty_signature ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlInstruction::getter_signature (UNUSED_LOCATION_ARGS) const {
  return mProperty_signature ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstruction::setter_setWhere (GALGAS_location inValue
                                             COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlInstruction * p = (cPtr_gtlInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlInstruction) ;
    p->mProperty_where = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlInstruction::setter_setWhere (GALGAS_location inValue
                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_where = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstruction::setter_setSignature (GALGAS_string inValue
                                                 COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlInstruction * p = (cPtr_gtlInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlInstruction) ;
    p->mProperty_signature = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlInstruction::setter_setSignature (GALGAS_string inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_signature = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlInstruction::cPtr_gtlInstruction (const GALGAS_location & in_where,
                                          const GALGAS_string & in_signature
                                          COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_where (in_where),
mProperty_signature (in_signature) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInstruction ("gtlInstruction",
                                       nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstruction GALGAS_gtlInstruction::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstruction result ;
  const GALGAS_gtlInstruction * p = (const GALGAS_gtlInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlInstruction location'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cPtr_gtlInstruction::getter_location (C_Compiler */* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_location result_result ; // Returned variable
  result_result = this->mProperty_where ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_location callExtensionGetter_location (const cPtr_gtlInstruction * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_location result ;
  if (nullptr != inObject) {
    result = inObject->getter_location (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@gtlInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_execute (cPtr_gtlInstruction * inObject,
                                  GALGAS_gtlContext & io_context,
                                  GALGAS_gtlData & io_vars,
                                  GALGAS_library & io_lib,
                                  GALGAS_string & io_outputString,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlInstruction) ;
    inObject->method_execute (io_context, io_vars, io_lib, io_outputString, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlInstructionList execute'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_execute (const GALGAS_gtlInstructionList inObject,
                              GALGAS_gtlContext & ioArgument_context,
                              GALGAS_gtlData & ioArgument_vars,
                              GALGAS_library & ioArgument_lib,
                              GALGAS_string & ioArgument_outputString,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_debugActive ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 60)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      const GALGAS_gtlInstructionList temp_1 = inObject ;
      ioArgument_context.insulate (HERE) ;
      cPtr_gtlContext * ptr_1570 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
      callExtensionSetter_pushInstructionList ((cPtr_gtlContext *) ptr_1570, temp_1, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 61)) ;
      }
      GALGAS_uint var_lastErrorCount_1615 = GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 62)) ;
      const GALGAS_gtlInstructionList temp_2 = inObject ;
      cEnumerator_gtlInstructionList enumerator_1652 (temp_2, kENUMERATION_UP) ;
      GALGAS_uint index_1648 ((uint32_t) 0) ;
      while (enumerator_1652.hasCurrentObject ()) {
        GALGAS_bool var_errorCountIncreased_1690 = GALGAS_bool (kIsStrictSup, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 64)).substract_operation (var_lastErrorCount_1615, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 64)).objectCompare (GALGAS_uint (uint32_t (0U)))) ;
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = callExtensionGetter_breakOnNext ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 65)).operator_or (callExtensionGetter_breakOn ((const cPtr_gtlContext *) ioArgument_context.ptr (), enumerator_1652.current_instruction (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 65)) COMMA_SOURCE_FILE ("gtl_instructions.galgas", 65)).operator_or (callExtensionGetter_watchOn ((const cPtr_gtlContext *) ioArgument_context.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 66)) COMMA_SOURCE_FILE ("gtl_instructions.galgas", 65)).operator_or (var_errorCountIncreased_1690 COMMA_SOURCE_FILE ("gtl_instructions.galgas", 66)).boolEnum () ;
          if (kBoolTrue == test_3) {
            {
            ioArgument_context.insulate (HERE) ;
            cPtr_gtlContext * ptr_1903 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
            callExtensionSetter_setBreakOnNext ((cPtr_gtlContext *) ptr_1903, GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 67)) ;
            }
            {
            ioArgument_context.insulate (HERE) ;
            cPtr_gtlContext * ptr_1944 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
            callExtensionSetter_setNextInstructionIndex ((cPtr_gtlContext *) ptr_1944, index_1648, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 68)) ;
            }
            {
            ioArgument_context.insulate (HERE) ;
            cPtr_gtlContext * ptr_1995 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
            callExtensionSetter_setDebugger ((cPtr_gtlContext *) ptr_1995, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 69)) ;
            }
            {
            ioArgument_context.insulate (HERE) ;
            cPtr_gtlContext * ptr_2034 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
            callExtensionSetter_executeStepDoList ((cPtr_gtlContext *) ptr_2034, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 70)) ;
            }
            {
            ioArgument_context.insulate (HERE) ;
            cPtr_gtlContext * ptr_2110 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
            callExtensionSetter_setDebugger ((cPtr_gtlContext *) ptr_2110, GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 71)) ;
            }
            {
            ioArgument_context.insulate (HERE) ;
            cPtr_gtlContext * ptr_2148 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
            callExtensionSetter_setLoopOnCommand ((cPtr_gtlContext *) ptr_2148, GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 72)) ;
            }
            if (GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_instructions.galgas", 73)).isValid ()) {
              uint32_t variant_2188 = GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_instructions.galgas", 73)).uintValue () ;
              bool loop_2188 = true ;
              while (loop_2188) {
                  inCompiler->printMessage (callExtensionGetter_promptStyle ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 74)).add_operation (GALGAS_string ("gtl> "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 74)).add_operation (function_endc (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 74)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 74))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 74)) ;
                  GALGAS_string var_input_2309 ;
                  {
                  ioArgument_context.insulate (HERE) ;
                  cPtr_gtlContext * ptr_2277 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
                  callExtensionSetter_getCommand ((cPtr_gtlContext *) ptr_2277, var_input_2309, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 75)) ;
                  }
                  GALGAS_gtlInstruction var_command_2346 ;
                  GALGAS_uint var_currentErrorCount_2374 = GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 77)) ;
                  enumGalgasBool test_4 = kBoolTrue ;
                  if (kBoolTrue == test_4) {
                    test_4 = GALGAS_bool (kIsEqual, var_input_2309.getter_stringByTrimmingWhiteSpaces (SOURCE_FILE ("gtl_instructions.galgas", 78)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                    if (kBoolTrue == test_4) {
                      var_command_2346 = GALGAS_gtlStepInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 79)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 79)) ;
                    }
                  }
                  if (kBoolFalse == test_4) {
                    var_command_2346.drop () ;
                    cGrammar_gtl_5F_debugger_5F_grammar::_performSourceStringParsing_ (inCompiler, var_input_2309, GALGAS_string ("Debugger command"), var_command_2346  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 81)) ;
                  }
                  enumGalgasBool test_5 = kBoolTrue ;
                  if (kBoolTrue == test_5) {
                    test_5 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 84)).objectCompare (var_currentErrorCount_2374)).boolEnum () ;
                    if (kBoolTrue == test_5) {
                      enumGalgasBool test_6 = kBoolTrue ;
                      if (kBoolTrue == test_6) {
                        test_6 = callExtensionGetter_mayExecuteWithoutError ((const cPtr_gtlInstruction *) var_command_2346.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 85)).boolEnum () ;
                        if (kBoolTrue == test_6) {
                          inCompiler->printMessage (callExtensionGetter_outputStyle ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 86))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 86)) ;
                          {
                          ioArgument_context.insulate (HERE) ;
                          cPtr_gtlContext * ptr_2846 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
                          callExtensionSetter_setDebugger ((cPtr_gtlContext *) ptr_2846, GALGAS_bool (false), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 87)) ;
                          }
                          callExtensionMethod_execute ((cPtr_gtlInstruction *) var_command_2346.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 88)) ;
                          {
                          ioArgument_context.insulate (HERE) ;
                          cPtr_gtlContext * ptr_2961 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
                          callExtensionSetter_setDebugger ((cPtr_gtlContext *) ptr_2961, GALGAS_bool (true), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 89)) ;
                          }
                          inCompiler->printMessage (function_endc (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 90))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 90)) ;
                        }
                      }
                    }
                  }
                loop_2188 = callExtensionGetter_loopOnCommand ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 93)).isValid () ;
                if (loop_2188) {
                  loop_2188 = callExtensionGetter_loopOnCommand ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 93)).boolValue () ;
                }
                if (loop_2188 && (0 == variant_2188)) {
                  loop_2188 = false ;
                  inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_instructions.galgas", 73)) ;
                }
                if (loop_2188) {
                  variant_2188 -- ;
                }
              }
            }
          }
        }
        var_lastErrorCount_1615 = GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 96)) ;
        callExtensionMethod_execute ((cPtr_gtlInstruction *) enumerator_1652.current_instruction (HERE).ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 97)) ;
        enumerator_1652.gotoNextObject () ;
        index_1648.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 63)) ;
      }
      {
      ioArgument_context.insulate (HERE) ;
      cPtr_gtlContext * ptr_3226 = (cPtr_gtlContext *) ioArgument_context.ptr () ;
      callExtensionSetter_popInstructionList ((cPtr_gtlContext *) ptr_3226, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 99)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    const GALGAS_gtlInstructionList temp_7 = inObject ;
    cEnumerator_gtlInstructionList enumerator_3269 (temp_7, kENUMERATION_UP) ;
    while (enumerator_3269.hasCurrentObject ()) {
      enumGalgasBool test_8 = kBoolTrue ;
      if (kBoolTrue == test_8) {
        test_8 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 102)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_8) {
          callExtensionMethod_execute ((cPtr_gtlInstruction *) enumerator_3269.current_instruction (HERE).ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 103)) ;
          enumGalgasBool test_9 = kBoolTrue ;
          if (kBoolTrue == test_9) {
            test_9 = GALGAS_bool (kIsNotEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("gtl_instructions.galgas", 104)).objectCompare (GALGAS_uint (uint32_t (0U)))).operator_and (ioArgument_context.readProperty_propagateError () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 104)).boolEnum () ;
            if (kBoolTrue == test_9) {
              TC_Array <C_FixItDescription> fixItArray10 ;
              inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlInstruction *) enumerator_3269.current_instruction (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 105)), GALGAS_string ("runtime error"), fixItArray10  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 105)) ;
            }
          }
        }
      }
      enumerator_3269.gotoNextObject () ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLetUnconstructedInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLetUnconstructedInstruction * p = (const cPtr_gtlLetUnconstructedInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLetUnconstructedInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lValue.objectCompare (p->mProperty_lValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLetUnconstructedInstruction::GALGAS_gtlLetUnconstructedInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLetUnconstructedInstruction GALGAS_gtlLetUnconstructedInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLetUnconstructedInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                                 GALGAS_string::constructor_default (HERE),
                                                                 GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                                                 COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLetUnconstructedInstruction::GALGAS_gtlLetUnconstructedInstruction (const cPtr_gtlLetUnconstructedInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLetUnconstructedInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlLetUnconstructedInstruction::readProperty_lValue (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlVarPath () ;
  }else{
    const cPtr_gtlLetUnconstructedInstruction * p = (const cPtr_gtlLetUnconstructedInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLetUnconstructedInstruction) ;
    return p->mProperty_lValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath cPtr_gtlLetUnconstructedInstruction::getter_lValue (UNUSED_LOCATION_ARGS) const {
  return mProperty_lValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlLetUnconstructedInstruction::setter_setLValue (GALGAS_gtlVarPath inValue
                                                              COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLetUnconstructedInstruction * p = (cPtr_gtlLetUnconstructedInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLetUnconstructedInstruction) ;
    p->mProperty_lValue = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLetUnconstructedInstruction::setter_setLValue (GALGAS_gtlVarPath inValue
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_lValue = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlLetUnconstructedInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlLetUnconstructedInstruction::cPtr_gtlLetUnconstructedInstruction (const GALGAS_location & in_where,
                                                                          const GALGAS_string & in_signature,
                                                                          const GALGAS_gtlVarPath & in_lValue
                                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_lValue (in_lValue) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLetUnconstructedInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetUnconstructedInstruction ;
}

void cPtr_gtlLetUnconstructedInstruction::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "[@gtlLetUnconstructedInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLetUnconstructedInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLetUnconstructedInstruction (mProperty_where, mProperty_signature, mProperty_lValue COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlLetUnconstructedInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLetUnconstructedInstruction ("gtlLetUnconstructedInstruction",
                                                       & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLetUnconstructedInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLetUnconstructedInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLetUnconstructedInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLetUnconstructedInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLetUnconstructedInstruction GALGAS_gtlLetUnconstructedInstruction::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlLetUnconstructedInstruction result ;
  const GALGAS_gtlLetUnconstructedInstruction * p = (const GALGAS_gtlLetUnconstructedInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLetUnconstructedInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLetUnconstructedInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlUnletInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlUnletInstruction * p = (const cPtr_gtlUnletInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlUnletInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lValue.objectCompare (p->mProperty_lValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlUnletInstruction::GALGAS_gtlUnletInstruction (void) :
GALGAS_gtlLetUnconstructedInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlUnletInstruction GALGAS_gtlUnletInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlUnletInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                      GALGAS_string::constructor_default (HERE),
                                                      GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                                      COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlUnletInstruction::GALGAS_gtlUnletInstruction (const cPtr_gtlUnletInstruction * inSourcePtr) :
GALGAS_gtlLetUnconstructedInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlUnletInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlUnletInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlUnletInstruction::cPtr_gtlUnletInstruction (const GALGAS_location & in_where,
                                                    const GALGAS_string & in_signature,
                                                    const GALGAS_gtlVarPath & in_lValue
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlLetUnconstructedInstruction (in_where, in_signature, in_lValue COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlUnletInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlUnletInstruction ;
}

void cPtr_gtlUnletInstruction::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlUnletInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlUnletInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlUnletInstruction (mProperty_where, mProperty_signature, mProperty_lValue COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlUnletInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlUnletInstruction ("gtlUnletInstruction",
                                            & kTypeDescriptor_GALGAS_gtlLetUnconstructedInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlUnletInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlUnletInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlUnletInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlUnletInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlUnletInstruction GALGAS_gtlUnletInstruction::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlUnletInstruction result ;
  const GALGAS_gtlUnletInstruction * p = (const GALGAS_gtlUnletInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlUnletInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlUnletInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlTemplateStringInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlTemplateStringInstruction * p = (const cPtr_gtlTemplateStringInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlTemplateStringInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateStringInstruction::GALGAS_gtlTemplateStringInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateStringInstruction GALGAS_gtlTemplateStringInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlTemplateStringInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                               GALGAS_string::constructor_default (HERE),
                                                               GALGAS_string::constructor_default (HERE)
                                                               COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateStringInstruction::GALGAS_gtlTemplateStringInstruction (const cPtr_gtlTemplateStringInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlTemplateStringInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_gtlTemplateStringInstruction::readProperty_value (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_gtlTemplateStringInstruction * p = (const cPtr_gtlTemplateStringInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateStringInstruction) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlTemplateStringInstruction::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateStringInstruction::setter_setValue (GALGAS_string inValue
                                                           COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlTemplateStringInstruction * p = (cPtr_gtlTemplateStringInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplateStringInstruction) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlTemplateStringInstruction::setter_setValue (GALGAS_string inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlTemplateStringInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlTemplateStringInstruction::cPtr_gtlTemplateStringInstruction (const GALGAS_location & in_where,
                                                                      const GALGAS_string & in_signature,
                                                                      const GALGAS_string & in_value
                                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlTemplateStringInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateStringInstruction ;
}

void cPtr_gtlTemplateStringInstruction::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "[@gtlTemplateStringInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlTemplateStringInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlTemplateStringInstruction (mProperty_where, mProperty_signature, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlTemplateStringInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTemplateStringInstruction ("gtlTemplateStringInstruction",
                                                     & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlTemplateStringInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateStringInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlTemplateStringInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTemplateStringInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateStringInstruction GALGAS_gtlTemplateStringInstruction::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateStringInstruction result ;
  const GALGAS_gtlTemplateStringInstruction * p = (const GALGAS_gtlTemplateStringInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlTemplateStringInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTemplateStringInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlGetColumnInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlGetColumnInstruction * p = (const cPtr_gtlGetColumnInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlGetColumnInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_destVariable.objectCompare (p->mProperty_destVariable) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetColumnInstruction::GALGAS_gtlGetColumnInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetColumnInstruction GALGAS_gtlGetColumnInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlGetColumnInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                          GALGAS_string::constructor_default (HERE),
                                                          GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                                          COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetColumnInstruction::GALGAS_gtlGetColumnInstruction (const cPtr_gtlGetColumnInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlGetColumnInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlGetColumnInstruction::readProperty_destVariable (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlVarPath () ;
  }else{
    const cPtr_gtlGetColumnInstruction * p = (const cPtr_gtlGetColumnInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetColumnInstruction) ;
    return p->mProperty_destVariable ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath cPtr_gtlGetColumnInstruction::getter_destVariable (UNUSED_LOCATION_ARGS) const {
  return mProperty_destVariable ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlGetColumnInstruction::setter_setDestVariable (GALGAS_gtlVarPath inValue
                                                             COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlGetColumnInstruction * p = (cPtr_gtlGetColumnInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetColumnInstruction) ;
    p->mProperty_destVariable = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlGetColumnInstruction::setter_setDestVariable (GALGAS_gtlVarPath inValue
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_destVariable = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlGetColumnInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlGetColumnInstruction::cPtr_gtlGetColumnInstruction (const GALGAS_location & in_where,
                                                            const GALGAS_string & in_signature,
                                                            const GALGAS_gtlVarPath & in_destVariable
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_destVariable (in_destVariable) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlGetColumnInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetColumnInstruction ;
}

void cPtr_gtlGetColumnInstruction::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlGetColumnInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_destVariable.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlGetColumnInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlGetColumnInstruction (mProperty_where, mProperty_signature, mProperty_destVariable COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlGetColumnInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGetColumnInstruction ("gtlGetColumnInstruction",
                                                & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlGetColumnInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetColumnInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlGetColumnInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGetColumnInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetColumnInstruction GALGAS_gtlGetColumnInstruction::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetColumnInstruction result ;
  const GALGAS_gtlGetColumnInstruction * p = (const GALGAS_gtlGetColumnInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlGetColumnInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGetColumnInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@gtlThenElsifStatementList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_gtlThenElsifStatementList : public cCollectionElement {
  public: GALGAS_gtlThenElsifStatementList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_gtlThenElsifStatementList (const GALGAS_gtlExpression & in_condition,
                                                        const GALGAS_gtlInstructionList & in_instructionList
                                                        COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_gtlThenElsifStatementList (const GALGAS_gtlThenElsifStatementList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_gtlThenElsifStatementList::cCollectionElement_gtlThenElsifStatementList (const GALGAS_gtlExpression & in_condition,
                                                                                            const GALGAS_gtlInstructionList & in_instructionList
                                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_condition, in_instructionList) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_gtlThenElsifStatementList::cCollectionElement_gtlThenElsifStatementList (const GALGAS_gtlThenElsifStatementList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_condition, inElement.mProperty_instructionList) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_gtlThenElsifStatementList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_gtlThenElsifStatementList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_gtlThenElsifStatementList (mObject.mProperty_condition, mObject.mProperty_instructionList COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_gtlThenElsifStatementList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "condition" ":" ;
  mObject.mProperty_condition.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "instructionList" ":" ;
  mObject.mProperty_instructionList.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_gtlThenElsifStatementList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlThenElsifStatementList * operand = (cCollectionElement_gtlThenElsifStatementList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlThenElsifStatementList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList::GALGAS_gtlThenElsifStatementList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList::GALGAS_gtlThenElsifStatementList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlThenElsifStatementList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::constructor_listWithValue (const GALGAS_gtlExpression & inOperand0,
                                                                                              const GALGAS_gtlInstructionList & inOperand1
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlThenElsifStatementList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlThenElsifStatementList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_gtlThenElsifStatementList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlThenElsifStatementList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                  const GALGAS_gtlExpression & in_condition,
                                                                  const GALGAS_gtlInstructionList & in_instructionList
                                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlThenElsifStatementList * p = nullptr ;
  macroMyNew (p, cCollectionElement_gtlThenElsifStatementList (in_condition,
                                                               in_instructionList COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlThenElsifStatementList::addAssign_operation (const GALGAS_gtlExpression & inOperand0,
                                                            const GALGAS_gtlInstructionList & inOperand1
                                                            COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlThenElsifStatementList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlThenElsifStatementList::setter_append (const GALGAS_gtlExpression inOperand0,
                                                      const GALGAS_gtlInstructionList inOperand1,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlThenElsifStatementList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlThenElsifStatementList::setter_insertAtIndex (const GALGAS_gtlExpression inOperand0,
                                                             const GALGAS_gtlInstructionList inOperand1,
                                                             const GALGAS_uint inInsertionIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_gtlThenElsifStatementList (inOperand0, inOperand1 COMMA_THERE)) ;
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

void GALGAS_gtlThenElsifStatementList::setter_removeAtIndex (GALGAS_gtlExpression & outOperand0,
                                                             GALGAS_gtlInstructionList & outOperand1,
                                                             const GALGAS_uint inRemoveIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
        outOperand0 = p->mObject.mProperty_condition ;
        outOperand1 = p->mObject.mProperty_instructionList ;
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

void GALGAS_gtlThenElsifStatementList::setter_popFirst (GALGAS_gtlExpression & outOperand0,
                                                        GALGAS_gtlInstructionList & outOperand1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    outOperand0 = p->mObject.mProperty_condition ;
    outOperand1 = p->mObject.mProperty_instructionList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlThenElsifStatementList::setter_popLast (GALGAS_gtlExpression & outOperand0,
                                                       GALGAS_gtlInstructionList & outOperand1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    outOperand0 = p->mObject.mProperty_condition ;
    outOperand1 = p->mObject.mProperty_instructionList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlThenElsifStatementList::method_first (GALGAS_gtlExpression & outOperand0,
                                                     GALGAS_gtlInstructionList & outOperand1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    outOperand0 = p->mObject.mProperty_condition ;
    outOperand1 = p->mObject.mProperty_instructionList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlThenElsifStatementList::method_last (GALGAS_gtlExpression & outOperand0,
                                                    GALGAS_gtlInstructionList & outOperand1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    outOperand0 = p->mObject.mProperty_condition ;
    outOperand1 = p->mObject.mProperty_instructionList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlThenElsifStatementList result = GALGAS_gtlThenElsifStatementList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlThenElsifStatementList result = GALGAS_gtlThenElsifStatementList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_gtlThenElsifStatementList result = GALGAS_gtlThenElsifStatementList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlThenElsifStatementList::plusAssign_operation (const GALGAS_gtlThenElsifStatementList inOperand,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlThenElsifStatementList::setter_setConditionAtIndex (GALGAS_gtlExpression inOperand,
                                                                   GALGAS_uint inIndex,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_condition = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlThenElsifStatementList::getter_conditionAtIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  GALGAS_gtlExpression result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    result = p->mObject.mProperty_condition ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlThenElsifStatementList::setter_setInstructionListAtIndex (GALGAS_gtlInstructionList inOperand,
                                                                         GALGAS_uint inIndex,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_instructionList = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlThenElsifStatementList::getter_instructionListAtIndex (const GALGAS_uint & inIndex,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlThenElsifStatementList * p = (cCollectionElement_gtlThenElsifStatementList *) attributes.ptr () ;
  GALGAS_gtlInstructionList result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
    result = p->mObject.mProperty_instructionList ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlThenElsifStatementList::cEnumerator_gtlThenElsifStatementList (const GALGAS_gtlThenElsifStatementList & inEnumeratedObject,
                                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList_2D_element cEnumerator_gtlThenElsifStatementList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlThenElsifStatementList * p = (const cCollectionElement_gtlThenElsifStatementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cEnumerator_gtlThenElsifStatementList::current_condition (LOCATION_ARGS) const {
  const cCollectionElement_gtlThenElsifStatementList * p = (const cCollectionElement_gtlThenElsifStatementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
  return p->mObject.mProperty_condition ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cEnumerator_gtlThenElsifStatementList::current_instructionList (LOCATION_ARGS) const {
  const cCollectionElement_gtlThenElsifStatementList * p = (const cCollectionElement_gtlThenElsifStatementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlThenElsifStatementList) ;
  return p->mObject.mProperty_instructionList ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlThenElsifStatementList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlThenElsifStatementList ("gtlThenElsifStatementList",
                                                  nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlThenElsifStatementList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlThenElsifStatementList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlThenElsifStatementList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlThenElsifStatementList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList GALGAS_gtlThenElsifStatementList::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlThenElsifStatementList result ;
  const GALGAS_gtlThenElsifStatementList * p = (const GALGAS_gtlThenElsifStatementList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlThenElsifStatementList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlThenElsifStatementList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlIfStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlIfStatementInstruction * p = (const cPtr_gtlIfStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlIfStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_thenElsifList.objectCompare (p->mProperty_thenElsifList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_elseList.objectCompare (p->mProperty_elseList) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlIfStatementInstruction::GALGAS_gtlIfStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlIfStatementInstruction GALGAS_gtlIfStatementInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlIfStatementInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                            GALGAS_string::constructor_default (HERE),
                                                            GALGAS_gtlThenElsifStatementList::constructor_emptyList (HERE),
                                                            GALGAS_gtlInstructionList::constructor_emptyList (HERE)
                                                            COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlIfStatementInstruction::GALGAS_gtlIfStatementInstruction (const cPtr_gtlIfStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlIfStatementInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList GALGAS_gtlIfStatementInstruction::readProperty_thenElsifList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlThenElsifStatementList () ;
  }else{
    const cPtr_gtlIfStatementInstruction * p = (const cPtr_gtlIfStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlIfStatementInstruction) ;
    return p->mProperty_thenElsifList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList cPtr_gtlIfStatementInstruction::getter_thenElsifList (UNUSED_LOCATION_ARGS) const {
  return mProperty_thenElsifList ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlIfStatementInstruction::readProperty_elseList (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlIfStatementInstruction * p = (const cPtr_gtlIfStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlIfStatementInstruction) ;
    return p->mProperty_elseList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlIfStatementInstruction::getter_elseList (UNUSED_LOCATION_ARGS) const {
  return mProperty_elseList ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlIfStatementInstruction::setter_setThenElsifList (GALGAS_gtlThenElsifStatementList inValue
                                                                COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlIfStatementInstruction * p = (cPtr_gtlIfStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlIfStatementInstruction) ;
    p->mProperty_thenElsifList = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlIfStatementInstruction::setter_setThenElsifList (GALGAS_gtlThenElsifStatementList inValue
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_thenElsifList = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlIfStatementInstruction::setter_setElseList (GALGAS_gtlInstructionList inValue
                                                           COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlIfStatementInstruction * p = (cPtr_gtlIfStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlIfStatementInstruction) ;
    p->mProperty_elseList = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlIfStatementInstruction::setter_setElseList (GALGAS_gtlInstructionList inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_elseList = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlIfStatementInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlIfStatementInstruction::cPtr_gtlIfStatementInstruction (const GALGAS_location & in_where,
                                                                const GALGAS_string & in_signature,
                                                                const GALGAS_gtlThenElsifStatementList & in_thenElsifList,
                                                                const GALGAS_gtlInstructionList & in_elseList
                                                                COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_thenElsifList (in_thenElsifList),
mProperty_elseList (in_elseList) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlIfStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlIfStatementInstruction ;
}

void cPtr_gtlIfStatementInstruction::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "[@gtlIfStatementInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_thenElsifList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_elseList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlIfStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlIfStatementInstruction (mProperty_where, mProperty_signature, mProperty_thenElsifList, mProperty_elseList COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlIfStatementInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlIfStatementInstruction ("gtlIfStatementInstruction",
                                                  & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlIfStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlIfStatementInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlIfStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlIfStatementInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlIfStatementInstruction GALGAS_gtlIfStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlIfStatementInstruction result ;
  const GALGAS_gtlIfStatementInstruction * p = (const GALGAS_gtlIfStatementInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlIfStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlIfStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlDisplayStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlDisplayStatementInstruction * p = (const cPtr_gtlDisplayStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlDisplayStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_variablePath.objectCompare (p->mProperty_variablePath) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlDisplayStatementInstruction::objectCompare (const GALGAS_gtlDisplayStatementInstruction & inOperand) const {
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

GALGAS_gtlDisplayStatementInstruction::GALGAS_gtlDisplayStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDisplayStatementInstruction GALGAS_gtlDisplayStatementInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlDisplayStatementInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                                 GALGAS_string::constructor_default (HERE),
                                                                 GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                                                 COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDisplayStatementInstruction::GALGAS_gtlDisplayStatementInstruction (const cPtr_gtlDisplayStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlDisplayStatementInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDisplayStatementInstruction GALGAS_gtlDisplayStatementInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                              const GALGAS_string & inAttribute_signature,
                                                                                              const GALGAS_gtlVarPath & inAttribute_variablePath
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlDisplayStatementInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_variablePath.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlDisplayStatementInstruction (inAttribute_where, inAttribute_signature, inAttribute_variablePath COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlDisplayStatementInstruction::readProperty_variablePath (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlVarPath () ;
  }else{
    const cPtr_gtlDisplayStatementInstruction * p = (const cPtr_gtlDisplayStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlDisplayStatementInstruction) ;
    return p->mProperty_variablePath ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath cPtr_gtlDisplayStatementInstruction::getter_variablePath (UNUSED_LOCATION_ARGS) const {
  return mProperty_variablePath ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDisplayStatementInstruction::setter_setVariablePath (GALGAS_gtlVarPath inValue
                                                                    COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlDisplayStatementInstruction * p = (cPtr_gtlDisplayStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlDisplayStatementInstruction) ;
    p->mProperty_variablePath = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlDisplayStatementInstruction::setter_setVariablePath (GALGAS_gtlVarPath inValue
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_variablePath = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlDisplayStatementInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlDisplayStatementInstruction::cPtr_gtlDisplayStatementInstruction (const GALGAS_location & in_where,
                                                                          const GALGAS_string & in_signature,
                                                                          const GALGAS_gtlVarPath & in_variablePath
                                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_variablePath (in_variablePath) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlDisplayStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDisplayStatementInstruction ;
}

void cPtr_gtlDisplayStatementInstruction::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "[@gtlDisplayStatementInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_variablePath.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlDisplayStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlDisplayStatementInstruction (mProperty_where, mProperty_signature, mProperty_variablePath COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlDisplayStatementInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDisplayStatementInstruction ("gtlDisplayStatementInstruction",
                                                       & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlDisplayStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDisplayStatementInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlDisplayStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDisplayStatementInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDisplayStatementInstruction GALGAS_gtlDisplayStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlDisplayStatementInstruction result ;
  const GALGAS_gtlDisplayStatementInstruction * p = (const GALGAS_gtlDisplayStatementInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlDisplayStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDisplayStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@sortingKeyList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_sortingKeyList : public cCollectionElement {
  public: GALGAS_sortingKeyList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_sortingKeyList (const GALGAS_lstring & in_key,
                                             const GALGAS_lsint & in_order
                                             COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_sortingKeyList (const GALGAS_sortingKeyList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_sortingKeyList::cCollectionElement_sortingKeyList (const GALGAS_lstring & in_key,
                                                                      const GALGAS_lsint & in_order
                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_key, in_order) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_sortingKeyList::cCollectionElement_sortingKeyList (const GALGAS_sortingKeyList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_key, inElement.mProperty_order) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_sortingKeyList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_sortingKeyList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_sortingKeyList (mObject.mProperty_key, mObject.mProperty_order COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_sortingKeyList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "key" ":" ;
  mObject.mProperty_key.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "order" ":" ;
  mObject.mProperty_order.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_sortingKeyList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_sortingKeyList * operand = (cCollectionElement_sortingKeyList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_sortingKeyList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList::GALGAS_sortingKeyList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList::GALGAS_sortingKeyList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList GALGAS_sortingKeyList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_sortingKeyList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList GALGAS_sortingKeyList::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                        const GALGAS_lsint & inOperand1
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_sortingKeyList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_sortingKeyList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_sortingKeyList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                       const GALGAS_lstring & in_key,
                                                       const GALGAS_lsint & in_order
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement_sortingKeyList * p = nullptr ;
  macroMyNew (p, cCollectionElement_sortingKeyList (in_key,
                                                    in_order COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                 const GALGAS_lsint & inOperand1
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_sortingKeyList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList::setter_append (const GALGAS_lstring inOperand0,
                                           const GALGAS_lsint inOperand1,
                                           C_Compiler * /* inCompiler */
                                           COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_sortingKeyList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                  const GALGAS_lsint inOperand1,
                                                  const GALGAS_uint inInsertionIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_sortingKeyList (inOperand0, inOperand1 COMMA_THERE)) ;
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

void GALGAS_sortingKeyList::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                  GALGAS_lsint & outOperand1,
                                                  const GALGAS_uint inRemoveIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
        outOperand0 = p->mObject.mProperty_key ;
        outOperand1 = p->mObject.mProperty_order ;
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

void GALGAS_sortingKeyList::setter_popFirst (GALGAS_lstring & outOperand0,
                                             GALGAS_lsint & outOperand1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    outOperand0 = p->mObject.mProperty_key ;
    outOperand1 = p->mObject.mProperty_order ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList::setter_popLast (GALGAS_lstring & outOperand0,
                                            GALGAS_lsint & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    outOperand0 = p->mObject.mProperty_key ;
    outOperand1 = p->mObject.mProperty_order ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList::method_first (GALGAS_lstring & outOperand0,
                                          GALGAS_lsint & outOperand1,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    outOperand0 = p->mObject.mProperty_key ;
    outOperand1 = p->mObject.mProperty_order ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList::method_last (GALGAS_lstring & outOperand0,
                                         GALGAS_lsint & outOperand1,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    outOperand0 = p->mObject.mProperty_key ;
    outOperand1 = p->mObject.mProperty_order ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList GALGAS_sortingKeyList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_sortingKeyList result = GALGAS_sortingKeyList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList GALGAS_sortingKeyList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_sortingKeyList result = GALGAS_sortingKeyList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList GALGAS_sortingKeyList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_sortingKeyList result = GALGAS_sortingKeyList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList::plusAssign_operation (const GALGAS_sortingKeyList inOperand,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList::setter_setKeyAtIndex (GALGAS_lstring inOperand,
                                                  GALGAS_uint inIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_key = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_sortingKeyList::getter_keyAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    result = p->mObject.mProperty_key ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList::setter_setOrderAtIndex (GALGAS_lsint inOperand,
                                                    GALGAS_uint inIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_order = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint GALGAS_sortingKeyList::getter_orderAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_sortingKeyList * p = (cCollectionElement_sortingKeyList *) attributes.ptr () ;
  GALGAS_lsint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
    result = p->mObject.mProperty_order ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_sortingKeyList::cEnumerator_sortingKeyList (const GALGAS_sortingKeyList & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element cEnumerator_sortingKeyList::current (LOCATION_ARGS) const {
  const cCollectionElement_sortingKeyList * p = (const cCollectionElement_sortingKeyList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_sortingKeyList::current_key (LOCATION_ARGS) const {
  const cCollectionElement_sortingKeyList * p = (const cCollectionElement_sortingKeyList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
  return p->mObject.mProperty_key ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint cEnumerator_sortingKeyList::current_order (LOCATION_ARGS) const {
  const cCollectionElement_sortingKeyList * p = (const cCollectionElement_sortingKeyList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_sortingKeyList) ;
  return p->mObject.mProperty_order ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @sortingKeyList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sortingKeyList ("sortingKeyList",
                                       nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sortingKeyList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sortingKeyList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sortingKeyList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sortingKeyList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList GALGAS_sortingKeyList::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_sortingKeyList result ;
  const GALGAS_sortingKeyList * p = (const GALGAS_sortingKeyList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_sortingKeyList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sortingKeyList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



typeComparisonResult GALGAS_gtlAbstractSortInstruction::objectCompare (const GALGAS_gtlAbstractSortInstruction & inOperand) const {
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

GALGAS_gtlAbstractSortInstruction::GALGAS_gtlAbstractSortInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAbstractSortInstruction::GALGAS_gtlAbstractSortInstruction (const cPtr_gtlAbstractSortInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlAbstractSortInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlAbstractSortInstruction::readProperty_variablePath (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlVarPath () ;
  }else{
    const cPtr_gtlAbstractSortInstruction * p = (const cPtr_gtlAbstractSortInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlAbstractSortInstruction) ;
    return p->mProperty_variablePath ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath cPtr_gtlAbstractSortInstruction::getter_variablePath (UNUSED_LOCATION_ARGS) const {
  return mProperty_variablePath ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlAbstractSortInstruction::setter_setVariablePath (GALGAS_gtlVarPath inValue
                                                                COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlAbstractSortInstruction * p = (cPtr_gtlAbstractSortInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlAbstractSortInstruction) ;
    p->mProperty_variablePath = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlAbstractSortInstruction::setter_setVariablePath (GALGAS_gtlVarPath inValue
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_variablePath = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlAbstractSortInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlAbstractSortInstruction::cPtr_gtlAbstractSortInstruction (const GALGAS_location & in_where,
                                                                  const GALGAS_string & in_signature,
                                                                  const GALGAS_gtlVarPath & in_variablePath
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_variablePath (in_variablePath) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlAbstractSortInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlAbstractSortInstruction ("gtlAbstractSortInstruction",
                                                   & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlAbstractSortInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAbstractSortInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlAbstractSortInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlAbstractSortInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAbstractSortInstruction GALGAS_gtlAbstractSortInstruction::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlAbstractSortInstruction result ;
  const GALGAS_gtlAbstractSortInstruction * p = (const GALGAS_gtlAbstractSortInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlAbstractSortInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlAbstractSortInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlAbstractSortInstruction compare'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint callExtensionGetter_compare (const cPtr_gtlAbstractSortInstruction * inObject,
                                         const GALGAS_gtlData in_s_31_,
                                         const GALGAS_gtlData in_s_32_,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_sint result ;
  if (nullptr != inObject) {
    result = inObject->getter_compare (in_s_31_, in_s_32_, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlAbstractSortInstruction swap'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlAbstractSortInstruction::method_swap (GALGAS_list & ioArgument_aList,
                                                   const GALGAS_uint constinArgument_index_31_,
                                                   const GALGAS_uint constinArgument_index_32_,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_temp_29516 = ioArgument_aList.getter_valueAtIndex (constinArgument_index_31_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 978)) ;
  {
  ioArgument_aList.setter_setValueAtIndex (ioArgument_aList.getter_valueAtIndex (constinArgument_index_32_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 979)), constinArgument_index_31_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 979)) ;
  }
  {
  ioArgument_aList.setter_setValueAtIndex (var_temp_29516, constinArgument_index_32_, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 980)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_swap (cPtr_gtlAbstractSortInstruction * inObject,
                               GALGAS_list & io_aList,
                               const GALGAS_uint constin_index_31_,
                               const GALGAS_uint constin_index_32_,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlAbstractSortInstruction) ;
    inObject->method_swap  (io_aList, constin_index_31_, constin_index_32_, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlAbstractSortInstruction partition'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlAbstractSortInstruction::method_partition (GALGAS_list & ioArgument_aList,
                                                        const GALGAS_uint constinArgument_min,
                                                        const GALGAS_uint constinArgument_max,
                                                        GALGAS_uint & ioArgument_pivotIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData var_pivot_29802 = ioArgument_aList.getter_valueAtIndex (ioArgument_pivotIndex, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 989)) ;
  const GALGAS_gtlAbstractSortInstruction temp_0 = this ;
  callExtensionMethod_swap ((cPtr_gtlAbstractSortInstruction *) temp_0.ptr (), ioArgument_aList, ioArgument_pivotIndex, constinArgument_max, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 990)) ;
  GALGAS_uint var_storeIndex_29890 = constinArgument_min ;
  GALGAS_uint var_i_29915 = constinArgument_min ;
  if (constinArgument_max.substract_operation (constinArgument_min, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 993)).isValid ()) {
    uint32_t variant_29925 = constinArgument_max.substract_operation (constinArgument_min, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 993)).uintValue () ;
    bool loop_29925 = true ;
    while (loop_29925) {
      loop_29925 = GALGAS_bool (kIsStrictInf, var_i_29915.objectCompare (constinArgument_max)).isValid () ;
      if (loop_29925) {
        loop_29925 = GALGAS_bool (kIsStrictInf, var_i_29915.objectCompare (constinArgument_max)).boolValue () ;
      }
      if (loop_29925 && (0 == variant_29925)) {
        loop_29925 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_instructions.galgas", 993)) ;
      }
      if (loop_29925) {
        variant_29925 -- ;
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          const GALGAS_gtlAbstractSortInstruction temp_2 = this ;
          test_1 = GALGAS_bool (kIsEqual, callExtensionGetter_compare ((const cPtr_gtlAbstractSortInstruction *) temp_2.ptr (), ioArgument_aList.getter_valueAtIndex (var_i_29915, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 995)), var_pivot_29802, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 995)).objectCompare (GALGAS_sint (int32_t (-1L)))).boolEnum () ;
          if (kBoolTrue == test_1) {
            const GALGAS_gtlAbstractSortInstruction temp_3 = this ;
            callExtensionMethod_swap ((cPtr_gtlAbstractSortInstruction *) temp_3.ptr (), ioArgument_aList, var_i_29915, var_storeIndex_29890, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 996)) ;
            var_storeIndex_29890.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 997)) ;
          }
        }
        var_i_29915.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 999)) ;
      }
    }
  }
  const GALGAS_gtlAbstractSortInstruction temp_4 = this ;
  callExtensionMethod_swap ((cPtr_gtlAbstractSortInstruction *) temp_4.ptr (), ioArgument_aList, var_storeIndex_29890, constinArgument_max, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1001)) ;
  ioArgument_pivotIndex = var_storeIndex_29890 ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_partition (cPtr_gtlAbstractSortInstruction * inObject,
                                    GALGAS_list & io_aList,
                                    const GALGAS_uint constin_min,
                                    const GALGAS_uint constin_max,
                                    GALGAS_uint & io_pivotIndex,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlAbstractSortInstruction) ;
    inObject->method_partition  (io_aList, constin_min, constin_max, io_pivotIndex, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlAbstractSortInstruction sort'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlAbstractSortInstruction::method_sort (GALGAS_list & ioArgument_aList,
                                                   const GALGAS_uint constinArgument_min,
                                                   const GALGAS_uint constinArgument_max,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictInf, constinArgument_min.objectCompare (constinArgument_max)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_uint var_pivotIndex_30301 = constinArgument_max.add_operation (constinArgument_min, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1011)).divide_operation (GALGAS_uint (uint32_t (2U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1011)) ;
      const GALGAS_gtlAbstractSortInstruction temp_1 = this ;
      callExtensionMethod_partition ((cPtr_gtlAbstractSortInstruction *) temp_1.ptr (), ioArgument_aList, constinArgument_min, constinArgument_max, var_pivotIndex_30301, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1012)) ;
      const GALGAS_gtlAbstractSortInstruction temp_2 = this ;
      callExtensionMethod_sort ((cPtr_gtlAbstractSortInstruction *) temp_2.ptr (), ioArgument_aList, constinArgument_min, var_pivotIndex_30301, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1013)) ;
      const GALGAS_gtlAbstractSortInstruction temp_3 = this ;
      callExtensionMethod_sort ((cPtr_gtlAbstractSortInstruction *) temp_3.ptr (), ioArgument_aList, var_pivotIndex_30301.add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1014)), constinArgument_max, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1014)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_sort (cPtr_gtlAbstractSortInstruction * inObject,
                               GALGAS_list & io_aList,
                               const GALGAS_uint constin_min,
                               const GALGAS_uint constin_max,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlAbstractSortInstruction) ;
    inObject->method_sort  (io_aList, constin_min, constin_max, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlSortStatementStructInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlSortStatementStructInstruction * p = (const cPtr_gtlSortStatementStructInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlSortStatementStructInstruction) ;
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
    result = mProperty_sortingKey.objectCompare (p->mProperty_sortingKey) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlSortStatementStructInstruction::objectCompare (const GALGAS_gtlSortStatementStructInstruction & inOperand) const {
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

GALGAS_gtlSortStatementStructInstruction::GALGAS_gtlSortStatementStructInstruction (void) :
GALGAS_gtlAbstractSortInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSortStatementStructInstruction GALGAS_gtlSortStatementStructInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlSortStatementStructInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                                    GALGAS_string::constructor_default (HERE),
                                                                    GALGAS_gtlVarPath::constructor_emptyList (HERE),
                                                                    GALGAS_sortingKeyList::constructor_emptyList (HERE)
                                                                    COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSortStatementStructInstruction::GALGAS_gtlSortStatementStructInstruction (const cPtr_gtlSortStatementStructInstruction * inSourcePtr) :
GALGAS_gtlAbstractSortInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlSortStatementStructInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSortStatementStructInstruction GALGAS_gtlSortStatementStructInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                                    const GALGAS_string & inAttribute_signature,
                                                                                                    const GALGAS_gtlVarPath & inAttribute_variablePath,
                                                                                                    const GALGAS_sortingKeyList & inAttribute_sortingKey
                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlSortStatementStructInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid () && inAttribute_variablePath.isValid () && inAttribute_sortingKey.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlSortStatementStructInstruction (inAttribute_where, inAttribute_signature, inAttribute_variablePath, inAttribute_sortingKey COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList GALGAS_gtlSortStatementStructInstruction::readProperty_sortingKey (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_sortingKeyList () ;
  }else{
    const cPtr_gtlSortStatementStructInstruction * p = (const cPtr_gtlSortStatementStructInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSortStatementStructInstruction) ;
    return p->mProperty_sortingKey ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList cPtr_gtlSortStatementStructInstruction::getter_sortingKey (UNUSED_LOCATION_ARGS) const {
  return mProperty_sortingKey ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlSortStatementStructInstruction::setter_setSortingKey (GALGAS_sortingKeyList inValue
                                                                     COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlSortStatementStructInstruction * p = (cPtr_gtlSortStatementStructInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlSortStatementStructInstruction) ;
    p->mProperty_sortingKey = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlSortStatementStructInstruction::setter_setSortingKey (GALGAS_sortingKeyList inValue
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_sortingKey = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlSortStatementStructInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlSortStatementStructInstruction::cPtr_gtlSortStatementStructInstruction (const GALGAS_location & in_where,
                                                                                const GALGAS_string & in_signature,
                                                                                const GALGAS_gtlVarPath & in_variablePath,
                                                                                const GALGAS_sortingKeyList & in_sortingKey
                                                                                COMMA_LOCATION_ARGS) :
cPtr_gtlAbstractSortInstruction (in_where, in_signature, in_variablePath COMMA_THERE),
mProperty_sortingKey (in_sortingKey) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlSortStatementStructInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSortStatementStructInstruction ;
}

void cPtr_gtlSortStatementStructInstruction::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "[@gtlSortStatementStructInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_variablePath.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_sortingKey.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlSortStatementStructInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlSortStatementStructInstruction (mProperty_where, mProperty_signature, mProperty_variablePath, mProperty_sortingKey COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlSortStatementStructInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSortStatementStructInstruction ("gtlSortStatementStructInstruction",
                                                          & kTypeDescriptor_GALGAS_gtlAbstractSortInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlSortStatementStructInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSortStatementStructInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlSortStatementStructInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSortStatementStructInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSortStatementStructInstruction GALGAS_gtlSortStatementStructInstruction::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlSortStatementStructInstruction result ;
  const GALGAS_gtlSortStatementStructInstruction * p = (const GALGAS_gtlSortStatementStructInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlSortStatementStructInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSortStatementStructInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlSortStatementStructInstruction compareElements'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint cPtr_gtlSortStatementStructInstruction::getter_compareElements (const GALGAS_gtlData constinArgument_s_31_,
                                                                            const GALGAS_gtlData constinArgument_s_32_,
                                                                            GALGAS_sortingKeyList inArgument_keyList,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, inArgument_keyList.getter_count (SOURCE_FILE ("gtl_instructions.galgas", 1063)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (constinArgument_s_31_.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct).boolEnum () ;
        if (kBoolTrue == test_1) {
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = GALGAS_bool (constinArgument_s_32_.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct).boolEnum () ;
            if (kBoolTrue == test_2) {
              GALGAS_gtlStruct temp_3 ;
              if (constinArgument_s_31_.isValid ()) {
                if (nullptr != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_s_31_.ptr ())) {
                  temp_3 = (cPtr_gtlStruct *) constinArgument_s_31_.ptr () ;
                }else{
                  inCompiler->castError ("gtlStruct", constinArgument_s_31_.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1066)) ;
                }
              }
              GALGAS_gtlStruct var_s_31_Struct_31806 = temp_3 ;
              GALGAS_gtlStruct temp_4 ;
              if (constinArgument_s_32_.isValid ()) {
                if (nullptr != dynamic_cast <const cPtr_gtlStruct *> (constinArgument_s_32_.ptr ())) {
                  temp_4 = (cPtr_gtlStruct *) constinArgument_s_32_.ptr () ;
                }else{
                  inCompiler->castError ("gtlStruct", constinArgument_s_32_.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1067)) ;
                }
              }
              GALGAS_gtlStruct var_s_32_Struct_31857 = temp_4 ;
              GALGAS_lstring var_field_31927 ;
              GALGAS_lsint var_order_31945 ;
              {
              inArgument_keyList.setter_popFirst (var_field_31927, var_order_31945, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1068)) ;
              }
              GALGAS_gtlData var_s_31_Field_32003 ;
              var_s_31_Struct_31806.readProperty_value ().method_get (var_field_31927, var_s_31_Field_32003, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1069)) ;
              GALGAS_gtlData var_s_32_Field_32063 ;
              var_s_32_Struct_31857.readProperty_value ().method_get (var_field_31927, var_s_32_Field_32063, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1070)) ;
              enumGalgasBool test_5 = kBoolTrue ;
              if (kBoolTrue == test_5) {
                test_5 = callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_ltOp ((const cPtr_gtlData *) var_s_31_Field_32003.ptr (), var_s_32_Field_32063, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1071)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1078)).boolEnum () ;
                if (kBoolTrue == test_5) {
                  result_result = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1072)).multiply_operation (var_order_31945.readProperty_sint ().getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 1072)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1072)).getter_sint (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1072)) ;
                }
              }
              if (kBoolFalse == test_5) {
                enumGalgasBool test_6 = kBoolTrue ;
                if (kBoolTrue == test_6) {
                  test_6 = callExtensionGetter_bool ((const cPtr_gtlData *) callExtensionGetter_gtOp ((const cPtr_gtlData *) var_s_31_Field_32003.ptr (), var_s_32_Field_32063, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1074)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1077)).boolEnum () ;
                  if (kBoolTrue == test_6) {
                    result_result = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1075)).multiply_operation (var_order_31945.readProperty_sint ().getter_bigint (SOURCE_FILE ("gtl_instructions.galgas", 1075)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1075)).getter_sint (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1075)) ;
                  }
                }
                if (kBoolFalse == test_6) {
                  const GALGAS_gtlSortStatementStructInstruction temp_7 = this ;
                  result_result = callExtensionGetter_compareElements ((const cPtr_gtlSortStatementStructInstruction *) temp_7.ptr (), constinArgument_s_31_, constinArgument_s_32_, inArgument_keyList, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1077)) ;
                }
              }
            }
          }
          if (kBoolFalse == test_2) {
            TC_Array <C_FixItDescription> fixItArray8 ;
            inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_s_32_.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1081)), GALGAS_string ("struct expected"), fixItArray8  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1081)) ;
            result_result.drop () ; // Release error dropped variable
          }
        }
      }
      if (kBoolFalse == test_1) {
        TC_Array <C_FixItDescription> fixItArray9 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_s_31_.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1084)), GALGAS_string ("struct expected"), fixItArray9  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1084)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_sint (int32_t (0L)) ;
  }
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint callExtensionGetter_compareElements (const cPtr_gtlSortStatementStructInstruction * inObject,
                                                 const GALGAS_gtlData in_s_31_,
                                                 const GALGAS_gtlData in_s_32_,
                                                 GALGAS_sortingKeyList in_keyList,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  GALGAS_sint result ;
  if (nullptr != inObject) {
    result = inObject->getter_compareElements (in_s_31_, in_s_32_, in_keyList, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlVariablesInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlVariablesInstruction * p = (const cPtr_gtlVariablesInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlVariablesInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_shortDisplay.objectCompare (p->mProperty_shortDisplay) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVariablesInstruction::GALGAS_gtlVariablesInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVariablesInstruction GALGAS_gtlVariablesInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlVariablesInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                          GALGAS_string::constructor_default (HERE),
                                                          GALGAS_bool::constructor_default (HERE)
                                                          COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVariablesInstruction::GALGAS_gtlVariablesInstruction (const cPtr_gtlVariablesInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlVariablesInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_gtlVariablesInstruction::readProperty_shortDisplay (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_gtlVariablesInstruction * p = (const cPtr_gtlVariablesInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVariablesInstruction) ;
    return p->mProperty_shortDisplay ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlVariablesInstruction::getter_shortDisplay (UNUSED_LOCATION_ARGS) const {
  return mProperty_shortDisplay ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVariablesInstruction::setter_setShortDisplay (GALGAS_bool inValue
                                                             COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlVariablesInstruction * p = (cPtr_gtlVariablesInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVariablesInstruction) ;
    p->mProperty_shortDisplay = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVariablesInstruction::setter_setShortDisplay (GALGAS_bool inValue
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_shortDisplay = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlVariablesInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlVariablesInstruction::cPtr_gtlVariablesInstruction (const GALGAS_location & in_where,
                                                            const GALGAS_string & in_signature,
                                                            const GALGAS_bool & in_shortDisplay
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_shortDisplay (in_shortDisplay) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlVariablesInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVariablesInstruction ;
}

void cPtr_gtlVariablesInstruction::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlVariablesInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_shortDisplay.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlVariablesInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlVariablesInstruction (mProperty_where, mProperty_signature, mProperty_shortDisplay COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlVariablesInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVariablesInstruction ("gtlVariablesInstruction",
                                                & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlVariablesInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVariablesInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlVariablesInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVariablesInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVariablesInstruction GALGAS_gtlVariablesInstruction::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlVariablesInstruction result ;
  const GALGAS_gtlVariablesInstruction * p = (const GALGAS_gtlVariablesInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlVariablesInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVariablesInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlVariablesInstruction displayShort'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVariablesInstruction::method_displayShort (const GALGAS_gtlData constinArgument_vars,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_vars.isValid ()) {
    if (constinArgument_vars.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
      GALGAS_gtlStruct cast_34336_variableMap ((cPtr_gtlStruct *) constinArgument_vars.ptr ()) ;
      cEnumerator_gtlVarMap enumerator_34363 (cast_34336_variableMap.readProperty_value (), kENUMERATION_UP) ;
      while (enumerator_34363.hasCurrentObject ()) {
        inCompiler->printMessage (enumerator_34363.current_lkey (HERE).readProperty_string ().add_operation (GALGAS_string (" >\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1158))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1158)) ;
        inCompiler->printMessage (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_34363.current_value (HERE).ptr (), GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1159))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1159)) ;
        enumerator_34363.gotoNextObject () ;
      }
    }else{
      const GALGAS_gtlVariablesInstruction temp_0 = this ;
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlVariablesInstruction *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1162)), GALGAS_string ("INTERNAL ERROR. a variable map should be a @gtlStruct"), fixItArray1  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1162)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_displayShort (cPtr_gtlVariablesInstruction * inObject,
                                       const GALGAS_gtlData constin_vars,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVariablesInstruction) ;
    inObject->method_displayShort  (constin_vars, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlVariablesInstruction displayLong'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVariablesInstruction::method_displayLong (const GALGAS_gtlData constinArgument_vars,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_delimitor_34647 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (61)), GALGAS_uint (uint32_t (79U))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1169)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1169)) ;
  GALGAS_string var_varDelim_34730 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (45)), GALGAS_uint (uint32_t (79U))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1170)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1170)) ;
  GALGAS_string var_separator_34813 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (61)), GALGAS_uint (uint32_t (17U))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1171)) ;
  inCompiler->printMessage (var_separator_34813.add_operation (GALGAS_string (" Variables "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1172)).add_operation (var_separator_34813, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1172)).add_operation (GALGAS_string ("= Displayed from "), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1173)).add_operation (var_separator_34813, inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1173)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1174))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1172)) ;
  inCompiler->printMessage (this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1175)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1175))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1175)) ;
  inCompiler->printMessage (var_delimitor_34647  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1176)) ;
  if (constinArgument_vars.isValid ()) {
    if (constinArgument_vars.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
      GALGAS_gtlStruct cast_35073_variableMap ((cPtr_gtlStruct *) constinArgument_vars.ptr ()) ;
      cEnumerator_gtlVarMap enumerator_35100 (cast_35073_variableMap.readProperty_value (), kENUMERATION_UP) ;
      while (enumerator_35100.hasCurrentObject ()) {
        inCompiler->printMessage (var_varDelim_34730  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1180)) ;
        inCompiler->printMessage (enumerator_35100.current_lkey (HERE).readProperty_string ().add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1181))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1181)) ;
        inCompiler->printMessage (var_varDelim_34730  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1182)) ;
        inCompiler->printMessage (callExtensionGetter_desc ((const cPtr_gtlData *) enumerator_35100.current_value (HERE).ptr (), GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1183))  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1183)) ;
        enumerator_35100.gotoNextObject () ;
      }
    }else{
      const GALGAS_gtlVariablesInstruction temp_0 = this ;
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlVariablesInstruction *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1186)), GALGAS_string ("INTERNAL ERROR. a variable map should be a @gtlStruct"), fixItArray1  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1186)) ;
    }
  }
  inCompiler->printMessage (var_delimitor_34647  COMMA_SOURCE_FILE ("gtl_instructions.galgas", 1188)) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_displayLong (cPtr_gtlVariablesInstruction * inObject,
                                      const GALGAS_gtlData constin_vars,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlVariablesInstruction) ;
    inObject->method_displayLong  (constin_vars, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLibrariesInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLibrariesInstruction * p = (const cPtr_gtlLibrariesInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLibrariesInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLibrariesInstruction::GALGAS_gtlLibrariesInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLibrariesInstruction GALGAS_gtlLibrariesInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLibrariesInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                          GALGAS_string::constructor_default (HERE)
                                                          COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLibrariesInstruction::GALGAS_gtlLibrariesInstruction (const cPtr_gtlLibrariesInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLibrariesInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLibrariesInstruction GALGAS_gtlLibrariesInstruction::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_string & inAttribute_signature
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlLibrariesInstruction result ;
  if (inAttribute_where.isValid () && inAttribute_signature.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLibrariesInstruction (inAttribute_where, inAttribute_signature COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlLibrariesInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlLibrariesInstruction::cPtr_gtlLibrariesInstruction (const GALGAS_location & in_where,
                                                            const GALGAS_string & in_signature
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLibrariesInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLibrariesInstruction ;
}

void cPtr_gtlLibrariesInstruction::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlLibrariesInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLibrariesInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlLibrariesInstruction (mProperty_where, mProperty_signature COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlLibrariesInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLibrariesInstruction ("gtlLibrariesInstruction",
                                                & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLibrariesInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLibrariesInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLibrariesInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLibrariesInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLibrariesInstruction GALGAS_gtlLibrariesInstruction::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLibrariesInstruction result ;
  const GALGAS_gtlLibrariesInstruction * p = (const GALGAS_gtlLibrariesInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlLibrariesInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLibrariesInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlInputStatementInstruction::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlInputStatementInstruction * p = (const cPtr_gtlInputStatementInstruction *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlInputStatementInstruction) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_signature.objectCompare (p->mProperty_signature) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_formalArguments.objectCompare (p->mProperty_formalArguments) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInputStatementInstruction::GALGAS_gtlInputStatementInstruction (void) :
GALGAS_gtlInstruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInputStatementInstruction GALGAS_gtlInputStatementInstruction::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlInputStatementInstruction::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                               GALGAS_string::constructor_default (HERE),
                                                               GALGAS_gtlArgumentList::constructor_emptyList (HERE)
                                                               COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInputStatementInstruction::GALGAS_gtlInputStatementInstruction (const cPtr_gtlInputStatementInstruction * inSourcePtr) :
GALGAS_gtlInstruction (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlInputStatementInstruction) ;
}
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList GALGAS_gtlInputStatementInstruction::readProperty_formalArguments (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_gtlArgumentList () ;
  }else{
    const cPtr_gtlInputStatementInstruction * p = (const cPtr_gtlInputStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlInputStatementInstruction) ;
    return p->mProperty_formalArguments ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList cPtr_gtlInputStatementInstruction::getter_formalArguments (UNUSED_LOCATION_ARGS) const {
  return mProperty_formalArguments ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInputStatementInstruction::setter_setFormalArguments (GALGAS_gtlArgumentList inValue
                                                                     COMMA_LOCATION_ARGS) {
  if (nullptr != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlInputStatementInstruction * p = (cPtr_gtlInputStatementInstruction *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlInputStatementInstruction) ;
    p->mProperty_formalArguments = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlInputStatementInstruction::setter_setFormalArguments (GALGAS_gtlArgumentList inValue
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_formalArguments = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlInputStatementInstruction class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlInputStatementInstruction::cPtr_gtlInputStatementInstruction (const GALGAS_location & in_where,
                                                                      const GALGAS_string & in_signature,
                                                                      const GALGAS_gtlArgumentList & in_formalArguments
                                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlInstruction (in_where, in_signature COMMA_THERE),
mProperty_formalArguments (in_formalArguments) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlInputStatementInstruction::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInputStatementInstruction ;
}

void cPtr_gtlInputStatementInstruction::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "[@gtlInputStatementInstruction:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_signature.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_formalArguments.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlInputStatementInstruction::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_gtlInputStatementInstruction (mProperty_where, mProperty_signature, mProperty_formalArguments COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlInputStatementInstruction generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInputStatementInstruction ("gtlInputStatementInstruction",
                                                     & kTypeDescriptor_GALGAS_gtlInstruction) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlInputStatementInstruction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInputStatementInstruction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlInputStatementInstruction::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInputStatementInstruction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInputStatementInstruction GALGAS_gtlInputStatementInstruction::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlInputStatementInstruction result ;
  const GALGAS_gtlInputStatementInstruction * p = (const GALGAS_gtlInputStatementInstruction *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlInputStatementInstruction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInputStatementInstruction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@string loadCommandFile'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_loadCommandFile (const GALGAS_string inObject,
                                      GALGAS_gtlContext & ioArgument_context,
                                      GALGAS_gtlData & ioArgument_vars,
                                      GALGAS_library & ioArgument_lib,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_string temp_1 = inObject ;
    test_0 = temp_1.getter_fileExists (SOURCE_FILE ("gtl_debugger.galgas", 70)).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_string temp_2 = inObject ;
      inCompiler->printMessage (GALGAS_string ("loading file ").add_operation (temp_2, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 71)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 71))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 71)) ;
      const GALGAS_string temp_3 = inObject ;
      GALGAS_stringlist var_commands_2684 = GALGAS_string::constructor_stringWithContentsOfFile (temp_3, inCompiler  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 72)).getter_componentsSeparatedByString (GALGAS_string ("\n") COMMA_SOURCE_FILE ("gtl_debugger.galgas", 73)) ;
      GALGAS_string var_whatInFile_2792 = GALGAS_string::makeEmptyString () ;
      cEnumerator_stringlist enumerator_2817 (var_commands_2684, kENUMERATION_UP) ;
      while (enumerator_2817.hasCurrentObject ()) {
        var_whatInFile_2792.plusAssign_operation(enumerator_2817.current_mValue (HERE).getter_stringByTrimmingWhiteSpaces (SOURCE_FILE ("gtl_debugger.galgas", 77)), inCompiler  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 77)) ;
        enumerator_2817.gotoNextObject () ;
      }
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsNotEqual, var_whatInFile_2792.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_4) {
          cEnumerator_stringlist enumerator_2950 (var_commands_2684, kENUMERATION_UP) ;
          while (enumerator_2950.hasCurrentObject ()) {
            enumGalgasBool test_5 = kBoolTrue ;
            if (kBoolTrue == test_5) {
              test_5 = GALGAS_bool (kIsNotEqual, enumerator_2950.current_mValue (HERE).getter_stringByTrimmingWhiteSpaces (SOURCE_FILE ("gtl_debugger.galgas", 82)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
              if (kBoolTrue == test_5) {
                GALGAS_gtlInstruction var_command_3135 ;
                var_command_3135.drop () ;
                cGrammar_gtl_5F_debugger_5F_grammar::_performSourceStringParsing_ (inCompiler, enumerator_2950.current_mValue (HERE), GALGAS_string ("Debugger command"), var_command_3135  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 83)) ;
                inCompiler->printMessage (ioArgument_context.readProperty_debuggerContext ().readProperty_instructionColor ().add_operation (ioArgument_context.readProperty_debuggerContext ().readProperty_instructionFace (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 85))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 85)) ;
                callExtensionMethod_display ((cPtr_gtlInstruction *) var_command_3135.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 87)) ;
                inCompiler->printMessage (function_endc (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 88))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 88)) ;
                inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 89)) ;
                GALGAS_string var_result_3362 = GALGAS_string::makeEmptyString () ;
                callExtensionMethod_execute ((cPtr_gtlInstruction *) var_command_3135.ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, var_result_3362, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 91)) ;
              }
            }
            enumerator_2950.gotoNextObject () ;
          }
        }
      }
      if (kBoolFalse == test_4) {
        const GALGAS_string temp_6 = inObject ;
        inCompiler->printMessage (GALGAS_string ("No command in ").add_operation (temp_6, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 95)).add_operation (GALGAS_string (" file\n"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 95))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 95)) ;
      }
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@gtlBreakpointList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_gtlBreakpointList : public cCollectionElement {
  public: GALGAS_gtlBreakpointList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_gtlBreakpointList (const GALGAS_gtlBreakpoint & in_breakpoint
                                                COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_gtlBreakpointList (const GALGAS_gtlBreakpointList_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_gtlBreakpointList::cCollectionElement_gtlBreakpointList (const GALGAS_gtlBreakpoint & in_breakpoint
                                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_breakpoint) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_gtlBreakpointList::cCollectionElement_gtlBreakpointList (const GALGAS_gtlBreakpointList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_breakpoint) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_gtlBreakpointList::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_gtlBreakpointList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_gtlBreakpointList (mObject.mProperty_breakpoint COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_gtlBreakpointList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "breakpoint" ":" ;
  mObject.mProperty_breakpoint.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_gtlBreakpointList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlBreakpointList * operand = (cCollectionElement_gtlBreakpointList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlBreakpointList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList::GALGAS_gtlBreakpointList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList::GALGAS_gtlBreakpointList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlBreakpointList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::constructor_listWithValue (const GALGAS_gtlBreakpoint & inOperand0
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlBreakpointList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_gtlBreakpointList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                          const GALGAS_gtlBreakpoint & in_breakpoint
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlBreakpointList * p = nullptr ;
  macroMyNew (p, cCollectionElement_gtlBreakpointList (in_breakpoint COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointList::addAssign_operation (const GALGAS_gtlBreakpoint & inOperand0
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlBreakpointList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointList::setter_append (const GALGAS_gtlBreakpoint inOperand0,
                                              C_Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlBreakpointList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointList::setter_insertAtIndex (const GALGAS_gtlBreakpoint inOperand0,
                                                     const GALGAS_uint inInsertionIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_gtlBreakpointList (inOperand0 COMMA_THERE)) ;
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

void GALGAS_gtlBreakpointList::setter_removeAtIndex (GALGAS_gtlBreakpoint & outOperand0,
                                                     const GALGAS_uint inRemoveIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
        outOperand0 = p->mObject.mProperty_breakpoint ;
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

void GALGAS_gtlBreakpointList::setter_popFirst (GALGAS_gtlBreakpoint & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
    outOperand0 = p->mObject.mProperty_breakpoint ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointList::setter_popLast (GALGAS_gtlBreakpoint & outOperand0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
    outOperand0 = p->mObject.mProperty_breakpoint ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointList::method_first (GALGAS_gtlBreakpoint & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
    outOperand0 = p->mObject.mProperty_breakpoint ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointList::method_last (GALGAS_gtlBreakpoint & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
    outOperand0 = p->mObject.mProperty_breakpoint ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlBreakpointList result = GALGAS_gtlBreakpointList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_gtlBreakpointList result = GALGAS_gtlBreakpointList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_gtlBreakpointList result = GALGAS_gtlBreakpointList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointList::plusAssign_operation (const GALGAS_gtlBreakpointList inOperand,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointList::setter_setBreakpointAtIndex (GALGAS_gtlBreakpoint inOperand,
                                                            GALGAS_uint inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_breakpoint = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpoint GALGAS_gtlBreakpointList::getter_breakpointAtIndex (const GALGAS_uint & inIndex,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlBreakpointList * p = (cCollectionElement_gtlBreakpointList *) attributes.ptr () ;
  GALGAS_gtlBreakpoint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
    result = p->mObject.mProperty_breakpoint ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlBreakpointList::cEnumerator_gtlBreakpointList (const GALGAS_gtlBreakpointList & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList_2D_element cEnumerator_gtlBreakpointList::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlBreakpointList * p = (const cCollectionElement_gtlBreakpointList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpoint cEnumerator_gtlBreakpointList::current_breakpoint (LOCATION_ARGS) const {
  const cCollectionElement_gtlBreakpointList * p = (const cCollectionElement_gtlBreakpointList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlBreakpointList) ;
  return p->mObject.mProperty_breakpoint ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlBreakpointList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpointList ("gtlBreakpointList",
                                          nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlBreakpointList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlBreakpointList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpointList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList GALGAS_gtlBreakpointList::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointList result ;
  const GALGAS_gtlBreakpointList * p = (const GALGAS_gtlBreakpointList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlBreakpointList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpointList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@gtlInstructionListContextStack' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_gtlInstructionListContextStack : public cCollectionElement {
  public: GALGAS_gtlInstructionListContextStack_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_gtlInstructionListContextStack (const GALGAS_uint & in_nextInstructionIndex,
                                                             const GALGAS_gtlInstructionList & in_instructionList
                                                             COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_gtlInstructionListContextStack (const GALGAS_gtlInstructionListContextStack_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_gtlInstructionListContextStack::cCollectionElement_gtlInstructionListContextStack (const GALGAS_uint & in_nextInstructionIndex,
                                                                                                      const GALGAS_gtlInstructionList & in_instructionList
                                                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_nextInstructionIndex, in_instructionList) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_gtlInstructionListContextStack::cCollectionElement_gtlInstructionListContextStack (const GALGAS_gtlInstructionListContextStack_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_nextInstructionIndex, inElement.mProperty_instructionList) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_gtlInstructionListContextStack::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_gtlInstructionListContextStack::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_gtlInstructionListContextStack (mObject.mProperty_nextInstructionIndex, mObject.mProperty_instructionList COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_gtlInstructionListContextStack::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "nextInstructionIndex" ":" ;
  mObject.mProperty_nextInstructionIndex.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "instructionList" ":" ;
  mObject.mProperty_instructionList.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_gtlInstructionListContextStack::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_gtlInstructionListContextStack * operand = (cCollectionElement_gtlInstructionListContextStack *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_gtlInstructionListContextStack) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack::GALGAS_gtlInstructionListContextStack (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack::GALGAS_gtlInstructionListContextStack (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlInstructionListContextStack  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::constructor_listWithValue (const GALGAS_uint & inOperand0,
                                                                                                        const GALGAS_gtlInstructionList & inOperand1
                                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionListContextStack result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlInstructionListContextStack (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_gtlInstructionListContextStack::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionListContextStack::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                                       const GALGAS_uint & in_nextInstructionIndex,
                                                                       const GALGAS_gtlInstructionList & in_instructionList
                                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlInstructionListContextStack * p = nullptr ;
  macroMyNew (p, cCollectionElement_gtlInstructionListContextStack (in_nextInstructionIndex,
                                                                    in_instructionList COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionListContextStack::addAssign_operation (const GALGAS_uint & inOperand0,
                                                                 const GALGAS_gtlInstructionList & inOperand1
                                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlInstructionListContextStack (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionListContextStack::setter_append (const GALGAS_uint inOperand0,
                                                           const GALGAS_gtlInstructionList inOperand1,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_gtlInstructionListContextStack (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionListContextStack::setter_insertAtIndex (const GALGAS_uint inOperand0,
                                                                  const GALGAS_gtlInstructionList inOperand1,
                                                                  const GALGAS_uint inInsertionIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_gtlInstructionListContextStack (inOperand0, inOperand1 COMMA_THERE)) ;
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

void GALGAS_gtlInstructionListContextStack::setter_removeAtIndex (GALGAS_uint & outOperand0,
                                                                  GALGAS_gtlInstructionList & outOperand1,
                                                                  const GALGAS_uint inRemoveIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
        outOperand0 = p->mObject.mProperty_nextInstructionIndex ;
        outOperand1 = p->mObject.mProperty_instructionList ;
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

void GALGAS_gtlInstructionListContextStack::setter_popFirst (GALGAS_uint & outOperand0,
                                                             GALGAS_gtlInstructionList & outOperand1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    outOperand0 = p->mObject.mProperty_nextInstructionIndex ;
    outOperand1 = p->mObject.mProperty_instructionList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionListContextStack::setter_popLast (GALGAS_uint & outOperand0,
                                                            GALGAS_gtlInstructionList & outOperand1,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    outOperand0 = p->mObject.mProperty_nextInstructionIndex ;
    outOperand1 = p->mObject.mProperty_instructionList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionListContextStack::method_first (GALGAS_uint & outOperand0,
                                                          GALGAS_gtlInstructionList & outOperand1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    outOperand0 = p->mObject.mProperty_nextInstructionIndex ;
    outOperand1 = p->mObject.mProperty_instructionList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionListContextStack::method_last (GALGAS_uint & outOperand0,
                                                         GALGAS_gtlInstructionList & outOperand1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    outOperand0 = p->mObject.mProperty_nextInstructionIndex ;
    outOperand1 = p->mObject.mProperty_instructionList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                                      C_Compiler * inCompiler
                                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionListContextStack result = GALGAS_gtlInstructionListContextStack::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                                      C_Compiler * inCompiler
                                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionListContextStack result = GALGAS_gtlInstructionListContextStack::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_gtlInstructionListContextStack result = GALGAS_gtlInstructionListContextStack::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionListContextStack::plusAssign_operation (const GALGAS_gtlInstructionListContextStack inOperand,
                                                                  C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionListContextStack::setter_setNextInstructionIndexAtIndex (GALGAS_uint inOperand,
                                                                                   GALGAS_uint inIndex,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_nextInstructionIndex = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_gtlInstructionListContextStack::getter_nextInstructionIndexAtIndex (const GALGAS_uint & inIndex,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
  GALGAS_uint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    result = p->mObject.mProperty_nextInstructionIndex ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionListContextStack::setter_setInstructionListAtIndex (GALGAS_gtlInstructionList inOperand,
                                                                              GALGAS_uint inIndex,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_instructionList = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlInstructionListContextStack::getter_instructionListAtIndex (const GALGAS_uint & inIndex,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_gtlInstructionListContextStack * p = (cCollectionElement_gtlInstructionListContextStack *) attributes.ptr () ;
  GALGAS_gtlInstructionList result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
    result = p->mObject.mProperty_instructionList ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_gtlInstructionListContextStack::cEnumerator_gtlInstructionListContextStack (const GALGAS_gtlInstructionListContextStack & inEnumeratedObject,
                                                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack_2D_element cEnumerator_gtlInstructionListContextStack::current (LOCATION_ARGS) const {
  const cCollectionElement_gtlInstructionListContextStack * p = (const cCollectionElement_gtlInstructionListContextStack *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_gtlInstructionListContextStack::current_nextInstructionIndex (LOCATION_ARGS) const {
  const cCollectionElement_gtlInstructionListContextStack * p = (const cCollectionElement_gtlInstructionListContextStack *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
  return p->mObject.mProperty_nextInstructionIndex ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cEnumerator_gtlInstructionListContextStack::current_instructionList (LOCATION_ARGS) const {
  const cCollectionElement_gtlInstructionListContextStack * p = (const cCollectionElement_gtlInstructionListContextStack *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_gtlInstructionListContextStack) ;
  return p->mObject.mProperty_instructionList ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlInstructionListContextStack generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInstructionListContextStack ("gtlInstructionListContextStack",
                                                       nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlInstructionListContextStack::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInstructionListContextStack ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlInstructionListContextStack::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInstructionListContextStack (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack GALGAS_gtlInstructionListContextStack::extractObject (const GALGAS_object & inObject,
                                                                                            C_Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionListContextStack result ;
  const GALGAS_gtlInstructionListContextStack * p = (const GALGAS_gtlInstructionListContextStack *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlInstructionListContextStack *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInstructionListContextStack", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}


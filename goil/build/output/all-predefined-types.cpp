//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"
#include "galgas2/cCollectionElement.h"
#include "galgas2/cSortedListElement.h"
#include "galgas2/capSortedListElement.h"
#include "galgas2/C_Compiler.h"

//----------------------------------------------------------------------------------------------------------------------

cMapElement::cMapElement (const GALGAS_lstring & inLKey
                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mProperty_lkey (inLKey) {
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @string generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_string ("string",
                               nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_string::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_string ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_string::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_string (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_string::extractObject (const GALGAS_object & inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  const GALGAS_string * p = (const GALGAS_string *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_string *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("string", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @stringlist generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringlist ("stringlist",
                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_stringlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringlist ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_stringlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringlist (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_stringlist::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_stringlist result ;
  const GALGAS_stringlist * p = (const GALGAS_stringlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_stringlist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringlist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@stringlist' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_stringlist : public cCollectionElement {
  public: GALGAS_stringlist_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_stringlist (const GALGAS_string & in_mValue
                                         COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_stringlist (const GALGAS_stringlist_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_stringlist::cCollectionElement_stringlist (const GALGAS_string & in_mValue
                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_stringlist::cCollectionElement_stringlist (const GALGAS_stringlist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_stringlist::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_stringlist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_stringlist (mObject.mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_stringlist::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue" ":" ;
  mObject.mProperty_mValue.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_stringlist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_stringlist * operand = (cCollectionElement_stringlist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_stringlist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist::GALGAS_stringlist (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist::GALGAS_stringlist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_stringlist::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_stringlist  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_stringlist::constructor_listWithValue (const GALGAS_string & inOperand0
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_stringlist result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_stringlist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_stringlist::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                   const GALGAS_string & in_mValue
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_stringlist * p = nullptr ;
  macroMyNew (p, cCollectionElement_stringlist (in_mValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringlist::addAssign_operation (const GALGAS_string & inOperand0
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_stringlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringlist::setter_append (const GALGAS_string inOperand0,
                                       C_Compiler * /* inCompiler */
                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_stringlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringlist::setter_insertAtIndex (const GALGAS_string inOperand0,
                                              const GALGAS_uint inInsertionIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_stringlist (inOperand0 COMMA_THERE)) ;
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

void GALGAS_stringlist::setter_removeAtIndex (GALGAS_string & outOperand0,
                                              const GALGAS_uint inRemoveIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_stringlist * p = (cCollectionElement_stringlist *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_stringlist) ;
        outOperand0 = p->mObject.mProperty_mValue ;
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

void GALGAS_stringlist::setter_popFirst (GALGAS_string & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_stringlist * p = (cCollectionElement_stringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_stringlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringlist::setter_popLast (GALGAS_string & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_stringlist * p = (cCollectionElement_stringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_stringlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringlist::method_first (GALGAS_string & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_stringlist * p = (cCollectionElement_stringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_stringlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringlist::method_last (GALGAS_string & outOperand0,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_stringlist * p = (cCollectionElement_stringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_stringlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_stringlist::add_operation (const GALGAS_stringlist & inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_stringlist::getter_subListWithRange (const GALGAS_range & inRange,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_stringlist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_stringlist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringlist::plusAssign_operation (const GALGAS_stringlist inOperand,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringlist::setter_setMValueAtIndex (GALGAS_string inOperand,
                                                 GALGAS_uint inIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement_stringlist * p = (cCollectionElement_stringlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_stringlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_stringlist::getter_mValueAtIndex (const GALGAS_uint & inIndex,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_stringlist * p = (cCollectionElement_stringlist *) attributes.ptr () ;
  GALGAS_string result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_stringlist) ;
    result = p->mObject.mProperty_mValue ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_stringlist::cEnumerator_stringlist (const GALGAS_stringlist & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist_2D_element cEnumerator_stringlist::current (LOCATION_ARGS) const {
  const cCollectionElement_stringlist * p = (const cCollectionElement_stringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_stringlist) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cEnumerator_stringlist::current_mValue (LOCATION_ARGS) const {
  const cCollectionElement_stringlist * p = (const cCollectionElement_stringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_stringlist) ;
  return p->mObject.mProperty_mValue ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @bool generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_bool ("bool",
                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_bool::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bool ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_bool::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_bool (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_bool::extractObject (const GALGAS_object & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  const GALGAS_bool * p = (const GALGAS_bool *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_bool *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("bool", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @stringset generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringset ("stringset",
                                  nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_stringset::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringset ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_stringset::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringset (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset GALGAS_stringset::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_stringset result ;
  const GALGAS_stringset * p = (const GALGAS_stringset *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_stringset *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringset", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @location generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_location ("location",
                                 nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_location::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_location ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_location::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_location (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_location::extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_location result ;
  const GALGAS_location * p = (const GALGAS_location *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_location *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("location", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @type generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_type ("type",
                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_type::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_type ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_type::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_type (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_type GALGAS_type::extractObject (const GALGAS_object & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_type result ;
  const GALGAS_type * p = (const GALGAS_type *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_type *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("type", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @char generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_char ("char",
                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_char::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_char ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_char::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_char (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_char GALGAS_char::extractObject (const GALGAS_object & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_char result ;
  const GALGAS_char * p = (const GALGAS_char *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_char *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("char", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @bigint generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_bigint ("bigint",
                               nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_bigint::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bigint ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_bigint::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_bigint (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint GALGAS_bigint::extractObject (const GALGAS_object & inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_bigint result ;
  const GALGAS_bigint * p = (const GALGAS_bigint *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_bigint *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("bigint", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @double generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_double ("double",
                               nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_double::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_double ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_double::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_double (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_double::extractObject (const GALGAS_object & inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_double result ;
  const GALGAS_double * p = (const GALGAS_double *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_double *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("double", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @sint64 generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_ ("sint64",
                                     nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_36__34_::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_ ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_36__34_::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_ (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_ result ;
  const GALGAS_sint_36__34_ * p = (const GALGAS_sint_36__34_ *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_sint_36__34_ *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @uint generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint ("uint",
                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_uint::extractObject (const GALGAS_object & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_uint result ;
  const GALGAS_uint * p = (const GALGAS_uint *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uint *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @lbigint generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lbigint ("lbigint",
                                nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lbigint::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lbigint ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lbigint::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lbigint (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint GALGAS_lbigint::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_lbigint result ;
  const GALGAS_lbigint * p = (const GALGAS_lbigint *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lbigint *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lbigint", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint::GALGAS_lbigint (void) :
mProperty_bigint (),
mProperty_location () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint::~ GALGAS_lbigint (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint::GALGAS_lbigint (const GALGAS_bigint & inOperand0,
                                const GALGAS_location & inOperand1) :
mProperty_bigint (inOperand0),
mProperty_location (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint GALGAS_lbigint::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lbigint (GALGAS_bigint::constructor_zero (HERE),
                         GALGAS_location::constructor_nowhere (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint GALGAS_lbigint::constructor_new (const GALGAS_bigint & in_bigint,
                                                const GALGAS_location & in_location 
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lbigint result ;
  if (in_bigint.isValid () && in_location.isValid ()) {
    result = GALGAS_lbigint (in_bigint, in_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_lbigint::objectCompare (const GALGAS_lbigint & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_bigint.objectCompare (inOperand.mProperty_bigint) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lbigint::isValid (void) const {
  return mProperty_bigint.isValid () && mProperty_location.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigint::drop (void) {
  mProperty_bigint.drop () ;
  mProperty_location.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigint::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "<struct @lbigint:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_bigint.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_location.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @uint64 generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_ ("uint64",
                                     nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_36__34_::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_ ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_36__34_::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_ (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_uint_36__34_::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_ result ;
  const GALGAS_uint_36__34_ * p = (const GALGAS_uint_36__34_ *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uint_36__34_ *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @sint generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint ("sint",
                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint::extractObject (const GALGAS_object & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_sint result ;
  const GALGAS_sint * p = (const GALGAS_sint *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_sint *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @lstringlist generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstringlist ("lstringlist",
                                    nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lstringlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstringlist ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lstringlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lstringlist (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist GALGAS_lstringlist::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_lstringlist result ;
  const GALGAS_lstringlist * p = (const GALGAS_lstringlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lstringlist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lstringlist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@lstringlist' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_lstringlist : public cCollectionElement {
  public: GALGAS_lstringlist_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_lstringlist (const GALGAS_lstring & in_mValue
                                          COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_lstringlist (const GALGAS_lstringlist_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_lstringlist::cCollectionElement_lstringlist (const GALGAS_lstring & in_mValue
                                                                COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_lstringlist::cCollectionElement_lstringlist (const GALGAS_lstringlist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_lstringlist::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_lstringlist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_lstringlist (mObject.mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_lstringlist::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue" ":" ;
  mObject.mProperty_mValue.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_lstringlist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_lstringlist * operand = (cCollectionElement_lstringlist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_lstringlist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist::GALGAS_lstringlist (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist::GALGAS_lstringlist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist GALGAS_lstringlist::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_lstringlist  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist GALGAS_lstringlist::constructor_listWithValue (const GALGAS_lstring & inOperand0
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_lstringlist result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_lstringlist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_lstringlist::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                    const GALGAS_lstring & in_mValue
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_lstringlist * p = nullptr ;
  macroMyNew (p, cCollectionElement_lstringlist (in_mValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringlist::addAssign_operation (const GALGAS_lstring & inOperand0
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_lstringlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringlist::setter_append (const GALGAS_lstring inOperand0,
                                        C_Compiler * /* inCompiler */
                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_lstringlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringlist::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                               const GALGAS_uint inInsertionIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_lstringlist (inOperand0 COMMA_THERE)) ;
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

void GALGAS_lstringlist::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                               const GALGAS_uint inRemoveIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_lstringlist * p = (cCollectionElement_lstringlist *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_lstringlist) ;
        outOperand0 = p->mObject.mProperty_mValue ;
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

void GALGAS_lstringlist::setter_popFirst (GALGAS_lstring & outOperand0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_lstringlist * p = (cCollectionElement_lstringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_lstringlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringlist::setter_popLast (GALGAS_lstring & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_lstringlist * p = (cCollectionElement_lstringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_lstringlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringlist::method_first (GALGAS_lstring & outOperand0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_lstringlist * p = (cCollectionElement_lstringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_lstringlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringlist::method_last (GALGAS_lstring & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_lstringlist * p = (cCollectionElement_lstringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_lstringlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist GALGAS_lstringlist::add_operation (const GALGAS_lstringlist & inOperand,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist GALGAS_lstringlist::getter_subListWithRange (const GALGAS_range & inRange,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_lstringlist result = GALGAS_lstringlist::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist GALGAS_lstringlist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_lstringlist result = GALGAS_lstringlist::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist GALGAS_lstringlist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_lstringlist result = GALGAS_lstringlist::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringlist::plusAssign_operation (const GALGAS_lstringlist inOperand,
                                               C_Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringlist::setter_setMValueAtIndex (GALGAS_lstring inOperand,
                                                  GALGAS_uint inIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_lstringlist * p = (cCollectionElement_lstringlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_lstringlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_lstringlist::getter_mValueAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_lstringlist * p = (cCollectionElement_lstringlist *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_lstringlist) ;
    result = p->mObject.mProperty_mValue ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_lstringlist::cEnumerator_lstringlist (const GALGAS_lstringlist & inEnumeratedObject,
                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist_2D_element cEnumerator_lstringlist::current (LOCATION_ARGS) const {
  const cCollectionElement_lstringlist * p = (const cCollectionElement_lstringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_lstringlist) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_lstringlist::current_mValue (LOCATION_ARGS) const {
  const cCollectionElement_lstringlist * p = (const cCollectionElement_lstringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_lstringlist) ;
  return p->mObject.mProperty_mValue ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @lbool generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lbool ("lbool",
                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lbool::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lbool ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lbool::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lbool (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbool GALGAS_lbool::extractObject (const GALGAS_object & inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_lbool result ;
  const GALGAS_lbool * p = (const GALGAS_lbool *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lbool *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lbool", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbool::GALGAS_lbool (void) :
mProperty_bool (),
mProperty_location () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbool::~ GALGAS_lbool (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbool::GALGAS_lbool (const GALGAS_bool & inOperand0,
                            const GALGAS_location & inOperand1) :
mProperty_bool (inOperand0),
mProperty_location (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbool GALGAS_lbool::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lbool (GALGAS_bool::constructor_default (HERE),
                       GALGAS_location::constructor_nowhere (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbool GALGAS_lbool::constructor_new (const GALGAS_bool & in_bool,
                                            const GALGAS_location & in_location 
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lbool result ;
  if (in_bool.isValid () && in_location.isValid ()) {
    result = GALGAS_lbool (in_bool, in_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_lbool::objectCompare (const GALGAS_lbool & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_bool.objectCompare (inOperand.mProperty_bool) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lbool::isValid (void) const {
  return mProperty_bool.isValid () && mProperty_location.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbool::drop (void) {
  mProperty_bool.drop () ;
  mProperty_location.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbool::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "<struct @lbool:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_bool.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_location.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @application generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_application ("application",
                                    nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_application::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_application ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_application::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_application (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_application GALGAS_application::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_application result ;
  const GALGAS_application * p = (const GALGAS_application *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_application *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("application", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @binaryset generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_binaryset ("binaryset",
                                  nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_binaryset::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_binaryset ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_binaryset::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_binaryset (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_binaryset GALGAS_binaryset::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_binaryset result ;
  const GALGAS_binaryset * p = (const GALGAS_binaryset *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_binaryset *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("binaryset", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @data generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_data ("data",
                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_data::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_data ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_data::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_data (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_data GALGAS_data::extractObject (const GALGAS_object & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_data result ;
  const GALGAS_data * p = (const GALGAS_data *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_data *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("data", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @filewrapper generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_filewrapper ("filewrapper",
                                    nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_filewrapper::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_filewrapper ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_filewrapper::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_filewrapper (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_filewrapper GALGAS_filewrapper::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_filewrapper result ;
  const GALGAS_filewrapper * p = (const GALGAS_filewrapper *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_filewrapper *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("filewrapper", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @function generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_function ("function",
                                 nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_function::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_function ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_function::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_function (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_function GALGAS_function::extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_function result ;
  const GALGAS_function * p = (const GALGAS_function *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_function *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("function", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @object generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_object ("object",
                               nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_object::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_object ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_object::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_object (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_object GALGAS_object::extractObject (const GALGAS_object & inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_object result ;
  const GALGAS_object * p = (const GALGAS_object *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_object *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("object", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @timer generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_timer ("timer",
                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_timer::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_timer ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_timer::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_timer (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_timer GALGAS_timer::extractObject (const GALGAS_object & inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_timer result ;
  const GALGAS_timer * p = (const GALGAS_timer *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_timer *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("timer", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @functionlist generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_functionlist ("functionlist",
                                     nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_functionlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_functionlist ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_functionlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_functionlist (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist GALGAS_functionlist::extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_functionlist result ;
  const GALGAS_functionlist * p = (const GALGAS_functionlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_functionlist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("functionlist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@functionlist' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_functionlist : public cCollectionElement {
  public: GALGAS_functionlist_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_functionlist (const GALGAS_function & in_mValue
                                           COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_functionlist (const GALGAS_functionlist_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_functionlist::cCollectionElement_functionlist (const GALGAS_function & in_mValue
                                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_functionlist::cCollectionElement_functionlist (const GALGAS_functionlist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_functionlist::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_functionlist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_functionlist (mObject.mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_functionlist::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue" ":" ;
  mObject.mProperty_mValue.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_functionlist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_functionlist * operand = (cCollectionElement_functionlist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_functionlist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist::GALGAS_functionlist (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist::GALGAS_functionlist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist GALGAS_functionlist::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_functionlist  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist GALGAS_functionlist::constructor_listWithValue (const GALGAS_function & inOperand0
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_functionlist result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_functionlist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_functionlist::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_functionlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                     const GALGAS_function & in_mValue
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement_functionlist * p = nullptr ;
  macroMyNew (p, cCollectionElement_functionlist (in_mValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_functionlist::addAssign_operation (const GALGAS_function & inOperand0
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_functionlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_functionlist::setter_append (const GALGAS_function inOperand0,
                                         C_Compiler * /* inCompiler */
                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_functionlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_functionlist::setter_insertAtIndex (const GALGAS_function inOperand0,
                                                const GALGAS_uint inInsertionIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_functionlist (inOperand0 COMMA_THERE)) ;
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

void GALGAS_functionlist::setter_removeAtIndex (GALGAS_function & outOperand0,
                                                const GALGAS_uint inRemoveIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_functionlist * p = (cCollectionElement_functionlist *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_functionlist) ;
        outOperand0 = p->mObject.mProperty_mValue ;
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

void GALGAS_functionlist::setter_popFirst (GALGAS_function & outOperand0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_functionlist * p = (cCollectionElement_functionlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_functionlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_functionlist::setter_popLast (GALGAS_function & outOperand0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_functionlist * p = (cCollectionElement_functionlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_functionlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_functionlist::method_first (GALGAS_function & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_functionlist * p = (cCollectionElement_functionlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_functionlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_functionlist::method_last (GALGAS_function & outOperand0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_functionlist * p = (cCollectionElement_functionlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_functionlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist GALGAS_functionlist::add_operation (const GALGAS_functionlist & inOperand,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_functionlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist GALGAS_functionlist::getter_subListWithRange (const GALGAS_range & inRange,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_functionlist result = GALGAS_functionlist::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist GALGAS_functionlist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_functionlist result = GALGAS_functionlist::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist GALGAS_functionlist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_functionlist result = GALGAS_functionlist::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_functionlist::plusAssign_operation (const GALGAS_functionlist inOperand,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_functionlist::setter_setMValueAtIndex (GALGAS_function inOperand,
                                                   GALGAS_uint inIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_functionlist * p = (cCollectionElement_functionlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_functionlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_function GALGAS_functionlist::getter_mValueAtIndex (const GALGAS_uint & inIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_functionlist * p = (cCollectionElement_functionlist *) attributes.ptr () ;
  GALGAS_function result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_functionlist) ;
    result = p->mObject.mProperty_mValue ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_functionlist::cEnumerator_functionlist (const GALGAS_functionlist & inEnumeratedObject,
                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist_2D_element cEnumerator_functionlist::current (LOCATION_ARGS) const {
  const cCollectionElement_functionlist * p = (const cCollectionElement_functionlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionlist) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_function cEnumerator_functionlist::current_mValue (LOCATION_ARGS) const {
  const cCollectionElement_functionlist * p = (const cCollectionElement_functionlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_functionlist) ;
  return p->mObject.mProperty_mValue ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @luintlist generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_luintlist ("luintlist",
                                  nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_luintlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_luintlist ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_luintlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_luintlist (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist GALGAS_luintlist::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_luintlist result ;
  const GALGAS_luintlist * p = (const GALGAS_luintlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_luintlist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("luintlist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@luintlist' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_luintlist : public cCollectionElement {
  public: GALGAS_luintlist_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_luintlist (const GALGAS_luint & in_mValue
                                        COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_luintlist (const GALGAS_luintlist_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_luintlist::cCollectionElement_luintlist (const GALGAS_luint & in_mValue
                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_luintlist::cCollectionElement_luintlist (const GALGAS_luintlist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_luintlist::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_luintlist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_luintlist (mObject.mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_luintlist::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue" ":" ;
  mObject.mProperty_mValue.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_luintlist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_luintlist * operand = (cCollectionElement_luintlist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_luintlist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist::GALGAS_luintlist (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist::GALGAS_luintlist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist GALGAS_luintlist::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_luintlist  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist GALGAS_luintlist::constructor_listWithValue (const GALGAS_luint & inOperand0
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_luintlist result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_luintlist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_luintlist::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luintlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const GALGAS_luint & in_mValue
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_luintlist * p = nullptr ;
  macroMyNew (p, cCollectionElement_luintlist (in_mValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luintlist::addAssign_operation (const GALGAS_luint & inOperand0
                                            COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_luintlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luintlist::setter_append (const GALGAS_luint inOperand0,
                                      C_Compiler * /* inCompiler */
                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_luintlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luintlist::setter_insertAtIndex (const GALGAS_luint inOperand0,
                                             const GALGAS_uint inInsertionIndex,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_luintlist (inOperand0 COMMA_THERE)) ;
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

void GALGAS_luintlist::setter_removeAtIndex (GALGAS_luint & outOperand0,
                                             const GALGAS_uint inRemoveIndex,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_luintlist * p = (cCollectionElement_luintlist *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_luintlist) ;
        outOperand0 = p->mObject.mProperty_mValue ;
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

void GALGAS_luintlist::setter_popFirst (GALGAS_luint & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_luintlist * p = (cCollectionElement_luintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_luintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luintlist::setter_popLast (GALGAS_luint & outOperand0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_luintlist * p = (cCollectionElement_luintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_luintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luintlist::method_first (GALGAS_luint & outOperand0,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_luintlist * p = (cCollectionElement_luintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_luintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luintlist::method_last (GALGAS_luint & outOperand0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_luintlist * p = (cCollectionElement_luintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_luintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist GALGAS_luintlist::add_operation (const GALGAS_luintlist & inOperand,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_luintlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist GALGAS_luintlist::getter_subListWithRange (const GALGAS_range & inRange,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_luintlist result = GALGAS_luintlist::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist GALGAS_luintlist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_luintlist result = GALGAS_luintlist::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist GALGAS_luintlist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_luintlist result = GALGAS_luintlist::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luintlist::plusAssign_operation (const GALGAS_luintlist inOperand,
                                             C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luintlist::setter_setMValueAtIndex (GALGAS_luint inOperand,
                                                GALGAS_uint inIndex,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cCollectionElement_luintlist * p = (cCollectionElement_luintlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_luintlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_luintlist::getter_mValueAtIndex (const GALGAS_uint & inIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_luintlist * p = (cCollectionElement_luintlist *) attributes.ptr () ;
  GALGAS_luint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_luintlist) ;
    result = p->mObject.mProperty_mValue ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_luintlist::cEnumerator_luintlist (const GALGAS_luintlist & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist_2D_element cEnumerator_luintlist::current (LOCATION_ARGS) const {
  const cCollectionElement_luintlist * p = (const cCollectionElement_luintlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_luintlist) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint cEnumerator_luintlist::current_mValue (LOCATION_ARGS) const {
  const cCollectionElement_luintlist * p = (const cCollectionElement_luintlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_luintlist) ;
  return p->mObject.mProperty_mValue ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @luint generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_luint ("luint",
                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_luint::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_luint ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_luint::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_luint (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_luint::extractObject (const GALGAS_object & inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_luint result ;
  const GALGAS_luint * p = (const GALGAS_luint *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_luint *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("luint", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint::GALGAS_luint (void) :
mProperty_uint (),
mProperty_location () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint::~ GALGAS_luint (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint::GALGAS_luint (const GALGAS_uint & inOperand0,
                            const GALGAS_location & inOperand1) :
mProperty_uint (inOperand0),
mProperty_location (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_luint::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_luint (GALGAS_uint::constructor_default (HERE),
                       GALGAS_location::constructor_nowhere (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_luint::constructor_new (const GALGAS_uint & in_uint,
                                            const GALGAS_location & in_location 
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint result ;
  if (in_uint.isValid () && in_location.isValid ()) {
    result = GALGAS_luint (in_uint, in_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_luint::objectCompare (const GALGAS_luint & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_uint.objectCompare (inOperand.mProperty_uint) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_luint::isValid (void) const {
  return mProperty_uint.isValid () && mProperty_location.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luint::drop (void) {
  mProperty_uint.drop () ;
  mProperty_location.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luint::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "<struct @luint:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_uint.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_location.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @objectlist generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectlist ("objectlist",
                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_objectlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectlist ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_objectlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectlist (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist GALGAS_objectlist::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_objectlist result ;
  const GALGAS_objectlist * p = (const GALGAS_objectlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_objectlist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectlist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@objectlist' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_objectlist : public cCollectionElement {
  public: GALGAS_objectlist_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_objectlist (const GALGAS_object & in_mValue
                                         COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_objectlist (const GALGAS_objectlist_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_objectlist::cCollectionElement_objectlist (const GALGAS_object & in_mValue
                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_objectlist::cCollectionElement_objectlist (const GALGAS_objectlist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_objectlist::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_objectlist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_objectlist (mObject.mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_objectlist::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue" ":" ;
  mObject.mProperty_mValue.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_objectlist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_objectlist * operand = (cCollectionElement_objectlist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_objectlist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist::GALGAS_objectlist (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist::GALGAS_objectlist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist GALGAS_objectlist::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_objectlist  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist GALGAS_objectlist::constructor_listWithValue (const GALGAS_object & inOperand0
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_objectlist result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_objectlist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_objectlist::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                   const GALGAS_object & in_mValue
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_objectlist * p = nullptr ;
  macroMyNew (p, cCollectionElement_objectlist (in_mValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectlist::addAssign_operation (const GALGAS_object & inOperand0
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_objectlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectlist::setter_append (const GALGAS_object inOperand0,
                                       C_Compiler * /* inCompiler */
                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_objectlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectlist::setter_insertAtIndex (const GALGAS_object inOperand0,
                                              const GALGAS_uint inInsertionIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_objectlist (inOperand0 COMMA_THERE)) ;
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

void GALGAS_objectlist::setter_removeAtIndex (GALGAS_object & outOperand0,
                                              const GALGAS_uint inRemoveIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_objectlist * p = (cCollectionElement_objectlist *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_objectlist) ;
        outOperand0 = p->mObject.mProperty_mValue ;
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

void GALGAS_objectlist::setter_popFirst (GALGAS_object & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_objectlist * p = (cCollectionElement_objectlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_objectlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectlist::setter_popLast (GALGAS_object & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_objectlist * p = (cCollectionElement_objectlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_objectlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectlist::method_first (GALGAS_object & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_objectlist * p = (cCollectionElement_objectlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_objectlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectlist::method_last (GALGAS_object & outOperand0,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_objectlist * p = (cCollectionElement_objectlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_objectlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist GALGAS_objectlist::add_operation (const GALGAS_objectlist & inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_objectlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist GALGAS_objectlist::getter_subListWithRange (const GALGAS_range & inRange,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_objectlist result = GALGAS_objectlist::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist GALGAS_objectlist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_objectlist result = GALGAS_objectlist::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist GALGAS_objectlist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_objectlist result = GALGAS_objectlist::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectlist::plusAssign_operation (const GALGAS_objectlist inOperand,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectlist::setter_setMValueAtIndex (GALGAS_object inOperand,
                                                 GALGAS_uint inIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement_objectlist * p = (cCollectionElement_objectlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_objectlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_object GALGAS_objectlist::getter_mValueAtIndex (const GALGAS_uint & inIndex,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_objectlist * p = (cCollectionElement_objectlist *) attributes.ptr () ;
  GALGAS_object result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_objectlist) ;
    result = p->mObject.mProperty_mValue ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_objectlist::cEnumerator_objectlist (const GALGAS_objectlist & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist_2D_element cEnumerator_objectlist::current (LOCATION_ARGS) const {
  const cCollectionElement_objectlist * p = (const cCollectionElement_objectlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_objectlist) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_object cEnumerator_objectlist::current_mValue (LOCATION_ARGS) const {
  const cCollectionElement_objectlist * p = (const cCollectionElement_objectlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_objectlist) ;
  return p->mObject.mProperty_mValue ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @typelist generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typelist ("typelist",
                                 nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typelist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typelist ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typelist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typelist (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist GALGAS_typelist::extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_typelist result ;
  const GALGAS_typelist * p = (const GALGAS_typelist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typelist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typelist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@typelist' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_typelist : public cCollectionElement {
  public: GALGAS_typelist_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_typelist (const GALGAS_type & in_mValue
                                       COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_typelist (const GALGAS_typelist_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_typelist::cCollectionElement_typelist (const GALGAS_type & in_mValue
                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_typelist::cCollectionElement_typelist (const GALGAS_typelist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_typelist::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_typelist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_typelist (mObject.mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_typelist::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue" ":" ;
  mObject.mProperty_mValue.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_typelist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_typelist * operand = (cCollectionElement_typelist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_typelist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist::GALGAS_typelist (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist::GALGAS_typelist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist GALGAS_typelist::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_typelist  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist GALGAS_typelist::constructor_listWithValue (const GALGAS_type & inOperand0
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_typelist result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_typelist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_typelist::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typelist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const GALGAS_type & in_mValue
                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement_typelist * p = nullptr ;
  macroMyNew (p, cCollectionElement_typelist (in_mValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typelist::addAssign_operation (const GALGAS_type & inOperand0
                                           COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_typelist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typelist::setter_append (const GALGAS_type inOperand0,
                                     C_Compiler * /* inCompiler */
                                     COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_typelist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typelist::setter_insertAtIndex (const GALGAS_type inOperand0,
                                            const GALGAS_uint inInsertionIndex,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_typelist (inOperand0 COMMA_THERE)) ;
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

void GALGAS_typelist::setter_removeAtIndex (GALGAS_type & outOperand0,
                                            const GALGAS_uint inRemoveIndex,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_typelist * p = (cCollectionElement_typelist *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_typelist) ;
        outOperand0 = p->mObject.mProperty_mValue ;
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

void GALGAS_typelist::setter_popFirst (GALGAS_type & outOperand0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typelist * p = (cCollectionElement_typelist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typelist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typelist::setter_popLast (GALGAS_type & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typelist * p = (cCollectionElement_typelist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typelist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typelist::method_first (GALGAS_type & outOperand0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typelist * p = (cCollectionElement_typelist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typelist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typelist::method_last (GALGAS_type & outOperand0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typelist * p = (cCollectionElement_typelist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typelist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist GALGAS_typelist::add_operation (const GALGAS_typelist & inOperand,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_typelist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist GALGAS_typelist::getter_subListWithRange (const GALGAS_range & inRange,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_typelist result = GALGAS_typelist::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist GALGAS_typelist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_typelist result = GALGAS_typelist::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist GALGAS_typelist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_typelist result = GALGAS_typelist::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typelist::plusAssign_operation (const GALGAS_typelist inOperand,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typelist::setter_setMValueAtIndex (GALGAS_type inOperand,
                                               GALGAS_uint inIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cCollectionElement_typelist * p = (cCollectionElement_typelist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typelist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_type GALGAS_typelist::getter_mValueAtIndex (const GALGAS_uint & inIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typelist * p = (cCollectionElement_typelist *) attributes.ptr () ;
  GALGAS_type result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typelist) ;
    result = p->mObject.mProperty_mValue ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_typelist::cEnumerator_typelist (const GALGAS_typelist & inEnumeratedObject,
                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist_2D_element cEnumerator_typelist::current (LOCATION_ARGS) const {
  const cCollectionElement_typelist * p = (const cCollectionElement_typelist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typelist) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cEnumerator_typelist::current_mValue (LOCATION_ARGS) const {
  const cCollectionElement_typelist * p = (const cCollectionElement_typelist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typelist) ;
  return p->mObject.mProperty_mValue ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @uintlist generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uintlist ("uintlist",
                                 nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uintlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uintlist ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uintlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uintlist (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist GALGAS_uintlist::extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_uintlist result ;
  const GALGAS_uintlist * p = (const GALGAS_uintlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uintlist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uintlist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@uintlist' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_uintlist : public cCollectionElement {
  public: GALGAS_uintlist_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_uintlist (const GALGAS_uint & in_mValue
                                       COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_uintlist (const GALGAS_uintlist_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_uintlist::cCollectionElement_uintlist (const GALGAS_uint & in_mValue
                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_uintlist::cCollectionElement_uintlist (const GALGAS_uintlist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_uintlist::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_uintlist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_uintlist (mObject.mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_uintlist::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue" ":" ;
  mObject.mProperty_mValue.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_uintlist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_uintlist * operand = (cCollectionElement_uintlist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_uintlist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist::GALGAS_uintlist (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist::GALGAS_uintlist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist GALGAS_uintlist::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_uintlist  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist GALGAS_uintlist::constructor_listWithValue (const GALGAS_uint & inOperand0
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_uintlist result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_uintlist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_uintlist::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uintlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const GALGAS_uint & in_mValue
                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement_uintlist * p = nullptr ;
  macroMyNew (p, cCollectionElement_uintlist (in_mValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uintlist::addAssign_operation (const GALGAS_uint & inOperand0
                                           COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_uintlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uintlist::setter_append (const GALGAS_uint inOperand0,
                                     C_Compiler * /* inCompiler */
                                     COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_uintlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uintlist::setter_insertAtIndex (const GALGAS_uint inOperand0,
                                            const GALGAS_uint inInsertionIndex,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_uintlist (inOperand0 COMMA_THERE)) ;
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

void GALGAS_uintlist::setter_removeAtIndex (GALGAS_uint & outOperand0,
                                            const GALGAS_uint inRemoveIndex,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_uintlist * p = (cCollectionElement_uintlist *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_uintlist) ;
        outOperand0 = p->mObject.mProperty_mValue ;
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

void GALGAS_uintlist::setter_popFirst (GALGAS_uint & outOperand0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uintlist * p = (cCollectionElement_uintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uintlist::setter_popLast (GALGAS_uint & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uintlist * p = (cCollectionElement_uintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uintlist::method_first (GALGAS_uint & outOperand0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uintlist * p = (cCollectionElement_uintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uintlist::method_last (GALGAS_uint & outOperand0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uintlist * p = (cCollectionElement_uintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist GALGAS_uintlist::add_operation (const GALGAS_uintlist & inOperand,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uintlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist GALGAS_uintlist::getter_subListWithRange (const GALGAS_range & inRange,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uintlist result = GALGAS_uintlist::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist GALGAS_uintlist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uintlist result = GALGAS_uintlist::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist GALGAS_uintlist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uintlist result = GALGAS_uintlist::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uintlist::plusAssign_operation (const GALGAS_uintlist inOperand,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uintlist::setter_setMValueAtIndex (GALGAS_uint inOperand,
                                               GALGAS_uint inIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cCollectionElement_uintlist * p = (cCollectionElement_uintlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_uintlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_uintlist::getter_mValueAtIndex (const GALGAS_uint & inIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_uintlist * p = (cCollectionElement_uintlist *) attributes.ptr () ;
  GALGAS_uint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_uintlist) ;
    result = p->mObject.mProperty_mValue ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_uintlist::cEnumerator_uintlist (const GALGAS_uintlist & inEnumeratedObject,
                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist_2D_element cEnumerator_uintlist::current (LOCATION_ARGS) const {
  const cCollectionElement_uintlist * p = (const cCollectionElement_uintlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uintlist) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_uintlist::current_mValue (LOCATION_ARGS) const {
  const cCollectionElement_uintlist * p = (const cCollectionElement_uintlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uintlist) ;
  return p->mObject.mProperty_mValue ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @uint64list generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_list ("uint64list",
                                         nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_36__34_list::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_list ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_36__34_list::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_list (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list GALGAS_uint_36__34_list::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_list result ;
  const GALGAS_uint_36__34_list * p = (const GALGAS_uint_36__34_list *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uint_36__34_list *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64list", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@uint_36__34_list' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_uint_36__34_list : public cCollectionElement {
  public: GALGAS_uint_36__34_list_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_uint_36__34_list (const GALGAS_uint_36__34_ & in_mValue
                                               COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_uint_36__34_list (const GALGAS_uint_36__34_list_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_uint_36__34_list::cCollectionElement_uint_36__34_list (const GALGAS_uint_36__34_ & in_mValue
                                                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_uint_36__34_list::cCollectionElement_uint_36__34_list (const GALGAS_uint_36__34_list_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_uint_36__34_list::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_uint_36__34_list::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_uint_36__34_list (mObject.mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_uint_36__34_list::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue" ":" ;
  mObject.mProperty_mValue.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_uint_36__34_list::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_uint_36__34_list * operand = (cCollectionElement_uint_36__34_list *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_uint_36__34_list) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list::GALGAS_uint_36__34_list (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list::GALGAS_uint_36__34_list (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list GALGAS_uint_36__34_list::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint_36__34_list  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list GALGAS_uint_36__34_list::constructor_listWithValue (const GALGAS_uint_36__34_ & inOperand0
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_list result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_uint_36__34_list (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_uint_36__34_list::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_list::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                         const GALGAS_uint_36__34_ & in_mValue
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_uint_36__34_list * p = nullptr ;
  macroMyNew (p, cCollectionElement_uint_36__34_list (in_mValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_list::addAssign_operation (const GALGAS_uint_36__34_ & inOperand0
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_uint_36__34_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_list::setter_append (const GALGAS_uint_36__34_ inOperand0,
                                             C_Compiler * /* inCompiler */
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_uint_36__34_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_list::setter_insertAtIndex (const GALGAS_uint_36__34_ inOperand0,
                                                    const GALGAS_uint inInsertionIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_uint_36__34_list (inOperand0 COMMA_THERE)) ;
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

void GALGAS_uint_36__34_list::setter_removeAtIndex (GALGAS_uint_36__34_ & outOperand0,
                                                    const GALGAS_uint inRemoveIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_uint_36__34_list * p = (cCollectionElement_uint_36__34_list *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_uint_36__34_list) ;
        outOperand0 = p->mObject.mProperty_mValue ;
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

void GALGAS_uint_36__34_list::setter_popFirst (GALGAS_uint_36__34_ & outOperand0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_list * p = (cCollectionElement_uint_36__34_list *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_36__34_list) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_list::setter_popLast (GALGAS_uint_36__34_ & outOperand0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_list * p = (cCollectionElement_uint_36__34_list *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_36__34_list) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_list::method_first (GALGAS_uint_36__34_ & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_list * p = (cCollectionElement_uint_36__34_list *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_36__34_list) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_list::method_last (GALGAS_uint_36__34_ & outOperand0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_list * p = (cCollectionElement_uint_36__34_list *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_uint_36__34_list) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list GALGAS_uint_36__34_list::add_operation (const GALGAS_uint_36__34_list & inOperand,
                                                                C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_list result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list GALGAS_uint_36__34_list::getter_subListWithRange (const GALGAS_range & inRange,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_list result = GALGAS_uint_36__34_list::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list GALGAS_uint_36__34_list::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_list result = GALGAS_uint_36__34_list::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list GALGAS_uint_36__34_list::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_list result = GALGAS_uint_36__34_list::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_list::plusAssign_operation (const GALGAS_uint_36__34_list inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_list::setter_setMValueAtIndex (GALGAS_uint_36__34_ inOperand,
                                                       GALGAS_uint inIndex,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement_uint_36__34_list * p = (cCollectionElement_uint_36__34_list *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_uint_36__34_list) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_uint_36__34_list::getter_mValueAtIndex (const GALGAS_uint & inIndex,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_uint_36__34_list * p = (cCollectionElement_uint_36__34_list *) attributes.ptr () ;
  GALGAS_uint_36__34_ result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_uint_36__34_list) ;
    result = p->mObject.mProperty_mValue ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_uint_36__34_list::cEnumerator_uint_36__34_list (const GALGAS_uint_36__34_list & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list_2D_element cEnumerator_uint_36__34_list::current (LOCATION_ARGS) const {
  const cCollectionElement_uint_36__34_list * p = (const cCollectionElement_uint_36__34_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_36__34_list) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ cEnumerator_uint_36__34_list::current_mValue (LOCATION_ARGS) const {
  const cCollectionElement_uint_36__34_list * p = (const cCollectionElement_uint_36__34_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_uint_36__34_list) ;
  return p->mObject.mProperty_mValue ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @bigintlist generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_bigintlist ("bigintlist",
                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_bigintlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bigintlist ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_bigintlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_bigintlist (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist GALGAS_bigintlist::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_bigintlist result ;
  const GALGAS_bigintlist * p = (const GALGAS_bigintlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_bigintlist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("bigintlist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@bigintlist' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_bigintlist : public cCollectionElement {
  public: GALGAS_bigintlist_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_bigintlist (const GALGAS_bigint & in_mValue
                                         COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_bigintlist (const GALGAS_bigintlist_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_bigintlist::cCollectionElement_bigintlist (const GALGAS_bigint & in_mValue
                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_bigintlist::cCollectionElement_bigintlist (const GALGAS_bigintlist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_bigintlist::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_bigintlist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_bigintlist (mObject.mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_bigintlist::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue" ":" ;
  mObject.mProperty_mValue.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_bigintlist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_bigintlist * operand = (cCollectionElement_bigintlist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_bigintlist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist::GALGAS_bigintlist (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist::GALGAS_bigintlist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist GALGAS_bigintlist::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_bigintlist  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist GALGAS_bigintlist::constructor_listWithValue (const GALGAS_bigint & inOperand0
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_bigintlist result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_bigintlist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_bigintlist::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_bigintlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                   const GALGAS_bigint & in_mValue
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement_bigintlist * p = nullptr ;
  macroMyNew (p, cCollectionElement_bigintlist (in_mValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_bigintlist::addAssign_operation (const GALGAS_bigint & inOperand0
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_bigintlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_bigintlist::setter_append (const GALGAS_bigint inOperand0,
                                       C_Compiler * /* inCompiler */
                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_bigintlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_bigintlist::setter_insertAtIndex (const GALGAS_bigint inOperand0,
                                              const GALGAS_uint inInsertionIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_bigintlist (inOperand0 COMMA_THERE)) ;
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

void GALGAS_bigintlist::setter_removeAtIndex (GALGAS_bigint & outOperand0,
                                              const GALGAS_uint inRemoveIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_bigintlist * p = (cCollectionElement_bigintlist *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_bigintlist) ;
        outOperand0 = p->mObject.mProperty_mValue ;
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

void GALGAS_bigintlist::setter_popFirst (GALGAS_bigint & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_bigintlist * p = (cCollectionElement_bigintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_bigintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_bigintlist::setter_popLast (GALGAS_bigint & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_bigintlist * p = (cCollectionElement_bigintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_bigintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_bigintlist::method_first (GALGAS_bigint & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_bigintlist * p = (cCollectionElement_bigintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_bigintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_bigintlist::method_last (GALGAS_bigint & outOperand0,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_bigintlist * p = (cCollectionElement_bigintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_bigintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist GALGAS_bigintlist::add_operation (const GALGAS_bigintlist & inOperand,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigintlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist GALGAS_bigintlist::getter_subListWithRange (const GALGAS_range & inRange,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_bigintlist result = GALGAS_bigintlist::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist GALGAS_bigintlist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_bigintlist result = GALGAS_bigintlist::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist GALGAS_bigintlist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_bigintlist result = GALGAS_bigintlist::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_bigintlist::plusAssign_operation (const GALGAS_bigintlist inOperand,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_bigintlist::setter_setMValueAtIndex (GALGAS_bigint inOperand,
                                                 GALGAS_uint inIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement_bigintlist * p = (cCollectionElement_bigintlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_bigintlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint GALGAS_bigintlist::getter_mValueAtIndex (const GALGAS_uint & inIndex,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_bigintlist * p = (cCollectionElement_bigintlist *) attributes.ptr () ;
  GALGAS_bigint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_bigintlist) ;
    result = p->mObject.mProperty_mValue ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_bigintlist::cEnumerator_bigintlist (const GALGAS_bigintlist & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist_2D_element cEnumerator_bigintlist::current (LOCATION_ARGS) const {
  const cCollectionElement_bigintlist * p = (const cCollectionElement_bigintlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_bigintlist) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint cEnumerator_bigintlist::current_mValue (LOCATION_ARGS) const {
  const cCollectionElement_bigintlist * p = (const cCollectionElement_bigintlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_bigintlist) ;
  return p->mObject.mProperty_mValue ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @lbigintlist generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lbigintlist ("lbigintlist",
                                    nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lbigintlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lbigintlist ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lbigintlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lbigintlist (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist GALGAS_lbigintlist::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_lbigintlist result ;
  const GALGAS_lbigintlist * p = (const GALGAS_lbigintlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lbigintlist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lbigintlist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@lbigintlist' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_lbigintlist : public cCollectionElement {
  public: GALGAS_lbigintlist_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_lbigintlist (const GALGAS_lbigint & in_mValue
                                          COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_lbigintlist (const GALGAS_lbigintlist_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement_lbigintlist::cCollectionElement_lbigintlist (const GALGAS_lbigint & in_mValue
                                                                COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_lbigintlist::cCollectionElement_lbigintlist (const GALGAS_lbigintlist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_lbigintlist::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_lbigintlist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_lbigintlist (mObject.mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_lbigintlist::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue" ":" ;
  mObject.mProperty_mValue.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_lbigintlist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_lbigintlist * operand = (cCollectionElement_lbigintlist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_lbigintlist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist::GALGAS_lbigintlist (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist::GALGAS_lbigintlist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist GALGAS_lbigintlist::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_lbigintlist  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist GALGAS_lbigintlist::constructor_listWithValue (const GALGAS_lbigint & inOperand0
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_lbigintlist result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_lbigintlist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_lbigintlist::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigintlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                    const GALGAS_lbigint & in_mValue
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_lbigintlist * p = nullptr ;
  macroMyNew (p, cCollectionElement_lbigintlist (in_mValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigintlist::addAssign_operation (const GALGAS_lbigint & inOperand0
                                              COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_lbigintlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigintlist::setter_append (const GALGAS_lbigint inOperand0,
                                        C_Compiler * /* inCompiler */
                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_lbigintlist (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigintlist::setter_insertAtIndex (const GALGAS_lbigint inOperand0,
                                               const GALGAS_uint inInsertionIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement_lbigintlist (inOperand0 COMMA_THERE)) ;
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

void GALGAS_lbigintlist::setter_removeAtIndex (GALGAS_lbigint & outOperand0,
                                               const GALGAS_uint inRemoveIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_lbigintlist * p = (cCollectionElement_lbigintlist *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_lbigintlist) ;
        outOperand0 = p->mObject.mProperty_mValue ;
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

void GALGAS_lbigintlist::setter_popFirst (GALGAS_lbigint & outOperand0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_lbigintlist * p = (cCollectionElement_lbigintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_lbigintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigintlist::setter_popLast (GALGAS_lbigint & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_lbigintlist * p = (cCollectionElement_lbigintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_lbigintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigintlist::method_first (GALGAS_lbigint & outOperand0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_lbigintlist * p = (cCollectionElement_lbigintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_lbigintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigintlist::method_last (GALGAS_lbigint & outOperand0,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_lbigintlist * p = (cCollectionElement_lbigintlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_lbigintlist) ;
    outOperand0 = p->mObject.mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist GALGAS_lbigintlist::add_operation (const GALGAS_lbigintlist & inOperand,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lbigintlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist GALGAS_lbigintlist::getter_subListWithRange (const GALGAS_range & inRange,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_lbigintlist result = GALGAS_lbigintlist::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist GALGAS_lbigintlist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_lbigintlist result = GALGAS_lbigintlist::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist GALGAS_lbigintlist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_lbigintlist result = GALGAS_lbigintlist::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigintlist::plusAssign_operation (const GALGAS_lbigintlist inOperand,
                                               C_Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigintlist::setter_setMValueAtIndex (GALGAS_lbigint inOperand,
                                                  GALGAS_uint inIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_lbigintlist * p = (cCollectionElement_lbigintlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_lbigintlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint GALGAS_lbigintlist::getter_mValueAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_lbigintlist * p = (cCollectionElement_lbigintlist *) attributes.ptr () ;
  GALGAS_lbigint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_lbigintlist) ;
    result = p->mObject.mProperty_mValue ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_lbigintlist::cEnumerator_lbigintlist (const GALGAS_lbigintlist & inEnumeratedObject,
                                                  const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist_2D_element cEnumerator_lbigintlist::current (LOCATION_ARGS) const {
  const cCollectionElement_lbigintlist * p = (const cCollectionElement_lbigintlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_lbigintlist) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigint cEnumerator_lbigintlist::current_mValue (LOCATION_ARGS) const {
  const cCollectionElement_lbigintlist * p = (const cCollectionElement_lbigintlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_lbigintlist) ;
  return p->mObject.mProperty_mValue ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @lchar generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lchar ("lchar",
                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lchar::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lchar ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lchar::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lchar (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lchar GALGAS_lchar::extractObject (const GALGAS_object & inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_lchar result ;
  const GALGAS_lchar * p = (const GALGAS_lchar *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lchar *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lchar", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lchar::GALGAS_lchar (void) :
mProperty_char (),
mProperty_location () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lchar::~ GALGAS_lchar (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lchar::GALGAS_lchar (const GALGAS_char & inOperand0,
                            const GALGAS_location & inOperand1) :
mProperty_char (inOperand0),
mProperty_location (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lchar GALGAS_lchar::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lchar (GALGAS_char::constructor_default (HERE),
                       GALGAS_location::constructor_nowhere (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lchar GALGAS_lchar::constructor_new (const GALGAS_char & in_char,
                                            const GALGAS_location & in_location 
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lchar result ;
  if (in_char.isValid () && in_location.isValid ()) {
    result = GALGAS_lchar (in_char, in_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_lchar::objectCompare (const GALGAS_lchar & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_char.objectCompare (inOperand.mProperty_char) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lchar::isValid (void) const {
  return mProperty_char.isValid () && mProperty_location.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lchar::drop (void) {
  mProperty_char.drop () ;
  mProperty_location.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lchar::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "<struct @lchar:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_char.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_location.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @ldouble generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ldouble ("ldouble",
                                nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_ldouble::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ldouble ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_ldouble::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ldouble (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ldouble GALGAS_ldouble::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_ldouble result ;
  const GALGAS_ldouble * p = (const GALGAS_ldouble *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_ldouble *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ldouble", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ldouble::GALGAS_ldouble (void) :
mProperty_double (),
mProperty_location () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ldouble::~ GALGAS_ldouble (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ldouble::GALGAS_ldouble (const GALGAS_double & inOperand0,
                                const GALGAS_location & inOperand1) :
mProperty_double (inOperand0),
mProperty_location (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ldouble GALGAS_ldouble::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_ldouble (GALGAS_double::constructor_default (HERE),
                         GALGAS_location::constructor_nowhere (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ldouble GALGAS_ldouble::constructor_new (const GALGAS_double & in_double,
                                                const GALGAS_location & in_location 
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_ldouble result ;
  if (in_double.isValid () && in_location.isValid ()) {
    result = GALGAS_ldouble (in_double, in_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_ldouble::objectCompare (const GALGAS_ldouble & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_double.objectCompare (inOperand.mProperty_double) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_ldouble::isValid (void) const {
  return mProperty_double.isValid () && mProperty_location.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ldouble::drop (void) {
  mProperty_double.drop () ;
  mProperty_location.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ldouble::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "<struct @ldouble:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_double.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_location.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @lsint64 generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lsint_36__34_ ("lsint64",
                                      nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lsint_36__34_::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lsint_36__34_ ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lsint_36__34_::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lsint_36__34_ (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint_36__34_ GALGAS_lsint_36__34_::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_lsint_36__34_ result ;
  const GALGAS_lsint_36__34_ * p = (const GALGAS_lsint_36__34_ *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lsint_36__34_ *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lsint64", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint_36__34_::GALGAS_lsint_36__34_ (void) :
mProperty_sint_36__34_ (),
mProperty_location () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint_36__34_::~ GALGAS_lsint_36__34_ (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint_36__34_::GALGAS_lsint_36__34_ (const GALGAS_sint_36__34_ & inOperand0,
                                            const GALGAS_location & inOperand1) :
mProperty_sint_36__34_ (inOperand0),
mProperty_location (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint_36__34_ GALGAS_lsint_36__34_::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lsint_36__34_ (GALGAS_sint_36__34_::constructor_default (HERE),
                               GALGAS_location::constructor_nowhere (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint_36__34_ GALGAS_lsint_36__34_::constructor_new (const GALGAS_sint_36__34_ & in_sint64,
                                                            const GALGAS_location & in_location 
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lsint_36__34_ result ;
  if (in_sint64.isValid () && in_location.isValid ()) {
    result = GALGAS_lsint_36__34_ (in_sint64, in_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_lsint_36__34_::objectCompare (const GALGAS_lsint_36__34_ & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_sint_36__34_.objectCompare (inOperand.mProperty_sint_36__34_) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lsint_36__34_::isValid (void) const {
  return mProperty_sint_36__34_.isValid () && mProperty_location.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lsint_36__34_::drop (void) {
  mProperty_sint_36__34_.drop () ;
  mProperty_location.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lsint_36__34_::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "<struct @lsint64:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_sint_36__34_.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_location.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @luint64 generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_luint_36__34_ ("luint64",
                                      nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_luint_36__34_::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_luint_36__34_ ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_luint_36__34_::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_luint_36__34_ (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint_36__34_ GALGAS_luint_36__34_::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result ;
  const GALGAS_luint_36__34_ * p = (const GALGAS_luint_36__34_ *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_luint_36__34_ *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("luint64", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint_36__34_::GALGAS_luint_36__34_ (void) :
mProperty_uint_36__34_ (),
mProperty_location () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint_36__34_::~ GALGAS_luint_36__34_ (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint_36__34_::GALGAS_luint_36__34_ (const GALGAS_uint_36__34_ & inOperand0,
                                            const GALGAS_location & inOperand1) :
mProperty_uint_36__34_ (inOperand0),
mProperty_location (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint_36__34_ GALGAS_luint_36__34_::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_luint_36__34_ (GALGAS_uint_36__34_::constructor_default (HERE),
                               GALGAS_location::constructor_nowhere (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint_36__34_ GALGAS_luint_36__34_::constructor_new (const GALGAS_uint_36__34_ & in_uint64,
                                                            const GALGAS_location & in_location 
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result ;
  if (in_uint64.isValid () && in_location.isValid ()) {
    result = GALGAS_luint_36__34_ (in_uint64, in_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_luint_36__34_::objectCompare (const GALGAS_luint_36__34_ & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_uint_36__34_.objectCompare (inOperand.mProperty_uint_36__34_) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_luint_36__34_::isValid (void) const {
  return mProperty_uint_36__34_.isValid () && mProperty_location.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luint_36__34_::drop (void) {
  mProperty_uint_36__34_.drop () ;
  mProperty_location.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luint_36__34_::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "<struct @luint64:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_uint_36__34_.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_location.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @2stringlist generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS__32_stringlist ("2stringlist",
                                       nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS__32_stringlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS__32_stringlist ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS__32_stringlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS__32_stringlist (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist GALGAS__32_stringlist::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS__32_stringlist result ;
  const GALGAS__32_stringlist * p = (const GALGAS__32_stringlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS__32_stringlist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("2stringlist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@_32_stringlist' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement__32_stringlist : public cCollectionElement {
  public: GALGAS__32_stringlist_2D_element mObject ;

//--- Constructors
  public: cCollectionElement__32_stringlist (const GALGAS_string & in_mValue_30_,
                                             const GALGAS_string & in_mValue_31_
                                             COMMA_LOCATION_ARGS) ;
  public: cCollectionElement__32_stringlist (const GALGAS__32_stringlist_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement__32_stringlist::cCollectionElement__32_stringlist (const GALGAS_string & in_mValue_30_,
                                                                      const GALGAS_string & in_mValue_31_
                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue_30_, in_mValue_31_) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement__32_stringlist::cCollectionElement__32_stringlist (const GALGAS__32_stringlist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue_30_, inElement.mProperty_mValue_31_) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement__32_stringlist::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement__32_stringlist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement__32_stringlist (mObject.mProperty_mValue_30_, mObject.mProperty_mValue_31_ COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement__32_stringlist::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue0" ":" ;
  mObject.mProperty_mValue_30_.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue1" ":" ;
  mObject.mProperty_mValue_31_.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement__32_stringlist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement__32_stringlist * operand = (cCollectionElement__32_stringlist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement__32_stringlist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist::GALGAS__32_stringlist (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist::GALGAS__32_stringlist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist GALGAS__32_stringlist::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS__32_stringlist  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist GALGAS__32_stringlist::constructor_listWithValue (const GALGAS_string & inOperand0,
                                                                        const GALGAS_string & inOperand1
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS__32_stringlist result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS__32_stringlist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS__32_stringlist::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_stringlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                       const GALGAS_string & in_mValue_30_,
                                                       const GALGAS_string & in_mValue_31_
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement__32_stringlist * p = nullptr ;
  macroMyNew (p, cCollectionElement__32_stringlist (in_mValue_30_,
                                                    in_mValue_31_ COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_stringlist::addAssign_operation (const GALGAS_string & inOperand0,
                                                 const GALGAS_string & inOperand1
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement__32_stringlist (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_stringlist::setter_append (const GALGAS_string inOperand0,
                                           const GALGAS_string inOperand1,
                                           C_Compiler * /* inCompiler */
                                           COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement__32_stringlist (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_stringlist::setter_insertAtIndex (const GALGAS_string inOperand0,
                                                  const GALGAS_string inOperand1,
                                                  const GALGAS_uint inInsertionIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement__32_stringlist (inOperand0, inOperand1 COMMA_THERE)) ;
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

void GALGAS__32_stringlist::setter_removeAtIndex (GALGAS_string & outOperand0,
                                                  GALGAS_string & outOperand1,
                                                  const GALGAS_uint inRemoveIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement__32_stringlist * p = (cCollectionElement__32_stringlist *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement__32_stringlist) ;
        outOperand0 = p->mObject.mProperty_mValue_30_ ;
        outOperand1 = p->mObject.mProperty_mValue_31_ ;
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

void GALGAS__32_stringlist::setter_popFirst (GALGAS_string & outOperand0,
                                             GALGAS_string & outOperand1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement__32_stringlist * p = (cCollectionElement__32_stringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement__32_stringlist) ;
    outOperand0 = p->mObject.mProperty_mValue_30_ ;
    outOperand1 = p->mObject.mProperty_mValue_31_ ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_stringlist::setter_popLast (GALGAS_string & outOperand0,
                                            GALGAS_string & outOperand1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement__32_stringlist * p = (cCollectionElement__32_stringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement__32_stringlist) ;
    outOperand0 = p->mObject.mProperty_mValue_30_ ;
    outOperand1 = p->mObject.mProperty_mValue_31_ ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_stringlist::method_first (GALGAS_string & outOperand0,
                                          GALGAS_string & outOperand1,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement__32_stringlist * p = (cCollectionElement__32_stringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement__32_stringlist) ;
    outOperand0 = p->mObject.mProperty_mValue_30_ ;
    outOperand1 = p->mObject.mProperty_mValue_31_ ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_stringlist::method_last (GALGAS_string & outOperand0,
                                         GALGAS_string & outOperand1,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement__32_stringlist * p = (cCollectionElement__32_stringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement__32_stringlist) ;
    outOperand0 = p->mObject.mProperty_mValue_30_ ;
    outOperand1 = p->mObject.mProperty_mValue_31_ ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist GALGAS__32_stringlist::add_operation (const GALGAS__32_stringlist & inOperand,
                                                            C_Compiler * /* inCompiler */
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS__32_stringlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist GALGAS__32_stringlist::getter_subListWithRange (const GALGAS_range & inRange,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS__32_stringlist result = GALGAS__32_stringlist::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist GALGAS__32_stringlist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS__32_stringlist result = GALGAS__32_stringlist::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist GALGAS__32_stringlist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS__32_stringlist result = GALGAS__32_stringlist::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_stringlist::plusAssign_operation (const GALGAS__32_stringlist inOperand,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_stringlist::setter_setMValue_30_AtIndex (GALGAS_string inOperand,
                                                         GALGAS_uint inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement__32_stringlist * p = (cCollectionElement__32_stringlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement__32_stringlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue_30_ = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS__32_stringlist::getter_mValue_30_AtIndex (const GALGAS_uint & inIndex,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement__32_stringlist * p = (cCollectionElement__32_stringlist *) attributes.ptr () ;
  GALGAS_string result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement__32_stringlist) ;
    result = p->mObject.mProperty_mValue_30_ ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_stringlist::setter_setMValue_31_AtIndex (GALGAS_string inOperand,
                                                         GALGAS_uint inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement__32_stringlist * p = (cCollectionElement__32_stringlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement__32_stringlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue_31_ = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS__32_stringlist::getter_mValue_31_AtIndex (const GALGAS_uint & inIndex,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement__32_stringlist * p = (cCollectionElement__32_stringlist *) attributes.ptr () ;
  GALGAS_string result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement__32_stringlist) ;
    result = p->mObject.mProperty_mValue_31_ ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator__32_stringlist::cEnumerator__32_stringlist (const GALGAS__32_stringlist & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist_2D_element cEnumerator__32_stringlist::current (LOCATION_ARGS) const {
  const cCollectionElement__32_stringlist * p = (const cCollectionElement__32_stringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement__32_stringlist) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cEnumerator__32_stringlist::current_mValue_30_ (LOCATION_ARGS) const {
  const cCollectionElement__32_stringlist * p = (const cCollectionElement__32_stringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement__32_stringlist) ;
  return p->mObject.mProperty_mValue_30_ ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cEnumerator__32_stringlist::current_mValue_31_ (LOCATION_ARGS) const {
  const cCollectionElement__32_stringlist * p = (const cCollectionElement__32_stringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement__32_stringlist) ;
  return p->mObject.mProperty_mValue_31_ ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @2lstringlist generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS__32_lstringlist ("2lstringlist",
                                        nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS__32_lstringlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS__32_lstringlist ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS__32_lstringlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS__32_lstringlist (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS__32_lstringlist result ;
  const GALGAS__32_lstringlist * p = (const GALGAS__32_lstringlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS__32_lstringlist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("2lstringlist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@_32_lstringlist' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement__32_lstringlist : public cCollectionElement {
  public: GALGAS__32_lstringlist_2D_element mObject ;

//--- Constructors
  public: cCollectionElement__32_lstringlist (const GALGAS_lstring & in_mValue_30_,
                                              const GALGAS_lstring & in_mValue_31_
                                              COMMA_LOCATION_ARGS) ;
  public: cCollectionElement__32_lstringlist (const GALGAS__32_lstringlist_2D_element & inElement COMMA_LOCATION_ARGS) ;

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

cCollectionElement__32_lstringlist::cCollectionElement__32_lstringlist (const GALGAS_lstring & in_mValue_30_,
                                                                        const GALGAS_lstring & in_mValue_31_
                                                                        COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue_30_, in_mValue_31_) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement__32_lstringlist::cCollectionElement__32_lstringlist (const GALGAS__32_lstringlist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue_30_, inElement.mProperty_mValue_31_) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement__32_lstringlist::isValid (void) const {
  return true ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement__32_lstringlist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement__32_lstringlist (mObject.mProperty_mValue_30_, mObject.mProperty_mValue_31_ COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement__32_lstringlist::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue0" ":" ;
  mObject.mProperty_mValue_30_.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue1" ":" ;
  mObject.mProperty_mValue_31_.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement__32_lstringlist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement__32_lstringlist * operand = (cCollectionElement__32_lstringlist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement__32_lstringlist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist::GALGAS__32_lstringlist (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist::GALGAS__32_lstringlist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS__32_lstringlist  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_lstring & inOperand1
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS__32_lstringlist result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS__32_lstringlist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS__32_lstringlist::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                        const GALGAS_lstring & in_mValue_30_,
                                                        const GALGAS_lstring & in_mValue_31_
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement__32_lstringlist * p = nullptr ;
  macroMyNew (p, cCollectionElement__32_lstringlist (in_mValue_30_,
                                                     in_mValue_31_ COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                  const GALGAS_lstring & inOperand1
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement__32_lstringlist (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::setter_append (const GALGAS_lstring inOperand0,
                                            const GALGAS_lstring inOperand1,
                                            C_Compiler * /* inCompiler */
                                            COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement__32_lstringlist (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                   const GALGAS_lstring inOperand1,
                                                   const GALGAS_uint inInsertionIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement__32_lstringlist (inOperand0, inOperand1 COMMA_THERE)) ;
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

void GALGAS__32_lstringlist::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                   GALGAS_lstring & outOperand1,
                                                   const GALGAS_uint inRemoveIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
        outOperand0 = p->mObject.mProperty_mValue_30_ ;
        outOperand1 = p->mObject.mProperty_mValue_31_ ;
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

void GALGAS__32_lstringlist::setter_popFirst (GALGAS_lstring & outOperand0,
                                              GALGAS_lstring & outOperand1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    outOperand0 = p->mObject.mProperty_mValue_30_ ;
    outOperand1 = p->mObject.mProperty_mValue_31_ ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::setter_popLast (GALGAS_lstring & outOperand0,
                                             GALGAS_lstring & outOperand1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    outOperand0 = p->mObject.mProperty_mValue_30_ ;
    outOperand1 = p->mObject.mProperty_mValue_31_ ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::method_first (GALGAS_lstring & outOperand0,
                                           GALGAS_lstring & outOperand1,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    outOperand0 = p->mObject.mProperty_mValue_30_ ;
    outOperand1 = p->mObject.mProperty_mValue_31_ ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::method_last (GALGAS_lstring & outOperand0,
                                          GALGAS_lstring & outOperand1,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    outOperand0 = p->mObject.mProperty_mValue_30_ ;
    outOperand1 = p->mObject.mProperty_mValue_31_ ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::add_operation (const GALGAS__32_lstringlist & inOperand,
                                                              C_Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS__32_lstringlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::getter_subListWithRange (const GALGAS_range & inRange,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS__32_lstringlist result = GALGAS__32_lstringlist::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS__32_lstringlist result = GALGAS__32_lstringlist::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS__32_lstringlist result = GALGAS__32_lstringlist::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::plusAssign_operation (const GALGAS__32_lstringlist inOperand,
                                                   C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::setter_setMValue_30_AtIndex (GALGAS_lstring inOperand,
                                                          GALGAS_uint inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue_30_ = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS__32_lstringlist::getter_mValue_30_AtIndex (const GALGAS_uint & inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    result = p->mObject.mProperty_mValue_30_ ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::setter_setMValue_31_AtIndex (GALGAS_lstring inOperand,
                                                          GALGAS_uint inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue_31_ = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS__32_lstringlist::getter_mValue_31_AtIndex (const GALGAS_uint & inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    result = p->mObject.mProperty_mValue_31_ ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator__32_lstringlist::cEnumerator__32_lstringlist (const GALGAS__32_lstringlist & inEnumeratedObject,
                                                          const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element cEnumerator__32_lstringlist::current (LOCATION_ARGS) const {
  const cCollectionElement__32_lstringlist * p = (const cCollectionElement__32_lstringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator__32_lstringlist::current_mValue_30_ (LOCATION_ARGS) const {
  const cCollectionElement__32_lstringlist * p = (const cCollectionElement__32_lstringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
  return p->mObject.mProperty_mValue_30_ ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator__32_lstringlist::current_mValue_31_ (LOCATION_ARGS) const {
  const cCollectionElement__32_lstringlist * p = (const cCollectionElement__32_lstringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
  return p->mObject.mProperty_mValue_31_ ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @range generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_range ("range",
                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_range::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_range ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_range::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_range (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_range GALGAS_range::extractObject (const GALGAS_object & inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_range result ;
  const GALGAS_range * p = (const GALGAS_range *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_range *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("range", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_range::GALGAS_range (void) :
mProperty_start (),
mProperty_length () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_range::~ GALGAS_range (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_range::GALGAS_range (const GALGAS_uint & inOperand0,
                            const GALGAS_uint & inOperand1) :
mProperty_start (inOperand0),
mProperty_length (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_range GALGAS_range::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_range (GALGAS_uint::constructor_default (HERE),
                       GALGAS_uint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_range GALGAS_range::constructor_new (const GALGAS_uint & in_start,
                                            const GALGAS_uint & in_length 
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_range result ;
  if (in_start.isValid () && in_length.isValid ()) {
    result = GALGAS_range (in_start, in_length) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_range::objectCompare (const GALGAS_range & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_start.objectCompare (inOperand.mProperty_start) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_length.objectCompare (inOperand.mProperty_length) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_range::isValid (void) const {
  return mProperty_start.isValid () && mProperty_length.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_range::drop (void) {
  mProperty_start.drop () ;
  mProperty_length.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_range::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "<struct @range:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_start.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_length.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @functionlist-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_functionlist_2D_element ("functionlist-element",
                                                nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_functionlist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_functionlist_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_functionlist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_functionlist_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist_2D_element GALGAS_functionlist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_functionlist_2D_element result ;
  const GALGAS_functionlist_2D_element * p = (const GALGAS_functionlist_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_functionlist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("functionlist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist_2D_element::GALGAS_functionlist_2D_element (void) :
mProperty_mValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist_2D_element::~ GALGAS_functionlist_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist_2D_element::GALGAS_functionlist_2D_element (const GALGAS_function & inOperand0) :
mProperty_mValue (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_functionlist_2D_element GALGAS_functionlist_2D_element::constructor_new (const GALGAS_function & in_mValue 
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_functionlist_2D_element result ;
  if (in_mValue.isValid ()) {
    result = GALGAS_functionlist_2D_element (in_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_functionlist_2D_element::objectCompare (const GALGAS_functionlist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mValue.objectCompare (inOperand.mProperty_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_functionlist_2D_element::isValid (void) const {
  return mProperty_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_functionlist_2D_element::drop (void) {
  mProperty_mValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_functionlist_2D_element::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "<struct @functionlist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @luintlist-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_luintlist_2D_element ("luintlist-element",
                                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_luintlist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_luintlist_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_luintlist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_luintlist_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist_2D_element GALGAS_luintlist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_luintlist_2D_element result ;
  const GALGAS_luintlist_2D_element * p = (const GALGAS_luintlist_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_luintlist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("luintlist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist_2D_element::GALGAS_luintlist_2D_element (void) :
mProperty_mValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist_2D_element::~ GALGAS_luintlist_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist_2D_element::GALGAS_luintlist_2D_element (const GALGAS_luint & inOperand0) :
mProperty_mValue (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist_2D_element GALGAS_luintlist_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_luintlist_2D_element (GALGAS_luint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luintlist_2D_element GALGAS_luintlist_2D_element::constructor_new (const GALGAS_luint & in_mValue 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luintlist_2D_element result ;
  if (in_mValue.isValid ()) {
    result = GALGAS_luintlist_2D_element (in_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_luintlist_2D_element::objectCompare (const GALGAS_luintlist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mValue.objectCompare (inOperand.mProperty_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_luintlist_2D_element::isValid (void) const {
  return mProperty_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luintlist_2D_element::drop (void) {
  mProperty_mValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_luintlist_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @luintlist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @objectlist-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectlist_2D_element ("objectlist-element",
                                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_objectlist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectlist_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_objectlist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectlist_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist_2D_element GALGAS_objectlist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_objectlist_2D_element result ;
  const GALGAS_objectlist_2D_element * p = (const GALGAS_objectlist_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_objectlist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectlist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist_2D_element::GALGAS_objectlist_2D_element (void) :
mProperty_mValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist_2D_element::~ GALGAS_objectlist_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist_2D_element::GALGAS_objectlist_2D_element (const GALGAS_object & inOperand0) :
mProperty_mValue (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectlist_2D_element GALGAS_objectlist_2D_element::constructor_new (const GALGAS_object & in_mValue 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectlist_2D_element result ;
  if (in_mValue.isValid ()) {
    result = GALGAS_objectlist_2D_element (in_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_objectlist_2D_element::objectCompare (const GALGAS_objectlist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mValue.objectCompare (inOperand.mProperty_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_objectlist_2D_element::isValid (void) const {
  return mProperty_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectlist_2D_element::drop (void) {
  mProperty_mValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectlist_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @objectlist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @stringlist-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringlist_2D_element ("stringlist-element",
                                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_stringlist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringlist_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_stringlist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringlist_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist_2D_element GALGAS_stringlist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_stringlist_2D_element result ;
  const GALGAS_stringlist_2D_element * p = (const GALGAS_stringlist_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_stringlist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringlist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist_2D_element::GALGAS_stringlist_2D_element (void) :
mProperty_mValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist_2D_element::~ GALGAS_stringlist_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist_2D_element::GALGAS_stringlist_2D_element (const GALGAS_string & inOperand0) :
mProperty_mValue (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist_2D_element GALGAS_stringlist_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_stringlist_2D_element (GALGAS_string::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist_2D_element GALGAS_stringlist_2D_element::constructor_new (const GALGAS_string & in_mValue 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist_2D_element result ;
  if (in_mValue.isValid ()) {
    result = GALGAS_stringlist_2D_element (in_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_stringlist_2D_element::objectCompare (const GALGAS_stringlist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mValue.objectCompare (inOperand.mProperty_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_stringlist_2D_element::isValid (void) const {
  return mProperty_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringlist_2D_element::drop (void) {
  mProperty_mValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringlist_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @stringlist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @typelist-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typelist_2D_element ("typelist-element",
                                            nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typelist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typelist_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typelist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typelist_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist_2D_element GALGAS_typelist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typelist_2D_element result ;
  const GALGAS_typelist_2D_element * p = (const GALGAS_typelist_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typelist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typelist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist_2D_element::GALGAS_typelist_2D_element (void) :
mProperty_mValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist_2D_element::~ GALGAS_typelist_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist_2D_element::GALGAS_typelist_2D_element (const GALGAS_type & inOperand0) :
mProperty_mValue (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typelist_2D_element GALGAS_typelist_2D_element::constructor_new (const GALGAS_type & in_mValue 
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typelist_2D_element result ;
  if (in_mValue.isValid ()) {
    result = GALGAS_typelist_2D_element (in_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_typelist_2D_element::objectCompare (const GALGAS_typelist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mValue.objectCompare (inOperand.mProperty_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_typelist_2D_element::isValid (void) const {
  return mProperty_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typelist_2D_element::drop (void) {
  mProperty_mValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typelist_2D_element::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "<struct @typelist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @uintlist-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uintlist_2D_element ("uintlist-element",
                                            nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uintlist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uintlist_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uintlist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uintlist_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist_2D_element GALGAS_uintlist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uintlist_2D_element result ;
  const GALGAS_uintlist_2D_element * p = (const GALGAS_uintlist_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uintlist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uintlist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist_2D_element::GALGAS_uintlist_2D_element (void) :
mProperty_mValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist_2D_element::~ GALGAS_uintlist_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist_2D_element::GALGAS_uintlist_2D_element (const GALGAS_uint & inOperand0) :
mProperty_mValue (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist_2D_element GALGAS_uintlist_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_uintlist_2D_element (GALGAS_uint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uintlist_2D_element GALGAS_uintlist_2D_element::constructor_new (const GALGAS_uint & in_mValue 
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uintlist_2D_element result ;
  if (in_mValue.isValid ()) {
    result = GALGAS_uintlist_2D_element (in_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_uintlist_2D_element::objectCompare (const GALGAS_uintlist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mValue.objectCompare (inOperand.mProperty_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_uintlist_2D_element::isValid (void) const {
  return mProperty_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uintlist_2D_element::drop (void) {
  mProperty_mValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uintlist_2D_element::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "<struct @uintlist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @uint64list-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_list_2D_element ("uint64list-element",
                                                    nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_36__34_list_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_list_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_36__34_list_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_list_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list_2D_element GALGAS_uint_36__34_list_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_list_2D_element result ;
  const GALGAS_uint_36__34_list_2D_element * p = (const GALGAS_uint_36__34_list_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_uint_36__34_list_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64list-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list_2D_element::GALGAS_uint_36__34_list_2D_element (void) :
mProperty_mValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list_2D_element::~ GALGAS_uint_36__34_list_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list_2D_element::GALGAS_uint_36__34_list_2D_element (const GALGAS_uint_36__34_ & inOperand0) :
mProperty_mValue (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list_2D_element GALGAS_uint_36__34_list_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint_36__34_list_2D_element (GALGAS_uint_36__34_::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_list_2D_element GALGAS_uint_36__34_list_2D_element::constructor_new (const GALGAS_uint_36__34_ & in_mValue 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_list_2D_element result ;
  if (in_mValue.isValid ()) {
    result = GALGAS_uint_36__34_list_2D_element (in_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_uint_36__34_list_2D_element::objectCompare (const GALGAS_uint_36__34_list_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mValue.objectCompare (inOperand.mProperty_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_uint_36__34_list_2D_element::isValid (void) const {
  return mProperty_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_list_2D_element::drop (void) {
  mProperty_mValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_list_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @uint64list-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @bigintlist-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_bigintlist_2D_element ("bigintlist-element",
                                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_bigintlist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_bigintlist_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_bigintlist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_bigintlist_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist_2D_element GALGAS_bigintlist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_bigintlist_2D_element result ;
  const GALGAS_bigintlist_2D_element * p = (const GALGAS_bigintlist_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_bigintlist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("bigintlist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist_2D_element::GALGAS_bigintlist_2D_element (void) :
mProperty_mValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist_2D_element::~ GALGAS_bigintlist_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist_2D_element::GALGAS_bigintlist_2D_element (const GALGAS_bigint & inOperand0) :
mProperty_mValue (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist_2D_element GALGAS_bigintlist_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_bigintlist_2D_element (GALGAS_bigint::constructor_zero (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigintlist_2D_element GALGAS_bigintlist_2D_element::constructor_new (const GALGAS_bigint & in_mValue 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigintlist_2D_element result ;
  if (in_mValue.isValid ()) {
    result = GALGAS_bigintlist_2D_element (in_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_bigintlist_2D_element::objectCompare (const GALGAS_bigintlist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mValue.objectCompare (inOperand.mProperty_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_bigintlist_2D_element::isValid (void) const {
  return mProperty_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_bigintlist_2D_element::drop (void) {
  mProperty_mValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_bigintlist_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @bigintlist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @lbigintlist-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lbigintlist_2D_element ("lbigintlist-element",
                                               nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lbigintlist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lbigintlist_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lbigintlist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lbigintlist_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist_2D_element GALGAS_lbigintlist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_lbigintlist_2D_element result ;
  const GALGAS_lbigintlist_2D_element * p = (const GALGAS_lbigintlist_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lbigintlist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lbigintlist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist_2D_element::GALGAS_lbigintlist_2D_element (void) :
mProperty_mValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist_2D_element::~ GALGAS_lbigintlist_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist_2D_element::GALGAS_lbigintlist_2D_element (const GALGAS_lbigint & inOperand0) :
mProperty_mValue (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist_2D_element GALGAS_lbigintlist_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lbigintlist_2D_element (GALGAS_lbigint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lbigintlist_2D_element GALGAS_lbigintlist_2D_element::constructor_new (const GALGAS_lbigint & in_mValue 
                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lbigintlist_2D_element result ;
  if (in_mValue.isValid ()) {
    result = GALGAS_lbigintlist_2D_element (in_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_lbigintlist_2D_element::objectCompare (const GALGAS_lbigintlist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mValue.objectCompare (inOperand.mProperty_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lbigintlist_2D_element::isValid (void) const {
  return mProperty_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigintlist_2D_element::drop (void) {
  mProperty_mValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lbigintlist_2D_element::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "<struct @lbigintlist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @2stringlist-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS__32_stringlist_2D_element ("2stringlist-element",
                                                  nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS__32_stringlist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS__32_stringlist_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS__32_stringlist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS__32_stringlist_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist_2D_element GALGAS__32_stringlist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS__32_stringlist_2D_element result ;
  const GALGAS__32_stringlist_2D_element * p = (const GALGAS__32_stringlist_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS__32_stringlist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("2stringlist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist_2D_element::GALGAS__32_stringlist_2D_element (void) :
mProperty_mValue_30_ (),
mProperty_mValue_31_ () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist_2D_element::~ GALGAS__32_stringlist_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist_2D_element::GALGAS__32_stringlist_2D_element (const GALGAS_string & inOperand0,
                                                                    const GALGAS_string & inOperand1) :
mProperty_mValue_30_ (inOperand0),
mProperty_mValue_31_ (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist_2D_element GALGAS__32_stringlist_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS__32_stringlist_2D_element (GALGAS_string::constructor_default (HERE),
                                           GALGAS_string::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_stringlist_2D_element GALGAS__32_stringlist_2D_element::constructor_new (const GALGAS_string & in_mValue0,
                                                                                    const GALGAS_string & in_mValue1 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS__32_stringlist_2D_element result ;
  if (in_mValue0.isValid () && in_mValue1.isValid ()) {
    result = GALGAS__32_stringlist_2D_element (in_mValue0, in_mValue1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS__32_stringlist_2D_element::objectCompare (const GALGAS__32_stringlist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mValue_30_.objectCompare (inOperand.mProperty_mValue_30_) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mValue_31_.objectCompare (inOperand.mProperty_mValue_31_) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS__32_stringlist_2D_element::isValid (void) const {
  return mProperty_mValue_30_.isValid () && mProperty_mValue_31_.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_stringlist_2D_element::drop (void) {
  mProperty_mValue_30_.drop () ;
  mProperty_mValue_31_.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_stringlist_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @2stringlist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mValue_30_.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mValue_31_.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @lstring generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstring ("lstring",
                                nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lstring::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstring ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lstring::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lstring (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_lstring::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
  const GALGAS_lstring * p = (const GALGAS_lstring *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lstring *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lstring", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring::GALGAS_lstring (void) :
mProperty_string (),
mProperty_location () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring::~ GALGAS_lstring (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring::GALGAS_lstring (const GALGAS_string & inOperand0,
                                const GALGAS_location & inOperand1) :
mProperty_string (inOperand0),
mProperty_location (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_lstring::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lstring (GALGAS_string::constructor_default (HERE),
                         GALGAS_location::constructor_nowhere (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_lstring::constructor_new (const GALGAS_string & in_string,
                                                const GALGAS_location & in_location 
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result ;
  if (in_string.isValid () && in_location.isValid ()) {
    result = GALGAS_lstring (in_string, in_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_lstring::objectCompare (const GALGAS_lstring & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_string.objectCompare (inOperand.mProperty_string) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lstring::isValid (void) const {
  return mProperty_string.isValid () && mProperty_location.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstring::drop (void) {
  mProperty_string.drop () ;
  mProperty_location.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstring::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "<struct @lstring:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_string.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_location.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @lsint generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lsint ("lsint",
                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lsint::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lsint ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lsint::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lsint (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint GALGAS_lsint::extractObject (const GALGAS_object & inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_lsint result ;
  const GALGAS_lsint * p = (const GALGAS_lsint *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lsint *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lsint", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint::GALGAS_lsint (void) :
mProperty_sint (),
mProperty_location () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint::~ GALGAS_lsint (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint::GALGAS_lsint (const GALGAS_sint & inOperand0,
                            const GALGAS_location & inOperand1) :
mProperty_sint (inOperand0),
mProperty_location (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint GALGAS_lsint::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lsint (GALGAS_sint::constructor_default (HERE),
                       GALGAS_location::constructor_nowhere (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint GALGAS_lsint::constructor_new (const GALGAS_sint & in_sint,
                                            const GALGAS_location & in_location 
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lsint result ;
  if (in_sint.isValid () && in_location.isValid ()) {
    result = GALGAS_lsint (in_sint, in_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_lsint::objectCompare (const GALGAS_lsint & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_sint.objectCompare (inOperand.mProperty_sint) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lsint::isValid (void) const {
  return mProperty_sint.isValid () && mProperty_location.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lsint::drop (void) {
  mProperty_sint.drop () ;
  mProperty_location.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lsint::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "<struct @lsint:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_sint.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_location.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @lstringlist-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstringlist_2D_element ("lstringlist-element",
                                               nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lstringlist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstringlist_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lstringlist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lstringlist_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist_2D_element GALGAS_lstringlist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_lstringlist_2D_element result ;
  const GALGAS_lstringlist_2D_element * p = (const GALGAS_lstringlist_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lstringlist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lstringlist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist_2D_element::GALGAS_lstringlist_2D_element (void) :
mProperty_mValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist_2D_element::~ GALGAS_lstringlist_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist_2D_element::GALGAS_lstringlist_2D_element (const GALGAS_lstring & inOperand0) :
mProperty_mValue (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist_2D_element GALGAS_lstringlist_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lstringlist_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist_2D_element GALGAS_lstringlist_2D_element::constructor_new (const GALGAS_lstring & in_mValue 
                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstringlist_2D_element result ;
  if (in_mValue.isValid ()) {
    result = GALGAS_lstringlist_2D_element (in_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_lstringlist_2D_element::objectCompare (const GALGAS_lstringlist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mValue.objectCompare (inOperand.mProperty_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lstringlist_2D_element::isValid (void) const {
  return mProperty_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringlist_2D_element::drop (void) {
  mProperty_mValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringlist_2D_element::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "<struct @lstringlist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @2lstringlist-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS__32_lstringlist_2D_element ("2lstringlist-element",
                                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS__32_lstringlist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS__32_lstringlist_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS__32_lstringlist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS__32_lstringlist_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element GALGAS__32_lstringlist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS__32_lstringlist_2D_element result ;
  const GALGAS__32_lstringlist_2D_element * p = (const GALGAS__32_lstringlist_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS__32_lstringlist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("2lstringlist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element::GALGAS__32_lstringlist_2D_element (void) :
mProperty_mValue_30_ (),
mProperty_mValue_31_ () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element::~ GALGAS__32_lstringlist_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element::GALGAS__32_lstringlist_2D_element (const GALGAS_lstring & inOperand0,
                                                                      const GALGAS_lstring & inOperand1) :
mProperty_mValue_30_ (inOperand0),
mProperty_mValue_31_ (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element GALGAS__32_lstringlist_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS__32_lstringlist_2D_element (GALGAS_lstring::constructor_default (HERE),
                                            GALGAS_lstring::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element GALGAS__32_lstringlist_2D_element::constructor_new (const GALGAS_lstring & in_mValue0,
                                                                                      const GALGAS_lstring & in_mValue1 
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS__32_lstringlist_2D_element result ;
  if (in_mValue0.isValid () && in_mValue1.isValid ()) {
    result = GALGAS__32_lstringlist_2D_element (in_mValue0, in_mValue1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS__32_lstringlist_2D_element::objectCompare (const GALGAS__32_lstringlist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mValue_30_.objectCompare (inOperand.mProperty_mValue_30_) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mValue_31_.objectCompare (inOperand.mProperty_mValue_31_) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS__32_lstringlist_2D_element::isValid (void) const {
  return mProperty_mValue_30_.isValid () && mProperty_mValue_31_.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist_2D_element::drop (void) {
  mProperty_mValue_30_.drop () ;
  mProperty_mValue_31_.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist_2D_element::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "<struct @2lstringlist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mValue_30_.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mValue_31_.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  AC_GALGAS_list : Base class for GALGAS list                                                                        *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2013 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"
#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_Compiler.h"

//---------------------------------------------------------------------------------------------------------------------*

class cSharedList : public C_SharedObject {
//--- Private data
  private : capCollectionElementArray mObjectArray ;

//--- Count
  public : inline uint32_t count (void) const { return mObjectArray.count () ; }

//--- Constructor
  public : cSharedList (LOCATION_ARGS) ;

//--- Internal methods
  protected : void description (C_String & ioString,
                                const int32_t inIndentation) const ;

  protected : void copyFrom (const cSharedList * inSource) ;

  protected : void populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                             const typeEnumerationOrder inEnumerationOrder) const ;

  protected : void readFirst (capCollectionElement & outObjectAttributeArray,
                              C_Compiler * inCompiler
                              COMMA_LOCATION_ARGS) ;

  protected : void readLast (capCollectionElement & outObjectAttributeArray,
                             C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

  protected : void subListWithRange (cSharedList * & ioSharedList,
                                     const GALGAS_range & inRange,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const ;

  protected : void subListFromIndex (cSharedList * & ioSharedList,
                                     const GALGAS_uint & inIndex,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const ;

  protected : void subListToIndex (cSharedList * & ioSharedList,
                                   const GALGAS_uint & inIndex,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) const ;

  protected : void prependAttributeArray (const capCollectionElement & inAttributeArray) ;

  protected : void appendList (const cSharedList * inListToAppend) ;

//--- Object handling
  private : void setCapacity (const uint32_t inNewCapacity) ;

  protected : void addObject (const capCollectionElement & inObjectArray) ;

  protected : void addObjectAtIndex (const capCollectionElement & inElementToAdd,
                                     const int32_t inInsertionIndex,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

  protected : void removeObjectAtIndex (capCollectionElement & outObjectAttributeArray,
                                        const uint32_t inRemoveIndex,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

  protected : void removeFirstObject (capCollectionElement & outObjectAttributeArray,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

  protected : void removeLastObject (capCollectionElement & outObjectAttributeArray,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

  protected : capCollectionElement readObjectAtIndex (const GALGAS_uint & inIndex,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

  protected : cCollectionElement * objectPointerAtIndex (const GALGAS_uint & inIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  protected : typeComparisonResult listCompare (const cSharedList * inOperand) const ;

//--- No copy
  private : cSharedList (const cSharedList &) ;
  private : cSharedList & operator = (const cSharedList &) ;

//--- Friends
  friend class AC_GALGAS_list ;
  friend class cSharedListMapRoot ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cSharedList::cSharedList (LOCATION_ARGS) :
C_SharedObject (THERE),
mObjectArray () {
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::setCapacity (const uint32_t inNewCapacity) {
  mObjectArray.setCapacity (inNewCapacity) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::addObject (const capCollectionElement & inObject) {
  macroUniqueSharedObject (this) ;
  mObjectArray.setCapacity (mObjectArray.count () + 1) ;
  mObjectArray.addObject (inObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::addObjectAtIndex (const capCollectionElement & inObject,
                                    const int32_t inInsertionIndex,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  mObjectArray.setCapacity (mObjectArray.count () + 1) ;
  mObjectArray.addObjectAtIndex (inObject, (uint32_t) inInsertionIndex, inCompiler COMMA_THERE) ;
}


//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::copyFrom (const cSharedList * inSource) {
  macroUniqueSharedObject (this) ;
  const uint32_t n = inSource->mObjectArray.count () ;
  mObjectArray.setCapacity (n) ;
  for (uint32_t i=0 ; i<n ; i++) {
    mObjectArray.addObject (inSource->mObjectArray.objectAtIndex (i COMMA_HERE)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

capCollectionElement cSharedList::readObjectAtIndex (const GALGAS_uint & inIndex,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement result ;
  if (inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx >= mObjectArray.count ()) {
      C_String s ;
      s << "Access with index " ;
      s << cStringWithUnsigned (idx) ;
      s << " >= count " ;
      s << cStringWithUnsigned (mObjectArray.count ()) ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      result = mObjectArray.objectAtIndex (idx COMMA_HERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cSharedList::objectPointerAtIndex (const GALGAS_uint & inIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  cCollectionElement * result = NULL ;
  if (inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx >= mObjectArray.count ()) {
      C_String s ;
      s << "Access with index " ;
      s << cStringWithUnsigned (idx) ;
      s << " >= count " ;
      s << cStringWithUnsigned (mObjectArray.count ()) ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      result = mObjectArray.pointerAtIndex (idx COMMA_HERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark removeObjectAtIndex
#endif

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::removeObjectAtIndex (capCollectionElement & outObjectAttributeArray,
                                       const uint32_t inRemoveIndex,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  if (mObjectArray.count () <= inRemoveIndex) {
    C_String message ;
    message << "'removeAtIndex' with index " << cStringWithUnsigned (inRemoveIndex) << " >= list length (" << cStringWithSigned (mObjectArray.count ()) << ")" ;
    inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
  }else{
    outObjectAttributeArray = mObjectArray.objectAtIndex (inRemoveIndex COMMA_HERE) ;
    mObjectArray.removeObjectAtIndex (inRemoveIndex) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::removeObjectAtIndex (capCollectionElement & outAttributes,
                                          const uint32_t inRemoveIndex,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  if (NULL != mSharedList) {
    insulateList (HERE) ;
    mSharedList->removeObjectAtIndex (outAttributes, inRemoveIndex, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark removeFirstObject
#endif

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::removeFirstObject (capCollectionElement & outObjectAttributeArray,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  if (mObjectArray.count () == 0) {
    inCompiler->onTheFlyRunTimeError ("call 'popFirst' on an empty list" COMMA_THERE) ;
  }else{
    outObjectAttributeArray = mObjectArray.objectAtIndex (0 COMMA_HERE) ;
    mObjectArray.removeObjectAtIndex (0) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::removeFirstObject (capCollectionElement & outAttributes,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (NULL != mSharedList) {
    insulateList (HERE) ;
    mSharedList->removeFirstObject (outAttributes, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark removeLastObject
#endif

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::removeLastObject (capCollectionElement & outObjectAttributeArray,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  macroUniqueSharedObject (this) ;
  if (mObjectArray.count () == 0) {
    inCompiler->onTheFlyRunTimeError ("call 'popLast' on an empty list" COMMA_THERE) ;
  }else{
    outObjectAttributeArray = mObjectArray.objectAtIndex (mObjectArray.count () - 1 COMMA_HERE) ;
    mObjectArray.removeObjectAtIndex (mObjectArray.count () - 1) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::removeLastObject (capCollectionElement & outAttributes,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  if (NULL != mSharedList) {
    insulateList (HERE) ;
    mSharedList->removeLastObject (outAttributes, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::readFirst (capCollectionElement & outObjectAttributeArray,
                             C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) {
  if (mObjectArray.count () == 0) {
    inCompiler->onTheFlyRunTimeError ("'first' method invoked on an empty list" COMMA_THERE) ;
  }else{
    outObjectAttributeArray = mObjectArray.objectAtIndex (0 COMMA_HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::readLast (capCollectionElement & outObjectAttributeArray,
                            C_Compiler * inCompiler
                            COMMA_LOCATION_ARGS) {
  if (mObjectArray.count () == 0) {
    inCompiler->onTheFlyRunTimeError ("'last' method invoked on an empty list" COMMA_THERE) ;
  }else{
    outObjectAttributeArray = mObjectArray.objectAtIndex (mObjectArray.count () - 1 COMMA_HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::subListWithRange (cSharedList * & ioSharedList,
                                    const GALGAS_range & inRange,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  bool ok = true ;
  if (inRange.isValid ()) {
    const uint32_t idx = inRange.mAttribute_start.uintValue () ;
    const uint32_t length = inRange.mAttribute_length.uintValue () ;
    if ((idx + length) > mObjectArray.count ()) {
      C_String s ;
      s << "Cannot get a sub list of range ["
        << cStringWithUnsigned (idx)
        << ":"
        << cStringWithUnsigned (length)
        << "] from a list of length "
        << cStringWithUnsigned (mObjectArray.count ()) ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
      ok = false ;
    }else{
      ioSharedList->mObjectArray.setCapacity (length) ;
      for (uint32_t i=0 ; i<length ; i++) {
        ioSharedList->mObjectArray.addObject (mObjectArray.objectAtIndex (idx + i COMMA_HERE)) ;
      }
    }
  }
  if (! ok) {
    macroDetachSharedObject (ioSharedList) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::subListFromIndex (cSharedList * & ioSharedList,
                                    const GALGAS_uint & inIndex,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  bool ok = true ;
  if (inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx > mObjectArray.count ()) {
      C_String s ;
      s << "Cannot get a sub list from index "
        << cStringWithUnsigned (idx)
        << " with a list of length "
        << cStringWithUnsigned (mObjectArray.count ()) ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
      ok = false ;
    }else{
      const uint32_t length = mObjectArray.count () - idx ;
      ioSharedList->mObjectArray.setCapacity (length) ;
      for (uint32_t i=0 ; i<length ; i++) {
        ioSharedList->mObjectArray.addObject (mObjectArray.objectAtIndex (idx + i COMMA_HERE)) ;
      }
    }
  }
  if (! ok) {
    macroDetachSharedObject (ioSharedList) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::subListToIndex (cSharedList * & ioSharedList,
                                  const GALGAS_uint & inIndex,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) const {
  bool ok = true ;
  if (inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx >= mObjectArray.count ()) {
      C_String s ;
      s << "Cannot get a sub list from index "
        << cStringWithUnsigned (idx)
        << " with a list of length "
        << cStringWithUnsigned (mObjectArray.count ()) ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
      ok = false ;
    }else{
      const uint32_t length = idx + 1;
      ioSharedList->mObjectArray.setCapacity (length) ;
      for (uint32_t i=0 ; i<length ; i++) {
        ioSharedList->mObjectArray.addObject (mObjectArray.objectAtIndex (i COMMA_HERE)) ;
      }
    }
  }
  if (! ok) {
    macroDetachSharedObject (ioSharedList) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::prependAttributeArray (const capCollectionElement & inAttributeArray) {
  macroUniqueSharedObject (this) ;
  setCapacity (mObjectArray.count () + 1) ;
  mObjectArray.predendObject (inAttributeArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::appendList (const cSharedList * inListToAppend) {
  macroUniqueSharedObject (this) ;
  if (NULL != inListToAppend) {
    setCapacity (mObjectArray.count () + inListToAppend->count ()) ;
    for (uint32_t i=0 ; i<inListToAppend->count () ; i++) {
      mObjectArray.addObject (inListToAppend->mObjectArray.objectAtIndex (i COMMA_HERE)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                            const typeEnumerationOrder inEnumerationOrder) const {
  inEnumerationArray.setCapacity (mObjectArray.count ()) ;
  switch (enumerationOrderValue (inEnumerationOrder)) {
  case kENUMERATION_UP  :
    for (uint32_t i=0 ; i<mObjectArray.count () ; i++) {
      inEnumerationArray.addObject (mObjectArray.objectAtIndex (i COMMA_HERE)) ;
    }
    break ;
  case kENUMERATION_DOWN :
    for (uint32_t i=mObjectArray.count () ; i>0 ; i--) {
      inEnumerationArray.addObject (mObjectArray.objectAtIndex (i - 1 COMMA_HERE)) ;
    }
    break ;
  case kENUMERATION_ENTER_ORDER :
  case kENUMERATION_REVERSE_ENTER_ORDER :
    MF_RunTimeError ("invalid inEnumerationOrder %lld", enumerationOrderValue (inEnumerationOrder), 0) ;
//    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::makeNewSharedList (cSharedList * & outSharedList
                                   COMMA_LOCATION_ARGS) {
  macroMyNew (outSharedList, cSharedList (THERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::insertInSharedList (cSharedList * inSharedList,
                                         const capCollectionElement & inAttributes) {
  macroValidSharedObject (inSharedList, cSharedList) ;
  inSharedList->addObject (inAttributes) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::detachSharedList (cSharedList * & ioSharedList) {
  macroDetachSharedObject (ioSharedList) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//    AC_GALGAS_list                                                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_list::AC_GALGAS_list (void) :
AC_GALGAS_root (),
mSharedList (NULL) {
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_list::AC_GALGAS_list (cSharedList * inSharedListPtr) :
AC_GALGAS_root (),
mSharedList (NULL) {
  macroAssignSharedObject (mSharedList, inSharedListPtr) ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_list::~ AC_GALGAS_list (void) {
  macroDetachSharedObject (mSharedList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_list::AC_GALGAS_list (const AC_GALGAS_list & inSource) :
AC_GALGAS_root (),
mSharedList (NULL) {
  macroAssignSharedObject (mSharedList, inSource.mSharedList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_list & AC_GALGAS_list::operator = (const AC_GALGAS_list & inSource) {
  macroAssignSharedObject (mSharedList, inSource.mSharedList) ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::createNewEmptyList (LOCATION_ARGS) {
  macroMyNew (mSharedList, cSharedList (THERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedList::description (C_String & ioString,
                               const int32_t inIndentation) const {
  ioString << " ("
           << cStringWithUnsigned (mObjectArray.count ())
           << " object" << ((mObjectArray.count () > 1) ? "s" : "")
           << "): " ;
  for (uint32_t i=0 ; i<mObjectArray.count () ; i++) {
    ioString << "\n" ;
    ioString.writeStringMultiple ("| ", inIndentation) ;
    ioString << "|-at " << cStringWithUnsigned (i) ;
    mObjectArray.objectAtIndex (i COMMA_HERE).description (ioString, inIndentation + 2) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "<list @"
           << staticTypeDescriptor ()->mGalgasTypeName ;
  if (isValid ()) {
    mSharedList->description (ioString, inIndentation) ;
  }else{
    ioString << " not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                               const typeEnumerationOrder inEnumerationOrder) const {
  if (isValid ()) {
    mSharedList->populateEnumerationArray (inEnumerationArray, inEnumerationOrder) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t AC_GALGAS_list::count () const {
  uint32_t result = 0 ;
  if (isValid ()) {
    result = mSharedList->count () ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint AC_GALGAS_list::getter_length (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mSharedList->count ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_range AC_GALGAS_list::getter_range (UNUSED_LOCATION_ARGS) const {
  GALGAS_range result ;
  if (isValid ()) {
    result = GALGAS_range (GALGAS_uint (0), GALGAS_uint (mSharedList->count ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::drop (void) {
  macroDetachSharedObject (mSharedList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::insulateList (LOCATION_ARGS) {
  if ((mSharedList != NULL) && (mSharedList->retainCount () > 1)) {
    cSharedList * p = NULL ;
    macroMyNew (p, cSharedList (THERE)) ;
    p->copyFrom (mSharedList) ;
    macroAssignSharedObject (mSharedList, p) ;
    macroDetachSharedObject (p) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::addObject (const capCollectionElement & inElementToAdd) {
  insulateList (HERE) ;
  if (NULL != mSharedList) {
    mSharedList->addObject (inElementToAdd) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::addObjectAtIndex (const capCollectionElement & inElementToAdd,
                                       const uint32_t inInsertionIndex,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  insulateList (HERE) ;
  if (NULL != mSharedList) {
    mSharedList->addObjectAtIndex (inElementToAdd, (int32_t) inInsertionIndex, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::readFirst (capCollectionElement & outAttributes,
                                C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) const {
  if (NULL != mSharedList) {
    mSharedList->readFirst (outAttributes, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::readLast (capCollectionElement & outAttributes,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) const {
  if (NULL != mSharedList) {
    mSharedList->readLast (outAttributes, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::subListWithRange (AC_GALGAS_list & outList,
                                       const GALGAS_range & inRange,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  if (isValid ()) {
    mSharedList->subListWithRange (outList.mSharedList, inRange, inCompiler COMMA_THERE) ;
  }else{
    outList.drop () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::subListFromIndex (AC_GALGAS_list & outList,
                                       const GALGAS_uint & inIndex,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  if (isValid ()) {
    mSharedList->subListFromIndex (outList.mSharedList, inIndex, inCompiler COMMA_THERE) ;
  }else{
    outList.drop () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::subListToIndex (AC_GALGAS_list & outList,
                                     const GALGAS_uint & inIndex,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  if (isValid ()) {
    mSharedList->subListToIndex (outList.mSharedList, inIndex, inCompiler COMMA_THERE) ;
  }else{
    outList.drop () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_list::appendList (const AC_GALGAS_list & inList) {
  if (NULL != mSharedList) {
    insulateList (HERE) ;
    mSharedList->appendList (inList.mSharedList) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

capCollectionElement AC_GALGAS_list::readObjectAtIndex (const GALGAS_uint & inIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement result ;
  if (isValid ()) {
    result = mSharedList->readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * AC_GALGAS_list::objectPointerAtIndex (const GALGAS_uint & inIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement * result = NULL ;
  if (isValid ()) {
    insulateList (HERE) ;
    if (NULL != mSharedList) {
      result = mSharedList->objectPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Object Compare
#endif

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cSharedList::listCompare (const cSharedList * inOperand) const {
  typeComparisonResult r = kOperandEqual ;
  if (count () < inOperand->count ()) {
    r = kFirstOperandLowerThanSecond ;
  }else if (count () > inOperand->count ()) {
    r = kFirstOperandGreaterThanSecond ;
  }else{
    capCollectionElementArray array ; populateEnumerationArray (array, kEnumeration_up) ;
    capCollectionElementArray operandArray ; inOperand->populateEnumerationArray (operandArray, kEnumeration_up) ;
    for (uint32_t i=0 ; (i<array.count ()) && (kOperandEqual == r) ; i++) {
      const capCollectionElement leftObject = array.objectAtIndex (i COMMA_HERE) ;
      const capCollectionElement rightObject = operandArray.objectAtIndex (i COMMA_HERE) ;
      r = leftObject.compare (rightObject) ;
    }
  }
  return r ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult AC_GALGAS_list::objectCompare (const AC_GALGAS_list & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    result = mSharedList->listCompare (inOperand.mSharedList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  c L i s t M a p N o d e                                                                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cListMapNode {
  public : cListMapNode * mInfPtr ;
  public : cListMapNode * mSupPtr ;
  public : int32_t mBalance ;
  public : C_String mKey ;
  public : cSharedList * mSharedList ;

//--- Constructors
  public : cListMapNode (const C_String & inKey) ;
  public : cListMapNode (const cListMapNode * inNode) ;

//--- Destructor
  public : virtual ~ cListMapNode (void) ;

//--- No copy
  private : cListMapNode (const cListMapNode &) ;
  private : cListMapNode & operator = (const cListMapNode &) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cListMapNode::cListMapNode (const C_String & inKey) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (0),
mKey (inKey),
mSharedList (NULL) {
  macroMyNew (mSharedList, cSharedList (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

cListMapNode::~ cListMapNode (void) {
  macroMyDelete (mInfPtr) ;
  macroMyDelete (mSupPtr) ;
  macroDetachSharedObject (mSharedList) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  c L i s t M a p N o d e                                                                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cSharedListMapRoot : public C_SharedObject {
//--- Attributes
  private : cListMapNode * mRoot ;
  public : const cListMapNode * root (void) const { return mRoot ; }
  private : uint32_t mCount ;

//--- Default constructor
  public : cSharedListMapRoot (LOCATION_ARGS) ;

//--- Destructor
  public : virtual ~ cSharedListMapRoot (void) ;

//--- No copy
  private : cSharedListMapRoot (const cSharedListMapRoot &) ;
  private : cSharedListMapRoot & operator = (const cSharedListMapRoot &) ;

//--- Copy from
  public : VIRTUAL_IN_DEBUG void copyFrom (const cSharedListMapRoot * inSource) ;

//--- Count
  public : VIRTUAL_IN_DEBUG uint32_t count (void) const { return mCount ; }

//--- Description
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;

  public : static void internalDescription (cListMapNode * inNode,
                                            C_String & ioString,
                                            const int32_t inIndentation,
                                            uint32_t & ioIdx) ;
//--- Find or add entry
  public : VIRTUAL_IN_DEBUG void findOrAddEntry (cListMapNode * & ioRootPtr,
                                                 const C_String & inKey,
                                                 cListMapNode * & outEntry,
                                                 bool & ioExtension) ;

  public : VIRTUAL_IN_DEBUG void addObjectInListMap (const C_String & inKey,
                                                     capCollectionElement & inAttributeArray) ;

//--------------------------------- Support for 'listForKey' reader
  public : VIRTUAL_IN_DEBUG cSharedList * listForKey (const C_String & inKey) const ;

//--------------------------------- Support for enumeration
  public : VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & ioEnumerationArray,
                                                           const typeEnumerationOrder inEnumerationOrder) const ;
//--------------------------------- Comparison
  public : typeComparisonResult listmapCompare (const cSharedListMapRoot * inOperand) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cSharedListMapRoot::cSharedListMapRoot (LOCATION_ARGS) :
C_SharedObject (THERE),
mRoot (NULL),
mCount (0) {
}

//---------------------------------------------------------------------------------------------------------------------*

cSharedListMapRoot::~cSharedListMapRoot (void) {
  macroMyDelete (mRoot) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark AC_GALGAS_listmap
#endif

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_listmap::AC_GALGAS_listmap (void) :
AC_GALGAS_root (),
mSharedListMap (NULL) {
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_listmap::~ AC_GALGAS_listmap (void) {
  macroDetachSharedObject (mSharedListMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_listmap::drop (void) {
  macroDetachSharedObject (mSharedListMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_listmap::AC_GALGAS_listmap (const AC_GALGAS_listmap & inSource) :
AC_GALGAS_root (),
mSharedListMap (NULL) {
  macroAssignSharedObject (mSharedListMap, inSource.mSharedListMap) ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_listmap & AC_GALGAS_listmap::operator = (const AC_GALGAS_listmap & inSource) {
  macroAssignSharedObject (mSharedListMap, inSource.mSharedListMap) ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t AC_GALGAS_listmap::count (void) const {
  uint32_t result = 0 ;
  if (NULL != mSharedListMap) {
    result = mSharedListMap->count () ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint AC_GALGAS_listmap::getter_count (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint (count ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark reader allKeys
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void enterAllKeys (const cListMapNode * inNode, GALGAS_stringset & ioResult) {
  if (inNode != NULL) {
    enterAllKeys (inNode->mInfPtr, ioResult) ;
    ioResult.addAssign_operation (GALGAS_string (inNode->mKey) COMMA_HERE) ;
    enterAllKeys (inNode->mSupPtr, ioResult) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset AC_GALGAS_listmap::getter_allKeys (LOCATION_ARGS) const {
  GALGAS_stringset result ;
  if (isValid ()) {
    result = GALGAS_stringset::constructor_emptySet (THERE) ;
    enterAllKeys (mSharedListMap->root (), result) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void enterKeyList (const cListMapNode * inNode, GALGAS_stringlist & ioResult) {
  if (inNode != NULL) {
    enterKeyList (inNode->mInfPtr, ioResult) ;
    ioResult.addAssign_operation (GALGAS_string (inNode->mKey) COMMA_HERE) ;
    enterKeyList (inNode->mSupPtr, ioResult) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist AC_GALGAS_listmap::getter_keyList (LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (isValid ()) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    enterKeyList (mSharedListMap->root (), result) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Object Compare
#endif

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cSharedListMapRoot::listmapCompare (const cSharedListMapRoot * inOperand) const {
  typeComparisonResult result = kOperandEqual ;
  if (count () < inOperand->count ()) {
    result = kFirstOperandLowerThanSecond ;
  }else if (count () > inOperand->count ()) {
    result = kFirstOperandGreaterThanSecond ;
  }else{
    capCollectionElementArray array ; populateEnumerationArray (array, kEnumeration_up) ;
    capCollectionElementArray operandArray ; inOperand->populateEnumerationArray (operandArray, kEnumeration_up) ;
    for (uint32_t i=0 ; (i<array.count ()) && (kOperandEqual == result) ; i++) {
      result = array.objectAtIndex (i COMMA_HERE).compare (operandArray.objectAtIndex (i COMMA_HERE)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult AC_GALGAS_listmap::objectCompare (const AC_GALGAS_listmap & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    result = mSharedListMap->listmapCompare (inOperand.mSharedListMap) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Description
#endif

//---------------------------------------------------------------------------------------------------------------------*

void cSharedListMapRoot::internalDescription (cListMapNode * inNode,
                                              C_String & ioString,
                                              const int32_t inIndentation,
                                              uint32_t & ioIdx) {
  if (NULL != inNode) {
    internalDescription (inNode->mInfPtr, ioString, inIndentation, ioIdx) ;
    ioString << "\n" ;
    ioString.writeStringMultiple ("| ", inIndentation) ;
    ioString << "|-at " << cStringWithUnsigned (ioIdx)
             << ": key '" << inNode->mKey << "' " ;
    inNode->mSharedList->description (ioString, inIndentation + 1) ;
    ioIdx ++ ;
    internalDescription (inNode->mSupPtr, ioString, inIndentation, ioIdx) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedListMapRoot::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << " ("
           << cStringWithUnsigned (count ())
           << " object" << ((count () > 1) ? "s" : "")
           << "): " ;
  uint32_t idx = 0 ;
  internalDescription (mRoot, ioString, inIndentation, idx) ;
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_listmap::description (C_String & ioString,
                                     const int32_t inIndentation) const {
  ioString << "<@" << staticTypeDescriptor ()->mGalgasTypeName << ": " ;
  if (isValid ()) {
    mSharedListMap->description (ioString, inIndentation) ;
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark List map Node
#endif

//---------------------------------------------------------------------------------------------------------------------*

cListMapNode::cListMapNode (const cListMapNode * inNode) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (0),
mKey (),
mSharedList (NULL) {
  macroValidPointer (inNode) ;
  if (inNode->mInfPtr != NULL) {
    macroMyNew (mInfPtr, cListMapNode (inNode->mInfPtr)) ;
  }
  if (inNode->mSupPtr != NULL) {
    macroMyNew (mSupPtr, cListMapNode (inNode->mSupPtr)) ;
  }
  mKey = inNode->mKey ;
  mBalance = inNode->mBalance ;
  macroAssignSharedObject (mSharedList, inNode->mSharedList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedListMapRoot::copyFrom (const cSharedListMapRoot * inSource) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    // inSource->checkMap (HERE) ;
  #endif
  macroValidSharedObject (inSource, cSharedListMapRoot) ;
  mCount = inSource->mCount ;
  if (NULL != inSource->mRoot) {
    macroMyNew (mRoot, cListMapNode (inSource->mRoot)) ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    // checkMap (HERE) ;
  #endif
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_listmap::insulateListMap (LOCATION_ARGS) {
  if ((mSharedListMap != NULL) && (mSharedListMap->retainCount () > 1)) {
    cSharedListMapRoot * p = NULL ;
    macroMyNew (p, cSharedListMapRoot (THERE)) ;
    p->copyFrom (mSharedListMap) ;
    macroAssignSharedObject (mSharedListMap, p) ;
    macroDetachSharedObject (p) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Create a new list map
#endif

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_listmap::makeNewEmptyListMap (LOCATION_ARGS) {
  macroMyNew (mSharedListMap, cSharedListMapRoot (THERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Adding an object
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void rotateLeft (cListMapNode * & ioRootPtr) {
  cListMapNode * b = ioRootPtr->mSupPtr ;
  ioRootPtr->mSupPtr = b->mInfPtr ;
  b->mInfPtr = ioRootPtr;

  if (b->mBalance >= 0) {
    ioRootPtr->mBalance++ ;
  }else{
    ioRootPtr->mBalance += 1 - b->mBalance ;
  }

  if (ioRootPtr->mBalance > 0) {
    b->mBalance += ioRootPtr->mBalance + 1 ;
  }else{
    b->mBalance++ ;
  }
  ioRootPtr = b ;
}

//---------------------------------------------------------------------

static void rotateRight (cListMapNode * & ioRootPtr) {
  cListMapNode * b = ioRootPtr->mInfPtr ;
  ioRootPtr->mInfPtr = b->mSupPtr ;
  b->mSupPtr = ioRootPtr ;

  if (b->mBalance > 0) {
    ioRootPtr->mBalance += -b->mBalance - 1 ;
  }else{
    ioRootPtr->mBalance-- ;
  }
  if (ioRootPtr->mBalance >= 0) {
    b->mBalance-- ;
  }else{
    b->mBalance += ioRootPtr->mBalance - 1 ;
  }
  ioRootPtr = b ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedListMapRoot::findOrAddEntry (cListMapNode * & ioRootPtr,
                                         const C_String & inKey,
                                         cListMapNode * & outEntry,
                                         bool & ioExtension) {
  if (ioRootPtr == NULL) {
    macroMyNew (ioRootPtr, cListMapNode (inKey)) ;
    outEntry = ioRootPtr ;
    mCount ++ ;
    ioExtension = true ;
  }else{
    macroValidPointer (ioRootPtr) ;
    const int32_t comparaison = ioRootPtr->mKey.compare (inKey) ;
    if (comparaison > 0) {
      findOrAddEntry (ioRootPtr->mInfPtr, inKey, outEntry, ioExtension) ;
      if (ioExtension) {
        ioRootPtr->mBalance++;
        if (ioRootPtr->mBalance == 0) {
          ioExtension = false;
        }else if (ioRootPtr->mBalance == 2) {
          if (ioRootPtr->mInfPtr->mBalance == -1) {
            rotateLeft (ioRootPtr->mInfPtr) ;
          }
          rotateRight (ioRootPtr) ;
          ioExtension = false;
        }
      }
    }else if (comparaison < 0) {
      findOrAddEntry (ioRootPtr->mSupPtr, inKey, outEntry, ioExtension) ;
      if (ioExtension) {
        ioRootPtr->mBalance-- ;
        if (ioRootPtr->mBalance == 0) {
          ioExtension = false ;
        }else if (ioRootPtr->mBalance == -2) {
          if (ioRootPtr->mSupPtr->mBalance == 1) {
            rotateRight (ioRootPtr->mSupPtr) ;
          }
          rotateLeft (ioRootPtr) ;
          ioExtension = false;
        }
      }
    }else{
      ioExtension = false ; // Found
      outEntry = ioRootPtr ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedListMapRoot::addObjectInListMap (const C_String & inKey,
                                             capCollectionElement & inAttributeArray) {
  macroUniqueSharedObject (this) ;
  cListMapNode * entry = NULL ;
  bool extension = false ; // Unused
  findOrAddEntry (mRoot, inKey, entry, extension) ;
  macroValidPointer (entry) ;
  macroValidSharedObject (entry->mSharedList, cSharedList) ;
//--- Insulate list ?
  if (entry->mSharedList->retainCount () > 1) {
    cSharedList * p = NULL ;
    macroMyNew (p, cSharedList (HERE)) ;
    p->copyFrom (entry->mSharedList) ;
    macroAssignSharedObject (entry->mSharedList, p) ;
    macroDetachSharedObject (p) ;
  }
//--- Add entry
  entry->mSharedList->addObject (inAttributeArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_listmap::addObjectInListMap (const GALGAS_string & inKey,
                                            capCollectionElement & inAttributeArray) {
  if (isValid () && inKey.isValid ()) {
    insulateListMap (HERE) ;
    if (NULL != mSharedListMap) {
      mSharedListMap->addObjectInListMap (inKey.stringValue (), inAttributeArray) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark listForKey support
#endif

//---------------------------------------------------------------------------------------------------------------------*

cSharedList * cSharedListMapRoot::listForKey (const C_String & inKey) const {
  cSharedList * result = NULL ;
  const cListMapNode * p = mRoot ;
  while ((p != NULL) && (NULL == result)) {
    const int32_t comparaison = p->mKey.compare (inKey) ;
    if (comparaison > 0) {
      p = p->mInfPtr ;
    }else if (comparaison < 0) {
      p = p->mSupPtr ;
    }else{
      result = p->mSharedList ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cSharedList * AC_GALGAS_listmap::listForKey (const GALGAS_string & inKey) const {
  cSharedList * result = NULL ;
  if (isValid () && inKey.isValid ()) {
    result = mSharedListMap->listForKey (inKey.stringValue ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cListMapElement
#endif

//---------------------------------------------------------------------------------------------------------------------*

cListMapElement::cListMapElement (const C_String & inKey,
                                  cSharedList * inSharedList
                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mKey (inKey),
mSharedListMapList (NULL) {
  macroAssignSharedObject (mSharedListMapList, inSharedList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

cListMapElement::~ cListMapElement (void) {
  macroDetachSharedObject (mSharedListMapList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool cListMapElement::isValid (void) const {
  return true ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cListMapElement::compare (const cCollectionElement * /* inOperand */) const {
  return kOperandNotValid ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cListMapElement::copy (void) {
  return NULL ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cListMapElement::description (C_String & /* ioString */,
                                   const int32_t /* inIndentation */) const {
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark listmap cEnumerator
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                 'GALGAS_stringset::cEnumerator' class                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static void enterAscendingEnumeration (const cListMapNode * inNode,
                                       capCollectionElementArray & ioEnumerationArray) {
  if (inNode != NULL) {
    enterAscendingEnumeration (inNode->mInfPtr, ioEnumerationArray) ;
    cListMapElement * p = NULL ;
    macroMyNew (p, cListMapElement (inNode->mKey, inNode->mSharedList COMMA_HERE)) ;
    capCollectionElement element ;
    element.setPointer (p) ;
    macroDetachSharedObject (p) ;
    ioEnumerationArray.addObject (element) ;
    enterAscendingEnumeration (inNode->mSupPtr, ioEnumerationArray) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void enterDescendingEnumeration (const cListMapNode * inNode,
                                        capCollectionElementArray & ioEnumerationArray) {
  if (inNode != NULL) {
    enterDescendingEnumeration (inNode->mSupPtr, ioEnumerationArray) ;
    cListMapElement * p = NULL ;
    macroMyNew (p, cListMapElement (inNode->mKey, inNode->mSharedList COMMA_HERE)) ;
    capCollectionElement element ;
    element.setPointer (p) ;
    macroDetachSharedObject (p) ;
    ioEnumerationArray.addObject (element) ;
    enterDescendingEnumeration (inNode->mInfPtr, ioEnumerationArray) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cSharedListMapRoot::populateEnumerationArray (capCollectionElementArray & ioEnumerationArray,
                                                   const typeEnumerationOrder inEnumerationOrder) const {
  // printf ("MAP COUNT %u\n", count ()) ;
  ioEnumerationArray.setCapacity (mCount) ;
  switch (enumerationOrderValue (inEnumerationOrder)) {
  case kENUMERATION_UP  :
    enterAscendingEnumeration (mRoot, ioEnumerationArray) ;
    break ;
  case kENUMERATION_DOWN :
    enterDescendingEnumeration (mRoot, ioEnumerationArray) ;
    break ;
  case kENUMERATION_ENTER_ORDER :
  case kENUMERATION_REVERSE_ENTER_ORDER :
    MF_RunTimeError ("invalid inEnumerationOrder %lld", enumerationOrderValue (inEnumerationOrder), 0) ;
//    break ;
  }
  MF_Assert (mCount == ioEnumerationArray.count (), "mCount (%lld) != ioEnumerationArray.count () (%lld)", mCount, ioEnumerationArray.count ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void AC_GALGAS_listmap::populateEnumerationArray (capCollectionElementArray & ioEnumerationArray,
                                                  const typeEnumerationOrder inEnumerationOrder) const {
  if (isValid ()) {
    mSharedListMap->populateEnumerationArray (ioEnumerationArray, inEnumerationOrder) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

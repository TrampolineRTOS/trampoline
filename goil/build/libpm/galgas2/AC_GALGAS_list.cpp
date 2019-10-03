//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  AC_GALGAS_list : Base class for GALGAS list                                                                        *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2016 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@ec-nantes.fr                                                                              *
//                                                                                                                     *
//  LS2N, Laboratoire des Sciences du Numérique de Nantes, ECN, École Centrale de Nantes (France)                      *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-predefined-types.h"
#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_Compiler.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark removeObjectAtIndex
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::removeObjectAtIndex (capCollectionElement & outAttributes,
                                              const uint32_t inRemoveIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  mSharedArray.removeObjectAtIndex (outAttributes, inRemoveIndex, inCompiler COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark removeFirstObject
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::removeFirstObject (capCollectionElement & outAttributes,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  mSharedArray.removeFirstObject (outAttributes, inCompiler COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark removeLastObject
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::removeLastObject (capCollectionElement & outAttributes,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  mSharedArray.removeLastObject (outAttributes, inCompiler COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//    AC_GALGAS_list                                                                                                   *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_list::AC_GALGAS_list (void) :
AC_GALGAS_root (),
mSharedArray (),
mIsValid (false) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_list::AC_GALGAS_list (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_root (),
mSharedArray (inSharedArray),
mIsValid (true) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_list::~ AC_GALGAS_list (void) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "<list @" << staticTypeDescriptor ()->mGalgasTypeName
           << " (" << cStringWithUnsigned (count()) << " object"
           << ((count() > 1) ? "s" : "") << "):" ;
  if (isValid ()) {
    mSharedArray.description (ioString, inIndentation) ;
  }else{
    ioString << " not built" ;
  }
  ioString << ">" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::populateEnumerationArray (capCollectionElementArray & outEnumerationArray) const {
  if (isValid ()) {
    outEnumerationArray = mSharedArray ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

uint32_t AC_GALGAS_list::count () const {
  uint32_t result = 0 ;
  if (isValid ()) {
    result = mSharedArray.count () ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint AC_GALGAS_list::getter_length (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mSharedArray.count ()) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_range AC_GALGAS_list::getter_range (UNUSED_LOCATION_ARGS) const {
  GALGAS_range result ;
  if (isValid ()) {
    result = GALGAS_range (GALGAS_uint (0), GALGAS_uint (mSharedArray.count ())) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::drop (void) {
  mIsValid = false ;
  mSharedArray.removeAllObjects () ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::appendObject (const capCollectionElement & inElementToAdd) {
  mSharedArray.appendObject (inElementToAdd) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::insertObjectAtIndex (const capCollectionElement & inElementToAdd,
                                              const uint32_t inInsertionIndex,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  mSharedArray.insertObjectAtIndex (inElementToAdd, inInsertionIndex, inCompiler COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::readFirst (capCollectionElement & outAttributes,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  mSharedArray.readFirstObject (outAttributes, inCompiler COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::readLast (capCollectionElement & outAttributes,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) const {
  mSharedArray.readLastObject (outAttributes, inCompiler COMMA_THERE) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::subListWithRange (AC_GALGAS_list & outList,
                                           const GALGAS_range & inRange,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  if (isValid () && inRange.isValid ()) {
    bool ok = false ;
    mSharedArray.subListWithRange (outList.mSharedArray,
                                   inRange.mProperty_start.uintValue (),
                                   inRange.mProperty_length.uintValue (),
                                   ok,
                                   inCompiler COMMA_THERE) ;
    outList.mIsValid = ok ;
  }else{
    outList.drop () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::subListFromIndex (AC_GALGAS_list & outList,
                                           const GALGAS_uint & inIndex,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  if (isValid () && inIndex.isValid ()) {
    bool ok = false ;
    mSharedArray.subListFromIndex (outList.mSharedArray, inIndex.uintValue (), ok, inCompiler COMMA_THERE) ;
    outList.mIsValid = ok ;
  }else{
    outList.drop () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::subListToIndex (AC_GALGAS_list & outList,
                                         const GALGAS_uint & inIndex,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  if (isValid () && inIndex.isValid ()) {
    bool ok = false ;
    mSharedArray.subListToIndex (outList.mSharedArray, inIndex.uintValue (), ok, inCompiler COMMA_THERE) ;
    outList.mIsValid = ok ;
  }else{
    outList.drop () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_list::appendList (const AC_GALGAS_list & inList) {
  if (isValid () && inList.isValid ()) {
    mSharedArray.appendObjects (inList.mSharedArray) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

capCollectionElement AC_GALGAS_list::readObjectAtIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t index = inIndex.uintValue () ;
    if (index < mSharedArray.count ()) {
      result = mSharedArray.objectAtIndex (index COMMA_THERE) ;
    }else{
      C_String s = "objectAtIndex: index (" ;
      s << cStringWithUnsigned (index) << ") >= length (" << cStringWithUnsigned (count ()) << ")" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cCollectionElement * AC_GALGAS_list::uniquelyReferencedPointerAtIndex (const GALGAS_uint & inIndex,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement * result = NULL ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t index = inIndex.uintValue () ;
    if (index < mSharedArray.count ()) {
      result = mSharedArray.uniquelyReferencedPointerAtIndex (index COMMA_THERE) ;
      macroUniqueSharedObject (result) ;
    }else{
      C_String s = "objectAtIndex: index (" ;
      s << cStringWithUnsigned (index) << ") >= length (" << cStringWithUnsigned (count ()) << ")" ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Object Compare
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult AC_GALGAS_list::objectCompare (const AC_GALGAS_list & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    result = mSharedArray.compareCollectionElementArray (inOperand.mSharedArray) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  c L i s t M a p N o d e                                                                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cListMapNode {
  public : cListMapNode * mInfPtr ;
  public : cListMapNode * mSupPtr ;
  public : int32_t mBalance ;
  public : C_String mKey ;
  public : capCollectionElementArray myList ;

//--- Constructors
  public : cListMapNode (const C_String & inKey) ;
  public : cListMapNode (const cListMapNode * inNode) ;

//--- Destructor
  public : virtual ~ cListMapNode (void) ;

//--- No copy
  private : cListMapNode (const cListMapNode &) ;
  private : cListMapNode & operator = (const cListMapNode &) ;
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cListMapNode::cListMapNode (const C_String & inKey) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (0),
mKey (inKey),
myList () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cListMapNode::~ cListMapNode (void) {
  macroMyDelete (mInfPtr) ;
  macroMyDelete (mSupPtr) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  cSharedListMapRoot                                                                                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

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
  public : VIRTUAL_IN_DEBUG capCollectionElementArray listForKey (const C_String & inKey) const ;

//--------------------------------- Support for enumeration
  public : VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & ioEnumerationArray) const ;
//--------------------------------- Comparison
  public : typeComparisonResult listmapCompare (const cSharedListMapRoot * inOperand) const ;
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cSharedListMapRoot::cSharedListMapRoot (LOCATION_ARGS) :
C_SharedObject (THERE),
mRoot (NULL),
mCount (0) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cSharedListMapRoot::~cSharedListMapRoot (void) {
  macroMyDelete (mRoot) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark AC_GALGAS_listmap
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_listmap::AC_GALGAS_listmap (void) :
AC_GALGAS_root (),
mSharedListMap (NULL) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_listmap::~ AC_GALGAS_listmap (void) {
  macroDetachSharedObject (mSharedListMap) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_listmap::drop (void) {
  macroDetachSharedObject (mSharedListMap) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_listmap::AC_GALGAS_listmap (const AC_GALGAS_listmap & inSource) :
AC_GALGAS_root (),
mSharedListMap (NULL) {
  macroAssignSharedObject (mSharedListMap, inSource.mSharedListMap) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_GALGAS_listmap & AC_GALGAS_listmap::operator = (const AC_GALGAS_listmap & inSource) {
  macroAssignSharedObject (mSharedListMap, inSource.mSharedListMap) ;
  return * this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

uint32_t AC_GALGAS_listmap::count (void) const {
  uint32_t result = 0 ;
  if (NULL != mSharedListMap) {
    result = mSharedListMap->count () ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_uint AC_GALGAS_listmap::getter_count (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint (count ()) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark reader allKeys
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void enterAllKeys (const cListMapNode * inNode, GALGAS_stringset & ioResult) {
  if (inNode != NULL) {
    enterAllKeys (inNode->mInfPtr, ioResult) ;
    ioResult.addAssign_operation (GALGAS_string (inNode->mKey) COMMA_HERE) ;
    enterAllKeys (inNode->mSupPtr, ioResult) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_stringset AC_GALGAS_listmap::getter_allKeys (LOCATION_ARGS) const {
  GALGAS_stringset result ;
  if (isValid ()) {
    result = GALGAS_stringset::constructor_emptySet (THERE) ;
    enterAllKeys (mSharedListMap->root (), result) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void enterKeyList (const cListMapNode * inNode, GALGAS_stringlist & ioResult) {
  if (inNode != NULL) {
    enterKeyList (inNode->mInfPtr, ioResult) ;
    ioResult.addAssign_operation (GALGAS_string (inNode->mKey) COMMA_HERE) ;
    enterKeyList (inNode->mSupPtr, ioResult) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_stringlist AC_GALGAS_listmap::getter_keyList (LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (isValid ()) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    enterKeyList (mSharedListMap->root (), result) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Object Compare
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cSharedListMapRoot::listmapCompare (const cSharedListMapRoot * inOperand) const {
  typeComparisonResult result = kOperandEqual ;
  if (count () < inOperand->count ()) {
    result = kFirstOperandLowerThanSecond ;
  }else if (count () > inOperand->count ()) {
    result = kFirstOperandGreaterThanSecond ;
  }else{
    capCollectionElementArray array ; populateEnumerationArray (array) ;
    capCollectionElementArray operandArray ; inOperand->populateEnumerationArray (operandArray) ;
    for (uint32_t i=0 ; (i<array.count ()) && (kOperandEqual == result) ; i++) {
      result = array.objectAtIndex (i COMMA_HERE).compare (operandArray.objectAtIndex (i COMMA_HERE)) ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult AC_GALGAS_listmap::objectCompare (const AC_GALGAS_listmap & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    result = mSharedListMap->listmapCompare (inOperand.mSharedListMap) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Description
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

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
    inNode->myList.description (ioString, inIndentation + 1) ;
    ioIdx ++ ;
    internalDescription (inNode->mSupPtr, ioString, inIndentation, ioIdx) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_listmap::description (C_String & ioString,
                                     const int32_t inIndentation) const {
  ioString << "<@" << staticTypeDescriptor ()->mGalgasTypeName ;
  if (isValid ()) {
    ioString << ": " << cStringWithUnsigned (count()) << " object"
             << ((count() > 1) ? "s" : "") ;
    mSharedListMap->description (ioString, inIndentation) ;
  }else{
    ioString << ": not built" ;
  }
  ioString << ">" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark List map Node
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cListMapNode::cListMapNode (const cListMapNode * inNode) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (0),
mKey (),
myList () {
  macroValidPointer (inNode) ;
  if (inNode->mInfPtr != NULL) {
    macroMyNew (mInfPtr, cListMapNode (inNode->mInfPtr)) ;
  }
  if (inNode->mSupPtr != NULL) {
    macroMyNew (mSupPtr, cListMapNode (inNode->mSupPtr)) ;
  }
  mKey = inNode->mKey ;
  mBalance = inNode->mBalance ;
  myList = inNode->myList ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_listmap::insulateListMap (LOCATION_ARGS) {
  if ((mSharedListMap != NULL) && !mSharedListMap->isUniquelyReferenced ()) {
    cSharedListMapRoot * p = NULL ;
    macroMyNew (p, cSharedListMapRoot (THERE)) ;
    p->copyFrom (mSharedListMap) ;
    macroAssignSharedObject (mSharedListMap, p) ;
    macroDetachSharedObject (p) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Create a new list map
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_listmap::makeNewEmptyListMap (LOCATION_ARGS) {
  macroMyNew (mSharedListMap, cSharedListMapRoot (THERE)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Adding an object
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedListMapRoot::addObjectInListMap (const C_String & inKey,
                                                 capCollectionElement & inAttributeArray) {
  macroUniqueSharedObject (this) ;
  cListMapNode * entry = NULL ;
  bool extension = false ; // Unused
  findOrAddEntry (mRoot, inKey, entry, extension) ;
  macroValidPointer (entry) ;
  entry->myList.appendObject (inAttributeArray) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_listmap::addObjectInListMap (const GALGAS_string & inKey,
                                            capCollectionElement & inAttributeArray) {
  if (isValid () && inKey.isValid ()) {
    insulateListMap (HERE) ;
    if (NULL != mSharedListMap) {
      mSharedListMap->addObjectInListMap (inKey.stringValue (), inAttributeArray) ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark listForKey support
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

capCollectionElementArray cSharedListMapRoot::listForKey (const C_String & inKey) const {
  capCollectionElementArray result ;
  bool found = false ;
  const cListMapNode * p = mRoot ;
  while ((p != NULL) && !found) {
    const int32_t comparaison = p->mKey.compare (inKey) ;
    if (comparaison > 0) {
      p = p->mInfPtr ;
    }else if (comparaison < 0) {
      p = p->mSupPtr ;
    }else{
      result = p->myList ;
      found = true ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

capCollectionElementArray AC_GALGAS_listmap::listForKey (const GALGAS_string & inKey) const {
  capCollectionElementArray result ;
  if (isValid () && inKey.isValid ()) {
    result = mSharedListMap->listForKey (inKey.stringValue ()) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cListMapElement
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cListMapElement::cListMapElement (const C_String & inKey,
                                          const capCollectionElementArray & inSharedList
                                          COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mKey (inKey),
mSharedListMapList (inSharedList) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cListMapElement::~ cListMapElement (void) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

bool cListMapElement::isValid (void) const {
  return true ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

typeComparisonResult cListMapElement::compare (const cCollectionElement * /* inOperand */) const {
  return kOperandNotValid ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

cCollectionElement * cListMapElement::copy (void) {
  return NULL ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cListMapElement::description (C_String & /* ioString */,
                                   const int32_t /* inIndentation */) const {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark listmap cEnumerator
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                 'GALGAS_stringset::cEnumerator' class                                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void enterAscendingEnumeration (const cListMapNode * inNode,
                                       capCollectionElementArray & ioEnumerationArray) {
  if (inNode != NULL) {
    enterAscendingEnumeration (inNode->mInfPtr, ioEnumerationArray) ;
    cListMapElement * p = NULL ;
    macroMyNew (p, cListMapElement (inNode->mKey, inNode->myList COMMA_HERE)) ;
    capCollectionElement element ;
    element.setPointer (p) ;
    macroDetachSharedObject (p) ;
    ioEnumerationArray.appendObject (element) ;
    enterAscendingEnumeration (inNode->mSupPtr, ioEnumerationArray) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void cSharedListMapRoot::populateEnumerationArray (capCollectionElementArray & ioEnumerationArray) const {
  // printf ("MAP COUNT %u\n", count ()) ;
  ioEnumerationArray.setCapacity (mCount) ;
  enterAscendingEnumeration (mRoot, ioEnumerationArray) ;
  MF_Assert (mCount == ioEnumerationArray.count (), "mCount (%lld) != ioEnumerationArray.count () (%lld)", mCount, ioEnumerationArray.count ()) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_GALGAS_listmap::populateEnumerationArray (capCollectionElementArray & ioEnumerationArray) const {
  if (isValid ()) {
    mSharedListMap->populateEnumerationArray (ioEnumerationArray) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

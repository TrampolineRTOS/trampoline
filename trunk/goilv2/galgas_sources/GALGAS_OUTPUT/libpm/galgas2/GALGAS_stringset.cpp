//---------------------------------------------------------------------------*
//                                                                           *
//  GALGAS_stringset                                                         *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2005, ..., 2011 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#include "predefined-types.h"
#include "utilities/MF_MemoryControl.h"
#include "cCollectionElement.h"

//---------------------------------------------------------------------------*
//   cCollectionElement_stringset                                            *
//---------------------------------------------------------------------------*

class cCollectionElement_stringset : public cCollectionElement {
//--- Private member
  protected : GALGAS_string mAttribute_key ;
  public : inline GALGAS_string attribute_key (void) const { return mAttribute_key ; }

//--- Default constructor
  public : cCollectionElement_stringset (const GALGAS_string & inString
                                         COMMA_LOCATION_ARGS) ;

//--- No copy
  private : cCollectionElement_stringset (const cCollectionElement_stringset &) ;
  private : cCollectionElement_stringset & operator = (const cCollectionElement_stringset &) ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const PMSInt32 inIndentation) const ;
} ;

//---------------------------------------------------------------------------*

cCollectionElement_stringset::cCollectionElement_stringset (const GALGAS_string & inKey
                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mAttribute_key (inKey) {
}

//---------------------------------------------------------------------------*

bool cCollectionElement_stringset::isValid (void) const {
  return mAttribute_key.isValid () ;
}

//---------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_stringset::compare (const cCollectionElement * inOperand) const {
  const cCollectionElement_stringset * operand = (const cCollectionElement_stringset *) inOperand ;
  macroValidSharedObject (operand, const cCollectionElement_stringset) ;
  return mAttribute_key.objectCompare (operand->mAttribute_key) ;
}

//---------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_stringset::copy (void) {
  cCollectionElement_stringset * p = NULL ;
  macroMyNew (p, cCollectionElement_stringset (mAttribute_key COMMA_HERE)) ;
  return p ;
}


//---------------------------------------------------------------------------*

void cCollectionElement_stringset::description (C_String & ioString, const PMSInt32 inIndentation) const {
  mAttribute_key.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  c S t r i n g s e t N o d e                                              *
//                                                                           *
//---------------------------------------------------------------------------*

class cStringsetNode {
  public : cStringsetNode * mInfPtr ;
  public : cStringsetNode * mSupPtr ;
  public : PMSInt32 mBalance ;
  public : C_String mKey ;

//---  
  public : cStringsetNode (const C_String & inString) ;
  public : cStringsetNode (const cStringsetNode * inNode,
                           PMUInt32 & ioCount) ;

//--- No copy
  private : cStringsetNode (const cStringsetNode &) ;
  private : cStringsetNode & operator = (const cStringsetNode &) ;

//--- Destructor
  public : ~ cStringsetNode (void) ;
} ;

//---------------------------------------------------------------------------*

cStringsetNode::cStringsetNode (const C_String & inString) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (0),
mKey (inString) {
}

//---------------------------------------------------------------------------*

cStringsetNode::cStringsetNode (const cStringsetNode * inNode,
                                PMUInt32 & ioCount) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (0),
mKey () {
  macroValidPointer (inNode) ;
  if (inNode->mInfPtr != NULL) {
    macroMyNew (mInfPtr, cStringsetNode (inNode->mInfPtr, ioCount)) ;
  }
  if (inNode->mSupPtr != NULL) {
    macroMyNew (mSupPtr, cStringsetNode (inNode->mSupPtr, ioCount)) ;
  }
  mKey = inNode->mKey ;
  mBalance = inNode->mBalance ;
  ioCount ++ ;
}

//---------------------------------------------------------------------------*

cStringsetNode::~cStringsetNode (void) {
  macroMyDelete (mInfPtr) ;
  macroMyDelete (mSupPtr) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Insertion Implementation
#endif

//---------------------------------------------------------------------------*

static void rotateLeft (cStringsetNode * & ioRootPtr) {
  cStringsetNode * ptr = ioRootPtr->mSupPtr ;
  ioRootPtr->mSupPtr = ptr->mInfPtr ;
  ptr->mInfPtr = ioRootPtr;

  if (ptr->mBalance >= 0) {
    ioRootPtr->mBalance++ ;
  }else{
    ioRootPtr->mBalance += 1 - ptr->mBalance ;
  }

  if (ioRootPtr->mBalance > 0) {
    ptr->mBalance += ioRootPtr->mBalance + 1 ;
  }else{
    ptr->mBalance++ ;
  }
  ioRootPtr = ptr ;
}

//---------------------------------------------------------------------

static void rotateRight (cStringsetNode * & ioRootPtr) {
  cStringsetNode * ptr = ioRootPtr->mInfPtr ;
  ioRootPtr->mInfPtr = ptr->mSupPtr ;
  ptr->mSupPtr = ioRootPtr ;
 
  if (ptr->mBalance > 0) {
    ioRootPtr->mBalance += -ptr->mBalance - 1 ;
  }else{
    ioRootPtr->mBalance-- ;
  }
  if (ioRootPtr->mBalance >= 0) {
    ptr->mBalance-- ;
  }else{
    ptr->mBalance += ioRootPtr->mBalance - 1 ;
  }
  ioRootPtr = ptr ;
}

//---------------------------------------------------------------------------*

static void recursiveAddEntry (cStringsetNode * & ioRootPtr,
                               const C_String & inKey,
                               bool & outEntryAdded,
                               bool & ioExtension) {
  if (ioRootPtr == NULL) {
    macroMyNew (ioRootPtr, cStringsetNode (inKey)) ;
    ioExtension = true ;
    outEntryAdded = true ;
  }else{
    macroValidPointer (ioRootPtr) ;
    const PMSInt32 comparaison = ioRootPtr->mKey.compare (inKey) ;
    if (comparaison > 0) {
      recursiveAddEntry (ioRootPtr->mInfPtr, inKey, outEntryAdded, ioExtension) ;
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
      recursiveAddEntry (ioRootPtr->mSupPtr, inKey, outEntryAdded, ioExtension) ;
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
      outEntryAdded = false ;
    }
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Remove Implementation
#endif

//---------------------------------------------------------------------------*

static void supBranchDecreased (cStringsetNode * & ioRoot,
                                bool & ioBranchHasBeenRemoved) {
  ioRoot->mBalance ++ ;
  switch (ioRoot->mBalance) {
  case 0:
    break;
  case 1:
    ioBranchHasBeenRemoved = false;
    break;
  case 2:
    switch (ioRoot->mInfPtr->mBalance) {
    case -1:
      rotateLeft (ioRoot->mInfPtr) ;
      rotateRight (ioRoot) ;
      break;
    case 0:
      rotateRight (ioRoot) ;
      ioBranchHasBeenRemoved = false;
      break;
    case 1:
      rotateRight (ioRoot) ;
      break;
    }
    break;
  }
}

//---------------------------------------------------------------------------*

static void infBranchDecreased (cStringsetNode * & ioRoot,
                                bool & ioBranchHasBeenRemoved) {
  ioRoot->mBalance -- ;
  switch (ioRoot->mBalance) {
  case 0:
    break;
  case -1:
    ioBranchHasBeenRemoved = false;
    break;
  case -2:
    switch (ioRoot->mSupPtr->mBalance) {
    case 1:
      rotateRight (ioRoot->mSupPtr) ;
      rotateLeft (ioRoot) ;
      break;
    case 0:
      rotateLeft (ioRoot) ;
      ioBranchHasBeenRemoved = false;
      break;
    case -1:
      rotateLeft (ioRoot) ;
      break;
    }
    break;
  }
}

//---------------------------------------------------------------------------*

static void getPreviousElement (cStringsetNode * & ioRoot,
                                cStringsetNode * & ioElement,
                                bool & ioBranchHasBeenRemoved) {
  if (ioRoot->mSupPtr == NULL) {
    ioElement = ioRoot ;
    ioRoot = ioRoot->mInfPtr ;
    ioBranchHasBeenRemoved = true ;
  }else{
    getPreviousElement (ioRoot->mSupPtr, ioElement, ioBranchHasBeenRemoved) ;
    if (ioBranchHasBeenRemoved) {
      supBranchDecreased (ioRoot, ioBranchHasBeenRemoved) ;
    }
  }
}

//---------------------------------------------------------------------------*

static void internalRemoveRecursively (cStringsetNode * & ioRoot,
                                       const C_String & inKeyToRemove,
                                       bool & outKeyHasBeenRemoved,
                                       bool & ioBranchHasBeenRemoved) {
  if (ioRoot != NULL) {
    const PMSInt32 comparaison = ioRoot->mKey.compare (inKeyToRemove) ;
    if (comparaison > 0) {
      internalRemoveRecursively (ioRoot->mInfPtr, inKeyToRemove, outKeyHasBeenRemoved, ioBranchHasBeenRemoved);
      if (ioBranchHasBeenRemoved) {
        infBranchDecreased (ioRoot, ioBranchHasBeenRemoved) ;
      }
    }else if (comparaison < 0) {
      internalRemoveRecursively (ioRoot->mSupPtr, inKeyToRemove, outKeyHasBeenRemoved, ioBranchHasBeenRemoved);
      if (ioBranchHasBeenRemoved) {
        supBranchDecreased (ioRoot, ioBranchHasBeenRemoved);
      }
    }else{
      cStringsetNode * p = ioRoot ;
      outKeyHasBeenRemoved = true ;
      if (p->mInfPtr == NULL) {
        ioRoot = p->mSupPtr;
        p->mSupPtr = NULL;
        ioBranchHasBeenRemoved = true;
      }else if (p->mSupPtr == NULL) {
        ioRoot = p->mInfPtr;
        p->mInfPtr = NULL;
        ioBranchHasBeenRemoved = true;
      }else{
        getPreviousElement (p->mInfPtr, ioRoot, ioBranchHasBeenRemoved) ;
        ioRoot->mSupPtr = p->mSupPtr;
        p->mSupPtr = NULL;
        ioRoot->mInfPtr = p->mInfPtr;
        p->mInfPtr = NULL;
        ioRoot->mBalance = p->mBalance;
        p->mBalance = 0;
        if (ioBranchHasBeenRemoved) {
          infBranchDecreased (ioRoot, ioBranchHasBeenRemoved) ;
        }
      }
      macroMyDelete (p) ;
    }
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cSharedStringsetRoot
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//  cSharedStringsetRoot                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

class cSharedStringsetRoot : public C_SharedObject {
//--- Private data members
  private : cStringsetNode * mRoot ;
  private : PMUInt32 mEntryCount ;

//--- Accessors
  public : inline const cStringsetNode * root (void) const { return mRoot ; }
  public : inline PMUInt32 count (void) const { return mEntryCount ; }

//--- Default constructor
  public : cSharedStringsetRoot (LOCATION_ARGS) ;
  
//--- Virtual destructor
  public : virtual ~ cSharedStringsetRoot (void) ;

//--- No copy
  private : cSharedStringsetRoot (const cSharedStringsetRoot &) ;
  private : cSharedStringsetRoot & operator = (const cSharedStringsetRoot &) ;

//--- In debug mode : check methods
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : void countStringSetNodes (const cStringsetNode * inNode,
                                       PMUInt32 & ioCount) const ;
    public : void checkStringset (LOCATION_ARGS) const ;
  #endif

//--- Add entry
  public : void addKey (const C_String & inKey) ;

//--- Remove key
  public : void removeKey (const C_String & inKey) ;

//--- Has key
  public : bool hasKey (const C_String & inKey) const ;

//--- Build key list
  public : void buildOrderedKeyList (TC_UniqueArray <C_String> & ioList) const ;

//--- enter contents into stringlist
  public : void addToStringList (GALGAS_stringlist & ioResult) const ;

//--- Copy from
  public : void copyFrom (const cSharedStringsetRoot * inSharedRootToCopy) ;

//--- Description
  protected : void displayEntries (const cStringsetNode * inNode,
                                   C_String & ioString) const ;
  public : void description (C_String & ioString) const ;
} ;

//---------------------------------------------------------------------------*

cSharedStringsetRoot::cSharedStringsetRoot (LOCATION_ARGS) :
C_SharedObject (THERE),
mRoot (NULL),
mEntryCount (0) {
}

//---------------------------------------------------------------------------*

cSharedStringsetRoot::~cSharedStringsetRoot (void) {
  macroMyDelete (mRoot) ;
}

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cSharedStringsetRoot::countStringSetNodes (const cStringsetNode * inNode,
                                                  PMUInt32 & ioCount) const {
    if (NULL != inNode) {
      countStringSetNodes (inNode->mInfPtr, ioCount) ;
      ioCount ++ ;
      countStringSetNodes (inNode->mSupPtr, ioCount) ;
    }
  }
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cSharedStringsetRoot::checkStringset (LOCATION_ARGS) const {
    PMUInt32 count = 0 ;
    countStringSetNodes (mRoot, count) ;
    MF_AssertThere (count == mEntryCount, "count %lld != mEntryCount %lld", count, mEntryCount) ;
  }
#endif

//---------------------------------------------------------------------------*

void cSharedStringsetRoot::displayEntries (const cStringsetNode * inNode,
                                           C_String & ioString) const {
  if (inNode != NULL) {
    displayEntries (inNode->mInfPtr, ioString) ;
    ioString << " '" << inNode->mKey << "'" ;
    displayEntries (inNode->mSupPtr, ioString) ;
  }
}

//---------------------------------------------------------------------------*

void cSharedStringsetRoot::description (C_String & ioString) const {
  ioString << cStringWithUnsigned (mEntryCount) ;
  if (mEntryCount > 1) {
    ioString << " entries" ;
  }else{
    ioString << " entry" ;
  }
  displayEntries (mRoot, ioString) ;
}

//---------------------------------------------------------------------------*

void cSharedStringsetRoot::addKey (const C_String & inKey) {
  macroUniqueSharedObject (this) ;
  bool extension = false ;
  bool entryAdded = false ;
  recursiveAddEntry (mRoot, inKey, entryAdded, extension) ;
  if (entryAdded) {
    mEntryCount ++ ;
  }
}

//---------------------------------------------------------------------------*

void cSharedStringsetRoot::copyFrom (const cSharedStringsetRoot * inSharedRootToCopy) {
  macroValidSharedObject (inSharedRootToCopy, const cSharedStringsetRoot) ;
  if (NULL != inSharedRootToCopy->mRoot) {
    macroMyNew (mRoot, cStringsetNode (inSharedRootToCopy->mRoot, mEntryCount)) ;
  }
}

//---------------------------------------------------------------------------*

void cSharedStringsetRoot::removeKey (const C_String & inKey) {
  // printf ("OPERATION -=\n") ; fflush (stdout) ;
  macroUniqueSharedObject (this) ;
  bool branchHasBeenRemoved = false ;
  bool keyHasBeenRemoved = false ;
  internalRemoveRecursively (mRoot, inKey, keyHasBeenRemoved, branchHasBeenRemoved) ;
  if (keyHasBeenRemoved) {
    mEntryCount -- ;
  }
}

//---------------------------------------------------------------------------*

static void recursiveBuildKeyList (const cStringsetNode * inNode,
                                   TC_UniqueArray <C_String> & ioList) {
  if (inNode != NULL) {
    recursiveBuildKeyList (inNode->mInfPtr, ioList) ;
    ioList.addObject (inNode->mKey) ;
    recursiveBuildKeyList (inNode->mSupPtr, ioList) ;
  }
}

//---------------------------------------------------------------------------*

void cSharedStringsetRoot::buildOrderedKeyList (TC_UniqueArray <C_String> & ioList) const {
  recursiveBuildKeyList (mRoot, ioList) ;
}

//---------------------------------------------------------------------------*

bool cSharedStringsetRoot::hasKey (const C_String & inKey) const {
  bool found = false ;
  const cStringsetNode * p = mRoot ;
  while ((p != NULL) && ! found) {
    const PMSInt32 comparaison = p->mKey.compare (inKey) ;
    if (comparaison > 0) {
      p = p->mInfPtr ;
    }else if (comparaison < 0) {
      p = p->mSupPtr ;
    }else{
      found = true ;
    }
  }
  return found ;
}

//---------------------------------------------------------------------------*

static void recursiveAddToStringList (GALGAS_stringlist & ioResult,
                                      const cStringsetNode * inNode) {
  if (inNode != NULL) {
    recursiveAddToStringList (ioResult, inNode->mInfPtr) ;
    ioResult.addAssign_operation (GALGAS_string (inNode->mKey) COMMA_HERE) ;
    recursiveAddToStringList (ioResult, inNode->mSupPtr) ;
  }
}

//---------------------------------------------------------------------------*

void cSharedStringsetRoot::addToStringList (GALGAS_stringlist & ioResult) const {
  recursiveAddToStringList (ioResult, mRoot) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark GALGAS_stringset
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//  G A L G A S _ s t r i n g s e t                                          *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_stringset::GALGAS_stringset (void) :
AC_GALGAS_root (),
mSharedRoot (NULL) {
}

//---------------------------------------------------------------------------*

GALGAS_stringset::~GALGAS_stringset (void) {
  macroDetachSharedObject (mSharedRoot) ;
}

//---------------------------------------------------------------------------*

void GALGAS_stringset::drop (void) {
  macroDetachSharedObject (mSharedRoot) ;
}

//---------------------------------------------------------------------------*

GALGAS_stringset::GALGAS_stringset (const GALGAS_stringset & inSource) :
AC_GALGAS_root (),
mSharedRoot (NULL) {
  macroAssignSharedObject (mSharedRoot, inSource.mSharedRoot) ;
}

//---------------------------------------------------------------------------*

GALGAS_stringset & GALGAS_stringset::operator = (const GALGAS_stringset & inSource) {
  macroAssignSharedObject (mSharedRoot, inSource.mSharedRoot) ;
  return * this ;
}

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  void GALGAS_stringset::checkStringset (LOCATION_ARGS) const {
    if (NULL != mSharedRoot) {
      mSharedRoot->checkStringset (THERE) ;
    }
  }
#endif

//---------------------------------------------------------------------------*

void GALGAS_stringset::description (C_String & ioString,
                                    const PMSInt32 /* inIndentation */) const {
  ioString << "<@stringset:" ;
  if (NULL == mSharedRoot) {
    ioString << "not built" ;
  }else{
    mSharedRoot->description (ioString) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------*

void GALGAS_stringset::insulate (LOCATION_ARGS) {
  if ((NULL != mSharedRoot) && (mSharedRoot->retainCount () > 1)) {
    cSharedStringsetRoot * p = NULL ;
    macroMyNew (p, cSharedStringsetRoot (THERE)) ;
    p->copyFrom (mSharedRoot) ;
    macroAssignSharedObject (mSharedRoot, p) ;
    macroDetachSharedObject (p) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkStringset (HERE) ;
    #endif
  }
}

//---------------------------------------------------------------------------*

void GALGAS_stringset::addAssign_operation (const GALGAS_string & inKey
                                            COMMA_LOCATION_ARGS) {
  if (isValid () && (inKey.isValid ())) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkStringset (HERE) ;
    #endif
    insulate (THERE) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkStringset (HERE) ;
    #endif
    mSharedRoot->addKey (inKey.stringValue ()) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkStringset (HERE) ;
    #endif
  }
}

//---------------------------------------------------------------------------*

void GALGAS_stringset::modifier_removeKey (GALGAS_string inKey
                                           COMMA_LOCATION_ARGS) {
  // printf ("OPERATION -=\n") ; fflush (stdout) ;
  if (isValid () && inKey.isValid ()) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkStringset (THERE) ;
    #endif
    insulate (THERE) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkStringset (HERE) ;
    #endif
    mSharedRoot->removeKey (inKey.stringValue ()) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkStringset (THERE) ;
    #endif
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark stringset operations
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//    I N T E R S E C T I O N                                                *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_stringset GALGAS_stringset::operator_and (const GALGAS_stringset & inOperand2
                                                 COMMA_LOCATION_ARGS) const {
// printf ("OPERATION AND\n") ; fflush (stdout) ;
  GALGAS_stringset result ;
  if (isValid () && inOperand2.isValid ()) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkStringset (HERE) ;
      inOperand2.checkStringset (HERE) ;
    #endif
    result = constructor_emptySet (THERE) ;
    const PMUInt32 leftCount = mSharedRoot->count () ;
    TC_UniqueArray <C_String> leftList ((PMSInt32) leftCount COMMA_THERE) ;
    mSharedRoot->buildOrderedKeyList (leftList) ;
    const PMUInt32 rightCount = inOperand2.mSharedRoot->count () ;
    TC_UniqueArray <C_String> rightList ((PMSInt32) rightCount COMMA_THERE) ;
    inOperand2.mSharedRoot->buildOrderedKeyList (rightList) ;
    PMUInt32 leftIndex = 0 ;
    PMUInt32 rightIndex = 0 ;
    while ((leftIndex < leftCount) && (rightIndex < rightCount)) {
      const PMSInt32 cmp = leftList ((PMSInt32) leftIndex COMMA_THERE).compare (rightList ((PMSInt32) rightIndex COMMA_THERE)) ;
      if (cmp < 0) {
        leftIndex ++ ;
      }else if (cmp > 0) {
        rightIndex ++ ;
      }else{
        result.addAssign_operation (GALGAS_string (leftList ((PMSInt32) leftIndex COMMA_THERE)) COMMA_HERE) ;
        leftIndex ++ ;
        rightIndex ++ ;
      }
    }
    #ifndef DO_NOT_GENERATE_CHECKINGS
      result.checkStringset (HERE) ;
    #endif
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//    U N I O N                                                              *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_stringset GALGAS_stringset::operator_or (const GALGAS_stringset & inOperand2
                                                COMMA_LOCATION_ARGS) const {
// printf ("OPERATION AND\n") ; fflush (stdout) ;
  GALGAS_stringset result ;
  if (isValid () && inOperand2.isValid ()) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkStringset (HERE) ;
      inOperand2.checkStringset (HERE) ;
    #endif
    result = *this ;
    const PMUInt32 rightCount = inOperand2.mSharedRoot->count () ;
    TC_UniqueArray <C_String> rightList ((PMSInt32) rightCount COMMA_THERE) ;
    inOperand2.mSharedRoot->buildOrderedKeyList (rightList) ;
    for (PMUInt32 i=0 ; i<rightCount ; i++) {
      result.addAssign_operation (GALGAS_string (rightList ((PMSInt32) i COMMA_THERE)) COMMA_HERE) ;
    }
    #ifndef DO_NOT_GENERATE_CHECKINGS
      result.checkStringset (HERE) ;
    #endif
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//    D I F F E R E N C E                                                    *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_stringset GALGAS_stringset::substract_operation (const GALGAS_stringset & inOperand2,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_LOCATION_ARGS) const {
// printf ("OPERATION SUBSTRACT\n") ; fflush (stdout) ;
  GALGAS_stringset result ;
  if (isValid () && inOperand2.isValid ()) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkStringset (HERE) ;
      inOperand2.checkStringset (HERE) ;
    #endif
    result = constructor_emptySet (THERE) ;
    const PMUInt32 leftCount = mSharedRoot->count () ;
    TC_UniqueArray <C_String> leftList ((PMSInt32) leftCount COMMA_THERE) ;
    mSharedRoot->buildOrderedKeyList (leftList) ;
    for (PMUInt32 i=0 ; i<leftCount ; i++) {
      if (! inOperand2.mSharedRoot->hasKey (leftList ((PMSInt32) i COMMA_HERE))) {
        result.addAssign_operation (GALGAS_string (leftList ((PMSInt32) i COMMA_HERE)) COMMA_HERE) ;
      }
    }
    #ifndef DO_NOT_GENERATE_CHECKINGS
      result.checkStringset (HERE) ;
    #endif
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Readers
#endif

//---------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_stringset::reader_stringList (LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (isValid ()) {
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    mSharedRoot->addToStringList (result) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_bool GALGAS_stringset::reader_hasKey (const GALGAS_string & inKey
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (isValid () && inKey.isValid ()) {
    const C_String key = inKey.stringValue () ;
    result = GALGAS_bool (mSharedRoot->hasKey (key)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_uint GALGAS_stringset::reader_count (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mSharedRoot->count ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark stringset cEnumerator
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                 'GALGAS_stringset::cEnumerator' class                     *
//                                                                           *
//---------------------------------------------------------------------------*

static void enterAscendingEnumeration (const cStringsetNode * inNode,
                                       capCollectionElementArray & ioResult) {
  if (inNode != NULL) {
    enterAscendingEnumeration (inNode->mInfPtr, ioResult) ;
    cCollectionElement_stringset * p = NULL ;
    GALGAS_string str (GALGAS_string (inNode->mKey)) ;
    macroMyNew (p, cCollectionElement_stringset (str COMMA_HERE)) ;
    capCollectionElement object ;
    object.setPointer (p) ;
    macroDetachSharedObject (p) ;
    ioResult.addObject (object) ;
    enterAscendingEnumeration (inNode->mSupPtr, ioResult) ;
  }
}

//---------------------------------------------------------------------------*

static void enterDescendingEnumeration (const cStringsetNode * inNode,
                                        capCollectionElementArray & ioResult) {
  if (inNode != NULL) {
    enterDescendingEnumeration (inNode->mSupPtr, ioResult) ;
    cCollectionElement_stringset * p = NULL ;
    GALGAS_string str (GALGAS_string (inNode->mKey)) ;
    macroMyNew (p, cCollectionElement_stringset (str COMMA_HERE)) ;
    capCollectionElement object ;
    object.setPointer (p) ;
    macroDetachSharedObject (p) ;
    ioResult.addObject (object) ;
    enterDescendingEnumeration (inNode->mInfPtr, ioResult) ;
  }
}

//---------------------------------------------------------------------------*

void GALGAS_stringset::populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                                 const typeEnumerationOrder inEnumerationOrder) const {
  if (isValid ()) {
    inEnumerationArray.setCapacity (mSharedRoot->count ()) ;
    switch (enumerationOrderValue (inEnumerationOrder)) {
    case kENUMERATION_UP: enterAscendingEnumeration (mSharedRoot->root (), inEnumerationArray) ; break ;
    case kENUMERATION_DOWN: enterDescendingEnumeration (mSharedRoot->root (), inEnumerationArray) ; break ;
    case kENUMERATION_ENTER_ORDER : case kENUMERATION_REVERSE_ENTER_ORDER:
     MF_Assert (false, "invalid inEnumerationOrder %lld", enumerationOrderValue (inEnumerationOrder), 0) ;
     break ;
    }
    #ifndef DO_NOT_GENERATE_CHECKINGS
      MF_Assert (mSharedRoot->count () == inEnumerationArray.count (),
                 "mSharedRoot->count () %lld != inEnumerationArray.count () %lld",
                 mSharedRoot->count (), inEnumerationArray.count ()) ;
    #endif
  }
}

//---------------------------------------------------------------------------*

cEnumerator_stringset::cEnumerator_stringset (const GALGAS_stringset & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------*

GALGAS_string cEnumerator_stringset::current_key (LOCATION_ARGS) const {
  const cCollectionElement_stringset * p = (const cCollectionElement_stringset *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, const cCollectionElement_stringset) ;
  return p->attribute_key () ;
}

//---------------------------------------------------------------------------*

GALGAS_string cEnumerator_stringset::current (LOCATION_ARGS) const {
  const cCollectionElement_stringset * p = (const cCollectionElement_stringset *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, const cCollectionElement_stringset) ;
  return p->attribute_key () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//    C O M P A R I S O N                                                    *
//                                                                           *
//---------------------------------------------------------------------------*

typeComparisonResult GALGAS_stringset::objectCompare (const GALGAS_stringset & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const PMSInt32 count1 = (PMSInt32) mSharedRoot->count () ;
    const cStringsetNode * root1 = mSharedRoot->root () ;
    const PMSInt32 count2 = (PMSInt32) inOperand.mSharedRoot->count () ;
    const cStringsetNode * root2 = inOperand.mSharedRoot->root () ;
    PMSInt32 r = 0 ;
    if (root1 != root2) {
      r = count1 - count2 ;
      if (r == 0) {
        TC_UniqueArray <C_String> leftList (count1 COMMA_HERE) ;
        mSharedRoot->buildOrderedKeyList (leftList) ;
        TC_UniqueArray <C_String> rightList (count2 COMMA_HERE) ;
        inOperand.mSharedRoot->buildOrderedKeyList (rightList) ;
        for (PMSInt32 i=0 ; (i<count1) && (r == 0) ; i++) {
          r = leftList (i COMMA_HERE).compare (rightList (i COMMA_HERE)) ;
        }
      }
    }
    if (r < 0) {
      result = kFirstOperandLowerThanSecond ;
    }else if (r > 0) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors
#endif

//---------------------------------------------------------------------------*

GALGAS_stringset GALGAS_stringset::constructor_emptySet (LOCATION_ARGS) {
  GALGAS_stringset result ;
  macroMyNew (result.mSharedRoot, cSharedStringsetRoot (THERE)) ;
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_stringset GALGAS_stringset::constructor_setWithString (const GALGAS_string & inString
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_stringset result ;
  if (inString.isValid ()) {
    result = constructor_emptySet (THERE) ;
    result.addAssign_operation (inString COMMA_HERE) ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      result.checkStringset (HERE) ;
    #endif
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_stringset GALGAS_stringset::constructor_setWithStringList (const GALGAS_stringlist & inStringList
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_stringset result ;
  if (inStringList.isValid ()) {
    result = constructor_emptySet (THERE) ;
    cEnumerator_stringlist enumerator (inStringList, kEnumeration_up) ;
    while (enumerator.hasCurrentObject ()) {
      result.addAssign_operation (enumerator.current_mValue (THERE) COMMA_THERE) ;
      enumerator.gotoNextObject () ;
    }
    #ifndef DO_NOT_GENERATE_CHECKINGS
      result.checkStringset (HERE) ;
    #endif
  }
  return result ;
}

//---------------------------------------------------------------------------*


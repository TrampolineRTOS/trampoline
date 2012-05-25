//---------------------------------------------------------------------------*
//                                                                           *
//  AC_GALGAS_sortedlist                                                     *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2005, ..., 2010 Pierre Molinaro.                           *
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

#include "AC_GALGAS_sortedlist.h"
#include "capSortedListElement.h"
#include "cSortedListElement.h"
#include "predefined-types.h"
#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_Compiler.h"

//---------------------------------------------------------------------------*
//                                                                           *
//  c S t r i n g s e t N o d e                                              *
//                                                                           *
//---------------------------------------------------------------------------*

class cSortedListNode {
  public : cSortedListNode * mInfPtr ;
  public : cSortedListNode * mSupPtr ;
  public : PMSInt32 mBalance ;
  public : cSortedListNode * mNextPtr ;
  public : cSortedListNode * mPreviousPtr ;
  public : capSortedListElement mAttributes ;

//---  
  public : cSortedListNode (const capSortedListElement & inAttributes) ;

  public : cSortedListNode (cSortedListNode * inNode) ;

//--- No copy
  private : cSortedListNode (const cSortedListNode &) ;
  private : cSortedListNode & operator = (const cSortedListNode &) ;
} ;

//---------------------------------------------------------------------------*

cSortedListNode::cSortedListNode (const capSortedListElement & inAttributes) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (0),
mNextPtr (NULL),
mPreviousPtr (NULL),
mAttributes (inAttributes) {
}

//---------------------------------------------------------------------------*

cSortedListNode::cSortedListNode (cSortedListNode * inNode) :
mInfPtr (NULL),
mSupPtr (NULL),
mBalance (0),
mNextPtr (NULL),
mPreviousPtr (NULL),
mAttributes () {
  macroValidPointer (inNode) ;
  mAttributes = inNode->mAttributes ;
  mBalance = inNode->mBalance ;
  if (inNode->mInfPtr != NULL) {
    macroMyNew (mInfPtr, cSortedListNode (inNode->mInfPtr)) ;
  }
  if (inNode->mSupPtr != NULL) {
    macroMyNew (mSupPtr, cSortedListNode (inNode->mSupPtr)) ;
  }
}

//---------------------------------------------------------------------------*

static void disposeNodes (cSortedListNode * inNode) {
  if (NULL != inNode) {
    disposeNodes (inNode->mInfPtr) ;
    disposeNodes (inNode->mSupPtr) ;
    macroMyDelete (inNode) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cSharedSortedListRoot
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//    cSharedSortedListRoot                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

class cSharedSortedListRoot : public C_SharedObject {
//--------------------------------- Private data members
  private : cSortedListNode * mRoot ; // For AVL tree
  private : cSortedListNode * mFirst ;
  private : cSortedListNode * mLast ;
  private : PMUInt32 mCount ;

//--------------------------------- Native constructor
  protected : cSharedSortedListRoot (LOCATION_ARGS) ;

//--------------------------------- Virtual destructor
  protected : virtual ~ cSharedSortedListRoot (void) ;

//--------------------------------- No copy
  private : cSharedSortedListRoot (const cSharedSortedListRoot &) ;
  private : cSharedSortedListRoot & operator = (const cSharedSortedListRoot &) ;

//--------------------------------- Accessor
  protected : inline PMUInt32 count (void) const { return mCount ; }

//--------------------------------- Implementation of reader 'description'
  protected : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

//--- Enumeration handling
  protected : virtual void populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                                     const typeEnumerationOrder inEnumerationOrder) const ;

//--- Object Compare
  protected : typeComparisonResult objectCompare (const cSharedSortedListRoot * inOperand) const ;

//--- Adding an object
  protected : void addObject (capSortedListElement & inAttributes) ;

  private : void addEntry (cSortedListNode * & ioRootPtr,
                           cSortedListNode * inCurrentNode,
                           const capSortedListElement & inAttributes,
                           bool & ioExtension) ;

//--------------------------------- Append a list
  protected : void appendSortedList (const cSharedSortedListRoot * inList) ;

//--------------------------------- Method Implementation
  protected : void smallestObjectAttributeList (capSortedListElement & outAttributes,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const ;

  protected : void greatestObjectAttributeList (capSortedListElement & outAttributes,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const ;

//--------------------------------- Modifier Implementation
  protected : void removeSmallestObject (capSortedListElement & outAttributes,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

  protected : void removeGreatestObject (capSortedListElement & outAttributes,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Copy from a other list
  protected : void copyFrom (const cSharedSortedListRoot * inList) ;

//--------------------------------- Friend
  friend class AC_GALGAS_sortedlist ;
} ;

//---------------------------------------------------------------------------*

cSharedSortedListRoot::cSharedSortedListRoot (LOCATION_ARGS) :
C_SharedObject (THERE),
mRoot (NULL),
mFirst (NULL),
mLast (NULL),
mCount (0) {
}

//---------------------------------------------------------------------------*

cSharedSortedListRoot::~ cSharedSortedListRoot (void) {
  disposeNodes (mRoot) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Checking sorted lists
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void populateCheckArray (const cSortedListNode * inNode,
                                  PMUInt32 & ioIndex,
                                  const cSortedListNode * * ioArray) {
    if (NULL != inNode) {
      macroValidSharedObject (inNode, const cSortedListNode) ;
      populateCheckArray (inNode->mInfPtr, ioIndex, ioArray) ;
      // printf ("Node %p at index %u\n", inNode, ioIndex) ;
      ioArray [ioIndex] = inNode ;
      ioIndex ++ ;
      populateCheckArray (inNode->mSupPtr, ioIndex, ioArray) ;
    }
  }
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  static void checkSortedList (const cSortedListNode * inRoot,
                               const PMUInt32 inCount,
                               const cSortedListNode * inFirst,
                               const cSortedListNode * inLast
                               COMMA_LOCATION_ARGS) {
    const cSortedListNode * * array = NULL ;
    macroMyNewPODArray (array, const cSortedListNode *, inCount) ; 
    PMUInt32 idx = 0 ;
    // printf ("-----\n") ;
    populateCheckArray (inRoot, idx, array) ;
    MF_AssertThere (idx == inCount, "a: idx (%lld) != inCount (%lld)", idx, inCount) ;

    const cSortedListNode * p = inFirst ;
    idx = 0 ;
    while (p != NULL) {
      MF_AssertThere (p == array [idx], "b: p (%p) != array [idx] (%p)", (PMSInt64) p, (PMSInt64) array [idx]) ;
      idx ++ ;
      p = p->mNextPtr ;
    }
    MF_AssertThere (idx == inCount, "c: idx (%lld) != inCount (%lld)", idx, inCount) ;

    p = inLast ;
    idx = inCount ;
    while (p != NULL) {
      idx -- ;
      MF_AssertThere (p == array [idx], "d: p (%p) != array [idx] (%p)", (PMSInt64) p, (PMSInt64) array [idx]) ;
      p = p->mPreviousPtr ;
    }
    MF_AssertThere (idx == 0, "idx (%lld) != 0", idx, 0) ;
    macroMyDeletePODArray (array) ;
  }
#endif

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Insulate
#endif

//---------------------------------------------------------------------------*

void AC_GALGAS_sortedlist::insulate (LOCATION_ARGS) {
  if ((mSharedRoot != NULL) && (mSharedRoot->retainCount () > 1)) {
    cSharedSortedListRoot * p = NULL ;
    macroMyNew (p, cSharedSortedListRoot (THERE)) ;
    p->copyFrom (mSharedRoot) ;
    macroAssignSharedObject (mSharedRoot, p) ;
    macroDetachSharedObject (p) ;
  }
}

//---------------------------------------------------------------------------*

static void buildDirectLinksOnCopy (cSortedListNode * inNode,
                                    cSortedListNode * & ioFirst) {
  if (NULL != inNode) {
    buildDirectLinksOnCopy (inNode->mSupPtr, ioFirst) ;
    inNode->mNextPtr = ioFirst ;
    ioFirst = inNode ;
    buildDirectLinksOnCopy (inNode->mInfPtr, ioFirst) ;
  }
}

//---------------------------------------------------------------------------*

static void buildReverseLinksOnCopy (cSortedListNode * inNode,
                                     cSortedListNode * & ioLast) {
  if (NULL != inNode) {
    buildReverseLinksOnCopy (inNode->mInfPtr, ioLast) ;
    inNode->mPreviousPtr = ioLast ;
    ioLast = inNode ;
    buildReverseLinksOnCopy (inNode->mSupPtr, ioLast) ;
  }
}

//---------------------------------------------------------------------------*

void cSharedSortedListRoot::copyFrom (const cSharedSortedListRoot * inList) {
  if ((inList != NULL) && (inList->mRoot != NULL)) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      checkSortedList (inList->mRoot, inList->mCount, inList->mFirst, inList->mLast COMMA_HERE) ;
    #endif
    MF_Assert (mCount == 0, "mCount (%lld) != 0", mCount, 0) ;
    macroValidSharedObject (inList, const cSharedSortedListRoot) ;
    mCount = inList->mCount ;
    macroMyNew (mRoot, cSortedListNode (inList->mRoot)) ;
    MF_Assert (mFirst == NULL, "mFirst (%p) != NULL", (PMSInt64) mFirst, 0) ;
    buildDirectLinksOnCopy (mRoot, mFirst) ;
    MF_Assert (mLast == NULL, "mLast (%p) != NULL", (PMSInt64) mLast, 0) ;
    buildReverseLinksOnCopy (mRoot, mLast) ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkSortedList (mRoot, mCount, mFirst, mLast COMMA_HERE) ;
  #endif
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Comparison
#endif

//---------------------------------------------------------------------------*

typeComparisonResult cSharedSortedListRoot::objectCompare (const cSharedSortedListRoot * inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (NULL != inOperand) {
    result = kOperandEqual ;
    if (mCount < inOperand->mCount) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mCount > inOperand->mCount) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      cSortedListNode * p1 = mFirst ;
      cSortedListNode * p2 = inOperand->mFirst ;
      while ((NULL != p1) && (NULL != p2) && (result == kOperandEqual)) {
        result = p1->mAttributes.compare (p2->mAttributes) ;
        p1 = p1->mNextPtr ;
        p2 = p1->mNextPtr ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

typeComparisonResult AC_GALGAS_sortedlist::objectCompare (const AC_GALGAS_sortedlist & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid ()) {
    result = mSharedRoot->objectCompare (inOperand.mSharedRoot) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Insertion Implementation
#endif

//---------------------------------------------------------------------------*

static void rotateLeft (cSortedListNode * & ioRootPtr) {
  cSortedListNode * b = ioRootPtr->mSupPtr ;
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

static void rotateRight (cSortedListNode * & ioRootPtr) {
  cSortedListNode * b = ioRootPtr->mInfPtr ;
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

//---------------------------------------------------------------------------*

void cSharedSortedListRoot::addEntry (cSortedListNode * & ioRootPtr,
                                      cSortedListNode * inBeforeNode,
                                      const capSortedListElement & inAttributes,
                                      bool & ioExtension) {
  if (ioRootPtr == NULL) {
    macroMyNew (ioRootPtr, cSortedListNode (inAttributes)) ;
    if (inBeforeNode == NULL) { // New node is the first one
      ioRootPtr->mNextPtr = mFirst ;
      if (mFirst == NULL) {
        mLast = ioRootPtr ;
      }else{
        mFirst->mPreviousPtr = ioRootPtr ;
      }
      mFirst = ioRootPtr ;
    }else{ // Insert new node just after 'inBeforeNode'
      cSortedListNode * next = inBeforeNode->mNextPtr ;
      if (next == NULL) {  // new node becomes the last one
        mLast = ioRootPtr ;
      }else{
        next->mPreviousPtr = ioRootPtr ;
      }
      ioRootPtr->mNextPtr = next ;
      ioRootPtr->mPreviousPtr = inBeforeNode ;
      inBeforeNode->mNextPtr = ioRootPtr ;
    }
    ioExtension = true ;
  }else{
    macroValidPointer (ioRootPtr) ;
    const typeComparisonResult comparaison = ioRootPtr->mAttributes.compareForSorting (inAttributes) ;
    if (comparaison > kOperandEqual) {
      addEntry (ioRootPtr->mInfPtr, inBeforeNode, inAttributes, ioExtension) ;
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
    }else{
      addEntry (ioRootPtr->mSupPtr, ioRootPtr, inAttributes, ioExtension) ;
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
    }
  }
}

//---------------------------------------------------------------------------*

/* static void imprimerArbre (cSortedListNode * inRoot,
                           const PMUInt32 inElementSize) {
  if (inRoot != NULL) {
    imprimerArbre (inRoot->mInfPtr, inElementSize) ;
    C_String s ;
    for (PMUInt32 i=0 ; i<inElementSize ; i++) {
      inRoot->mAttributes [i]->description (s, 0) ;
    }
    printf ("%s\n", s.cString (HERE)) ;
    imprimerArbre (inRoot->mSupPtr, inElementSize) ;
  }
} */

//---------------------------------------------------------------------------*

void cSharedSortedListRoot::addObject (capSortedListElement & inAttributes) {
  if (inAttributes.isValid ()) {
    bool extension = false ; // Unused here
    addEntry (mRoot, NULL, inAttributes, extension) ;
    mCount ++ ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkSortedList (mRoot, mCount, mFirst, mLast COMMA_HERE) ;
  #endif
//  printf ("*** ARBRE\n") ;
//  imprimerArbre (mRoot, mElementSize) ;
//  printf ("*** FIN\n") ;
}

//---------------------------------------------------------------------------*

void AC_GALGAS_sortedlist::addObject (capSortedListElement & inAttributes) {
  if (isValid ()) {
    insulate (HERE) ;
    mSharedRoot->addObject (inAttributes) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Insertion Implementation
#endif

//---------------------------------------------------------------------------*

void cSharedSortedListRoot::appendSortedList (const cSharedSortedListRoot * inList) {
  if (inList != NULL) {
    const cSortedListNode * p = inList->mFirst ;
    while (p != NULL) {
      bool extension = false ; // Unused here
      addEntry (mRoot, NULL, p->mAttributes, extension) ;
      p = p->mNextPtr ;
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkSortedList (mRoot, mCount, mFirst, mLast COMMA_HERE) ;
  #endif
}

//---------------------------------------------------------------------------*

void AC_GALGAS_sortedlist::appendSortedList (const AC_GALGAS_sortedlist & inList) {
  if (NULL != mSharedRoot) {
    mSharedRoot->appendSortedList (inList.mSharedRoot) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Remove Smallest
#endif

//---------------------------------------------------------------------------*

static void supBranchDecreased (cSortedListNode * & ioRoot,
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

static void infBranchDecreased (cSortedListNode * & ioRoot,
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

/* static void getPreviousElement (cSortedListNode * & ioRoot,
                                cSortedListNode * & ioElement,
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
} */

//---------------------------------------------------------------------------*

static void internalRemoveLowestElement (cSortedListNode * & ioRoot,
                                         bool & ioBranchHasBeenRemoved) {
  if (ioRoot->mInfPtr != NULL) {
    internalRemoveLowestElement (ioRoot->mInfPtr, ioBranchHasBeenRemoved) ;
    if (ioBranchHasBeenRemoved) {
      infBranchDecreased (ioRoot, ioBranchHasBeenRemoved) ;
    }
  }else{
    cSortedListNode * p = ioRoot->mSupPtr ;
    ioRoot->mSupPtr = NULL ;
    macroMyDelete (ioRoot) ;
    ioRoot = p ;
    ioBranchHasBeenRemoved = true ;
  }
}

//---------------------------------------------------------------------------*

void cSharedSortedListRoot::removeSmallestObject (capSortedListElement & outAttributes,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkSortedList (mRoot, mCount, mFirst, mLast COMMA_HERE) ;
  #endif
  if (mFirst == NULL) {
    inCompiler->onTheFlyRunTimeError ("'popSmallest' method invoked on an empty list" COMMA_THERE) ;
  }else{
    outAttributes = mFirst->mAttributes ;
    mFirst->mAttributes.drop () ;
  //--- Remove from sequential List
    mFirst = mFirst->mNextPtr ;
    if (mFirst == NULL) {
      mLast = NULL ;
    }else{
      mFirst->mPreviousPtr = NULL ;
    }
  //--- Remove from AVL tree
   bool branchHasBeenRemoved = false ; // Unused here
   internalRemoveLowestElement (mRoot, branchHasBeenRemoved) ;
  //--- 
    mCount -- ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkSortedList (mRoot, mCount, mFirst, mLast COMMA_HERE) ;
  #endif
}

//---------------------------------------------------------------------------*

void AC_GALGAS_sortedlist::removeSmallestObject (capSortedListElement & outAttributes,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  if (NULL != mSharedRoot) {
    mSharedRoot->removeSmallestObject (outAttributes, inCompiler COMMA_HERE) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Remove Greatest
#endif

//---------------------------------------------------------------------------*

static void internalRemoveGreatestElement (cSortedListNode * & ioRoot,
                                           bool & ioBranchHasBeenRemoved) {
  if (ioRoot->mSupPtr != NULL) {
    internalRemoveGreatestElement (ioRoot->mSupPtr, ioBranchHasBeenRemoved) ;
    if (ioBranchHasBeenRemoved) {
      supBranchDecreased (ioRoot, ioBranchHasBeenRemoved) ;
    }
  }else{
    cSortedListNode * p = ioRoot->mInfPtr ;
    ioRoot->mInfPtr = NULL ;
    macroMyDelete (ioRoot) ;
    ioRoot = p ;
    ioBranchHasBeenRemoved = true ;
  }
}

//---------------------------------------------------------------------------*

void cSharedSortedListRoot::removeGreatestObject (capSortedListElement & outAttributes,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkSortedList (mRoot, mCount, mFirst, mLast COMMA_HERE) ;
  #endif
  if (mLast == NULL) {
    inCompiler->onTheFlyRunTimeError ("'popGreatest' method invoked on an empty list" COMMA_THERE) ;
  }else{
    outAttributes = mLast->mAttributes ;
    mLast->mAttributes.drop () ;
  //--- Remove from sequential List
    mLast = mLast->mPreviousPtr ;
    if (mLast == NULL) {
      mFirst = NULL ;
    }else{
      mLast->mNextPtr = NULL ;
    }
  //--- Remove from AVL tree
   bool branchHasBeenRemoved = false ; // Unused here
   internalRemoveGreatestElement (mRoot, branchHasBeenRemoved) ;
  //--- 
    mCount -- ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkSortedList (mRoot, mCount, mFirst, mLast COMMA_HERE) ;
  #endif
}

//---------------------------------------------------------------------------*

void AC_GALGAS_sortedlist::removeGreatestObject (capSortedListElement & outAttributes,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  if (NULL != mSharedRoot) {
    mSharedRoot->removeGreatestObject (outAttributes, inCompiler COMMA_HERE) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark AC_GALGAS_sortedlist
#endif

//---------------------------------------------------------------------------*

AC_GALGAS_sortedlist::AC_GALGAS_sortedlist (void) :
mSharedRoot (NULL) {
}

//---------------------------------------------------------------------------*

AC_GALGAS_sortedlist::AC_GALGAS_sortedlist (const AC_GALGAS_sortedlist & inSource) :
AC_GALGAS_root (),
mSharedRoot (NULL) {
  macroAssignSharedObject (mSharedRoot, inSource.mSharedRoot) ;
}

//---------------------------------------------------------------------------*

AC_GALGAS_sortedlist & AC_GALGAS_sortedlist::operator = (const AC_GALGAS_sortedlist & inSource) {
  macroAssignSharedObject (mSharedRoot, inSource.mSharedRoot) ;
  return *this ;
}

//---------------------------------------------------------------------------*

AC_GALGAS_sortedlist::~ AC_GALGAS_sortedlist (void) {
  macroDetachSharedObject (mSharedRoot) ;
}

//---------------------------------------------------------------------------*

void AC_GALGAS_sortedlist::drop (void) {
  macroDetachSharedObject (mSharedRoot) ;
}

//---------------------------------------------------------------------------*

void AC_GALGAS_sortedlist::createNewEmptySortedList (LOCATION_ARGS) {
  macroMyNew (mSharedRoot, cSharedSortedListRoot (THERE)) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark description
#endif

//---------------------------------------------------------------------------*

void cSharedSortedListRoot::description (C_String & ioString,
                                         const PMSInt32 inIndentation) const {
  ioString << " ("
           << cStringWithUnsigned (mCount)
           << " object" << ((mCount > 1) ? "s" : "")
           << "): " ;
  const cSortedListNode * p = mFirst ;
  PMUInt32 idx = 0 ;
  while (p != NULL) {
    ioString << "\n" ;
    ioString.writeStringMultiple ("| ", inIndentation) ;
    ioString << "|-at " << cStringWithUnsigned (idx) ;
    p->mAttributes.description (ioString, inIndentation + 1) ;
    p = p->mNextPtr ;
    idx ++ ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------*

void AC_GALGAS_sortedlist::description (C_String & ioString,
                                     const PMSInt32 inIndentation) const {
  ioString << "<@"<< staticTypeDescriptor ()->mGalgasTypeName ;
  if (NULL == mSharedRoot) {
    ioString << " not built" ;
  }else{
    mSharedRoot->description (ioString, inIndentation) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Readers
#endif

//---------------------------------------------------------------------------*

GALGAS_uint AC_GALGAS_sortedlist::reader_length (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mSharedRoot->count ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

PMUInt32 AC_GALGAS_sortedlist::count () const {
  PMUInt32 result = 0 ;
  if (isValid ()) {
    result = mSharedRoot->count () ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Methods
#endif

//---------------------------------------------------------------------------*

void cSharedSortedListRoot::smallestObjectAttributeList (capSortedListElement & outAttributes,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  if (mFirst == NULL) {
    inCompiler->onTheFlyRunTimeError ("'smallest' method invoked on an empty list" COMMA_THERE) ;
  }else{
    outAttributes = mFirst->mAttributes ;
  }
}

//---------------------------------------------------------------------------*

void AC_GALGAS_sortedlist::smallestObjectAttributeList (capSortedListElement & outAttributes,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  if (mSharedRoot != NULL) {
    mSharedRoot->smallestObjectAttributeList (outAttributes, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------*

void cSharedSortedListRoot::greatestObjectAttributeList (capSortedListElement & outAttributes,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  if (mLast == NULL) {
    inCompiler->onTheFlyRunTimeError ("'greatest' method invoked on an empty list" COMMA_THERE) ;
  }else{
    outAttributes = mLast->mAttributes ;
  }
}

//---------------------------------------------------------------------------*

void AC_GALGAS_sortedlist::greatestObjectAttributeList (capSortedListElement & outAttributes,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  if (mSharedRoot != NULL) {
    mSharedRoot->greatestObjectAttributeList (outAttributes, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Enumerator
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                 'AC_GALGAS_sortedlist::cEnumerator' class                 *
//                                                                           *
//---------------------------------------------------------------------------*

void cSharedSortedListRoot::populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                                      const typeEnumerationOrder inEnumerationOrder) const {
  inEnumerationArray.setCapacity (mCount) ;
  switch (enumerationOrderValue (inEnumerationOrder)) {
  case kENUMERATION_UP : {
    cSortedListNode * p = mFirst ;
    while (p != NULL) {
      capCollectionElement object ;
      object.setPointer (p->mAttributes.ptr ()) ;
      inEnumerationArray.addObject (object) ;
      p = p->mNextPtr ;
    }
  }break ;
  case kENUMERATION_DOWN : {
    cSortedListNode * p = mLast ;
    while (p != NULL) {
      capCollectionElement object ;
      object.setPointer (p->mAttributes.ptr ()) ;
      inEnumerationArray.addObject (object) ;
      p = p->mPreviousPtr ;
    }
  }break ;
  case kENUMERATION_ENTER_ORDER :
  case kENUMERATION_REVERSE_ENTER_ORDER :
    MF_RunTimeError ("invalid inEnumerationOrder %lld", enumerationOrderValue (inEnumerationOrder), 0) ;
    break ;
  }
  MF_Assert (mCount == inEnumerationArray.count (), "mCount %lld != inEnumerationArray.count () %lld", mCount, inEnumerationArray.count ()) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    checkSortedList (mRoot, mCount, mFirst, mLast COMMA_HERE) ;
  #endif
}

//---------------------------------------------------------------------------*

void AC_GALGAS_sortedlist::populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                                     const typeEnumerationOrder inEnumerationOrder) const {
  if (mSharedRoot != NULL) {
    mSharedRoot->populateEnumerationArray (inEnumerationArray, inEnumerationOrder) ;
  }
}

//---------------------------------------------------------------------------*


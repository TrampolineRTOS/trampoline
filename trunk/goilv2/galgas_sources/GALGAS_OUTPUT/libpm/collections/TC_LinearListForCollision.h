//-----------------------------------------------------------------------------*
//                                                                             *
//  Declaration and implementation of the template class                     *
//                'TC_LinearListForCollision'                                *
//                                                                             *
//  This class implements hash table collision resolution with a linear      *
//  ordered list.                                                            *
//                                                                             *
//  COPY OF ITS INSTANCES IS FORBIDDEN BY REDEFINITION OF COPY CONSTRUCTOR   *
//  AND ASSIGNMENT OPERATOR.                                                 *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2001 Pierre Molinaro.                                      *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, Ecole Centrale de Nantes                                            *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#ifndef TEMPLATE_CLASS_LINEAR_ORDERED_LIST_FOR_COLLISION_RESOLUTION_DEFINED
#define TEMPLATE_CLASS_LINEAR_ORDERED_LIST_FOR_COLLISION_RESOLUTION_DEFINED

//-----------------------------------------------------------------------------*

#include <stddef.h>

//-----------------------------------------------------------------------------*
//                                                                             *
//       Class of linear list                                                *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO>
class TC_LinearListForCollision {
//--- Constructor and destructor
  public : TC_LinearListForCollision (void) ;
  public : ~TC_LinearListForCollision (void) ;

//--- Search or insert
  public : inline INFO * search_or_insert (const INFO & inInfo,
                                           bool & outInsertionPerformed) ;

//--- Tranfert object in a new map array
  public : void transfertElementsInNewMapArray (TC_LinearListForCollision<INFO> * inNewMapArray,
                                                const PMUInt32 inNewSize) ;

//--- Unmark objects
  public : void unmarkAllObjects (void) ;

//--- Sweep unmarked objects
  public : PMUInt32 sweepUnmarkedObjects (void) ;

//--- Internal class of an element
  protected : class TC_linearlist_element {
    public : INFO mInfo ;
    public : TC_linearlist_element * mPtrToNext ;
    public : TC_linearlist_element (const INFO & inInfo) {
      mInfo = inInfo ;
      mPtrToNext = NULL ;
    }
    private : TC_linearlist_element (const TC_linearlist_element & inSource) ;
    private : TC_linearlist_element & operator = (const TC_linearlist_element & inSource) ;
  } ;

//--- Class of allocation info
  protected : class cAllocInfo {
    public : PMSInt32 mCreatedObjectsCount ;
    public : cAllocInfo (void) {
      mCreatedObjectsCount = 0 ;
    }
  } ;

//--- Allocation info (static variable)
  protected : static cAllocInfo smAllocInfo ;

//--- Get created element count
  public : static PMSInt32 getCreatedObjectsCount (void) { return smAllocInfo.mCreatedObjectsCount ; }

//--- Get node size (in bytes)
  public : static PMUInt32 getNodeSize (void) { return sizeof (TC_linearlist_element) ; }

//--- Root
  protected : TC_linearlist_element * mRoot ;

//--- No copy
  private : TC_LinearListForCollision (const TC_LinearListForCollision <INFO> & inSource) ;
  private : TC_LinearListForCollision <INFO> & operator = (const TC_LinearListForCollision <INFO> & inSource) ;

//--- Internal methods
  protected : PMUInt32 internalRecursiveSweep (TC_linearlist_element * inElement) ;
  protected : bool insertElement (TC_linearlist_element * inElement) ;
  protected : static void recursiveTransfertElementsInNewMapArray
                                             (TC_linearlist_element * inElementPointer,
                                              TC_LinearListForCollision<INFO> * inNewMapArray,
                                              const PMUInt32 inNewSize) ;
} ;

//-----------------------------------------------------------------------------*
//                                                                             *
//       Constructor for linear list                                         *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO>
TC_LinearListForCollision<INFO>::TC_LinearListForCollision (void) {
  mRoot = (TC_linearlist_element *) NULL ;
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Destructor for linear list                                          *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO>
TC_LinearListForCollision<INFO>::~TC_LinearListForCollision (void) {
  while (mRoot != NULL) {
    TC_linearlist_element * p = mRoot ;
    mRoot = mRoot->mPtrToNext ;
    delete p ;
  }
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Search and insert if not found                                      *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO>
INFO * TC_LinearListForCollision<INFO>::search_or_insert (const INFO & inInfo,
                                                       bool & outInsertionPerformed) {
  outInsertionPerformed = false ;
//--- Search into list
  TC_linearlist_element * * p = & mRoot ;
  TC_linearlist_element * result = (TC_linearlist_element *) NULL ;
  while (NULL == result) {
    if ((*p) == NULL) { // Insert
      result = new TC_linearlist_element (inInfo) ;
      p = & result ;
      outInsertionPerformed = true ;
      smAllocInfo.mCreatedObjectsCount ++ ;
    }else{
      const PMSInt32 c = (*p)->mInfo.compare (inInfo) ;
      if (c > 0) { // Go to next
        p = & ((*p)->mPtrToNext) ;
      }else if (c < 0) { // Insert
        result = new TC_linearlist_element (inInfo) ;
        result->mPtrToNext = * p ;
        p = & result ;
        outInsertionPerformed = true ;
        smAllocInfo.mCreatedObjectsCount ++ ;
      }else{ // c == 0 : found
        result = * p ;
      }
    }
  }
  return & (result->mInfo) ;
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Insert element                                                      *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO>
bool TC_LinearListForCollision<INFO>::insertElement (TC_linearlist_element * inElement) {
  bool insertionPerformed = false ;
//--- Search into list
  bool continueLooping = true ;
  TC_linearlist_element * & p = mRoot ;
  while (continueLooping) {
    if (p == NULL) { // Insert
      p = inElement ;
      insertionPerformed = true ;
      continueLooping = false ;
    }else{
      const PMSInt32 c = p->mInfo.compare (inElement->mInfo) ;
      if (c > 0) { // Go to next
        & p = & (p->mPtrToNext) ;
      }else if (c < 0) { // Insert
        inElement->mPtrToNext = p ;
        p = inElement ;
        insertionPerformed = true ;
        continueLooping = false ;
      }else{ // c == 0 : found
        continueLooping = false ;
      }
    }
  }
  return insertionPerformed ;
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Sweep unmarked objects                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO>
PMUInt32 TC_LinearListForCollision<INFO>::internalRecursiveSweep (TC_linearlist_element * inElement) {
  PMUInt32 sweepedNodes = 0 ;
  if (inElement != NULL) {
    sweepedNodes += internalRecursiveSweep (inElement->mPtrToNext) ;
    if (inElement->mInfo.isMarked ()) {
      inElement->mInfo.unmark () ;
      inElement->mPtrToNext = mRoot ;
      mRoot = inElement ;
    }else{
      delete inElement ;
      sweepedNodes ++ ;
    }
  }
  return sweepedNodes ;
}

//-----------------------------------------------------------------------------*

template <class INFO>
PMUInt32 TC_LinearListForCollision<INFO>::sweepUnmarkedObjects (void) {
  TC_linearlist_element * temporaryRoot = mRoot ;
  mRoot = (TC_linearlist_element *) NULL ;
  return internalRecursiveSweep (temporaryRoot) ;
}

//-----------------------------------------------------------------------------*

template <class INFO>
void TC_LinearListForCollision<INFO>::unmarkAllObjects (void) {
  TC_linearlist_element * temporary = mRoot ;
  while (temporary != NULL) {
    temporary->mInfo.unmark () ;
    temporary = temporary->mPtrToNext ;
  }
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Tranfert objects in a new map array                                 *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO>
void TC_LinearListForCollision<INFO>
   ::recursiveTransfertElementsInNewMapArray (TC_linearlist_element * inElementPointer,
                                              TC_LinearListForCollision<INFO> * inNewMapArray,
                                              const PMUInt32 inNewSize) {
  if (inElementPointer != NULL) {
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToNext, inNewMapArray, inNewSize) ;
    inElementPointer->mPtrToNext = (TC_linearlist_element *) NULL ;
    const PMUInt32 hash = inElementPointer->mInfo.getHashCodeForMap () % inNewSize ;
    inNewMapArray [hash].insertElement (inElementPointer) ;
  }
}

//-----------------------------------------------------------------------------*

template <class INFO>
void TC_LinearListForCollision<INFO>
      ::transfertElementsInNewMapArray (TC_LinearListForCollision<INFO> * inNewMapArray,
                                        const PMUInt32 inNewSize) {
  recursiveTransfertElementsInNewMapArray (mRoot, inNewMapArray, inNewSize) ;
  mRoot = (TC_linearlist_element *) NULL ;
}

//-----------------------------------------------------------------------------*

#endif

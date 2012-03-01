//---------------------------------------------------------------------------*
//                                                                           *
//  Declaration and implementation of the template class                     *
//  'TC_AVL_TreeForCollision'                                                *
//                                                                           *
//  This class implements a generic ordered binary AVL tree for hash map     *
//  table collision.                                                         *
//                                                                           *
//  COPY OF ITS INSTANCES IS FORBIDDEN BY REDEFINITION OF COPY CONSTRUCTOR   *
//  AND ASSIGNMENT OPERATOR.                                                 *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2001 Pierre Molinaro.                                      *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes                                            *
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

#ifndef TEMPLATE_CLASS_AVLTREE_FOR_COLLISION_RESOLUTION_DEFINED
#define TEMPLATE_CLASS_AVLTREE_FOR_COLLISION_RESOLUTION_DEFINED

//---------------------------------------------------------------------------*

#include <stddef.h>

//---------------------------------------------------------------------------*

#include "collections/TF_AVL_Tree.h"

//---------------------------------------------------------------------------*
//                                                                           *
//       Class of avl trees                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

template <class INFO>
class TC_AVL_TreeForCollision {
//--- Constructor and destructor
  public : TC_AVL_TreeForCollision (void) ;
  public : ~TC_AVL_TreeForCollision (void) ;

//--- Search or insert
  public : INFO * search_or_insert (const INFO & inInfo,
                                    bool & outInsertionPerformed) ;

//--- Unmark objects
  public : void unmarkAllObjects (void) ;

//--- Sweep unmarked objects
  public : PMUInt32 sweepUnmarkedObjects (void) ;

//--- No copy
  private : TC_AVL_TreeForCollision (const TC_AVL_TreeForCollision <INFO> &) ;
  private : TC_AVL_TreeForCollision <INFO> & operator = (const TC_AVL_TreeForCollision <INFO> &) ;

//--- Class of an element
  protected : class TC_avltree_element {
    public : INFO mInfo ;
    public : TC_avltree_element * mPtrToSup ;
    public : TC_avltree_element * mPtrToInf ;
    public : PMSInt8 mBalance ;
    public : TC_avltree_element (const INFO & inInfo) {
      mInfo = inInfo ;
      mPtrToSup = (TC_avltree_element *) NULL ;
      mPtrToInf = (TC_avltree_element *) NULL ;
      mBalance = 0 ;
    }
    public : ~TC_avltree_element (void) {
      delete mPtrToSup ;
      delete mPtrToInf ;
    }
    public : PMSInt32 compare (const TC_avltree_element & inElement) const {
      return mInfo.compare (inElement.mInfo) ;
    }
    private : TC_avltree_element (const TC_avltree_element & inSource) ;
    private : TC_avltree_element & operator = (const TC_avltree_element & inSource) ;
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
  public : static PMUInt32 getNodeSize (void) { return sizeof (TC_avltree_element) ; }

//--- Root
  protected : TC_avltree_element * mRoot ;

//--- Tranfert object in a new map array
  public : void transfertElementsInNewMapArray (TC_AVL_TreeForCollision<INFO> * inNewMapArray,
                                                const PMUInt32 inNewSize) ;

//--- Internal methods
  protected : PMUInt32 internalRecursiveSweep (TC_avltree_element * inElement) ;
  protected : void internalRecursiveUnmark (TC_avltree_element * inElement) ;
  protected : static void recursiveTransfertElementsInNewMapArray
                                             (TC_avltree_element * inElementPointer,
                                              TC_AVL_TreeForCollision<INFO> * inNewMapArray,
                                              const PMUInt32 inNewSize) ;
  protected : static void printNodes (TC_avltree_element * inRootPtr,
                                      const PMSInt32 inIndentation)  ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for avl tree                                            *
//                                                                           *
//---------------------------------------------------------------------------*

template <class INFO>
TC_AVL_TreeForCollision<INFO>::TC_AVL_TreeForCollision (void) {
  mRoot = (TC_avltree_element *) NULL ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Destructor for avl tree                                             *
//                                                                           *
//---------------------------------------------------------------------------*

template <class INFO>
TC_AVL_TreeForCollision<INFO>::~TC_AVL_TreeForCollision (void) {
  delete mRoot ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Search and insert if not found                                      *
//                                                                           *
//---------------------------------------------------------------------------*

template <class INFO>
void TC_AVL_TreeForCollision<INFO>::printNodes (TC_avltree_element * inRootPtr,
                                            const PMSInt32 inIndentation) {
  if (inRootPtr != NULL) {
    for (PMSInt32 i=0 ; i<inIndentation ; i++) {
      printf (" ") ;
    }
    printf ("0x%08lX --> b:%3hd, inf:0x%08lX, sup:0x%08lX",
            inRootPtr, inRootPtr->mBalance, inRootPtr->mPtrToInf, inRootPtr->mPtrToSup) ;
    inRootPtr->mInfo.dump () ;
    printf ("\n") ;
    printNodes (inRootPtr->mPtrToInf, inIndentation + 1) ;
    printNodes (inRootPtr->mPtrToSup, inIndentation + 1) ;
  }
}

//---------------------------------------------------------------------------*

template <class INFO>
INFO * TC_AVL_TreeForCollision<INFO>::search_or_insert (const INFO & inInfo,
                                                    bool & outInsertionPerformed) {
  bool extension ; // unused
  INFO * result = recursiveSearchOrInsert (mRoot, inInfo, extension, outInsertionPerformed) ;
  if (outInsertionPerformed) {
    smAllocInfo.mCreatedObjectsCount ++ ;
  }
//  PMSInt32 maxLevels = 0 ;
//  const bool ok = verifyAVLtree <TC_avltree_element, INFO> (mRoot, LONG_MAX, maxLevels, stdout) ;
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Sweep unmarked objects                                              *
//                                                                           *
//---------------------------------------------------------------------------*

template <class INFO>
PMUInt32 TC_AVL_TreeForCollision<INFO>::internalRecursiveSweep (TC_avltree_element * inElement) {
  PMUInt32 sweepedNodes = 0 ;
  if (inElement != NULL) {
    sweepedNodes += internalRecursiveSweep (inElement->mPtrToInf) ;
    sweepedNodes += internalRecursiveSweep (inElement->mPtrToSup) ;
    inElement->mPtrToInf = (TC_avltree_element *) NULL ;
    inElement->mPtrToSup = (TC_avltree_element *) NULL ;
    inElement->mBalance = 0 ;
    if (inElement->mInfo.isMarked ()) {
      inElement->mInfo.unmark () ;
      bool extension ; // Unused
      bool insertionPerformed ; // Unused
      recursiveInsertElement (mRoot, inElement, extension, insertionPerformed) ;
    }else{
      delete inElement ;
      sweepedNodes ++ ;
    }
  }
  return sweepedNodes ;
}

//---------------------------------------------------------------------------*

template <class INFO>
PMUInt32 TC_AVL_TreeForCollision<INFO>::sweepUnmarkedObjects (void) {
  TC_avltree_element * temporaryRoot = mRoot ;
  mRoot = (TC_avltree_element *) NULL ;
  return internalRecursiveSweep (temporaryRoot) ;
}

//---------------------------------------------------------------------------*

template <class INFO>
void TC_AVL_TreeForCollision<INFO>::internalRecursiveUnmark (TC_avltree_element * inElement) {
  if (inElement != NULL) {
    inElement->mInfo.unmark () ;
    internalRecursiveUnmark (inElement->mPtrToInf) ;
    internalRecursiveUnmark (inElement->mPtrToSup) ;
  }
}

//---------------------------------------------------------------------------*

template <class INFO>
void TC_AVL_TreeForCollision<INFO>::unmarkAllObjects (void) {
  internalRecursiveUnmark (mRoot) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Tranfert objects in a new map array                                 *
//                                                                           *
//---------------------------------------------------------------------------*

template <class INFO>
void TC_AVL_TreeForCollision<INFO>
   ::recursiveTransfertElementsInNewMapArray (TC_avltree_element * inElementPointer,
                                              TC_AVL_TreeForCollision<INFO> * inNewMapArray,
                                              const PMUInt32 inNewSize) {
  if (inElementPointer != NULL) {
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToInf, inNewMapArray, inNewSize) ;
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToSup, inNewMapArray, inNewSize) ;
    inElementPointer->mPtrToInf = (TC_avltree_element *) NULL ;
    inElementPointer->mPtrToSup = (TC_avltree_element *) NULL ;
    inElementPointer->mBalance = 0 ;
    const PMUInt32 hash = inElementPointer->mInfo.getHashCodeForMap () % inNewSize ;
    bool extension ; // Unused
    bool insertionPerformed ; // Unused
    recursiveInsertElement (inNewMapArray [hash].mRoot, inElementPointer, extension, insertionPerformed) ;
  }
}

//---------------------------------------------------------------------------*

template <class INFO>
void TC_AVL_TreeForCollision<INFO>
      ::transfertElementsInNewMapArray (TC_AVL_TreeForCollision<INFO> * inNewMapArray,
                                        const PMUInt32 inNewSize) {
  recursiveTransfertElementsInNewMapArray (mRoot, inNewMapArray, inNewSize) ;
  mRoot = (TC_avltree_element *) NULL ;
}

//---------------------------------------------------------------------------*

#endif

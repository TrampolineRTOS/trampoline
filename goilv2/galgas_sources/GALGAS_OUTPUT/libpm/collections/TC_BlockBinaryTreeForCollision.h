//-----------------------------------------------------------------------------*
//                                                                             *
//  Declaration and implementation of the template class                     *
//                   'TC_BlockBinaryTreeForCollision'                        *
//                                                                             *
//  This class implements a generic ordered binary AVL tree for hash map     *
//   collisions.                                                             *
//                                                                             *
//  For heap efficiency, element are allocated by blocks.                    *
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

#ifndef TEMPLATE_CLASS_BLOCK_BINARY_TREE_FOR_COLLISION_RESOLUTION_DEFINED
#define TEMPLATE_CLASS_BLOCK_BINARY_TREE_FOR_COLLISION_RESOLUTION_DEFINED

//-----------------------------------------------------------------------------*

//#include "collections/TF_AVL_Tree.h"

//-----------------------------------------------------------------------------*

#include <stddef.h>

//-----------------------------------------------------------------------------*
//                                                                             *
//       Class of avl trees                                                  *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
class TC_BlockBinaryTreeForCollision {
//--- Constructor and destructor
  public : TC_BlockBinaryTreeForCollision (void) ;
  public : virtual ~TC_BlockBinaryTreeForCollision (void) ;

//--- Search or insert
  public : inline INFO * search_or_insert (const INFO & inInfo,
                                           bool & outInsertionPerformed) ;

//--- Get marked nodes count
  public : PMSInt32 getMarkedNodesCount (void) const ;

//--- Sweep unmarked objects
  public : PMUInt32 sweepUnmarkedObjects (void) ;

//--- No copy
  private : TC_BlockBinaryTreeForCollision (const TC_BlockBinaryTreeForCollision <INFO, BLOCK_SIZE> &) ;
  private : TC_BlockBinaryTreeForCollision <INFO, BLOCK_SIZE> & operator = (const TC_BlockBinaryTreeForCollision <INFO, BLOCK_SIZE> &) ;

//--- Class of an element
  protected : class TC_element {
    public : INFO mInfo ;
    public : TC_element * mPtrToSup ;
    public : TC_element * mPtrToInf ;
    public : TC_element (const INFO & inInfo) : mInfo (inInfo) {
      mPtrToSup = (TC_element *) NULL ;
      mPtrToInf = (TC_element *) NULL ;
    }
    public : ~TC_element (void) {
      delete mPtrToSup ;
      delete mPtrToInf ;
    }
    public : PMSInt32 compare (const TC_element & inElement) const {
      return mInfo.compare (inElement.mInfo) ;
    }
    public : void * operator new (const size_t inByteSize) ;
    public : void operator delete (void * inPtr) ;
    private : TC_element (const TC_element & inSource) ;
    private : TC_element & operator = (const TC_element & inSource) ;
  } ;
  
//--- Root
  protected : TC_element * mRoot ;

//--- Class of allocation info
  protected : class cAllocInfo {
    public : char * * mAllocatedBlockList ;
    public : PMSInt32 mAllocatedBlockListSize ;
    public : PMSInt32 mAllocatedBlockCount ;
    public : TC_element * mFreeList ;
    public : PMSInt32 mAllocatedObjectsCount ;
    public : PMSInt32 mCreatedObjectsCount ;
    public : cAllocInfo (void) {
      mAllocatedBlockList = (char * *)  NULL ;
      mFreeList = (TC_element *) NULL ;
      mAllocatedObjectsCount = 0 ;
      mAllocatedBlockCount = 0 ;
      mAllocatedBlockListSize = 0 ;
      mCreatedObjectsCount = 0 ;
    }
  } ;

//--- Get node size (in bytes)
  public : static PMUInt32 getNodeSize (void) { return sizeof (TC_element) ; }

//--- Allocation info (static variable)
  protected : static cAllocInfo smAllocInfo ;

//--- Get created element count
  public : static PMSInt32 getCreatedObjectsCount (void) { return smAllocInfo.mCreatedObjectsCount ; }

//--- Get currently used element count
  public : static PMSInt32 getCurrentObjectsCount (void) { return smAllocInfo.mAllocatedObjectsCount ; }

//--- Unmarked all objects
  public : void unmarkAllObjects (void) ;

//--- Allocation of a block
  public : static void allocBlock (void) ;

//--- Tranfert object in a new map array
  public : void transfertElementsInNewMapArray (TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE> * inNewMapArray,
                                                const PMUInt32 inNewSize) ;

//--- Internal methods
  private : static INFO * recursiveSearchOrInsert (TC_element * & ioRootPointer,
                                            const INFO & inInfo,
                                            bool & outInsertionPerformed) ;
  private : static void recursiveInsertElement (TC_element * & ioRootPointer,
                        TC_element * const inElementPointer) ;
  private : PMSInt32 internalMarkedNodeCount (const TC_element * const inElement) const ;
  private : PMUInt32 internalRecursiveSweep (TC_element * inElement) ;
  private : void internalRecursiveUnmark (TC_element * inElement) ;
  private : static void recursiveTransfertElementsInNewMapArray
                                             (TC_element * inElementPointer,
                                              TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE> * inNewMapArray,
                                              const PMUInt32 inNewSize) ;
//--- Friend
  friend class TC_element ;
} ;

//-----------------------------------------------------------------------------*
//                                                                             *
//       Constructor for avl tree                                            *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
void * TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>::TC_element::operator new (const size_t /*inByteSize*/) {
  if (smAllocInfo.mFreeList == NULL) {
    allocBlock () ;
  }
  smAllocInfo.mAllocatedObjectsCount ++ ;
  TC_element * result = smAllocInfo.mFreeList ;
  smAllocInfo.mFreeList = smAllocInfo.mFreeList->mPtrToSup ;
  return result ;
}

//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
void TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>::TC_element::operator delete (void * inPtr) {
  TC_element * p = (TC_element *) inPtr ;
  p->mPtrToSup = smAllocInfo.mFreeList ;
  smAllocInfo.mFreeList = p ;
  smAllocInfo.mAllocatedObjectsCount -- ;
  if (smAllocInfo.mAllocatedObjectsCount == 0) {
    for (PMSInt32 i=0 ; i<smAllocInfo.mAllocatedBlockCount ; i++) {
      delete [] smAllocInfo.mAllocatedBlockList [i] ;
    }
    delete [] smAllocInfo.mAllocatedBlockList ;
    smAllocInfo.mAllocatedBlockList = (char * *) NULL ;
    smAllocInfo.mAllocatedBlockCount = 0 ;
    smAllocInfo.mAllocatedBlockListSize = 0 ;
    smAllocInfo.mFreeList = (TC_element *) NULL ;
  }
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Constructor for avl tree                                            *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
void TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>::allocBlock (void) {
//--- Realloc block list ?
  if (smAllocInfo.mAllocatedBlockListSize <= smAllocInfo.mAllocatedBlockCount) {
    const PMSInt32 newSize = smAllocInfo.mAllocatedBlockCount + 1024 ;
    char ** newBlockList = new char * [newSize] ;
    for (PMSInt32 i=0 ; i<smAllocInfo.mAllocatedBlockCount ; i++) {
      newBlockList [i] = smAllocInfo.mAllocatedBlockList [i] ;
    }
    delete [] smAllocInfo.mAllocatedBlockList ;
    smAllocInfo.mAllocatedBlockList = newBlockList ;
    smAllocInfo.mAllocatedBlockListSize = newSize ;
  }
//--- Alloc block
  smAllocInfo.mAllocatedBlockList [smAllocInfo.mAllocatedBlockCount] = new char [BLOCK_SIZE] ;
  char * ptr = & (smAllocInfo.mAllocatedBlockList [smAllocInfo.mAllocatedBlockCount] [0]) ;
  smAllocInfo.mAllocatedBlockCount ++ ;
  PMSInt32 blockSize = BLOCK_SIZE ;
  const PMSInt32 ALIGNMENT = 32 ;
//--- Align pointer
  if ((((PMSInt32) ptr) % ALIGNMENT) != 0) {
    ptr = (char *) (((((PMSInt32) ptr) / ALIGNMENT) + 1) * ALIGNMENT) ;
    blockSize -= ALIGNMENT ;
  }
  const PMSInt32 nbNewObjects = blockSize / ((PMSInt32) sizeof (TC_element)) ;
  for (PMSInt32 i=0 ; i<nbNewObjects ; i++) {
    TC_element * newObjectPtr = (TC_element *) ptr ;
    newObjectPtr->mPtrToSup = smAllocInfo.mFreeList ;
    smAllocInfo.mFreeList = newObjectPtr ;
    ptr += sizeof (TC_element) ;
  }
  smAllocInfo.mCreatedObjectsCount += nbNewObjects ;
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Constructor for avl tree                                            *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>::TC_BlockBinaryTreeForCollision (void) {
  mRoot = (TC_element *) NULL ;
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Destructor for avl tree                                             *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>::~TC_BlockBinaryTreeForCollision (void) {
  delete mRoot ;
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Search and insert if not found                                      *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
INFO * TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>
::recursiveSearchOrInsert (TC_element * & ioRootPointer,
                           const INFO & inInfo,
                           bool & outInsertionPerformed) {
  INFO * result ;
  if (ioRootPointer == NULL) {
    ioRootPointer = new TC_element (inInfo) ;
    result = & (ioRootPointer->mInfo) ;
    outInsertionPerformed = true ;
  }else{
    outInsertionPerformed = false ;
    const PMSInt32 comp = ioRootPointer->mInfo.compare (inInfo) ;
    if (comp > 0) {
      result = recursiveSearchOrInsert (ioRootPointer->mPtrToSup, inInfo, outInsertionPerformed) ;
    }else if (comp < 0) {
      result = recursiveSearchOrInsert (ioRootPointer->mPtrToInf, inInfo, outInsertionPerformed) ;
    }else{ // Found
      result = & (ioRootPointer->mInfo) ;
      outInsertionPerformed = false ;
    }
  }
  return result ;
}
 
//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
INFO * TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>
::search_or_insert (const INFO & inInfo,
                    bool & outInsertionPerformed) {
  return recursiveSearchOrInsert (mRoot, inInfo, outInsertionPerformed) ;
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Sweep unmarked objects                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
void TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>::
recursiveInsertElement (TC_element * & ioRootPointer,
                        TC_element * const inElementPointer) {
  if (ioRootPointer == NULL) {
    ioRootPointer = inElementPointer ;
    inElementPointer->mPtrToInf = (TC_element *) NULL ;
    inElementPointer->mPtrToSup = (TC_element *) NULL ;
  }else{
    const PMSInt32 comp = ioRootPointer->compare (* inElementPointer) ;
    if (comp > 0) {
      recursiveInsertElement (ioRootPointer->mPtrToSup, inElementPointer) ;
    }else if (comp < 0) {
      recursiveInsertElement (ioRootPointer->mPtrToInf, inElementPointer) ;
    }else{ // Found

    }
  }
}

//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
PMUInt32 TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>
::internalRecursiveSweep (TC_element * inElement) {
  PMUInt32 sweepedNodes = 0 ;
  if (inElement != NULL) {
    sweepedNodes += internalRecursiveSweep (inElement->mPtrToInf) ;
    sweepedNodes += internalRecursiveSweep (inElement->mPtrToSup) ;
    inElement->mPtrToInf = (TC_element *) NULL ;
    inElement->mPtrToSup = (TC_element *) NULL ;
    if (inElement->mInfo.isMarked ()) {
      inElement->mInfo.unmark () ;
      recursiveInsertElement (mRoot, inElement) ;
    }else{
      delete inElement ;
      sweepedNodes ++ ;
    }
  }
  return sweepedNodes ;
}

//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
PMUInt32 TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>::sweepUnmarkedObjects (void) {
  TC_element * temporaryRoot = mRoot ;
  mRoot = (TC_element *) NULL ;
  return internalRecursiveSweep (temporaryRoot) ;
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Tranfert objects in a new map array                                 *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
void TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>
   ::recursiveTransfertElementsInNewMapArray (TC_element * inElementPointer,
                                              TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE> * inNewMapArray,
                                              const PMUInt32 inNewSize) {
  if (inElementPointer != NULL) {
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToInf, inNewMapArray, inNewSize) ;
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToSup, inNewMapArray, inNewSize) ;
    inElementPointer->mPtrToInf = (TC_element *) NULL ;
    inElementPointer->mPtrToSup = (TC_element *) NULL ;
    const PMUInt32 hash = inElementPointer->mInfo.getHashCodeForMap () % inNewSize ;
    recursiveInsertElement (inNewMapArray [hash].mRoot, inElementPointer) ;
  }
}

//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
void TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>
      ::transfertElementsInNewMapArray (TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE> * inNewMapArray,
                                        const PMUInt32 inNewSize) {
  recursiveTransfertElementsInNewMapArray (mRoot, inNewMapArray, inNewSize) ;
  mRoot = (TC_element *) NULL ;
}

//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
void TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>::internalRecursiveUnmark (TC_element * inElement) {
  if (inElement != NULL) {
    inElement->mInfo.unmark () ;
    internalRecursiveUnmark (inElement->mPtrToInf) ;
    internalRecursiveUnmark (inElement->mPtrToSup) ;
  }
}

//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
void TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>::unmarkAllObjects (void) {
  internalRecursiveUnmark (mRoot) ;
}

//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
PMSInt32 TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>::internalMarkedNodeCount (const TC_element * const inElement) const {
  PMSInt32 result = 0 ;
  if (inElement != NULL) {
    if (inElement->mInfo.isMarked ()) {
      result ++ ;
    }
    result += internalMarkedNodeCount (inElement->mPtrToInf) ;
    result += internalMarkedNodeCount (inElement->mPtrToSup) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

template <class INFO, PMSInt32 BLOCK_SIZE>
PMSInt32 TC_BlockBinaryTreeForCollision<INFO, BLOCK_SIZE>::getMarkedNodesCount (void) const {
  return internalMarkedNodeCount (mRoot) ;
}

//-----------------------------------------------------------------------------*

#endif

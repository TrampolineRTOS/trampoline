//---------------------------------------------------------------------------*
//                                                                           *
//  Implementation of class %HASHMAPCLASSTYPE%
//                                                                           *
//  COPY OF ITS INSTANCES IS FORBIDDEN BY REDEFINITION OF COPY CONSTRUCTOR   *
//  AND ASSIGNMENT OPERATOR.                                                 *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2005 Pierre Molinaro.                                      *
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

#include "%INCLUDEPREFIX%%HASHMAPCLASSTYPE%.h"
#include "utilities/F_GetPrime.h"

//---------------------------------------------------------------------------*

%HASHMAPCLASSTYPE%::cAllocInfo %HASHMAPCLASSTYPE%::smAllocInfo ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for avl tree                                            *
//                                                                           *
//---------------------------------------------------------------------------*

void * %HASHMAPCLASSTYPE%::MyBlockavltree_element_for_collision::operator new (const size_t /*inByteSize*/) {
  if (smAllocInfo.mFreeList == NULL) {
    C_TreeForCollision::allocBlock () ;
  }
  smAllocInfo.mAllocatedObjectCount ++ ;
  MyBlockavltree_element_for_collision * result = smAllocInfo.mFreeList ;
  smAllocInfo.mFreeList = smAllocInfo.mFreeList->mPtrToSup ;
  return result ;
}

//---------------------------------------------------------------------------*

void %HASHMAPCLASSTYPE%::MyBlockavltree_element_for_collision::operator delete (void * inPtr) {
  MyBlockavltree_element_for_collision * p = (MyBlockavltree_element_for_collision *) inPtr ;
  p->mPtrToSup = smAllocInfo.mFreeList ;
  smAllocInfo.mFreeList = p ;
  smAllocInfo.mAllocatedObjectCount -- ;
  if (smAllocInfo.mAllocatedObjectCount == 0) {
    for (PMSInt32 i=0 ; i<smAllocInfo.mAllocatedBlockCount ; i++) {
      delete [] smAllocInfo.mAllocatedBlockList [i] ;
    }
    delete [] smAllocInfo.mAllocatedBlockList ;
    smAllocInfo.mAllocatedBlockList = (char * *) NULL ;
    smAllocInfo.mAllocatedBlockCount = 0 ;
    smAllocInfo.mAllocatedBlockListSize = 0 ;
    smAllocInfo.mFreeList = (MyBlockavltree_element_for_collision *) NULL ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for avl tree                                            *
//                                                                           *
//---------------------------------------------------------------------------*

void %HASHMAPCLASSTYPE%::C_TreeForCollision::allocBlock (void) {
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
  smAllocInfo.mAllocatedBlockList [smAllocInfo.mAllocatedBlockCount] = new char [%ALLOCATIONSIZE%] ;
  char * ptr = & (smAllocInfo.mAllocatedBlockList [smAllocInfo.mAllocatedBlockCount] [0]) ;
  smAllocInfo.mAllocatedBlockCount ++ ;
  PMSInt32 blockSize = %ALLOCATIONSIZE% ;
  const PMSInt32 ALIGNMENT = 32 ;
//--- Align pointer
  if ((((PMSInt32) ptr) % ALIGNMENT) != 0) {
    ptr = (char *) (((((PMSInt32) ptr) / ALIGNMENT) + 1) * ALIGNMENT) ;
    blockSize -= ALIGNMENT ;
  }
  const PMSInt32 nbNewObjects = blockSize / ((PMSInt32) sizeof (MyBlockavltree_element_for_collision)) ;
  for (PMSInt32 i=0 ; i<nbNewObjects ; i++) {
    MyBlockavltree_element_for_collision * newObjectPtr = (MyBlockavltree_element_for_collision *) ptr ;
    newObjectPtr->mPtrToSup = smAllocInfo.mFreeList ;
    smAllocInfo.mFreeList = newObjectPtr ;
    ptr += sizeof (MyBlockavltree_element_for_collision) ;
  }
  smAllocInfo.mCreatedObjectCount += nbNewObjects ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for avl tree                                            *
//                                                                           *
//---------------------------------------------------------------------------*

%HASHMAPCLASSTYPE%::C_TreeForCollision::C_TreeForCollision (void) {
  mRoot = NULL ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Destructor for avl tree                                             *
//                                                                           *
//---------------------------------------------------------------------------*

%HASHMAPCLASSTYPE%::C_TreeForCollision::~C_TreeForCollision (void) {
  delete mRoot ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get allocated size (in bytes)                                       *
//                                                                           *
//---------------------------------------------------------------------------*

PMUInt32 %HASHMAPCLASSTYPE%::C_TreeForCollision::getAllocatedSizeInBytes (void) {
  return (PMUInt32) (%ALLOCATIONSIZE% * smAllocInfo.mAllocatedBlockCount) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Rotate left                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

void %HASHMAPCLASSTYPE%::C_TreeForCollision::
rotateLeft (MyBlockavltree_element_for_collision * & ioPtr) {
//--- Rotate 
  MyBlockavltree_element_for_collision * ptr = ioPtr->mPtrToSup ;
  ioPtr->mPtrToSup = ptr->mPtrToInf ;
  ptr->mPtrToInf = ioPtr ;
//--- Update balance 
  if (ptr->mBalance < 0) {
    ioPtr->mBalance -= ptr->mBalance ;
  }
  ioPtr->mBalance ++ ;
  if (ioPtr->mBalance > 0) {
    ptr->mBalance += ioPtr->mBalance ;
  }
  ptr->mBalance ++ ;
  ioPtr = ptr ;
} 

//---------------------------------------------------------------------------*
//                                                                           *
//       Rotate right                                                        *
//                                                                           *
//---------------------------------------------------------------------------*

void %HASHMAPCLASSTYPE%::C_TreeForCollision::
rotateRight (MyBlockavltree_element_for_collision * & ioPtr) {
//--- Rotate 
  MyBlockavltree_element_for_collision * ptr = ioPtr->mPtrToInf ;
  ioPtr->mPtrToInf = ptr->mPtrToSup ;
  ptr->mPtrToSup = ioPtr ;
 //--- Update balance 
  if (ptr->mBalance > 0) {
    ioPtr->mBalance -= ptr->mBalance ;
  }
  ioPtr->mBalance -- ;
  if (ioPtr->mBalance < 0) {
    ptr->mBalance += ioPtr->mBalance ;
  }
  ptr->mBalance-- ;
  ioPtr = ptr ;
}
 
//---------------------------------------------------------------------------*
//                                                                           *
//       Recursive search and insert                                         *
//                                                                           *
//---------------------------------------------------------------------------*

%ELEMENTTYPE% * %HASHMAPCLASSTYPE%::C_TreeForCollision::
avltree_search (MyBlockavltree_element_for_collision * ioRootPointer,
                 const %ELEMENTTYPE% & inInfo) {
  %ELEMENTTYPE% * result = NULL ;
  if (ioRootPointer == NULL) {
    result = (%ELEMENTTYPE% *) NULL ;
  }else{
    const PMSInt32 comp = ioRootPointer->mInfo.compare (inInfo) ;
    if (comp > 0) {
      result = avltree_search (ioRootPointer->mPtrToSup, inInfo) ;
    }else if (comp < 0) {
      result = avltree_search (ioRootPointer->mPtrToInf, inInfo) ;
    }else{ // Found
      result = & (ioRootPointer->mInfo) ;
    }
  }
  return result ;
}
 
//---------------------------------------------------------------------------*
//                                                                           *
//       Recursive search and insert                                         *
//                                                                           *
//---------------------------------------------------------------------------*

%ELEMENTTYPE% * %HASHMAPCLASSTYPE%::C_TreeForCollision::
recursiveSearchOrInsert (MyBlockavltree_element_for_collision * & ioRootPointer,
                         const %ELEMENTTYPE% & inInfo,
                         bool & outExtension,
                         bool & outInsertionPerformed) {
  %ELEMENTTYPE% * result ;
  if (ioRootPointer == NULL) {
    ioRootPointer = new MyBlockavltree_element_for_collision (inInfo) ;
    result = & (ioRootPointer->mInfo) ;
    outExtension = true ;
    outInsertionPerformed = true ;
  }else{
    outInsertionPerformed = false ;
    const PMSInt32 comp = ioRootPointer->mInfo.compare (inInfo) ;
    if (comp > 0) {
      result = recursiveSearchOrInsert (ioRootPointer->mPtrToSup, inInfo, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance -- ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case -1:
          break;
        case -2:
          if (ioRootPointer->mPtrToSup->mBalance == 1) {
            rotateRight (ioRootPointer->mPtrToSup) ;
          }
          rotateLeft (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      result = recursiveSearchOrInsert (ioRootPointer->mPtrToInf, inInfo, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance ++ ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case 1:
          break;
        case 2:
          if (ioRootPointer->mPtrToInf->mBalance == -1) {
            rotateLeft (ioRootPointer->mPtrToInf) ;
          }
          rotateRight (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      result = & (ioRootPointer->mInfo) ;
      outExtension = false;
    }
  }
  return result ;
}
 
//---------------------------------------------------------------------------*
//                                                                           *
//       Search and insert if not found                                      *
//                                                                           *
//---------------------------------------------------------------------------*

%ELEMENTTYPE% * %HASHMAPCLASSTYPE%::C_TreeForCollision::
search_or_insert (const %ELEMENTTYPE% & inInfo,
                  bool & outInsertionPerformed) {
  bool unused = false ;
  return recursiveSearchOrInsert (mRoot, inInfo, unused, outInsertionPerformed) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Search only                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

%ELEMENTTYPE% * %HASHMAPCLASSTYPE%::C_TreeForCollision::
search (const %ELEMENTTYPE% & inInfo) {
  return avltree_search (mRoot, inInfo) ;
}

//---------------------------------------------------------------------------*

void %HASHMAPCLASSTYPE%::C_TreeForCollision::
recursiveInsertElement (MyBlockavltree_element_for_collision * & ioRootPointer,
                        MyBlockavltree_element_for_collision * const inElementPointer,
                        bool & outExtension,
                        bool & outInsertionPerformed) {
  if (ioRootPointer == NULL) {
    ioRootPointer = inElementPointer ;
    inElementPointer->mPtrToInf = NULL ;
    inElementPointer->mPtrToSup = NULL ;
    inElementPointer->mBalance = 0 ;
    outExtension = true ;
    outInsertionPerformed = true ;
  }else{
    const PMSInt32 comp = ioRootPointer->compare (* inElementPointer) ;
    if (comp > 0) {
      recursiveInsertElement (ioRootPointer->mPtrToSup, inElementPointer, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance -- ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case -1:
          break;
        case -2:
          if (ioRootPointer->mPtrToSup->mBalance == 1) {
            rotateRight (ioRootPointer->mPtrToSup) ;
          }
          rotateLeft (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      recursiveInsertElement (ioRootPointer->mPtrToInf, inElementPointer, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance ++ ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case 1:
          break;
        case 2:
          if (ioRootPointer->mPtrToInf->mBalance == -1) {
            rotateLeft (ioRootPointer->mPtrToInf) ;
          }
          rotateRight (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      outInsertionPerformed = false ;
      outExtension = false;
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Sweep unmarked objects                                              *
//                                                                           *
//---------------------------------------------------------------------------*

PMUInt32 %HASHMAPCLASSTYPE%::C_TreeForCollision::internalRecursiveSweep (%HASHMAPCLASSTYPE%::MyBlockavltree_element_for_collision * inElement) {
  PMUInt32 sweepedNodes = 0 ;
  if (inElement != NULL) {
    sweepedNodes += internalRecursiveSweep (inElement->mPtrToInf) ;
    sweepedNodes += internalRecursiveSweep (inElement->mPtrToSup) ;
    inElement->mPtrToInf = NULL ;
    inElement->mPtrToSup = NULL ;
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

PMUInt32 %HASHMAPCLASSTYPE%::C_TreeForCollision::sweepUnmarkedObjects (void) {
  MyBlockavltree_element_for_collision * temporaryRoot = mRoot ;
  mRoot = (MyBlockavltree_element_for_collision *) NULL ;
  return internalRecursiveSweep (temporaryRoot) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Tranfert objects in a new map array                                 *
//                                                                           *
//---------------------------------------------------------------------------*

void %HASHMAPCLASSTYPE%::C_TreeForCollision::
recursiveTransfertElementsInNewMapArray (MyBlockavltree_element_for_collision * const inElementPointer,
                                         C_TreeForCollision * inNewMapArray,
                                         const PMUInt32 inNewSize) {
  if (inElementPointer != NULL) {
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToInf, inNewMapArray, inNewSize) ;
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToSup, inNewMapArray, inNewSize) ;
    inElementPointer->mPtrToInf = (MyBlockavltree_element_for_collision *) NULL ;
    inElementPointer->mPtrToSup = (MyBlockavltree_element_for_collision *) NULL ;
    inElementPointer->mBalance = 0 ;
    const PMUInt32 hash = inElementPointer->mInfo.getHashCodeForMap () % inNewSize ;
    bool extension ; // Unused
    bool insertionPerformed ; // Unused
    recursiveInsertElement (inNewMapArray [hash].mRoot, inElementPointer, extension, insertionPerformed) ;
  }
}

//---------------------------------------------------------------------------*

void %HASHMAPCLASSTYPE%::C_TreeForCollision::
transfertElementsInNewMapArray (C_TreeForCollision * inNewMapArray,
                                const PMUInt32 inNewSize) {
  recursiveTransfertElementsInNewMapArray (mRoot, inNewMapArray, inNewSize) ;
  mRoot = (MyBlockavltree_element_for_collision *) NULL ;
}

//---------------------------------------------------------------------------*

void %HASHMAPCLASSTYPE%::C_TreeForCollision::
internalRecursiveUnmark (MyBlockavltree_element_for_collision * inElement) {
  if (inElement != NULL) {
    inElement->mInfo.unmark () ;
    internalRecursiveUnmark (inElement->mPtrToInf) ;
    internalRecursiveUnmark (inElement->mPtrToSup) ;
  }
}

//---------------------------------------------------------------------------*

void %HASHMAPCLASSTYPE%::C_TreeForCollision::
unmarkAllObjects (void) {
  internalRecursiveUnmark (mRoot) ;
}

//---------------------------------------------------------------------------*

PMSInt32 %HASHMAPCLASSTYPE%::C_TreeForCollision::
internalMarkedNodeCount (const MyBlockavltree_element_for_collision * const inElement) const {
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

//---------------------------------------------------------------------------*

PMSInt32 %HASHMAPCLASSTYPE%::C_TreeForCollision::
getMarkedNodesCount (void) const {
  return internalMarkedNodeCount (mRoot) ;
}

//---------------------------------------------------------------------------*

%HASHMAPCLASSTYPE%
::%HASHMAPCLASSTYPE% (void) {
  mMapArray = & mMinimumMapArray ;
  mEntryCurrentCount = 1 ;
}

//---------------------------------------------------------------------------*

%HASHMAPCLASSTYPE%::~%HASHMAPCLASSTYPE% (void) {
  if (mEntryCurrentCount > 1) {
    delete [] mMapArray ;
  }
}

//---------------------------------------------------------------------------*

%ELEMENTTYPE% * %HASHMAPCLASSTYPE%::
search_or_insert (const %ELEMENTTYPE% & inInfo,
                  bool & outInsertionPerformed) {
  PMUInt32 hashCode = inInfo.getHashCodeForMap () ;
  hashCode %= (PMUInt32) mEntryCurrentCount ;
  return mMapArray [hashCode].search_or_insert (inInfo, outInsertionPerformed) ;
}

//---------------------------------------------------------------------------*

%ELEMENTTYPE% * %HASHMAPCLASSTYPE%::
search (const %ELEMENTTYPE% & inInfo) {
  PMUInt32 hashCode = inInfo.getHashCodeForMap () ;
  hashCode %= (PMUInt32) mEntryCurrentCount ;
  return mMapArray [hashCode].search (inInfo) ;
}

//---------------------------------------------------------------------------*

PMUInt32 %HASHMAPCLASSTYPE%::sweepUnmarkedObjects (void) {
  PMUInt32 sweepedNodes = 0 ;
  for (PMSInt32 i=0 ; i<mEntryCurrentCount ; i++) {
    sweepedNodes += mMapArray [i].sweepUnmarkedObjects () ;
  }
  return sweepedNodes ;
}

//---------------------------------------------------------------------------*

PMUInt32 %HASHMAPCLASSTYPE%
::getMapSizeInBytes (void) const {
  return ((PMUInt32) mEntryCurrentCount) * sizeof (C_TreeForCollision) ;
}

//---------------------------------------------------------------------------*

void %HASHMAPCLASSTYPE%
::reallocMap (const PMSInt32 inNewSize) {
  const PMSInt32 newSize = (inNewSize < 1) ? 1 : getPrimeGreaterThan (inNewSize) ;
  if (newSize != mEntryCurrentCount) {
    C_TreeForCollision * newMapArray = (newSize > 1) ? new C_TreeForCollision [newSize] : (& mMinimumMapArray) ;
    for (PMSInt32 i=0 ; i<mEntryCurrentCount ; i++) {
      mMapArray [i].transfertElementsInNewMapArray (newMapArray, (PMUInt32) newSize) ;
    }
    if (mEntryCurrentCount > 1) {
      delete [] mMapArray ;
    }
    mMapArray = newMapArray ;
    mEntryCurrentCount = newSize ;
  }
}

//---------------------------------------------------------------------------*

void %HASHMAPCLASSTYPE%::unmarkAllObjects (void) {
  for (PMSInt32 i=0 ; i<mEntryCurrentCount ; i++) {
    mMapArray [i].unmarkAllObjects () ;
  }
}

//---------------------------------------------------------------------------*

PMSInt32 %HASHMAPCLASSTYPE%::getMarkedNodesCount (void) const {
  PMSInt32 count = 0 ;
  for (PMSInt32 i=0 ; i<mEntryCurrentCount ; i++) {
    count += mMapArray [i].getMarkedNodesCount () ;
  }
  return count ;
}

//---------------------------------------------------------------------------*

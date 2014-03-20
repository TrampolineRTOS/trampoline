//---------------------------------------------------------------------------*
//                                                                           *
//                                                                           *
//                                                                           *
//  For heap efficiency, elements are allocated by blocks.                   *
//                                                                           *
//  COPY OF ITS INSTANCES IS FORBIDDEN BY REDEFINITION OF COPY CONSTRUCTOR   *
//  AND ASSIGNMENT OPERATOR.                                                 *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2005 Pierre Molinaro.                                      *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                             *
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

#ifndef %HASHMAPCLASSTYPE%_DEFINED
#define %HASHMAPCLASSTYPE%_DEFINED

//---------------------------------------------------------------------------*

%INCLUDEINHEADER%

//---------------------------------------------------------------------------*

#include <stddef.h>

//---------------------------------------------------------------------------*

class %HASHMAPCLASSTYPE% {
//--- Constructor
  public : %HASHMAPCLASSTYPE% (void) ;

//--- Destructor
  public : virtual ~%HASHMAPCLASSTYPE% (void) ;

//--- Search or insert
  public : %ELEMENTTYPE% * search_or_insert (const %ELEMENTTYPE% & inInfo,
                                                   bool & outInsertionPerformed) ;

//--- Search
  public : %ELEMENTTYPE% * search (const %ELEMENTTYPE% & inInfo) ;

//--- Change size
  public : void reallocMap (const PMSInt32 inNewSize) ;

//--- Get map size (in bytes)
  public : PMUInt32 getMapSizeInBytes (void) const ;

//--- Get marked nodes count
  public : PMSInt32 getMarkedNodesCount (void) const ;

//--- Sweep unmarked objects
  public : PMUInt32 sweepUnmarkedObjects (void) ;

//--- Unmarked all objects
  public : void unmarkAllObjects (void) ;

//--- Current Entry count
  protected : PMSInt32 mEntryCurrentCount ;
  public : inline PMSInt32 getHashMapEntryCount (void) const { return mEntryCurrentCount ; }

//--- Get node size (in bytes)
  public : static PMUInt32 getNodeSize (void) { return sizeof (MyBlockavltree_element_for_collision) ; }

//--- No copy
  private : %HASHMAPCLASSTYPE% (const %HASHMAPCLASSTYPE% &) ;
  private : void operator = (const %HASHMAPCLASSTYPE% &) ;

  private : class MyBlockavltree_element_for_collision ;
  
//------------------- C_TreeForCollision embedded class
  private : class C_TreeForCollision {
//--- Constructor and destructor
  public : C_TreeForCollision (void) ;
  public : virtual ~C_TreeForCollision (void) ;

//--- Search or insert
  public : %ELEMENTTYPE% * search_or_insert (const %ELEMENTTYPE% & inInfo,
                                                   bool & outInsertionPerformed) ;

//--- Search
  public : inline %ELEMENTTYPE% * search (const %ELEMENTTYPE% & inInfo) ;

//--- Get marked nodes count
  public : PMSInt32 getMarkedNodesCount (void) const ;

//--- Sweep unmarked objects
  public : PMUInt32 sweepUnmarkedObjects (void) ;

//--- No copy
  private : C_TreeForCollision (const C_TreeForCollision &) ;
  private : void operator = (const C_TreeForCollision &) ;
  
//--- Root
  protected : MyBlockavltree_element_for_collision * mRoot ;

//--- Unmarked all objects
  public : void unmarkAllObjects (void) ;

//--- Allocation of a block
  public : static void allocBlock (void) ;

//--- Get allocated size (in bytes)
  public : static PMUInt32 getAllocatedSizeInBytes (void) ;

//--- Transfer object in a new map array
  public : void transfertElementsInNewMapArray (C_TreeForCollision * inNewMapArray,
                                                const PMUInt32 inNewSize) ;

//--- Internal methods
  protected : static void rotateLeft (MyBlockavltree_element_for_collision * & ioPtr) ;

  protected : static void rotateRight (MyBlockavltree_element_for_collision * & ioPtr) ;

  protected : %ELEMENTTYPE% * avltree_search (MyBlockavltree_element_for_collision * ioRootPointer,
                                                       const %ELEMENTTYPE% & inInfo) ;

  protected : %ELEMENTTYPE% * recursiveSearchOrInsert (MyBlockavltree_element_for_collision * & ioRootPointer,
                                                             const %ELEMENTTYPE% & inInfo,
                                                             bool & outExtension,
                                                             bool & outInsertionPerformed) ;

  protected : static void recursiveInsertElement (MyBlockavltree_element_for_collision * & ioRootPointer,
                                           MyBlockavltree_element_for_collision * const inElementPointer,
                                           bool & outExtension,
                                           bool & outInsertionPerformed) ;

  protected : PMSInt32 internalMarkedNodeCount (const MyBlockavltree_element_for_collision * const inElement) const ;

  protected : PMUInt32 internalRecursiveSweep (MyBlockavltree_element_for_collision * inElement) ;

  protected : void internalRecursiveUnmark (MyBlockavltree_element_for_collision * inElement) ;

  protected : static void recursiveTransfertElementsInNewMapArray
                                             (MyBlockavltree_element_for_collision * const inElementPointer,
                                              C_TreeForCollision * inNewMapArray,
                                              const PMUInt32 inNewSize) ;
//--- Friend
  friend class MyBlockavltree_element_for_collision ;
  friend class cAllocInfo ;
} ;

//------------------- MyBlockavltree_element_for_collision embedded class
  private : class MyBlockavltree_element_for_collision {
    public : %ELEMENTTYPE% mInfo ;
    public : MyBlockavltree_element_for_collision * mPtrToSup ;
    public : MyBlockavltree_element_for_collision * mPtrToInf ;
    public : PMSInt32 mBalance ;
    public : MyBlockavltree_element_for_collision (const %ELEMENTTYPE% & inInfo) : mInfo (inInfo) {
      mPtrToSup = (MyBlockavltree_element_for_collision *) NULL ;
      mPtrToInf = (MyBlockavltree_element_for_collision *) NULL ;
      mBalance = 0 ;
    }
    public : ~MyBlockavltree_element_for_collision (void) {
      delete mPtrToSup ;
      delete mPtrToInf ;
    }
    public : PMSInt32 compare (const MyBlockavltree_element_for_collision & inElement) const {
      return mInfo.compare (inElement.mInfo) ;
    }
    public : void * operator new (const size_t inByteSize) ;
    public : void operator delete (void * inPtr) ;
    private : MyBlockavltree_element_for_collision (const MyBlockavltree_element_for_collision & inSource) ;
    private : void operator = (const MyBlockavltree_element_for_collision & inSource) ;
  } ;

//------------------- MyBlockavltree_element_for_collision embedded class
  private : class cAllocInfo {
    public : char * * mAllocatedBlockList ;
    public : PMSInt32 mAllocatedBlockListSize ;
    public : PMSInt32 mAllocatedBlockCount ;
    public : MyBlockavltree_element_for_collision * mFreeList ;
    public : PMSInt32 mAllocatedObjectCount ;
    public : PMSInt32 mCreatedObjectCount ;
    public : cAllocInfo (void) {
      mAllocatedBlockList = (char * *)  NULL ;
      mFreeList = (MyBlockavltree_element_for_collision *) NULL ;
      mAllocatedObjectCount = 0 ;
      mAllocatedBlockCount = 0 ;
      mAllocatedBlockListSize = 0 ;
      mCreatedObjectCount = 0 ;
    }
  } ;

//--- Minimum map array (1 entry)
  protected : C_TreeForCollision mMinimumMapArray ;

//--- map array
  protected : C_TreeForCollision * mMapArray ;

//--- Get created element count
  public : static PMSInt32 getCreatedObjectCount (void) { return smAllocInfo.mCreatedObjectCount ; }

//--- Get currently used element count
  public : static PMSInt32 getCurrentObjectCount (void) { return smAllocInfo.mAllocatedObjectCount ; }

//--- Allocation info (static variable)
  protected : static cAllocInfo smAllocInfo ;
} ;

//---------------------------------------------------------------------------*

#endif

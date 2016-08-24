//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  GALGAS Type Inspector (for introspection)                                                                          *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2010, ..., 2011 Pierre Molinaro.                                                                     *
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

#include "galgas2/C_galgas_type_descriptor.h"
#include "strings/C_String.h"
#include "galgas2/C_galgas_io.h"

//---------------------------------------------------------------------------------------------------------------------*

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  GALGAS type reference (for type introspection)                                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ======== C_galgas_type_descriptor
#endif

//---------------------------------------------------------------------------------------------------------------------*

static C_galgas_type_descriptor * gGalgasTypeListRoot = NULL ;
static int32_t gSlotID = 0 ;

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_type_descriptor::C_galgas_type_descriptor (const char * inGalgasTypeName,
                                                    const C_galgas_type_descriptor * inSuperClassDescriptor) :
mNextType (NULL),
mPreviousType (NULL),
mBalance (0),
mGalgasTypeName (inGalgasTypeName),
mSlotID (gSlotID),
mSuperclassDescriptor (inSuperClassDescriptor) {
  gSlotID ++ ;
  bool extension = false ; // Unused here
  recursiveInsert (gGalgasTypeListRoot, this, extension) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_galgas_type_descriptor::recursiveGetSortedTypeList (C_galgas_type_descriptor * inRoot,
                                                           TC_UniqueArray <C_galgas_type_descriptor *> & ioTypeList) {
  if (NULL != inRoot) {
    recursiveGetSortedTypeList (inRoot->mPreviousType, ioTypeList) ;
    ioTypeList.addObject (inRoot) ;
    recursiveGetSortedTypeList (inRoot->mNextType, ioTypeList) ;  
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_galgas_type_descriptor::typeListRoot (TC_UniqueArray <C_galgas_type_descriptor *> & outTypeList) {
  recursiveGetSortedTypeList (gGalgasTypeListRoot, outTypeList) ;
} 

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Insertion Implementation
#endif

//---------------------------------------------------------------------------------------------------------------------*

void C_galgas_type_descriptor::rotateLeft (C_galgas_type_descriptor * & ioRootPtr) {
  C_galgas_type_descriptor * b = ioRootPtr->mNextType ;
  ioRootPtr->mNextType = b->mPreviousType ;
  b->mPreviousType = ioRootPtr;

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

//---------------------------------------------------------------------------------------------------------------------*

void C_galgas_type_descriptor::rotateRight (C_galgas_type_descriptor * & ioRootPtr) {
  C_galgas_type_descriptor * b = ioRootPtr->mPreviousType ;
  ioRootPtr->mPreviousType = b->mNextType ;
  b->mNextType = ioRootPtr ;
 
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

void C_galgas_type_descriptor::recursiveInsert (C_galgas_type_descriptor * & ioRootPtr,
                                                C_galgas_type_descriptor * inDescriptor,
                                                bool & ioExtension) {
  if (ioRootPtr == NULL) {
    ioExtension = true ;
    ioRootPtr = inDescriptor ;
  }else{
    const int32_t comparaison = strcmp (ioRootPtr->mGalgasTypeName, inDescriptor->mGalgasTypeName) ;
    if (comparaison > 0) {
      recursiveInsert (ioRootPtr->mPreviousType, inDescriptor, ioExtension) ;
      if (ioExtension) {
        ioRootPtr->mBalance++;
        if (ioRootPtr->mBalance == 0) {
          ioExtension = false;
        }else if (ioRootPtr->mBalance == 2) {
          if (ioRootPtr->mPreviousType->mBalance == -1) {
            rotateLeft (ioRootPtr->mPreviousType) ;
          }
          rotateRight (ioRootPtr) ;
          ioExtension = false;
        }
      }
    }else if (comparaison < 0) {
      recursiveInsert (ioRootPtr->mNextType, inDescriptor, ioExtension) ;
      if (ioExtension) {
        ioRootPtr->mBalance-- ;
        if (ioRootPtr->mBalance == 0) {
          ioExtension = false ;
        }else if (ioRootPtr->mBalance == -2) {
          if (ioRootPtr->mNextType->mBalance == 1) {
            rotateRight (ioRootPtr->mNextType) ;
          }
          rotateLeft (ioRootPtr) ;
          ioExtension = false;
        }
      }
    }else{
      ioExtension = false;
      C_String errorMessage ;
      errorMessage << "FATAL ERROR (type '@" << inDescriptor->mGalgasTypeName << "' already defined)" ;
      fatalError (errorMessage, __FILE__, __LINE__) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

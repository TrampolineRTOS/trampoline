//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Declaration and implementation of the template class 'TC_UniqueSparseArray'                                        *
//                                                                                                                     *
//  COPY OF ITS INSTANCES IS FORBIDDEN BY REDEFINITION OF COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR.                    *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2008 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes                                          *
//  ECN, Ecole Centrale de Nantes (France)                                                                             *
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

#ifndef UNIQUE_GENERIC_SPARSE_ARRAY_IS_DEFINED
#define UNIQUE_GENERIC_SPARSE_ARRAY_IS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_Assert.h"
#include "utilities/M_SourceLocation.h"
#include "utilities/TF_Swap.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Template class predeclaration                                                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> class TC_UniqueSparseArray ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   swap function for TC_UniqueSparseArray <TYPE> classes                                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
void swap (TC_UniqueSparseArray <TYPE> & ioOperand1,
           TC_UniqueSparseArray <TYPE> & ioOperand2) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Template class declaration                                                                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> class TC_UniqueSparseArray {
//--- Default Constructor
  public : TC_UniqueSparseArray (const TYPE & inDefaultValue) ;
  
//--- Virtual Destructor
  public : virtual ~TC_UniqueSparseArray (void) ;

//--- No copy
  private : TC_UniqueSparseArray (const TC_UniqueSparseArray <TYPE> &) ;
  private : TC_UniqueSparseArray <TYPE> & operator = (const TC_UniqueSparseArray <TYPE> &) ;

//--- Remove all objects and deallocate
  public : void free (void) ;

//--- Set entry
  public : void setObjectAtIndex (const TYPE & inValue,
                                  const uint32_t inIndex) ;

//--- Get entry
  public : TYPE objectAtIndex (const uint32_t inIndex) const ;
  
//--- Is default Value at index ?
  public : bool isDefaultObjectAtIndex (const uint32_t inIndex) const ;

//--- Find first entry with index
//    Search from ioIndex the first explicit found entry
//    On return :
//      - returns false if no entry found (ioIndex unknown)
//      - return true if found, and ioIndex points to this entry
  public : bool findFirstEntryWithIndex (uint32_t & ioIndex) const ;

//--- Embedded classes
  protected : typedef struct { TYPE mObjectArray [256] ; uint32_t mExplicitValueFlags [32] ; } TC_arrayL ;
  protected : typedef struct { TC_arrayL * mArrayL [256] ; } TC_arrayH ;
  protected : typedef struct { TC_arrayH * mArrayH [256] ; } TC_arrayU ;

//--- Protected attributes
  protected : TC_arrayU * mArray [256] ;
  protected : TYPE mDefaultValue ;

//--- Internal methods
  protected : void freeArrayH (TC_arrayH * & ioArrayH) ;
  protected : void freeArrayU (TC_arrayU * & ioArrayU) ;
  protected : bool findFirstEntryWithIndexAfterNotFound (uint32_t & ioIndex) const ;

//--- swap
  friend void swap <TYPE> (TC_UniqueSparseArray <TYPE> & ioOperand1,
                           TC_UniqueSparseArray <TYPE> & ioOperand2) ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Default Constructor                                                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
TC_UniqueSparseArray <TYPE>::TC_UniqueSparseArray (const TYPE & inDefaultValue) :
mDefaultValue (inDefaultValue) {
  for (int32_t i=0 ; i<256 ; i++) {
    mArray [i] = NULL ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Destructor                                                                                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
TC_UniqueSparseArray <TYPE>::~TC_UniqueSparseArray (void) {
  free () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Remove all objects and deallocate                                                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
void TC_UniqueSparseArray <TYPE>::freeArrayH (TC_arrayH * & ioArrayH) {
  if (ioArrayH != NULL) {
    for (int32_t i=0 ; i<256 ; i++) {
      macroMyDelete (ioArrayH->mArrayL [i]) ;
    }
    macroMyDelete (ioArrayH) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
void TC_UniqueSparseArray <TYPE>::freeArrayU (TC_arrayU * & ioArrayU) {
  if (ioArrayU != NULL) {
    for (int32_t i=0 ; i<256 ; i++) {
      freeArrayH (ioArrayU->mArrayH [i]) ;
    }
    macroMyDelete (ioArrayU) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
void TC_UniqueSparseArray <TYPE>::free (void) {
  for (int32_t i=0 ; i<256 ; i++) {
    freeArrayU (mArray [i]) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Set entry                                                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
void TC_UniqueSparseArray <TYPE>::
setObjectAtIndex (const TYPE & inValue,
                  const uint32_t inIndex) {
  const uint32_t primaryIndex = inIndex >> 24 ;
  const uint32_t indexU = (inIndex >> 16) & 255 ;
  const uint32_t indexH = (inIndex >> 8) & 255 ;
  const uint32_t indexL = inIndex & 255 ;
//--- Primary
  TC_arrayU * & upperArrayRef = mArray [primaryIndex] ;
  if (upperArrayRef == NULL) {
    macroMyNew (upperArrayRef, TC_arrayU) ;
    for (int32_t i=0 ; i<256 ; i++) {
      upperArrayRef->mArrayH [i] = NULL ;
    }
  }
//--- Upper
  TC_arrayH * & highArrayRef = upperArrayRef->mArrayH [indexU] ;
  if (highArrayRef == NULL) {
    macroMyNew (highArrayRef, TC_arrayH) ;
    for (int32_t i=0 ; i<256 ; i++) {
      highArrayRef->mArrayL [i] = NULL ;
    }
  }
//--- High
  TC_arrayL * & lowArrayRef = highArrayRef->mArrayL [indexH] ;
  if (lowArrayRef == NULL) {
    macroMyNew (lowArrayRef, TC_arrayL) ;
    for (int32_t i=0 ; i<256 ; i++) {
      lowArrayRef->mObjectArray [i] = mDefaultValue ;
    }
    for (int32_t i=0 ; i<32 ; i++) {
      lowArrayRef->mExplicitValueFlags [i] = 0 ; // All are default value
    }
  }
//---
  lowArrayRef->mObjectArray [indexL] = inValue ;
  lowArrayRef->mExplicitValueFlags [indexL >> 5] |= 1 << (indexL & 31) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Object at index                                                                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
TYPE TC_UniqueSparseArray <TYPE>::
objectAtIndex (const uint32_t inIndex) const {
  TYPE result = mDefaultValue ;
  const uint32_t primaryIndex = inIndex >> 24 ;
  TC_arrayU * upperArrayRef = mArray [primaryIndex] ;
  if (upperArrayRef != NULL) {
    const uint32_t indexU = (inIndex >> 16) & 255 ;
    TC_arrayH * highArrayRef = upperArrayRef->mArrayH [indexU] ;
    if (highArrayRef != NULL) {
      const uint32_t indexH = (inIndex >> 8) & 255 ;
      TC_arrayL * lowArrayRef = highArrayRef->mArrayL [indexH] ;
      if (lowArrayRef != NULL) {
        const uint32_t indexL = inIndex & 255 ;
        result = lowArrayRef->mObjectArray [indexL] ;
      }
    }
  }
//---
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Default object at index                                                                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
bool TC_UniqueSparseArray <TYPE>::
findFirstEntryWithIndex (uint32_t & ioIndex) const {
//  const uint32_t start = ioIndex ; printf ("SEARCH FROM 0x%X\n", start) ;
  bool found = false ;
  uint32_t primaryIndex = ioIndex >> 24 ;
  uint32_t indexU = (ioIndex >> 16) & 255 ;
  uint32_t indexH = (ioIndex >> 8) & 255 ;
  uint32_t indexL = ioIndex & 255 ;
//--- Primary
  found = mArray [primaryIndex] != NULL ;
  if (! found) {
    indexU = 0 ;
    indexH = 0 ;
    indexL = 0 ;
  }
  primaryIndex ++ ;
  while ((primaryIndex < 256) && ! found) {
    found = mArray [primaryIndex] != NULL ;
    primaryIndex ++ ;
  }
  primaryIndex -- ;
//--- Upper
  if (found) {
    const TC_arrayU * upperArrayRef = mArray [primaryIndex] ;
    found = upperArrayRef->mArrayH [indexU] != NULL ;
    if (! found) {
      indexH = 0 ;
      indexL = 0 ;
    }
    indexU ++ ;
    while ((indexU < 256) && ! found) {
      found = upperArrayRef->mArrayH [indexU] != NULL ;
      indexU ++ ;
    }
    indexU -- ;
  //--- High
    if (! found) {
      MF_Assert (primaryIndex < 256, "primaryIndex (%ld) should be <= 255", (int32_t) primaryIndex, 0) ;
      MF_Assert (indexU      == 255, "indexU (%ld) should be == 255", (int32_t) indexU, 0) ;
      ioIndex = (primaryIndex << 24) | (indexU << 16) ;
      ioIndex += 1 << 16 ;
      found = findFirstEntryWithIndexAfterNotFound (ioIndex) ;
    }else{
      const TC_arrayH * highArrayRef = upperArrayRef->mArrayH [indexU] ;
      found = highArrayRef->mArrayL [indexH] != NULL ;
      if (! found) {
        indexL = 0 ;
      }
      indexH ++ ;
      while ((indexH < 256) && ! found) {
        found = highArrayRef->mArrayL [indexH] != NULL ;
        indexH ++ ;
      }
      indexH -- ;
    //--- Low
      if (! found) {
        MF_Assert (primaryIndex < 256, "primaryIndex (%ld) should be <= 255", (int32_t) primaryIndex, 0) ;
        MF_Assert (indexU       < 256, "indexU (%ld) should be <= 255", (int32_t) indexU, 0) ;
        MF_Assert (indexH      == 255, "indexH (%ld) should be == 255", (int32_t) indexH, 0) ;
        ioIndex = (primaryIndex << 24) | (indexU << 16) | (indexH << 8) ;
        ioIndex += 256 ;
        found = findFirstEntryWithIndexAfterNotFound (ioIndex) ;
      }else{
        const TC_arrayL * lowArrayRef = highArrayRef->mArrayL [indexH] ;
        found = (lowArrayRef->mExplicitValueFlags [indexL >> 5] & (1 << (indexL & 31))) != 0 ;
        indexL ++ ;
        while ((indexL < 256) && ! found) {
          found = (lowArrayRef->mExplicitValueFlags [indexL >> 5] & (1 << (indexL & 31))) != 0 ;
          indexL ++ ;
        }
        indexL -- ;
      //--- Computing result index
        MF_Assert (primaryIndex < 256, "primaryIndex (%ld) should be <= 255", (int32_t) primaryIndex, 0) ;
        MF_Assert (indexU       < 256, "indexU (%ld) should be <= 255", (int32_t) indexU, 0) ;
        MF_Assert (indexH       < 256, "indexH (%ld) should be <= 255", (int32_t) indexH, 0) ;
        MF_Assert (indexL       < 256, "indexL (%ld) should be <= 255", (int32_t) indexL, 0) ;
        ioIndex = (primaryIndex << 24) | (indexU << 16) | (indexH << 8) | indexL ;
        if (! found) {
          MF_Assert (indexL == 255, "indexL (%ld) should be == 255", (int32_t) indexL, 0) ;
          ioIndex ++ ;
          found = findFirstEntryWithIndexAfterNotFound (ioIndex) ;
        }
      }
    }
  }
//---
//  printf ("RESULT FROM 0x%X:%s, address 0x%X\n", start, found ? "found" : "not found", ioIndex) ;
  return found ;
}

//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
bool TC_UniqueSparseArray <TYPE>::
findFirstEntryWithIndexAfterNotFound (uint32_t & ioIndex) const {
  bool found = false ;
  if (ioIndex != 0) {
    found = findFirstEntryWithIndex (ioIndex) ;
  }
  return found ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Default object at index                                                                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
bool TC_UniqueSparseArray <TYPE>::
isDefaultObjectAtIndex (const uint32_t inIndex) const {
  bool result = true ;
  const uint32_t primaryIndex = inIndex >> 24 ;
  TC_arrayU * upperArrayRef = mArray [primaryIndex] ;
  if (upperArrayRef != NULL) {
    const uint32_t indexU = (inIndex >> 16) & 255 ;
    TC_arrayH * highArrayRef = upperArrayRef->mArrayH [indexU] ;
    if (highArrayRef != NULL) {
      const uint32_t indexH = (inIndex >> 8) & 255 ;
      TC_arrayL * lowArrayRef = highArrayRef->mArrayL [indexH] ;
      if (lowArrayRef != NULL) {
        const uint32_t indexL = inIndex & 255 ;
        result = (lowArrayRef->mExplicitValueFlags [indexL >> 5] & (1 << (indexL & 31))) == 0 ;
      }
    }
  }
//--- Low
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   swap function for TC_UniqueSparseArray <TYPE> classes                                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
void swap (TC_UniqueSparseArray <TYPE> & ioOperand1,
           TC_UniqueSparseArray <TYPE> & ioOperand2) {
  swap (ioOperand1.mDefaultValue, ioOperand2.mDefaultValue) ;
  swap (ioOperand1.mArray, ioOperand2.mArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#endif

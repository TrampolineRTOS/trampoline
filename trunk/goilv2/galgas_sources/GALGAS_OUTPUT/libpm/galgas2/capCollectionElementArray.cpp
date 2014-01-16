//---------------------------------------------------------------------------*
//                                                                           *
//  capCollectionElementArray                                                *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2010, ..., 2013 Pierre Molinaro.                           *
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

#include "capCollectionElementArray.h"
#include "utilities/MF_MemoryControl.h"

//---------------------------------------------------------------------------*

#include "strings/C_String.h"
#include "galgas2/C_Compiler.h"

//---------------------------------------------------------------------------*

capCollectionElementArray::capCollectionElementArray (void) :
mArray (NULL),
mCapacity (0),
mCount (0) {
}

//---------------------------------------------------------------------------*

capCollectionElementArray::capCollectionElementArray (const PMUInt32 inCapacity) :
mArray (NULL),
mCapacity (0),
mCount (0) {
  setCapacity (inCapacity) ;
}

//---------------------------------------------------------------------------*

capCollectionElementArray::capCollectionElementArray (const capCollectionElementArray & inSource) :
mArray (NULL),
mCapacity (0),
mCount (0) {
  setCapacity (inSource.mCount) ;
  for (PMUInt32 i=0 ; i<inSource.mCount ; i++) {
    addObject (inSource.objectAtIndex (i COMMA_HERE)) ;
  }
}

//---------------------------------------------------------------------------*

capCollectionElementArray & capCollectionElementArray::operator = (const capCollectionElementArray & inSource) {
  removeAllObjects () ;
  setCapacity (inSource.mCount) ;
  for (PMUInt32 i=0 ; i<inSource.mCount ; i++) {
    addObject (inSource.objectAtIndex (i COMMA_HERE)) ;
  }
  return *this ;
}

//---------------------------------------------------------------------------*

capCollectionElementArray::~capCollectionElementArray (void) {
  macroMyDeleteArray (mArray) ;
}

//---------------------------------------------------------------------------*

void capCollectionElementArray::setCapacity (const PMUInt32 inNewCapacity) {
  if (inNewCapacity > mCapacity) {
    PMUInt32 newCapacity = (mCapacity > 8) ? mCapacity : 8 ;
    while (newCapacity < inNewCapacity) {
      newCapacity <<= 1 ;
    }
    // printf ("inNewCapacity %u, current %u, new %u\n", inNewCapacity, mCapacity, newCapacity) ;
    capCollectionElement * newArray = NULL ;
    macroMyNewArray (newArray, capCollectionElement, newCapacity) ;
    for (PMUInt32 i=0 ; i<mCount ; i++) {
      newArray [i] = mArray [i] ;
    }
    macroMyDeleteArray (mArray) ;
    mArray = newArray ;
    mCapacity = newCapacity ;
  }
}

//---------------------------------------------------------------------------*

void capCollectionElementArray::addObject (const capCollectionElement & inObject) {
  MF_Assert (mCount < mCapacity, "mCount (%lld) >= mCapacity (%lld)", mCount, mCapacity) ;
  mArray [mCount] = inObject ;
  mCount ++ ;
}

//---------------------------------------------------------------------------*

void capCollectionElementArray::addObjectAtIndex (const capCollectionElement & inObject,
                                                  const PMUInt32 inInsertionIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  MF_Assert (mCount < mCapacity, "mCount (%lld) >= mCapacity (%lld)", mCount, mCapacity) ;
  if (inInsertionIndex <= mCount) {
    for (PMUInt32 i=mCount ; i>inInsertionIndex ; i--) {
      mArray [i] = mArray [i-1] ;
    }
    mArray [inInsertionIndex] = inObject ;
    mCount ++ ;
  }else{
    C_String s = "insertAtIndex: insertion index (" ;
    s << inInsertionIndex << ") > length (" << mCount << ")" ;
    inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------*

void capCollectionElementArray::replaceObjectAtIndex (const capCollectionElement & inObject,
                                                      const PMUInt32 inIndex
                                                      COMMA_LOCATION_ARGS) {
  MF_AssertThere (inIndex < mCount, "inIndex (%ld) >= mCount (%ld)", inIndex, mCount) ;
  mArray [inIndex] = inObject ;
}

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS 
  capCollectionElement capCollectionElementArray::objectAtIndex (const PMUInt32 inIndex
                                                                 COMMA_LOCATION_ARGS) const {
    MF_AssertThere (inIndex < mCount, "inIndex (%ld) >= mCount (%ld)", inIndex, mCount) ;
    return mArray [inIndex] ;
  }
#endif

//---------------------------------------------------------------------------*

cCollectionElement * capCollectionElementArray::pointerAtIndex (const PMUInt32 inIndex
                                                                COMMA_LOCATION_ARGS) {
  mArray [inIndex].insulate () ;
  MF_AssertThere (inIndex < mCount, "inIndex (%ld) >= mCount (%ld)", inIndex, mCount) ;
  return mArray [inIndex].ptr () ;
}

//---------------------------------------------------------------------------*

const cCollectionElement * capCollectionElementArray::pointerAtIndexForReadAccess (const PMUInt32 inIndex
                                                                                   COMMA_LOCATION_ARGS) const {
  MF_AssertThere (inIndex < mCount, "inIndex (%ld) >= mCount (%ld)", inIndex, mCount) ;
  return mArray [inIndex].ptr () ;
}

//---------------------------------------------------------------------------*

void capCollectionElementArray::removeObjectAtIndex (const PMUInt32 inIndex) {
  MF_Assert (mCount > inIndex, "mCount (%ld) <= inIndex (%lld)", mCount, inIndex) ;
  for (PMUInt32 i=inIndex+1 ; i<mCount ; i++) {
    mArray [i - 1] = mArray [i] ;
  }
  mCount -- ;
  mArray [mCount].drop () ;
}

//---------------------------------------------------------------------------*

void capCollectionElementArray::predendObject (const capCollectionElement & inObject) {
  MF_Assert (mCount < mCapacity, "mCount (%lld) >= mCapacity (%lld)", mCount, mCapacity) ;
  for (PMUInt32 i=mCount ; i>0 ; i--) {
    mArray [i] = mArray [i-1] ;
  }
  mArray [0] = inObject ;
  mCount ++ ;
}

//---------------------------------------------------------------------------*

void capCollectionElementArray::removeAllObjects (void) {
  for (PMUInt32 i=0 ; i<mCount ; i++) {
    mArray [i].drop () ;
  }
  mCount = 0 ;
}

//---------------------------------------------------------------------------*

typeComparisonResult capCollectionElementArray::compareCollectionElementArray (const capCollectionElementArray & inOperand) const {
  typeComparisonResult result = kOperandEqual ;
  if (mCount < inOperand.mCount) {
    result = kFirstOperandLowerThanSecond ;
  }else if (mCount > inOperand.mCount) {
    result = kFirstOperandGreaterThanSecond ;
  }else{
    for (PMUInt32 i=0 ; (i<mCount) && (result == kOperandEqual) ; i++) {
      result = mArray [i].compare (inOperand.mArray [i]) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

//----------------------------------------------------------------------------------------------------------------------
//
//  Declaration and implementation of the template class 'TC_Array2'                             
//
//  It implements a generic two dimensions dynamic sized array.                                  
//
//  COPY OF ITS INSTANCES IS ALLOWED AND FULLY IMPLEMENTED BY DUPLICATION.                       
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1997 Pierre Molinaro.                                                          
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//----------------------------------------------------------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "utilities/MF_MemoryControl.h"
#include "utilities/TF_Swap.h"

//----------------------------------------------------------------------------------------------------------------------

#include <stddef.h>

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> class TC_Array2 ;

template <typename TYPE> void swap (TC_Array2 <TYPE> & ioOperand1,
                                    TC_Array2 <TYPE> & ioOperand2) ;

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> class TC_Array2 {
  protected : TYPE * mArray ;
  protected : int32_t mCurrentRowCount ;
  protected : int32_t mCurrentColumnCount ;
  protected : int32_t mCapacity ;

//--- Constructors
  public : TC_Array2 (void) ;
  public : TC_Array2 (const int32_t inRowCount,
                      const int32_t inColumnCount COMMA_LOCATION_ARGS) ;

//--- Destructor
  public : virtual ~TC_Array2 (void) ;

//--- Handle copy
  public : TC_Array2 (TC_Array2 <TYPE> & inSource) ;
  public : TC_Array2 <TYPE> & operator = (TC_Array2 <TYPE> & inSource) ;

//--- Get Row and Column count
  public : inline int32_t rowCount (void) const { return mCurrentRowCount ; }
  public : inline int32_t columnCount (void) const { return mCurrentColumnCount ; }

//--- Acces
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : TYPE & operator () (const int32_t inRowIndex, const int32_t inColumnIndex COMMA_LOCATION_ARGS) ;
    public : const TYPE operator () (const int32_t inRowIndex, const int32_t inColumnIndex COMMA_LOCATION_ARGS) const ;
    protected : size_t long2size_t (const int32_t inRowIndex, const int32_t inColumnIndex COMMA_LOCATION_ARGS) const {
      MF_AssertThere (inRowIndex >= 0, "indice ligne (%ld) < 0", inRowIndex, 0) ;
      MF_AssertThere (inRowIndex < mCurrentRowCount, "indice ligne (%ld) >= nombre de lignes (%ld)", inRowIndex, mCurrentRowCount) ;
      MF_AssertThere (inColumnIndex >= 0, "indice colonne (%ld) < 0", inColumnIndex, 0) ;
      MF_AssertThere (inColumnIndex < mCurrentColumnCount, "indice ligne (%ld) >= nombre de colonnes (%ld)", inColumnIndex, mCurrentColumnCount) ;
      return (size_t) (inRowIndex * mCurrentColumnCount + inColumnIndex) ;
    }
    public : void setObjectAtIndexes (const TYPE & inObject,
                                      const int32_t inRowIndex,
                                      const int32_t inColumnIndex
                                      COMMA_LOCATION_ARGS) ;
  #endif

  #ifdef DO_NOT_GENERATE_CHECKINGS
    public : inline TYPE & operator () (const int32_t inRowIndex,
                                        const int32_t inColumnIndex) {
      return mArray [(size_t) (inRowIndex * mCurrentColumnCount + inColumnIndex)] ;
    }
    public : inline const TYPE operator () (const int32_t inRowIndex,
                                            const int32_t inColumnIndex) const {
      return mArray [(size_t) (inRowIndex * mCurrentColumnCount + inColumnIndex)] ;
    }
    public : inline void setObjectAtIndexes (const TYPE & inObject,
                                             const int32_t inRowIndex,
                                             const int32_t inColumnIndex
                                             COMMA_LOCATION_ARGS) {
      mArray [(size_t) (inRowIndex * mCurrentColumnCount + inColumnIndex)] = inObject ;
    }
  #endif

//--- Vider
  public : virtual void removeAll (void) ;

//--- Exchange
  friend void swap <TYPE> (TC_Array2 <TYPE> & ioOperand1,
                           TC_Array2 <TYPE> & ioOperand2) ;

//--- Changer la taille da la matrice
  public : void reallocArray (const int32_t inRowCount,
                              const int32_t inColumnCount COMMA_LOCATION_ARGS) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//                         Implementation                                                        
//
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array2 <TYPE>::TC_Array2 (void) :
mArray (NULL),
mCurrentRowCount (0),
mCurrentColumnCount (0),
mCapacity (0) {
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array2 <TYPE>::TC_Array2 (TC_Array2 <TYPE> & inSource) :
mArray (NULL),
mCurrentRowCount (0),
mCurrentColumnCount (0),
mCapacity (0) {
  *this = inSource ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array2 <TYPE>::TC_Array2 (const int32_t inRowCount,
                                                      const int32_t inColumnCount
                                                      COMMA_LOCATION_ARGS)  :
mArray (NULL),
mCurrentRowCount (0),
mCurrentColumnCount (0),
mCapacity (0){
  reallocArray (inRowCount, inColumnCount COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array2 <TYPE> & TC_Array2 <TYPE>::operator = (TC_Array2 <TYPE> & inSource) {
  removeAll () ;
  const int32_t tailleSource = inSource.mCurrentRowCount * inSource.mCurrentColumnCount ;
  if (tailleSource == 0) {
    mCurrentRowCount = inSource.mCurrentRowCount ;
    mCurrentColumnCount = inSource.mCurrentColumnCount ;
  }else{
    try{
      macroMyNewArray (mArray, TYPE, tailleSource) ;
      for (int32_t i=0 ; i<tailleSource ; i++) {
        mArray [(size_t) i] = inSource.mArray [(size_t) i] ;
      }
      mCurrentRowCount = inSource.mCurrentRowCount ;
      mCurrentColumnCount = inSource.mCurrentColumnCount ;
    }catch (...) {
      macroMyDeleteArray (mArray) ;
      throw ;
    }
  }
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> TC_Array2 <TYPE>::~TC_Array2 (void) {
  removeAll () ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array2<TYPE>::removeAll (void) {
  macroMyDeleteArray (mArray) ;
  mCurrentRowCount = 0 ;
  mCurrentColumnCount = 0 ;
  mCapacity = 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void TC_Array2<TYPE>::reallocArray (const int32_t inRowCount,
                                                             const int32_t inColumnCount COMMA_LOCATION_ARGS) {
  if ((inRowCount != mCurrentRowCount) || (inColumnCount != mCurrentColumnCount)) {
    MF_AssertThere (inRowCount >= 0, "inRowCount (%ld) < 0", inRowCount, 0) ;
    MF_AssertThere (inColumnCount >= 0, "inColumnCount (%ld) < 0", inColumnCount, 0) ;
    const int32_t newNeededSize = inRowCount * inColumnCount ;
    int32_t newCapacity = (mCapacity > 32) ? mCapacity : 32 ;
    while (newCapacity < newNeededSize) {
      newCapacity <<= 1 ;
    }
    TYPE * newArray = NULL ;
    macroMyNewArray (newArray, TYPE, (size_t) newCapacity) ;
    const int32_t maxLigne = (mCurrentRowCount < inRowCount) ? mCurrentRowCount : inRowCount ;
    const int32_t maxColonne = (mCurrentColumnCount < inColumnCount) ? mCurrentColumnCount : inColumnCount ;
    for (int32_t i=0 ; i<maxLigne ; i++) {
      for (int32_t j=0 ; j<maxColonne ; j++) {
        newArray [(size_t) (i * inColumnCount + j)] = mArray [(size_t) (i * mCurrentColumnCount + j)] ;
      }
    }
    macroMyDeleteArray (mArray) ;
    mArray = newArray ; newArray = NULL ;
    mCurrentColumnCount = inColumnCount ;
    mCurrentRowCount = inRowCount ;
    mCapacity = newCapacity ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  template <typename TYPE> TYPE & TC_Array2 <TYPE>::operator () (const int32_t inRowIndex,
                                                                 const int32_t inColumnIndex
                                                                 COMMA_LOCATION_ARGS) {
    return mArray [long2size_t (inRowIndex, inColumnIndex COMMA_THERE)] ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  template <typename TYPE> const TYPE TC_Array2 <TYPE>::operator () (const int32_t inRowIndex,
                                                                     const int32_t inColumnIndex
                                                                     COMMA_LOCATION_ARGS) const {
    return mArray [long2size_t (inRowIndex, inColumnIndex COMMA_THERE)] ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  template <typename TYPE> void TC_Array2 <TYPE>::setObjectAtIndexes (const TYPE & inObject,
                                                                      const int32_t inRowIndex,
                                                                      const int32_t inColumnIndex
                                                                      COMMA_LOCATION_ARGS) {
    mArray [long2size_t (inRowIndex, inColumnIndex COMMA_THERE)] = inObject ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> void swap (TC_Array2 <TYPE> & ioOperand1,
                                    TC_Array2 <TYPE> & ioOperand2) {
  swap (ioOperand1.mArray, ioOperand2.mArray) ;
  swap (ioOperand1.mCurrentRowCount, ioOperand2.mCurrentRowCount) ;
  swap (ioOperand1.mCurrentColumnCount, ioOperand2.mCurrentColumnCount) ;
  swap (ioOperand1.mCapacity, ioOperand2.mCapacity) ;
}

//----------------------------------------------------------------------------------------------------------------------

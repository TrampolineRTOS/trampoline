//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  Declaration and implementation of the template class 'TC_UniqueArray2'                                             *
//                                                                                                                     *
//  It implements a generic two dimensions dynamic sized array.                                                        *
//                                                                                                                     *
//  COPY OF ITS INSTANCES IS NOT ALLOWED.                                                                              *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2014 Pierre Molinaro.                                                                     *
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
//----------------------------------------------------------------------------------------------------------------------

#ifndef UNIQUE_ARRAY2_TEMPLATE_CLASS_DEFINED
#define UNIQUE_ARRAY2_TEMPLATE_CLASS_DEFINED

//----------------------------------------------------------------------------------------------------------------------

#include "utilities/MF_MemoryControl.h"
#include "utilities/TF_Swap.h"

//----------------------------------------------------------------------------------------------------------------------

#include <stddef.h>

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> class TC_UniqueArray2 ;

template <typename TYPE> void swap (TC_UniqueArray2 <TYPE> & ioOperand1,
                                    TC_UniqueArray2 <TYPE> & ioOperand2) ;

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> class TC_UniqueArray2 {
  protected : TYPE * mArray ;
  protected : int32_t mCurrentRowCount ;
  protected : int32_t mCurrentColumnCount ;

//--- Constructor
  public : TC_UniqueArray2 (const int32_t inRowCount,
                            const int32_t inColumnCount) ;

//--- Destructor
  public : virtual ~TC_UniqueArray2 (void) ;

//--- No copy
  private : TC_UniqueArray2 (TC_UniqueArray2 <TYPE> & inSource) ;
  private : TC_UniqueArray2 <TYPE> & operator = (TC_UniqueArray2 <TYPE> & inSource) ;

//--- Get Row and Column count
  public : inline int32_t rowCount (void) const { return mCurrentRowCount ; }
  public : inline int32_t columnCount (void) const { return mCurrentColumnCount ; }

//--- Access
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : TYPE & operator () (const int32_t inRowIndex, const int32_t inColumnIndex COMMA_LOCATION_ARGS) ;
    public : const TYPE & operator () (const int32_t inRowIndex, const int32_t inColumnIndex COMMA_LOCATION_ARGS) const ;
  #endif

  #ifdef DO_NOT_GENERATE_CHECKINGS
    public : inline TYPE & operator () (const int32_t inRowIndex,
                                        const int32_t inColumnIndex) {
      return mArray [(size_t) (inRowIndex * mCurrentColumnCount + inColumnIndex)] ;
    }
    public : inline const TYPE & operator () (const int32_t inRowIndex,
                                              const int32_t inColumnIndex) const {
      return mArray [(size_t) (inRowIndex * mCurrentColumnCount + inColumnIndex)] ;
    }
  #endif

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

//--- Exchange
  friend void swap <TYPE> (TC_UniqueArray2 <TYPE> & ioOperand1,
                           TC_UniqueArray2 <TYPE> & ioOperand2) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                         Implementation                                                                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
TC_UniqueArray2 <TYPE>::
TC_UniqueArray2 (const int32_t inRowCount,
                 const int32_t inColumnCount) :
mArray (NULL),
mCurrentRowCount (0),
mCurrentColumnCount (0) {
  if ((inRowCount > 0) && (inColumnCount > 0)) {
    macroMyNewArray (mArray, TYPE, (size_t) (inRowCount * inColumnCount)) ;
    mCurrentRowCount = inRowCount ;
    mCurrentColumnCount = inColumnCount ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
TC_UniqueArray2 <TYPE>::~TC_UniqueArray2 (void) {
  macroMyDeleteArray (mArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  template <typename TYPE>
  TYPE & TC_UniqueArray2 <TYPE>::operator () (const int32_t inRowIndex, const int32_t inColumnIndex COMMA_LOCATION_ARGS) {
    return mArray [long2size_t (inRowIndex, inColumnIndex COMMA_THERE)] ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  template <typename TYPE>
  const TYPE & TC_UniqueArray2 <TYPE>::operator () (const int32_t inRowIndex, const int32_t inColumnIndex COMMA_LOCATION_ARGS) const {
    return mArray [long2size_t (inRowIndex, inColumnIndex COMMA_THERE)] ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
void swap (TC_UniqueArray2 <TYPE> & ioOperand1,
           TC_UniqueArray2 <TYPE> & ioOperand2) {
  swap (ioOperand1.mArray, ioOperand2.mArray) ;
  swap (ioOperand1.mCurrentRowCount, ioOperand2.mCurrentRowCount) ;
  swap (ioOperand1.mCurrentColumnCount, ioOperand2.mCurrentColumnCount) ;
  swap (ioOperand1.mCapacity, ioOperand2.mCapacity) ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
void TC_UniqueArray2 <TYPE>::setObjectAtIndexes (const TYPE & inObject,
                                                 const int32_t inRowIndex,
                                                 const int32_t inColumnIndex
                                                 COMMA_LOCATION_ARGS) {
  const size_t idx = long2size_t (inRowIndex, inColumnIndex COMMA_THERE) ;
  if (NULL != mArray) {
    mArray [idx] = inObject ;
  }
}

//----------------------------------------------------------------------------------------------------------------------


#endif

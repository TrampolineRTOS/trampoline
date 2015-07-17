//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   G E N E R I C     A R R A Y                                                                                       *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef GENERIC_ARRAY_IS_DEFINED
#define GENERIC_ARRAY_IS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "collections/TC_UniqueArray.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Template class predeclaration                                                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> class TC_Array ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   swap function for TC_Array <TYPE> classes                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> void swap (TC_Array <TYPE> & ioOperand1,
                                    TC_Array <TYPE> & ioOperand2) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Template class declaration                                                                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE> class TC_Array : public TC_UniqueArray <TYPE> {
//--- Default Constructor
  public : TC_Array (void) ;
  
//--- Allocation Constructor (empty array)
  public : TC_Array (const int inAllocatedSize COMMA_LOCATION_ARGS) ;
  
//--- Allocation Constructor (array initialized with inValue)
  public : TC_Array (const int inAllocatedSize,
                     const TYPE & inValue COMMA_LOCATION_ARGS) ;
  
//--- Handle Copy
  public : TC_Array (const TC_Array <TYPE> &) ;
  public : TC_Array <TYPE> & operator = (const TC_Array <TYPE> &) ;

//--- swap
  friend void swap <TYPE> (TC_Array <TYPE> & ioOperand1,
                           TC_Array <TYPE> & ioOperand2) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Default Constructor                                                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
TC_Array <TYPE>::TC_Array (void) :
TC_UniqueArray <TYPE> () {
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Allocation Constructor                                                                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
TC_Array <TYPE>::
TC_Array (const int inAllocatedSize COMMA_LOCATION_ARGS) :
TC_UniqueArray <TYPE> (inAllocatedSize COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Allocation Constructor                                                                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
TC_Array <TYPE>::
TC_Array (const int inAllocatedSize, const TYPE & inValue COMMA_LOCATION_ARGS) :
TC_UniqueArray <TYPE> (inAllocatedSize, inValue COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Copy Constructor                                                                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
TC_Array <TYPE>::TC_Array (const TC_Array <TYPE> & inOperand) :
TC_UniqueArray <TYPE> () {
  if (inOperand.mCount > 0) {
    macroMyNewArray (this->mArray, TYPE, inOperand.mCount) ;
    for (int32_t i=0 ; i<inOperand.mCount ; i++) {
      this->mArray [i] = inOperand.mArray [i] ;
    }
    this->mCount = inOperand.mCount ;
    this->mCapacity = inOperand.mCount ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Assignment Operator                                                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
TC_Array <TYPE> & TC_Array <TYPE>::operator = (const TC_Array <TYPE> & inOperand) {
  if (this->mCapacity < inOperand.mCount) {
    macroMyDeleteArray (this->mArray) ;
    macroMyNewArray (this->mArray, TYPE, inOperand.mCount) ;
    this->mCapacity = inOperand.mCount ;
  }
  for (int32_t i=0 ; i<inOperand.mCount ; i++) {
    this->mArray [i] = inOperand.mArray [i] ;
  }
  this->mCount = inOperand.mCount ;
  return *this ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   swap function for TC_Array <TYPE> classes                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

template <typename TYPE>
void swap (TC_Array <TYPE> & ioOperand1,
           TC_Array <TYPE> & ioOperand2) {
  swap (ioOperand1.mCount, ioOperand2.mCount) ;
  swap (ioOperand1.mCapacity, ioOperand2.mCapacity) ;
  swap (ioOperand1.mArray, ioOperand2.mArray) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#endif

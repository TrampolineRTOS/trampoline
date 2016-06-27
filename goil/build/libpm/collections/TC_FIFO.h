//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  Declaration of the template class 'TC_FIFO'.                                                                       *
//                                                                                                                     *
//  COPY OF ITS INSTANCES IS FORBIDDEN BY REDEFINITION OF COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR.                    *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2001 Pierre Molinaro.                                                                                *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
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
//----------------------------------------------------------------------------------------------------------------------

#ifndef TEMPLATE_CLASS_FIFO_DEFINED
#define TEMPLATE_CLASS_FIFO_DEFINED

//----------------------------------------------------------------------------------------------------------------------

#include <stdio.h>

//----------------------------------------------------------------------------------------------------------------------

#include "utilities/M_SourceLocation.h"
#include "utilities/TF_Swap.h"
#include "utilities/MF_Assert.h"

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//           FIFO template class declaration                                                                           *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE> class TC_FIFO {
//--- Constructor and destructor
  public : TC_FIFO (void) ;
  public : virtual ~TC_FIFO (void) ;
  
//--- No copy
  private : TC_FIFO <TYPE> (TC_FIFO <TYPE> &) ;
  private : void operator = (TC_FIFO <TYPE> &) ;

//--- Length
  public : inline int32_t length (void) const { return mListLength ; }

//--- Empty ?
  public : inline bool isEmpty (void) const { return mListLength == 0 ; }

//--- Insert a new element at head 
  public : void insertByCopy (const TYPE & inInfo) ;
  public : void insertByExchange (TYPE & ioInfo) ;

//--- Delete last element
  public : void deleteLastItem (void) ;

//--- Get and suppress last element
  public : void getByCopyAndSuppressLastItem (TYPE & outInfo) ;
  public : void getByExchangeAndSuppressLastItem (TYPE & outInfo) ;

//--- Direct access
  public : TYPE & operator () (const int32_t inIndex COMMA_LOCATION_ARGS) ;
  public : TYPE & operator () (const int32_t inIndex COMMA_LOCATION_ARGS) const ;

//------- Element class ---------------------
  private : class TC_FIFO_element {
  //--- Constructors
    public : TC_FIFO_element (const TYPE & inSource) ;
    public : TC_FIFO_element (void) ;

  //--- Data members
    private : TYPE mInfo ;
    private : TC_FIFO_element * mNextItem ;

  //--- No copy
    private : TC_FIFO_element (TC_FIFO_element &) ;
    private : void operator = (TC_FIFO_element &) ;
  
  //--- Friend
    friend class TC_FIFO <TYPE> ;
  } ;

//--- Data members
  private : TC_FIFO_element * mFirstItem ;
  private : TC_FIFO_element * mLastItem ;
  private : int32_t mListLength ;
  private : mutable TC_FIFO_element * * mItemsArray ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//           FIFO template class implementation                                                                        *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
TC_FIFO <TYPE>::TC_FIFO_element::TC_FIFO_element (void) :
mInfo (),
mNextItem (NULL) {
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
TC_FIFO <TYPE>::TC_FIFO_element::
TC_FIFO_element (const TYPE & inSource) :
mInfo (inSource),
mNextItem (NULL) {
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
TC_FIFO <TYPE>::TC_FIFO (void) :
mFirstItem (NULL),
mLastItem (NULL),
mListLength (0),
mItemsArray (NULL) {
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
TC_FIFO<TYPE>::
~TC_FIFO (void) {
  macroMyDeleteArray (mItemsArray) ;
  while (mFirstItem != (TC_FIFO_element *) NULL) {
    mLastItem = mFirstItem->mNextItem ;
    macroMyDelete (mFirstItem) ;
    mFirstItem = mLastItem ;
  }
  mListLength = 0 ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
void TC_FIFO<TYPE>::
insertByCopy (const TYPE & inInfo) {
  TC_FIFO_element * p = NULL ;
  macroMyNew (p, TC_FIFO_element (inInfo)) ; // Copy
  if (mLastItem == NULL) {
    mFirstItem = p ;
  }else{
    mLastItem->mNextItem = p ;
  }
  mLastItem = p ;
  mListLength ++ ;
  macroMyDeleteArray (mItemsArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
void TC_FIFO<TYPE>::
insertByExchange (TYPE & ioInfo) {
  TC_FIFO_element * p = NULL ;
  macroMyNew (p, TC_FIFO_element ()) ;
  swap (p->mInfo, ioInfo) ; // Exchange
  if (mLastItem == NULL) {
    mFirstItem = p ;
  }else{
    mLastItem->mNextItem = p ;
  }
  mLastItem = p ;
  mListLength ++ ;
  macroMyDeleteArray (mItemsArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
void TC_FIFO<TYPE>::
deleteLastItem (void) {
  if (mFirstItem != NULL) {
    TC_FIFO_element * p = mFirstItem->mNextItem ;
    macroMyDelete (mFirstItem) ;
    mFirstItem = p ;
    mListLength -- ;
    if (mFirstItem == NULL) {
      mLastItem = NULL ;
    }
  }
  macroMyDeleteArray (mItemsArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
void TC_FIFO <TYPE>::
getByCopyAndSuppressLastItem (TYPE & outInfo) {
  if (mFirstItem != NULL) {
    outInfo = mFirstItem->mInfo ;
    TC_FIFO_element * p = mFirstItem->mNextItem ;
    macroMyDelete (mFirstItem) ;
    mListLength -- ;
    if (mFirstItem == NULL) {
      mLastItem = NULL ;
    }
  }
  macroMyDeleteArray (mItemsArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

template <typename TYPE>
void TC_FIFO<TYPE>::
getByExchangeAndSuppressLastItem (TYPE & outInfo) {
  if (mFirstItem != NULL) {
    swap (outInfo, mFirstItem->mInfo) ;
    TC_FIFO_element * p = mFirstItem->mNextItem ;
    macroMyDelete (mFirstItem) ;
    mFirstItem = p ;
    mListLength -- ;
    if (mFirstItem == NULL) {
      mLastItem = NULL ;
    }
  }
  macroMyDeleteArray (mItemsArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

 template <typename TYPE>
 TYPE & TC_FIFO<TYPE>::
 operator () (const int32_t inIndex COMMA_LOCATION_ARGS) {
   MF_AssertThere (inIndex >= 0, "inIndex (%ld) < 0", inIndex, 0) ;
   MF_AssertThere (inIndex < mListLength, "inIndex (%ld) >= mListLength (%ld)", inIndex, mListLength) ;
   TC_FIFO_element * p = (TC_FIFO_element *) NULL ;
   if (inIndex == 0) {
     p = mFirstItem ;
   }else if (inIndex == (mListLength - 1)) {
     p = mLastItem ;
   }else{
     if (mItemsArray == NULL) {
       macroMyNewArray (mItemsArray, TC_FIFO_element *, mListLength) ;
       p = mFirstItem ;
       for (int32_t i=0 ; i<mListLength ; i++) {
         mItemsArray [i] = p ;
         p = p->mNextItem ;
       }
     }
     p = mItemsArray [inIndex] ;
   }
   return p->mInfo ;
 }

//----------------------------------------------------------------------------------------------------------------------

 template <typename TYPE>
 TYPE & TC_FIFO <TYPE>::
 operator () (const int32_t inIndex COMMA_LOCATION_ARGS) const {
   MF_AssertThere (inIndex >= 0, "inIndex (%ld) < 0", inIndex, 0) ;
   MF_AssertThere (inIndex < mListLength, "inIndex (%ld) >= mListLength (%ld)", inIndex, mListLength) ;
   TC_FIFO_element * p = (TC_FIFO_element *) NULL ;
   if (inIndex == 0) {
     p = mFirstItem ;
   }else if (inIndex == (mListLength - 1)) {
     p = mLastItem ;
   }else{
     if (mItemsArray == NULL) {
       macroMyNewArray (mItemsArray, TC_FIFO_element *, mListLength) ;
       p = mFirstItem ;
       for (int32_t i=0 ; i<mListLength ; i++) {
         mItemsArray [i] = p ;
         p = p->mNextItem ;
       }
     }
     p = mItemsArray [inIndex] ;
   }
   return p->mInfo ;
 }

//----------------------------------------------------------------------------------------------------------------------

#endif

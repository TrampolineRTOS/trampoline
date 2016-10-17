//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'cEnumerator_range' : galgas range enumerator                                                                      *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2012, ..., 2012 Pierre Molinaro.                                                                     *
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

#include "all-predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_range::cEnumerator_range (const GALGAS_range & inEnumeratedRange,
                                      const typeEnumerationOrder inOrder) :
mIsValid (inEnumeratedRange.isValid ()),
mAscending (inOrder == kENUMERATION_UP),
mStart (inEnumeratedRange.mProperty_start.uintValue ()),
mLength (inEnumeratedRange.mProperty_length.uintValue ()),
mCurrent (0) {
  if (mAscending) {
    mCurrent = mStart ;
  }else{
    mCurrent = mStart + mLength - 1 ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_range::~cEnumerator_range (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cEnumerator_range::hasCurrentObject (void) const {
  bool ok = false ;
  if (mIsValid) {
    if (mAscending) {
      ok = mCurrent < (mStart + mLength) ;
    }else{
      ok = mCurrent >= mStart ;
    }
  }
  return ok ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool cEnumerator_range::hasNextObject (void) const {
  bool ok = false ;
  if (mIsValid) {
    if (mAscending) {
      ok = (mCurrent + 1) < (mStart + mLength) ;
    }else{
      ok = mCurrent > mStart ;
    }
  }
  return ok ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cEnumerator_range::gotoNextObject (void) {
  if (mAscending) {
    mCurrent ++ ;
  }else{
    mCurrent -- ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cEnumerator_range::current (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint (hasCurrentObject (), (uint32_t) (mCurrent)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

//-----------------------------------------------------------------------------*
//                                                                             *
//  C_UIntSet : algorithms on sets of PMUInt32                               *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2013, ..., 2013 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#include "utilities/C_UIntSet.h"

//-----------------------------------------------------------------------------*

C_UIntSet::C_UIntSet (void) :
mDefinition () {
}

//-----------------------------------------------------------------------------*

C_UIntSet::C_UIntSet (const PMUInt32 inValue) :
mDefinition () {
  add (inValue) ;
}

//-----------------------------------------------------------------------------*

void C_UIntSet::add (const PMUInt32 inNodeIndex) {
  const PMSInt32 idx = (PMSInt32) (inNodeIndex >> 6) ;
  while (idx >= mDefinition.count ()) {
    mDefinition.addObject (0) ;
  }
  mDefinition (idx COMMA_HERE) |= ((PMUInt64) 1) << (inNodeIndex & 63) ;
}

//-----------------------------------------------------------------------------*

void C_UIntSet::remove (const PMUInt32 inNodeIndex) {
  const PMSInt32 idx = (PMSInt32) (inNodeIndex >> 6) ;
  if (idx < mDefinition.count ()) {
    mDefinition (idx COMMA_HERE) &= ~ (((PMUInt64) 1) << (inNodeIndex & 63)) ;
    while ((mDefinition.count () > 0) && (mDefinition.lastObject (HERE) == 0)) {
      mDefinition.removeLastObject (HERE) ;
    }
  }
}

//-----------------------------------------------------------------------------*

void C_UIntSet::getBoolValueArray (TC_UniqueArray <bool> & outBoolValueArray) const {
  outBoolValueArray.setCountToZero () ;
  for (PMSInt32 i=0 ; i<mDefinition.count () ; i++) {
    for (PMUInt32 j=0 ; j<64 ; j++) {
      outBoolValueArray.addObject ((mDefinition (i COMMA_HERE) & (((PMUInt64) 1) << j)) != 0) ;
    }
  }
//---
  while ((outBoolValueArray.count () > 0) && ! outBoolValueArray.lastObject (HERE)) {
    outBoolValueArray.removeLastObject (HERE) ;  
  }
}
  
//-----------------------------------------------------------------------------*

void C_UIntSet::getValueArray (TC_UniqueArray <PMUInt32> & outValueArray) const {
  outValueArray.setCountToZero () ;
  PMUInt32 idx = 0 ;
  for (PMSInt32 i=0 ; i<mDefinition.count () ; i++) {
    for (PMUInt32 j=0 ; j<64 ; j++) {
      const bool exists = (mDefinition (i COMMA_HERE) & (((PMUInt64) 1) << j)) != 0 ;
      if (exists) {
        outValueArray.addObject (idx) ;
      }
      idx ++ ;
    }
  }
}
  
//-----------------------------------------------------------------------------*

bool C_UIntSet::contains (const PMUInt32 inNodeIndex) const {
  const PMSInt32 idx = (PMSInt32) (inNodeIndex >> 6) ;
  bool result = idx < mDefinition.count () ;
  if (result) {
    result = (mDefinition (idx COMMA_HERE) & (((PMUInt64) 1) << (inNodeIndex & 63))) != 0 ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

PMUInt32 C_UIntSet::firstValueNotIsSet (void) const {
  PMUInt32 result = 0 ;
  if (mDefinition.count () > 0) {
    result = 64 * (((PMUInt32) mDefinition.count ()) - 1) ;
    PMUInt64 v = mDefinition.lastObject (HERE) ;
    while (v != 0) {
      result ++ ;
      v >>= 1 ;
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*

PMUInt32 C_UIntSet::count (void) const {
  PMUInt32 result = 0 ;
  for (PMSInt32 i=0 ; i<mDefinition.count () ; i++) {
    PMUInt64 v = mDefinition (i COMMA_HERE) ;
    while (v != 0) {
      result += (v & 1) != 0 ;
      v >>= 1 ;
    }
  }
  return result ;
}

//-----------------------------------------------------------------------------*

void C_UIntSet::operator &= (const C_UIntSet & inOther) {
  while (mDefinition.count () > inOther.mDefinition.count ()) {
    mDefinition.removeLastObject (HERE) ;
  }
  for (PMSInt32 i=0 ; i<mDefinition.count () ; i++) {
    mDefinition (i COMMA_HERE) &= inOther.mDefinition (i COMMA_HERE) ;
  }
  while ((mDefinition.count () > 0) && (mDefinition.lastObject (HERE) == 0)) {
    mDefinition.removeLastObject (HERE) ;
  }
}

//-----------------------------------------------------------------------------*

void C_UIntSet::operator |= (const C_UIntSet & inOther) {
  while (mDefinition.count () < inOther.mDefinition.count ()) {
    mDefinition.addObject (0) ;
  }
  for (PMSInt32 i=0 ; i<inOther.mDefinition.count () ; i++) {
    mDefinition (i COMMA_HERE) |= inOther.mDefinition (i COMMA_HERE) ;
  }
}

//-----------------------------------------------------------------------------*

static inline PMSInt32 minSInt32 (const PMSInt32 inA, const PMSInt32 inB) {
  return (inA < inB) ? inA : inB ;
}

//-----------------------------------------------------------------------------*

void C_UIntSet::operator -= (const C_UIntSet & inOther) {
  const PMSInt32 n = minSInt32 (mDefinition.count (), inOther.mDefinition.count ()) ;
  for (PMSInt32 i=0 ; i<n ; i++) {
    mDefinition (i COMMA_HERE) &= ~ inOther.mDefinition (i COMMA_HERE) ;
  }
  while ((mDefinition.count () > 0) && (mDefinition.lastObject (HERE) == 0)) {
    mDefinition.removeLastObject (HERE) ;
  }
}

//-----------------------------------------------------------------------------*

bool C_UIntSet::operator == (const C_UIntSet & inOther) const {
  bool result = mDefinition.count () == inOther.mDefinition.count () ;
  for (PMSInt32 i=0 ; (i<mDefinition.count ()) && result ; i++) {
    result = mDefinition (i COMMA_HERE) == inOther.mDefinition (i COMMA_HERE) ;
  }
  return result ;
}

//-----------------------------------------------------------------------------*

bool C_UIntSet::operator != (const C_UIntSet & inOther) const {
  return ! (*this == inOther) ;
}

//-----------------------------------------------------------------------------*

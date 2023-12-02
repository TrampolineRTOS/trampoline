//----------------------------------------------------------------------------------------------------------------------
//
//  C_UIntSet : algorithms on sets of uint32_t                                                   
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2013, ..., 2013 Pierre Molinaro.
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

#include "C_UIntSet.h"

//----------------------------------------------------------------------------------------------------------------------

C_UIntSet::C_UIntSet (void) :
mDefinition () {
}

//----------------------------------------------------------------------------------------------------------------------

C_UIntSet::C_UIntSet (const uint32_t inValue) :
mDefinition () {
  add (inValue) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_UIntSet::add (const uint32_t inNodeIndex) {
  const int32_t idx = (int32_t) (inNodeIndex >> 6) ;
  while (idx >= mDefinition.count ()) {
    mDefinition.appendObject (0) ;
  }
  mDefinition (idx COMMA_HERE) |= ((uint64_t) 1) << (inNodeIndex & 63) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    check () ;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------

void C_UIntSet::remove (const uint32_t inNodeIndex) {
  const int32_t idx = (int32_t) (inNodeIndex >> 6) ;
  if (idx < mDefinition.count ()) {
    mDefinition (idx COMMA_HERE) &= ~ (((uint64_t) 1) << (inNodeIndex & 63)) ;
    while ((mDefinition.count () > 0) && (mDefinition.lastObject (HERE) == 0)) {
      mDefinition.removeLastObject (HERE) ;
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    check () ;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------

void C_UIntSet::getBoolValueArray (TC_UniqueArray <bool> & outBoolValueArray) const {
  outBoolValueArray.removeAllKeepingCapacity () ;
  for (int32_t i=0 ; i<mDefinition.count () ; i++) {
    for (uint32_t j=0 ; j<64 ; j++) {
      outBoolValueArray.appendObject ((mDefinition (i COMMA_HERE) & (((uint64_t) 1) << j)) != 0) ;
    }
  }
//---
  while ((outBoolValueArray.count () > 0) && ! outBoolValueArray.lastObject (HERE)) {
    outBoolValueArray.removeLastObject (HERE) ;  
  }
}
  
//----------------------------------------------------------------------------------------------------------------------

void C_UIntSet::getValueArray (TC_UniqueArray <uint32_t> & outValueArray) const {
  outValueArray.removeAllKeepingCapacity () ;
  uint32_t idx = 0 ;
  for (int32_t i=0 ; i<mDefinition.count () ; i++) {
    for (uint32_t j=0 ; j<64 ; j++) {
      const bool exists = (mDefinition (i COMMA_HERE) & (((uint64_t) 1) << j)) != 0 ;
      if (exists) {
        outValueArray.appendObject (idx) ;
      }
      idx ++ ;
    }
  }
}
  
//----------------------------------------------------------------------------------------------------------------------

bool C_UIntSet::contains (const uint32_t inNodeIndex) const {
  const int32_t idx = (int32_t) (inNodeIndex >> 6) ;
  bool result = idx < mDefinition.count () ;
  if (result) {
    result = (mDefinition (idx COMMA_HERE) & (((uint64_t) 1) << (inNodeIndex & 63))) != 0 ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

uint32_t C_UIntSet::firstValueNotIsSet (void) const {
  uint32_t result = 0 ;
  if (mDefinition.count () > 0) {
    result = 64 * (((uint32_t) mDefinition.count ()) - 1) ;
    uint64_t v = mDefinition.lastObject (HERE) ;
    while (v != 0) {
      result ++ ;
      v >>= 1 ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

uint32_t C_UIntSet::count (void) const {
  uint32_t result = 0 ;
  for (int32_t i=0 ; i<mDefinition.count () ; i++) {
    uint64_t v = mDefinition (i COMMA_HERE) ;
    while (v != 0) {
      result += (v & 1) != 0 ;
      v >>= 1 ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_UIntSet::operator &= (const C_UIntSet & inOther) {
  while (mDefinition.count () > inOther.mDefinition.count ()) {
    mDefinition.removeLastObject (HERE) ;
  }
  for (int32_t i=0 ; i<mDefinition.count () ; i++) {
    mDefinition (i COMMA_HERE) &= inOther.mDefinition (i COMMA_HERE) ;
  }
  while ((mDefinition.count () > 0) && (mDefinition.lastObject (HERE) == 0)) {
    mDefinition.removeLastObject (HERE) ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    check () ;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------

void C_UIntSet::operator |= (const C_UIntSet & inOther) {
  while (mDefinition.count () < inOther.mDefinition.count ()) {
    mDefinition.appendObject (0) ;
  }
  for (int32_t i=0 ; i<inOther.mDefinition.count () ; i++) {
    mDefinition (i COMMA_HERE) |= inOther.mDefinition (i COMMA_HERE) ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    check () ;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------

static inline int32_t minSInt32 (const int32_t inA, const int32_t inB) {
  return (inA < inB) ? inA : inB ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_UIntSet::operator -= (const C_UIntSet & inOther) {
  const int32_t n = minSInt32 (mDefinition.count (), inOther.mDefinition.count ()) ;
  for (int32_t i=0 ; i<n ; i++) {
    mDefinition (i COMMA_HERE) &= ~ inOther.mDefinition (i COMMA_HERE) ;
  }
  while ((mDefinition.count () > 0) && (mDefinition.lastObject (HERE) == 0)) {
    mDefinition.removeLastObject (HERE) ;
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    check () ;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------

bool C_UIntSet::operator == (const C_UIntSet & inOther) const {
  bool result = mDefinition.count () == inOther.mDefinition.count () ;
  for (int32_t i=0 ; (i<mDefinition.count ()) && result ; i++) {
    result = mDefinition (i COMMA_HERE) == inOther.mDefinition (i COMMA_HERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_UIntSet::operator != (const C_UIntSet & inOther) const {
  return ! (*this == inOther) ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void C_UIntSet::check (void) const {
    if (mDefinition.count () > 0) {
      MF_Assert (mDefinition.lastObject (HERE) != 0, "last entry of C_UIntSet is 0", 0, 0) ;
    }
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

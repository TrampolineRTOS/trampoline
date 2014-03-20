//-----------------------------------------------------------------------------*
//                                                                             *
//     C++ template class for implementing a software cache                  *
//                        (size : a prime integer)                           *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2001, ..., 2005 Pierre Molinaro.                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
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

#ifndef CLASS_TEMPLATE_PRIME_CACHE4_DEFINED
#define CLASS_TEMPLATE_PRIME_CACHE4_DEFINED

//-----------------------------------------------------------------------------*

#include "F_GetPrime.h"

//-----------------------------------------------------------------------------*

#include <math.h>
#include <cmath>

//-----------------------------------------------------------------------------*
//                                                                             *
//       Template for implementing three-operands cache                      *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class RESULT>
class TC_prime_cache4 {
//--- Constructor
  public : TC_prime_cache4 (const PMSInt32 inDefaultValueForOperand1,
                                     const PMSInt32 inOperand1NumberOfValues,
                                     const PMSInt32 inCacheSize) ;

//--- Destructor
  public : virtual ~TC_prime_cache4 (void) ;

//--- Cache entry type
  protected : class cCacheEntry {
    public : PMSInt32 mOperand1 ;
    public : PMSInt32 mOperand2 ;
    public : PMSInt32 mOperand3 ;
    public : PMSInt32 mOperand4 ;
    public : RESULT mResult ;
  } ;

//--- Cache read
  public : inline void getCacheEntry (const PMSInt32 inOperand1,
                                      const PMSInt32 inOperand2,
                                      const PMSInt32 inOperand3,
                                      const PMSInt32 inOperand4,
                                      bool & outCacheSuccess,
                                      PMSInt32 & outHashCode,
                                      PMSInt32 & outTag,
                                      RESULT & outResult) ;

//--- Cache write
  public : inline void writeCacheEntry (const PMSInt32 inOperand1,
                                        const PMSInt32 inOperand2,
                                        const PMSInt32 inOperand3,
                                        const PMSInt32 inOperand4,
                                        const PMSInt32 inHashCode,
                                        const PMSInt32 inTag,
                                        const RESULT inResult) ;

//--- Clear all cache entries
  public : void clearAllCacheEntries (void) ;

//--- Realloc cache
  public : void reallocCache (const PMSInt32 inCacheNewSize) ;

//--- Cache array pointer
  protected : cCacheEntry * mCache ;

//--- Number of value of operand 1
  public : PMSInt32 cmOperand1NumberOfValues ;

//--- Cache size
  protected : PMSInt32 mCacheSize ;

//--- Integer parameters for computing hashcode
  protected : PMSInt32 mParameter3 ;
  protected : PMSInt32 mParameter4 ;

//--- Default value for operand 1
  public : const PMSInt32 cmDefaultValueForOperand1 ;

//--- Cache successes
  protected : PMSInt32 mCacheSuccessCount ;
  public : PMSInt32 getCacheSuccessCount (void) const { return mCacheSuccessCount ; }

//--- Cache missises
  protected : PMSInt32 mCacheMissCount ;
  public : PMSInt32 getCacheMissCount (void) const { return mCacheMissCount ; }

//--- Cache missises
  protected : PMSInt32 mCacheOverridesCount ;
  public : PMSInt32 getCacheOverrideCount (void) const { return mCacheOverridesCount ; }

//--- Get cache entries count
  public : PMSInt32 getCacheEntriesCount (void) {
    return mCacheSize ;
  }

//--- Get unused entries count
  public : PMSInt32 getUnusedCacheEntriesCount (void) const {
    PMSInt32 unusedEntriesCount = 0 ;
    for (PMSInt32 i=0 ; i<mCacheSize ; i++) {
      unusedEntriesCount += (mCache [i].mOperand1 == cmDefaultValueForOperand1) ;
    }
    return unusedEntriesCount ;
  }


//--- No copy
  private : TC_prime_cache4 (TC_prime_cache4 <RESULT> &) ;
  private : TC_prime_cache4 <RESULT> & operator = (TC_prime_cache4 <RESULT> &) ;
} ;

//-----------------------------------------------------------------------------*

template <class RESULT>
TC_prime_cache4 <RESULT>::TC_prime_cache4 (const PMSInt32 inDefaultValueForOperand1,
                                           const PMSInt32 inOperand1NumberOfValues,
                                           const PMSInt32 inCacheSize) :
cmOperand1NumberOfValues ((inOperand1NumberOfValues < 1) ? 1 : inOperand1NumberOfValues),
cmDefaultValueForOperand1 (inDefaultValueForOperand1) {
  mCacheSize = getPrimeGreaterThan ((inCacheSize < 1) ? 1 : inCacheSize) ;
  mParameter3 = (PMSInt32) (::pow (mCacheSize / cmOperand1NumberOfValues, 1./3.)) ;
  mParameter4 = mParameter3 * mParameter3 ;
  mParameter3 *= cmOperand1NumberOfValues ;
  mParameter4 *= cmOperand1NumberOfValues ;
  mCacheSuccessCount = 0 ;
  mCacheMissCount = 0 ;
  mCacheOverridesCount = 0 ;
  mCache = new cCacheEntry [mCacheSize] ;
  clearAllCacheEntries () ;
}

//-----------------------------------------------------------------------------*

template <class RESULT>
TC_prime_cache4 <RESULT>::~TC_prime_cache4 (void) {
  delete [] mCache ;
}

//-----------------------------------------------------------------------------*

template <class RESULT>
void TC_prime_cache4 <RESULT>::reallocCache (const PMSInt32 inCacheSize) {
  const PMSInt32 newCacheSize = getPrimeGreaterThan (inCacheSize) ;
  if (newCacheSize != mCacheSize) {
    cCacheEntry * newCache = new cCacheEntry [newCacheSize] ;
    if (newCache != NULL) {
      cCacheEntry * previousCache = mCache ;
      mCache = newCache ;
      const PMSInt32 previousCacheSize = mCacheSize ;
      mCacheSize = newCacheSize ;
      for (PMSInt32 i=0 ; i<newCacheSize ; i++) {
        mCache [i].mOperand1 = cmDefaultValueForOperand1 ;
      }
      mParameter3 = (PMSInt32) (::pow (mCacheSize / cmOperand1NumberOfValues, 1./3.)) ;
      mParameter4 = mParameter3 * mParameter3 ;
      mParameter3 *= cmOperand1NumberOfValues ;
      mParameter4 *= cmOperand1NumberOfValues ;
      bool cacheSuccess ;
      PMSInt32 hashCode ;
      RESULT cacheResult ;
      PMSInt32 tag = 0 ; 
      for (PMSInt32 i=0 ; i<previousCacheSize ; i++) {
        getCacheEntry (previousCache [i].mOperand1,
                       previousCache [i].mOperand2,
                       previousCache [i].mOperand3,
                       previousCache [i].mOperand4,
                       cacheSuccess,
                       hashCode,
                       tag,
                       cacheResult) ;
        if (! cacheSuccess) {
          writeCacheEntry (previousCache [i].mOperand1,
                           previousCache [i].mOperand2,
                           previousCache [i].mOperand3,
                           previousCache [i].mOperand4,
                           hashCode,
                           tag,
                           previousCache [i].mResult) ;
        }
      }
      delete [] previousCache ;
    }
  }
}

//-----------------------------------------------------------------------------*

template <class RESULT>
void TC_prime_cache4 <RESULT>::getCacheEntry (const PMSInt32 inOperand1,
                                                       const PMSInt32 inOperand2,
                                                       const PMSInt32 inOperand3,
                                                       const PMSInt32 inOperand4,
                                                       bool & outCacheSuccess,
                                                       PMSInt32 & outHashCode,
                                                       PMSInt32 & /* outTag */,
                                                       RESULT & outResult) {
//--- Compute hash code
  outHashCode = (PMSInt32) (((PMUInt32) ((inOperand4 * mParameter4)
                                        + (inOperand3 * mParameter3)
                                        + (inOperand2 * cmOperand1NumberOfValues)
                                        + inOperand1)) % ((PMUInt32) mCacheSize)) ;
//--- Cache success ?
  outCacheSuccess = (inOperand1 == mCache [outHashCode].mOperand1)
                 && (inOperand2 == mCache [outHashCode].mOperand2)
                 && (inOperand3 == mCache [outHashCode].mOperand3)
                 && (inOperand4 == mCache [outHashCode].mOperand4) ;
//--- Update counts
  mCacheSuccessCount +=   outCacheSuccess ;
  mCacheMissCount    += ! outCacheSuccess ;
//--- Get result
  outResult = mCache [outHashCode].mResult ;
}

//-----------------------------------------------------------------------------*

template <class RESULT>
void TC_prime_cache4 <RESULT>::writeCacheEntry (const PMSInt32 inOperand1,
                                                         const PMSInt32 inOperand2,
                                                         const PMSInt32 inOperand3,
                                                         const PMSInt32 inOperand4,
                                                         const PMSInt32 inHashCode,
                                                         const PMSInt32 /* inTag */,
                                                         const RESULT inResult) {
//--- Cache overrides ?
  mCacheOverridesCount += (mCache [inHashCode].mOperand1 != cmDefaultValueForOperand1) ;
//--- Write Operands
  mCache [inHashCode].mOperand1 = inOperand1 ;
  mCache [inHashCode].mOperand2 = inOperand2 ;
  mCache [inHashCode].mOperand3 = inOperand3 ;
  mCache [inHashCode].mOperand4 = inOperand4 ;
//--- Write result
  mCache [inHashCode].mResult = inResult ;
}

//-----------------------------------------------------------------------------*

template <class RESULT>
void TC_prime_cache4 <RESULT>::clearAllCacheEntries (void) {
  for (PMSInt32 i=0 ; i<mCacheSize ; i++) {
    mCache [i].mOperand1 = cmDefaultValueForOperand1 ;
  }
}

//-----------------------------------------------------------------------------*

#endif

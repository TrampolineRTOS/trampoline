//---------------------------------------------------------------------------*
//                                                                           *
//     C++ template class for implementing a software cache                  *
//                        (size : a prime integer)                           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2001, ..., 2005 Pierre Molinaro.                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
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

#ifndef CLASS_TEMPLATE_PRIME_CACHE2_DEFINED
#define CLASS_TEMPLATE_PRIME_CACHE2_DEFINED

//---------------------------------------------------------------------------*

#include "utilities/F_GetPrime.h"

//---------------------------------------------------------------------------*

#include <math.h>

//---------------------------------------------------------------------------*
//                                                                           *
//       Template for implementing two-operands cache                        *
//                                                                           *
//---------------------------------------------------------------------------*

template <class RESULT>
class TC_prime_cache2 {
//--- Constructor
  public : TC_prime_cache2 (void) ;

//--- Destructor
  public : virtual ~TC_prime_cache2 (void) ;

//--- Cache entry type
  protected : class cCacheEntry {
    public : PMSInt mOperand1 ;
    public : PMSInt mOperand2 ;
    public : RESULT mResult ;
  } ;

//--- Cache read
  public : inline void getCacheEntry (const PMSInt inOperand1,
                                      const PMSInt inOperand2,
                                      bool & outCacheSuccess,
                                      PMSInt32 & outHashCode,
                                      RESULT & outResult) ;

//--- Cache write
  public : inline void writeCacheEntry (const PMSInt inOperand1,
                                        const PMSInt inOperand2,
                                        const PMSInt inHashCode,
                                        const RESULT inResult) ;

//--- Clear all cache entries
  public : void clearAllCacheEntries (void) ;

//--- Realloc cache
  public : void reallocCache (const PMSInt32 inCacheNewSize) ;

//--- Get cache size (in bytes)
  public : PMUInt32 getCacheSizeInBytes (void) const ;

//--- Cache array pointer
  protected : cCacheEntry * mCache ;

//--- Cache size
  protected : PMSInt32 mCacheSize ;

//--- Integer square root of cache size
  protected : PMSInt32 mCacheSizeIntegerSquareRoot ;

//--- Default cache (size 1) ;
  protected : cCacheEntry mDefaultCache ;

//--- Cache successes
  protected : PMUInt64 mCacheSuccessCount ;
  public : PMUInt64 getCacheSuccessCount (void) const { return mCacheSuccessCount ; }

//--- Cache miss
  protected : PMUInt64 mCacheMissCount ;
  public : PMUInt64 getCacheMissCount (void) const { return mCacheMissCount ; }

//--- Cache override
  protected : PMUInt64 mCacheOverridesCount ;
  public : PMUInt64 getCacheOverrideCount (void) const { return mCacheOverridesCount ; }

//--- Get cache entries count
  public : PMSInt32 getCacheEntriesCount (void) {
    return mCacheSize ;
  }

//--- Get cache size in kbytes
  public : PMSInt32 getCacheSizeInKBytes (void) {
    return (mCacheSize * (PMSInt32) sizeof (cCacheEntry)) / 1024 ;
  }

//--- Get unused entries count
  public : PMUInt64 getUnusedCacheEntriesCount (void) const {
    PMUInt64 unusedEntriesCount = 0 ;
    for (PMSInt32 i=0 ; i<mCacheSize ; i++) {
      unusedEntriesCount += (PMUInt64) (mCache [i].mOperand1 == 0) ;
    }
    return unusedEntriesCount ;
  }


//--- No copy
  private : TC_prime_cache2 (TC_prime_cache2 <RESULT> &) ;
  private : TC_prime_cache2 <RESULT> & operator = (TC_prime_cache2 <RESULT> &) ;
} ;

//---------------------------------------------------------------------------*

template <class RESULT>
TC_prime_cache2 <RESULT>::TC_prime_cache2 (void) :
mCache (& mDefaultCache),
mCacheSize (1),
mCacheSizeIntegerSquareRoot (1),
mDefaultCache (),
mCacheSuccessCount (0),
mCacheMissCount (0),
mCacheOverridesCount (0) {
}

//---------------------------------------------------------------------------*

template <class RESULT>
TC_prime_cache2 <RESULT>::~TC_prime_cache2 (void) {
  if (mCacheSize > 1) {
    delete [] mCache ;
  }
}

//---------------------------------------------------------------------------*

template <class RESULT>
PMUInt32 TC_prime_cache2 <RESULT>::getCacheSizeInBytes (void) const {
  return ((PMUInt32) mCacheSize) * sizeof (cCacheEntry) ;
}

//---------------------------------------------------------------------------*

template <class RESULT>
void TC_prime_cache2 <RESULT>::reallocCache (const PMSInt32 inCacheSize) {
  if (inCacheSize <= 1) {
    if (mCacheSize > 1) {
      delete [] mCache ;
    }
    mCache = & mDefaultCache ;
    mCacheSize = 1 ;
  }else{
    const PMSInt32 newCacheSize = (PMSInt32) getPrimeGreaterThan ((PMUInt32) inCacheSize) ;
    if (newCacheSize != mCacheSize) {
      cCacheEntry * newCache = new cCacheEntry [newCacheSize] ;
      if (newCache != NULL) {
        cCacheEntry * previousCache = mCache ;
        mCache = newCache ;
        const PMSInt32 previousCacheSize = mCacheSize ;
        mCacheSize = newCacheSize ;
        mCacheSizeIntegerSquareRoot = (PMSInt32) ::sqrt (mCacheSize) ;
        clearAllCacheEntries () ;
        bool cacheSuccess ;
        PMSInt32 hashCode ;
        RESULT cacheResult ;
        for (PMSInt32 i=0 ; i<previousCacheSize ; i++) {
          if (previousCache [i].mOperand1 != 0) {
            getCacheEntry (previousCache [i].mOperand1,
                           previousCache [i].mOperand2,
                           cacheSuccess,
                           hashCode,
                           cacheResult) ;
            if (! cacheSuccess) {
              writeCacheEntry (previousCache [i].mOperand1,
                               previousCache [i].mOperand2,
                               hashCode,
                               previousCache [i].mResult) ;
            }
          }
        }
        if (previousCacheSize > 1) {
          delete [] previousCache ;
        }
      }
    }
  }
}

//---------------------------------------------------------------------------*

template <class RESULT>
void TC_prime_cache2 <RESULT>::getCacheEntry (const PMSInt inOperand1,
                                              const PMSInt inOperand2,
                                              bool & outCacheSuccess,
                                              PMSInt32 & outHashCode,
                                              RESULT & outResult) {
//--- Compute hash code
  outHashCode = (PMSInt32) (((PMUInt32) ((inOperand2 * mCacheSizeIntegerSquareRoot) + inOperand1)) % ((PMUInt32) mCacheSize)) ;
//--- Cache success ?
  outCacheSuccess = (inOperand1 == mCache [outHashCode].mOperand1)
                 && (inOperand2 == mCache [outHashCode].mOperand2) ;
//--- Update counts
  mCacheSuccessCount +=   outCacheSuccess ;
  mCacheMissCount    += ! outCacheSuccess ;
//--- Get result
  outResult = mCache [outHashCode].mResult ;
}

//---------------------------------------------------------------------------*

template <class RESULT>
void TC_prime_cache2 <RESULT>::writeCacheEntry (const PMSInt inOperand1,
                                                const PMSInt inOperand2,
                                                const PMSInt inHashCode,
                                                const RESULT inResult) {
//--- Cache overrides ?
  mCacheOverridesCount += (mCache [inHashCode].mOperand1 != 0) ;
//--- Write Operands
  mCache [inHashCode].mOperand1 = inOperand1 ;
  mCache [inHashCode].mOperand2 = inOperand2 ;
//--- Write result
  mCache [inHashCode].mResult = inResult ;
}

//---------------------------------------------------------------------------*

template <class RESULT>
void TC_prime_cache2 <RESULT>::clearAllCacheEntries (void) {
  for (PMSInt32 i=0 ; i<mCacheSize ; i++) {
    mCache [i].mOperand1 = 0 ;
    mCache [i].mOperand2 = 0 ;
  }
}

//---------------------------------------------------------------------------*

#endif

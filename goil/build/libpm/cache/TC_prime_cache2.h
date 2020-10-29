//----------------------------------------------------------------------------------------------------------------------
//
//     C++ template class for implementing a software cache                                      
//                        (size : a prime integer)                                               
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2001, ..., 2005 Pierre Molinaro.
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

#include "utilities/F_GetPrime.h"

//----------------------------------------------------------------------------------------------------------------------

#include <math.h>

//----------------------------------------------------------------------------------------------------------------------
//
//       Template for implementing two-operands cache                                            
//
//----------------------------------------------------------------------------------------------------------------------

template <class RESULT>
class TC_prime_cache2 {
//--- Constructor
  public : TC_prime_cache2 (void) ;

//--- Destructor
  public : virtual ~TC_prime_cache2 (void) ;

//--- Cache entry type
  protected : class cCacheEntry {
    public : intptr_t mOperand1 ;
    public : intptr_t mOperand2 ;
    public : RESULT mResult ;
  } ;

//--- Cache read
  public : inline void getCacheEntry (const intptr_t inOperand1,
                                      const intptr_t inOperand2,
                                      bool & outCacheSuccess,
                                      int32_t & outHashCode,
                                      RESULT & outResult) ;

//--- Cache write
  public : inline void writeCacheEntry (const intptr_t inOperand1,
                                        const intptr_t inOperand2,
                                        const intptr_t inHashCode,
                                        const RESULT inResult) ;

//--- Clear all cache entries
  public : void clearAllCacheEntries (void) ;

//--- Realloc cache
  public : void reallocCache (const int32_t inCacheNewSize) ;

//--- Get cache size (in bytes)
  public : uint32_t getCacheSizeInBytes (void) const ;

//--- Cache array pointer
  protected : cCacheEntry * mCache ;

//--- Cache size
  protected : int32_t mCacheSize ;

//--- Integer square root of cache size
  protected : int32_t mCacheSizeIntegerSquareRoot ;

//--- Default cache (size 1) ;
  protected : cCacheEntry mDefaultCache ;

//--- Cache successes
  protected : uint64_t mCacheSuccessCount ;
  public : uint64_t getCacheSuccessCount (void) const { return mCacheSuccessCount ; }

//--- Cache miss
  protected : uint64_t mCacheMissCount ;
  public : uint64_t getCacheMissCount (void) const { return mCacheMissCount ; }

//--- Cache override
  protected : uint64_t mCacheOverridesCount ;
  public : uint64_t getCacheOverrideCount (void) const { return mCacheOverridesCount ; }

//--- Get cache entries count
  public : int32_t getCacheEntriesCount (void) {
    return mCacheSize ;
  }

//--- Get cache size in kbytes
  public : int32_t getCacheSizeInKBytes (void) {
    return (mCacheSize * (int32_t) sizeof (cCacheEntry)) / 1024 ;
  }

//--- Get unused entries count
  public : uint64_t getUnusedCacheEntriesCount (void) const {
    uint64_t unusedEntriesCount = 0 ;
    for (int32_t i=0 ; i<mCacheSize ; i++) {
      unusedEntriesCount += (uint64_t) (mCache [i].mOperand1 == 0) ;
    }
    return unusedEntriesCount ;
  }


//--- No copy
  private : TC_prime_cache2 (TC_prime_cache2 <RESULT> &) ;
  private : TC_prime_cache2 <RESULT> & operator = (TC_prime_cache2 <RESULT> &) ;
} ;

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

template <class RESULT>
TC_prime_cache2 <RESULT>::~TC_prime_cache2 (void) {
  if (mCacheSize > 1) {
    delete [] mCache ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

template <class RESULT>
uint32_t TC_prime_cache2 <RESULT>::getCacheSizeInBytes (void) const {
  return (uint32_t) (((size_t) mCacheSize) * sizeof (cCacheEntry)) ;
}

//----------------------------------------------------------------------------------------------------------------------

template <class RESULT>
void TC_prime_cache2 <RESULT>::reallocCache (const int32_t inCacheSize) {
  if (inCacheSize <= 1) {
    if (mCacheSize > 1) {
      delete [] mCache ;
    }
    mCache = & mDefaultCache ;
    mCacheSize = 1 ;
  }else{
    const int32_t newCacheSize = (int32_t) getPrimeGreaterThan ((uint32_t) inCacheSize) ;
    if (newCacheSize != mCacheSize) {
      cCacheEntry * newCache = new cCacheEntry [newCacheSize] ;
      if (newCache != NULL) {
        cCacheEntry * previousCache = mCache ;
        mCache = newCache ;
        const int32_t previousCacheSize = mCacheSize ;
        mCacheSize = newCacheSize ;
        mCacheSizeIntegerSquareRoot = (int32_t) ::sqrt (mCacheSize) ;
        clearAllCacheEntries () ;
        bool cacheSuccess ;
        int32_t hashCode ;
        RESULT cacheResult ;
        for (int32_t i=0 ; i<previousCacheSize ; i++) {
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

//----------------------------------------------------------------------------------------------------------------------

template <class RESULT>
void TC_prime_cache2 <RESULT>::getCacheEntry (const intptr_t inOperand1,
                                              const intptr_t inOperand2,
                                              bool & outCacheSuccess,
                                              int32_t & outHashCode,
                                              RESULT & outResult) {
//--- Compute hash code
  outHashCode = (int32_t) (((uint32_t) ((inOperand2 * mCacheSizeIntegerSquareRoot) + inOperand1)) % ((uint32_t) mCacheSize)) ;
//--- Cache success ?
  outCacheSuccess = (inOperand1 == mCache [outHashCode].mOperand1)
                 && (inOperand2 == mCache [outHashCode].mOperand2) ;
//--- Update counts
  mCacheSuccessCount +=   outCacheSuccess ;
  mCacheMissCount    += ! outCacheSuccess ;
//--- Get result
  outResult = mCache [outHashCode].mResult ;
}

//----------------------------------------------------------------------------------------------------------------------

template <class RESULT>
void TC_prime_cache2 <RESULT>::writeCacheEntry (const intptr_t inOperand1,
                                                const intptr_t inOperand2,
                                                const intptr_t inHashCode,
                                                const RESULT inResult) {
//--- Cache overrides ?
  mCacheOverridesCount += (mCache [inHashCode].mOperand1 != 0) ;
//--- Write Operands
  mCache [inHashCode].mOperand1 = inOperand1 ;
  mCache [inHashCode].mOperand2 = inOperand2 ;
//--- Write result
  mCache [inHashCode].mResult = inResult ;
}

//----------------------------------------------------------------------------------------------------------------------

template <class RESULT>
void TC_prime_cache2 <RESULT>::clearAllCacheEntries (void) {
  for (int32_t i=0 ; i<mCacheSize ; i++) {
    mCache [i].mOperand1 = 0 ;
    mCache [i].mOperand2 = 0 ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

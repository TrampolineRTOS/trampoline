//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  BDD package (implementation of ROBDD)                                                                              *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1999, ..., 2010 Pierre Molinaro.                                                                     *
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

#include "bdd/C_BDD.h"
#include "utilities/F_GetPrime.h"
#include "bdd/C_BDD-node.h"

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Cache for Single Operand Operations
#endif

//---------------------------------------------------------------------------------------------------------------------*

static const int32_t kSingleOperandOperationCacheInitialSize = 131101 ;

//---------------------------------------------------------------------------------------------------------------------*

typedef struct {
  uint32_t mOperand ;
  uint32_t mResult ;
} tStructSingleOperandOperationCacheEntry ;

//---------------------------------------------------------------------------------------------------------------------*

static tStructSingleOperandOperationCacheEntry * gSingleOperandOperationCacheMap ;
static uint32_t gSingleOperandOperationMapSize ;
static uint32_t gSingleOperandOperationCacheMapUsedEntryCount ;
static uint64_t gSingleOperandOperationCacheTrivialOperationCount ;
static uint32_t gSingleOperandOperationCacheMaxPowerOfTwoSize = 31 ;
static bool gSingleOperandOperationCacheExpandable = true ;

//---------------------------------------------------------------------------------------------------------------------*

uint32_t singleOperandOperationCacheMemoryUsage (void) {
  return (gSingleOperandOperationMapSize * (uint32_t) sizeof (uint64_t)) / 1000000 ;
}

//---------------------------------------------------------------------------------------------------------------------*

void releaseSingleOperandOperationCache (void) {
  gSingleOperandOperationCacheMapUsedEntryCount = 0 ;
  macroMyDeletePODArray (gSingleOperandOperationCacheMap) ;
  gSingleOperandOperationCacheExpandable = true ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void clearSingleOperandOperationCache (void) {
  gSingleOperandOperationCacheMapUsedEntryCount = 0 ;
  if (0 == gSingleOperandOperationMapSize) {
    gSingleOperandOperationMapSize = kSingleOperandOperationCacheInitialSize ;
    macroMyNewPODArray (gSingleOperandOperationCacheMap, tStructSingleOperandOperationCacheEntry, gSingleOperandOperationMapSize) ;
    if (C_BDD::displaysInformationMessages ()) {
      printf ("BDD package info: single operand operation cache allocated to %u %03u %03u (%u MB)\n",
              gSingleOperandOperationMapSize / 1000000,
              (gSingleOperandOperationMapSize / 1000) % 1000,
              gSingleOperandOperationMapSize % 1000,
              (gSingleOperandOperationMapSize * (uint32_t) sizeof (tStructSingleOperandOperationCacheEntry)) / 1000000) ;
    }
  }
  for (uint32_t i=0 ; i<gSingleOperandOperationMapSize ; i++) {
    gSingleOperandOperationCacheMap [i].mOperand = 0 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void reallocSingleOperandOperationCache (const uint32_t inNewSize) {
  gSingleOperandOperationCacheMapUsedEntryCount = 0 ;
  tStructSingleOperandOperationCacheEntry * newCache = NULL ;
  if (inNewSize << (1U << gSingleOperandOperationCacheMaxPowerOfTwoSize)) {
    uint32_t newMemoryUsage = C_BDD::currentMemoryUsage () ;
    newMemoryUsage -= singleOperandOperationCacheMemoryUsage () ;
    newMemoryUsage += (uint32_t) ((inNewSize * sizeof (uint64_t)) / 1000000) ;
    if (newMemoryUsage < C_BDD::maximumMemoryUsage ()) {
      macroMyNewPODArray (newCache, tStructSingleOperandOperationCacheEntry, inNewSize) ;
      for (uint32_t i=0 ; i<gSingleOperandOperationMapSize ; i++) {
        if (gSingleOperandOperationCacheMap [i].mOperand != 0) {
          const uint32_t newIndex = gSingleOperandOperationCacheMap [i].mOperand % inNewSize ;
          newCache [newIndex].mOperand = gSingleOperandOperationCacheMap [i].mOperand ;
          newCache [newIndex].mResult = gSingleOperandOperationCacheMap [i].mResult ;
          gSingleOperandOperationCacheMapUsedEntryCount += newCache [newIndex].mOperand == 0 ;
        }
      }
      macroMyDeletePODArray (gSingleOperandOperationCacheMap) ;
      gSingleOperandOperationCacheMap = newCache ;
      gSingleOperandOperationMapSize = inNewSize ;
      if (C_BDD::displaysInformationMessages ()) {
        printf ("BDD package info: single operand operation cache reallocated to %u %03u %03u (%u MB)\n",
                gSingleOperandOperationMapSize / 1000000,
                (gSingleOperandOperationMapSize / 1000) % 1000,
                gSingleOperandOperationMapSize % 1000,
                (gSingleOperandOperationMapSize * (uint32_t) sizeof (tStructSingleOperandOperationCacheEntry)) / 1000000) ;
      }
    }else{
      gSingleOperandOperationCacheExpandable = false ;
      if (C_BDD::displaysInformationMessages ()) {
        printf ("BDD package info: single operand operation cache reallocation to %u %03u %03u inhibited (max RAM usage reached)\n",
                gSingleOperandOperationMapSize / 1000000,
                (gSingleOperandOperationMapSize / 1000) % 1000,
                gSingleOperandOperationMapSize % 1000) ;
      }
    }
  }else{
    gSingleOperandOperationCacheExpandable = false ;
    if (C_BDD::displaysInformationMessages ()) {
      printf ("BDD package info: single operand operation cache reallocation to %u %03u %03u inhibited (max size reached)\n",
              gSingleOperandOperationMapSize / 1000000,
              (gSingleOperandOperationMapSize / 1000) % 1000,
              gSingleOperandOperationMapSize % 1000) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static bool searchInSingleOperandOperationCache (const uint32_t inOperand,
                                                 uint32_t & outResult) {
  if (0 == gSingleOperandOperationMapSize) {
    reallocSingleOperandOperationCache (getPrimeGreaterThan (1024)) ;
  }
  const uint32_t idx = inOperand % gSingleOperandOperationMapSize ;
  const bool found = gSingleOperandOperationCacheMap [idx].mOperand == inOperand ;
  if (found) {
    outResult = gSingleOperandOperationCacheMap [idx].mResult ;
  }
  return found ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void enterInSingleOperandOperationCache (const uint32_t inOperand,
                                                const uint32_t inResult) {
  const uint32_t idx = inOperand % gSingleOperandOperationMapSize ;
  const bool entryWasUnused = gSingleOperandOperationCacheMap [idx].mOperand == 0 ;
  gSingleOperandOperationCacheMap [idx].mOperand = inOperand ;
  gSingleOperandOperationCacheMap [idx].mResult = inResult ;
//--- Realloc cache ?
  if (entryWasUnused) {
    gSingleOperandOperationCacheMapUsedEntryCount ++ ;
    if (gSingleOperandOperationCacheExpandable && ((gSingleOperandOperationCacheMapUsedEntryCount + gSingleOperandOperationCacheMapUsedEntryCount / 4) > gSingleOperandOperationMapSize)) {
      reallocSingleOperandOperationCache (gSingleOperandOperationMapSize + 1) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::setSingleOperandOperationCacheMaxSize (const uint32_t inPowerOfTwo) {
  gSingleOperandOperationCacheMaxPowerOfTwoSize = inPowerOfTwo ;
  if (C_BDD::displaysInformationMessages ()) {
    printf ("BDD package info: single operand operation cache max size limited < 2 ** %u\n", gSingleOperandOperationCacheMaxPowerOfTwoSize) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Forall Operation
#endif

//---------------------------------------------------------------------------------------------------------------------*

static uint32_t
internalForAllOnBitRange (const uint32_t inValue,
                          const uint32_t inFirstBit,
                          const uint32_t inBitCount) {
  const uint32_t complement = inValue & 1 ;
  uint32_t result = complement ;
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    gSingleOperandOperationCacheTrivialOperationCount ++ ;
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    if (var >= (inFirstBit + inBitCount)) {
      bool cacheSuccess = false ;
      // int32_t hashCode ;
      // const uint32_t key = ((uint32_t) inBitCount) | (((uint32_t) inFirstBit) << 16) ;
  //    gForAllOperationCache.getCacheEntry (inValue, key, cacheSuccess, hashCode, result) ;
      if (! cacheSuccess) {
        result = find_or_add (var,
          internalForAllOnBitRange (gNodeArray [nodeIndex].mELSE ^ complement, inFirstBit, inBitCount),
          internalForAllOnBitRange (gNodeArray [nodeIndex].mTHEN ^ complement, inFirstBit, inBitCount) COMMA_HERE) ;
  //      gForAllOperationCache.writeCacheEntry (inValue, key, hashCode, result) ;
      }
    }else if (var >= inFirstBit) {
      result = internalANDoperation (
         internalForAllOnBitRange (gNodeArray [nodeIndex].mELSE ^ complement, inFirstBit, inBitCount),
         internalForAllOnBitRange (gNodeArray [nodeIndex].mTHEN ^ complement, inFirstBit, inBitCount)) ;
    }else{ // var < numeroBit
      result = inValue ;
      gSingleOperandOperationCacheTrivialOperationCount ++ ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static uint32_t
operationQuelqueSoitSurBitSupNumeroInterne (const uint32_t inValue,
                                            const uint32_t numeroBit) {
  const uint32_t complement = inValue & 1 ;
  uint32_t result = complement ;
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    gSingleOperandOperationCacheTrivialOperationCount ++ ;
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    if (var > numeroBit) {
      if (! searchInSingleOperandOperationCache (inValue, result)) {
        result = internalANDoperation (
              operationQuelqueSoitSurBitSupNumeroInterne (gNodeArray [nodeIndex].mELSE ^ complement, numeroBit),
              operationQuelqueSoitSurBitSupNumeroInterne (gNodeArray [nodeIndex].mTHEN ^ complement, numeroBit)) ;
        enterInSingleOperandOperationCache (inValue, result) ;
      }
    }else if (var == numeroBit) {
      result = internalANDoperation (gNodeArray [nodeIndex].mELSE ^ complement, gNodeArray [nodeIndex].mTHEN ^ complement) ;
    }else{ // var < numeroBit
      result = inValue ;
      gSingleOperandOperationCacheTrivialOperationCount ++ ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::forallOnBitNumber (const uint32_t numeroBit) const {
  clearSingleOperandOperationCache () ;
  return C_BDD (internalForAllOnBitRange (mBDDvalue, numeroBit, 1)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::forallOnBitsAfterNumber (const uint32_t numeroBit) const {
  clearSingleOperandOperationCache () ;
  return C_BDD (operationQuelqueSoitSurBitSupNumeroInterne (mBDDvalue, numeroBit)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Exist Operation
#endif

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::existsOnBitNumber (const uint32_t numeroBit) const {
  clearSingleOperandOperationCache () ;
//--- ilExiste x : F <=> non (quelquesoit x : non (F))
  return C_BDD (internalForAllOnBitRange (mBDDvalue ^ 1, numeroBit, 1) ^ 1) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::
existsOnBitRange (const uint32_t inFirstBit,
                  const uint32_t inBitCount) const {
  clearSingleOperandOperationCache () ;
  return C_BDD (internalForAllOnBitRange (mBDDvalue ^ 1, inFirstBit, inBitCount) ^ 1) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::existsOnBitsAfterNumber (const uint32_t numeroBit) const {
// ilExiste x : F <=> non (quelquesoit x : non (F))
  clearSingleOperandOperationCache () ;
  return C_BDD (operationQuelqueSoitSurBitSupNumeroInterne (mBDDvalue ^ 1, numeroBit) ^ 1) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Substitute variables
#endif

//---------------------------------------------------------------------------------------------------------------------*

static uint32_t internalRecursiveSubstitution (const uint32_t inValue,
                                               const uint32_t vecteurSubstitutionBool [],
                                               const uint32_t inNoChangeIndex,
                                               const uint32_t inBDDvariablesCount
                                               COMMA_LOCATION_ARGS) {
  uint32_t result = inValue ;
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    gSingleOperandOperationCacheTrivialOperationCount ++ ;
  }else{
    const uint32_t complement = inValue & 1 ;
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    MF_AssertThere (var < inBDDvariablesCount, "var (%lld) < inBDDvariablesCount (%lld)", var, inBDDvariablesCount) ;
    if (var < inNoChangeIndex) {
      result = inValue ;
      gSingleOperandOperationCacheTrivialOperationCount ++ ;
    }else if (! searchInSingleOperandOperationCache (inValue, result)) {
      result = internalITEoperation (
        find_or_add (vecteurSubstitutionBool [var], 1, 0 COMMA_HERE),
        internalRecursiveSubstitution (gNodeArray [nodeIndex].mELSE ^ complement, vecteurSubstitutionBool, inNoChangeIndex, inBDDvariablesCount COMMA_THERE),
        internalRecursiveSubstitution (gNodeArray [nodeIndex].mTHEN ^ complement, vecteurSubstitutionBool, inNoChangeIndex, inBDDvariablesCount COMMA_THERE)
      ) ;
      enterInSingleOperandOperationCache (inValue, result) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::substitution (const uint32_t inSubstitutionArray [],
                           const uint32_t inBDDvariablesCount
                           COMMA_LOCATION_ARGS) const {
  clearSingleOperandOperationCache () ;
//--- Le vecteur subsitution est-il l'identite ?
  bool estIdentite = true ;
  uint32_t noChangeIndex = 0 ;
  for (uint32_t i=0 ; estIdentite && (i<inBDDvariablesCount) ; i++) {
    estIdentite = inSubstitutionArray [i] == i ;
    noChangeIndex ++ ;
  }
  noChangeIndex -- ;
  // printf ("inBDDvariablesCount %u\n", inBDDvariablesCount) ;
  return C_BDD (estIdentite ? mBDDvalue : internalRecursiveSubstitution (mBDDvalue, inSubstitutionArray, noChangeIndex, inBDDvariablesCount COMMA_THERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Translate BDD variables
#endif

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::translate (const uint32_t inBDDvariablesCount,
                        const uint32_t inTranslation) const {
  uint32_t * substitionVector = NULL ;
  macroMyNewArray (substitionVector, uint32_t, inBDDvariablesCount) ;
  for (uint32_t i=0 ; i<inBDDvariablesCount ; i++) {
    substitionVector [i] = (uint32_t) (i + inTranslation) ;
  }
  const uint32_t result = internalRecursiveSubstitution (mBDDvalue, substitionVector, 0, inBDDvariablesCount COMMA_HERE) ;
  macroMyDeleteArray (substitionVector) ;
  return C_BDD (result) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Exchange Variables
#endif

//---------------------------------------------------------------------------------------------------------------------*

static uint32_t
internalExchangeVariables (const uint32_t inValue,
                           const uint32_t var1,
                           const uint32_t var2) {
  uint32_t result = inValue ;
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    const uint32_t complement = inValue & 1 ;
    if (gNodeArray [nodeIndex].mVariableIndex > var1) {
      result = internalITEoperation (
                     find_or_add (gNodeArray [nodeIndex].mVariableIndex, 0, 1 COMMA_HERE),
                     internalExchangeVariables (gNodeArray [nodeIndex].mTHEN ^ complement, var1, var2),
                     internalExchangeVariables (gNodeArray [nodeIndex].mELSE ^ complement, var1, var2)) ;
    }else if (gNodeArray [nodeIndex].mVariableIndex == var1) {
      result = internalITEoperation (
                     find_or_add (var2, 0, 1 COMMA_HERE),
                     internalExchangeVariables (gNodeArray [nodeIndex].mTHEN ^ complement, var1, var2),
                     internalExchangeVariables (gNodeArray [nodeIndex].mELSE ^ complement, var1, var2)) ;
    }else if (gNodeArray [nodeIndex].mVariableIndex > var2) {
      result = internalITEoperation (
                     find_or_add (gNodeArray [nodeIndex].mVariableIndex, 0, 1 COMMA_HERE),
                     internalExchangeVariables (gNodeArray [nodeIndex].mTHEN ^ complement, var1, var2),
                     internalExchangeVariables (gNodeArray [nodeIndex].mELSE ^ complement, var1, var2)) ;
    }else if (gNodeArray [nodeIndex].mVariableIndex == var2) {
      result = internalITEoperation (
                     find_or_add (var1, 0, 1 COMMA_HERE),
                     internalExchangeVariables (gNodeArray [nodeIndex].mTHEN ^ complement, var1, var2),
                     internalExchangeVariables (gNodeArray [nodeIndex].mELSE ^ complement, var1, var2)) ;
    }     
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::exchangeVariables (const uint32_t var1, const uint32_t var2) const {
  C_BDD result (mBDDvalue) ;
  if (var1 > var2) {
    result.mBDDvalue = internalExchangeVariables (mBDDvalue, var1, var2) ;
  }else if (var1 < var2) {
    result.mBDDvalue = internalExchangeVariables (mBDDvalue, var2, var1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Roll Down
#endif

//---------------------------------------------------------------------------------------------------------------------*

static uint32_t
internalRollDown (const uint32_t inValue,
                  const uint32_t inHighVar,
                  const uint32_t inLowVar) {
  uint32_t result = inValue ;
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    const uint32_t complement = inValue & 1 ;
    if (gNodeArray [nodeIndex].mVariableIndex > inHighVar) {
      result = internalITEoperation (
                     find_or_add (gNodeArray [nodeIndex].mVariableIndex, 0, 1 COMMA_HERE),
                     internalRollDown (gNodeArray [nodeIndex].mTHEN ^ complement, inHighVar, inLowVar),
                     internalRollDown (gNodeArray [nodeIndex].mELSE ^ complement, inHighVar, inLowVar)) ;
    }else if (gNodeArray [nodeIndex].mVariableIndex > inLowVar) {
      result = internalITEoperation (
                     find_or_add ((uint32_t) (gNodeArray [nodeIndex].mVariableIndex - 1), 0, 1 COMMA_HERE),
                     internalRollDown (gNodeArray [nodeIndex].mTHEN ^ complement, inHighVar, inLowVar),
                     internalRollDown (gNodeArray [nodeIndex].mELSE ^ complement, inHighVar, inLowVar)) ;
    }else if (gNodeArray [nodeIndex].mVariableIndex == inLowVar) {
      result = internalITEoperation (
                     find_or_add (inHighVar, 0, 1 COMMA_HERE),
                     internalRollDown (gNodeArray [nodeIndex].mTHEN ^ complement, inHighVar, inLowVar),
                     internalRollDown (gNodeArray [nodeIndex].mELSE ^ complement, inHighVar, inLowVar)) ;
    }     
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::rollDownVariables (const uint32_t var1, const uint32_t var2) const {
  C_BDD result (mBDDvalue) ;
  if (var1 > var2) {
    result.mBDDvalue = internalRollDown (mBDDvalue, var1, var2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Roll Up
#endif

//---------------------------------------------------------------------------------------------------------------------*

static uint32_t
internalRollUp (const uint32_t inValue,
                const uint32_t var1,
                const uint32_t var2) {
  uint32_t result = inValue ;
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    const uint32_t complement = inValue & 1 ;
    if (gNodeArray [nodeIndex].mVariableIndex > var1) {
      result = internalITEoperation (
                     find_or_add (gNodeArray [nodeIndex].mVariableIndex, 0, 1 COMMA_HERE),
                     internalRollUp (gNodeArray [nodeIndex].mTHEN ^ complement, var1, var2),
                     internalRollUp (gNodeArray [nodeIndex].mELSE ^ complement, var1, var2)) ;
    }else if (gNodeArray [nodeIndex].mVariableIndex == var1) {
      result = internalITEoperation (
                     find_or_add (var2, 0, 1 COMMA_HERE),
                     internalRollUp (gNodeArray [nodeIndex].mTHEN ^ complement, var1, var2),
                     internalRollUp (gNodeArray [nodeIndex].mELSE ^ complement, var1, var2)) ;
    }else if (gNodeArray [nodeIndex].mVariableIndex >= var2) {
      result = internalITEoperation (
                     find_or_add ((uint32_t) (gNodeArray [nodeIndex].mVariableIndex + 1), 0, 1 COMMA_HERE),
                     internalRollUp (gNodeArray [nodeIndex].mTHEN ^ complement, var1, var2),
                     internalRollUp (gNodeArray [nodeIndex].mELSE ^ complement, var1, var2)) ;
    }     
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::
rollUpVariables (const uint32_t var1, const uint32_t var2) const {
  C_BDD result (mBDDvalue) ;
  if (var1 > var2) {
    result.mBDDvalue = internalRollUp (mBDDvalue, var1, var2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Left shift
#endif

//---------------------------------------------------------------------------------------------------------------------*

static uint32_t internalLeftShift (const uint32_t inValue,
                                   const uint32_t inLeftShiftCount) {
  uint32_t result = inValue ;
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    gSingleOperandOperationCacheTrivialOperationCount ++ ;
  }else if (! searchInSingleOperandOperationCache (inValue, result)) {
    const uint32_t complement = inValue & 1 ;
    result = find_or_add (gNodeArray [nodeIndex].mVariableIndex + inLeftShiftCount,
                          internalLeftShift (gNodeArray [nodeIndex].mELSE ^ complement, inLeftShiftCount),
                          internalLeftShift (gNodeArray [nodeIndex].mTHEN ^ complement, inLeftShiftCount)
                          COMMA_HERE) ;
    enterInSingleOperandOperationCache (inValue, result) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::bddByLeftShifting (const uint32_t inLeftShiftCount) const {
  clearSingleOperandOperationCache () ;
  C_BDD result ;
  result.mBDDvalue = internalLeftShift (mBDDvalue, inLeftShiftCount) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Right shift
#endif

//---------------------------------------------------------------------------------------------------------------------*

static uint32_t internalRightShift (const uint32_t inValue,
                                    const uint32_t inRightShiftCount) {
  uint32_t result = inValue ;
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    gSingleOperandOperationCacheTrivialOperationCount ++ ;
  }else if (gNodeArray [nodeIndex].mVariableIndex < inRightShiftCount) {
    result = 1 ;
    gSingleOperandOperationCacheTrivialOperationCount ++ ;
  }else if (! searchInSingleOperandOperationCache (inValue, result)) {
    const uint32_t complement = inValue & 1 ;
    result = find_or_add (gNodeArray [nodeIndex].mVariableIndex - inRightShiftCount,
                          internalRightShift (gNodeArray [nodeIndex].mELSE ^ complement, inRightShiftCount),
                          internalRightShift (gNodeArray [nodeIndex].mTHEN ^ complement, inRightShiftCount)
                          COMMA_HERE) ;
    enterInSingleOperandOperationCache (inValue, result) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::bddByRightShifting (const uint32_t inRightShiftCount) const {
  clearSingleOperandOperationCache () ;
  C_BDD result ;
  result.mBDDvalue = internalRightShift (mBDDvalue, inRightShiftCount) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

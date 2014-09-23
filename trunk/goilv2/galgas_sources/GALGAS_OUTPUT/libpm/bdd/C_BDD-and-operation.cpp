//-----------------------------------------------------------------------------*
//                                                                             *
//     BDD package (implementation of ROBDD)                                   *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 1999, ..., 2010 Pierre Molinaro.                             *
//                                                                             *
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

#include "bdd/C_BDD.h"
#include "utilities/F_GetPrime.h"
#include "strings/C_String.h"
#include "bdd/C_BDD-node.h"

//-----------------------------------------------------------------------------*

#include <stddef.h>
#include <string.h>
#include <limits.h>

//-----------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Cache for AND Operation
#endif

//-----------------------------------------------------------------------------*
//                                                                             *
//  And computation cache                                                      *
//                                                                             *
//-----------------------------------------------------------------------------*

typedef struct {
  public : uint64_t mOperands ;
  public : uint32_t mResult ;
} tStructANDOperationCacheEntry ;

//-----------------------------------------------------------------------------*

static const int32_t kANDOperationCacheInitialSize = 262145 ;

//-----------------------------------------------------------------------------*

static uint64_t * gANDOperationCacheOperandMap ;
static uint32_t * gANDOperationCacheResultMap ;
static uint32_t gANDOperationMapSize ;
static uint32_t gANDOperationCacheMapUsedEntryCount ;
static uint64_t gANDOperationCacheTrivialOperationCount ;
static bool gANDOperationCacheExpandable = true ;
static uint32_t gANDOperationCacheMaxPowerOfTwoSize = 31 ;

//-----------------------------------------------------------------------------*

uint32_t ANDCacheMemoryUsage (void) {
  return (gANDOperationMapSize * (uint32_t) (sizeof (uint32_t) + sizeof (uint64_t))) / 1000000 ;
}

//-----------------------------------------------------------------------------*

void releaseANDOperationCache (void) {
  gANDOperationCacheMapUsedEntryCount = 0 ;
  macroMyDeletePODArray (gANDOperationCacheOperandMap) ;
  macroMyDeletePODArray (gANDOperationCacheResultMap) ;
  gANDOperationMapSize = 0 ;
  gANDOperationCacheExpandable = true ;
}

//-----------------------------------------------------------------------------*

void clearANDOperationCache (void) {
  gANDOperationCacheMapUsedEntryCount = 0 ;
  for (uint32_t i=0 ; i<gANDOperationMapSize ; i++) {
    gANDOperationCacheOperandMap [i] = 0 ;
  }
}

//-----------------------------------------------------------------------------*

static inline uint64_t getOperands (const uint32_t inOperand1,
                                    const uint32_t inOperand2) {
  uint64_t operands = inOperand1 ;
  operands <<= 32 ;
  operands |= inOperand2 ;
  return operands ;
}

//-----------------------------------------------------------------------------*

static bool searchInANDOperationCache (const uint32_t inOperand1,
                                       const uint32_t inOperand2,
                                       uint32_t & outResult) {
  if (0 == gANDOperationMapSize) {
    gANDOperationMapSize = kANDOperationCacheInitialSize ;
    // tStructANDOperationCacheEntry temp [5] ;
    // printf ("tStructANDOperationCacheEntry: %ld bytes\n", sizeof (tStructANDOperationCacheEntry)) ;
    // printf ("tStructANDOperationCacheEntry [5]: %ld bytes\n", sizeof (temp)) ;
    macroMyNewPODArray (gANDOperationCacheOperandMap, uint64_t, gANDOperationMapSize) ;
    macroMyNewPODArray (gANDOperationCacheResultMap, uint32_t, gANDOperationMapSize) ;
    clearANDOperationCache () ;
    if (C_BDD::displaysInformationMessages ()) {
      printf ("BDD package info: AND cache allocated to %u %03u %03u (%u MB)\n",
              gANDOperationMapSize / 1000000,
              (gANDOperationMapSize / 1000) % 1000,
              gANDOperationMapSize % 1000,
              (gANDOperationMapSize * (uint32_t) (sizeof (uint32_t) + sizeof (uint64_t))) / 1000000) ;
    }
  }
  const uint64_t operands = getOperands (inOperand1, inOperand2) ;
  const uint64_t idx = operands % gANDOperationMapSize ;
  const bool found = gANDOperationCacheOperandMap [idx] == operands ;
  if (found) {
    outResult = gANDOperationCacheResultMap [idx] ;
  }
  return found ;
}

//-----------------------------------------------------------------------------*

static void reallocANDOperationCache (const uint32_t inNewSize) {
  if (0 < inNewSize) {
    gANDOperationCacheMapUsedEntryCount = 0 ;
    uint64_t * newCache = NULL ;
    macroMyNewPODArray (newCache, uint64_t, inNewSize) ;
    for (uint32_t i=0 ; i<inNewSize ; i++) {
      newCache [i] = 0 ;
    }
    uint32_t * newResult = NULL ;
    macroMyNewPODArray (newResult, uint32_t, inNewSize) ;
    for (uint32_t i=0 ; i<gANDOperationMapSize ; i++) {
      if (gANDOperationCacheOperandMap [i] != 0) {
        const uint64_t newIndex = gANDOperationCacheOperandMap [i] % inNewSize ;
        gANDOperationCacheMapUsedEntryCount += newCache [newIndex] == 0 ;
        newCache [newIndex] = gANDOperationCacheOperandMap [i] ;
        newResult [newIndex] = gANDOperationCacheResultMap [i] ;
      }
    }
    macroMyDeletePODArray (gANDOperationCacheOperandMap) ;
    macroMyDeletePODArray (gANDOperationCacheResultMap) ;
    gANDOperationCacheOperandMap = newCache ;
    gANDOperationCacheResultMap = newResult ;
    gANDOperationMapSize = inNewSize ;
    if (C_BDD::displaysInformationMessages ()) {
      printf ("BDD package info: AND cache reallocated to %u %03u %03u (%u MB)\n",
              gANDOperationMapSize / 1000000,
              (gANDOperationMapSize / 1000) % 1000,
              gANDOperationMapSize % 1000,
              (gANDOperationMapSize * (uint32_t) (sizeof (uint32_t) + sizeof (uint64_t))) / 1000000) ;
    }
  }
}

//-----------------------------------------------------------------------------*

static void enterInANDOperationCache (const uint32_t inOperand1,
                                      const uint32_t inOperand2,
                                      const uint32_t inResult) {
  const uint64_t operands = getOperands (inOperand1, inOperand2) ;
  const uint64_t idx = operands % gANDOperationMapSize ;
  const bool entryWasUnused = gANDOperationCacheOperandMap [idx] == 0 ;
  gANDOperationCacheOperandMap [idx] = operands ;
  gANDOperationCacheResultMap [idx] = inResult ;
//--- Realloc cache ?
  if (entryWasUnused) {
    gANDOperationCacheMapUsedEntryCount ++ ;
    if (gANDOperationCacheExpandable &&
        ((gANDOperationCacheMapUsedEntryCount + gANDOperationCacheMapUsedEntryCount / 4) > gANDOperationMapSize)) {
      const uint32_t newSize = getPrimeGreaterThan (gANDOperationMapSize + 1) ;
      if (newSize < (1U << gANDOperationCacheMaxPowerOfTwoSize)) {
        uint32_t newMemoryUsage = C_BDD::currentMemoryUsage () ;
        newMemoryUsage -= ANDCacheMemoryUsage () ;
        newMemoryUsage += (uint32_t) ((newSize * (sizeof (uint64_t) + sizeof (uint32_t))) / 1000000) ;
        if (newMemoryUsage < C_BDD::maximumMemoryUsage ()) {
          reallocANDOperationCache (newSize) ;
        }else{
          gANDOperationCacheExpandable = false ;
          if (C_BDD::displaysInformationMessages ()) {
            printf ("BDD package info: AND cache reallocation to %u %03u %03u inhibited (max RAM usage reached)\n",
              newSize / 1000000,
              (newSize / 1000) % 1000,
              newSize % 1000) ;
          }
        }
      }else{
        gANDOperationCacheExpandable = false ;
        if (C_BDD::displaysInformationMessages ()) {
          printf ("BDD package info: AND cache reallocation to %u %03u %03u inhibited (max size reached)\n",
            newSize / 1000000,
            (newSize / 1000) % 1000,
            newSize % 1000) ;
        }
      }
    }
  }
}

//-----------------------------------------------------------------------------*

void C_BDD::setANDOperationCacheMaxSize (const uint32_t inPowerOfTwo) {
  gANDOperationCacheMaxPowerOfTwoSize = inPowerOfTwo ;
  if (C_BDD::displaysInformationMessages ()) {
    printf ("BDD package info: AND cache max size limited < 2 ** %u\n", gANDOperationCacheMaxPowerOfTwoSize) ;
  }
}

//-----------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark AND operation
#endif

//-----------------------------------------------------------------------------*
//                                                                             *
//                        Operation AND                                        *
//                                                                             *
//-----------------------------------------------------------------------------*

uint32_t internalANDoperation (const uint32_t opf,
                               const uint32_t opg) {
//  MF_Assert ((opf >> 1) < gUniqueTableSize, "(opf >> 1) (%lld) should be < gUniqueTableSize (%lld)", (opf >> 1), gUniqueTableSize) ;
//  MF_Assert ((opg >> 1) < gUniqueTableSize, "(opg >> 1) (%lld) should be < gUniqueTableSize (%lld)", (opg >> 1), gUniqueTableSize) ;
  uint32_t result ;
  uint32_t f = opf ;
  uint32_t g = opg ;
//--- Simplification 1 : si f > g, and (f, g) -> and (g, f) ;
  if (f > g) {
    const uint32_t tempo = g ; g = f ; f = tempo ;
  }
//--- Test trivial 1 : and (0, g) -> 0 ;
  if (f == 0) {
    gANDOperationCacheTrivialOperationCount ++ ;
    result = 0 ;
//--- Test trivial 2 : and (1, g) -> g ;
  }else if (f == 1) {
    gANDOperationCacheTrivialOperationCount ++ ;
    result = g ;
//--- Test trivial 3 : and (f, f) -> f ;
  }else if (f == g) {
    gANDOperationCacheTrivialOperationCount ++ ;
    result = g ;
//--- Test trivial 3 : and (f, ~f) -> 0 ;
  }else if ((f ^ g) == 1) {
    gANDOperationCacheTrivialOperationCount ++ ;
    result = 0 ;
//--- Effectuer le calcul
  }else if (! searchInANDOperationCache (f, g, result)) {
  //--- Faire l'operation
    const uint32_t nodeF = nodeIndexForRoot (f COMMA_HERE) ;
    const uint32_t nodeG = nodeIndexForRoot (g COMMA_HERE) ;
    const uint32_t compF = f & 1 ;
    const uint32_t compG = g & 1 ;
    const uint32_t varF = gNodeArray [nodeF].mVariableIndex ;
    const uint32_t varG = gNodeArray [nodeG].mVariableIndex ;
  //--- Compute
    if (varF < varG) {
      result = find_or_add (varG,
                            internalANDoperation (f, gNodeArray [nodeG].mELSE ^ compG),
                            internalANDoperation (f, gNodeArray [nodeG].mTHEN ^ compG) COMMA_HERE) ;
    }else if (varF == varG) {
      result = find_or_add (varF,
                            internalANDoperation (gNodeArray [nodeF].mELSE ^ compF, gNodeArray [nodeG].mELSE ^ compG),
                            internalANDoperation (gNodeArray [nodeF].mTHEN ^ compF, gNodeArray [nodeG].mTHEN ^ compG) COMMA_HERE) ;
    }else{ // varF > varG
      result = find_or_add (varF,
                            internalANDoperation (gNodeArray [nodeF].mELSE ^ compF, g),
                            internalANDoperation (gNodeArray [nodeF].mTHEN ^ compF, g) COMMA_HERE) ;
    }
  //--- Insert result into cache
    enterInANDOperationCache (f, g, result) ;
  }
//  MF_Assert ((result >> 1) < gUniqueTableSize, "(result >> 1) (%lld) should be < gUniqueTableSize (%lld)", (result >> 1), gUniqueTableSize) ;
  return result ;
}

//-----------------------------------------------------------------------------*

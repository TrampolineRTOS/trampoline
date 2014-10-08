//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     BDD package (implementation of ROBDD)                                   *
//                                                                                                                     *
//  This file is part of libpm library                                         *
//                                                                                                                     *
//  Copyright (C) 1999, ..., 2013 Pierre Molinaro.                             *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "bdd/C_BDD.h"
#include "utilities/F_GetPrime.h"
#include "utilities/C_PrologueEpilogue.h"
#include "utilities/M_Threads.h"
#include "strings/C_String.h"
#include "bdd/C_BDD-node.h"
#include "time/C_Timer.h"

//---------------------------------------------------------------------------------------------------------------------*

#include <stddef.h>
#include <string.h>
#include <limits.h>

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_BDD::getBDDnodeSize (void) {
  return (uint32_t) sizeof (cBDDnode) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  BDD objects unique table                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static uint32_t gNodeArraySize = 0 ;
cBDDnode * gNodeArray = NULL ;
static uint64_t * gMarkTable = NULL ;
static uint32_t gCurrentNodeCount = 0 ;

//---------------------------------------------------------------------------------------------------------------------*

uint32_t nodeMapMemoryUsage (void) {
  return (gNodeArraySize * C_BDD::getBDDnodeSize ()) / 1000000 ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_BDD::getCreatedNodesCount (void) {
  return gNodeArraySize ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_BDD::getExistingNodesCount (void) {
  return gCurrentNodeCount ;
}

//---------------------------------------------------------------------------------------------------------------------*

static uint32_t * gCollisionMap = NULL ;
static uint32_t gCollisionMapSize = 0 ;
static uint32_t gHashMapPowerOfTwoMaxSize = 31 ;
static bool gHashMapExpandable = true ;

//---------------------------------------------------------------------------------------------------------------------*

uint32_t hashMapMemoryUsage (void) {
  return (uint32_t) ((gCollisionMapSize * sizeof (uint32_t)) / 1000000) ;
}

//---------------------------------------------------------------------------------------------------------------------*

inline uint64_t nodeHashCode (const cBDDnode inNode) {
  uint64_t result = bothBranches (inNode) % (uint64_t) gCollisionMapSize ;
  result <<= 32 ;
  result = (result | inNode.mVariableIndex) % (uint64_t) gCollisionMapSize ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void reallocHashMap (const uint32_t inNewSize) {
  if ((0 < inNewSize) && (inNewSize != gCollisionMapSize)) {
    if (C_BDD::displaysInformationMessages ()) {
      printf ("BDD package info: hash map reallocated to %u %03u %03u (%u MB)\n",
              inNewSize / 1000000, (inNewSize / 1000) % 1000, inNewSize % 1000,
              (inNewSize * (uint32_t) sizeof (uint32_t)) / 1000000) ;
    }
    macroMyReallocPODArray (gCollisionMap, uint32_t, inNewSize) ;
    gCollisionMapSize = inNewSize ;
    for (uint32_t i=0 ; i<gCollisionMapSize ; i++) {
      gCollisionMap [i] = 0 ;
    }
    for (uint32_t nodeIndex=1 ; nodeIndex<=gCurrentNodeCount ; nodeIndex++) {
      const uint64_t hashCode = nodeHashCode (gNodeArray [nodeIndex]) ;
      gNodeArray [nodeIndex].mAuxiliary = gCollisionMap [hashCode] ;
      gCollisionMap [hashCode] = nodeIndex ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static const uint32_t kUniqueMapSizeIncrement = 4194304 ;

//---------------------------------------------------------------------------------------------------------------------*

static uint32_t addNewNode (const cBDDnode inNode) {
  if (gNodeArraySize <= (gCurrentNodeCount + 1)) {
    const uint32_t newSize = gNodeArraySize + kUniqueMapSizeIncrement ;
    if (newSize > (1U << 31)) {
      printf ("*** BDD package node map saturation: needs more than 2 ** 31 nodes\n") ;
      exit (1) ;
    }else  if (C_BDD::displaysInformationMessages ()) {
      printf ("BDD package info: node map reallocated to %u %03u %03u (%u MB)\n",
              newSize / 1000000, (newSize / 1000) % 1000, newSize % 1000,
              (newSize * (uint32_t) sizeof (cBDDnode)) / 1000000) ;
    }
    macroMyReallocPODArray (gNodeArray, cBDDnode, newSize) ;
    macroMyReallocPODArray (gMarkTable, uint64_t, newSize >> 6) ;
    gNodeArraySize = newSize ;
    gNodeArray [0].mELSE = 0 ;
    gNodeArray [0].mTHEN = 0 ;
    gNodeArray [0].mVariableIndex = 0 ;
  }
  if (gHashMapExpandable && (gCurrentNodeCount > (gCollisionMapSize / 2))) {
    const uint32_t newSize = getPrimeGreaterThan (gCollisionMapSize + 1) ;
    if (newSize < (1U << gHashMapPowerOfTwoMaxSize)) {
      uint32_t newMemoryUsage = C_BDD::currentMemoryUsage () ;
      newMemoryUsage -= hashMapMemoryUsage () ;
      newMemoryUsage += (uint32_t) ((newSize * sizeof (uint32_t)) / 1000000) ;
      if (newMemoryUsage < C_BDD::maximumMemoryUsage ()) {
        reallocHashMap (newSize) ;
      }else{
        gHashMapExpandable = false ;
        if (C_BDD::displaysInformationMessages ()) {
          printf ("BDD package info: hash map reallocation to %u %03u %03u inhibited (max RAM usage reached)\n",
            newSize / 1000000,
            (newSize / 1000) % 1000,
            newSize % 1000) ;
        }
      }
    }else{
      gHashMapExpandable = false ;
      if (C_BDD::displaysInformationMessages ()) {
        printf ("BDD package info: hash map reallocation to %u %03u %03u inhibited (max size reached)\n",
          newSize / 1000000,
          (newSize / 1000) % 1000,
          newSize % 1000) ;
      }
    }
  }
 //--- Retrieve a free node
  gCurrentNodeCount ++ ;
  gNodeArray [gCurrentNodeCount] = inNode ;
//--- Enter in hash map
  const uint64_t hashCode = nodeHashCode (inNode) ;
  gNodeArray [gCurrentNodeCount].mAuxiliary = gCollisionMap [hashCode] ;
  gCollisionMap [hashCode] = gCurrentNodeCount ;
//---
  return gCurrentNodeCount ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::unmarkAllExistingBDDnodes (void) {
  MF_Assert ((gNodeArraySize % 64) == 0, "gNodeArraySize (%lld) is not a multiple of 64", gNodeArraySize, 0) ;
  for (uint32_t i=0 ; i<(gNodeArraySize >> 6) ; i++) {
    gMarkTable [i] = 0 ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static bool isNodeMarked (const uint32_t inValue COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  bool marked = nodeIndex == 0 ;
  if (! marked) {
    MF_AssertThere (nodeIndex > 0, "nodeIndex (%lld) should be > 0", nodeIndex, 0) ;
    MF_AssertThere (nodeIndex <= gCurrentNodeCount, "nodeIndex (%lld) should be <= gCurrentNodeCount (%lld)", nodeIndex, gCurrentNodeCount) ;
    const uint64_t mask = 1ULL << (nodeIndex & 0x3F) ;
    const uint32_t idx = nodeIndex >> 6 ;
    marked = (gMarkTable [idx] & mask) != 0 ;
  }
  return marked ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool isNodeMarkedThenMark (const uint32_t inValue COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = inValue >> 1 ;
  MF_AssertThere (nodeIndex > 0, "nodeIndex (%lld) should be > 0", nodeIndex, 0) ;
  MF_AssertThere (nodeIndex <= gCurrentNodeCount, "nodeIndex (%lld) should be <= gCurrentNodeCount (%lld)", nodeIndex, gCurrentNodeCount) ;
  const uint64_t mask = 1ULL << (nodeIndex & 0x3F) ;
  const uint32_t idx = nodeIndex >> 6 ;
  const bool isMarked = (gMarkTable [idx] & mask) != 0 ;
  gMarkTable [idx] |= mask ;
  return isMarked ;
}

//---------------------------------------------------------------------------------------------------------------------*

void markNode (const uint32_t inValue) {
  const uint32_t nodeIndex = inValue >> 1 ;
  MF_Assert (nodeIndex > 0, "nodeIndex (%lld) should be > 0", nodeIndex, 0) ;
  MF_Assert (nodeIndex <= gCurrentNodeCount, "nodeIndex (%lld) should be <= gCurrentNodeCount (%lld)", nodeIndex, gCurrentNodeCount) ;
  const uint64_t mask = 1ULL << (nodeIndex & 0x3F) ;
  const uint32_t idx = nodeIndex >> 6 ;
  gMarkTable [idx] |= mask ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_BDD::getMarkedNodesCount (void) {
  uint32_t count = 0 ;
  for (uint32_t i=0 ; i<(gNodeArraySize >> 6) ; i++) {
    uint64_t v = gMarkTable [i] ;
    while (v > 0) {
      count += (v & 1) != 0 ;
      v >>= 1 ;
    }
  }
  return count ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  BDD objects hash map                                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t kInitialCollisionMapPowerOfTwoSize = 20 ; 

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//       BDD unique table implementation                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

macroDeclareStaticMutex (semaphore)

//---------------------------------------------------------------------------------------------------------------------*

uint32_t find_or_add (const uint32_t inBoolVar,
                      const uint32_t inELSEbranch,
                      const uint32_t inTHENbranch
                      COMMA_UNUSED_LOCATION_ARGS) {
  uint32_t result = inELSEbranch ;
  if (inELSEbranch != inTHENbranch) {
    macroMutexLock (semaphore) ;
      if (0 == gCollisionMapSize) {
        reallocHashMap (getPrimeGreaterThan (1U << kInitialCollisionMapPowerOfTwoSize)) ;
      }
      const uint32_t complement = inELSEbranch & 1 ;
      const uint32_t c1 = inTHENbranch ^ complement ;
      const uint32_t c0 = inELSEbranch ^ complement ;
 //     const cBDDnode candidateNode = cBDDnode (c1, c0, inBoolVar) ;
      const cBDDnode candidateNode = {c1, c0, inBoolVar, 0} ;
      // printf ("candidateNode %llu gCollisionMapSize %u\n", candidateNode, gCollisionMapSize) ;
      const uint64_t hashCode = nodeHashCode (candidateNode) ;
      uint32_t nodeIndex = gCollisionMap [hashCode] ;
      while ((0 != nodeIndex)
         && ((bothBranches (gNodeArray [nodeIndex]) != bothBranches (candidateNode))
          || (gNodeArray [nodeIndex].mVariableIndex != candidateNode.mVariableIndex))) {
        nodeIndex = gNodeArray [nodeIndex].mAuxiliary ;
      }
      if (0 == nodeIndex) {
        nodeIndex = addNewNode (candidateNode) ;
      }
    macroMutexUnlock (semaphore) ;
    result = (nodeIndex << 1) | complement ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::setHashMapMaxSize (const uint32_t inPowerOfTwoSize) {
  gHashMapPowerOfTwoMaxSize = inPowerOfTwoSize ;
  if (C_BDD::displaysInformationMessages ()) {
    printf ("BDD package info: hash map max size limited < 2 ** %u\n", gHashMapPowerOfTwoMaxSize) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static C_BDD gBDDinstancesListRoot ;

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_BDD::getBDDinstancesCount (void) {
  uint32_t n = 0 ;
  C_BDD * p = gBDDinstancesListRoot.mPtrToNextBDD ;
  while (p != & gBDDinstancesListRoot) {
    n ++ ;
    p = p->mPtrToNextBDD ;
  }
  return n ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Mark and Sweep
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void recursiveMarkBDDNodes (const uint32_t inValue) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  if ((nodeIndex > 0) && ! isNodeMarkedThenMark (inValue COMMA_HERE)) {
    if (bothBranches (gNodeArray [nodeIndex]) != 0) {
      recursiveMarkBDDNodes (gNodeArray [nodeIndex].mTHEN) ;
      recursiveMarkBDDNodes (gNodeArray [nodeIndex].mELSE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::markAllBDDnodes (void) {
  recursiveMarkBDDNodes (mBDDvalue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::markAndSweepUnusedNodes (void) {
  C_Timer timer ;
/* printf ("mark and sweep\n") ; fflush (stdout) ;
  for (uint32_t nodeIndex=2 ; nodeIndex<=gCurrentNodeCount ; nodeIndex++) {
    for (uint32_t idx=1 ; idx<nodeIndex ; idx++) {
      MF_Assert (gNodeArray [nodeIndex] != gNodeArray [idx], "(gNodeArray [nodeIndex]  (%lld) != gNodeArray [idx] [%lld]", nodeIndex, idx) ;
    }
  }*/
//--- Clear operation caches
  clearANDOperationCache () ;
//--- Effacer tous les champs marquage des elements BDD existants
  unmarkAllExistingBDDnodes () ;
//--- Marquer tous les elements utilises
  C_BDD * p = gBDDinstancesListRoot.mPtrToNextBDD ;
  while (p != & gBDDinstancesListRoot) {
    recursiveMarkBDDNodes (p->mBDDvalue) ;
    p = p->mPtrToNextBDD ;
  }
//--- Parcourir la table des elements BDD et recycler ceux qui sont inutilises
  uint32_t unchangedNodeCount = 0 ;
  if (gNodeArraySize > 0) {
    gNodeArray [0].mAuxiliary = 0 ;
    if (gMarkTable [0] == ~ 1LLU) {
      unchangedNodeCount = 63 ;
      for (uint32_t i=1 ; (i<(gNodeArraySize >> 6)) && (gMarkTable [i] == ~ 0LLU) ; i++) {
        unchangedNodeCount += 64 ;
      }
    }
  }
  // printf ("********************************************** %u nodes inchanges\n", unchangedNodeCount) ;
  for (uint32_t i=1 ; i<=unchangedNodeCount ; i++) {
    gNodeArray [i].mAuxiliary = i ;
  }
  uint32_t newNodeCount = unchangedNodeCount ;
  for (uint32_t nodeIndex=unchangedNodeCount+1 ; nodeIndex<=gCurrentNodeCount ; nodeIndex++) {
    if (isNodeMarked (nodeIndex << 1 COMMA_HERE)) { // Node is used
      const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
      const uint32_t thenBranch = gNodeArray [nodeIndex].mTHEN ;
      const uint32_t elseBranch = gNodeArray [nodeIndex].mELSE ;
      MF_Assert ((thenBranch >> 1) < nodeIndex, "(thenBranch [%lld] >> 1) < nodeIndex [%lld]", thenBranch >> 1, nodeIndex) ;
      MF_Assert ((elseBranch >> 1) < nodeIndex, "(elseBranch [%lld] >> 1) < nodeIndex [%lld]", elseBranch >> 1, nodeIndex) ;
      const uint32_t newThenBranch = (gNodeArray [thenBranch >> 1].mAuxiliary << 1) | (thenBranch & 1) ;
      const uint32_t newElseBranch = (gNodeArray [elseBranch >> 1].mAuxiliary << 1) | (elseBranch & 1) ;
      newNodeCount ++ ;
      gNodeArray [newNodeCount].mTHEN = newThenBranch ;
      gNodeArray [newNodeCount].mELSE = newElseBranch ;
      gNodeArray [newNodeCount].mVariableIndex = var ;
      gNodeArray [nodeIndex].mAuxiliary = newNodeCount ;
     // MF_Assert (node == newNode, "node [%lld] == newNode [%lld]", node, newNode) ;
      //if (newNodeCount < 10) {
      //  printf ("index %4u -> %4u, node %16llX -> %16llX\n", nodeIndex, newNodeCount, node, newNode) ;
      // }
    }
  }
  // printf ("gCurrentNodeCount %u -> %u\n", gCurrentNodeCount, newNodeCount) ;
  const uint32_t previousNodeCount = gCurrentNodeCount ;
  gCurrentNodeCount = newNodeCount ;
  p = gBDDinstancesListRoot.mPtrToNextBDD ;
  while (p != & gBDDinstancesListRoot) {
    const uint32_t previousValue = p->mBDDvalue ;
    MF_Assert ((gNodeArray [previousValue >> 1].mAuxiliary) <= (previousValue >> 1), "(elseBranch [%lld] >> 1) <= nodeIndex [%lld]", (gNodeArray [previousValue >> 1].mAuxiliary), previousValue >> 1) ;
    p->mBDDvalue = (gNodeArray [previousValue >> 1].mAuxiliary << 1) | (previousValue & 1) ;
    // printf ("root %X -> %X\n", previousValue, p->mBDDvalue) ;
   // MF_Assert (previousValue == p->mBDDvalue, "(previousValue [%lld] >> 1) == p->mBDDvalue [%lld]", previousValue, p->mBDDvalue) ;
    p = p->mPtrToNextBDD ;
  }
//--- Check for node unicity
  /* for (uint32_t nodeIndex=1 ; nodeIndex<=gCurrentNodeCount ; nodeIndex++) {
    for (uint32_t idx=1 ; idx<nodeIndex ; idx++) {
      MF_Assert (gNodeArray [nodeIndex] != gNodeArray [idx], "(gNodeArray [nodeIndex]  (%lld) != gNodeArray [idx] [%lld]", nodeIndex, idx) ;
    }
  } */
//--- Rebuilt collision map
  for (uint32_t i=0 ; i<gCollisionMapSize ; i++) {
    gCollisionMap [i] = 0 ;
  }
  if (0 < gCollisionMapSize) {
    for (uint32_t nodeIndex=1 ; nodeIndex<=gCurrentNodeCount ; nodeIndex++) {
      const uint64_t hashCode = nodeHashCode (gNodeArray [nodeIndex]) ;
      gNodeArray [nodeIndex].mAuxiliary = gCollisionMap [hashCode] ;
      gCollisionMap [hashCode] = nodeIndex ;
    }
  }
  if (C_BDD::displaysInformationMessages ()) {
    co << "BDD package info: mark and sweep done in " << timer
       << " (nodes " << cStringWithUnsigned (previousNodeCount) << " -> " << cStringWithUnsigned (gCurrentNodeCount) << ")\n" ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD constructors, destructor, assignment
#endif

//---------------------------------------------------------------------------------------------------------------------*

C_BDD::C_BDD (void) :
mBDDvalue (0),
mPtrToPreviousBDD (NULL),
mPtrToNextBDD (NULL) {
  initLinks () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD::C_BDD (const uint32_t inValue) :
mBDDvalue (inValue),
mPtrToPreviousBDD (NULL),
mPtrToNextBDD (NULL) {
  initLinks () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD::C_BDD (const uint32_t variable,
              const bool inSign) :
mBDDvalue (0),
mPtrToPreviousBDD (NULL),
mPtrToNextBDD (NULL) {
  initLinks () ;
  const uint32_t complement = inSign ? 0U : 1U ;
  mBDDvalue = find_or_add (variable, complement, complement ^ 1 COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD::C_BDD (const C_BDD & inSource) :
mBDDvalue (inSource.mBDDvalue),
mPtrToPreviousBDD (NULL),
mPtrToNextBDD (NULL) {
  initLinks () ;
}

//---------------------------------------------------------------------------------------------------------------------*

macroDeclareStaticMutex (semaphoreLink)

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::initLinks (void) {
  mPtrToPreviousBDD = this ;
  mPtrToNextBDD = this ;
  macroMutexLock (semaphoreLink) ;
    C_BDD * suivantRacine = gBDDinstancesListRoot.mPtrToNextBDD ;
    mPtrToPreviousBDD = & gBDDinstancesListRoot ;
    suivantRacine->mPtrToPreviousBDD = this ;
    mPtrToNextBDD = suivantRacine ;
    gBDDinstancesListRoot.mPtrToNextBDD = this ;
  macroMutexUnlock (semaphoreLink) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD::~C_BDD (void) {
  mBDDvalue = 0 ;
  macroMutexLock (semaphoreLink) ;
    C_BDD * suivant = mPtrToNextBDD ;
    C_BDD * precedent = mPtrToPreviousBDD ;
    precedent->mPtrToNextBDD = suivant ;
    suivant->mPtrToPreviousBDD = precedent ;
  macroMutexUnlock (semaphoreLink) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD & C_BDD::operator = (const C_BDD & inSource) {
  mBDDvalue = inSource.mBDDvalue ;
  return *this ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Check all BDDs are well-formed
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void internalCheckBDDIsWellFormed (const uint32_t inBDD,
                                          const uint32_t inCurrentVar
                                          COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inBDD COMMA_HERE) ;
  if (0 != bothBranches (gNodeArray [nodeIndex])) {
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    if (var >= inCurrentVar) {
     #ifndef DO_NOT_GENERATE_CHECKINGS
        printf ("*** ERROR at %s:%d: BDD is not well-formed (var %u sould be < var %u) ***\n", IN_SOURCE_FILE, IN_SOURCE_LINE, var, inCurrentVar) ;
      #else
        printf ("*** ERROR (compile in debug mode for locating the error): BDD is not well-formed (var %u sould be < var %u) ***\n", var, inCurrentVar) ;
      #endif
      exit (1) ;
    }
    if (! isNodeMarkedThenMark (inBDD COMMA_HERE)) {
      internalCheckBDDIsWellFormed (gNodeArray [nodeIndex].mTHEN, var COMMA_HERE) ;
      internalCheckBDDIsWellFormed (gNodeArray [nodeIndex].mELSE, var COMMA_HERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::checkAllBDDsAreWellFormed (LOCATION_ARGS) {
//--- Unmark all nodes
  unmarkAllExistingBDDnodes () ;
//--- Check BDDs
  C_BDD * p = gBDDinstancesListRoot.mPtrToNextBDD ;
  while (p != & gBDDinstancesListRoot) {
    internalCheckBDDIsWellFormed (p->mBDDvalue, UINT16_MAX COMMA_THERE) ;
    p = p->mPtrToNextBDD ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::checkBDDIsWellFormed (LOCATION_ARGS) {
//--- Unmark all nodes
  unmarkAllExistingBDDnodes () ;
//--- Check BDD
  internalCheckBDDIsWellFormed (mBDDvalue, UINT16_MAX COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Memory Usage
#endif

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_BDD::currentMemoryUsage (void) {
  uint32_t result = nodeMapMemoryUsage () ;
  result += hashMapMemoryUsage () ;
  result += ANDCacheMemoryUsage () ;
  result += singleOperandOperationCacheMemoryUsage () ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static uint32_t gMaximumMemoryUsage = UINT32_MAX ;

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_BDD::maximumMemoryUsage (void) { // In MB
  return gMaximumMemoryUsage ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::setMaximumMemoryUsage (const uint32_t inMaxMemoryUsage) { // In MB
  gMaximumMemoryUsage = inMaxMemoryUsage ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD Package stats
#endif

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::printBDDpackageOperationsSummary (AC_OutputStream & inStream) {
  #ifdef __LP64__
    const uint32_t mode = 64 ;
  #else
    const uint32_t mode = 32 ;
  #endif
  inStream << "\n"
              "Statistics about BDD package ("
           << cStringWithUnsigned (mode)
           << "-bit mode, "
           << cStringWithUnsigned (getBDDnodeSize ())
           << " bytes for a BDD node)\n" ;
  inStream << "  Current BDD count: " << cStringWithUnsigned (getBDDinstancesCount ()) << "\n"
              "  Created nodes count: " << cStringWithUnsigned (getCreatedNodesCount ()) << "\n"
              "  RAM usage: " ;
  inStream.appendUnsigned (currentMemoryUsage ()) ;
  inStream << " MB\n" ;
//---
  inStream << "Unique table:\n" ;
  inStream << "  size: " << cStringWithUnsigned (gCollisionMapSize)
           << " (" << cStringWithUnsigned ((gCollisionMapSize * sizeof (uint32_t)) / 1000000) << " MB)\n" ;
  TC_UniqueArray <uint32_t> entrySizeArray (1 COMMA_HERE) ;
  for (uint32_t i=0 ; i<gCollisionMapSize ; i++) {
    int32_t length = 0 ;
    uint32_t nodeIndex = gCollisionMap [i] ;
    while (0 != nodeIndex) {
      length ++ ;
      nodeIndex = gNodeArray [nodeIndex].mAuxiliary ;
    }
    if (entrySizeArray.count () > length) {
      entrySizeArray.incrementAtIndex (length COMMA_HERE) ;
    }else{
      entrySizeArray.forceObjectAtIndex (length, 1, 0 COMMA_HERE) ;
    }
  }  
  for (int32_t i=0 ; i<entrySizeArray.count () ; i++) {
    if ((entrySizeArray (i COMMA_HERE) > 0) && (gCollisionMapSize > 0)) {
      inStream << "  " << cStringWithUnsigned (entrySizeArray (i COMMA_HERE))
               << " entries of size " << cStringWithSigned (i) 
               << " (" << cStringWithUnsigned ((100UL * entrySizeArray (i COMMA_HERE)) / gCollisionMapSize) << "%)\n" ;
    }
  }  
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::freeBDDStataStructures (void) {
  releaseANDOperationCache () ;
  releaseSingleOperandOperationCache () ;
  C_BDD::markAndSweepUnusedNodes () ;
  if (0 == gCurrentNodeCount) {
    macroMyDeletePODArray (gCollisionMap) ;
    macroMyDeletePODArray (gMarkTable) ;
    macroMyDeletePODArray (gNodeArray) ;
  }else{
    #ifndef DO_NOT_GENERATE_CHECKINGS 
      printf ("BDD package info: cannot free BDD structures, %u C_BDD instances, %u BDD nodes still alive\n",
              C_BDD::getBDDinstancesCount (),
              gCurrentNodeCount) ;
    #endif
  }
}

//---------------------------------------------------------------------------------------------------------------------*

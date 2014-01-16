//---------------------------------------------------------------------------*
//                                                                           *
//     BDD package (implementation of ROBDD)                                 *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1999, ..., 2013 Pierre Molinaro.                           *
//                                                                           *
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

#include "bdd/C_BDD.h"
#include "utilities/F_GetPrime.h"
#include "utilities/C_PrologueEpilogue.h"
#include "utilities/M_Threads.h"
#include "strings/C_String.h"
#include "bdd/C_BDD-node.h"
#include "time/C_Timer.h"

//---------------------------------------------------------------------------*

#include <stddef.h>
#include <string.h>
#include <limits.h>

//---------------------------------------------------------------------*

PMUInt32 C_BDD::getBDDnodeSize (void) {
  return (PMUInt32) sizeof (cBDDnode) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  BDD objects unique table                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

static PMUInt32 gNodeArraySize = 0 ;
cBDDnode * gNodeArray = NULL ;
static PMUInt64 * gMarkTable = NULL ;
static PMUInt32 gCurrentNodeCount = 0 ;

//---------------------------------------------------------------------*

PMUInt32 nodeMapMemoryUsage (void) {
  return (gNodeArraySize * C_BDD::getBDDnodeSize ()) / 1000000 ;
}

//---------------------------------------------------------------------*

PMUInt32 C_BDD::getCreatedNodesCount (void) {
  return gNodeArraySize ;
}

//------------------------------------------------------------------------*

PMUInt32 C_BDD::getExistingNodesCount (void) {
  return gCurrentNodeCount ;
}

//---------------------------------------------------------------------------*

static PMUInt32 * gCollisionMap = NULL ;
static PMUInt32 gCollisionMapSize = 0 ;
static PMUInt32 gHashMapPowerOfTwoMaxSize = 31 ;
static bool gHashMapExpandable = true ;

//---------------------------------------------------------------------*

PMUInt32 hashMapMemoryUsage (void) {
  return (PMUInt32) ((gCollisionMapSize * sizeof (PMUInt32)) / 1000000) ;
}

//---------------------------------------------------------------------*

inline PMUInt64 nodeHashCode (const cBDDnode inNode) {
  PMUInt64 result = inNode.bothBranches () % (PMUInt64) gCollisionMapSize ;
  result <<= 32 ;
  result = (result | inNode.mVariableIndex) % (PMUInt64) gCollisionMapSize ;
  return result ;
}

//---------------------------------------------------------------------*

static void reallocHashMap (const PMUInt32 inNewSize) {
  if ((0 < inNewSize) && (inNewSize != gCollisionMapSize)) {
    if (C_BDD::displaysInformationMessages ()) {
      printf ("BDD package info: hash map reallocated to %u %03u %03u (%u MB)\n",
              inNewSize / 1000000, (inNewSize / 1000) % 1000, inNewSize % 1000,
              (inNewSize * (PMUInt32) sizeof (PMUInt32)) / 1000000) ;
    }
    macroMyReallocPODArray (gCollisionMap, PMUInt32, inNewSize) ;
    gCollisionMapSize = inNewSize ;
    for (PMUInt32 i=0 ; i<gCollisionMapSize ; i++) {
      gCollisionMap [i] = 0 ;
    }
    for (PMUInt32 nodeIndex=1 ; nodeIndex<=gCurrentNodeCount ; nodeIndex++) {
      const PMUInt64 hashCode = nodeHashCode (gNodeArray [nodeIndex]) ;
      gNodeArray [nodeIndex].mAuxiliary = gCollisionMap [hashCode] ;
      gCollisionMap [hashCode] = nodeIndex ;
    }
  }
}

//---------------------------------------------------------------------------*

static const PMUInt32 kUniqueMapSizeIncrement = 4194304 ;

//---------------------------------------------------------------------------*

static PMUInt32 addNewNode (const cBDDnode inNode) {
  if (gNodeArraySize <= (gCurrentNodeCount + 1)) {
    const PMUInt32 newSize = gNodeArraySize + kUniqueMapSizeIncrement ;
    if (newSize > (1U << 31)) {
      printf ("*** BDD package node map saturation: needs more than 2 ** 31 nodes\n") ;
      exit (1) ;
    }else  if (C_BDD::displaysInformationMessages ()) {
      printf ("BDD package info: node map reallocated to %u %03u %03u (%u MB)\n",
              newSize / 1000000, (newSize / 1000) % 1000, newSize % 1000,
              (newSize * (PMUInt32) sizeof (cBDDnode)) / 1000000) ;
    }
    macroMyReallocPODArray (gNodeArray, cBDDnode, newSize) ;
    macroMyReallocPODArray (gMarkTable, PMUInt64, newSize >> 6) ;
    gNodeArraySize = newSize ;
    gNodeArray [0].mELSE = 0 ;
    gNodeArray [0].mTHEN = 0 ;
    gNodeArray [0].mVariableIndex = 0 ;
  }
  if (gHashMapExpandable && (gCurrentNodeCount > (gCollisionMapSize / 2))) {
    const PMUInt32 newSize = getPrimeGreaterThan (gCollisionMapSize + 1) ;
    if (newSize < (1U << gHashMapPowerOfTwoMaxSize)) {
      PMUInt32 newMemoryUsage = C_BDD::currentMemoryUsage () ;
      newMemoryUsage -= hashMapMemoryUsage () ;
      newMemoryUsage += (PMUInt32) ((newSize * sizeof (PMUInt32)) / 1000000) ;
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
  const PMUInt64 hashCode = nodeHashCode (inNode) ;
  gNodeArray [gCurrentNodeCount].mAuxiliary = gCollisionMap [hashCode] ;
  gCollisionMap [hashCode] = gCurrentNodeCount ;
//---
  return gCurrentNodeCount ;
}

//------------------------------------------------------------------------*

void C_BDD::unmarkAllExistingBDDnodes (void) {
  MF_Assert ((gNodeArraySize % 64) == 0, "gNodeArraySize (%lld) is not a multiple of 64", gNodeArraySize, 0) ;
  for (PMUInt32 i=0 ; i<(gNodeArraySize >> 6) ; i++) {
    gMarkTable [i] = 0 ;
  }
}

//------------------------------------------------------------------------*

static bool isNodeMarked (const PMUInt32 inValue COMMA_LOCATION_ARGS) {
  const PMUInt32 nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  bool marked = nodeIndex == 0 ;
  if (! marked) {
    MF_AssertThere (nodeIndex > 0, "nodeIndex (%lld) should be > 0", nodeIndex, 0) ;
    MF_AssertThere (nodeIndex <= gCurrentNodeCount, "nodeIndex (%lld) should be <= gCurrentNodeCount (%lld)", nodeIndex, gCurrentNodeCount) ;
    const PMUInt64 mask = 1ULL << (nodeIndex & 0x3F) ;
    const PMUInt32 idx = nodeIndex >> 6 ;
    marked = (gMarkTable [idx] & mask) != 0 ;
  }
  return marked ;
}

//------------------------------------------------------------------------*

bool isNodeMarkedThenMark (const PMUInt32 inValue COMMA_LOCATION_ARGS) {
  const PMUInt32 nodeIndex = inValue >> 1 ;
  MF_AssertThere (nodeIndex > 0, "nodeIndex (%lld) should be > 0", nodeIndex, 0) ;
  MF_AssertThere (nodeIndex <= gCurrentNodeCount, "nodeIndex (%lld) should be <= gCurrentNodeCount (%lld)", nodeIndex, gCurrentNodeCount) ;
  const PMUInt64 mask = 1ULL << (nodeIndex & 0x3F) ;
  const PMUInt32 idx = nodeIndex >> 6 ;
  const bool isMarked = (gMarkTable [idx] & mask) != 0 ;
  gMarkTable [idx] |= mask ;
  return isMarked ;
}

//------------------------------------------------------------------------*

void markNode (const PMUInt32 inValue) {
  const PMUInt32 nodeIndex = inValue >> 1 ;
  MF_Assert (nodeIndex > 0, "nodeIndex (%lld) should be > 0", nodeIndex, 0) ;
  MF_Assert (nodeIndex <= gCurrentNodeCount, "nodeIndex (%lld) should be <= gCurrentNodeCount (%lld)", nodeIndex, gCurrentNodeCount) ;
  const PMUInt64 mask = 1ULL << (nodeIndex & 0x3F) ;
  const PMUInt32 idx = nodeIndex >> 6 ;
  gMarkTable [idx] |= mask ;
}

//---------------------------------------------------------------------------*

PMUInt32 C_BDD::getMarkedNodesCount (void) {
  PMUInt32 count = 0 ;
  for (PMUInt32 i=0 ; i<(gNodeArraySize >> 6) ; i++) {
    PMUInt64 v = gMarkTable [i] ;
    while (v > 0) {
      count += (v & 1) != 0 ;
      v >>= 1 ;
    }
  }
  return count ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  BDD objects hash map                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

static const PMSInt32 kInitialCollisionMapPowerOfTwoSize = 20 ; 

//---------------------------------------------------------------------------*
//                                                                           *
//       BDD unique table implementation                                     *
//                                                                           *
//---------------------------------------------------------------------------*

macroDeclareStaticMutex (semaphore)

//---------------------------------------------------------------------------*

PMUInt32 find_or_add (const PMUInt32 inBoolVar,
                      const PMUInt32 inELSEbranch,
                      const PMUInt32 inTHENbranch
                      COMMA_UNUSED_LOCATION_ARGS) {
  PMUInt32 result = inELSEbranch ;
  if (inELSEbranch != inTHENbranch) {
    macroMutexLock (semaphore) ;
      if (0 == gCollisionMapSize) {
        reallocHashMap (getPrimeGreaterThan (1U << kInitialCollisionMapPowerOfTwoSize)) ;
      }
      const PMUInt32 complement = inELSEbranch & 1 ;
      const PMUInt32 c1 = inTHENbranch ^ complement ;
      const PMUInt32 c0 = inELSEbranch ^ complement ;
      const cBDDnode candidateNode = cBDDnode (c1, c0, inBoolVar) ;
      // printf ("candidateNode %llu gCollisionMapSize %u\n", candidateNode, gCollisionMapSize) ;
      const PMUInt64 hashCode = nodeHashCode (candidateNode) ;
      PMUInt32 nodeIndex = gCollisionMap [hashCode] ;
      while ((0 != nodeIndex)
         && ((gNodeArray [nodeIndex].bothBranches () != candidateNode.bothBranches ())
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

//---------------------------------------------------------------------*

void C_BDD::setHashMapMaxSize (const PMUInt32 inPowerOfTwoSize) {
  gHashMapPowerOfTwoMaxSize = inPowerOfTwoSize ;
  if (C_BDD::displaysInformationMessages ()) {
    printf ("BDD package info: hash map max size limited < 2 ** %u\n", gHashMapPowerOfTwoMaxSize) ;
  }
}

//---------------------------------------------------------------------*

static C_BDD gBDDinstancesListRoot ;

//------------------------------------------------------------------------*

PMUInt32 C_BDD::getBDDinstancesCount (void) {
  PMUInt32 n = 0 ;
  C_BDD * p = gBDDinstancesListRoot.mPtrToNextBDD ;
  while (p != & gBDDinstancesListRoot) {
    n ++ ;
    p = p->mPtrToNextBDD ;
  }
  return n ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Mark and Sweep
#endif

//------------------------------------------------------------------------*

static void recursiveMarkBDDNodes (const PMUInt32 inValue) {
  const PMUInt32 nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  if ((nodeIndex > 0) && ! isNodeMarkedThenMark (inValue COMMA_HERE)) {
    if (gNodeArray [nodeIndex].bothBranches () != 0) {
      recursiveMarkBDDNodes (gNodeArray [nodeIndex].mTHEN) ;
      recursiveMarkBDDNodes (gNodeArray [nodeIndex].mELSE) ;
    }
  }
}

//---------------------------------------------------------------------*

void C_BDD::markAllBDDnodes (void) {
  recursiveMarkBDDNodes (mBDDvalue) ;
}

//------------------------------------------------------------------------*

void C_BDD::markAndSweepUnusedNodes (void) {
  C_Timer timer ;
/* printf ("mark and sweep\n") ; fflush (stdout) ;
  for (PMUInt32 nodeIndex=2 ; nodeIndex<=gCurrentNodeCount ; nodeIndex++) {
    for (PMUInt32 idx=1 ; idx<nodeIndex ; idx++) {
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
  PMUInt32 unchangedNodeCount = 0 ;
  if (gNodeArraySize > 0) {
    gNodeArray [0].mAuxiliary = 0 ;
    if (gMarkTable [0] == ~ 1LLU) {
      unchangedNodeCount = 63 ;
      for (PMUInt32 i=1 ; (i<(gNodeArraySize >> 6)) && (gMarkTable [i] == ~ 0LLU) ; i++) {
        unchangedNodeCount += 64 ;
      }
    }
  }
  // printf ("********************************************** %u nodes inchanges\n", unchangedNodeCount) ;
  for (PMUInt32 i=1 ; i<=unchangedNodeCount ; i++) {
    gNodeArray [i].mAuxiliary = i ;
  }
  PMUInt32 newNodeCount = unchangedNodeCount ;
  for (PMUInt32 nodeIndex=unchangedNodeCount+1 ; nodeIndex<=gCurrentNodeCount ; nodeIndex++) {
    if (isNodeMarked (nodeIndex << 1 COMMA_HERE)) { // Node is used
      const PMUInt32 var = gNodeArray [nodeIndex].mVariableIndex ;
      const PMUInt32 thenBranch = gNodeArray [nodeIndex].mTHEN ;
      const PMUInt32 elseBranch = gNodeArray [nodeIndex].mELSE ;
      MF_Assert ((thenBranch >> 1) < nodeIndex, "(thenBranch [%lld] >> 1) < nodeIndex [%lld]", thenBranch >> 1, nodeIndex) ;
      MF_Assert ((elseBranch >> 1) < nodeIndex, "(elseBranch [%lld] >> 1) < nodeIndex [%lld]", elseBranch >> 1, nodeIndex) ;
      const PMUInt32 newThenBranch = (gNodeArray [thenBranch >> 1].mAuxiliary << 1) | (thenBranch & 1) ;
      const PMUInt32 newElseBranch = (gNodeArray [elseBranch >> 1].mAuxiliary << 1) | (elseBranch & 1) ;
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
  const PMUInt32 previousNodeCount = gCurrentNodeCount ;
  gCurrentNodeCount = newNodeCount ;
  p = gBDDinstancesListRoot.mPtrToNextBDD ;
  while (p != & gBDDinstancesListRoot) {
    const PMUInt32 previousValue = p->mBDDvalue ;
    MF_Assert ((gNodeArray [previousValue >> 1].mAuxiliary) <= (previousValue >> 1), "(elseBranch [%lld] >> 1) <= nodeIndex [%lld]", (gNodeArray [previousValue >> 1].mAuxiliary), previousValue >> 1) ;
    p->mBDDvalue = (gNodeArray [previousValue >> 1].mAuxiliary << 1) | (previousValue & 1) ;
    // printf ("root %X -> %X\n", previousValue, p->mBDDvalue) ;
   // MF_Assert (previousValue == p->mBDDvalue, "(previousValue [%lld] >> 1) == p->mBDDvalue [%lld]", previousValue, p->mBDDvalue) ;
    p = p->mPtrToNextBDD ;
  }
//--- Check for node unicity
  /* for (PMUInt32 nodeIndex=1 ; nodeIndex<=gCurrentNodeCount ; nodeIndex++) {
    for (PMUInt32 idx=1 ; idx<nodeIndex ; idx++) {
      MF_Assert (gNodeArray [nodeIndex] != gNodeArray [idx], "(gNodeArray [nodeIndex]  (%lld) != gNodeArray [idx] [%lld]", nodeIndex, idx) ;
    }
  } */
//--- Rebuilt collision map
  for (PMUInt32 i=0 ; i<gCollisionMapSize ; i++) {
    gCollisionMap [i] = 0 ;
  }
  if (0 < gCollisionMapSize) {
    for (PMUInt32 nodeIndex=1 ; nodeIndex<=gCurrentNodeCount ; nodeIndex++) {
      const PMUInt64 hashCode = nodeHashCode (gNodeArray [nodeIndex]) ;
      gNodeArray [nodeIndex].mAuxiliary = gCollisionMap [hashCode] ;
      gCollisionMap [hashCode] = nodeIndex ;
    }
  }
  if (C_BDD::displaysInformationMessages ()) {
    co << "BDD package info: mark and sweep done in " << timer
       << " (nodes " << cStringWithUnsigned (previousNodeCount) << " -> " << cStringWithUnsigned (gCurrentNodeCount) << ")\n" ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD constructors, destructor, assignment
#endif

//---------------------------------------------------------------------*

C_BDD::C_BDD (void) :
mBDDvalue (0),
mPtrToPreviousBDD (NULL),
mPtrToNextBDD (NULL) {
  initLinks () ;
}

//---------------------------------------------------------------------*

C_BDD::C_BDD (const PMUInt32 inValue) :
mBDDvalue (inValue),
mPtrToPreviousBDD (NULL),
mPtrToNextBDD (NULL) {
  initLinks () ;
}

//---------------------------------------------------------------------*

C_BDD::C_BDD (const PMUInt32 variable,
              const bool inSign) :
mBDDvalue (0),
mPtrToPreviousBDD (NULL),
mPtrToNextBDD (NULL) {
  initLinks () ;
  const PMUInt32 complement = inSign ? 0U : 1U ;
  mBDDvalue = find_or_add (variable, complement, complement ^ 1 COMMA_HERE) ;
}

//---------------------------------------------------------------------*

C_BDD::C_BDD (const C_BDD & inSource) :
mBDDvalue (inSource.mBDDvalue),
mPtrToPreviousBDD (NULL),
mPtrToNextBDD (NULL) {
  initLinks () ;
}

//---------------------------------------------------------------------------*

macroDeclareStaticMutex (semaphoreLink)

//---------------------------------------------------------------------*

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

//---------------------------------------------------------------------*

C_BDD::~C_BDD (void) {
  mBDDvalue = 0 ;
  macroMutexLock (semaphoreLink) ;
    C_BDD * suivant = mPtrToNextBDD ;
    C_BDD * precedent = mPtrToPreviousBDD ;
    precedent->mPtrToNextBDD = suivant ;
    suivant->mPtrToPreviousBDD = precedent ;
  macroMutexUnlock (semaphoreLink) ;
}

//---------------------------------------------------------------------*

C_BDD & C_BDD::operator = (const C_BDD & inSource) {
  mBDDvalue = inSource.mBDDvalue ;
  return *this ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Check all BDDs are well-formed
#endif

//---------------------------------------------------------------------------*

static void internalCheckBDDIsWellFormed (const PMUInt32 inBDD,
                                          const PMUInt32 inCurrentVar
                                          COMMA_LOCATION_ARGS) {
  const PMUInt32 nodeIndex = nodeIndexForRoot (inBDD COMMA_HERE) ;
  if (0 != gNodeArray [nodeIndex].bothBranches ()) {
    const PMUInt32 var = gNodeArray [nodeIndex].mVariableIndex ;
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

//---------------------------------------------------------------------------*

void C_BDD::checkAllBDDsAreWellFormed (LOCATION_ARGS) {
//--- Unmark all nodes
  unmarkAllExistingBDDnodes () ;
//--- Check BDDs
  C_BDD * p = gBDDinstancesListRoot.mPtrToNextBDD ;
  while (p != & gBDDinstancesListRoot) {
    internalCheckBDDIsWellFormed (p->mBDDvalue, PMUINT16_MAX COMMA_THERE) ;
    p = p->mPtrToNextBDD ;
  }
}

//---------------------------------------------------------------------------*

void C_BDD::checkBDDIsWellFormed (LOCATION_ARGS) {
//--- Unmark all nodes
  unmarkAllExistingBDDnodes () ;
//--- Check BDD
  internalCheckBDDIsWellFormed (mBDDvalue, PMUINT16_MAX COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Memory Usage
#endif

//---------------------------------------------------------------------------*

PMUInt32 C_BDD::currentMemoryUsage (void) {
  PMUInt32 result = nodeMapMemoryUsage () ;
  result += hashMapMemoryUsage () ;
  result += ANDCacheMemoryUsage () ;
  result += singleOperandOperationCacheMemoryUsage () ;
  return result ;
}

//---------------------------------------------------------------------------*

static PMUInt32 gMaximumMemoryUsage = PMUINT32_MAX ;

//---------------------------------------------------------------------------*

PMUInt32 C_BDD::maximumMemoryUsage (void) { // In MB
  return gMaximumMemoryUsage ;
}

//---------------------------------------------------------------------------*

void C_BDD::setMaximumMemoryUsage (const PMUInt32 inMaxMemoryUsage) { // In MB
  gMaximumMemoryUsage = inMaxMemoryUsage ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD Package stats
#endif

//---------------------------------------------------------------------*

void C_BDD::printBDDpackageOperationsSummary (AC_OutputStream & inStream) {
  #ifdef __LP64__
    const PMUInt32 mode = 64 ;
  #else
    const PMUInt32 mode = 32 ;
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
           << " (" << cStringWithUnsigned ((gCollisionMapSize * sizeof (PMUInt32)) / 1000000) << " MB)\n" ;
  TC_UniqueArray <PMUInt32> entrySizeArray (1 COMMA_HERE) ;
  for (PMUInt32 i=0 ; i<gCollisionMapSize ; i++) {
    PMSInt32 length = 0 ;
    PMUInt32 nodeIndex = gCollisionMap [i] ;
    while (0 != nodeIndex) {
      length ++ ;
      nodeIndex = gNodeArray [nodeIndex].mAuxiliary ;
    }
    if (entrySizeArray.count () > length) {
      entrySizeArray (length COMMA_HERE) ++ ;
    }else{
      entrySizeArray.forceObjectAtIndex (length, 1, 0 COMMA_HERE) ;
    }
  }  
  for (PMSInt32 i=0 ; i<entrySizeArray.count () ; i++) {
    if ((entrySizeArray (i COMMA_HERE) > 0) && (gCollisionMapSize > 0)) {
      inStream << "  " << cStringWithUnsigned (entrySizeArray (i COMMA_HERE))
               << " entries of size " << cStringWithSigned (i) 
               << " (" << cStringWithUnsigned ((100UL * entrySizeArray (i COMMA_HERE)) / gCollisionMapSize) << "%)\n" ;
    }
  }  
}

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------*

//---------------------------------------------------------------------------*
//                                                                           *
//     BDD package (implementation of ROBDD)                                 *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1999, ..., 2010 Pierre Molinaro.                           *
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
  return (sizeof (PMUInt64) + sizeof (PMUInt32)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  BDD objects unique table                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

static PMUInt32 gNodeArraySize = 0 ;
static PMUInt64 * gNodeArray = NULL ;
static PMUInt32 * gAuxiliaryArray = NULL ;
static PMUInt64 * gMarkTable = NULL ;
static PMUInt32 gCurrentNodeCount = 0 ;

//---------------------------------------------------------------------*

PMUInt32 nodeMapMemoryUsage (void) {
  return (gNodeArraySize * (PMUInt32) (sizeof (PMUInt32) + sizeof (PMUInt64))) / 1000000 ;
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
      const PMUInt64 hashCode = gNodeArray [nodeIndex] % (PMUInt64) gCollisionMapSize ;
      gAuxiliaryArray [nodeIndex] = gCollisionMap [hashCode] ;
      gCollisionMap [hashCode] = nodeIndex ;
    }
  }
}

//---------------------------------------------------------------------------*

static const PMUInt32 kUniqueMapSizeIncrement = 4194304 ;

//---------------------------------------------------------------------------*

static PMUInt32 addNewNode (const PMUInt64 inNode) {
  if (gNodeArraySize <= (gCurrentNodeCount + 1)) {
    const PMUInt32 newSize = gNodeArraySize + kUniqueMapSizeIncrement ;
    if (newSize > (1 << BDD_SPACE_BIT_COUNT)) {
      printf ("*** BDD package node map saturation: needs more than 1 ** %d nodes\n", BDD_SPACE_BIT_COUNT) ;
      exit (1) ;
    }else  if (C_BDD::displaysInformationMessages ()) {
      printf ("BDD package info: node map reallocated to %u %03u %03u (%u MB)\n",
              newSize / 1000000, (newSize / 1000) % 1000, newSize % 1000,
              (newSize * (PMUInt32) sizeof (PMUInt64)) / 1000000) ;
    }
    macroMyReallocPODArray (gNodeArray, PMUInt64, newSize) ;
    macroMyReallocPODArray (gAuxiliaryArray, PMUInt32, newSize) ;
    macroMyReallocPODArray (gMarkTable, PMUInt64, newSize >> 6) ;
    gNodeArraySize = newSize ;
    gNodeArray [0] = 0 ;
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
  const PMUInt64 hashCode = inNode % (PMUInt64) gCollisionMapSize ;
  gAuxiliaryArray [gCurrentNodeCount] = gCollisionMap [hashCode] ;
  gCollisionMap [hashCode] = gCurrentNodeCount ;
//---
  return gCurrentNodeCount ;
}

//---------------------------------------------------------------------------*

PMUInt64 nodeForRoot (const PMUInt32 inRoot
                      COMMA_LOCATION_ARGS) {
  const PMUInt32 nodeIndex = inRoot >> 1 ;
  MF_AssertThere (nodeIndex <= gCurrentNodeCount, "nodeIndex (%lld) should be <= gCurrentNodeCount (%lld)", nodeIndex, gCurrentNodeCount) ;
  const PMUInt64 result = gNodeArray [nodeIndex] ;
  return result ;
}

//------------------------------------------------------------------------*

void C_BDD::unmarkAllExistingBDDnodes (void) {
  MF_Assert ((gNodeArraySize % 64) == 0, "gNodeArraySize (%lld) is not a multiple of 64", gNodeArraySize, 0) ;
  for (PMUInt32 i=0 ; i<(gNodeArraySize >> 6) ; i++) {
    gMarkTable [i] = 0ULL ;
  }
}

//------------------------------------------------------------------------*

static bool isNodeMarked (const PMUInt32 inValue COMMA_LOCATION_ARGS) {
  const PMUInt32 nodeIndex = inValue >> 1 ;
  MF_AssertThere (nodeIndex > 0, "nodeIndex (%lld) should be > 0", nodeIndex, 0) ;
  MF_AssertThere (nodeIndex <= gCurrentNodeCount, "nodeIndex (%lld) should be <= gCurrentNodeCount (%lld)", nodeIndex, gCurrentNodeCount) ;
  const PMUInt64 mask = 1ULL << (nodeIndex & 0x3F) ;
  const PMUInt32 idx = nodeIndex >> 6 ;
  return (gMarkTable [idx] & mask) != 0 ;
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

PMUInt32 find_or_add (const PMUInt16 inBoolVar,
                      const PMUInt32 inELSEbranch,
                      const PMUInt32 inTHENbranch
                      COMMA_LOCATION_ARGS) {
  PMUInt32 result = inELSEbranch ;
  if (inELSEbranch != inTHENbranch) {
    macroMutexLock (semaphore) ;
      if (0 == gCollisionMapSize) {
        reallocHashMap (getPrimeGreaterThan (1U << kInitialCollisionMapPowerOfTwoSize)) ;
      }
      const PMUInt32 complement = inELSEbranch & 1 ;
      const PMUInt32 c1 = inTHENbranch ^ complement ;
      const PMUInt32 c0 = inELSEbranch ^ complement ;
      const PMUInt64 candidateNode = makeNode (inBoolVar, c1, c0 COMMA_THERE) ;
      // printf ("candidateNode %llu gCollisionMapSize %u\n", candidateNode, gCollisionMapSize) ;
      const PMUInt64 hashCode = candidateNode % (PMUInt64) gCollisionMapSize ;
      PMUInt32 nodeIndex = gCollisionMap [hashCode] ;
      while ((0 != nodeIndex) && (gNodeArray [nodeIndex] != candidateNode)) {
        nodeIndex = gAuxiliaryArray [nodeIndex] ;
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
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  if ((node != 0) && (! isNodeMarkedThenMark (inValue COMMA_HERE))) {
    recursiveMarkBDDNodes (extractThen (node)) ;
    recursiveMarkBDDNodes (extractElse (node)) ;
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
    gAuxiliaryArray [0] = 0 ;
    if (gMarkTable [0] == ~ 1LLU) {
      unchangedNodeCount = 63 ;
      for (PMUInt32 i=1 ; (i<(gNodeArraySize >> 6)) && (gMarkTable [i] == ~ 0LLU) ; i++) {
        unchangedNodeCount += 64 ;
      }
    }
  }
  // printf ("********************************************** %u nodes inchanges\n", unchangedNodeCount) ;
  for (PMUInt32 i=1 ; i<=unchangedNodeCount ; i++) {
    gAuxiliaryArray [i] = i ;
  }
  PMUInt32 newNodeCount = unchangedNodeCount ;
  for (PMUInt32 nodeIndex=unchangedNodeCount+1 ; nodeIndex<=gCurrentNodeCount ; nodeIndex++) {
    if (isNodeMarked (nodeIndex << 1 COMMA_HERE)) { // Node is used
      const PMUInt64 node = gNodeArray [nodeIndex] ;
      const PMUInt16 var = extractVar (node COMMA_HERE) ;
      const PMUInt32 thenBranch = extractThen (node) ;
      const PMUInt32 elseBranch = extractElse (node) ;
      MF_Assert ((thenBranch >> 1) < nodeIndex, "(thenBranch [%lld] >> 1) < nodeIndex [%lld]", (thenBranch >> 1), nodeIndex) ;
      MF_Assert ((elseBranch >> 1) < nodeIndex, "(elseBranch [%lld] >> 1) < nodeIndex [%lld]", (elseBranch >> 1), nodeIndex) ;
      const PMUInt32 newThenBranch = (gAuxiliaryArray [thenBranch >> 1] << 1) | (thenBranch & 1) ;
      const PMUInt32 newElseBranch = (gAuxiliaryArray [elseBranch >> 1] << 1) | (elseBranch & 1) ;
      const PMUInt64 newNode = makeNode (var, newThenBranch, newElseBranch COMMA_HERE) ;
      newNodeCount ++ ;
      gNodeArray [newNodeCount] = newNode ;
      gAuxiliaryArray [nodeIndex] = newNodeCount ;
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
    MF_Assert ((gAuxiliaryArray [previousValue >> 1]) <= (previousValue >> 1), "(elseBranch [%lld] >> 1) <= nodeIndex [%lld]", (gAuxiliaryArray [previousValue >> 1]), previousValue >> 1) ;
    p->mBDDvalue = (gAuxiliaryArray [previousValue >> 1] << 1) | (previousValue & 1) ;
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
      const PMUInt64 hashCode = gNodeArray [nodeIndex] % (PMUInt64) gCollisionMapSize ;
      gAuxiliaryArray [nodeIndex] = gCollisionMap [hashCode] ;
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

C_BDD::C_BDD (const PMUInt16 variable,
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

//---------------------------------------------------------------------*

void C_BDD::initLinks (void) {
  mPtrToPreviousBDD = this ;
  mPtrToNextBDD = this ;
  C_BDD * suivantRacine = gBDDinstancesListRoot.mPtrToNextBDD ;
  mPtrToPreviousBDD = & gBDDinstancesListRoot ;
  suivantRacine->mPtrToPreviousBDD = this ;
  mPtrToNextBDD = suivantRacine ;
  gBDDinstancesListRoot.mPtrToNextBDD = this ;
}

//---------------------------------------------------------------------*

C_BDD::~C_BDD (void) {
  mBDDvalue = 0 ;
  C_BDD * suivant = mPtrToNextBDD ;
  C_BDD * precedent = mPtrToPreviousBDD ;
  precedent->mPtrToNextBDD = suivant ;
  suivant->mPtrToPreviousBDD = precedent ;
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
                                          const PMUInt16 inCurrentVar
                                          COMMA_LOCATION_ARGS) {
  const PMUInt64 node = nodeForRoot (inBDD COMMA_HERE) ;
  if (0 != node) {
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    if (var >= inCurrentVar) {
     #ifndef DO_NOT_GENERATE_CHECKINGS
        printf ("*** ERROR at %s:%d: BDD is not well-formed (var %hu sould be < var %hu) ***\n", IN_SOURCE_FILE, IN_SOURCE_LINE, var, inCurrentVar) ;
      #else
        printf ("*** ERROR (compile in debug mode for locating the error): BDD is not well-formed (var %hu sould be < var %hu) ***\n", var, inCurrentVar) ;
      #endif
      exit (1) ;
    }
    if (! isNodeMarkedThenMark (inBDD COMMA_HERE)) {
      internalCheckBDDIsWellFormed (extractThen (inBDD), var COMMA_THERE) ;
      internalCheckBDDIsWellFormed (extractElse (inBDD), var COMMA_THERE) ;
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
      nodeIndex = gAuxiliaryArray [nodeIndex] ;
    }
    if (entrySizeArray.count () > length) {
      entrySizeArray (length COMMA_HERE) ++ ;
    }else{
      entrySizeArray.forceObjectAtIndex (length, 1, 0 COMMA_HERE) ;
    }
  }  
  for (PMSInt32 i=0 ; i<entrySizeArray.count () ; i++) {
    if (entrySizeArray (i COMMA_HERE) > 0) {
      inStream << "  " << cStringWithUnsigned (entrySizeArray (i COMMA_HERE))
               << " entries of size " << cStringWithSigned (i) 
               << " (" << cStringWithUnsigned ((100UL * entrySizeArray (i COMMA_HERE)) / gCollisionMapSize) << "%)\n" ;
    }
  }  
//---
//  gAndOperationCache.printStatistics (inStream, "AND") ;
//  gForAllOperationCache.printStatistics (inStream, "FOR ALL") ;
//  gITEoperationCache.printStatistics (inStream, "ITE") ;
}

//---------------------------------------------------------------------------*

void C_BDD::freeBDDStataStructures (void) {
  releaseANDOperationCache () ;
  releaseSingleOperandOperationCache () ;
  C_BDD::markAndSweepUnusedNodes () ;
  if (0 == gCurrentNodeCount) {
    macroMyDeletePODArray (gCollisionMap) ;
    macroMyDeletePODArray (gAuxiliaryArray) ;
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

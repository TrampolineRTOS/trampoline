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

#ifndef BDD_NODE_DEFINED
#define BDD_NODE_DEFINED

//---------------------------------------------------------------------------*

#include "bdd/C_BDD.h"

//---------------------------------------------------------------------*
//                                                                     *
//            Declaration de la classe 'cBDDnode'                      *
//               definissant un element d'un BDD                       *
//                                                                     *
//---------------------------------------------------------------------*

#define BDD_SPACE_BIT_COUNT (27)

//---------------------------------------------------------------------*

// static PMUInt64 nodeForRoot (const PMUInt32 inRoot COMMA_LOCATION_ARGS) ;

static inline PMUInt64 makeNode (const PMUInt16 inBoolVar,
                                 const PMUInt32 inTHENbranch,
                                 const PMUInt32 inELSEbranch
                                 COMMA_LOCATION_ARGS) {
  MF_AssertThere (inBoolVar < (1 << (64 - (BDD_SPACE_BIT_COUNT + BDD_SPACE_BIT_COUNT + 1))), "inBoolVar (%lld) >= 1<<%lld", inBoolVar, 64 - (BDD_SPACE_BIT_COUNT + BDD_SPACE_BIT_COUNT + 1)) ;
  MF_AssertThere (inTHENbranch < (1U << (BDD_SPACE_BIT_COUNT + 1)), "inTHENbranch (0x%llx) >= 1<<%lld", inTHENbranch, BDD_SPACE_BIT_COUNT + 1) ;
  /* if ((inTHENbranch >> 1) >> 0) {
      nodeForRoot (inTHENbranch COMMA_HERE) ;
    }
   */
  MF_AssertThere (inELSEbranch < (1U << (BDD_SPACE_BIT_COUNT + 1)), "inELSEbranch (0x%llx) >= 1<<%lld", inELSEbranch, BDD_SPACE_BIT_COUNT + 1) ;
  MF_AssertThere ((inELSEbranch & 1) == 0, "inELSEbranch (0x%llx) is odd", inELSEbranch, 0) ;
  /* if ((inELSEbranch >> 1) >> 0) {
      nodeForRoot (inELSEbranch COMMA_HERE) ;
    } */
  MF_AssertThere (inBoolVar < 256, "inBoolVar (0x%llx) < 256", inBoolVar, 0) ;
  PMUInt64 node = inBoolVar ;
  node <<= (BDD_SPACE_BIT_COUNT + 1) ;
  node |= inTHENbranch ;
  node <<= BDD_SPACE_BIT_COUNT ;
  node |= (inELSEbranch >> 1) ;
  return node ;
}

//---------------------------------------------------------------------------*

static inline PMUInt16 extractVar (const PMUInt64 inNode COMMA_UNUSED_LOCATION_ARGS) {
  const PMUInt64 v = inNode >> (BDD_SPACE_BIT_COUNT + BDD_SPACE_BIT_COUNT + 1) ;
  return (PMUInt16) (v & PMUINT16_MAX) ;
}

//---------------------------------------------------------------------------*

static inline PMUInt32 extractThen (const PMUInt64 inNode) {
  const PMUInt64 v = (inNode >> BDD_SPACE_BIT_COUNT) & ((1 << (BDD_SPACE_BIT_COUNT + 1)) - 1) ;
//  MF_Assert ((v >> 1) < gUniqueTableSize, "v (%lld) should be < gUniqueTableSize (%lld)", v >> 1, gUniqueTableSize) ;
  return (PMUInt32) (v & PMUINT32_MAX) ;
}

//---------------------------------------------------------------------------*

static inline PMUInt32 extractElse (const PMUInt64 inNode) {
  PMUInt64 v = inNode & ((1 << BDD_SPACE_BIT_COUNT) - 1) ;
//  MF_Assert (v < gUniqueTableSize, "v (%lld) should be < gUniqueTableSize (%lld)", v, gUniqueTableSize) ;
  v <<= 1 ;
  return (PMUInt32) (v & PMUINT32_MAX) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  BDD objects unique table                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

PMUInt64 nodeForRoot (const PMUInt32 inRoot
                      COMMA_LOCATION_ARGS) ;

bool isNodeMarkedThenMark (const PMUInt32 inValue COMMA_LOCATION_ARGS) ;

void markNode (const PMUInt32 inValue) ;

//---------------------------------------------------------------------------*

PMUInt32 find_or_add (const PMUInt16 inBoolVar,
                      const PMUInt32 inELSEbranch,
                      const PMUInt32 inTHENbranch
                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------*
//                                                                     *
//                        Operation AND                                *
//                                                                     *
//---------------------------------------------------------------------*

PMUInt32 internalANDoperation (const PMUInt32 opf,
                               const PMUInt32 opg) ;

PMUInt32 internalITEoperation (const PMUInt32 opf, 
                               const PMUInt32 opg,
                               const PMUInt32 oph) ;

void clearANDOperationCache (void) ;

void releaseANDOperationCache (void) ;

void releaseSingleOperandOperationCache (void) ;

//---------------------------------------------------------------------*
//                                                                     *
//                        Memory Usage                                 *
//                                                                     *
//---------------------------------------------------------------------*

PMUInt32 ANDCacheMemoryUsage (void) ;

PMUInt32 singleOperandOperationCacheMemoryUsage (void) ;

PMUInt32 nodeMapMemoryUsage (void) ;

PMUInt32 hashMapMemoryUsage (void) ;

//---------------------------------------------------------------------*

#endif

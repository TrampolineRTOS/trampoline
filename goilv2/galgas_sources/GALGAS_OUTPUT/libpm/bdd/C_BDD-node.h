//-----------------------------------------------------------------------------*
//                                                                             *
//     BDD package (implementation of ROBDD)                                 *
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

#ifndef BDD_NODE_DEFINED
#define BDD_NODE_DEFINED

//-----------------------------------------------------------------------------*

#include "bdd/C_BDD.h"

//---------------------------------------------------------------------*
//                                                                     *
//            Declaration de la classe 'cBDDnode'                      *
//               definissant un element d'un BDD                       *
//                                                                     *
///---------------------------------------------------------------------*

class cBDDnode {
  public : inline cBDDnode (const PMUInt32 inTHENbranch,
                            const PMUInt32 inELSEbranch,
                            const PMUInt32 inVariableIndex) :
  mTHEN (inTHENbranch),
  mELSE (inELSEbranch),
  mVariableIndex (inVariableIndex),
  mAuxiliary (0) {
  }
  
  public : inline PMUInt64 bothBranches (void) const {
    PMUInt64 result = mTHEN ;
    result <<= 32 ;
    result |= mELSE ;
    return result ;
  }
  public : PMUInt32 mTHEN ;
  public : PMUInt32 mELSE ;
  public : PMUInt32 mVariableIndex ;
  public : PMUInt32 mAuxiliary ;
} ;

//-----------------------------------------------------------------------------*
//                                                                             *
//  Utilities                                                                *
//                                                                             *
//-----------------------------------------------------------------------------*

extern cBDDnode * gNodeArray ;

inline PMUInt32 nodeIndexForRoot (const PMUInt32 inRoot
                                  COMMA_LOCATION_ARGS) {
  MF_AssertThere ((inRoot >> 1) <= C_BDD::getExistingNodesCount (), "nodeIndex (%lld) should be <= current node count (%lld)", inRoot >> 1, C_BDD::getExistingNodesCount ()) ;
  return inRoot >> 1 ;
}

bool isNodeMarkedThenMark (const PMUInt32 inValue COMMA_LOCATION_ARGS) ;

void markNode (const PMUInt32 inValue) ;

//-----------------------------------------------------------------------------*

PMUInt32 find_or_add (const PMUInt32 inBoolVar,
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

//----------------------------------------------------------------------------------------------------------------------
//
//     BDD package (implementation of ROBDD)                                                     
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1999, ..., 2014 Pierre Molinaro.
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

#include "bdd/C_BDD.h"

//----------------------------------------------------------------------------------------------------------------------

typedef struct {
  uint32_t mTHEN ;
  uint32_t mELSE ;
  uint32_t mVariableIndex ;
  uint32_t mAuxiliary ;
} cBDDnode ;

//----------------------------------------------------------------------------------------------------------------------
//
//  Utilities                                                                                    
//
//----------------------------------------------------------------------------------------------------------------------

inline uint64_t bothBranches (const cBDDnode & inNode) {
  uint64_t result = inNode.mTHEN ;
  result <<= 32 ;
  result |= inNode.mELSE ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

extern cBDDnode * gNodeArray ;

inline uint32_t nodeIndexForRoot (const uint32_t inRoot
                                  COMMA_LOCATION_ARGS) {
  MF_AssertThere ((inRoot >> 1) <= C_BDD::getExistingNodesCount (), "nodeIndex (%lld) should be <= current node count (%lld)", inRoot >> 1, C_BDD::getExistingNodesCount ()) ;
  return inRoot >> 1 ;
}

//----------------------------------------------------------------------------------------------------------------------

bool isNodeMarkedThenMark (const uint32_t inValue COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void markNode (const uint32_t inValue) ;

//----------------------------------------------------------------------------------------------------------------------

uint32_t find_or_add (const uint32_t inBoolVar,
                      const uint32_t inELSEbranch,
                      const uint32_t inTHENbranch
                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//                        Operation AND                                                          
//
//----------------------------------------------------------------------------------------------------------------------

uint32_t internalANDoperation (const uint32_t opf,
                               const uint32_t opg) ;

uint32_t internalITEoperation (const uint32_t opf, 
                               const uint32_t opg,
                               const uint32_t oph) ;

void clearANDOperationCache (void) ;

void releaseANDOperationCache (void) ;

void releaseSingleOperandOperationCache (void) ;

//----------------------------------------------------------------------------------------------------------------------
//
//                        Memory Usage                                                           
//
//----------------------------------------------------------------------------------------------------------------------

uint32_t ANDCacheMemoryUsage (void) ;

uint32_t singleOperandOperationCacheMemoryUsage (void) ;

uint32_t nodeMapMemoryUsage (void) ;

uint32_t hashMapMemoryUsage (void) ;

//----------------------------------------------------------------------------------------------------------------------

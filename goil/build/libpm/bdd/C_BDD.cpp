//--------------------------------------------------------------------------------------------------
//
//     BDD package (implementation of ROBDD)
//
//  This file is part of libpm library
//
//  Copyright (C) 1999, ..., 2023 Pierre Molinaro.
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
//--------------------------------------------------------------------------------------------------

#include "C_BDD.h"
#include "C_BDD-node.h"
#include "F_GetPrime.h"
#include "Timer.h"

//--------------------------------------------------------------------------------------------------
//
//  BDD objects unique table
//
//--------------------------------------------------------------------------------------------------

static uint32_t gNodeArraySize = 0 ;
cBDDnode * gNodeArray = nullptr ;
static uint64_t * gMarkTable = nullptr ;
static uint32_t gCurrentNodeCount = 0 ;

//--------------------------------------------------------------------------------------------------

uint32_t nodeMapMemoryUsage (void) {
  return (gNodeArraySize * C_BDD::getBDDnodeSize ()) / 1000000 ;
}

//--------------------------------------------------------------------------------------------------

uint32_t C_BDD::getCreatedNodesCount (void) {
  return gNodeArraySize ;
}

//--------------------------------------------------------------------------------------------------

uint32_t C_BDD::getExistingNodesCount (void) {
  return gCurrentNodeCount ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Display Information Messages
#endif

//--------------------------------------------------------------------------------------------------

static bool gDisplaysInformationMessages ;

//--------------------------------------------------------------------------------------------------

bool C_BDD::displaysInformationMessages (void) {
  return gDisplaysInformationMessages ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::setDisplaysInformationMessages (const bool inFlag) {
  gDisplaysInformationMessages = inFlag ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ITE operation
#endif

//--------------------------------------------------------------------------------------------------

uint32_t internalITEoperation (const uint32_t opf,
                               const uint32_t opg,
                               const uint32_t oph) {
  return internalANDoperation (internalANDoperation (opf, opg)     ^ 1,
                               internalANDoperation (opf ^ 1, oph) ^ 1) ^ 1 ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Compare BDDs
#endif

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::compareWithBDD (const compareEnum inComparison, const C_BDD & inOperand) const {
  C_BDD result ;
  switch (inComparison) {
  case kEqual :
    result = equalTo (inOperand) ;
    break ;
  case kNotEqual :
    result = notEqualTo (inOperand) ;
    break ;
  case kLowerOrEqual :
    result = lowerOrEqual (inOperand) ;
    break ;
  case kStrictLower :
    result = lowerThan (inOperand) ;
    break ;
  case kGreaterOrEqual :
    result = greaterOrEqual (inOperand) ;
    break ;
  case kStrictGreater :
    result = greaterThan (inOperand) ;
    break ;
  default :
    ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Complement BDD
#endif

//--------------------------------------------------------------------------------------------------

void C_BDD::negate (void) {
  mBDDvalue ^= 1 ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::operator ~ (void) const {
  return C_BDD (mBDDvalue ^ 1) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD is complemented
#endif

//--------------------------------------------------------------------------------------------------

bool C_BDD::isComplemented (void) const {
  return (mBDDvalue & 1) != 0 ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD with constants
#endif

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::bddWithConstants (const uint32_t * inValues,
                               const uint32_t * inBitCount,
                               const int32_t inEntryCount) {
  uint32_t result = 1 ; // true
  uint32_t idx = 0 ;
  for (int32_t i=0 ; i<inEntryCount ; i++) {
    uint32_t v = inValues [i] ;
    for (uint32_t j=0 ; j<inBitCount [i] ; j++) {
      if ((v & 1) == 0) {
        result = find_or_add (idx, result, 0 COMMA_HERE) ;
      }else{
        result = find_or_add (idx, 0, result COMMA_HERE) ;
      }
      v >>= 1 ;
      idx ++ ;
    }
  }
  return C_BDD (result) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build BDD from comparison between variables and constant
#endif

//--------------------------------------------------------------------------------------------------

static C_BDD construireInfEgal (const uint32_t inFirstIndex,
                                const uint32_t indiceMax,
                                const uint64_t inValue) {
  C_BDD result ;
  if (inFirstIndex < indiceMax) {
    if (((1 << (indiceMax - inFirstIndex)) & inValue) != 0) {
      result = C_BDD (indiceMax, false) | (C_BDD (indiceMax, true) & construireInfEgal (inFirstIndex, (uint32_t) (indiceMax - 1), inValue)) ;
    }else{
      result = C_BDD (indiceMax, false) & construireInfEgal (inFirstIndex, (uint32_t) (indiceMax - 1), inValue) ;
    }
  }else{
    result = ((inValue & 1) != 0) ? (~C_BDD ()) : C_BDD (indiceMax, false) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

static C_BDD construireSupEgal (const uint32_t inFirstIndex,
                                const uint32_t indiceMax,
                                const uint64_t inValue) {
  C_BDD result ;
  if (inFirstIndex < indiceMax) {
    if (((1 << (indiceMax - inFirstIndex)) & inValue) == 0) {
      result = C_BDD (indiceMax, true) | (C_BDD (indiceMax, false) & construireSupEgal (inFirstIndex, (uint32_t) (indiceMax - 1), inValue)) ;
    }else{
      result = C_BDD (indiceMax, true) & construireSupEgal (inFirstIndex, (uint32_t) (indiceMax - 1), inValue) ;
    }
  }else{
    result = ((inValue & 1) == 0) ? (~C_BDD ()) : C_BDD (indiceMax, true) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::varCompareConst (const uint32_t inFirstIndex,
                              const uint32_t inDimension,
                              const compareEnum inComparison,
                              const uint64_t inComparisonConstant) {
  if (inDimension == 0) {
    printf ("*** BDD Error in %s:%d: inDimension should be > 0 ***\n", __FILE__, __LINE__) ;
    exit (1) ;
  }
  C_BDD result ;
  uint64_t val = inComparisonConstant ;
  const uint32_t indiceMax = (uint32_t) (inFirstIndex + inDimension - 1) ;
  switch (inComparison) {
  case kEqual : case kNotEqual : // on construit l'egalite
    result.mBDDvalue = 1 ;
    for (uint32_t i = inFirstIndex ; i <= indiceMax ; i++) {
      result = result & C_BDD (i, ((val & 1) == 0) ? false : true) ;
      val >>= 1 ;
    }
    break ;
  case kLowerOrEqual : case kStrictGreater : // on construit l'inf ou egal
    result = construireInfEgal (inFirstIndex, indiceMax, inComparisonConstant) ;
    break ;
  case kGreaterOrEqual : case kStrictLower : // on construit le sup ou egal
    result = construireSupEgal (inFirstIndex, indiceMax, inComparisonConstant) ;
    break ;
  default :
    ;
  }
  switch (inComparison) {
  case kNotEqual : case kStrictGreater : case kStrictLower :
    result.mBDDvalue ^= 1 ;
    break ;
  default :
    ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build BDD from comparison between variables
#endif

//--------------------------------------------------------------------------------------------------

static C_BDD construireSupVariable (const uint32_t inLeftFirstIndex,
                                    const uint32_t inDimension,
                                    const uint32_t inRightFirstIndex) {
  C_BDD result ;
  const C_BDD gauche = C_BDD ((uint32_t) (inLeftFirstIndex + inDimension - 1), true) ;
  const C_BDD droite = C_BDD ((uint32_t) (inRightFirstIndex + inDimension - 1), true) ;
  if (inDimension > 1) {
    result = (gauche.greaterThan (droite)) |
      ((gauche.equalTo (droite)) &
      construireSupVariable (inLeftFirstIndex, (uint32_t) (inDimension - 1), inRightFirstIndex)) ;
  }else{
    result = gauche.greaterThan (droite) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::
varCompareVar (const uint32_t inLeftFirstIndex,
               const uint32_t inDimension,
               const compareEnum inComparison,
               const uint32_t inRightFirstIndex) {
  C_BDD result ;
  switch (inComparison) {
  case kEqual : case kNotEqual :
    result = ~ result ;
    for (uint32_t i=0 ; i<inDimension ; i++) {
      result &= C_BDD ((uint32_t) (inLeftFirstIndex + i), false).equalTo (C_BDD ((uint32_t) (inRightFirstIndex + i), false)) ;
    }
    break ;
  case kStrictLower : case kGreaterOrEqual :
    result = construireSupVariable (inRightFirstIndex, inDimension, inLeftFirstIndex) ;
    break ;
  case kStrictGreater : case kLowerOrEqual :
    result = construireSupVariable (inLeftFirstIndex, inDimension, inRightFirstIndex) ;
    break ;
  default :
    ;
  }
  switch (inComparison) {
  case kNotEqual : case kGreaterOrEqual : case kLowerOrEqual :
    result.mBDDvalue ^= 1 ;
    break ;
  default :
    ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Needed Variable Count
#endif

//--------------------------------------------------------------------------------------------------

uint32_t C_BDD::significantVariableCount (void) const {
  uint32_t bitCount = 0 ;
  const uint32_t nodeIndex = nodeIndexForRoot (mBDDvalue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    bitCount = gNodeArray [nodeIndex].mVariableIndex + 1 ;
  }
  return bitCount ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Test if BDD does contain a value
#endif

//--------------------------------------------------------------------------------------------------

static bool recursiveContainsValue64 (const uint32_t inBDD,
                                      const uint64_t inValue,
                                      const uint32_t inFirstBit,
                                      const uint32_t inLastBitPlusOne) {
  bool result ;
  const uint32_t nodeIndex = nodeIndexForRoot (inBDD COMMA_HERE) ;
  const uint32_t complement = inBDD & 1 ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    result = complement != 0 ;
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    if (var >= inLastBitPlusOne) {
      result = recursiveContainsValue64 (gNodeArray [nodeIndex].mTHEN ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      if (! result) {
        result = recursiveContainsValue64 (gNodeArray [nodeIndex].mELSE ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      }
    }else if (var < inFirstBit) {
      result = true ;
    }else{
      const bool bitValue = ((inValue >> (var - inFirstBit)) & 1) != 0 ;
      if (bitValue) {
        result = recursiveContainsValue64 (gNodeArray [nodeIndex].mTHEN ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      }else{
        result = recursiveContainsValue64 (gNodeArray [nodeIndex].mELSE ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      }
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool C_BDD::containsValue64 (const uint64_t inValue,
                             const uint32_t inFirstBit,
                             const uint32_t inBitCount) const {
  return recursiveContainsValue64 (mBDDvalue,
                                   inValue,
                                   inFirstBit,
                                   (uint32_t) (inFirstBit + inBitCount)) ;
}

//--------------------------------------------------------------------------------------------------

static bool recursiveContainsValue (const uint32_t inBDD,
                                    const TC_Array <bool> & inValue,
                                    const uint32_t inFirstBit,
                                    const uint32_t inLastBitPlusOne) {
  bool result ;
  const uint32_t nodeIndex = nodeIndexForRoot (inBDD COMMA_HERE) ;
  const uint32_t complement = inBDD & 1 ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    result = complement != 0 ;
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    if (var >= inLastBitPlusOne) {
      result = recursiveContainsValue (gNodeArray [nodeIndex].mTHEN ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      if (! result) {
        result = recursiveContainsValue (gNodeArray [nodeIndex].mELSE ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      }
    }else if (var < inFirstBit) {
      result = true ;
    }else{
      const bool bitValue = inValue ((int32_t) (var - inFirstBit) COMMA_HERE) ;
      if (bitValue) {
        result = recursiveContainsValue (gNodeArray [nodeIndex].mTHEN ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      }else{
        result = recursiveContainsValue (gNodeArray [nodeIndex].mELSE ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      }
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool C_BDD::containsValue (const TC_Array <bool> & inValue,
                           const uint32_t inFirstBit,
                           const uint32_t inBitCount) const {
  return recursiveContainsValue (mBDDvalue,
                                 inValue,
                                 inFirstBit,
                                 (uint32_t) (inFirstBit + inBitCount)) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Value Count
#endif

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::BDDWithPredicateString (const String & inPredicateStringValue
                                     COMMA_LOCATION_ARGS) {
  C_BDD result ;
  const int32_t stringLength = inPredicateStringValue.length () ;
  int32_t stringIndex = 0 ;
  bool ok = true ;
  while ((stringIndex < stringLength) && ok) {
    utf32 cc = inPredicateStringValue.charAtIndex (stringIndex COMMA_HERE) ;
    String s ;
    while ((stringIndex < stringLength) && ((UNICODE_VALUE (cc) == '0') || (UNICODE_VALUE (cc) == '1') || (UNICODE_VALUE (cc) == 'X') || (UNICODE_VALUE (cc) == ' '))) {
      s.appendChar (cc) ;
      stringIndex += 1 ;
      if (stringIndex < stringLength) {
        cc = inPredicateStringValue.charAtIndex (stringIndex COMMA_HERE) ;
      }
    }
    if (s.length () > 0) {
      C_BDD v ; v.setToTrue () ;
      int32_t bitIndex = 0 ;
      for (int32_t i=s.length () - 1 ; i>=0 ; i--) {
        const utf32 c = s.charAtIndex (i COMMA_HERE) ;
        if (UNICODE_VALUE (c) == '0') {
          v &= C_BDD ((uint32_t) (((uint32_t) bitIndex) & UINT16_MAX), false) ;
          bitIndex ++ ;
        }else if (UNICODE_VALUE (c) == '1') {
          v &= C_BDD ((uint32_t) (((uint32_t) bitIndex) & UINT16_MAX), true) ;
          bitIndex ++ ;
        }else if (UNICODE_VALUE (c) == 'X') {
          bitIndex ++ ;
        }
      }
      result |= v ;
    }
    if (stringIndex < stringLength) {
      ok = UNICODE_VALUE (cc) == '|' ;
      macroAssertThere (ok, "BDD predicate string syntax error at character index %lld", stringIndex, 0) ;
      stringIndex ++ ;
    }
  }
  if (! ok) {
    result = C_BDD () ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Get i-th value as uint64_t
#endif

//--------------------------------------------------------------------------------------------------

static uint64_t obtenirValeurAbsolueBDDInterne (const uint32_t inValue) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  const uint32_t complement = inValue & 1 ;
  uint64_t result = 1 ^ complement ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    if ((gNodeArray [nodeIndex].mELSE ^ complement) != 0) {
      result = obtenirValeurAbsolueBDDInterne (gNodeArray [nodeIndex].mELSE ^ complement) ;
    }else{
      result = 1 ;
      for (uint32_t i = 1 ; i <= gNodeArray [nodeIndex].mVariableIndex ; i++) {
        result <<= 1 ;
      }
      result += obtenirValeurAbsolueBDDInterne (gNodeArray [nodeIndex].mTHEN ^ complement) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

uint64_t C_BDD::getBDDabsoluteValue (const uint32_t inVariableCount) const {
  uint64_t result = 0 ;
  if (valueCount64 (inVariableCount) == 1) {
    result = obtenirValeurAbsolueBDDInterne (mBDDvalue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Node Count
#endif

//--------------------------------------------------------------------------------------------------

static uint32_t internalRecursiveNodeCount (const uint32_t inValue) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  uint32_t n = 0 ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    if (! isNodeMarkedThenMark (inValue COMMA_HERE)) {
      n = 1 ;
      n += internalRecursiveNodeCount (gNodeArray [nodeIndex].mELSE) ;
      n += internalRecursiveNodeCount (gNodeArray [nodeIndex].mTHEN) ;
    }
  }
  return n ;
}

//--------------------------------------------------------------------------------------------------

uint32_t C_BDD::getBDDnodesCount (void) const {
  const uint32_t nodeIndex = nodeIndexForRoot (mBDDvalue COMMA_HERE) ;
  uint32_t result = 0 ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    unmarkAllExistingBDDnodes () ;
    result = internalRecursiveNodeCount (mBDDvalue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Boolean array
#endif

//--------------------------------------------------------------------------------------------------

class cBuildArrayForSet : public C_bdd_value_traversing {
//--- Attributs
  protected: TC_UniqueArray <bool> & mArray ;

//--- Constructeur
  public: cBuildArrayForSet (TC_UniqueArray <bool> & outArray) ;

//--- Methode virtuelle appelee pour chaque valeur
  public: virtual void action (const bool * inValuesArray,
                               const uint32_t inBDDbitsSize) ;
} ;

//--------------------------------------------------------------------------------------------------

cBuildArrayForSet::cBuildArrayForSet (TC_UniqueArray <bool> & outArray) :
mArray (outArray) {
}

//--------------------------------------------------------------------------------------------------

void cBuildArrayForSet::action (const bool * inValuesArray,
                                const uint32_t inBDDbitsSize) {
  int32_t element = 0 ;
  for (int32_t i=((int32_t) inBDDbitsSize) - 1 ; i>=0 ; i--) {
    element = (element << 1) + inValuesArray [i] ;
  }
  mArray.setObjectAtIndex (true, element COMMA_HERE) ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::getBoolArray (TC_UniqueArray <bool> & outArray,
                          const uint32_t inMaxValues,
                          const uint32_t inBitSize) const {
  outArray.removeAllKeepingCapacity () ;
  outArray.setCapacity ((int32_t) inMaxValues) ;
  outArray.appendObjects ((int32_t) inMaxValues, false) ;
  cBuildArrayForSet s (outArray) ;
  traverseBDDvalues (s, inBitSize) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD as N-relation
#endif

//--------------------------------------------------------------------------------------------------
//
//   U P D A T E   R E L A T I O N
//
//--------------------------------------------------------------------------------------------------

static uint32_t internalRecursiveUpdateRelation (const uint32_t inValue,
                                                 const uint32_t * inTranslationVector) {
  uint32_t result = inValue ;
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    if (inTranslationVector [var] != var) {
      const uint32_t complement = inValue & 1 ;
      result = internalITEoperation (
        find_or_add (inTranslationVector [var], 1, 0 COMMA_HERE),
        internalRecursiveUpdateRelation (gNodeArray [nodeIndex].mELSE ^ complement, inTranslationVector),
        internalRecursiveUpdateRelation (gNodeArray [nodeIndex].mTHEN ^ complement, inTranslationVector)
      ) ;
      uint32_t preceeding = (uint32_t) (inTranslationVector [var - 1] + 1) ;
      while (preceeding < inTranslationVector [var]) {
        result = internalITEoperation (find_or_add (preceeding, 1, 0 COMMA_HERE), result, 0) ;
        preceeding ++ ;
      }
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::updateRelation (const uint32_t * inRelationBitNeededCount,
                             uint32_t* * inRelationBitCurrentCount,
                             const int32_t inRelationCardinality) const {
  uint32_t result = mBDDvalue ;
//--- Check if update is needed
  bool updateIsNeeded = false ;
  for (int32_t i=0 ; (i<inRelationCardinality) && ! updateIsNeeded ; i++) {
    updateIsNeeded = inRelationBitNeededCount [i] > * (inRelationBitCurrentCount [i]) ;
  }
//--- Perform updating
  if (updateIsNeeded) {
    uint32_t totalCurrentBitCount = 0 ;
    uint32_t newNeededTotalBitCount = 0 ;
    for (int32_t i=0 ; i<inRelationCardinality ; i++) {
      totalCurrentBitCount = (uint32_t) (totalCurrentBitCount + * (inRelationBitCurrentCount [i])) ;
      newNeededTotalBitCount = (uint32_t) (newNeededTotalBitCount + inRelationBitNeededCount [i]) ;
    }
    uint32_t * translationVector = nullptr ;
    macroMyNewArray (translationVector, uint32_t, totalCurrentBitCount) ;
    int32_t idx = 0 ;
    int32_t newIdx = 0 ;
    for (int32_t i=0 ; i<inRelationCardinality ; i++) {
      for (uint32_t j=0 ; j<* (inRelationBitCurrentCount [i]) ; j++) {
        translationVector [idx] = (uint32_t) ((((uint32_t) newIdx) + j) & UINT16_MAX) ;
        idx ++ ;
      }
      newIdx += inRelationBitNeededCount [i] ;
    }
    printf ("[") ;
    for (uint32_t i=0 ; i<totalCurrentBitCount ; i++) {
      printf (" %u", translationVector [i]) ;
    }
    printf ("] %u\n", newNeededTotalBitCount) ;
    result = internalRecursiveUpdateRelation (mBDDvalue, translationVector) ;
    uint32_t  finalTranslatedIndex = (uint32_t) (newNeededTotalBitCount
      + (* (inRelationBitCurrentCount [inRelationCardinality - 1]))
      - inRelationBitNeededCount [inRelationCardinality - 1]) ;
    while (finalTranslatedIndex < newNeededTotalBitCount) {
      result = find_or_add (finalTranslatedIndex, result, 0 COMMA_HERE) ;
      finalTranslatedIndex ++ ;
    }
    macroMyDeleteArray (translationVector) ;
  }
//--- Register updating
  if (updateIsNeeded) {
    for (int32_t i=0 ; i<inRelationCardinality; i++) {
      * (inRelationBitCurrentCount [i]) = inRelationBitNeededCount [i] ;
    }
  }
//---
  return C_BDD (result) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD as 2-relation
#endif

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::
swap10 (const uint32_t inBitSize1,
        const uint32_t inBitSize2) const {
  const uint32_t totalSize = (uint32_t) (inBitSize1 + inBitSize2) ;
  uint32_t * tab = nullptr ;
  macroMyNewArray (tab, uint32_t, totalSize) ;
  for (uint32_t i=0 ; i<inBitSize1 ; i++) {
    tab [i] = (uint32_t) (i + inBitSize2) ;
  }
  for (uint32_t j=0 ; j<inBitSize2 ; j++) {
    tab [j + inBitSize1] = j ;
  }
  const C_BDD result = substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::
accessibleStates (const C_BDD & inInitialStateSet,
                  const uint32_t inBitSize,
                  int32_t * outIterationCount) const {
//--- Current object is edge [x, y].
//    Accessible states set is computed by:
// accessible [x] += initial [x] | exists y (accessible [y] & edge [y, x]) ;
//
//--- Compute edge [y, x]
  const C_BDD edgeYX = swap10 (inBitSize, inBitSize) ;
  C_BDD accessible = inInitialStateSet ;
  C_BDD v ;
  C_BDD accessibleY ;
  int32_t iterationCount = 0 ;
  do{
    v = accessible ;
    iterationCount ++ ;
    accessibleY = accessible.translate (inBitSize, inBitSize) ;
    accessible |= (accessibleY & edgeYX).existsOnBitsAfterNumber (inBitSize) ;
  }while (v != accessible) ;
  if (outIterationCount != nullptr) {
    * outIterationCount = iterationCount ;
  }
  return accessible ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::
transitiveClosure (const uint32_t inBitSize,
                   int32_t * outIterationCount) const {
//--- Transitive closure is computed by:
// closure [x, y] += relation [x, y] | exists z (closure [x, z] & closure [z, y]) ;
  C_BDD closure = *this ;
  C_BDD XZclosure ;
  C_BDD ZYclosure ;
  C_BDD v ;
  const uint32_t bitCount2 = (uint32_t) (inBitSize + inBitSize) ;
  int32_t iterationCount = 0 ;
  do{
    v = closure ;
    iterationCount ++ ;
    XZclosure = closure.swap021 (inBitSize, inBitSize, inBitSize) ;
    ZYclosure = closure.swap210 (inBitSize, inBitSize, inBitSize) ;
    closure |= (XZclosure & ZYclosure).existsOnBitsAfterNumber (bitCount2) ;
  }while (closure != v) ;
  if (outIterationCount != nullptr) {
    * outIterationCount = iterationCount ;
  }
  return closure ;
}

//--------------------------------------------------------------------------------------------------

class cBuildArrayForRelation2 : public C_bdd_value_traversing {
//--- Attributes
  protected: TC_UniqueArray <TC_UniqueArray <uint64_t> > & mArray ;
  protected: uint32_t mBitsSize1 ;

//--- Constructor
  public:
  cBuildArrayForRelation2 (TC_UniqueArray <TC_UniqueArray <uint64_t> > & outArray,
                           const uint32_t inBitsSize1) ;

//--- Virtual method called for every value
  public: virtual void action (const bool * inValuesArray,
                               const uint32_t inBDDbitsSize) ;
} ;

//--------------------------------------------------------------------------------------------------

cBuildArrayForRelation2::cBuildArrayForRelation2 (TC_UniqueArray <TC_UniqueArray <uint64_t> > & outArray,
                                                  const uint32_t inBitsSize1) :
mArray (outArray),
mBitsSize1 (inBitsSize1) {
}

//--------------------------------------------------------------------------------------------------

void cBuildArrayForRelation2::action (const bool * inValuesArray,
                                      const uint32_t inBDDbitsSize) {
  int32_t index1 = 0 ;
  uint64_t index2 = 0 ;
  for (int32_t i=((int32_t) mBitsSize1) - 1 ; i>=0 ; i--) {
    index1 = (index1 << 1) + inValuesArray [i] ;
  }
  for (int32_t j=((int32_t) inBDDbitsSize) - 1 ; j>= (int32_t) mBitsSize1 ; j--) {
    index2 = (index2 << 1) + inValuesArray [j] ;
  }
  mArray (index1 COMMA_HERE).appendObject (index2) ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::getArray2 (TC_UniqueArray <TC_UniqueArray <uint64_t> > & outArray,
                       const uint32_t inMaxValueCount,
                       const uint32_t inBitSize1,
                       const uint32_t inBitSize2) const {
  outArray.removeAllKeepingCapacity () ;
  outArray.setCapacityUsingSwap ((int32_t) inMaxValueCount) ;
  for (uint32_t i=0 ; i<inMaxValueCount ; i++) {
    outArray.appendDefaultObjectUsingSwap () ;
  }
  cBuildArrayForRelation2 s (outArray, inBitSize1) ;
  traverseBDDvalues (s, (uint32_t) (inBitSize1 + inBitSize2)) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD as 3-relation
#endif

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::
swap021 (const uint32_t inBitSize1,
         const uint32_t inBitSize2,
         const uint32_t inBitSize3) const {
  const uint32_t totalSize = (uint32_t) (inBitSize1 + inBitSize2 + inBitSize3) ;
  uint32_t * tab = nullptr ;
  macroMyNewArray (tab, uint32_t, totalSize) ;
  for (uint32_t i=0 ; i<inBitSize1 ; i++) {
    tab [i] = i ;
  }
  for (uint32_t j=0 ; j<inBitSize2 ; j++) {
    tab [j + inBitSize1] = (uint32_t) (j + inBitSize1 + inBitSize3) ;
  }
  for (uint32_t k=0 ; k<inBitSize3 ; k++) {
    tab [k + inBitSize1 + inBitSize2] = (uint32_t) (k + inBitSize1) ;
  }
  const C_BDD bdd = substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return bdd ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::
swap120 (const uint32_t inBitSize1,
         const uint32_t inBitSize2,
         const uint32_t inBitSize3) const {
  const uint32_t totalSize = (uint32_t) (inBitSize1 + inBitSize2 + inBitSize3) ;
  uint32_t * tab = nullptr ;
  macroMyNewArray (tab, uint32_t, totalSize) ;
  for (uint32_t i=0 ; i<inBitSize1 ; i++) {
    tab [i] = (uint32_t) (i + inBitSize1 + inBitSize2) ;
  }
  for (uint32_t j=0 ; j<inBitSize2 ; j++) {
    tab [j + inBitSize1] = j ;
  }
  for (uint32_t k=0 ; k<inBitSize3 ; k++) {
    tab [k + inBitSize1 + inBitSize2] = (uint32_t) (k + inBitSize2) ;
  }
  const C_BDD bdd = substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return bdd ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::
swap102 (const uint32_t inBitSize1,
         const uint32_t inBitSize2,
         const uint32_t inBitSize3) const {
  const uint32_t totalSize = (uint32_t) (inBitSize1 + inBitSize2 + inBitSize3) ;
  uint32_t * tab = nullptr ;
  macroMyNewArray (tab, uint32_t, totalSize) ;
  for (uint32_t i=0 ; i<inBitSize1 ; i++) {
    tab [i] = (uint32_t) (i + inBitSize2) ;
  }
  for (uint32_t j=0 ; j<inBitSize2 ; j++) {
    tab [j + inBitSize1] = j ;
  }
  for (uint32_t k=0 ; k<inBitSize3 ; k++) {
    tab [k + inBitSize1 + inBitSize2] = (uint32_t) (k + inBitSize1 + inBitSize2) ;
  }
  const C_BDD bdd = substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return bdd ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::
swap210 (const uint32_t inBitSize1,
         const uint32_t inBitSize2,
         const uint32_t inBitSize3) const {
  const uint32_t totalSize = (uint32_t) (inBitSize1 + inBitSize2 + inBitSize3) ;
  uint32_t * tab = nullptr ;
  macroMyNewArray (tab, uint32_t, totalSize) ;
  for (uint32_t i=0 ; i<inBitSize1 ; i++) {
    tab [i] = (uint32_t) (i + inBitSize1 + inBitSize2) ;
  }
  for (uint32_t j=0 ; j<inBitSize2 ; j++) {
    tab [j + inBitSize1] = (uint32_t) (j + inBitSize3) ;
  }
  for (uint32_t k=0 ; k<inBitSize3 ; k++) {
    tab [k + inBitSize1 + inBitSize2] = k ;
  }
  const C_BDD bdd = substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return bdd ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::
swap201 (const uint32_t inBitSize1,
         const uint32_t inBitSize2,
         const uint32_t inBitSize3) const {
  const uint32_t totalSize = (uint32_t) (inBitSize1 + inBitSize2 + inBitSize3) ;
  uint32_t * tab = nullptr ;
  macroMyNewArray (tab, uint32_t, totalSize) ;
  for (uint32_t i=0 ; i<inBitSize1 ; i++) {
    tab [i] = (uint32_t) (i + inBitSize3) ;
  }
  for (uint32_t j=0 ; j<inBitSize2 ; j++) {
    tab [j + inBitSize1] = (uint32_t) (j + inBitSize1 + inBitSize3) ;
  }
  for (uint32_t k=0 ; k<inBitSize3 ; k++) {
    tab [k + inBitSize1 + inBitSize2] = k ;
  }
  const C_BDD bdd = substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return bdd ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Print BDD
#endif

//--------------------------------------------------------------------------------------------------

static void printLineWithSeparator (AbstractOutputStream & outputStream,
                                    const TC_UniqueArray <char> & inValueArray) {
  for (int32_t i=inValueArray.count () - 1 ; i>=0 ; i--) {
    if ((i % 4) == 3) {
      outputStream.appendCString (" ") ;
    }
    outputStream.appendASCIIChar (inValueArray (i COMMA_HERE)) ;
  }
  outputStream.appendNewLine () ;
}

//--------------------------------------------------------------------------------------------------

static void internalPrintWithSeparator (AbstractOutputStream & outputStream,
                                        const uint32_t inValue,
                                        TC_UniqueArray <char> & inDisplayString,
                                        uint32_t inVariableIndex) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  const uint32_t complement = inValue & 1 ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    if (complement == 1) {
      printLineWithSeparator (outputStream, inDisplayString) ;
    }
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    while (inVariableIndex > var) {
      inDisplayString.setObjectAtIndex ('X', (int32_t) inVariableIndex COMMA_HERE) ;
      inVariableIndex -- ;
    }
  //--- Branche Zero
    const uint32_t branche0 = gNodeArray [nodeIndex].mELSE ^ complement ;
    if (branche0 != 0) {
      inDisplayString.setObjectAtIndex ('0', (int32_t) var COMMA_HERE) ;
      if (branche0 == 1) {
        for (uint32_t i=0 ; i<var ; i++) {
          inDisplayString.setObjectAtIndex ('X', (int32_t) i COMMA_HERE) ;
        }
        printLineWithSeparator (outputStream, inDisplayString) ;
      }else{
        internalPrintWithSeparator (outputStream, branche0, inDisplayString, (uint32_t) (inVariableIndex - 1)) ;
      }
    }
  //--- Branche 1
    const uint32_t branche1 = gNodeArray [nodeIndex].mTHEN ^ complement ;
    if (branche1 != 0) {
      inDisplayString.setObjectAtIndex ('1', (int32_t) var COMMA_HERE) ;
      if (branche1 == 1) {
        for (uint32_t i=0 ; i<var ; i++) {
          inDisplayString.setObjectAtIndex ('X', (int32_t) i COMMA_HERE) ;
        }
        printLineWithSeparator (outputStream, inDisplayString) ;
      }else{
        internalPrintWithSeparator (outputStream, branche1, inDisplayString, (uint32_t) (inVariableIndex - 1)) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void C_BDD::print (AbstractOutputStream & outputStream) const {
  if (mBDDvalue == 0) {
    outputStream.appendCString ("(false)\n") ;
  }else if (mBDDvalue == 1) {
    outputStream.appendCString ("(true)\n") ;
  }else{
    const uint32_t nodeIndex = nodeIndexForRoot (mBDDvalue COMMA_HERE) ;
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    TC_UniqueArray <char> displayString ((int32_t) var + 1, 'X' COMMA_HERE) ;
    internalPrintWithSeparator (outputStream,
                                mBDDvalue,
                                displayString,
                                var) ;
  }
}

//--------------------------------------------------------------------------------------------------

void C_BDD::printHeader (AbstractOutputStream & outputStream) const {
  if (mBDDvalue > 1) {
    const uint32_t nodeIndex = nodeIndexForRoot (mBDDvalue COMMA_HERE) ;
    const int32_t var = (int32_t) gNodeArray [nodeIndex].mVariableIndex ;
  //--- Digit count
    int32_t digitCount = 0 ;
    int32_t n = var ;
    int32_t divisor = 1 ;
    while (n > 0) {
      digitCount ++ ;
      n /= 10 ;
      divisor *= 10 ;
    }
  //---
    for (int32_t d=0 ; d<digitCount ; d++) {
      divisor /= 10 ;
      for (int32_t i=var ; i>=0 ; i--) {
        if ((i % 4) == 3) {
          outputStream.appendCString (" ") ;
        }
        const int32_t v = (i / divisor) % 10 ;
        outputStream.appendSigned (v) ;
      }
      outputStream.appendNewLine () ;
    }
    for (int32_t i=var ; i>=0 ; i--) {
      if ((i % 4) == 3) {
        outputStream.appendCString ("-") ;
      }
      outputStream.appendCString ("-") ;
    }
    outputStream.appendNewLine () ;
  }
}

//--------------------------------------------------------------------------------------------------

void C_BDD::printWithHeader (AbstractOutputStream & outputStream) const {
  printHeader (outputStream) ;
  print (outputStream) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Print BDD with variables
#endif

//--------------------------------------------------------------------------------------------------

static void printLineWithSeparator (AbstractOutputStream & outputStream,
                                    const TC_UniqueArray <int32_t> & inValueSeparation,
                                    const TC_UniqueArray <int32_t> & inBitCounts,
                                    const TC_UniqueArray <char> & inValueArray) {
  int32_t bitIndex = inValueArray.count () - 1 ;
  for (int32_t i=0 ; i<inBitCounts.count () ; i++) {
    outputStream.appendCString (" ") ;
    outputStream.appendString (String::spaces (inValueSeparation (i COMMA_HERE))) ;
    for (int32_t j=0 ; j<inBitCounts (i COMMA_HERE) ; j++) {
      outputStream.appendASCIIChar (inValueArray (bitIndex COMMA_HERE)) ;
      bitIndex -- ;
    }
  }
  outputStream.appendNewLine () ;
}

//--------------------------------------------------------------------------------------------------

static void internalPrintWithSeparator (AbstractOutputStream & outputStream,
                                        const TC_UniqueArray <int32_t> & inValueSeparation,
                                        const TC_UniqueArray <int32_t> & inBitCounts,
                                        const uint32_t inValue,
                                        TC_UniqueArray <char> & inDisplayString,
                                        uint32_t inVariableIndex) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  const uint32_t complement = inValue & 1 ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    if (complement == 1) {
      printLineWithSeparator (outputStream, inValueSeparation, inBitCounts, inDisplayString) ;
    }
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    while (inVariableIndex > var) {
      inDisplayString.setObjectAtIndex ('X', (int32_t) inVariableIndex COMMA_HERE) ;
      inVariableIndex -- ;
    }
  //--- Branche Zero
    const uint32_t branche0 = gNodeArray [nodeIndex].mELSE ^ complement ;
    if (branche0 != 0) {
      inDisplayString.setObjectAtIndex ('0', (int32_t) var COMMA_HERE) ;
      if (branche0 == 1) {
        for (uint32_t i=0 ; i<var ; i++) {
          inDisplayString.setObjectAtIndex ('X', (int32_t) i COMMA_HERE) ;
        }
        printLineWithSeparator (outputStream, inValueSeparation, inBitCounts, inDisplayString) ;
      }else{
        internalPrintWithSeparator (outputStream, inValueSeparation, inBitCounts, branche0, inDisplayString, (uint32_t) (inVariableIndex - 1)) ;
      }
    }
  //--- Branche 1
    const uint32_t branche1 = gNodeArray [nodeIndex].mTHEN ^ complement ;
    if (branche1 != 0) {
      inDisplayString.setObjectAtIndex ('1', (int32_t) var COMMA_HERE) ;
      if (branche1 == 1) {
        for (uint32_t i=0 ; i<var ; i++) {
          inDisplayString.setObjectAtIndex ('X', (int32_t) i COMMA_HERE) ;
        }
        printLineWithSeparator (outputStream, inValueSeparation, inBitCounts, inDisplayString) ;
      }else{
        internalPrintWithSeparator (outputStream, inValueSeparation, inBitCounts, branche1, inDisplayString, (uint32_t) (inVariableIndex - 1)) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void C_BDD::print (AbstractOutputStream & outputStream,
                   const TC_UniqueArray <String> & inVariablesNames,
                   const TC_UniqueArray <int32_t> & inBitCounts) const {
//--- Build separators
  TC_UniqueArray <int32_t> variableNameSeparation ;
  TC_UniqueArray <int32_t> valuesSeparation ;
  for (int32_t i=0 ; i<inVariablesNames.count () ; i++) {
    const int32_t variableLength = inVariablesNames (i COMMA_HERE).length () ;
    const int32_t bitCount = inBitCounts (i COMMA_HERE) ;
    const int32_t length = (variableLength > bitCount) ? variableLength : bitCount ;
    variableNameSeparation.appendObject (length - variableLength) ;
    valuesSeparation.appendObject (length - bitCount) ;
  }
//--- Print header
  for (int32_t i=0 ; i<inVariablesNames.count () ; i++) {
    outputStream.appendCString (" ") ;
    outputStream.appendString (String::spaces (variableNameSeparation (i COMMA_HERE))) ;
    outputStream.appendString (inVariablesNames (i COMMA_HERE)) ;
  }
  outputStream.appendNewLine () ;
//--- Print value
  print (outputStream, valuesSeparation, inBitCounts, 1) ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::print (AbstractOutputStream & outputStream,
                   const TC_UniqueArray <int32_t> & inValueSeparation,
                   const TC_UniqueArray <int32_t> & inBitCounts,
                   const int32_t inPrefixedSpaceCount) const {
  if (mBDDvalue == 0) {
    outputStream.appendString (String::spaces (inPrefixedSpaceCount)) ;
    outputStream.appendCString ("(false)\n") ;
  }else if (mBDDvalue == 1) {
    outputStream.appendString (String::spaces (inPrefixedSpaceCount)) ;
    outputStream.appendCString ("(true)\n") ;
  }else{
    uint32_t totalBitCount = 0 ;
    for (int32_t i=0 ; i<inBitCounts.count () ; i++) {
      totalBitCount += (uint32_t) inBitCounts (i COMMA_HERE) ;
    }
    TC_UniqueArray <char> displayString ((int32_t) totalBitCount, 'X' COMMA_HERE) ;
    internalPrintWithSeparator (outputStream,
                                inValueSeparation,
                                inBitCounts,
                                mBDDvalue,
                                displayString,
                                totalBitCount - 1) ;
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Graphviz representation
#endif

//--------------------------------------------------------------------------------------------------

static void buildGraphvizRepresentation (String & ioString,
                                         const String & inSourceNode,
                                         const uint32_t inBDDValue,
                                         const TC_UniqueArray <String> & inBitNames) {
  const uint32_t nodeIndex = nodeIndexForRoot (inBDDValue COMMA_HERE) ;
  const int32_t var = (int32_t) gNodeArray [nodeIndex].mVariableIndex ;
  const String node = String ("N") + stringWithUnsigned (nodeIndex) ;
  if (! isNodeMarkedThenMark (inBDDValue COMMA_HERE)) {
    const uint32_t THENbranch = gNodeArray [nodeIndex].mTHEN ;
    String THENlabel ;
    if (THENbranch == 0) {
      THENlabel.appendCString ("F") ;
    }else if (THENbranch == 1) {
      THENlabel.appendCString ("T") ;
    }else{
      THENlabel.appendCString ("<f1>") ;
    }
    const uint32_t ELSEbranch = gNodeArray [nodeIndex].mELSE ;
    String ELSElabel ;
    if (ELSEbranch == 0) {
      ELSElabel.appendCString ("F") ;
    }else if (ELSEbranch == 1) {
      ELSElabel.appendCString ("T") ;
    }else{
      ELSElabel.appendCString ("<f0>") ;
    }
    ioString.appendCString ("  ") ;
    ioString.appendString (node) ;
    ioString.appendCString (" [label=\"{") ;
    ioString.appendString (inBitNames (var COMMA_HERE)) ;
    ioString.appendCString ("|{") ;
    ioString.appendString (ELSElabel) ;
    ioString.appendCString ("|") ;
    ioString.appendString (THENlabel) ;
    ioString.appendCString ("}}\"]\n") ;
    if (ELSEbranch > 1) {
      buildGraphvizRepresentation (ioString, node + String (":f0:c"), ELSEbranch, inBitNames) ;
    }
    if (THENbranch > 1) {
      buildGraphvizRepresentation (ioString, node + String (":f1:c"), THENbranch, inBitNames) ;
    }
  }
  ioString.appendCString ("  ") ;
  ioString.appendString (inSourceNode) ;
  ioString.appendCString (" -> ") ;
  ioString.appendString (node) ;
  ioString.appendCString ("") ;
  if ((inBDDValue & 1) != 0) {
    ioString.appendCString (" [dir=both, arrowtail=dot]") ;
  }
  ioString.appendCString (" ;\n") ;
}

//--------------------------------------------------------------------------------------------------

String C_BDD::graphvizRepresentation (void) const {
  int32_t varCount = 0 ;
  if (mBDDvalue > 1) {
    const uint32_t nodeIndex = nodeIndexForRoot (mBDDvalue COMMA_HERE) ;
    varCount = ((int32_t) gNodeArray [nodeIndex].mVariableIndex) + 1 ;
  }
  TC_UniqueArray <String> bitNames ;
  for (int32_t i=0 ; i<varCount ; i++) {
    bitNames.appendObject (stringWithSigned (i)) ;
  }
  return graphvizRepresentationWithNames (bitNames) ;
}

//--------------------------------------------------------------------------------------------------

String C_BDD::graphvizRepresentationWithNames (const TC_UniqueArray <String> & inBitNames) const {
  unmarkAllExistingBDDnodes () ;
  String result ;
  result.appendCString ("digraph G {\n") ;
  if (mBDDvalue == 0) {
    result.appendCString ("  N [label=\"F\", shape=rectangle]\n") ;
  }else if (mBDDvalue == 1) {
    result.appendCString ("  N [label=\"T\", shape=rectangle]\n") ;
  }else{
    result.appendCString ("  edge [arrowhead=vee, tailclip=false]\n"
                         "  node [fontname=courier, shape=record]\n"
                         "  N [label=\"\", shape=rectangle]\n") ;
    buildGraphvizRepresentation (result, "N", mBDDvalue, inBitNames) ;
  }
  result.appendCString ("}\n") ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark String array representation
#endif

//--------------------------------------------------------------------------------------------------

static void internalPrintBDDInLittleEndianStringArray (const uint32_t inValue,
                                                       String & ioDisplayString,
                                                       uint32_t inVariableIndex,
                                                       TC_UniqueArray <String> & outStringArray
                                                       COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  const uint32_t complement = inValue & 1 ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    if (complement == 1) {
      outStringArray.appendObject (ioDisplayString) ;
    }
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    while (inVariableIndex > var) {
      ioDisplayString.setCharAtIndex (TO_UNICODE ('X'), (int32_t) inVariableIndex COMMA_THERE) ;
      inVariableIndex -- ;
    }
  //--- Branche Zero
    const uint32_t branche0 = gNodeArray [nodeIndex].mELSE ^ complement ;
    if (branche0 != 0) {
      ioDisplayString.setCharAtIndex (TO_UNICODE ('0'), (int32_t) var COMMA_HERE) ;
      if (branche0 == 1) {
        for (uint32_t i=0 ; i<var ; i++) {
          ioDisplayString.setCharAtIndex (TO_UNICODE ('X'), (int32_t) i COMMA_HERE) ;
        }
        outStringArray.appendObject (ioDisplayString) ;
      }else{
        internalPrintBDDInLittleEndianStringArray (branche0, ioDisplayString, (uint32_t) (inVariableIndex - 1), outStringArray COMMA_THERE) ;
      }
    }
  //--- Branche 1
    const uint32_t branche1 = gNodeArray [nodeIndex].mTHEN ^ complement ;
    if (branche1 != 0) {
      ioDisplayString.setCharAtIndex (TO_UNICODE ('1'), (int32_t) var COMMA_HERE) ;
      if (branche1 == 1) {
        for (uint32_t i=0 ; i<var ; i++) {
          ioDisplayString.setCharAtIndex (TO_UNICODE ('X'), (int32_t) i COMMA_HERE) ;
        }
        outStringArray.appendObject (ioDisplayString) ;
      }else{
        internalPrintBDDInLittleEndianStringArray (branche1, ioDisplayString, (uint32_t) (inVariableIndex - 1), outStringArray COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void C_BDD::
buildCompressedLittleEndianStringValueArray (TC_UniqueArray <String> & outStringArray
                                             COMMA_LOCATION_ARGS) const {
  const uint32_t nodeIndex = nodeIndexForRoot (mBDDvalue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    String displayString ;
    for (int32_t i=0 ; i<=((int32_t) gNodeArray [nodeIndex].mVariableIndex) ; i++) {
      displayString.appendCString ("X") ;
    }
    internalPrintBDDInLittleEndianStringArray (mBDDvalue, displayString, gNodeArray [nodeIndex].mVariableIndex, outStringArray COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

void C_BDD::
buildCompressedLittleEndianStringValueArray (TC_UniqueArray <String> & outStringArray,
                                             const uint32_t inVariableCount
                                             COMMA_LOCATION_ARGS) const {
  String displayString ;
  for (int32_t i=0 ; i<((int32_t) inVariableCount) ; i++) {
    displayString.appendCString ("X") ;
  }
  internalPrintBDDInLittleEndianStringArray (mBDDvalue, displayString, inVariableCount, outStringArray COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

static void internalPrintBDDInBigEndianStringArray (const uint32_t inValue,
                                                    String & ioDisplayString,
                                                    uint32_t inVariableIndex,
                                                    const uint32_t inTotalVariableCountMinusOne,
                                                    TC_UniqueArray <String> & outStringArray
                                                    COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  const uint32_t complement = inValue & 1 ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    if (complement == 1) {
      outStringArray.appendObject (ioDisplayString) ;
    }
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    while (inVariableIndex > var) {
      ioDisplayString.setCharAtIndex (TO_UNICODE ('X'), (int32_t) (inTotalVariableCountMinusOne - inVariableIndex) COMMA_THERE) ;
      inVariableIndex -- ;
    }
  //--- Branche Zero
    const uint32_t branche0 = gNodeArray [nodeIndex].mELSE ^ complement ;
    if (branche0 != 0) {
      ioDisplayString.setCharAtIndex (TO_UNICODE ('0'), (int32_t) (inTotalVariableCountMinusOne - var) COMMA_THERE) ;
      if (branche0 == 1) {
        for (uint32_t i=0 ; i<var ; i++) {
          ioDisplayString.setCharAtIndex (TO_UNICODE ('X'), (int32_t) (inTotalVariableCountMinusOne - i) COMMA_THERE) ;
        }
        outStringArray.appendObject (ioDisplayString) ;
      }else{
        internalPrintBDDInBigEndianStringArray (branche0, ioDisplayString, (uint32_t) (inVariableIndex - 1), inTotalVariableCountMinusOne, outStringArray COMMA_THERE) ;
      }
    }
  //--- Branche 1
    const uint32_t branche1 = gNodeArray [nodeIndex].mTHEN ^ complement ;
    if (branche1 != 0) {
      ioDisplayString.setCharAtIndex (TO_UNICODE ('1'), (int32_t) (inTotalVariableCountMinusOne - var) COMMA_HERE) ;
      if (branche1 == 1) {
        for (uint32_t i=0 ; i<var ; i++) {
          ioDisplayString.setCharAtIndex (TO_UNICODE ('X'), (int32_t) (inTotalVariableCountMinusOne - i) COMMA_HERE) ;
        }
        outStringArray.appendObject (ioDisplayString) ;
      }else{
        internalPrintBDDInBigEndianStringArray (branche1, ioDisplayString, (uint32_t) (inVariableIndex - 1), inTotalVariableCountMinusOne, outStringArray COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void C_BDD::
buildCompressedBigEndianStringValueArray (TC_UniqueArray <String> & outStringArray
                                          COMMA_LOCATION_ARGS) const {
  const uint32_t nodeIndex = nodeIndexForRoot (mBDDvalue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    String displayString ;
    for (int32_t i=0 ; i<=((int32_t) gNodeArray [nodeIndex].mVariableIndex) ; i++) {
      displayString.appendCString ("X") ;
    }
    internalPrintBDDInBigEndianStringArray (mBDDvalue, displayString, gNodeArray [nodeIndex].mVariableIndex, gNodeArray [nodeIndex].mVariableIndex, outStringArray COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

void C_BDD::
buildCompressedBigEndianStringValueArray (TC_UniqueArray <String> & outStringArray,
                                 const uint32_t inVariableCount
                                 COMMA_LOCATION_ARGS) const {
  String displayString ;
  for (int32_t i=0 ; i<((int32_t) inVariableCount) ; i++) {
    displayString.appendCString ("X") ;
  }
  internalPrintBDDInBigEndianStringArray (mBDDvalue,
                                          displayString,
                                          inVariableCount - 1,
                                          inVariableCount - 1,
                                          outStringArray COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build BDD from value list
#endif

static inline void swapValueArray (uint64_t * ioValueArray,
                                   const int32_t inIndex1,
                                   const int32_t inIndex2) {
  const uint64_t v = ioValueArray [inIndex1] ;
  ioValueArray [inIndex1] = ioValueArray [inIndex2] ;
  ioValueArray [inIndex2] = v ;
}

//--------------------------------------------------------------------------------------------------

static void sortValueArray (uint64_t * ioValueArray,
                            const int32_t inLeftIndex,
                            const int32_t inRightIndex) {
  if (inLeftIndex < inRightIndex) {
    const int32_t pivotIndex = (inRightIndex + inLeftIndex) / 2 ;
    const uint64_t pivotValue = ioValueArray [pivotIndex] ;
  //--- Move pivot to the end
    swapValueArray (ioValueArray, pivotIndex, inRightIndex) ;
  //--- storeIndex := left
    int32_t storeIndex = inLeftIndex ;
    for (int32_t i=inLeftIndex ; i<inRightIndex ; i++) {
      if (ioValueArray [i] <= pivotValue) {
        swapValueArray (ioValueArray, i, storeIndex) ;
        storeIndex ++ ;
      }
    }
    swapValueArray (ioValueArray, inRightIndex, storeIndex) ;
  //---
    sortValueArray (ioValueArray, inLeftIndex, storeIndex - 1) ;
    sortValueArray (ioValueArray, storeIndex + 1, inRightIndex) ;
  }
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::buildBDDFromValueList (uint64_t * ioValueList,
                                    const uint32_t inValueCount,
                                    const uint32_t inBitCount) {
//---
  if (0 == inBitCount) {
    printf ("*** error in %s:%d: inBitCount is zero (should be > 0)***\n", __FILE__, __LINE__) ;
    exit (1) ;
  }
  if (inBitCount > 64) {
    printf ("*** error in %s:%d: inBitCount = %u (should be <= 64)***\n", __FILE__, __LINE__, inBitCount) ;
    exit (1) ;
  }
//---
  C_BDD result ;
  if (inValueCount > 0) {
  //--- Sort value list in ascending order
    sortValueArray (ioValueList, 0, (int32_t) (inValueCount - 1)) ;
  //--- Search for duplicates
    uint32_t duplicates = 0 ;
    for (uint32_t i=1 ; i<inValueCount ; i++) {
      duplicates += ioValueList [i-1] == ioValueList [i] ;
    }
    if (duplicates > 0) {
      printf ("Warning: %u duplicates\n", duplicates) ;
    }
  //--- Translate into BDD
    C_BDD * accumulatorArray = nullptr ;
    macroMyNewArray (accumulatorArray, C_BDD, inBitCount) ;
    uint64_t referenceValue = ioValueList [0] ;
    for (uint32_t i=0 ; i<inValueCount ; i++) {
      const uint64_t currentTransition = ioValueList [i] ;
      uint64_t mask = 1UL << (inBitCount - 1) ;
      int32_t firstDifferentBit = ((int32_t) inBitCount) - 1 ;
      while ((firstDifferentBit >= 0) && (((currentTransition ^ referenceValue) & mask) == 0)) {
        firstDifferentBit -- ;
        mask >>=1 ;
      }
      if (firstDifferentBit >= 0) {
        C_BDD accumulatorBDD ; accumulatorBDD.setToTrue () ;
        mask = 1UL ;
        for (int32_t idx=0 ; idx<=firstDifferentBit ; idx++) {
          accumulatorBDD = (C_BDD ((uint32_t) (((uint32_t) idx) & UINT16_MAX), (referenceValue & mask) != 0) & accumulatorBDD) | accumulatorArray [idx] ;
          accumulatorArray [idx].setToFalse () ;
          mask <<= 1 ;
        }
        referenceValue = currentTransition ;
        accumulatorArray [firstDifferentBit] |= accumulatorBDD ;
      }
    }
    result.setToTrue () ;
    uint64_t mask = 1UL ;
    for (uint32_t idx=0 ; idx<inBitCount ; idx++) {
      result = (C_BDD ((uint32_t) (((uint32_t) idx) & UINT16_MAX), (referenceValue & mask) != 0) & result) | accumulatorArray [idx] ;
      mask <<= 1 ;
    }
    macroMyDeleteArray (accumulatorArray) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD operators
#endif

//--------------------------------------------------------------------------------------------------

void C_BDD::setToFalse (void) {
  mBDDvalue = 0  ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::setToTrue (void) {
  mBDDvalue = 1  ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::ite (const C_BDD & f, const C_BDD & g, const C_BDD & h) {
  return C_BDD (internalITEoperation (f.mBDDvalue, g.mBDDvalue, h.mBDDvalue)) ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::implies (const C_BDD & inOperand) const {
//--- f -> g est defini par (non f) ou g, c'est a dire non (f et (non g))
  return C_BDD (internalANDoperation (mBDDvalue, inOperand.mBDDvalue ^ 1) ^ 1) ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::operator & (const C_BDD & inOperand) const {
  return C_BDD (internalANDoperation (mBDDvalue, inOperand.mBDDvalue)) ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::operator &= (const C_BDD & inOperand) {
   mBDDvalue = internalANDoperation (mBDDvalue, inOperand.mBDDvalue) ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::operator | (const C_BDD & inOperand) const {
  return C_BDD (internalANDoperation (mBDDvalue ^ 1, inOperand.mBDDvalue ^ 1) ^ 1) ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::operator |= (const C_BDD & inOperand) {
  mBDDvalue = internalANDoperation (mBDDvalue ^ 1, inOperand.mBDDvalue ^ 1) ^ 1 ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::equalTo(const C_BDD & inOperand) const {
  return C_BDD (internalITEoperation (mBDDvalue, inOperand.mBDDvalue, inOperand.mBDDvalue ^ 1)) ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::notEqualTo (const C_BDD & inOperand) const {
  return C_BDD (internalITEoperation (mBDDvalue, inOperand.mBDDvalue ^ 1, inOperand.mBDDvalue)) ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::lowerOrEqual (const C_BDD & inOperand) const { // <=
  return C_BDD (internalANDoperation (mBDDvalue, inOperand.mBDDvalue ^ 1) ^ 1) ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::greaterThan (const C_BDD & inOperand) const { // >
  return C_BDD (internalANDoperation (mBDDvalue, inOperand.mBDDvalue ^ 1)) ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::lowerThan (const C_BDD & inOperand) const { // <
  return C_BDD (internalANDoperation (mBDDvalue ^ 1, inOperand.mBDDvalue)) ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::greaterOrEqual (const C_BDD & inOperand) const { // >=
  return C_BDD (internalANDoperation (mBDDvalue ^ 1, inOperand.mBDDvalue) ^ 1) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Value Count (64)
#endif

//--------------------------------------------------------------------------------------------------

static void internalValueCount64 (const uint32_t inValue,
                                  const uint32_t inVariableCount,
                                  uint64_t & nombreDirect,
                                  uint64_t & nombreComplement
                                  COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_THERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    nombreDirect = 0 ;
    nombreComplement = 1 ;
    for (uint32_t i=0 ; i<inVariableCount ; i++) {
      nombreComplement += nombreComplement ;
    }
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    uint64_t nd0, nc0, nd1, nc1 ;
    internalValueCount64 (gNodeArray [nodeIndex].mELSE, var, nd0, nc0 COMMA_THERE) ;
    internalValueCount64 (gNodeArray [nodeIndex].mTHEN, var, nd1, nc1 COMMA_THERE) ;
    nombreDirect = nd0 + nd1 ;
    nombreComplement = nc0 + nc1 ;
    for (uint32_t i=(uint32_t) (var+1) ; i<inVariableCount ; i++) {
      nombreDirect += nombreDirect ;
      nombreComplement += nombreComplement ;
    }
  }
  if ((inValue & 1) != 0) {
    const uint64_t tempo = nombreDirect ;
    nombreDirect = nombreComplement ;
    nombreComplement = tempo ;
  }
}

//--------------------------------------------------------------------------------------------------

uint64_t C_BDD::valueCount64 (const uint32_t inVariableCount) const {
  uint64_t nombreDirect = 0 ;
  uint64_t nombreComplement = 0 ;
  internalValueCount64 (mBDDvalue, inVariableCount, nombreDirect, nombreComplement COMMA_HERE) ;
  return nombreDirect ;
}

//--------------------------------------------------------------------------------------------------

static void internalValueCount64UsingCache (const uint32_t inValue,
                                            const uint32_t inVariableCount,
                                            uint64_t & nombreDirect,
                                            uint64_t & nombreComplement,
                                            TC_UniqueArray <uint64_t> & ioDirectCacheArray,
                                            TC_UniqueArray <uint64_t> & ioComplementCacheArray
                                            COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_THERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    nombreDirect = 0 ;
    nombreComplement = 1 << inVariableCount ;
  }else if ((ioDirectCacheArray.count () > (int32_t) (inValue / 2))
      && ((ioDirectCacheArray (inValue / 2 COMMA_HERE) != 0) || (ioComplementCacheArray (inValue / 2 COMMA_HERE) != 0))) {
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    nombreDirect = ioDirectCacheArray (inValue / 2 COMMA_HERE) << (inVariableCount - var - 1) ;
    nombreComplement = ioComplementCacheArray (inValue / 2 COMMA_HERE) << (inVariableCount - var - 1) ;
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    uint64_t nd0, nc0, nd1, nc1 ;
    internalValueCount64UsingCache (gNodeArray [nodeIndex].mELSE, var, nd0, nc0, ioDirectCacheArray, ioComplementCacheArray COMMA_THERE) ;
    internalValueCount64UsingCache (gNodeArray [nodeIndex].mTHEN, var, nd1, nc1, ioDirectCacheArray, ioComplementCacheArray COMMA_THERE) ;
    nombreDirect = nd0 + nd1 ;
    nombreComplement = nc0 + nc1 ;
    ioDirectCacheArray.forceObjectAtIndex (inValue / 2, nombreDirect, 0) ;
    ioComplementCacheArray.forceObjectAtIndex (inValue / 2, nombreComplement, 0) ;
    nombreDirect <<= (inVariableCount - var - 1) ;
    nombreComplement <<= (inVariableCount - var - 1) ;
  }
//---
  if ((inValue & 1) != 0) {
    const uint64_t tempo = nombreDirect ;
    nombreDirect = nombreComplement ;
    nombreComplement = tempo ;
  }
}

//--------------------------------------------------------------------------------------------------

uint64_t C_BDD::valueCount64UsingCache (const uint32_t inVariableCount,
                                        TC_UniqueArray <uint64_t> & ioDirectCacheArray,
                                        TC_UniqueArray <uint64_t> & ioComplementCacheArray) const {
  uint64_t nombreDirect = 0 ;
  uint64_t nombreComplement = 0 ;
  internalValueCount64UsingCache (mBDDvalue, inVariableCount, nombreDirect, nombreComplement, ioDirectCacheArray, ioComplementCacheArray COMMA_HERE) ;
  return nombreDirect ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Value Count (128)
#endif

//--------------------------------------------------------------------------------------------------

static void internalValueCount128 (const uint32_t inValue,
                                   const uint32_t inVariableCount,
                                   UInt128 & nombreDirect,
                                   UInt128 & nombreComplement
                                   COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_THERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    nombreDirect = 0 ;
    nombreComplement = 1 ;
    for (uint32_t i=0 ; i<inVariableCount ; i++) {
      nombreComplement += nombreComplement ;
    }
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    UInt128 nd0, nc0, nd1, nc1 ;
    internalValueCount128 (gNodeArray [nodeIndex].mELSE, var, nd0, nc0 COMMA_THERE) ;
    internalValueCount128 (gNodeArray [nodeIndex].mTHEN, var, nd1, nc1 COMMA_THERE) ;
    nombreDirect = nd0 + nd1 ;
    nombreComplement = nc0 + nc1 ;
    for (uint32_t i=(uint32_t) (var+1) ; i<inVariableCount ; i++) {
      nombreDirect += nombreDirect ;
      nombreComplement += nombreComplement ;
    }
  }
  if ((inValue & 1) != 0) {
    const UInt128 tempo = nombreDirect ;
    nombreDirect = nombreComplement ;
    nombreComplement = tempo ;
  }
}

//--------------------------------------------------------------------------------------------------

UInt128 C_BDD::valueCount128 (const uint32_t inVariableCount) const {
  UInt128 nombreDirect = 0 ;
  UInt128 nombreComplement = 0 ;
  internalValueCount128 (mBDDvalue, inVariableCount, nombreDirect, nombreComplement COMMA_HERE) ;
  return nombreDirect ;
}

//--------------------------------------------------------------------------------------------------

static void internalValueCount128UsingCache (const uint32_t inValue,
                                             const uint32_t inVariableCount,
                                             UInt128 & nombreDirect,
                                             UInt128 & nombreComplement,
                                             TC_UniqueArray <UInt128> & ioDirectCacheArray,
                                             TC_UniqueArray <UInt128> & ioComplementCacheArray
                                             COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_THERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    nombreDirect = 0 ;
    nombreComplement = 1 << inVariableCount ;
  }else if ((ioDirectCacheArray.count () > (int32_t) (inValue / 2))
    && (((ioDirectCacheArray (inValue / 2 COMMA_HERE) != 0) || (ioComplementCacheArray (inValue / 2 COMMA_HERE) != 0)))) {
    nombreDirect = ioDirectCacheArray (inValue / 2 COMMA_HERE) ;
    nombreComplement = ioComplementCacheArray (inValue / 2 COMMA_HERE) ;
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    UInt128 nd0, nc0, nd1, nc1 ;
    internalValueCount128UsingCache (gNodeArray [nodeIndex].mELSE, var, nd0, nc0, ioDirectCacheArray, ioComplementCacheArray COMMA_THERE) ;
    internalValueCount128UsingCache (gNodeArray [nodeIndex].mTHEN, var, nd1, nc1, ioDirectCacheArray, ioComplementCacheArray COMMA_THERE) ;
    nombreDirect = nd0 + nd1 ;
    nombreComplement = nc0 + nc1 ;
    for (uint32_t i=(uint32_t) (var+1) ; i<inVariableCount ; i++) {
      nombreDirect += nombreDirect ;
      nombreComplement += nombreComplement ;
    }
    ioDirectCacheArray.forceObjectAtIndex (int32_t (inValue / 2), nombreDirect, 0) ;
    ioComplementCacheArray.forceObjectAtIndex (int32_t (inValue / 2), nombreComplement, 0) ;
  }
  if ((inValue & 1) != 0) {
    const UInt128 tempo = nombreDirect ;
    nombreDirect = nombreComplement ;
    nombreComplement = tempo ;
  }
}

//--------------------------------------------------------------------------------------------------

UInt128 C_BDD::valueCount128UsingCache (const uint32_t inVariableCount,
                                          TC_UniqueArray <UInt128> & ioDirectCacheArray,
                                          TC_UniqueArray <UInt128> & ioComplementCacheArray) const {
  UInt128 nombreDirect = 0 ;
  UInt128 nombreComplement = 0 ;
  internalValueCount128UsingCache (mBDDvalue, inVariableCount, nombreDirect, nombreComplement, ioDirectCacheArray, ioComplementCacheArray COMMA_HERE) ;
  return nombreDirect ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Value Count (Big ints)
#endif

//--------------------------------------------------------------------------------------------------

static void internalValueCount (const uint32_t inValue,
                                const uint32_t inVariableCount,
                                BigSigned & nombreDirect,
                                BigSigned & nombreComplement
                                COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_THERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    nombreDirect = BigSigned () ;
    nombreComplement = BigSigned (true, 1) ;
    nombreComplement <<= inVariableCount ;
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    BigSigned nd0, nc0, nd1, nc1 ;
    internalValueCount (gNodeArray [nodeIndex].mELSE, var, nd0, nc0 COMMA_THERE) ;
    internalValueCount (gNodeArray [nodeIndex].mTHEN, var, nd1, nc1 COMMA_THERE) ;
    nombreDirect = nd0 + nd1 ;
    nombreComplement = nc0 + nc1 ;
    const int32_t shiftCount = ((int32_t) inVariableCount) - ((int32_t) var) - 1 ;
    if (shiftCount > 0) {
      nombreDirect <<= (uint32_t) shiftCount ;
      nombreComplement <<= (uint32_t) shiftCount ;
    }
  }
  if ((inValue & 1) != 0) {
    swap (nombreDirect, nombreComplement) ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned C_BDD::valueCount (const uint32_t inVariableCount) const {
  BigSigned nombreDirect ;
  BigSigned nombreComplement ;
  internalValueCount (mBDDvalue, inVariableCount, nombreDirect, nombreComplement COMMA_HERE) ;
  return nombreDirect ;
}

//--------------------------------------------------------------------------------------------------

static void internalValueCountUsingCache (const uint32_t inValue,
                                          const uint32_t inVariableCount,
                                          BigSigned & nombreDirect,
                                          BigSigned & nombreComplement,
                                          TC_UniqueArray <BigSigned> & ioDirectCacheArray,
                                          TC_UniqueArray <BigSigned> & ioComplementCacheArray
                                          COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_THERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    nombreDirect = BigSigned () ;
    nombreComplement = BigSigned (true, 1) ;
    nombreComplement <<= inVariableCount ;
  }else if ((ioDirectCacheArray.count () > (int32_t) (inValue / 2))
    && (((!ioDirectCacheArray (inValue / 2 COMMA_HERE).isZero ()) || (!ioComplementCacheArray (inValue / 2 COMMA_HERE).isZero())))) {
    nombreDirect = ioDirectCacheArray (inValue / 2 COMMA_HERE) ;
    nombreComplement = ioComplementCacheArray (inValue / 2 COMMA_HERE) ;
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    BigSigned nd0, nc0, nd1, nc1 ;
    internalValueCountUsingCache (gNodeArray [nodeIndex].mELSE, var, nd0, nc0, ioDirectCacheArray, ioComplementCacheArray COMMA_THERE) ;
    internalValueCountUsingCache (gNodeArray [nodeIndex].mTHEN, var, nd1, nc1, ioDirectCacheArray, ioComplementCacheArray COMMA_THERE) ;
    nombreDirect = nd0 + nd1 ;
    nombreComplement = nc0 + nc1 ;
    const int32_t shiftCount = ((int32_t) inVariableCount) - ((int32_t) var) - 1 ;
    if (shiftCount > 0) {
      nombreDirect <<= (uint32_t) shiftCount ;
      nombreComplement <<= (uint32_t) shiftCount ;
    }
    ioDirectCacheArray.forceObjectAtIndex (inValue / 2, nombreDirect, BigSigned ()) ;
    ioComplementCacheArray.forceObjectAtIndex (inValue / 2, nombreComplement, BigSigned ()) ;
  }
  if ((inValue & 1) != 0) {
    swap (nombreDirect, nombreComplement) ;
  }
}

//--------------------------------------------------------------------------------------------------

BigSigned C_BDD::valueCountUsingCache (const uint32_t inVariableCount,
                                      TC_UniqueArray <BigSigned> & ioDirectCacheArray,
                                      TC_UniqueArray <BigSigned> & ioComplementCacheArray) const {
  BigSigned nombreDirect ;
  BigSigned nombreComplement ;
  internalValueCountUsingCache (mBDDvalue, inVariableCount, nombreDirect, nombreComplement, ioDirectCacheArray, ioComplementCacheArray COMMA_HERE) ;
  return nombreDirect ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Get i-th value as BDD
#endif

//--------------------------------------------------------------------------------------------------

static C_BDD obtenirIemeBDDinterne (const uint32_t inValue,
                                    const uint64_t inNthBDDvalue,
                                    const uint32_t inVariableCount) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  const uint32_t complement = inValue & 1 ;
  uint64_t iEme ;
  C_BDD result ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    if (complement == 1) { // Decomposer inNthBDDvalue en binaire
      result = ~ result ;
      iEme = inNthBDDvalue ;
      for (uint32_t i=0 ; i<inVariableCount ; i++) {
        result = result & C_BDD (i, ((iEme & 1) == 0) ? false : true) ;
        iEme >>= 1 ;
      }
    }
  }else{
    result = ~ result ;
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    uint64_t nd0 = 0UL ;
    uint64_t nc0 = 0UL ; // Non utilise ici
    internalValueCount64 (gNodeArray [nodeIndex].mELSE ^ complement, inVariableCount - 1, nd0, nc0 COMMA_HERE) ;
    uint64_t nd1 = 0UL ;
    uint64_t nc1 = 0UL ; // Non utilise ici
    internalValueCount64 (gNodeArray [nodeIndex].mTHEN ^ complement, inVariableCount - 1, nd1, nc1 COMMA_HERE) ;
    uint64_t total = nd0 + nd1 ;
    for (uint32_t i = (uint32_t) (inVariableCount-1) ; i>var ; i--) {
      total >>= 1 ;
      nd0 >>= 1 ;
    }
    iEme = inNthBDDvalue % total ;
    uint64_t quotient = inNthBDDvalue / total ;
    for (uint32_t j = (uint32_t) (var+1) ; j<inVariableCount ; j++) {
      result = result & C_BDD (j, ((quotient & 1) == 0) ? false : true) ;
      quotient >>= 1 ;
    }
    if (iEme < nd0) {
      result = result & C_BDD (var, false) & obtenirIemeBDDinterne (gNodeArray [nodeIndex].mELSE ^ complement, iEme, var) ;
    }else if (iEme < total) {
      result = result & C_BDD (var, true) & obtenirIemeBDDinterne (gNodeArray [nodeIndex].mTHEN ^ complement, iEme - nd0, var) ;
    }else{
      result = C_BDD () ; // Vide
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::getNthBDD (const uint64_t inNthBDDvalue,
                        const uint32_t inVariableCount) const {
  return obtenirIemeBDDinterne (mBDDvalue, inNthBDDvalue, inVariableCount) ;
}


//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD range
#endif

//--------------------------------------------------------------------------------------------------

static uint64_t rangBDDinterne (const uint32_t inValue,
                                const uint32_t valeurTestee,
                                const uint32_t inVariableCount) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  const uint32_t testedValueNodeIndex = nodeIndexForRoot (valeurTestee COMMA_HERE) ;
  const uint32_t complementValeurTestee = valeurTestee & 1 ;
  const uint32_t complement = inValue & 1 ;
  uint64_t rang = 0 ;
  uint64_t nc ; // non utilise
  if (bothBranches (gNodeArray [testedValueNodeIndex]) == 0) {
  }else if ((gNodeArray [testedValueNodeIndex].mELSE ^ complementValeurTestee) == 0) {
    if ((gNodeArray [nodeIndex].mTHEN == 0) && (gNodeArray [nodeIndex].mELSE == 0)) {
      rang = 1UL << gNodeArray [testedValueNodeIndex].mVariableIndex ;
      rang += rangBDDinterne (inValue, gNodeArray [testedValueNodeIndex].mTHEN ^ complementValeurTestee, inVariableCount - 1) ;
    }else if (gNodeArray [nodeIndex].mVariableIndex == gNodeArray [testedValueNodeIndex].mVariableIndex) {
      internalValueCount64 (gNodeArray [nodeIndex].mELSE ^ complement, inVariableCount - 1, rang, nc COMMA_HERE) ;
      rang += rangBDDinterne (gNodeArray [nodeIndex].mTHEN ^ complement, gNodeArray [testedValueNodeIndex].mTHEN ^ complementValeurTestee, inVariableCount - 1) ;
    }else{
      internalValueCount64 (inValue, inVariableCount - 1, rang, nc COMMA_HERE) ;
      rang += rangBDDinterne (inValue, gNodeArray [testedValueNodeIndex].mTHEN ^ complementValeurTestee, inVariableCount - 1) ;
    }
  }else{
    if ((gNodeArray [nodeIndex].mTHEN == 0) && (gNodeArray [nodeIndex].mELSE == 0)) {
      rang = rangBDDinterne (inValue, gNodeArray [testedValueNodeIndex].mELSE ^ complementValeurTestee, inVariableCount - 1) ;
    }else if (gNodeArray [nodeIndex].mVariableIndex == gNodeArray [testedValueNodeIndex].mVariableIndex) {
      rang = rangBDDinterne (gNodeArray [nodeIndex].mELSE ^ complement, gNodeArray [testedValueNodeIndex].mELSE ^ complementValeurTestee, inVariableCount - 1) ;
    }else{
      rang = rangBDDinterne (inValue, gNodeArray [testedValueNodeIndex].mELSE ^ complementValeurTestee, inVariableCount - 1) ;
    }
  }
  return rang ;
}

//--------------------------------------------------------------------------------------------------

uint64_t C_BDD::getBDDrange (const C_BDD & inOperand,
                             const uint32_t inVariableCount) const {
  uint64_t rang = 0 ;
  if (inOperand.valueCount64 (inVariableCount) == 1) {
    rang = rangBDDinterne (mBDDvalue, inOperand.mBDDvalue, inVariableCount) ;
  }
  return rang ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Cache for Single Operand Operations
#endif

//--------------------------------------------------------------------------------------------------

static const int32_t kSingleOperandOperationCacheInitialSize = 131101 ;

//--------------------------------------------------------------------------------------------------

class tStructSingleOperandOperationCacheEntry {
  public: uint32_t mOperand ;
  public: uint32_t mResult ;
} ;

//--------------------------------------------------------------------------------------------------

static tStructSingleOperandOperationCacheEntry * gSingleOperandOperationCacheMap ;
static uint32_t gSingleOperandOperationMapSize ;
static uint32_t gSingleOperandOperationCacheMapUsedEntryCount ;
static uint64_t gSingleOperandOperationCacheTrivialOperationCount ;
static uint32_t gSingleOperandOperationCacheMaxPowerOfTwoSize = 31 ;
static bool gSingleOperandOperationCacheExpandable = true ;

//--------------------------------------------------------------------------------------------------

uint32_t singleOperandOperationCacheMemoryUsage (void) {
  return (gSingleOperandOperationMapSize * (uint32_t) sizeof (uint64_t)) / 1000000 ;
}

//--------------------------------------------------------------------------------------------------

void releaseSingleOperandOperationCache (void) {
  gSingleOperandOperationCacheMapUsedEntryCount = 0 ;
  macroMyDeletePODArray (gSingleOperandOperationCacheMap) ;
  gSingleOperandOperationCacheExpandable = true ;
}

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

static void reallocSingleOperandOperationCache (const uint32_t inNewSize) {
  gSingleOperandOperationCacheMapUsedEntryCount = 0 ;
  tStructSingleOperandOperationCacheEntry * newCache = nullptr ;
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

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

void C_BDD::setSingleOperandOperationCacheMaxSize (const uint32_t inPowerOfTwo) {
  gSingleOperandOperationCacheMaxPowerOfTwoSize = inPowerOfTwo ;
  if (C_BDD::displaysInformationMessages ()) {
    printf ("BDD package info: single operand operation cache max size limited < 2 ** %u\n", gSingleOperandOperationCacheMaxPowerOfTwoSize) ;
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Forall Operation
#endif

//--------------------------------------------------------------------------------------------------

static uint32_t internalForAllOnBitRange (const uint32_t inValue,
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
      if (! cacheSuccess) {
        result = find_or_add (var,
          internalForAllOnBitRange (gNodeArray [nodeIndex].mELSE ^ complement, inFirstBit, inBitCount),
          internalForAllOnBitRange (gNodeArray [nodeIndex].mTHEN ^ complement, inFirstBit, inBitCount) COMMA_HERE) ;
      }
    }else if (var >= inFirstBit) {
      result = internalANDoperation (
         internalForAllOnBitRange (gNodeArray [nodeIndex].mELSE ^ complement, inFirstBit, inBitCount),
         internalForAllOnBitRange (gNodeArray [nodeIndex].mTHEN ^ complement, inFirstBit, inBitCount)) ;
    }else{
      result = inValue ;
      gSingleOperandOperationCacheTrivialOperationCount ++ ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

static uint32_t operationQuelqueSoitSurBitSupNumeroInterne (const uint32_t inValue,
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

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::forallOnBitNumber (const uint32_t numeroBit) const {
  clearSingleOperandOperationCache () ;
  return C_BDD (internalForAllOnBitRange (mBDDvalue, numeroBit, 1)) ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::forallOnBitsAfterNumber (const uint32_t numeroBit) const {
  clearSingleOperandOperationCache () ;
  return C_BDD (operationQuelqueSoitSurBitSupNumeroInterne (mBDDvalue, numeroBit)) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Exist Operation
#endif

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::existsOnBitNumber (const uint32_t numeroBit) const {
  clearSingleOperandOperationCache () ;
//--- ilExiste x : F <=> non (quelquesoit x : non (F))
  return C_BDD (internalForAllOnBitRange (mBDDvalue ^ 1, numeroBit, 1) ^ 1) ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::existsOnBitRange (const uint32_t inFirstBit,
                               const uint32_t inBitCount) const {
  clearSingleOperandOperationCache () ;
  return C_BDD (internalForAllOnBitRange (mBDDvalue ^ 1, inFirstBit, inBitCount) ^ 1) ;
}

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::existsOnBitsAfterNumber (const uint32_t numeroBit) const {
// ilExiste x : F <=> non (quelquesoit x : non (F))
  clearSingleOperandOperationCache () ;
  return C_BDD (operationQuelqueSoitSurBitSupNumeroInterne (mBDDvalue ^ 1, numeroBit) ^ 1) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Substitute variables
#endif

//--------------------------------------------------------------------------------------------------

static uint32_t internalRecursiveSubstitution (const uint32_t inValue,
                                               const uint32_t * vecteurSubstitutionBool,
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
    macroAssertThere (var < inBDDvariablesCount, "var (%lld) < inBDDvariablesCount (%lld)", var, inBDDvariablesCount) ;
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

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::substitution (const uint32_t * inSubstitutionArray,
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
  return C_BDD (estIdentite ? mBDDvalue : internalRecursiveSubstitution (mBDDvalue, inSubstitutionArray, noChangeIndex, inBDDvariablesCount COMMA_THERE)) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Translate BDD variables
#endif

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::translate (const uint32_t inBDDvariablesCount,
                        const uint32_t inTranslation) const {
  uint32_t * substitionVector = nullptr ;
  macroMyNewArray (substitionVector, uint32_t, inBDDvariablesCount) ;
  for (uint32_t i=0 ; i<inBDDvariablesCount ; i++) {
    substitionVector [i] = (uint32_t) (i + inTranslation) ;
  }
  const uint32_t result = internalRecursiveSubstitution (mBDDvalue, substitionVector, 0, inBDDvariablesCount COMMA_HERE) ;
  macroMyDeleteArray (substitionVector) ;
  return C_BDD (result) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Exchange Variables
#endif

//--------------------------------------------------------------------------------------------------

static uint32_t internalExchangeVariables (const uint32_t inValue,
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

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::exchangeVariables (const uint32_t var1, const uint32_t var2) const {
  C_BDD result (mBDDvalue) ;
  if (var1 > var2) {
    result.mBDDvalue = internalExchangeVariables (mBDDvalue, var1, var2) ;
  }else if (var1 < var2) {
    result.mBDDvalue = internalExchangeVariables (mBDDvalue, var2, var1) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Roll Down
#endif

//--------------------------------------------------------------------------------------------------

static uint32_t internalRollDown (const uint32_t inValue,
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

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::rollDownVariables (const uint32_t var1, const uint32_t var2) const {
  C_BDD result (mBDDvalue) ;
  if (var1 > var2) {
    result.mBDDvalue = internalRollDown (mBDDvalue, var1, var2) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Roll Up
#endif

//--------------------------------------------------------------------------------------------------

static uint32_t internalRollUp (const uint32_t inValue,
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

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::
rollUpVariables (const uint32_t var1, const uint32_t var2) const {
  C_BDD result (mBDDvalue) ;
  if (var1 > var2) {
    result.mBDDvalue = internalRollUp (mBDDvalue, var1, var2) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Left shift
#endif

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::bddByLeftShifting (const uint32_t inLeftShiftCount) const {
  clearSingleOperandOperationCache () ;
  C_BDD result ;
  result.mBDDvalue = internalLeftShift (mBDDvalue, inLeftShiftCount) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Right shift
#endif

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

C_BDD C_BDD::bddByRightShifting (const uint32_t inRightShiftCount) const {
  clearSingleOperandOperationCache () ;
  C_BDD result ;
  result.mBDDvalue = internalRightShift (mBDDvalue, inRightShiftCount) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

uint32_t C_BDD::getBDDnodeSize (void) {
  return (uint32_t) sizeof (cBDDnode) ;
}

//--------------------------------------------------------------------------------------------------

static uint32_t * gCollisionMap = nullptr ;
static uint32_t gCollisionMapSize = 0 ;
static uint32_t gHashMapPowerOfTwoMaxSize = 31 ;
static bool gHashMapExpandable = true ;

//--------------------------------------------------------------------------------------------------

uint32_t hashMapMemoryUsage (void) {
  return (uint32_t) ((gCollisionMapSize * sizeof (uint32_t)) / 1000000) ;
}

//--------------------------------------------------------------------------------------------------

inline uint64_t nodeHashCode (const cBDDnode inNode) {
  uint64_t result = bothBranches (inNode) % (uint64_t) gCollisionMapSize ;
  result <<= 32 ;
  result = (result | inNode.mVariableIndex) % (uint64_t) gCollisionMapSize ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

static void reallocHashMap (const uint32_t inNewSize) {
  if ((0 < inNewSize) && (inNewSize != gCollisionMapSize)) {
    if (C_BDD::displaysInformationMessages ()) {
      printf ("BDD package info: hash map reallocated to %u %03u %03u (%u MB)\n",
              inNewSize / 1000000, (inNewSize / 1000) % 1000, inNewSize % 1000,
              (inNewSize * (uint32_t) sizeof (uint32_t)) / 1000000) ;
    }
    if (gCollisionMap == nullptr) {
      macroMyNewPODArray (gCollisionMap, uint32_t, inNewSize) ;
    }else{
      macroMyReallocPODArray (gCollisionMap, uint32_t, inNewSize) ;
    }
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

//--------------------------------------------------------------------------------------------------

static const uint32_t kUniqueMapSizeIncrement = 4194304 ;

//--------------------------------------------------------------------------------------------------

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
    if (gNodeArray == nullptr) {
      macroMyNewPODArray (gNodeArray, cBDDnode, newSize) ;
    }else{
      macroMyReallocPODArray (gNodeArray, cBDDnode, newSize) ;
    }
    if (gMarkTable == nullptr) {
      macroMyNewPODArray (gMarkTable, uint64_t, newSize >> 6) ;
    }else{
      macroMyReallocPODArray (gMarkTable, uint64_t, newSize >> 6) ;
    }
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

//--------------------------------------------------------------------------------------------------

void C_BDD::unmarkAllExistingBDDnodes (void) {
  macroAssert ((gNodeArraySize % 64) == 0, "gNodeArraySize (%lld) is not a multiple of 64", gNodeArraySize, 0) ;
  for (uint32_t i=0 ; i<(gNodeArraySize >> 6) ; i++) {
    gMarkTable [i] = 0 ;
  }
}

//--------------------------------------------------------------------------------------------------

static bool isNodeMarked (const uint32_t inValue COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  bool marked = nodeIndex == 0 ;
  if (! marked) {
    macroAssertThere (nodeIndex > 0, "nodeIndex (%lld) should be > 0", nodeIndex, 0) ;
    macroAssertThere (nodeIndex <= gCurrentNodeCount, "nodeIndex (%lld) should be <= gCurrentNodeCount (%lld)", nodeIndex, gCurrentNodeCount) ;
    const uint64_t mask = 1ULL << (nodeIndex & 0x3F) ;
    const uint32_t idx = nodeIndex >> 6 ;
    marked = (gMarkTable [idx] & mask) != 0 ;
  }
  return marked ;
}

//--------------------------------------------------------------------------------------------------

bool isNodeMarkedThenMark (const uint32_t inValue COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = inValue >> 1 ;
  macroAssertThere (nodeIndex > 0, "nodeIndex (%lld) should be > 0", nodeIndex, 0) ;
  macroAssertThere (nodeIndex <= gCurrentNodeCount, "nodeIndex (%lld) should be <= gCurrentNodeCount (%lld)", nodeIndex, gCurrentNodeCount) ;
  const uint64_t mask = 1ULL << (nodeIndex & 0x3F) ;
  const uint32_t idx = nodeIndex >> 6 ;
  const bool isMarked = (gMarkTable [idx] & mask) != 0 ;
  gMarkTable [idx] |= mask ;
  return isMarked ;
}

//--------------------------------------------------------------------------------------------------

void markNode (const uint32_t inValue) {
  const uint32_t nodeIndex = inValue >> 1 ;
  macroAssert (nodeIndex > 0, "nodeIndex (%lld) should be > 0", nodeIndex, 0) ;
  macroAssert (nodeIndex <= gCurrentNodeCount, "nodeIndex (%lld) should be <= gCurrentNodeCount (%lld)", nodeIndex, gCurrentNodeCount) ;
  const uint64_t mask = 1ULL << (nodeIndex & 0x3F) ;
  const uint32_t idx = nodeIndex >> 6 ;
  gMarkTable [idx] |= mask ;
}

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------
//
//  BDD objects hash map
//
//--------------------------------------------------------------------------------------------------

static const int32_t kInitialCollisionMapPowerOfTwoSize = 20 ;

//--------------------------------------------------------------------------------------------------
//
//       BDD unique table implementation
//
//--------------------------------------------------------------------------------------------------

uint32_t find_or_add (const uint32_t inBoolVar,
                      const uint32_t inELSEbranch,
                      const uint32_t inTHENbranch
                      COMMA_UNUSED_LOCATION_ARGS) {
  uint32_t result = inELSEbranch ;
  if (inELSEbranch != inTHENbranch) {
    if (0 == gCollisionMapSize) {
      reallocHashMap (getPrimeGreaterThan (1U << kInitialCollisionMapPowerOfTwoSize)) ;
    }
    const uint32_t complement = inELSEbranch & 1 ;
    const uint32_t c1 = inTHENbranch ^ complement ;
    const uint32_t c0 = inELSEbranch ^ complement ;
    const cBDDnode candidateNode = {c1, c0, inBoolVar, 0} ;
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
    result = (nodeIndex << 1) | complement ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::setHashMapMaxSize (const uint32_t inPowerOfTwoSize) {
  gHashMapPowerOfTwoMaxSize = inPowerOfTwoSize ;
  if (C_BDD::displaysInformationMessages ()) {
    printf ("BDD package info: hash map max size limited < 2 ** %u\n", gHashMapPowerOfTwoMaxSize) ;
  }
}

//--------------------------------------------------------------------------------------------------

static C_BDD * gFirstBDD = nullptr ;
static C_BDD * gLastBDD = nullptr ;

//--------------------------------------------------------------------------------------------------

uint32_t C_BDD::getBDDinstancesCount (void) {
  uint32_t n = 0 ;
  C_BDD * p = gFirstBDD ;
  while (p != nullptr) {
    n ++ ;
    p = p->mPtrToNextBDD ;
  }
  return n ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Mark and Sweep
#endif

//--------------------------------------------------------------------------------------------------

static void recursiveMarkBDDNodes (const uint32_t inValue) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  if ((nodeIndex > 0) && ! isNodeMarkedThenMark (inValue COMMA_HERE)) {
    if (bothBranches (gNodeArray [nodeIndex]) != 0) {
      recursiveMarkBDDNodes (gNodeArray [nodeIndex].mTHEN) ;
      recursiveMarkBDDNodes (gNodeArray [nodeIndex].mELSE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void C_BDD::markAllBDDnodes (void) {
  recursiveMarkBDDNodes (mBDDvalue) ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::markAndSweepUnusedNodes (void) {
  Timer timer ;
//--- Clear operation caches
  clearANDOperationCache () ;
//--- Effacer tous les champs marquage des elements BDD existants
  unmarkAllExistingBDDnodes () ;
//--- Marquer tous les elements utilises
  C_BDD * p = gFirstBDD ;
  while (p != nullptr) {
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
  for (uint32_t i=1 ; i<=unchangedNodeCount ; i++) {
    gNodeArray [i].mAuxiliary = i ;
  }
  uint32_t newNodeCount = unchangedNodeCount ;
  for (uint32_t nodeIndex=unchangedNodeCount+1 ; nodeIndex<=gCurrentNodeCount ; nodeIndex++) {
    if (isNodeMarked (nodeIndex << 1 COMMA_HERE)) { // Node is used
      const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
      const uint32_t thenBranch = gNodeArray [nodeIndex].mTHEN ;
      const uint32_t elseBranch = gNodeArray [nodeIndex].mELSE ;
      macroAssert ((thenBranch >> 1) < nodeIndex, "(thenBranch [%lld] >> 1) < nodeIndex [%lld]", thenBranch >> 1, nodeIndex) ;
      macroAssert ((elseBranch >> 1) < nodeIndex, "(elseBranch [%lld] >> 1) < nodeIndex [%lld]", elseBranch >> 1, nodeIndex) ;
      const uint32_t newThenBranch = (gNodeArray [thenBranch >> 1].mAuxiliary << 1) | (thenBranch & 1) ;
      const uint32_t newElseBranch = (gNodeArray [elseBranch >> 1].mAuxiliary << 1) | (elseBranch & 1) ;
      newNodeCount ++ ;
      gNodeArray [newNodeCount].mTHEN = newThenBranch ;
      gNodeArray [newNodeCount].mELSE = newElseBranch ;
      gNodeArray [newNodeCount].mVariableIndex = var ;
      gNodeArray [nodeIndex].mAuxiliary = newNodeCount ;
    }
  }
  const uint32_t previousNodeCount = gCurrentNodeCount ;
  if (gNodeArraySize > 0) {
    gCurrentNodeCount = newNodeCount ;
    p = gFirstBDD ;
    while (p != nullptr) {
      const uint32_t previousValue = p->mBDDvalue ;
      macroAssert ((gNodeArray [previousValue >> 1].mAuxiliary) <= (previousValue >> 1), "(elseBranch [%lld] >> 1) <= nodeIndex [%lld]", (gNodeArray [previousValue >> 1].mAuxiliary), previousValue >> 1) ;
      p->mBDDvalue = (gNodeArray [previousValue >> 1].mAuxiliary << 1) | (previousValue & 1) ;
      p = p->mPtrToNextBDD ;
    }
  }
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
    gCout.appendCString ("BDD package info: mark and sweep done in ") ;
    gCout.appendString (timer.timeString ()) ;
    gCout.appendCString (" (nodes ") ;
    gCout.appendUnsigned (previousNodeCount) ;
    gCout.appendCString (" -> ") ;
    gCout.appendUnsigned (gCurrentNodeCount) ;
    gCout.appendCString (")\n") ;
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD constructors, destructor, assignment
#endif

//--------------------------------------------------------------------------------------------------

C_BDD::C_BDD (void) :
mBDDvalue (0),
mPtrToPreviousBDD (nullptr),
mPtrToNextBDD (nullptr) {
  initLinks () ;
}

//--------------------------------------------------------------------------------------------------

C_BDD::C_BDD (const uint32_t inValue) :
mBDDvalue (inValue),
mPtrToPreviousBDD (nullptr),
mPtrToNextBDD (nullptr) {
  initLinks () ;
}

//--------------------------------------------------------------------------------------------------

C_BDD::C_BDD (const uint32_t variable,
              const bool inSign) :
mBDDvalue (0),
mPtrToPreviousBDD (nullptr),
mPtrToNextBDD (nullptr) {
  initLinks () ;
  const uint32_t complement = inSign ? 0U : 1U ;
  mBDDvalue = find_or_add (variable, complement, complement ^ 1 COMMA_HERE) ;
}

//--------------------------------------------------------------------------------------------------

C_BDD::C_BDD (const C_BDD & inSource) :
mBDDvalue (inSource.mBDDvalue),
mPtrToPreviousBDD (nullptr),
mPtrToNextBDD (nullptr) {
  initLinks () ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::initLinks (void) {
  if (gFirstBDD == nullptr) {
    gLastBDD = this ;
  }else{
    gFirstBDD->mPtrToPreviousBDD = this ;
  }
  mPtrToNextBDD = gFirstBDD ;
  gFirstBDD = this ;
}

//--------------------------------------------------------------------------------------------------

C_BDD::~C_BDD (void) {
  mBDDvalue = 0 ;
  if (mPtrToPreviousBDD == nullptr) {
    gFirstBDD = gFirstBDD->mPtrToNextBDD ;
  }else{
    mPtrToPreviousBDD->mPtrToNextBDD = mPtrToNextBDD ;
  }
  if (mPtrToNextBDD == nullptr) {
    gLastBDD = gLastBDD->mPtrToPreviousBDD ;
  }else{
    mPtrToNextBDD->mPtrToPreviousBDD = mPtrToPreviousBDD ;
  }
}

//--------------------------------------------------------------------------------------------------

C_BDD & C_BDD::operator = (const C_BDD & inSource) {
  mBDDvalue = inSource.mBDDvalue ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Check all BDDs are well-formed
#endif

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

void C_BDD::checkAllBDDsAreWellFormed (LOCATION_ARGS) {
//--- Unmark all nodes
  unmarkAllExistingBDDnodes () ;
//--- Check BDDs
  C_BDD * p = gFirstBDD ;
  while (p != nullptr) {
    internalCheckBDDIsWellFormed (p->mBDDvalue, UINT16_MAX COMMA_THERE) ;
    p = p->mPtrToNextBDD ;
  }
}

//--------------------------------------------------------------------------------------------------

void C_BDD::checkBDDIsWellFormed (LOCATION_ARGS) {
//--- Unmark all nodes
  unmarkAllExistingBDDnodes () ;
//--- Check BDD
  internalCheckBDDIsWellFormed (mBDDvalue, UINT16_MAX COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Memory Usage
#endif

//--------------------------------------------------------------------------------------------------

uint32_t C_BDD::currentMemoryUsage (void) {
  uint32_t result = nodeMapMemoryUsage () ;
  result += hashMapMemoryUsage () ;
  result += ANDCacheMemoryUsage () ;
  result += singleOperandOperationCacheMemoryUsage () ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

static uint32_t gMaximumMemoryUsage = UINT32_MAX ;

//--------------------------------------------------------------------------------------------------

uint32_t C_BDD::maximumMemoryUsage (void) { // In MB
  return gMaximumMemoryUsage ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::setMaximumMemoryUsage (const uint32_t inMaxMemoryUsage) { // In MB
  gMaximumMemoryUsage = inMaxMemoryUsage ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD Package stats
#endif

//--------------------------------------------------------------------------------------------------

void C_BDD::printBDDpackageOperationsSummary (AbstractOutputStream & inStream) {
  #ifdef __LP64__
    const uint32_t mode = 64 ;
  #else
    const uint32_t mode = 32 ;
  #endif
  inStream.appendCString ("\n" "Statistics about BDD package (") ;
  inStream.appendUnsigned (mode) ;
  inStream.appendCString ("-bit mode, ") ;
  inStream.appendUnsigned (getBDDnodeSize ()) ;
  inStream.appendCString (" bytes for a BDD node)\n") ;
  inStream.appendCString ("  Current BDD count: ") ;
  inStream.appendUnsigned (getBDDinstancesCount ()) ;
  inStream.appendCString ("\n") ;
  inStream.appendCString ("  Created nodes count: ") ;
  inStream.appendUnsigned (getCreatedNodesCount ()) ;
  inStream.appendNewLine () ;
  inStream.appendCString ("  RAM usage: ") ;
  inStream.appendUnsigned (currentMemoryUsage ()) ;
  inStream.appendCString (" MB\n") ;
//---
  inStream.appendCString ("Unique table:\n") ;
  inStream.appendCString ("  size: ") ;
  inStream.appendUnsigned (gCollisionMapSize) ;
  inStream.appendCString (" (") ;
  inStream.appendUnsigned ((gCollisionMapSize * sizeof (uint32_t)) / 1000000) ;
  inStream.appendCString (" MB)\n") ;
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
      entrySizeArray.forceObjectAtIndex (length, 1, 0) ;
    }
  }
  for (int32_t i=0 ; i<entrySizeArray.count () ; i++) {
    if ((entrySizeArray (i COMMA_HERE) > 0) && (gCollisionMapSize > 0)) {
      inStream.appendCString ("  ") ;
      inStream.appendUnsigned (entrySizeArray (i COMMA_HERE)) ;
      inStream.appendCString (" entries of size ") ;
      inStream.appendSigned (i) ;
      inStream.appendCString (" (") ;
      inStream.appendUnsigned ((100UL * entrySizeArray (i COMMA_HERE)) / gCollisionMapSize) ;
      inStream.appendCString ("%)\n") ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

static void
parcoursBDDinterneParValeur (const uint32_t inValue,
                             C_bdd_value_traversing & inTraversing,
                             bool * tableauDesValeurs,
                             uint32_t variableCourante,
                             const uint32_t inVariableCount) {
  if (variableCourante != 0) {
    variableCourante -- ;
    if (inValue == 1) {
      tableauDesValeurs [variableCourante] = false ;
      parcoursBDDinterneParValeur (inValue, inTraversing, tableauDesValeurs, variableCourante, inVariableCount) ;
      tableauDesValeurs [variableCourante] = true ;
      parcoursBDDinterneParValeur (inValue, inTraversing, tableauDesValeurs, variableCourante, inVariableCount) ;
    }else if (inValue != 0) {
      const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
      const uint32_t variable = gNodeArray [nodeIndex].mVariableIndex ;
      if (variable == variableCourante) {
        const uint32_t complement = inValue & 1 ;
        tableauDesValeurs [variableCourante] = false ;
        parcoursBDDinterneParValeur (gNodeArray [nodeIndex].mELSE ^ complement, inTraversing, tableauDesValeurs, variableCourante, inVariableCount) ;
        tableauDesValeurs [variableCourante] = true ;
        parcoursBDDinterneParValeur (gNodeArray [nodeIndex].mTHEN ^ complement, inTraversing, tableauDesValeurs, variableCourante, inVariableCount) ;
      }else if (variable < variableCourante) {
        tableauDesValeurs [variableCourante] = false ;
        parcoursBDDinterneParValeur (inValue, inTraversing, tableauDesValeurs, variableCourante, inVariableCount) ;
        tableauDesValeurs [variableCourante] = true ;
        parcoursBDDinterneParValeur (inValue, inTraversing, tableauDesValeurs, variableCourante, inVariableCount) ;
      }
    }
  }else if (inValue == 1) {
    inTraversing.action (tableauDesValeurs, inVariableCount) ;
  }
}

//--------------------------------------------------------------------------------------------------

void C_BDD::traverseBDDvalues (C_bdd_value_traversing & inTraversing,
                               const uint32_t inVariableCount) const {
  bool * tableauDesValeurs = nullptr ;
  macroMyNewArray (tableauDesValeurs, bool, inVariableCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, inTraversing, tableauDesValeurs, inVariableCount, inVariableCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build an array of uint64_t values
#endif

//--------------------------------------------------------------------------------------------------

class C_build_values64_array : public C_bdd_value_traversing {
  private: TC_UniqueArray <uint64_t> * mPtr ;

  public: inline C_build_values64_array (TC_UniqueArray <uint64_t> * inPtr) :
  mPtr (inPtr) {
  }

//--- No copy
  private: C_build_values64_array (const C_build_values64_array &) ;
  private: C_build_values64_array & operator = (const C_build_values64_array &) ;

//--- Virtual method called for every value
  public: virtual void action (const bool * tableauDesValeurs,
                               const uint32_t inVariableCount) ;
} ;

//--------------------------------------------------------------------------------------------------

void C_build_values64_array::action (const bool * tableauDesValeurs,
                                     const uint32_t inVariableCount) {
  uint64_t value = 0 ;
  for (uint32_t i=1 ; i<=inVariableCount ; i++) {
    value = (value << 1) | tableauDesValeurs [inVariableCount - i] ;
  }
  mPtr->appendObject (value) ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::buildValue64Array (TC_UniqueArray <uint64_t> & outValuesArray,
                               const uint32_t inVariableCount) const {
  macroAssert(inVariableCount < 64, "inVariableCount == %ld >= 64", (int64_t) inVariableCount, 0) ;
  outValuesArray.removeAllKeepingCapacity () ;
  C_build_values64_array builder (& outValuesArray) ;
  bool * tableauDesValeurs = nullptr ;
  macroMyNewArray (tableauDesValeurs, bool, inVariableCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, builder, tableauDesValeurs, inVariableCount, inVariableCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build an array of bool array values
#endif

//--------------------------------------------------------------------------------------------------

class C_build_values_array : public C_bdd_value_traversing {
  private: TC_UniqueArray <TC_Array <bool> > * mPtr ;

  public: inline C_build_values_array (TC_UniqueArray <TC_Array <bool> > * inPtr) :
  mPtr (inPtr) {
  }

//--- No copy
  private: C_build_values_array (const C_build_values_array &) ;
  private: C_build_values_array & operator = (const C_build_values_array &) ;

//--- Virtual method called for every value
  public: virtual void action (const bool * tableauDesValeurs,
                               const uint32_t inVariableCount) ;
} ;

//--------------------------------------------------------------------------------------------------

void C_build_values_array::action (const bool * tableauDesValeurs,
                                   const uint32_t inVariableCount) {
  TC_Array <bool> value ;
  for (uint32_t i=0 ; i<inVariableCount ; i++) {
    value.appendObject (tableauDesValeurs [i]) ;
  }
  mPtr->appendObject (value) ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::buildValueArray (TC_UniqueArray <TC_Array <bool> > & outValuesArray,
                             const uint32_t inVariableCount) const {
  outValuesArray.removeAllKeepingCapacity () ;
  C_build_values_array builder (& outValuesArray) ;
  bool * tableauDesValeurs = nullptr ;
  macroMyNewArray (tableauDesValeurs, bool, inVariableCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, builder, tableauDesValeurs, inVariableCount, inVariableCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build an array of string values
#endif

//--------------------------------------------------------------------------------------------------

class cLittleEndianStringValueBuilder : public C_bdd_value_traversing {
  private: TC_UniqueArray <String> * mPtr ;

  public: cLittleEndianStringValueBuilder (TC_UniqueArray <String> * inPtr) :
  mPtr (inPtr) {
  }

//--- No copy
  private: cLittleEndianStringValueBuilder (const cLittleEndianStringValueBuilder &) ;
  private: cLittleEndianStringValueBuilder & operator = (const cLittleEndianStringValueBuilder &) ;

//--- Virtual method called for every value
  public: virtual void action (const bool * tableauDesValeurs,
                               const uint32_t inVariableCount) ;
} ;

//--------------------------------------------------------------------------------------------------

void cLittleEndianStringValueBuilder::
action (const bool * tableauDesValeurs,
        const uint32_t inVariableCount) {
  String value ;
  for (uint32_t i=0 ; i<inVariableCount ; i++) {
    value.appendASCIIChar ((char) ('0' + tableauDesValeurs [i])) ;
  }
  mPtr->appendObject (value) ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::
buildLittleEndianStringValueArray (TC_UniqueArray <String> & outValuesArray,
                                   const uint32_t inVariableCount) const {
  outValuesArray.removeAllKeepingCapacity () ;
  cLittleEndianStringValueBuilder builder (& outValuesArray) ;
  bool * tableauDesValeurs = nullptr ;
  macroMyNewArray (tableauDesValeurs, bool, inVariableCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, builder, tableauDesValeurs, inVariableCount, inVariableCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//--------------------------------------------------------------------------------------------------

class cBuildBigEndianStringValueArray : public C_bdd_value_traversing {
  private: TC_UniqueArray <String> * mPtr ;

  public: cBuildBigEndianStringValueArray (TC_UniqueArray <String> * inPtr) :
  mPtr (inPtr) {
  }

//--- No copy
  private: cBuildBigEndianStringValueArray (const cBuildBigEndianStringValueArray &) ;
  private: cBuildBigEndianStringValueArray & operator = (const cBuildBigEndianStringValueArray &) ;

//--- Virtual method called for every value
  public: virtual void action (const bool * tableauDesValeurs,
                                const uint32_t inVariableCount) ;
} ;

//--------------------------------------------------------------------------------------------------

void cBuildBigEndianStringValueArray::action (const bool * tableauDesValeurs,
                                              const uint32_t inVariableCount) {
  String value ;
  for (uint32_t i=inVariableCount ; i>0 ; i--) {
    value.appendASCIIChar (char ('0' + tableauDesValeurs [i-1])) ;
  }
  mPtr->appendObject (value) ;
}

//--------------------------------------------------------------------------------------------------

void C_BDD::buildBigEndianStringValueArray (TC_UniqueArray <String> & outValuesArray,
                                            const uint32_t inVariableCount) const {
  outValuesArray.removeAllKeepingCapacity () ;
  cBuildBigEndianStringValueArray builder (& outValuesArray) ;
  bool * tableauDesValeurs = nullptr ;
  macroMyNewArray (tableauDesValeurs, bool, inVariableCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, builder, tableauDesValeurs, inVariableCount, inVariableCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//--------------------------------------------------------------------------------------------------

class cBuildQueryString : public C_bdd_value_traversing {
  private: String * mStringPtr ;

  public: cBuildQueryString (String * inStringPtr) :
  mStringPtr (inStringPtr) {
  }

//--- No copy
  private: cBuildQueryString (const cBuildQueryString &) ;
  private: cBuildQueryString & operator = (const cBuildQueryString &) ;


//--- Virtual method called for every value
  public: virtual void action (const bool * tableauDesValeurs,
                               const uint32_t inVariableCount) ;
} ;

//--------------------------------------------------------------------------------------------------

void cBuildQueryString::action (const bool * tableauDesValeurs,
                                const uint32_t inVariableCount) {
  String value ;
  if (mStringPtr->length () > 0) {
    mStringPtr->appendCString ("|") ;
  }
  for (uint32_t i=inVariableCount ; i>0 ; i--) {
    mStringPtr->appendASCIIChar (char ('0' + tableauDesValeurs [i-1])) ;
  }
}

//--------------------------------------------------------------------------------------------------

String C_BDD::
queryStringValue (LOCATION_ARGS) const {
  String s ;
  if (isTrue ()) {
    s.appendCString ("X") ;
  }else if (! isFalse ()) {
    TC_UniqueArray <String> stringArray ;
    buildCompressedBigEndianStringValueArray (stringArray COMMA_THERE) ;
    if (stringArray.count () > 0) {
      s.appendString (stringArray (0 COMMA_HERE)) ;
      for (int32_t i=1 ; i<stringArray.count () ; i++) {
        s.appendCString ("|") ;
        s.appendString (stringArray (i COMMA_HERE)) ;
      }
    }
  }
  return s ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Cache for AND Operation
#endif

//--------------------------------------------------------------------------------------------------
//
//  And computation cache
//
//--------------------------------------------------------------------------------------------------

class tStructANDOperationCacheEntry {
  public: uint64_t mOperands ;
  public: uint32_t mResult ;
} ;

//--------------------------------------------------------------------------------------------------

static const int32_t kANDOperationCacheInitialSize = 262145 ;

//--------------------------------------------------------------------------------------------------

static uint64_t * gANDOperationCacheOperandMap ;
static uint32_t * gANDOperationCacheResultMap ;
static uint32_t gANDOperationMapSize ;
static uint32_t gANDOperationCacheMapUsedEntryCount ;
static uint64_t gANDOperationCacheTrivialOperationCount ;
static bool gANDOperationCacheExpandable = true ;
static uint32_t gANDOperationCacheMaxPowerOfTwoSize = 31 ;

//--------------------------------------------------------------------------------------------------

uint32_t ANDCacheMemoryUsage (void) {
  return (gANDOperationMapSize * (uint32_t) (sizeof (uint32_t) + sizeof (uint64_t))) / 1000000 ;
}

//--------------------------------------------------------------------------------------------------

void releaseANDOperationCache (void) {
  gANDOperationCacheMapUsedEntryCount = 0 ;
  macroMyDeletePODArray (gANDOperationCacheOperandMap) ;
  macroMyDeletePODArray (gANDOperationCacheResultMap) ;
  gANDOperationMapSize = 0 ;
  gANDOperationCacheExpandable = true ;
}

//--------------------------------------------------------------------------------------------------

void clearANDOperationCache (void) {
  gANDOperationCacheMapUsedEntryCount = 0 ;
  for (uint32_t i=0 ; i<gANDOperationMapSize ; i++) {
    gANDOperationCacheOperandMap [i] = 0 ;
  }
}

//--------------------------------------------------------------------------------------------------

static inline uint64_t getOperands (const uint32_t inOperand1,
                                    const uint32_t inOperand2) {
  uint64_t operands = inOperand1 ;
  operands <<= 32 ;
  operands |= inOperand2 ;
  return operands ;
}

//--------------------------------------------------------------------------------------------------

static bool searchInANDOperationCache (const uint32_t inOperand1,
                                       const uint32_t inOperand2,
                                       uint32_t & outResult) {
  if (0 == gANDOperationMapSize) {
    gANDOperationMapSize = kANDOperationCacheInitialSize ;
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

//--------------------------------------------------------------------------------------------------

static void reallocANDOperationCache (const uint32_t inNewSize) {
  if (0 < inNewSize) {
    gANDOperationCacheMapUsedEntryCount = 0 ;
    uint64_t * newCache = nullptr ;
    macroMyNewPODArray (newCache, uint64_t, inNewSize) ;
    for (uint32_t i=0 ; i<inNewSize ; i++) {
      newCache [i] = 0 ;
    }
    uint32_t * newResult = nullptr ;
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

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

void C_BDD::setANDOperationCacheMaxSize (const uint32_t inPowerOfTwo) {
  gANDOperationCacheMaxPowerOfTwoSize = inPowerOfTwo ;
  if (C_BDD::displaysInformationMessages ()) {
    printf ("BDD package info: AND cache max size limited < 2 ** %u\n", gANDOperationCacheMaxPowerOfTwoSize) ;
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark AND operation
#endif

//--------------------------------------------------------------------------------------------------
//
//                        Operation AND
//
//--------------------------------------------------------------------------------------------------

uint32_t internalANDoperation (const uint32_t opf,
                               const uint32_t opg) {
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
  return result ;
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------

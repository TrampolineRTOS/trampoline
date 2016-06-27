//
//  C_Relation.cpp
//  galgas-developer
//
//  Created by Pierre Molinaro on 22/05/14.
//  Copyright (c) 2014 IRCCyN. All rights reserved.
//
//----------------------------------------------------------------------------------------------------------------------

#include "bdd/C_Relation.h"
#include "utilities/C_SharedObject.h"

//----------------------------------------------------------------------------------------------------------------------

C_Relation::C_Relation (void) :
mConfiguration (),
mBDD () {
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation::C_Relation (const C_RelationConfiguration & inConfiguration,
                        const C_BDD inBDD) :
mConfiguration (inConfiguration),
mBDD (inBDD) {
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation::C_Relation (const C_RelationConfiguration & inConfiguration,
                        const bool inIsFull) :
mConfiguration (inConfiguration),
mBDD () {
  if (inIsFull) {
    mBDD.setToTrue () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation::C_Relation (const C_String & inVariableName,
                        const C_RelationSingleType & inVariableType,
                        const bool inIsFull) :
mConfiguration (),
mBDD () {
  if (inIsFull) {
    mBDD.setToTrue () ;
  }
  mConfiguration.addVariable (inVariableName, inVariableType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation::~C_Relation (void) {
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation::C_Relation (const C_Relation & inSource) :
mConfiguration (inSource.mConfiguration),
mBDD (inSource.mBDD) {
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation & C_Relation::operator = (const C_Relation & inSource) {
  if (this != & inSource) {
    mConfiguration = inSource.mConfiguration ;
    mBDD = inSource.mBDD ;
  }
  return *this ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Relation::addVariable (const C_String & inVariableName,
                              const C_RelationSingleType & inType) {
  mConfiguration.addVariable (inVariableName, inType) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Relation::appendConfiguration (const C_RelationConfiguration & inConfiguration) {
  mConfiguration.appendConfiguration (inConfiguration) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_RelationConfiguration C_Relation::configuration (void) const {
  return mConfiguration ;
}

//----------------------------------------------------------------------------------------------------------------------

C_BDD C_Relation::bdd (void) const {
  return mBDD ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Relation::setToEmpty (void) {
  mBDD.setToFalse () ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Relation::setToFull (void) {
  mBDD.setToTrue () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation::C_Relation (const C_RelationConfiguration & inConfiguration,
                        const int32_t inVariableIndex,
                        const C_BDD::compareEnum inComparaison,
                        const uint64_t inConstant
                        COMMA_LOCATION_ARGS) :
mConfiguration (inConfiguration),
mBDD () {
  mBDD = C_BDD::varCompareConst (inConfiguration.bddStartBitIndexForVariable (inVariableIndex COMMA_THERE),
                                 inConfiguration.bddBitCountForVariable (inVariableIndex COMMA_THERE),
                                 inComparaison,
                                 inConstant) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Relation::andWith (const C_Relation & inRelation COMMA_LOCATION_ARGS) {
  mConfiguration.checkIdenticalTo (inRelation.mConfiguration COMMA_THERE) ;
  mBDD &= inRelation.mBDD ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Relation::orWith (const C_Relation & inRelation COMMA_LOCATION_ARGS) {
  mConfiguration.checkIdenticalTo (inRelation.mConfiguration COMMA_THERE) ;
  mBDD |= inRelation.mBDD ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::andOp (const C_Relation & inRelation COMMA_LOCATION_ARGS) const {
  C_Relation result = *this ;
  result.andWith (inRelation COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::orOp (const C_Relation & inRelation COMMA_LOCATION_ARGS) const {
  C_Relation result = *this ;
  result.orWith (inRelation COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::operator ~ (void) const {
  C_Relation result = *this ;
  result.mBDD.negate () ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::accessibleStatesFrom (const C_Relation & inStartStates,
                                             int32_t * outIterationCount
                                             COMMA_LOCATION_ARGS) const {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    const int32_t startRelationVariableCount = inStartStates.variableCount () ;
    const int32_t accessibilityVariableCount = variableCount () ;
  #endif
  MF_AssertThere ((startRelationVariableCount + startRelationVariableCount) == accessibilityVariableCount,
                  "C_Relation::accessibleStatesFrom error: start state has %lld variables, accessibility relation has %lld variables",
                  (int64_t) startRelationVariableCount,
                  (int64_t) accessibilityVariableCount) ;
  return C_Relation (
    inStartStates.configuration(),
    mBDD.accessibleStates (inStartStates.mBDD, inStartStates.bitCount (), outIterationCount)
  ) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::transitiveClosure (int32_t * outIterationCount) const {
  return C_Relation (
    mConfiguration,
    mBDD.transitiveClosure (bitCount () / 2, outIterationCount)
  ) ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_Relation::containsValue (const int32_t inVariableIndex,
                                const uint64_t inValue
                                COMMA_LOCATION_ARGS) const {
  return mBDD.containsValue64 (inValue,
                               mConfiguration.bddStartBitIndexForVariable (inVariableIndex COMMA_THERE),
                               mConfiguration.bddBitCountForVariable (inVariableIndex COMMA_THERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Relation::getValueArray (TC_UniqueArray <uint64_t> & outArray) const {
  mBDD.buildValue64Array (outArray, mConfiguration.bitCount ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

uint64_t C_Relation::value64Count (void) const {
  return mBDD.valueCount64 (mConfiguration.bitCount ()) ;
}

//----------------------------------------------------------------------------------------------------------------------
//   getArray                                                                  *
//----------------------------------------------------------------------------------------------------------------------

void C_Relation::getArray (TC_UniqueArray <TC_UniqueArray <uint64_t> > & outArray
                           COMMA_LOCATION_ARGS) const {
  MF_AssertThere (variableCount () == 2,
                  "C_Relation::getArray error: variableCount () == %lld != 2",
                  (int64_t) variableCount (),
                  0) ;

  const uint32_t bitCount0 = mConfiguration.bddBitCountForVariable (0 COMMA_THERE) ;
  const uint32_t bitCount1 = mConfiguration.bddBitCountForVariable (1 COMMA_THERE) ;
  const uint32_t size0 = mConfiguration.constantCountForVariable (0 COMMA_THERE) ;
  mBDD.getArray2 (outArray,
                  size0,
                  bitCount0,
                  bitCount1) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::relationByDeletingLastVariable (LOCATION_ARGS) const {
  C_Relation result = *this ;
  const int32_t lastVariableIndex = variableCount () - 1 ;
  result.mBDD = result.mBDD.existsOnBitRange (mConfiguration.bddStartBitIndexForVariable (lastVariableIndex COMMA_THERE),
                                              mConfiguration.bddBitCountForVariable (lastVariableIndex COMMA_THERE)) ;
  result.mConfiguration.deleteLastVariable (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::swap021 (LOCATION_ARGS) const {
  MF_AssertThere (variableCount () == 3,
                  "C_Relation::swap021 error: variableCount () == %lld != 3",
                  (int64_t) variableCount (),
                  0) ;

  const uint32_t bitCount0 = mConfiguration.bddBitCountForVariable (0 COMMA_THERE) ;
  const uint32_t bitCount1 = mConfiguration.bddBitCountForVariable (1 COMMA_THERE) ;
  const uint32_t bitCount2 = mConfiguration.bddBitCountForVariable (2 COMMA_THERE) ;
  const C_BDD result = mBDD.swap021 (bitCount0, bitCount1, bitCount2) ;
  const C_RelationConfiguration config = mConfiguration.swap021 (THERE) ;
  return C_Relation (config, result) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::swap102 (LOCATION_ARGS) const {
  MF_AssertThere (variableCount () == 3,
                  "C_Relation::swap102 error: variableCount () == %lld != 3",
                  (int64_t) variableCount (),
                  0) ;

  const uint32_t bitCount0 = mConfiguration.bddBitCountForVariable (0 COMMA_THERE) ;
  const uint32_t bitCount1 = mConfiguration.bddBitCountForVariable (1 COMMA_THERE) ;
  const uint32_t bitCount2 = mConfiguration.bddBitCountForVariable (2 COMMA_THERE) ;
  const C_BDD result = mBDD.swap102 (bitCount0, bitCount1, bitCount2) ;
  const C_RelationConfiguration config = mConfiguration.swap102 (THERE) ;
  return C_Relation (config, result) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::swap120 (LOCATION_ARGS) const {
  MF_AssertThere (variableCount () == 3,
                  "C_Relation::swap120 error: variableCount () == %lld != 3",
                  (int64_t) variableCount (),
                  0) ;

  const uint32_t bitCount0 = mConfiguration.bddBitCountForVariable (0 COMMA_THERE) ;
  const uint32_t bitCount1 = mConfiguration.bddBitCountForVariable (1 COMMA_THERE) ;
  const uint32_t bitCount2 = mConfiguration.bddBitCountForVariable (2 COMMA_THERE) ;
  const C_BDD result = mBDD.swap120 (bitCount0, bitCount1, bitCount2) ;
  const C_RelationConfiguration config = mConfiguration.swap120 (THERE) ;
  return C_Relation (config, result) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::swap201 (LOCATION_ARGS) const {
  MF_AssertThere (variableCount () == 3,
                  "C_Relation::swap201 error: variableCount () == %lld != 3",
                  (int64_t) variableCount (),
                  0) ;

  const uint32_t bitCount0 = mConfiguration.bddBitCountForVariable (0 COMMA_THERE) ;
  const uint32_t bitCount1 = mConfiguration.bddBitCountForVariable (1 COMMA_THERE) ;
  const uint32_t bitCount2 = mConfiguration.bddBitCountForVariable (2 COMMA_THERE) ;
  const C_BDD result = mBDD.swap201 (bitCount0, bitCount1, bitCount2) ;
  const C_RelationConfiguration config = mConfiguration.swap201 (THERE) ;
  return C_Relation (config, result) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::swap210 (LOCATION_ARGS) const {
  MF_AssertThere (variableCount () == 3,
                  "C_Relation::swap210 error: variableCount () == %lld != 3",
                  (int64_t) variableCount (),
                  0) ;

  const uint32_t bitCount0 = mConfiguration.bddBitCountForVariable (0 COMMA_THERE) ;
  const uint32_t bitCount1 = mConfiguration.bddBitCountForVariable (1 COMMA_THERE) ;
  const uint32_t bitCount2 = mConfiguration.bddBitCountForVariable (2 COMMA_THERE) ;
  const C_BDD result = mBDD.swap210 (bitCount0, bitCount1, bitCount2) ;
  const C_RelationConfiguration config = mConfiguration.swap210 (THERE) ;
  return C_Relation (config, result) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::exitsOnVariable (const int32_t inVariableIndex
                                        COMMA_LOCATION_ARGS) const {
  C_Relation result = *this ;
  const uint32_t bitIndex = mConfiguration.bddStartBitIndexForVariable (inVariableIndex COMMA_THERE) ;
  const uint32_t bit_count = mConfiguration.bddBitCountForVariable (inVariableIndex COMMA_THERE) ;
  result.mBDD = result.mBDD.existsOnBitRange (bitIndex, bit_count) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_Relation::operator == (const C_Relation & inRelation) const {
  mConfiguration.checkIdenticalTo (inRelation.mConfiguration COMMA_HERE) ;
  return mBDD == inRelation.mBDD ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_Relation::operator != (const C_Relation & inRelation) const {
  mConfiguration.checkIdenticalTo (inRelation.mConfiguration COMMA_HERE) ;
  return mBDD != inRelation.mBDD ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Relation C_Relation::transposedRelation (LOCATION_ARGS) const {
  MF_AssertThere (variableCount () == 2,
                  "C_Relation::transposedRelation error: variableCount () == %lld != 2",
                  (int64_t) variableCount (),
                  0) ;
  const uint32_t bitSize0 = mConfiguration.bddBitCountForVariable (0 COMMA_THERE) ;
  const uint32_t bitSize1 = mConfiguration.bddBitCountForVariable (1 COMMA_THERE) ;
  const uint32_t totalSize = (uint32_t) (bitSize0 + bitSize1) ;
  uint32_t * tab = NULL ;
  macroMyNewArray (tab, uint32_t, totalSize) ;
  for (uint32_t i=0 ; i<bitSize0 ; i++) {
    tab [i] = (uint32_t) (i + bitSize1) ;
  }
  for (uint32_t j=0 ; j<bitSize1 ; j++) {
    tab [j + bitSize0] = j ;
  }
  const C_BDD r = mBDD.substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
//---
  const C_String name0 = mConfiguration.nameForVariable (0 COMMA_HERE) ;
  const C_RelationSingleType type0 = mConfiguration.typeForVariable (0 COMMA_HERE) ;
  const C_String name1 = mConfiguration.nameForVariable (1 COMMA_HERE) ;
  const C_RelationSingleType type1 = mConfiguration.typeForVariable (1 COMMA_HERE) ;
  C_RelationConfiguration config ;
  config.addVariable (name1, type1) ;
  config.addVariable (name0, type0) ;
  return C_Relation (config, r) ;
}

//----------------------------------------------------------------------------------------------------------------------

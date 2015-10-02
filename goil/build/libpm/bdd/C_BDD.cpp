//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     BDD package (implementation of ROBDD)                                                                           *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1999, ..., 2014 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
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
#include "utilities/TF_sup.h"
#include "bdd/C_BDD-node.h"

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Display Information Messages
#endif

//---------------------------------------------------------------------------------------------------------------------*

static bool gDisplaysInformationMessages ;

//---------------------------------------------------------------------------------------------------------------------*

bool C_BDD::displaysInformationMessages (void) {
  return gDisplaysInformationMessages ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::setDisplaysInformationMessages (const bool inFlag) {
  gDisplaysInformationMessages = inFlag ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ITE operation
#endif

//---------------------------------------------------------------------------------------------------------------------*

uint32_t internalITEoperation (const uint32_t opf, 
                               const uint32_t opg,
                               const uint32_t oph) {
  return internalANDoperation (internalANDoperation (opf, opg)     ^ 1,
                               internalANDoperation (opf ^ 1, oph) ^ 1) ^ 1 ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD operators
#endif

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::setToFalse (void) {
  mBDDvalue = 0  ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::setToTrue (void) {
  mBDDvalue = 1  ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::ite (const C_BDD & f, const C_BDD & g, const C_BDD & h) {
  return C_BDD (internalITEoperation (f.mBDDvalue, g.mBDDvalue, h.mBDDvalue)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::implies (const C_BDD & inOperand) const {
//--- f -> g est defini par (non f) ou g, c'est a dire non (f et (non g))
  return C_BDD (internalANDoperation (mBDDvalue, inOperand.mBDDvalue ^ 1) ^ 1) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::operator & (const C_BDD & inOperand) const {
  return C_BDD (internalANDoperation (mBDDvalue, inOperand.mBDDvalue)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::operator &= (const C_BDD & inOperand) {
   mBDDvalue = internalANDoperation (mBDDvalue, inOperand.mBDDvalue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::operator | (const C_BDD & inOperand) const {
  return C_BDD (internalANDoperation (mBDDvalue ^ 1, inOperand.mBDDvalue ^ 1) ^ 1) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::operator |= (const C_BDD & inOperand) {
  mBDDvalue = internalANDoperation (mBDDvalue ^ 1, inOperand.mBDDvalue ^ 1) ^ 1 ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::equalTo(const C_BDD & inOperand) const {
  return C_BDD (internalITEoperation (mBDDvalue, inOperand.mBDDvalue, inOperand.mBDDvalue ^ 1)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::notEqualTo (const C_BDD & inOperand) const {
  return C_BDD (internalITEoperation (mBDDvalue, inOperand.mBDDvalue ^ 1, inOperand.mBDDvalue)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::lowerOrEqual (const C_BDD & inOperand) const { // <=
  return C_BDD (internalANDoperation (mBDDvalue, inOperand.mBDDvalue ^ 1) ^ 1) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::greaterThan (const C_BDD & inOperand) const { // >
  return C_BDD (internalANDoperation (mBDDvalue, inOperand.mBDDvalue ^ 1)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::lowerThan (const C_BDD & inOperand) const { // <
  return C_BDD (internalANDoperation (mBDDvalue ^ 1, inOperand.mBDDvalue)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::greaterOrEqual (const C_BDD & inOperand) const { // >=
  return C_BDD (internalANDoperation (mBDDvalue ^ 1, inOperand.mBDDvalue) ^ 1) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Compare BDDs
#endif

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Complement BDD
#endif

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::negate (void) {
  mBDDvalue ^= 1 ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::operator ~ (void) const {
  return C_BDD (mBDDvalue ^ 1) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD is complemented
#endif

//---------------------------------------------------------------------------------------------------------------------*

bool C_BDD::isComplemented (void) const {
  return (mBDDvalue & 1) != 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD with constants
#endif

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::bddWithConstants (const uint32_t inValues [],
                               const uint32_t inBitCount [],
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
//--- Check
/*  C_BDD r ; r.setToTrue () ;
  idx = 0 ;
  for (int32_t i=0 ; i<inEntryCount ; i++) {
    uint32_t v = inValues [i] ;
    for (uint32_t j=0 ; j<inBitCount [i] ; j++) {
      r &= C_BDD (idx, ((v & 1) == 0) ? false : true) ;
      v >>= 1 ;
      idx ++ ;
    }
  }
  if (r.mBDDvalue != result) {
    printf ("[ERROR bddWithConstants]") ;
  }*/
//---- 
  return C_BDD (result) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build BDD from comparison between variables and constant
#endif

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build BDD from comparison between variables
#endif

//---------------------------------------------------------------------------------------------------------------------*

static C_BDD
construireSupVariable (const uint32_t inLeftFirstIndex,
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

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Needed Variable Count
#endif

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_BDD::significantVariableCount (void) const {
  uint32_t bitCount = 0 ;
  const uint32_t nodeIndex = nodeIndexForRoot (mBDDvalue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    bitCount = gNodeArray [nodeIndex].mVariableIndex + 1 ;
  }
  return bitCount ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Test if BDD does contain a value
#endif

//---------------------------------------------------------------------------------------------------------------------*

//#define DEBUG_CONTAINS_VALUE
 
//---------------------------------------------------------------------------------------------------------------------*

static bool recursiveContainsValue64 (const uint32_t inBDD,
                                      const uint64_t inValue,
                                      const uint32_t inFirstBit,
                                      const uint32_t inLastBitPlusOne) {
  bool result ;
  const uint32_t nodeIndex = nodeIndexForRoot (inBDD COMMA_HERE) ;
  const uint32_t complement = inBDD & 1 ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    result = complement != 0 ;
    #ifdef DEBUG_CONTAINS_VALUE
      printf ("result %s\n", result ? "YES" : "NO") ;
    #endif
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    if (var >= inLastBitPlusOne) {
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u\n", var) ;
      #endif
      result = recursiveContainsValue64 (gNodeArray [nodeIndex].mTHEN ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u branch THEN returns %s\n", var, result ? "YES" : "NO") ;
      #endif
      if (! result) {
        result = recursiveContainsValue64 (gNodeArray [nodeIndex].mELSE ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
        #ifdef DEBUG_CONTAINS_VALUE
          printf ("var %u branch ELSE returns %s\n", var, result ? "YES" : "NO") ;
        #endif
      }
    }else if (var < inFirstBit) {
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u -> true\n", var) ;
      #endif
      result = true ;
    }else{
      const bool bitValue = ((inValue >> (var - inFirstBit)) & 1) != 0 ;
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u, bitvalue %s\n", var, bitValue ? "YES" : "NO") ;
      #endif
      if (bitValue) {
        result = recursiveContainsValue64 (gNodeArray [nodeIndex].mTHEN ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      }else{
        result = recursiveContainsValue64 (gNodeArray [nodeIndex].mELSE ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      }
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u, bitvalue %s returns %s\n", var, bitValue ? "YES" : "NO", result ? "YES" : "NO") ;
      #endif
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool C_BDD::containsValue64 (const uint64_t inValue,
                             const uint32_t inFirstBit,
                             const uint32_t inBitCount) const {
  return recursiveContainsValue64 (mBDDvalue,
                                   inValue,
                                   inFirstBit,
                                   (uint32_t) (inFirstBit + inBitCount)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static bool recursiveContainsValue (const uint32_t inBDD,
                                    const TC_Array <bool> & inValue,
                                    const uint32_t inFirstBit,
                                    const uint32_t inLastBitPlusOne) {
  bool result ;
  const uint32_t nodeIndex = nodeIndexForRoot (inBDD COMMA_HERE) ;
  const uint32_t complement = inBDD & 1 ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    result = complement != 0 ;
    #ifdef DEBUG_CONTAINS_VALUE
      printf ("result %s\n", result ? "YES" : "NO") ;
    #endif
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    if (var >= inLastBitPlusOne) {
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u\n", var) ;
      #endif
      result = recursiveContainsValue (gNodeArray [nodeIndex].mTHEN ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u branch THEN returns %s\n", var, result ? "YES" : "NO") ;
      #endif
      if (! result) {
        result = recursiveContainsValue (gNodeArray [nodeIndex].mELSE ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
        #ifdef DEBUG_CONTAINS_VALUE
          printf ("var %u branch ELSE returns %s\n", var, result ? "YES" : "NO") ;
        #endif
      }
    }else if (var < inFirstBit) {
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u -> true\n", var) ;
      #endif
      result = true ;
    }else{
      const bool bitValue = inValue ((int32_t) (var - inFirstBit) COMMA_HERE) ;
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u, bitvalue %s\n", var, bitValue ? "YES" : "NO") ;
      #endif
      if (bitValue) {
        result = recursiveContainsValue (gNodeArray [nodeIndex].mTHEN ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      }else{
        result = recursiveContainsValue (gNodeArray [nodeIndex].mELSE ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      }
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u, bitvalue %s returns %s\n", var, bitValue ? "YES" : "NO", result ? "YES" : "NO") ;
      #endif
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool C_BDD::containsValue (const TC_Array <bool> & inValue,
                           const uint32_t inFirstBit,
                           const uint32_t inBitCount) const {
  return recursiveContainsValue (mBDDvalue,
                                 inValue,
                                 inFirstBit,
                                 (uint32_t) (inFirstBit + inBitCount)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void
parcoursBDDinterneParValeur (const uint32_t inValue,
                             C_bdd_value_traversing & inTraversing,
                             bool tableauDesValeurs [],
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

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::traverseBDDvalues (C_bdd_value_traversing & inTraversing,
                               const uint32_t inVariableCount) const {
  bool * tableauDesValeurs = NULL ;
  macroMyNewArray (tableauDesValeurs, bool, inVariableCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, inTraversing, tableauDesValeurs, inVariableCount, inVariableCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build an array of uint64_t values
#endif

//---------------------------------------------------------------------------------------------------------------------*

class C_build_values64_array : public C_bdd_value_traversing {
  private : TC_UniqueArray <uint64_t> * mPtr ;

  public : inline C_build_values64_array (TC_UniqueArray <uint64_t> * inPtr) :
  mPtr (inPtr) {
  }

//--- No copy
  private : C_build_values64_array (const C_build_values64_array &) ;
  private : C_build_values64_array & operator = (const C_build_values64_array &) ;

//--- Virtual method called for every value
  public : virtual void action (const bool tableauDesValeurs [],
                                const uint32_t inVariableCount) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

void C_build_values64_array::action (const bool tableauDesValeurs [],
                                   const uint32_t inVariableCount) {
  uint64_t value = 0 ;
  for (uint32_t i=1 ; i<=inVariableCount ; i++) {
    value = (value << 1) | tableauDesValeurs [inVariableCount - i] ;
  }
  mPtr->addObject (value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::buildValue64Array (TC_UniqueArray <uint64_t> & outValuesArray,
                               const uint32_t inVariableCount) const {
  MF_Assert(inVariableCount < 64, "inVariableCount == %ld >= 64", (int64_t) inVariableCount, 0) ;
  outValuesArray.setCountToZero () ;
  C_build_values64_array builder (& outValuesArray) ;
  bool * tableauDesValeurs = NULL ;
  macroMyNewArray (tableauDesValeurs, bool, inVariableCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, builder, tableauDesValeurs, inVariableCount, inVariableCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build an array of bool array values
#endif

//---------------------------------------------------------------------------------------------------------------------*

class C_build_values_array : public C_bdd_value_traversing {
  private : TC_UniqueArray <TC_Array <bool> > * mPtr ;

  public : inline C_build_values_array (TC_UniqueArray <TC_Array <bool> > * inPtr) :
  mPtr (inPtr) {
  }

//--- No copy
  private : C_build_values_array (const C_build_values_array &) ;
  private : C_build_values_array & operator = (const C_build_values_array &) ;

//--- Virtual method called for every value
  public : virtual void action (const bool tableauDesValeurs [],
                                const uint32_t inVariableCount) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

void C_build_values_array::action (const bool tableauDesValeurs [],
                                   const uint32_t inVariableCount) {
  TC_Array <bool> value ;
  for (uint32_t i=0 ; i<inVariableCount ; i++) {
    value.addObject (tableauDesValeurs [i]) ;
  }
  mPtr->addObject (value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::buildValueArray (TC_UniqueArray <TC_Array <bool> > & outValuesArray,
                             const uint32_t inVariableCount) const {
  outValuesArray.setCountToZero () ;
  C_build_values_array builder (& outValuesArray) ;
  bool * tableauDesValeurs = NULL ;
  macroMyNewArray (tableauDesValeurs, bool, inVariableCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, builder, tableauDesValeurs, inVariableCount, inVariableCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build an array of string values
#endif

//---------------------------------------------------------------------------------------------------------------------*

class cLittleEndianStringValueBuilder : public C_bdd_value_traversing {
  private : TC_UniqueArray <C_String> * mPtr ;

  public : cLittleEndianStringValueBuilder (TC_UniqueArray <C_String> * inPtr) :
  mPtr (inPtr) {
  }

//--- No copy
  private : cLittleEndianStringValueBuilder (const cLittleEndianStringValueBuilder &) ;
  private : cLittleEndianStringValueBuilder & operator = (const cLittleEndianStringValueBuilder &) ;

//--- Virtual method called for every value
  public : virtual void action (const bool tableauDesValeurs [],
                                const uint32_t inVariableCount) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cLittleEndianStringValueBuilder::
action (const bool tableauDesValeurs [],
        const uint32_t inVariableCount) {
  C_String value ;
  for (uint32_t i=0 ; i<inVariableCount ; i++) {
    value << cStringWithCharacter ((char) ('0' + tableauDesValeurs [i])) ;
  }
  mPtr->addObject (value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::
buildLittleEndianStringValueArray (TC_UniqueArray <C_String> & outValuesArray,
                                   const uint32_t inVariableCount) const {
  outValuesArray.setCountToZero () ;
  cLittleEndianStringValueBuilder builder (& outValuesArray) ;
  bool * tableauDesValeurs = NULL ;
  macroMyNewArray (tableauDesValeurs, bool, inVariableCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, builder, tableauDesValeurs, inVariableCount, inVariableCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//---------------------------------------------------------------------------------------------------------------------*

class cBuildBigEndianStringValueArray : public C_bdd_value_traversing {
  private : TC_UniqueArray <C_String> * mPtr ;

  public : cBuildBigEndianStringValueArray (TC_UniqueArray <C_String> * inPtr) :
  mPtr (inPtr) {
  }

//--- No copy
  private : cBuildBigEndianStringValueArray (const cBuildBigEndianStringValueArray &) ;
  private : cBuildBigEndianStringValueArray & operator = (const cBuildBigEndianStringValueArray &) ;

//--- Virtual method called for every value
  public : virtual void action (const bool tableauDesValeurs [],
                                const uint32_t inVariableCount) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cBuildBigEndianStringValueArray::
action (const bool tableauDesValeurs [],
        const uint32_t inVariableCount) {
  C_String value ;
  for (uint32_t i=inVariableCount ; i>0 ; i--) {
    value << cStringWithCharacter ((char) ('0' + tableauDesValeurs [i-1])) ;
  }
  mPtr->addObject (value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::
buildBigEndianStringValueArray (TC_UniqueArray <C_String> & outValuesArray,
                                const uint32_t inVariableCount) const {
  outValuesArray.setCountToZero () ;
  cBuildBigEndianStringValueArray builder (& outValuesArray) ;
  bool * tableauDesValeurs = NULL ;
  macroMyNewArray (tableauDesValeurs, bool, inVariableCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, builder, tableauDesValeurs, inVariableCount, inVariableCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//---------------------------------------------------------------------------------------------------------------------*

class cBuildQueryString : public C_bdd_value_traversing {
  private : C_String * mStringPtr ;

  public : cBuildQueryString (C_String * inStringPtr) :
  mStringPtr (inStringPtr) {
  }

//--- No copy
  private : cBuildQueryString (const cBuildQueryString &) ;
  private : cBuildQueryString & operator = (const cBuildQueryString &) ;


//--- Virtual method called for every value
  public : virtual void action (const bool tableauDesValeurs [],
                                const uint32_t inVariableCount) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

void cBuildQueryString::
action (const bool tableauDesValeurs [],
        const uint32_t inVariableCount) {
  C_String value ;
  if (mStringPtr->length () > 0) {
    *mStringPtr << "|" ;
  }
  for (uint32_t i=inVariableCount ; i>0 ; i--) {
    *mStringPtr << cStringWithCharacter ((char) ('0' + tableauDesValeurs [i-1])) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_BDD::
queryStringValue (LOCATION_ARGS) const {
  C_String s ;
  if (isTrue ()) {
    s << "X" ;
  }else if (! isFalse ()) {
    TC_UniqueArray <C_String> stringArray ;
    buildCompressedBigEndianStringValueArray (stringArray COMMA_THERE) ;
    if (stringArray.count () > 0) {
      s << stringArray (0 COMMA_HERE) ;
      for (int32_t i=1 ; i<stringArray.count () ; i++) {
        s << "|" << stringArray (i COMMA_HERE) ;
      }
    }
  }
  return s ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Value Count
#endif

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::BDDWithPredicateString (const C_String & inPredicateStringValue
                                     COMMA_LOCATION_ARGS) {
  C_BDD result ;
  const int32_t stringLength = inPredicateStringValue.length () ;
  int32_t stringIndex = 0 ;
  bool ok = true ;
  while ((stringIndex < stringLength) && ok) {
    utf32 cc = inPredicateStringValue (stringIndex COMMA_HERE) ;
    C_String s ;
    while ((stringIndex < stringLength) && ((UNICODE_VALUE (cc) == '0') || (UNICODE_VALUE (cc) == '1') || (UNICODE_VALUE (cc) == 'X') || (UNICODE_VALUE (cc) == ' '))) {
      s.appendUnicodeCharacter (cc COMMA_HERE) ;
      stringIndex ++ ;
      if (stringIndex < stringLength) {
        cc = inPredicateStringValue (stringIndex COMMA_HERE) ;
      }
    }
    if (s.length () > 0) {
      C_BDD v ; v.setToTrue () ;
      int32_t bitIndex = 0 ;
      for (int32_t i=s.length () - 1 ; i>=0 ; i--) {
        const utf32 c = s (i COMMA_HERE) ;
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
      MF_AssertThere (ok, "BDD predicate string syntax error at character index %lld", stringIndex, 0) ;
      stringIndex ++ ;
    }
  }
  if (! ok) {
    result = C_BDD () ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Value Count (64)
#endif

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

uint64_t C_BDD::valueCount64 (const uint32_t inVariableCount) const {
  uint64_t nombreDirect = 0 ;
  uint64_t nombreComplement = 0 ;
  internalValueCount64 (mBDDvalue, inVariableCount, nombreDirect, nombreComplement COMMA_HERE) ;
  return nombreDirect ;
}

//---------------------------------------------------------------------------------------------------------------------*

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
    ioDirectCacheArray.forceObjectAtIndex (inValue / 2, nombreDirect, 0 COMMA_HERE) ;
    ioComplementCacheArray.forceObjectAtIndex (inValue / 2, nombreComplement, 0 COMMA_HERE) ;
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

//---------------------------------------------------------------------------------------------------------------------*

uint64_t C_BDD::valueCount64UsingCache (const uint32_t inVariableCount,
                                        TC_UniqueArray <uint64_t> & ioDirectCacheArray,
                                        TC_UniqueArray <uint64_t> & ioComplementCacheArray) const {
  uint64_t nombreDirect = 0 ;
  uint64_t nombreComplement = 0 ;
  internalValueCount64UsingCache (mBDDvalue, inVariableCount, nombreDirect, nombreComplement, ioDirectCacheArray, ioComplementCacheArray COMMA_HERE) ;
  return nombreDirect ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Value Count (128)
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void internalValueCount128 (const uint32_t inValue,
                                   const uint32_t inVariableCount,
                                   PMUInt128 & nombreDirect,
                                   PMUInt128 & nombreComplement
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
    PMUInt128 nd0, nc0, nd1, nc1 ;
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
    const PMUInt128 tempo = nombreDirect ;
    nombreDirect = nombreComplement ;
    nombreComplement = tempo ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

PMUInt128 C_BDD::valueCount128 (const uint32_t inVariableCount) const {
  PMUInt128 nombreDirect = 0 ;
  PMUInt128 nombreComplement = 0 ;
  internalValueCount128 (mBDDvalue, inVariableCount, nombreDirect, nombreComplement COMMA_HERE) ;
  return nombreDirect ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void internalValueCount128UsingCache (const uint32_t inValue,
                                             const uint32_t inVariableCount,
                                             PMUInt128 & nombreDirect,
                                             PMUInt128 & nombreComplement,
                                             TC_UniqueArray <PMUInt128> & ioDirectCacheArray,
                                             TC_UniqueArray <PMUInt128> & ioComplementCacheArray
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
    PMUInt128 nd0, nc0, nd1, nc1 ;
    internalValueCount128UsingCache (gNodeArray [nodeIndex].mELSE, var, nd0, nc0, ioDirectCacheArray, ioComplementCacheArray COMMA_THERE) ;
    internalValueCount128UsingCache (gNodeArray [nodeIndex].mTHEN, var, nd1, nc1, ioDirectCacheArray, ioComplementCacheArray COMMA_THERE) ;
    nombreDirect = nd0 + nd1 ;
    nombreComplement = nc0 + nc1 ;
    for (uint32_t i=(uint32_t) (var+1) ; i<inVariableCount ; i++) {
      nombreDirect += nombreDirect ;
      nombreComplement += nombreComplement ;
    }
    ioDirectCacheArray.forceObjectAtIndex (inValue / 2, nombreDirect, 0 COMMA_HERE) ;
    ioComplementCacheArray.forceObjectAtIndex (inValue / 2, nombreComplement, 0 COMMA_HERE) ;
  }
  if ((inValue & 1) != 0) {
    const PMUInt128 tempo = nombreDirect ;
    nombreDirect = nombreComplement ;
    nombreComplement = tempo ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

PMUInt128 C_BDD::valueCount128UsingCache (const uint32_t inVariableCount,
                                          TC_UniqueArray <PMUInt128> & ioDirectCacheArray,
                                          TC_UniqueArray <PMUInt128> & ioComplementCacheArray) const {
  PMUInt128 nombreDirect = 0 ;
  PMUInt128 nombreComplement = 0 ;
  internalValueCount128UsingCache (mBDDvalue, inVariableCount, nombreDirect, nombreComplement, ioDirectCacheArray, ioComplementCacheArray COMMA_HERE) ;
  return nombreDirect ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Value Count (Big ints)
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void internalValueCount (const uint32_t inValue,
                                const uint32_t inVariableCount,
                                C_BigInt & nombreDirect,
                                C_BigInt & nombreComplement
                                COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_THERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    nombreDirect.setToZero () ;
    nombreComplement.setFromUnsigned (1) ;
    nombreComplement <<= inVariableCount ;
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    C_BigInt nd0, nc0, nd1, nc1 ;
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

//---------------------------------------------------------------------------------------------------------------------*

C_BigInt C_BDD::valueCount (const uint32_t inVariableCount) const {
  C_BigInt nombreDirect ;
  C_BigInt nombreComplement ;
  internalValueCount (mBDDvalue, inVariableCount, nombreDirect, nombreComplement COMMA_HERE) ;
  return nombreDirect ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void internalValueCountUsingCache (const uint32_t inValue,
                                          const uint32_t inVariableCount,
                                          C_BigInt & nombreDirect,
                                          C_BigInt & nombreComplement,
                                          TC_UniqueArray <C_BigInt> & ioDirectCacheArray,
                                          TC_UniqueArray <C_BigInt> & ioComplementCacheArray
                                          COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_THERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    nombreDirect.setToZero () ;
    nombreComplement.setFromUnsigned (1) ; nombreComplement <<= inVariableCount ;
  }else if ((ioDirectCacheArray.count () > (int32_t) (inValue / 2))
    && (((!ioDirectCacheArray (inValue / 2 COMMA_HERE).isZero ()) || (!ioComplementCacheArray (inValue / 2 COMMA_HERE).isZero())))) {
    nombreDirect = ioDirectCacheArray (inValue / 2 COMMA_HERE) ;
    nombreComplement = ioComplementCacheArray (inValue / 2 COMMA_HERE) ;
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    C_BigInt nd0, nc0, nd1, nc1 ;
    internalValueCountUsingCache (gNodeArray [nodeIndex].mELSE, var, nd0, nc0, ioDirectCacheArray, ioComplementCacheArray COMMA_THERE) ;
    internalValueCountUsingCache (gNodeArray [nodeIndex].mTHEN, var, nd1, nc1, ioDirectCacheArray, ioComplementCacheArray COMMA_THERE) ;
    nombreDirect = nd0 + nd1 ;
    nombreComplement = nc0 + nc1 ;
    const int32_t shiftCount = ((int32_t) inVariableCount) - ((int32_t) var) - 1 ;
    if (shiftCount > 0) {
      nombreDirect <<= (uint32_t) shiftCount ;
      nombreComplement <<= (uint32_t) shiftCount ;
    }
    ioDirectCacheArray.forceObjectAtIndex (inValue / 2, nombreDirect, C_BigInt () COMMA_HERE) ;
    ioComplementCacheArray.forceObjectAtIndex (inValue / 2, nombreComplement, C_BigInt () COMMA_HERE) ;
  }
  if ((inValue & 1) != 0) {
    swap (nombreDirect, nombreComplement) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

C_BigInt C_BDD::valueCountUsingCache (const uint32_t inVariableCount,
                                      TC_UniqueArray <C_BigInt> & ioDirectCacheArray,
                                      TC_UniqueArray <C_BigInt> & ioComplementCacheArray) const {
  C_BigInt nombreDirect ;
  C_BigInt nombreComplement ;
  internalValueCountUsingCache (mBDDvalue, inVariableCount, nombreDirect, nombreComplement, ioDirectCacheArray, ioComplementCacheArray COMMA_HERE) ;
  return nombreDirect ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Get i-th value as BDD
#endif

//---------------------------------------------------------------------------------------------------------------------*

static C_BDD
obtenirIemeBDDinterne (const uint32_t inValue,
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

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::getNthBDD (const uint64_t inNthBDDvalue,
                        const uint32_t inVariableCount) const {
  return obtenirIemeBDDinterne (mBDDvalue, inNthBDDvalue, inVariableCount) ;
}
  

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Get i-th value as uint64_t
#endif

//---------------------------------------------------------------------------------------------------------------------*

static uint64_t
obtenirValeurAbsolueBDDInterne (const uint32_t inValue) {
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

//---------------------------------------------------------------------------------------------------------------------*

uint64_t C_BDD::getBDDabsoluteValue (const uint32_t inVariableCount) const {
  uint64_t result = 0 ;
  if (valueCount64 (inVariableCount) == 1) {
    result = obtenirValeurAbsolueBDDInterne (mBDDvalue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD range
#endif

//---------------------------------------------------------------------------------------------------------------------*

static uint64_t
rangBDDinterne (const uint32_t inValue,
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

//---------------------------------------------------------------------------------------------------------------------*

uint64_t C_BDD::
getBDDrange (const C_BDD & inOperand,
             const uint32_t inVariableCount) const {
  uint64_t rang = 0 ;
  if (inOperand.valueCount64 (inVariableCount) == 1) {
    rang = rangBDDinterne (mBDDvalue, inOperand.mBDDvalue, inVariableCount) ;
  }
  return rang ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Node Count
#endif

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_BDD::getBDDnodesCount (void) const {
  const uint32_t nodeIndex = nodeIndexForRoot (mBDDvalue COMMA_HERE) ;
  uint32_t result = 0 ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    unmarkAllExistingBDDnodes () ;
    result = internalRecursiveNodeCount (mBDDvalue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Boolean array
#endif

//---------------------------------------------------------------------------------------------------------------------*

class cBuildArrayForSet : public C_bdd_value_traversing {
//--- Attributs
  protected : TC_UniqueArray <bool> & mArray ;

//--- Constructeur
  public : cBuildArrayForSet (TC_UniqueArray <bool> & outArray) ;

//--- Methode virtuelle appelee pour chaque valeur
  public : virtual void action (const bool inValuesArray [],
                                const uint32_t inBDDbitsSize) ;
} ;
  
//---------------------------------------------------------------------------------------------------------------------*

cBuildArrayForSet::
cBuildArrayForSet (TC_UniqueArray <bool> & outArray) :
mArray (outArray) {
}

//---------------------------------------------------------------------------------------------------------------------*

void cBuildArrayForSet::action (const bool inValuesArray [],
                                const uint32_t inBDDbitsSize) {
  int32_t element = 0 ;
  for (int32_t i=((int32_t) inBDDbitsSize) - 1 ; i>=0 ; i--) {
    element = (element << 1) + inValuesArray [i] ;
  }
  mArray.setObjectAtIndex (true, element COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::
getBoolArray (TC_UniqueArray <bool> & outArray,
              const uint32_t inMaxValues,
              const uint32_t inBitSize) const {
  outArray.setCountToZero () ;
  outArray.makeRoom ((int32_t) inMaxValues) ;
  outArray.addObjects ((int32_t) inMaxValues, false) ;
  cBuildArrayForSet s (outArray) ;
  traverseBDDvalues (s, inBitSize) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD as N-relation
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   U P D A T E   R E L A T I O N                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static uint32_t
internalRecursiveUpdateRelation (const uint32_t inValue,
                                 const uint32_t inTranslationVector []) {
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

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::
updateRelation (const uint32_t inRelationBitNeededCount [], 
                uint32_t * inRelationBitCurrentCount [], 
                const int32_t inRelationCardinality) const {
  uint32_t result = mBDDvalue ;
//--- Check if update is needed
  bool updateIsNeeded = false ;
  for (int32_t i=0 ; (i<inRelationCardinality) && ! updateIsNeeded ; i++) {
    updateIsNeeded = inRelationBitNeededCount [i] > * (inRelationBitCurrentCount [i]) ;
  }
//--- Perform updating
  if (updateIsNeeded) {
    //printf ("BEFORE '%s'\n", queryStringValue ().cString (HERE)) ;
    uint32_t totalCurrentBitCount = 0 ;
    uint32_t newNeededTotalBitCount = 0 ;
    for (int32_t i=0 ; i<inRelationCardinality ; i++) {
      totalCurrentBitCount = (uint32_t) (totalCurrentBitCount + * (inRelationBitCurrentCount [i])) ;
      newNeededTotalBitCount = (uint32_t) (newNeededTotalBitCount + inRelationBitNeededCount [i]) ;
    }
    uint32_t * translationVector = NULL ;
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
     // printf ("finalTranslatedIndex %u\n", finalTranslatedIndex) ;
     // result = internalITEoperation (find_or_add (finalTranslatedIndex, 1, 0), result, 0) ;
      result = find_or_add (finalTranslatedIndex, result, 0 COMMA_HERE) ;
      finalTranslatedIndex ++ ;
    }
    // printf ("AFTER '%s'\n", C_BDD (result).queryStringValue ().cString (HERE)) ;
    macroMyDeleteArray (translationVector) ;
  }
//--- Register updating
  if (updateIsNeeded) {
    for (int32_t i=0 ; i<inRelationCardinality; i++) {
      //printf ("%d -> %d\n", * (inRelationBitCurrentCount [i]), inRelationBitNeededCount [i]) ;
      * (inRelationBitCurrentCount [i]) = inRelationBitNeededCount [i] ;
    }
  }
//---
  return C_BDD (result) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD as 2-relation
#endif

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::
swap10 (const uint32_t inBitSize1,
        const uint32_t inBitSize2) const {
  const uint32_t totalSize = (uint32_t) (inBitSize1 + inBitSize2) ;
  uint32_t * tab = NULL ;
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

//---------------------------------------------------------------------------------------------------------------------*

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
  if (outIterationCount != NULL) {
    * outIterationCount = iterationCount ;
  }
  return accessible ;
}

//---------------------------------------------------------------------------------------------------------------------*

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
  if (outIterationCount != NULL) {
    * outIterationCount = iterationCount ;
  }
  return closure ;
}

//---------------------------------------------------------------------------------------------------------------------*

class cBuildArrayForRelation2 : public C_bdd_value_traversing {
//--- Attributes
  protected : TC_UniqueArray <TC_UniqueArray <uint64_t> > & mArray ;
  protected : uint32_t mBitsSize1 ;

//--- Constructor
  public :
  cBuildArrayForRelation2 (TC_UniqueArray <TC_UniqueArray <uint64_t> > & outArray,
                           const uint32_t inBitsSize1) ;

//--- Virtual method called for every value
  public : virtual void action (const bool inValuesArray [],
                                const uint32_t inBDDbitsSize) ;
} ;
  
//---------------------------------------------------------------------------------------------------------------------*

cBuildArrayForRelation2::
cBuildArrayForRelation2 (TC_UniqueArray <TC_UniqueArray <uint64_t> > & outArray,
                         const uint32_t inBitsSize1) :
mArray (outArray),
mBitsSize1 (inBitsSize1) {
}

//---------------------------------------------------------------------------------------------------------------------*

void cBuildArrayForRelation2::action (const bool inValuesArray [],
                                      const uint32_t inBDDbitsSize) {
  int32_t index1 = 0 ;
  uint64_t index2 = 0 ;
  for (int32_t i=((int32_t) mBitsSize1) - 1 ; i>=0 ; i--) {
    index1 = (index1 << 1) + inValuesArray [i] ;
  }
  for (int32_t j=((int32_t) inBDDbitsSize) - 1 ; j>= (int32_t) mBitsSize1 ; j--) {
    index2 = (index2 << 1) + inValuesArray [j] ;
  }
  mArray (index1 COMMA_HERE).addObject (index2) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::getArray2 (TC_UniqueArray <TC_UniqueArray <uint64_t> > & outArray,
                       const uint32_t inMaxValueCount,
                       const uint32_t inBitSize1,
                       const uint32_t inBitSize2) const {
  outArray.setCountToZero () ;
  outArray.makeRoomUsingSwap ((int32_t) inMaxValueCount) ;
  for (uint32_t i=0 ; i<inMaxValueCount ; i++) {
    outArray.addDefaultObjectUsingSwap () ;
  }
  cBuildArrayForRelation2 s (outArray, inBitSize1) ;
  traverseBDDvalues (s, (uint32_t) (inBitSize1 + inBitSize2)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD as 3-relation
#endif

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::
swap021 (const uint32_t inBitSize1,
         const uint32_t inBitSize2,
         const uint32_t inBitSize3) const {
  const uint32_t totalSize = (uint32_t) (inBitSize1 + inBitSize2 + inBitSize3) ;
  uint32_t * tab = NULL ;
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

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::
swap120 (const uint32_t inBitSize1,
         const uint32_t inBitSize2,
         const uint32_t inBitSize3) const {
  const uint32_t totalSize = (uint32_t) (inBitSize1 + inBitSize2 + inBitSize3) ;
  uint32_t * tab = NULL ;
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

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::
swap102 (const uint32_t inBitSize1,
         const uint32_t inBitSize2,
         const uint32_t inBitSize3) const {
  const uint32_t totalSize = (uint32_t) (inBitSize1 + inBitSize2 + inBitSize3) ;
  uint32_t * tab = NULL ;
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

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::
swap210 (const uint32_t inBitSize1,
         const uint32_t inBitSize2,
         const uint32_t inBitSize3) const {
  const uint32_t totalSize = (uint32_t) (inBitSize1 + inBitSize2 + inBitSize3) ;
  uint32_t * tab = NULL ;
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

//---------------------------------------------------------------------------------------------------------------------*

C_BDD C_BDD::
swap201 (const uint32_t inBitSize1,
         const uint32_t inBitSize2,
         const uint32_t inBitSize3) const {
  const uint32_t totalSize = (uint32_t) (inBitSize1 + inBitSize2 + inBitSize3) ;
  uint32_t * tab = NULL ;
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

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Print BDD
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void printLineWithSeparator (AC_OutputStream & outputStream,
                                    const TC_UniqueArray <char> & inValueArray) {
  for (int32_t i=inValueArray.count () - 1 ; i>=0 ; i--) {
    if ((i % 4) == 3) {
      outputStream << " " ;
    }
    outputStream << cStringWithCharacter (inValueArray (i COMMA_HERE)) ;
  }
  outputStream << "\n" ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void internalPrintWithSeparator (AC_OutputStream & outputStream,
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

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::print (AC_OutputStream & outputStream) const {
  if (mBDDvalue == 0) {
    outputStream << "(false)\n" ;
  }else if (mBDDvalue == 1) {
    outputStream << "(true)\n" ;
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

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::printHeader (AC_OutputStream & outputStream) const {
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
          outputStream << " " ;
        }
        const int32_t v = (i / divisor) % 10 ;
        outputStream << cStringWithSigned (v) ;
      }
      outputStream << "\n" ;
    }
    for (int32_t i=var ; i>=0 ; i--) {
      if ((i % 4) == 3) {
        outputStream << "-" ;
      }
      outputStream << "-" ;
    }
    outputStream << "\n" ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::printWithHeader (AC_OutputStream & outputStream) const {
  printHeader (outputStream) ;
  print (outputStream) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Print BDD with variables
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void printLineWithSeparator (AC_OutputStream & outputStream,
                                    const TC_UniqueArray <int32_t> & inValueSeparation,
                                    const TC_UniqueArray <int32_t> & inBitCounts,
                                    const TC_UniqueArray <char> & inValueArray) {
  int32_t bitIndex = inValueArray.count () - 1 ;
  for (int32_t i=0 ; i<inBitCounts.count () ; i++) {
    outputStream << " " << C_String::spaces (inValueSeparation (i COMMA_HERE)) ;
    for (int32_t j=0 ; j<inBitCounts (i COMMA_HERE) ; j++) {
      outputStream << cStringWithCharacter (inValueArray (bitIndex COMMA_HERE)) ;
      bitIndex -- ;
    }
  }
  outputStream << "\n" ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void internalPrintWithSeparator (AC_OutputStream & outputStream,
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

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::print (AC_OutputStream & outputStream,
                   const TC_UniqueArray <C_String> & inVariablesNames,
                   const TC_UniqueArray <int32_t> & inBitCounts) const {
//--- Build separators
  TC_UniqueArray <int32_t> variableNameSeparation ;
  TC_UniqueArray <int32_t> valuesSeparation ;
  for (int32_t i=0 ; i<inVariablesNames.count () ; i++) {
    const int32_t variableLength = inVariablesNames (i COMMA_HERE).length () ;
    const int32_t bitCount = inBitCounts (i COMMA_HERE) ;
    const int32_t length = (variableLength > bitCount) ? variableLength : bitCount ;
    variableNameSeparation.addObject (length - variableLength) ;
    valuesSeparation.addObject (length - bitCount) ;
  }
//--- Print header
  for (int32_t i=0 ; i<inVariablesNames.count () ; i++) {
    outputStream << " " << C_String::spaces (variableNameSeparation (i COMMA_HERE)) << inVariablesNames (i COMMA_HERE) ;
  }
  outputStream << "\n" ;
//--- Print value
  print (outputStream, valuesSeparation, inBitCounts, 1) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::print (AC_OutputStream & outputStream,
                   const TC_UniqueArray <int32_t> & inValueSeparation,
                   const TC_UniqueArray <int32_t> & inBitCounts,
                   const int32_t inPrefixedSpaceCount) const {
  if (mBDDvalue == 0) {
    outputStream << C_String::spaces (inPrefixedSpaceCount) << "(false)\n" ;
  }else if (mBDDvalue == 1) {
    outputStream << C_String::spaces (inPrefixedSpaceCount) << "(true)\n" ;
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

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Graphviz representation
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void buildGraphvizRepresentation (C_String & ioString,
                                         const C_String & inSourceNode,
                                         const uint32_t inBDDValue,
                                         const TC_UniqueArray <C_String> & inBitNames) {
  const uint32_t nodeIndex = nodeIndexForRoot (inBDDValue COMMA_HERE) ;
  const int32_t var = (int32_t) gNodeArray [nodeIndex].mVariableIndex ;
  const C_String node = C_String ("N") + cStringWithUnsigned (nodeIndex) ;
  if (! isNodeMarkedThenMark (inBDDValue COMMA_HERE)) {
    const uint32_t THENbranch = gNodeArray [nodeIndex].mTHEN ;
    C_String THENlabel ;
    if (THENbranch == 0) {
      THENlabel << "F" ;
    }else if (THENbranch == 1) {
      THENlabel << "T" ;
    }else{
      THENlabel << "<f1>" ;
    }
    const uint32_t ELSEbranch = gNodeArray [nodeIndex].mELSE ;
    C_String ELSElabel ;
    if (ELSEbranch == 0) {
      ELSElabel << "F" ;
    }else if (ELSEbranch == 1) {
      ELSElabel << "T" ;
    }else{
      ELSElabel << "<f0>" ;
    }
    ioString << "  " << node << " [label=\"{" << inBitNames (var COMMA_HERE) << "|{" << ELSElabel << "|" << THENlabel << "}}\"]\n" ;
    if (ELSEbranch > 1) {
      buildGraphvizRepresentation (ioString, node + ":f0:c", ELSEbranch, inBitNames) ;
    }
    if (THENbranch > 1) {
      buildGraphvizRepresentation (ioString, node + ":f1:c", THENbranch, inBitNames) ;
    }
  }
  ioString << "  " << inSourceNode << " -> " << node << "" ;
  if ((inBDDValue & 1) != 0) {
    ioString << " [dir=both, arrowtail=dot]" ;
  }
  ioString << " ;\n" ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_BDD::graphvizRepresentation (void) const {
  int32_t varCount = 0 ;
  if (mBDDvalue > 1) {
    const uint32_t nodeIndex = nodeIndexForRoot (mBDDvalue COMMA_HERE) ;
    varCount = ((int32_t) gNodeArray [nodeIndex].mVariableIndex) + 1 ;
  }
  TC_UniqueArray <C_String> bitNames ;
  for (int32_t i=0 ; i<varCount ; i++) {
    bitNames.addObject (cStringWithSigned (i)) ;
  }
  return graphvizRepresentationWithNames (bitNames) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_BDD::graphvizRepresentationWithNames (const TC_UniqueArray <C_String> & inBitNames) const {
  unmarkAllExistingBDDnodes () ;
  C_String result ;
  result << "digraph G {\n" ;
  if (mBDDvalue == 0) {
    result << "  N [label=\"F\", shape=rectangle]\n" ;
  }else if (mBDDvalue == 1) {
    result << "  N [label=\"T\", shape=rectangle]\n" ;
  }else{
    result << "  edge [arrowhead=vee, tailclip=false]\n"
           << "  node [fontname=courier, shape=record]\n"
           << "  N [label=\"\", shape=rectangle]\n" ;
    buildGraphvizRepresentation (result, "N", mBDDvalue, inBitNames) ;
  }
  result << "}\n" ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark String array representation
#endif

//---------------------------------------------------------------------------------------------------------------------*

static void
internalPrintBDDInLittleEndianStringArray (const uint32_t inValue,
                               C_String & ioDisplayString,
                               uint32_t inVariableIndex,
                               TC_UniqueArray <C_String> & outStringArray
                               COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  const uint32_t complement = inValue & 1 ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    if (complement == 1) {
      outStringArray.addObject (ioDisplayString) ;
    }
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    while (inVariableIndex > var) {
      ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('X'), (int32_t) inVariableIndex COMMA_THERE) ;
      inVariableIndex -- ;
    }
  //--- Branche Zero
    const uint32_t branche0 = gNodeArray [nodeIndex].mELSE ^ complement ;
    if (branche0 != 0) {
      ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('0'), (int32_t) var COMMA_HERE) ;
      if (branche0 == 1) {
        for (uint32_t i=0 ; i<var ; i++) {
          ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('X'), (int32_t) i COMMA_HERE) ;
        }
        outStringArray.addObject (ioDisplayString) ;
      }else{
        internalPrintBDDInLittleEndianStringArray (branche0, ioDisplayString, (uint32_t) (inVariableIndex - 1), outStringArray COMMA_THERE) ;
      }
    }
  //--- Branche 1
    const uint32_t branche1 = gNodeArray [nodeIndex].mTHEN ^ complement ;
    if (branche1 != 0) {
      ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('1'), (int32_t) var COMMA_HERE) ;
      if (branche1 == 1) {
        for (uint32_t i=0 ; i<var ; i++) {
          ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('X'), (int32_t) i COMMA_HERE) ;
        }
        outStringArray.addObject (ioDisplayString) ;
      }else{
        internalPrintBDDInLittleEndianStringArray (branche1, ioDisplayString, (uint32_t) (inVariableIndex - 1), outStringArray COMMA_THERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::
buildCompressedLittleEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray
                                             COMMA_LOCATION_ARGS) const {
  const uint32_t nodeIndex = nodeIndexForRoot (mBDDvalue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    C_String displayString ;
    for (int32_t i=0 ; i<=((int32_t) gNodeArray [nodeIndex].mVariableIndex) ; i++) {
      displayString << "X" ;
    }
    internalPrintBDDInLittleEndianStringArray (mBDDvalue, displayString, gNodeArray [nodeIndex].mVariableIndex, outStringArray COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::
buildCompressedLittleEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray,
                                             const uint32_t inVariableCount
                                             COMMA_LOCATION_ARGS) const {
  C_String displayString ;
  for (int32_t i=0 ; i<((int32_t) inVariableCount) ; i++) {
    displayString << "X" ;
  }
  internalPrintBDDInLittleEndianStringArray (mBDDvalue, displayString, inVariableCount, outStringArray COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void
internalPrintBDDInBigEndianStringArray (const uint32_t inValue,
                               C_String & ioDisplayString,
                               uint32_t inVariableIndex,
                               const uint32_t inTotalVariableCountMinusOne,
                               TC_UniqueArray <C_String> & outStringArray
                               COMMA_LOCATION_ARGS) {
  const uint32_t nodeIndex = nodeIndexForRoot (inValue COMMA_HERE) ;
  const uint32_t complement = inValue & 1 ;
  if (bothBranches (gNodeArray [nodeIndex]) == 0) {
    if (complement == 1) {
      outStringArray.addObject (ioDisplayString) ;
    }
  }else{
    const uint32_t var = gNodeArray [nodeIndex].mVariableIndex ;
    while (inVariableIndex > var) {
      ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('X'), (int32_t) (inTotalVariableCountMinusOne - inVariableIndex) COMMA_THERE) ;
      inVariableIndex -- ;
    }
  //--- Branche Zero
    const uint32_t branche0 = gNodeArray [nodeIndex].mELSE ^ complement ;
    if (branche0 != 0) {
      ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('0'), (int32_t) (inTotalVariableCountMinusOne - var) COMMA_THERE) ;
      if (branche0 == 1) {
        for (uint32_t i=0 ; i<var ; i++) {
          ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('X'), (int32_t) (inTotalVariableCountMinusOne - i) COMMA_THERE) ;
        }
        outStringArray.addObject (ioDisplayString) ;
      }else{
        internalPrintBDDInBigEndianStringArray (branche0, ioDisplayString, (uint32_t) (inVariableIndex - 1), inTotalVariableCountMinusOne, outStringArray COMMA_THERE) ;
      }
    }
  //--- Branche 1
    const uint32_t branche1 = gNodeArray [nodeIndex].mTHEN ^ complement ;
    if (branche1 != 0) {
      ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('1'), (int32_t) (inTotalVariableCountMinusOne - var) COMMA_HERE) ;
      if (branche1 == 1) {
        for (uint32_t i=0 ; i<var ; i++) {
          ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('X'), (int32_t) (inTotalVariableCountMinusOne - i) COMMA_HERE) ;
        }
        outStringArray.addObject (ioDisplayString) ;
      }else{
        internalPrintBDDInBigEndianStringArray (branche1, ioDisplayString, (uint32_t) (inVariableIndex - 1), inTotalVariableCountMinusOne, outStringArray COMMA_THERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::
buildCompressedBigEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray
                                          COMMA_LOCATION_ARGS) const {
  const uint32_t nodeIndex = nodeIndexForRoot (mBDDvalue COMMA_HERE) ;
  if (bothBranches (gNodeArray [nodeIndex]) != 0) {
    C_String displayString ;
    for (int32_t i=0 ; i<=((int32_t) gNodeArray [nodeIndex].mVariableIndex) ; i++) {
      displayString << "X" ;
    }
    internalPrintBDDInBigEndianStringArray (mBDDvalue, displayString, gNodeArray [nodeIndex].mVariableIndex, gNodeArray [nodeIndex].mVariableIndex, outStringArray COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_BDD::
buildCompressedBigEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray,
                                 const uint32_t inVariableCount
                                 COMMA_LOCATION_ARGS) const {
  C_String displayString ;
  for (int32_t i=0 ; i<((int32_t) inVariableCount) ; i++) {
    displayString << "X" ;
  }
  internalPrintBDDInBigEndianStringArray (mBDDvalue,
                                          displayString,
                                          inVariableCount - 1,
                                          inVariableCount - 1,
                                          outStringArray COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build BDD from value list
#endif

static inline void swapValueArray (uint64_t ioValueArray [],
                                   const int32_t inIndex1,
                                   const int32_t inIndex2) {
  const uint64_t v = ioValueArray [inIndex1] ;
  ioValueArray [inIndex1] = ioValueArray [inIndex2] ;
  ioValueArray [inIndex2] = v ;
}

//----------------------------------------------------------------

static void sortValueArray (uint64_t ioValueArray [],
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

//----------------------------------------------------------------

//#define CHECK_WITH_TRIVIAL_BDD_COMPUTING

//----------------------------------------------------------------

C_BDD C_BDD::buildBDDFromValueList (uint64_t ioValueList [],
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
  //--- Check values are sorted
  //  for (uint32_t i=1 ; i<inValueCount ; i++) {
  //    MF_Assert (ioValueList [i-1] < ioValueList [i], "ioValueList [i-1] < ioValueList [i] for i=%lld, inValueCount:%lld", i, inValueCount) ;
  //  }
  //--- Search for duplicates
    uint32_t duplicates = 0 ;
    for (uint32_t i=1 ; i<inValueCount ; i++) {
      duplicates += ioValueList [i-1] == ioValueList [i] ;
    }
    if (duplicates > 0) {
      printf ("Warning: %u duplicates\n", duplicates) ;
    }
  //--- Translate into BDD
    #ifdef CHECK_WITH_TRIVIAL_BDD_COMPUTING
      C_BDD EXresult ;
    #endif
    C_BDD * accumulatorArray = NULL ;
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
      #ifdef CHECK_WITH_TRIVIAL_BDD_COMPUTING
        EXresult |= C_BDD::varCompareConst (0, inBitCount, C_BDD::kEqual, ioValueList [i]) ;
      #endif
    }
    result.setToTrue () ;
    uint64_t mask = 1UL ;
    for (uint32_t idx=0 ; idx<inBitCount ; idx++) {
      result = (C_BDD ((uint32_t) (((uint32_t) idx) & UINT16_MAX), (referenceValue & mask) != 0) & result) | accumulatorArray [idx] ;
      mask <<= 1 ;
    }
    macroMyDeleteArray (accumulatorArray) ;
    #ifdef CHECK_WITH_TRIVIAL_BDD_COMPUTING
      if (result.integerValue () != EXresult.integerValue ()) {
        printf ("*** error in %s:%d ***\n", __FILE__, __LINE__) ;
        exit (1) ;
      }
    #endif
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

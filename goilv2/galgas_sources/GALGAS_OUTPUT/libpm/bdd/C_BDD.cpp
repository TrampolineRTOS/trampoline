//---------------------------------------------------------------------------*
//                                                                           *
//     BDD package (implementation of ROBDD)                                 *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1999, ..., 2012 Pierre Molinaro.                           *
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
#include "bdd/C_Display_BDD.h"
#include "utilities/TF_sup.h"
#include "bdd/C_BDD-node.h"

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Display Information Messages
#endif

//---------------------------------------------------------------------------*

static bool gDisplaysInformationMessages ;

//---------------------------------------------------------------------------*

bool C_BDD::displaysInformationMessages (void) {
  return gDisplaysInformationMessages ;
}

//---------------------------------------------------------------------------*

void C_BDD::setDisplaysInformationMessages (const bool inFlag) {
  gDisplaysInformationMessages = inFlag ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ITE operation
#endif

//---------------------------------------------------------------------*

PMUInt32 internalITEoperation (const PMUInt32 opf, 
                               const PMUInt32 opg,
                               const PMUInt32 oph) {
  return internalANDoperation (internalANDoperation (opf, opg)     ^ 1,
                               internalANDoperation (opf ^ 1, oph) ^ 1) ^ 1 ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD operators
#endif

//---------------------------------------------------------------------*

void C_BDD::setToFalse (void) {
  mBDDvalue = 0  ;
}

//---------------------------------------------------------------------*

void C_BDD::setToTrue (void) {
  mBDDvalue = 1  ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::ite (const C_BDD & f, const C_BDD & g, const C_BDD & h) {
  return C_BDD (internalITEoperation (f.mBDDvalue, g.mBDDvalue, h.mBDDvalue)) ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::implies (const C_BDD & inOperand) const {
//--- f -> g est defini par (non f) ou g, c'est a dire non (f et (non g))
  return C_BDD (internalANDoperation (mBDDvalue, inOperand.mBDDvalue ^ 1) ^ 1) ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::operator & (const C_BDD & inOperand) const {
  return C_BDD (internalANDoperation (mBDDvalue, inOperand.mBDDvalue)) ;
}

//---------------------------------------------------------------------*

void C_BDD::operator &= (const C_BDD & inOperand) {
   mBDDvalue = internalANDoperation (mBDDvalue, inOperand.mBDDvalue) ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::operator | (const C_BDD & inOperand) const {
  return C_BDD (internalANDoperation (mBDDvalue ^ 1, inOperand.mBDDvalue ^ 1) ^ 1) ;
}

//---------------------------------------------------------------------*

void C_BDD::operator |= (const C_BDD & inOperand) {
  mBDDvalue = internalANDoperation (mBDDvalue ^ 1, inOperand.mBDDvalue ^ 1) ^ 1 ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::operator == (const C_BDD & inOperand) const {
  return C_BDD (internalITEoperation (mBDDvalue, inOperand.mBDDvalue, inOperand.mBDDvalue ^ 1)) ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::operator != (const C_BDD & inOperand) const {
  return C_BDD (internalITEoperation (mBDDvalue, inOperand.mBDDvalue ^ 1, inOperand.mBDDvalue)) ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::operator <= (const C_BDD & inOperand) const {
  return C_BDD (internalANDoperation (mBDDvalue, inOperand.mBDDvalue ^ 1) ^ 1) ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::operator > (const C_BDD & inOperand) const {
  return C_BDD (internalANDoperation (mBDDvalue, inOperand.mBDDvalue ^ 1)) ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::operator < (const C_BDD & inOperand) const {
  return C_BDD (internalANDoperation (mBDDvalue ^ 1, inOperand.mBDDvalue)) ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::operator >= (const C_BDD & inOperand) const {
  return C_BDD (internalANDoperation (mBDDvalue ^ 1, inOperand.mBDDvalue) ^ 1) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Opposite BDD
#endif

//---------------------------------------------------------------------*

static PMUInt32 internalOpposite (const PMUInt32 inValue) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  const PMUInt32 complement = inValue & 1 ;
  PMUInt32 result = 0 ;
  if (node != 0) {
    result = find_or_add (extractVar (node COMMA_HERE),
                          internalOpposite (extractThen (node)),
                          internalOpposite (extractElse (node)) COMMA_HERE) ;
  }
  return result ^ complement ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::getOpposite (void) const {
  return C_BDD (internalOpposite (mBDDvalue)) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Compare BDDs
#endif

//---------------------------------------------------------------------*

C_BDD C_BDD::compareWithBDD (const compareEnum inComparison, const C_BDD & inOperand) const {
  C_BDD result ;
  switch (inComparison) {
  case kEqual :
    result = (* this) == inOperand ;
    break ;
  case kNotEqual :
    result = (* this) != inOperand ;
    break ;
  case kLowerOrEqual :
    result = (* this) <= inOperand ;
    break ;
  case kStrictLower :
    result = (* this) < inOperand ;
    break ;
  case kGreaterOrEqual :
    result = (* this) >= inOperand ;
    break ;
  case kStrictGreater :
    result = (* this) > inOperand ;
    break ;
  default :
    ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Complement BDD
#endif

//---------------------------------------------------------------------*

void C_BDD::negate (void) {
  mBDDvalue ^= 1 ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::operator ~ (void) const {
  return C_BDD (mBDDvalue ^ 1) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD is complemented
#endif

//---------------------------------------------------------------------*

bool C_BDD::isComplemented (void) const {
  return (mBDDvalue & 1) != 0 ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD with constants
#endif

//---------------------------------------------------------------------------*

C_BDD C_BDD::bddWithConstants (const PMUInt32 inValues [],
                               const PMUInt16 inBitCount [],
                               const PMSInt32 inEntryCount) {
  PMUInt32 result = 1 ; // true
  PMUInt16 idx = 0 ;
  for (PMSInt32 i=0 ; i<inEntryCount ; i++) {
    PMUInt32 v = inValues [i] ;
    for (PMUInt16 j=0 ; j<inBitCount [i] ; j++) {
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
  for (PMSInt32 i=0 ; i<inEntryCount ; i++) {
    PMUInt32 v = inValues [i] ;
    for (PMUInt16 j=0 ; j<inBitCount [i] ; j++) {
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

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build BDD from comparison between variables and constant
#endif

//---------------------------------------------------------------------*

static C_BDD construireInfEgal (const PMUInt16 inFirstIndex,
                                const PMUInt16 indiceMax,
                                const PMUInt64 inValue) {
  C_BDD result ;
  if (inFirstIndex < indiceMax) {
    if (((1 << (indiceMax - inFirstIndex)) & inValue) != 0) {
      result = C_BDD (indiceMax, false) | (C_BDD (indiceMax, true) & construireInfEgal (inFirstIndex, (PMUInt16) (indiceMax - 1), inValue)) ;
    }else{
      result = C_BDD (indiceMax, false) & construireInfEgal (inFirstIndex, (PMUInt16) (indiceMax - 1), inValue) ;
    }
  }else{
    result = ((inValue & 1) != 0) ? (~C_BDD ()) : C_BDD (indiceMax, false) ;
  }
  return result ;
}

//---------------------------------------------------------------------*

static C_BDD construireSupEgal (const PMUInt16 inFirstIndex,
                                const PMUInt16 indiceMax,
                                const PMUInt64 inValue) {
  C_BDD result ;
  if (inFirstIndex < indiceMax) {
    if (((1 << (indiceMax - inFirstIndex)) & inValue) == 0) {
      result = C_BDD (indiceMax, true) | (C_BDD (indiceMax, false) & construireSupEgal (inFirstIndex, (PMUInt16) (indiceMax - 1), inValue)) ;
    }else{
      result = C_BDD (indiceMax, true) & construireSupEgal (inFirstIndex, (PMUInt16) (indiceMax - 1), inValue) ;
    }
  }else{
    result = ((inValue & 1) == 0) ? (~C_BDD ()) : C_BDD (indiceMax, true) ;
  }
  return result ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::varCompareConst (const PMUInt16 inFirstIndex,
                              const PMUInt16 inDimension,
                              const compareEnum inComparison,
                              const PMUInt64 inComparisonConstant) {
  if (inDimension == 0) {
    printf ("*** BDD Error in %s:%d: inDimension should be > 0 ***\n", __FILE__, __LINE__) ;
    exit (1) ;
  }
  C_BDD result ;
  PMUInt16 i ;
  PMUInt64 val = inComparisonConstant ;
  const PMUInt16 indiceMax = (PMUInt16) (inFirstIndex + inDimension - 1) ;
  switch (inComparison) {
  case kEqual : case kNotEqual : // on construit l'egalite
    result.mBDDvalue = 1 ;
    for (i = inFirstIndex ; i <= indiceMax ; i++) {
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

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build BDD from comparison between variables
#endif

//---------------------------------------------------------------------*

static C_BDD
construireSupVariable (const PMUInt16 inLeftFirstIndex,
                       const PMUInt16 inDimension,
                       const PMUInt16 inRightFirstIndex) {
  C_BDD result ;
  const C_BDD gauche = C_BDD ((PMUInt16) (inLeftFirstIndex + inDimension - 1), true) ;
  const C_BDD droite = C_BDD ((PMUInt16) (inRightFirstIndex + inDimension - 1), true) ;
  if (inDimension > 1) {
    result = (gauche > droite) |
      ((gauche == droite) &
      construireSupVariable (inLeftFirstIndex, (PMUInt16) (inDimension - 1), inRightFirstIndex)) ;
  }else{
    result = gauche > droite ;
  }
  return result ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::
varCompareVar (const PMUInt16 inLeftFirstIndex,
               const PMUInt16 inDimension,
               const compareEnum inComparison,
               const PMUInt16 inRightFirstIndex) {
  C_BDD result ;
  switch (inComparison) {
  case kEqual : case kNotEqual :
    result = ~ result ;
    for (PMUInt16 i=0 ; i<inDimension ; i++) {
      result &= C_BDD ((PMUInt16) (inLeftFirstIndex + i), false) == C_BDD ((PMUInt16) (inRightFirstIndex + i), false) ;
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

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Needed Variable Count
#endif

//---------------------------------------------------------------------*

PMUInt16 C_BDD::
significantVariableCount (void) const {
  PMUInt16 bitCount = 0 ;
  const PMUInt64 node = nodeForRoot (mBDDvalue COMMA_HERE) ;
  if (node != 0) {
    bitCount = (PMUInt16) (extractVar (node COMMA_HERE) + 1) ;
  }
  return bitCount ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Test if BDD does contain a value
#endif

//---------------------------------------------------------------------*

//#define DEBUG_CONTAINS_VALUE
 
//---------------------------------------------------------------------*

static bool
recursiveContainsValue (const PMUInt32 inBDD,
                        const PMUInt64 inValue,
                        const PMUInt16 inFirstBit,
                        const PMUInt16 inLastBitPlusOne) {
  bool result ;
  const PMUInt64 node = nodeForRoot (inBDD COMMA_HERE) ;
  const PMUInt32 complement = inBDD & 1 ;
  if (node == 0) {
    result = complement != 0 ;
    #ifdef DEBUG_CONTAINS_VALUE
      printf ("result %s\n", result ? "YES" : "NO") ;
    #endif
  }else{
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    if (var >= inLastBitPlusOne) {
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u\n", var) ;
      #endif
      result = recursiveContainsValue (extractThen (node) ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u branch THEN returns %s\n", var, result ? "YES" : "NO") ;
      #endif
      if (! result) {
        result = recursiveContainsValue (extractElse (node) ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
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
        result = recursiveContainsValue (extractThen (node) ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      }else{
        result = recursiveContainsValue (extractElse (node) ^ complement, inValue, inFirstBit, inLastBitPlusOne) ;
      }
      #ifdef DEBUG_CONTAINS_VALUE
        printf ("var %u, bitvalue %s returns %s\n", var, bitValue ? "YES" : "NO", result ? "YES" : "NO") ;
      #endif
    }
  }
  return result ;
}

//---------------------------------------------------------------------*

bool C_BDD::
containsValue (const PMUInt64 inValue,
               const PMUInt16 inFirstBit,
               const PMUInt16 inBitCount) const {
  return recursiveContainsValue (mBDDvalue,
                                 inValue,
                                 inFirstBit,
                                 (PMUInt16) (inFirstBit + inBitCount)) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Traverse BDD values
#endif

//---------------------------------------------------------------------*

static void parcoursBDDinterneParNoeud (const PMUInt32 inValue,
                                        C_bdd_node_traversing & inTraversing) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  if ((node != 0) && ! isNodeMarkedThenMark (inValue COMMA_HERE)) {
    parcoursBDDinterneParNoeud (extractElse (node), inTraversing) ;
    parcoursBDDinterneParNoeud (extractThen (node), inTraversing) ;
    inTraversing.action (inValue & ~1U,
                         extractVar (node COMMA_HERE),
                         extractElse (node),
                         extractThen (node) & ~1U,
                         extractThen (node) & 1) ;
  }
}

//---------------------------------------------------------------------*

void C_BDD::traversBDDnodes (C_bdd_node_traversing & inTraversing) const {
  parcoursBDDinterneParNoeud (mBDDvalue, inTraversing) ;
}

//---------------------------------------------------------------------*

static void
parcoursBDDinterneParValeur (const PMUInt32 inValue,
                             C_bdd_value_traversing & inTraversing,
                             bool tableauDesValeurs [],
                             PMUInt16 variableCourante,
                             const PMUInt16 inBDDvariablesCount) {
  if (variableCourante != 0) {
    variableCourante -- ;
    if (inValue == 1) {
      tableauDesValeurs [variableCourante] = false ;
      parcoursBDDinterneParValeur (inValue, inTraversing, tableauDesValeurs, variableCourante, inBDDvariablesCount) ;
      tableauDesValeurs [variableCourante] = true ;
      parcoursBDDinterneParValeur (inValue, inTraversing, tableauDesValeurs, variableCourante, inBDDvariablesCount) ;
    }else if (inValue != 0) {
      const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
      const PMUInt16 variable = extractVar (node COMMA_HERE) ;
      if (variable == variableCourante) {
        const PMUInt32 complement = inValue & 1 ;
        tableauDesValeurs [variableCourante] = false ;
        parcoursBDDinterneParValeur (extractElse (node) ^ complement, inTraversing, tableauDesValeurs, variableCourante, inBDDvariablesCount) ;
        tableauDesValeurs [variableCourante] = true ;
        parcoursBDDinterneParValeur (extractThen (node) ^ complement, inTraversing, tableauDesValeurs, variableCourante, inBDDvariablesCount) ;
      }else if (variable < variableCourante) {
        tableauDesValeurs [variableCourante] = false ;
        parcoursBDDinterneParValeur (inValue, inTraversing, tableauDesValeurs, variableCourante, inBDDvariablesCount) ;
        tableauDesValeurs [variableCourante] = true ;
        parcoursBDDinterneParValeur (inValue, inTraversing, tableauDesValeurs, variableCourante, inBDDvariablesCount) ;
      }
    }
  }else if (inValue == 1) {
    inTraversing.action (tableauDesValeurs, inBDDvariablesCount) ;  
  }
}

//---------------------------------------------------------------------*

void C_BDD::traverseBDDvalues (C_bdd_value_traversing & inTraversing,
                               const PMUInt16 inBDDvariablesCount) const {
  bool * tableauDesValeurs = NULL ;
  macroMyNewArray (tableauDesValeurs, bool, inBDDvariablesCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, inTraversing, tableauDesValeurs, inBDDvariablesCount, inBDDvariablesCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build an array of PMUInt64 values
#endif

//---------------------------------------------------------------------*

class C_build_values_array : public C_bdd_value_traversing {
  private : TC_UniqueArray <PMUInt64> * mPtr ;

  public : inline C_build_values_array (TC_UniqueArray <PMUInt64> * inPtr) :
  mPtr (inPtr) {
  }

//--- No copy
  private : C_build_values_array (const C_build_values_array &) ;
  private : C_build_values_array & operator = (const C_build_values_array &) ;

//--- Virtual method called for every value
  public : virtual void action (const bool tableauDesValeurs [],
                                const PMUInt16 inBDDvariablesCount) ;
} ;

//---------------------------------------------------------------------*

void C_build_values_array::
action (const bool tableauDesValeurs [],
        const PMUInt16 inBDDvariablesCount) {
  PMUInt64 value = 0 ;
  for (PMUInt16 i=1 ; i<=inBDDvariablesCount ; i++) {
    value = (value << 1) | tableauDesValeurs [inBDDvariablesCount - i] ;
  }
  mPtr->addObject (value) ;
}

//---------------------------------------------------------------------*

void C_BDD::buildValueArray (TC_UniqueArray <PMUInt64> & outValuesArray,
                              const PMUInt16 inBDDvariablesCount) const {
  outValuesArray.setCountToZero () ;
  C_build_values_array builder (& outValuesArray) ;
  bool * tableauDesValeurs = NULL ;
  macroMyNewArray (tableauDesValeurs, bool, inBDDvariablesCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, builder, tableauDesValeurs, inBDDvariablesCount, inBDDvariablesCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build an array of string values
#endif

//---------------------------------------------------------------------*

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
                                const PMUInt16 inBDDvariablesCount) ;
} ;

//---------------------------------------------------------------------*

void cLittleEndianStringValueBuilder::
action (const bool tableauDesValeurs [],
        const PMUInt16 inBDDvariablesCount) {
  C_String value ;
  for (PMUInt16 i=0 ; i<inBDDvariablesCount ; i++) {
    value << cStringWithCharacter ((char) ('0' + tableauDesValeurs [i])) ;
  }
  mPtr->addObject (value) ;
}

//---------------------------------------------------------------------*

void C_BDD::
buildLittleEndianStringValueArray (TC_UniqueArray <C_String> & outValuesArray,
                                   const PMUInt16 inBDDvariablesCount) const {
  outValuesArray.setCountToZero () ;
  cLittleEndianStringValueBuilder builder (& outValuesArray) ;
  bool * tableauDesValeurs = NULL ;
  macroMyNewArray (tableauDesValeurs, bool, inBDDvariablesCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, builder, tableauDesValeurs, inBDDvariablesCount, inBDDvariablesCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//---------------------------------------------------------------------*

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
                                const PMUInt16 inBDDvariablesCount) ;
} ;

//---------------------------------------------------------------------*

void cBuildBigEndianStringValueArray::
action (const bool tableauDesValeurs [],
        const PMUInt16 inBDDvariablesCount) {
  C_String value ;
  for (PMUInt16 i=inBDDvariablesCount ; i>0 ; i--) {
    value << cStringWithCharacter ((char) ('0' + tableauDesValeurs [i-1])) ;
  }
  mPtr->addObject (value) ;
}

//---------------------------------------------------------------------*

void C_BDD::
buildBigEndianStringValueArray (TC_UniqueArray <C_String> & outValuesArray,
                                const PMUInt16 inBDDvariablesCount) const {
  outValuesArray.setCountToZero () ;
  cBuildBigEndianStringValueArray builder (& outValuesArray) ;
  bool * tableauDesValeurs = NULL ;
  macroMyNewArray (tableauDesValeurs, bool, inBDDvariablesCount) ;
  parcoursBDDinterneParValeur (mBDDvalue, builder, tableauDesValeurs, inBDDvariablesCount, inBDDvariablesCount) ;
  macroMyDeleteArray (tableauDesValeurs) ;
}

//---------------------------------------------------------------------*

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
                                const PMUInt16 inBDDvariablesCount) ;
} ;

//---------------------------------------------------------------------*

void cBuildQueryString::
action (const bool tableauDesValeurs [],
        const PMUInt16 inBDDvariablesCount) {
  C_String value ;
  if (mStringPtr->length () > 0) {
    *mStringPtr << "|" ;
  }
  for (PMUInt16 i=inBDDvariablesCount ; i>0 ; i--) {
    *mStringPtr << cStringWithCharacter ((char) ('0' + tableauDesValeurs [i-1])) ;
  }
}

//---------------------------------------------------------------------*

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
      for (PMSInt32 i=1 ; i<stringArray.count () ; i++) {
        s << "|" << stringArray (i COMMA_HERE) ;
      }
    }
  }
  return s ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Value Count
#endif

//---------------------------------------------------------------------------*

C_BDD C_BDD::BDDWithPredicateString (const C_String & inPredicateStringValue
                                     COMMA_LOCATION_ARGS) {
  C_BDD result ;
  const PMSInt32 stringLength = inPredicateStringValue.length () ;
  PMSInt32 stringIndex = 0 ;
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
      PMSInt32 bitIndex = 0 ;
      for (PMSInt32 i=s.length () - 1 ; i>=0 ; i--) {
        const utf32 c = s (i COMMA_HERE) ;
        if (UNICODE_VALUE (c) == '0') {
          v &= C_BDD ((PMUInt16) (((PMUInt16) bitIndex) & PMUINT16_MAX), false) ;
          bitIndex ++ ;
        }else if (UNICODE_VALUE (c) == '1') {
          v &= C_BDD ((PMUInt16) (((PMUInt16) bitIndex) & PMUINT16_MAX), true) ;
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

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Value Count
#endif

//---------------------------------------------------------------------*

static void nombreValeursInterne (const PMUInt32 inValue,
                                  const PMUInt16 inBDDvariablesCount,
                                  PMUInt64 & nombreDirect,
                                  PMUInt64 & nombreComplement
                                  COMMA_LOCATION_ARGS) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_THERE) ;
  if (node == 0) {
    nombreDirect = 0 ;
    nombreComplement = 1 ;
    for (PMSInt32 i=0 ; i<inBDDvariablesCount ; i++) {
      nombreComplement += nombreComplement ;
    }
  }else{
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    PMUInt64 nd0, nc0, nd1, nc1 ;
    nombreValeursInterne (extractElse (node), var, nd0, nc0 COMMA_THERE) ;
    nombreValeursInterne (extractThen (node), var, nd1, nc1 COMMA_THERE) ;
    nombreDirect = nd0 + nd1 ;
    nombreComplement = nc0 + nc1 ;
    for (PMUInt16 i=(PMUInt16) (var+1) ; i<inBDDvariablesCount ; i++) {
      nombreDirect += nombreDirect ;
      nombreComplement += nombreComplement ;
    }
  }
  if ((inValue & 1) != 0) {
    const PMUInt64 tempo = nombreDirect ;
    nombreDirect = nombreComplement ;
    nombreComplement = tempo ;
  }
}

//---------------------------------------------------------------------*

PMUInt64 C_BDD::valueCount (const PMUInt16 inBDDvariablesCount) const {
  PMUInt64 nombreDirect = 0 ;
  PMUInt64 nombreComplement = 0 ;
  nombreValeursInterne (mBDDvalue, inBDDvariablesCount, nombreDirect, nombreComplement COMMA_HERE) ;
  return nombreDirect ;
}

//---------------------------------------------------------------------*

static void internalValueCountUsingCache (const PMUInt32 inValue,
                                  const PMUInt16 inBDDvariablesCount,
                                  PMUInt64 & nombreDirect,
                                  PMUInt64 & nombreComplement,
                                  TC_UniqueArray <PMUInt64> & ioDirectCacheArray,
                                  TC_UniqueArray <PMUInt64> & ioComplementCacheArray
                                  COMMA_LOCATION_ARGS) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_THERE) ;
  if (node == 0) {
    nombreDirect = 0 ;
    nombreComplement = 1 ;
    for (PMSInt32 i=0 ; i<inBDDvariablesCount ; i++) {
      nombreComplement += nombreComplement ;
    }
  }else if ((ioDirectCacheArray.count () > (PMSInt32) (inValue / 2))
    && (((ioDirectCacheArray (inValue / 2 COMMA_HERE) != 0) || (ioComplementCacheArray (inValue / 2 COMMA_HERE) != 0)))) {
    nombreDirect = ioDirectCacheArray (inValue / 2 COMMA_HERE) ;
    nombreComplement = ioComplementCacheArray (inValue / 2 COMMA_HERE) ;
  }else{
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    PMUInt64 nd0, nc0, nd1, nc1 ;
    internalValueCountUsingCache (extractElse (node), var, nd0, nc0, ioDirectCacheArray, ioComplementCacheArray COMMA_THERE) ;
    internalValueCountUsingCache (extractThen (node), var, nd1, nc1, ioDirectCacheArray, ioComplementCacheArray COMMA_THERE) ;
    nombreDirect = nd0 + nd1 ;
    nombreComplement = nc0 + nc1 ;
    for (PMUInt16 i=(PMUInt16) (var+1) ; i<inBDDvariablesCount ; i++) {
      nombreDirect += nombreDirect ;
      nombreComplement += nombreComplement ;
    }
    ioDirectCacheArray.forceObjectAtIndex (inValue / 2, nombreDirect, 0 COMMA_HERE) ;
    ioComplementCacheArray.forceObjectAtIndex (inValue / 2, nombreComplement, 0 COMMA_HERE) ;
  }
  if ((inValue & 1) != 0) {
    const PMUInt64 tempo = nombreDirect ;
    nombreDirect = nombreComplement ;
    nombreComplement = tempo ;
  }
}

//---------------------------------------------------------------------*

PMUInt64 C_BDD::valueCountUsingCache (const PMUInt16 inBDDvariablesCount,
                                    TC_UniqueArray <PMUInt64> & ioDirectCacheArray,
                                    TC_UniqueArray <PMUInt64> & ioComplementCacheArray) const {
  PMUInt64 nombreDirect = 0 ;
  PMUInt64 nombreComplement = 0 ;
  internalValueCountUsingCache (mBDDvalue, inBDDvariablesCount, nombreDirect, nombreComplement, ioDirectCacheArray, ioComplementCacheArray COMMA_HERE) ;
  return nombreDirect ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Get i-th value as BDD
#endif

//---------------------------------------------------------------------*

static C_BDD
obtenirIemeBDDinterne (const PMUInt32 inValue,
                       const PMUInt64 inNthBDDvalue,
                       const PMUInt16 inBDDvariablesCount) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  const PMUInt32 complement = inValue & 1 ;
  PMUInt64 iEme ;
  C_BDD result ;
  if (node == 0) {
    if (complement == 1) { // Decomposer inNthBDDvalue en binaire
      result = ~ result ;
      iEme = inNthBDDvalue ;
      for (PMUInt16 i=0 ; i<inBDDvariablesCount ; i++) {
        result = result & C_BDD (i, ((iEme & 1) == 0) ? false : true) ;
        iEme >>= 1 ;
      }
    }
  }else{
    result = ~ result ;
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    PMUInt64 nd0 = 0UL ;
    PMUInt64 nc0 = 0UL ; // Non utilise ici
    nombreValeursInterne (extractElse (node) ^ complement, (PMUInt16) (inBDDvariablesCount - 1), nd0, nc0 COMMA_HERE) ;
    PMUInt64 nd1 = 0UL ;
    PMUInt64 nc1 = 0UL ; // Non utilise ici
    nombreValeursInterne (extractThen (node) ^ complement, (PMUInt16) (inBDDvariablesCount - 1), nd1, nc1 COMMA_HERE) ;
    PMUInt64 total = nd0 + nd1 ;
    for (PMUInt16 i = (PMUInt16) (inBDDvariablesCount-1) ; i>var ; i--) {
      total >>= 1 ;
      nd0 >>= 1 ;
    }
    iEme = inNthBDDvalue % total ;
    PMUInt64 quotient = inNthBDDvalue / total ;
    for (PMUInt16 j = (PMUInt16) (var+1) ; j<inBDDvariablesCount ; j++) {
      result = result & C_BDD (j, ((quotient & 1) == 0) ? false : true) ;
      quotient >>= 1 ;
    }
    if (iEme < nd0) {
      result = result & C_BDD (var, false) & obtenirIemeBDDinterne (extractElse (node) ^ complement, iEme, var) ;
    }else if (iEme < total) {
      result = result & C_BDD (var, true) & obtenirIemeBDDinterne (extractThen (node) ^ complement, iEme - nd0, var) ;
    }else{
      result = C_BDD () ; // Vide
    }
  }
  return result ;
}

//---------------------------------------------------------------------*

C_BDD C_BDD::getNthBDD (const PMUInt64 inNthBDDvalue,
                        const PMUInt16 inBDDvariablesCount) const {
  return obtenirIemeBDDinterne (mBDDvalue, inNthBDDvalue, inBDDvariablesCount) ;
}
  

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Get i-th value as PMUInt64
#endif

//---------------------------------------------------------------------*

static PMUInt64
obtenirValeurAbsolueBDDInterne (const PMUInt32 inValue) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  const PMUInt32 complement = inValue & 1 ;
  PMUInt64 result = 1 ^ complement ;
  if (node != 0) {
    if ((extractElse (node) ^ complement) != 0) {
      result = obtenirValeurAbsolueBDDInterne (extractElse (node) ^ complement) ;
    }else{
      result = 1 ;
      for (PMUInt32 i = 1 ; i <= extractVar (node COMMA_HERE) ; i++) {
        result <<= 1 ;
      }
      result += obtenirValeurAbsolueBDDInterne (extractThen (node) ^ complement) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------*

PMUInt64 C_BDD::getBDDabsoluteValue (const PMUInt16 inBDDvariablesCount) const {
  PMUInt64 result = 0 ;
  if (valueCount (inBDDvariablesCount) == 1) {
    result = obtenirValeurAbsolueBDDInterne (mBDDvalue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD range
#endif

//---------------------------------------------------------------------*

static PMUInt64
rangBDDinterne (const PMUInt32 inValue,
                const PMUInt32 valeurTestee,
                const PMUInt16 inBDDvariablesCount) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  const PMUInt64 testedValueNode = nodeForRoot (valeurTestee COMMA_HERE) ;
  const PMUInt32 complementValeurTestee = valeurTestee & 1 ;
  const PMUInt32 complement = inValue & 1 ;
  PMUInt64 rang = 0 ;
  PMUInt64 nc ; // non utilise
  if (testedValueNode == 0) {
  }else if ((extractElse (testedValueNode) ^ complementValeurTestee) == 0) {
    if (node == 0) {
      rang = 1UL << extractVar (testedValueNode COMMA_HERE) ;
      rang += rangBDDinterne (inValue, extractThen (testedValueNode) ^ complementValeurTestee, (PMUInt16) (inBDDvariablesCount - 1)) ;
    }else if (extractVar (node COMMA_HERE) == extractVar (testedValueNode COMMA_HERE)) {
      nombreValeursInterne (extractElse (node) ^ complement, (PMUInt16) (inBDDvariablesCount - 1), rang, nc COMMA_HERE) ;
      rang += rangBDDinterne (extractThen (node) ^ complement, extractThen (testedValueNode) ^ complementValeurTestee, (PMUInt16) (inBDDvariablesCount - 1)) ;
    }else{
      nombreValeursInterne (inValue, (PMUInt16) (inBDDvariablesCount - 1), rang, nc COMMA_HERE) ;
      rang += rangBDDinterne (inValue, extractThen (testedValueNode) ^ complementValeurTestee, (PMUInt16) (inBDDvariablesCount - 1)) ;
    }
  }else{
    if (node == 0) {
      rang = rangBDDinterne (inValue, extractElse (testedValueNode) ^ complementValeurTestee, (PMUInt16) (inBDDvariablesCount - 1)) ;
    }else if (extractVar (node COMMA_HERE) == extractVar (testedValueNode COMMA_HERE)) {
      rang = rangBDDinterne (extractElse (node) ^ complement, extractElse (testedValueNode) ^ complementValeurTestee, (PMUInt16) (inBDDvariablesCount - 1)) ;
    }else{
      rang = rangBDDinterne (inValue, extractElse (testedValueNode) ^ complementValeurTestee, (PMUInt16) (inBDDvariablesCount - 1)) ;
    }
  }
  return rang ;
}

//---------------------------------------------------------------------*

PMUInt64 C_BDD::
getBDDrange (const C_BDD & inOperand,
             const PMUInt16 inBDDvariablesCount) const {
  PMUInt64 rang = 0 ;
  if (inOperand.valueCount (inBDDvariablesCount) == 1) {
    rang = rangBDDinterne (mBDDvalue, inOperand.mBDDvalue, inBDDvariablesCount) ;
  }
  return rang ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Node Count
#endif

//---------------------------------------------------------------------*

static PMUInt32 internalRecursiveNodeCount (const PMUInt32 inValue) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  PMUInt32 n = 0 ;
  if (node != 0ULL) {
    if (! isNodeMarkedThenMark (inValue COMMA_HERE)) {
      n = 1 ;
      n += internalRecursiveNodeCount (extractElse (node)) ;
      n += internalRecursiveNodeCount (extractThen (node)) ;
    }
  }
  return n ;
}

//---------------------------------------------------------------------*

PMUInt32 C_BDD::getBDDnodesCount (void) const {
  PMUInt32 result = 0 ;
  if (nodeForRoot (mBDDvalue COMMA_HERE) != 0) {
    unmarkAllExistingBDDnodes () ;
    result = internalRecursiveNodeCount (mBDDvalue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Boolean array
#endif

//---------------------------------------------------------------------------*

class cBuildArrayForSet : public C_bdd_value_traversing {
//--- Attributs
  protected : TC_UniqueArray <bool> & mArray ;

//--- Constructeur
  public : cBuildArrayForSet (TC_UniqueArray <bool> & outArray) ;

//--- Methode virtuelle appelee pour chaque valeur
  public : virtual void action (const bool inValuesArray [],
                                const PMUInt16 inBDDbitsSize) ;
} ;
  
//---------------------------------------------------------------------------*

cBuildArrayForSet::
cBuildArrayForSet (TC_UniqueArray <bool> & outArray) :
mArray (outArray) {
}

//---------------------------------------------------------------------------*

void cBuildArrayForSet::
action (const bool inValuesArray [],
        const PMUInt16 inBDDbitsSize) {
  PMSInt32 element = 0L ;
  for (PMSInt32 i=inBDDbitsSize - 1 ; i>=0 ; i--) {
    element = (element << 1) + inValuesArray [i] ;
  }
  mArray (element COMMA_HERE) = true ;
}

//----------------------------------------------------------------------------*

void C_BDD::
getBoolArray (TC_UniqueArray <bool> & outArray,
              const PMUInt32 inMaxValues,
              const PMUInt16 inBitSize) const {
  outArray.setCountToZero () ;
  outArray.makeRoom ((PMSInt32) inMaxValues) ;
  outArray.addObjects ((PMSInt32) inMaxValues, false) ;
  cBuildArrayForSet s (outArray) ;
  traverseBDDvalues (s, inBitSize) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD as N-relation
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   U P D A T E   R E L A T I O N                                           *
//                                                                           *
//---------------------------------------------------------------------------*

static PMUInt32
internalRecursiveUpdateRelation (const PMUInt32 inValue,
                                 const PMUInt16 inTranslationVector []) {
  PMUInt32 result = inValue ;
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  if (node != 0) {
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    if (inTranslationVector [var] != var) {
      const PMUInt32 complement = inValue & 1 ;
      result = internalITEoperation (
        find_or_add (inTranslationVector [var], 1, 0 COMMA_HERE),
        internalRecursiveUpdateRelation (extractElse (node) ^ complement, inTranslationVector),
        internalRecursiveUpdateRelation (extractThen (node) ^ complement, inTranslationVector)
      ) ;
      PMUInt16 preceeding = (PMUInt16) (inTranslationVector [var - 1] + 1) ;
      while (preceeding < inTranslationVector [var]) {
        result = internalITEoperation (find_or_add (preceeding, 1, 0 COMMA_HERE), result, 0) ;
        preceeding ++ ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_BDD C_BDD::
updateRelation (const PMUInt16 inRelationBitNeededCount [], 
                PMUInt16 * inRelationBitCurrentCount [], 
                const PMSInt32 inRelationCardinality) const {
  PMUInt32 result = mBDDvalue ;
//--- Check if update is needed
  bool updateIsNeeded = false ;
  for (PMSInt32 i=0 ; (i<inRelationCardinality) && ! updateIsNeeded ; i++) {
    updateIsNeeded = inRelationBitNeededCount [i] > * (inRelationBitCurrentCount [i]) ;
  }
//--- Perform updating
  if (updateIsNeeded) {
    //printf ("BEFORE '%s'\n", queryStringValue ().cString (HERE)) ;
    PMUInt16 totalCurrentBitCount = 0 ;
    PMUInt16 newNeededTotalBitCount = 0 ;
    for (PMSInt32 i=0 ; i<inRelationCardinality ; i++) {
      totalCurrentBitCount = (PMUInt16) (totalCurrentBitCount + * (inRelationBitCurrentCount [i])) ;
      newNeededTotalBitCount = (PMUInt16) (newNeededTotalBitCount + inRelationBitNeededCount [i]) ;
    }
    PMUInt16 * translationVector = NULL ;
    macroMyNewArray (translationVector, PMUInt16, totalCurrentBitCount) ;
    PMSInt32 idx = 0 ;
    PMSInt32 newIdx = 0 ;
    for (PMSInt32 i=0 ; i<inRelationCardinality ; i++) {
      for (PMSInt32 j=0 ; j<* (inRelationBitCurrentCount [i]) ; j++) {
        translationVector [idx] = (PMUInt16) (((PMUInt16)(newIdx + j)) & PMUINT16_MAX) ;
        idx ++ ;
      }
      newIdx += inRelationBitNeededCount [i] ;
    }
    printf ("[") ;
    for (PMSInt32 i=0 ; i<totalCurrentBitCount ; i++) {
      printf (" %u", translationVector [i]) ;
    }
    printf ("] %u\n", newNeededTotalBitCount) ;
    result = internalRecursiveUpdateRelation (mBDDvalue, translationVector) ;
    PMUInt16  finalTranslatedIndex = (PMUInt16) (newNeededTotalBitCount
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
    for (PMSInt32 i=0 ; i<inRelationCardinality; i++) {
      //printf ("%d -> %d\n", * (inRelationBitCurrentCount [i]), inRelationBitNeededCount [i]) ;
      * (inRelationBitCurrentCount [i]) = inRelationBitNeededCount [i] ;
    }
  }
//---
  return C_BDD (result) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD as 2-relation
#endif

//---------------------------------------------------------------------------*

C_BDD C_BDD::
swap21 (const PMUInt16 inBitSize1,
        const PMUInt16 inBitSize2) const {
  const PMUInt16 totalSize = (PMUInt16) (inBitSize1 + inBitSize2) ;
  PMUInt16 * tab = NULL ;
  macroMyNewArray (tab, PMUInt16, totalSize) ;
  for (PMUInt16 i=0 ; i<inBitSize1 ; i++) {
    tab [i] = (PMUInt16) (i + inBitSize2) ;
  }
  for (PMUInt16 j=0 ; j<inBitSize2 ; j++) {
    tab [j + inBitSize1] = j ;
  }
  const C_BDD result = substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return result ;
}

//---------------------------------------------------------------------------*

C_BDD C_BDD::
accessibleStates (const C_BDD & inInitialStateSet,
                  const PMUInt16 inBitSize,
                  PMSInt32 * outIterationCount) const {
//--- Current object is edge [x, y].
//    Accessible states set is computed by:
// accessible [x] += initial [x] | exists y (accessible [y] & edge [y, x]) ;
//
//--- Compute edge [y, x]
  const C_BDD edgeYX = swap21 (inBitSize, inBitSize) ;
  C_BDD accessible = inInitialStateSet ;
  C_BDD v ;
  C_BDD accessibleY ;
  PMSInt32 iterationCount = 0 ;
  do{
    v = accessible ;
    iterationCount ++ ;
    accessibleY = accessible.translate (inBitSize, inBitSize) ;
    accessible |= (accessibleY & edgeYX).existsOnBitsAfterNumber (inBitSize) ;
  }while (! v.isEqualToBDD (accessible)) ;
  if (outIterationCount != NULL) {
    * outIterationCount = iterationCount ;
  }
  return accessible ;
}

//---------------------------------------------------------------------------*

C_BDD C_BDD::
transitiveClosure (const PMUInt16 inBitSize,
                   PMSInt32 * outIterationCount) const {
//--- Transitive closure is computed by:
// closure [x, y] += relation [x, y] | exists z (closure [x, z] & closure [z, y]) ;
  C_BDD closure = *this ;
  C_BDD XZclosure ;
  C_BDD ZYclosure ;
  C_BDD v ;
  const PMUInt16 bitCount2 = (PMUInt16) (inBitSize + inBitSize) ;
  PMSInt32 iterationCount = 0 ;
  do{
    v = closure ;
    iterationCount ++ ;
    XZclosure = closure.swap132 (inBitSize, inBitSize, inBitSize) ;
    ZYclosure = closure.swap321 (inBitSize, inBitSize, inBitSize) ;
    closure |= (XZclosure & ZYclosure).existsOnBitsAfterNumber (bitCount2) ;
  }while (! closure.isEqualToBDD (v)) ;
  if (outIterationCount != NULL) {
    * outIterationCount = iterationCount ;
  }
  return closure ;
}

//---------------------------------------------------------------------------*

class cBuildArrayForRelation2 : public C_bdd_value_traversing {
//--- Attributes
  protected : TC_UniqueArray <TC_UniqueArray <PMSInt32> > & mArray ;
  protected : PMUInt16 mBitsSize1 ;

//--- Constructor
  public :
  cBuildArrayForRelation2 (TC_UniqueArray <TC_UniqueArray <PMSInt32> > & outArray,
                           const PMUInt16 inBitsSize1) ;

//--- Virtual method called for every value
  public : virtual void action (const bool inValuesArray [],
                                const PMUInt16 inBDDbitsSize) ;
} ;
  
//---------------------------------------------------------------------------*

cBuildArrayForRelation2::
cBuildArrayForRelation2 (TC_UniqueArray <TC_UniqueArray <PMSInt32> > & outArray,
                         const PMUInt16 inBitsSize1) :
mArray (outArray),
mBitsSize1 (inBitsSize1) {
}

//---------------------------------------------------------------------------*

void cBuildArrayForRelation2::
action (const bool inValuesArray [],
        const PMUInt16 inBDDbitsSize) {
  PMSInt32 index1 = 0L ;
  PMSInt32 index2 = 0L ;
  for (PMSInt32 i=mBitsSize1 - 1 ; i>=0 ; i--) {
    index1 = (index1 << 1) + inValuesArray [i] ;
  }
  for (PMSInt32 j=inBDDbitsSize - 1 ; j>=mBitsSize1 ; j--) {
    index2 = (index2 << 1) + inValuesArray [j] ;
  }
  mArray (index1 COMMA_HERE).addObject (index2) ;
}

//----------------------------------------------------------------------------*

void C_BDD::
getArray2 (TC_UniqueArray <TC_UniqueArray <PMSInt32> > & outArray,
           const PMUInt32 inMaxValueCount,
           const PMUInt16 inBitSize1,
           const PMUInt16 inBitSize2) const {
  outArray.setCountToZero () ;
  outArray.makeRoomUsingSwap ((PMSInt32) inMaxValueCount) ;
  for (PMUInt32 i=0 ; i<inMaxValueCount ; i++) {
    outArray.addDefaultObjectUsingSwap () ;
  }
  cBuildArrayForRelation2 s (outArray, inBitSize1) ;
  traverseBDDvalues (s, (PMUInt16) (inBitSize1 + inBitSize2)) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark BDD as 3-relation
#endif

//----------------------------------------------------------------------------*

C_BDD C_BDD::
swap132 (const PMUInt16 inBitSize1,
         const PMUInt16 inBitSize2,
         const PMUInt16 inBitSize3) const {
  const PMUInt16 totalSize = (PMUInt16) (inBitSize1 + inBitSize2 + inBitSize3) ;
  PMUInt16 * tab = NULL ;
  macroMyNewArray (tab, PMUInt16, totalSize) ;
  for (PMUInt16 i=0 ; i<inBitSize1 ; i++) {
    tab [i] = i ;
  }
  for (PMUInt16 j=0 ; j<inBitSize2 ; j++) {
    tab [j + inBitSize1] = (PMUInt16) (j + inBitSize1 + inBitSize3) ;
  }
  for (PMUInt16 k=0 ; k<inBitSize3 ; k++) {
    tab [k + inBitSize1 + inBitSize2] = (PMUInt16) (k + inBitSize1) ;
  }
  const C_BDD bdd = substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return bdd ;
}

//----------------------------------------------------------------------------*

C_BDD C_BDD::
swap231 (const PMUInt16 inBitSize1,
         const PMUInt16 inBitSize2,
         const PMUInt16 inBitSize3) const {
  const PMUInt16 totalSize = (PMUInt16) (inBitSize1 + inBitSize2 + inBitSize3) ;
  PMUInt16 * tab = NULL ;
  macroMyNewArray (tab, PMUInt16, totalSize) ;
  for (PMUInt16 i=0 ; i<inBitSize1 ; i++) {
    tab [i] = (PMUInt16) (i + inBitSize1 + inBitSize2) ;
  }
  for (PMUInt16 j=0 ; j<inBitSize2 ; j++) {
    tab [j + inBitSize1] = j ;
  }
  for (PMUInt16 k=0 ; k<inBitSize3 ; k++) {
    tab [k + inBitSize1 + inBitSize2] = (PMUInt16) (k + inBitSize2) ;
  }
  const C_BDD bdd = substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return bdd ;
}

//----------------------------------------------------------------------------*

C_BDD C_BDD::
swap213 (const PMUInt16 inBitSize1,
         const PMUInt16 inBitSize2,
         const PMUInt16 inBitSize3) const {
  const PMUInt16 totalSize = (PMUInt16) (inBitSize1 + inBitSize2 + inBitSize3) ;
  PMUInt16 * tab = NULL ;
  macroMyNewArray (tab, PMUInt16, totalSize) ;
  for (PMUInt16 i=0 ; i<inBitSize1 ; i++) {
    tab [i] = (PMUInt16) (i + inBitSize2) ;
  }
  for (PMUInt16 j=0 ; j<inBitSize2 ; j++) {
    tab [j + inBitSize1] = j ;
  }
  for (PMUInt16 k=0 ; k<inBitSize3 ; k++) {
    tab [k + inBitSize1 + inBitSize2] = (PMUInt16) (k + inBitSize1 + inBitSize2) ;
  }
  const C_BDD bdd = substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return bdd ;
}

//----------------------------------------------------------------------------*

C_BDD C_BDD::
swap321 (const PMUInt16 inBitSize1,
         const PMUInt16 inBitSize2,
         const PMUInt16 inBitSize3) const {
  const PMUInt16 totalSize = (PMUInt16) (inBitSize1 + inBitSize2 + inBitSize3) ;
  PMUInt16 * tab = NULL ;
  macroMyNewArray (tab, PMUInt16, totalSize) ;
  for (PMUInt16 i=0 ; i<inBitSize1 ; i++) {
    tab [i] = (PMUInt16) (i + inBitSize1 + inBitSize2) ;
  }
  for (PMUInt16 j=0 ; j<inBitSize2 ; j++) {
    tab [j + inBitSize1] = (PMUInt16) (j + inBitSize3) ;
  }
  for (PMUInt16 k=0 ; k<inBitSize3 ; k++) {
    tab [k + inBitSize1 + inBitSize2] = k ;
  }
  const C_BDD bdd = substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return bdd ;
}

//----------------------------------------------------------------------------*

C_BDD C_BDD::
swap312 (const PMUInt16 inBitSize1,
         const PMUInt16 inBitSize2,
         const PMUInt16 inBitSize3) const {
  const PMUInt16 totalSize = (PMUInt16) (inBitSize1 + inBitSize2 + inBitSize3) ;
  PMUInt16 * tab = NULL ;
  macroMyNewArray (tab, PMUInt16, totalSize) ;
  for (PMUInt16 i=0 ; i<inBitSize1 ; i++) {
    tab [i] = (PMUInt16) (i + inBitSize3) ;
  }
  for (PMUInt16 j=0 ; j<inBitSize2 ; j++) {
    tab [j + inBitSize1] = (PMUInt16) (j + inBitSize1 + inBitSize3) ;
  }
  for (PMUInt16 k=0 ; k<inBitSize3 ; k++) {
    tab [k + inBitSize1 + inBitSize2] = k ;
  }
  const C_BDD bdd = substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return bdd ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Print BDD
#endif

//----------------------------------------------------------------------------*

static void
ecrireLigneBDD (AC_OutputStream & inStream,
                TC_UniqueArray <char> & chaineAffichage,
                const C_Display_BDD & inVariablesNames) {
//--- Ecriture des valeurs booleennes
  PMUInt16 indiceBDD = 0 ;
  for (PMUInt16 i=0 ; i<inVariablesNames.nombreEntrees () ; i++) {
    const PMSInt32 lg = ::TF_sup (inVariablesNames.longueur (i), (PMSInt32) inVariablesNames.obtenirDimension (i)) ;
    const PMSInt32 espaces = 1 + lg - inVariablesNames.obtenirDimension (i) ;
    inStream.appendSpaces (espaces) ;
    for (PMSInt32 k=inVariablesNames.obtenirDimension (i) ; k>0 ; k--) {
      inStream << cStringWithCharacter (chaineAffichage (indiceBDD + k - 1 COMMA_HERE)) ;
    }
    indiceBDD = (PMUInt16) (indiceBDD + inVariablesNames.obtenirDimension (i)) ;
  }
//--- Fin
  inStream << "\n" ;
}

//---------------------------------------------------------------------*

static void
ecrireBDDinterne (AC_OutputStream & inStream,
                  const PMUInt32 inValue,
                  TC_UniqueArray <char> & chaineAffichage,
                  PMUInt16 numeroVariable,
                  const PMUInt16 inBDDvariablesCount,
                  const C_Display_BDD & inVariablesNames) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  const PMUInt32 complement = inValue & 1 ;
  if (node == 0) {
    if (complement == 1) {
      ecrireLigneBDD (inStream, chaineAffichage, inVariablesNames) ;
    }
  }else{
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    while (numeroVariable > var) {
      chaineAffichage (numeroVariable COMMA_HERE) = 'X' ;
      numeroVariable -- ;
    }
  //--- Branche Zero
    const PMUInt32 branche0 = (extractElse (node)) ^ complement ;
    if (branche0 != 0) {
      chaineAffichage (var COMMA_HERE) = '0' ;
      if (branche0 == 1) {
        for (PMUInt16 i=0 ; i<var ; i++) {
          chaineAffichage (i COMMA_HERE) = 'X' ;
        }
        ecrireLigneBDD (inStream, chaineAffichage, inVariablesNames) ;
      }else{
        ecrireBDDinterne (inStream, branche0, chaineAffichage, (PMUInt16) (var - 1), inBDDvariablesCount,
                          inVariablesNames) ;
      }
    }
  //--- Branche 1
    const PMUInt32 branche1 = extractThen (node) ^ complement ;
    if (branche1 != 0) {
      chaineAffichage (var COMMA_HERE) = '1' ;
      if (branche1 == 1) {
        for (PMUInt16 i=0 ; i<var ; i++) {
          chaineAffichage (i COMMA_HERE) = 'X' ;
        }
        ecrireLigneBDD (inStream, chaineAffichage, inVariablesNames) ;
      }else{
        ecrireBDDinterne (inStream, branche1, chaineAffichage, (PMUInt16) (var - 1), inBDDvariablesCount,
                          inVariablesNames) ;
      }
    }
  }
}

//---------------------------------------------------------------------*

void C_BDD::printBDD (AC_OutputStream & inStream,
                      const PMUInt16 inBDDvariablesCount,
                      const C_Display_BDD & inVariablesNames) const {
//--- Imprimer les variables
  for (PMUInt16 i=0 ; i<inVariablesNames.nombreEntrees () ; i++) {
    const PMSInt32 lg = ::TF_sup (inVariablesNames.longueur (i), (PMSInt32) inVariablesNames.obtenirDimension (i)) ;
    const PMSInt32 espaces = 1 + lg - inVariablesNames.longueur (i) ;
    inStream.appendSpaces (espaces) ;
    inVariablesNames.ecrire (i, inStream) ;
  }
  inStream << "\n" ;
//--- Ecrire le BDD
  if (mBDDvalue == 0) {
    inStream << "(false)\n" ;
  }else if (mBDDvalue == 1) {
    TC_UniqueArray <char> chaineAffichage (inBDDvariablesCount, 'X' COMMA_HERE) ;
    ecrireLigneBDD (inStream, chaineAffichage, inVariablesNames) ;
  }else{
    TC_UniqueArray <char> chaineAffichage (inBDDvariablesCount, 'X' COMMA_HERE) ;
    ecrireBDDinterne (inStream, mBDDvalue, chaineAffichage, (PMUInt16) (inBDDvariablesCount - 1), inBDDvariablesCount, inVariablesNames) ;
  }
}


//---------------------------------------------------------------------*

static void
printBDDline (const TC_UniqueArray <char> & inDisplayString,
              const TC_UniqueArray <PMSInt32> & inNameLengthArray,
              const PMSInt32 inLeadingSpacesCount) {
  for (PMSInt32 i=0 ; i<inLeadingSpacesCount ; i++) {
    co << " " ;
  }
  for (PMSInt32 i=0 ; i<inDisplayString.count () ; i++) {
    for (PMSInt32 c=0 ; c<inNameLengthArray (i COMMA_HERE) ; c++) {
      co << " " ;
    }
    co << cStringWithCharacter (inDisplayString (i COMMA_HERE)) ;
  }
  co << "\n" ;
}

//---------------------------------------------------------------------*

static void
internalPrintBDD (const PMUInt32 inValue,
                  TC_UniqueArray <char> & inDisplayString,
                  const TC_UniqueArray <PMSInt32> & inNameLengthArray,
                  PMUInt16 inVariableIndex,
                  const PMSInt32 inLeadingSpacesCount) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  const PMUInt32 complement = inValue & 1 ;
  if (node == 0) {
    if (complement == 1) {
      printBDDline (inDisplayString, inNameLengthArray, inLeadingSpacesCount) ;
    }
  }else{
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    while (inVariableIndex > var) {
      inDisplayString (inVariableIndex COMMA_HERE) = 'X' ;
      inVariableIndex -- ;
    }
  //--- Branche Zero
    const PMUInt32 branche0 = (extractElse (node)) ^ complement ;
    if (branche0 != 0) {
      inDisplayString (var COMMA_HERE) = '0' ;
      if (branche0 == 1) {
        for (PMUInt16 i=0 ; i<var ; i++) {
          inDisplayString (i COMMA_HERE) = 'X' ;
        }
        printBDDline (inDisplayString, inNameLengthArray, inLeadingSpacesCount) ;
      }else{
        internalPrintBDD (branche0, inDisplayString, inNameLengthArray, (PMUInt16) (inVariableIndex - 1), inLeadingSpacesCount) ;
      }
    }
  //--- Branche 1
    const PMUInt32 branche1 = extractThen (node) ^ complement ;
    if (branche1 != 0) {
      inDisplayString (var COMMA_HERE) = '1' ;
      if (branche1 == 1) {
        for (PMUInt16 i=0 ; i<var ; i++) {
          inDisplayString (i COMMA_HERE) = 'X' ;
        }
        printBDDline (inDisplayString, inNameLengthArray, inLeadingSpacesCount) ;
      }else{
        internalPrintBDD (branche1, inDisplayString, inNameLengthArray, (PMUInt16) (inVariableIndex - 1), inLeadingSpacesCount) ;
      }
    }
  }
}

//---------------------------------------------------------------------*

void C_BDD::
printBDD (const TC_UniqueArray <C_String> & inVariablesNames,
          const PMSInt32 inLeadingSpacesCount) const {
  printBDD (inVariablesNames, inVariablesNames.count (), inLeadingSpacesCount) ;
}

//---------------------------------------------------------------------*

void C_BDD::
printBDDHeader (const TC_UniqueArray <C_String> & inVariablesNames,
                const PMSInt32 inVariablesCount,
                const PMSInt32 inLeadingSpacesCount) const {
//--- Imprimer les variables
  for (PMSInt32 i=0 ; i<inLeadingSpacesCount ; i++) {
    co << " " ;
  }
  for (PMSInt32 i=0 ; i<inVariablesCount ; i++) {
    co << " " << inVariablesNames (i COMMA_HERE) ;
  }
  co << "\n" ;
}

//---------------------------------------------------------------------*

void C_BDD::
printBDD (const TC_UniqueArray <C_String> & inVariablesNames,
          const PMSInt32 inVariablesCount,
          const PMSInt32 inLeadingSpacesCount) const {
//--- Print header
  printBDDHeader (inVariablesNames, inVariablesCount, inLeadingSpacesCount) ;
//--- Print without header
  printBDDwithoutHeader (inVariablesNames, inVariablesCount, inLeadingSpacesCount) ;
}

//---------------------------------------------------------------------*

void C_BDD::printBDDwithoutHeader (const TC_UniqueArray <C_String> & inVariablesNames,
                                   const PMSInt32 inVariablesCount,
                                   const PMSInt32 inLeadingSpacesCount) const {
//--- Compute header size
  TC_UniqueArray <PMSInt32> nameLengthArray (inVariablesCount COMMA_HERE) ;
  for (PMSInt32 i=0 ; i<inVariablesCount ; i++) {
    nameLengthArray.addObject (inVariablesNames (i COMMA_HERE).length ()) ;
  }
//--- Print BDD
  if (mBDDvalue == 0) {
    for (PMSInt32 i=0 ; i<inLeadingSpacesCount ; i++) {
      co << " " ;
    }
    co << " (false)\n" ;
  }else if (mBDDvalue == 1) {
    TC_UniqueArray <char> displayString (inVariablesCount, 'X' COMMA_HERE) ;
    printBDDline (displayString, nameLengthArray, inLeadingSpacesCount) ;
  }else{
    const PMUInt64 node = nodeForRoot (mBDDvalue COMMA_HERE) ;
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    if (var >= inVariablesCount) {
      co << "** ERROR in "
         << __FILE__
         << " at line %"
         << cStringWithSigned (__LINE__)
         << ": BDD variable ("
         << cStringWithUnsigned (var)
         << ") is greater than variable count ("
         << cStringWithSigned (inVariablesCount)
         << ") **\n" ;
    }else{
      TC_UniqueArray <char> displayString (inVariablesCount, 'X' COMMA_HERE) ;
      internalPrintBDD (mBDDvalue, displayString, nameLengthArray, (PMUInt16) ((((PMUInt16) inVariablesCount) - 1) & PMUINT16_MAX), inLeadingSpacesCount) ;
    }
  }
}

//---------------------------------------------------------------------*

static void
printBDDlineWithSeparator (const TC_UniqueArray <C_String> & inSeparatorArray,
                           const TC_UniqueArray <char> & inValueArray) {
  for (PMSInt32 i=0 ; i<inSeparatorArray.count () ; i++) {
    printf ("%s%c", inSeparatorArray (i COMMA_HERE).cString(HERE), inValueArray (i COMMA_HERE)) ;
  }
  printf ("\n") ;
}

//---------------------------------------------------------------------*

static void
internalPrintBDDWithSeparator (const PMUInt32 inValue,
                               TC_UniqueArray <char> & inDisplayString,
                               const TC_UniqueArray <C_String> & inSeparatorArray,
                               PMUInt16 inVariableIndex) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  const PMUInt32 complement = inValue & 1 ;
  if (node == 0) {
    if (complement == 1) {
      printBDDlineWithSeparator (inSeparatorArray, inDisplayString) ;
    }
  }else{
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    while (inVariableIndex > var) {
      inDisplayString (inVariableIndex COMMA_HERE) = 'X' ;
      inVariableIndex -- ;
    }
  //--- Branche Zero
    const PMUInt32 branche0 = (extractElse (node)) ^ complement ;
    if (branche0 != 0) {
      inDisplayString (var COMMA_HERE) = '0' ;
      if (branche0 == 1) {
        for (PMUInt16 i=0 ; i<var ; i++) {
          inDisplayString (i COMMA_HERE) = 'X' ;
        }
        printBDDlineWithSeparator (inSeparatorArray, inDisplayString) ;
      }else{
        internalPrintBDDWithSeparator (branche0, inDisplayString, inSeparatorArray, (PMUInt16) (inVariableIndex - 1)) ;
      }
    }
  //--- Branche 1
    const PMUInt32 branche1 = extractThen (node) ^ complement ;
    if (branche1 != 0) {
      inDisplayString (var COMMA_HERE) = '1' ;
      if (branche1 == 1) {
        for (PMUInt16 i=0 ; i<var ; i++) {
          inDisplayString (i COMMA_HERE) = 'X' ;
        }
        printBDDlineWithSeparator (inSeparatorArray, inDisplayString) ;
      }else{
        internalPrintBDDWithSeparator (branche1, inDisplayString, inSeparatorArray, (PMUInt16) (inVariableIndex - 1)) ;
      }
    }
  }
}

//---------------------------------------------------------------------*

void C_BDD::printBDDwithSeparator (const TC_UniqueArray <C_String> & inSeparatorArray) const {
  const PMUInt16 variablesCount = (PMUInt16) inSeparatorArray.count () ;
//--- Print BDD
  if (mBDDvalue == 1) {
    TC_UniqueArray <char> displayString (variablesCount, 'X' COMMA_HERE) ;
    printBDDlineWithSeparator (inSeparatorArray, displayString) ;
  }else if (mBDDvalue != 0) {
    const PMUInt64 node = nodeForRoot (mBDDvalue COMMA_HERE) ;
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    if (var >= variablesCount) {
      co << "** ERROR in "
         << __FILE__
         << " at line %"
         << cStringWithSigned (__LINE__)
         << ": BDD variable ("
         << cStringWithUnsigned (var)
         << ") is greater than variable count ("
         << cStringWithSigned (variablesCount)
         << ") **\n" ;
    }else{
      TC_UniqueArray <char> displayString (variablesCount, 'X' COMMA_HERE) ;
      internalPrintBDDWithSeparator (mBDDvalue,
                                     displayString,
                                     inSeparatorArray,
                                     (PMUInt16) ((variablesCount - 1) & PMUINT16_MAX)) ;
    }
  }
}

//---------------------------------------------------------------------*

static void
internalPrintBDDInLittleEndianStringArray (const PMUInt32 inValue,
                               C_String & ioDisplayString,
                               PMUInt16 inVariableIndex,
                               TC_UniqueArray <C_String> & outStringArray
                               COMMA_LOCATION_ARGS) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  const PMUInt32 complement = inValue & 1 ;
  if (node == 0) {
    if (complement == 1) {
      outStringArray.addObject (ioDisplayString) ;
    }
  }else{
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    while (inVariableIndex > var) {
      ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('X'), inVariableIndex COMMA_THERE) ;
      inVariableIndex -- ;
    }
  //--- Branche Zero
    const PMUInt32 branche0 = (extractElse (node)) ^ complement ;
    if (branche0 != 0) {
      ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('0'), var COMMA_HERE) ;
      if (branche0 == 1) {
        for (PMUInt16 i=0 ; i<var ; i++) {
          ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('X'), i COMMA_HERE) ;
        }
        outStringArray.addObject (ioDisplayString) ;
      }else{
        internalPrintBDDInLittleEndianStringArray (branche0, ioDisplayString, (PMUInt16) (inVariableIndex - 1), outStringArray COMMA_THERE) ;
      }
    }
  //--- Branche 1
    const PMUInt32 branche1 = extractThen (node) ^ complement ;
    if (branche1 != 0) {
      ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('1'), var COMMA_HERE) ;
      if (branche1 == 1) {
        for (PMUInt16 i=0 ; i<var ; i++) {
          ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('X'), i COMMA_HERE) ;
        }
        outStringArray.addObject (ioDisplayString) ;
      }else{
        internalPrintBDDInLittleEndianStringArray (branche1, ioDisplayString, (PMUInt16) (inVariableIndex - 1), outStringArray COMMA_THERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------*

void C_BDD::
buildCompressedLittleEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray
                                             COMMA_LOCATION_ARGS) const {
  const PMUInt64 node = nodeForRoot (mBDDvalue COMMA_HERE) ;
  if (node != 0) {
    C_String displayString ;
    for (PMSInt32 i=0 ; i<=((PMSInt32) extractVar (node COMMA_HERE)) ; i++) {
      displayString << "X" ;
    }
    internalPrintBDDInLittleEndianStringArray (mBDDvalue, displayString, extractVar (node COMMA_HERE), outStringArray COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------*

void C_BDD::
buildCompressedLittleEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray,
                                             const PMUInt16 inBDDvariablesCount
                                             COMMA_LOCATION_ARGS) const {
  C_String displayString ;
  for (PMSInt32 i=0 ; i<((PMSInt32) inBDDvariablesCount) ; i++) {
    displayString << "X" ;
  }
  internalPrintBDDInLittleEndianStringArray (mBDDvalue, displayString, inBDDvariablesCount, outStringArray COMMA_THERE) ;
}

//---------------------------------------------------------------------*

static void
internalPrintBDDInBigEndianStringArray (const PMUInt32 inValue,
                               C_String & ioDisplayString,
                               PMUInt16 inVariableIndex,
                               const PMUInt16 inTotalVariableCountMinusOne,
                               TC_UniqueArray <C_String> & outStringArray
                               COMMA_LOCATION_ARGS) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  const PMUInt32 complement = inValue & 1 ;
  if (node == 0) {
    if (complement == 1) {
      outStringArray.addObject (ioDisplayString) ;
    }
  }else{
    const PMUInt16 var = extractVar (node COMMA_HERE) ;
    while (inVariableIndex > var) {
      ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('X'), inTotalVariableCountMinusOne - inVariableIndex COMMA_THERE) ;
      inVariableIndex -- ;
    }
  //--- Branche Zero
    const PMUInt32 branche0 = (extractElse (node)) ^ complement ;
    if (branche0 != 0) {
      ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('0'), inTotalVariableCountMinusOne - var COMMA_THERE) ;
      if (branche0 == 1) {
        for (PMUInt16 i=0 ; i<var ; i++) {
          ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('X'), inTotalVariableCountMinusOne - i COMMA_THERE) ;
        }
        outStringArray.addObject (ioDisplayString) ;
      }else{
        internalPrintBDDInBigEndianStringArray (branche0, ioDisplayString, (PMUInt16) (inVariableIndex - 1), inTotalVariableCountMinusOne, outStringArray COMMA_THERE) ;
      }
    }
  //--- Branche 1
    const PMUInt32 branche1 = extractThen (node) ^ complement ;
    if (branche1 != 0) {
      ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('1'), inTotalVariableCountMinusOne - var COMMA_HERE) ;
      if (branche1 == 1) {
        for (PMUInt16 i=0 ; i<var ; i++) {
          ioDisplayString.setUnicodeCharacterAtIndex (TO_UNICODE ('X'), inTotalVariableCountMinusOne - i COMMA_HERE) ;
        }
        outStringArray.addObject (ioDisplayString) ;
      }else{
        internalPrintBDDInBigEndianStringArray (branche1, ioDisplayString, (PMUInt16) (inVariableIndex - 1), inTotalVariableCountMinusOne, outStringArray COMMA_THERE) ;
      }
    }
  }
}

//---------------------------------------------------------------------*

void C_BDD::
buildCompressedBigEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray
                                          COMMA_LOCATION_ARGS) const {
  const PMUInt64 node = nodeForRoot (mBDDvalue COMMA_HERE) ;
  if (node != 0) {
    C_String displayString ;
    for (PMSInt32 i=0 ; i<=((PMSInt32) extractVar (node COMMA_HERE)) ; i++) {
      displayString << "X" ;
    }
    internalPrintBDDInBigEndianStringArray (mBDDvalue, displayString, extractVar (node COMMA_HERE), extractVar (node COMMA_HERE), outStringArray COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------*

void C_BDD::
buildCompressedBigEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray,
                                 const PMUInt16 inBDDvariablesCount
                                 COMMA_LOCATION_ARGS) const {
  C_String displayString ;
  for (PMSInt32 i=0 ; i<((PMSInt32) inBDDvariablesCount) ; i++) {
    displayString << "X" ;
  }
  internalPrintBDDInBigEndianStringArray (mBDDvalue,
                                          displayString,
                                          (PMUInt16) (inBDDvariablesCount - 1),
                                          (PMUInt16) (inBDDvariablesCount - 1),
                                          outStringArray COMMA_THERE) ;
}

//---------------------------------------------------------------------*

static void displayBranchCode (AC_OutputStream & inStream,
                               const PMUInt32 inBranchValue) {
  if (inBranchValue == 0) {
    inStream << "FALSE" ;
  }else if (inBranchValue == 1) {
    inStream << "TRUE" ;
  }else{
    if ((inBranchValue & 1) != 0) {
      inStream << "~ " ;
    }
    inStream << "node " << cStringWithUnsigned (inBranchValue >> 1) ;
  }
}

//---------------------------------------------------------------------*

static void ecrireCompositionBDDrecursif (AC_OutputStream & inStream,
                                          const PMUInt32 inValue,
                                          const C_Display_BDD & inVariablesNames) {
  const PMUInt64 node = nodeForRoot (inValue COMMA_HERE) ;
  if ((node != 0ULL) && ! isNodeMarkedThenMark (inValue COMMA_HERE)) {
    inStream << "  node " << cStringWithUnsigned (inValue >> 1) << ": if " ;
    inVariablesNames.ecrire (extractVar (node COMMA_HERE), inStream) ;
    inStream << " (#" << cStringWithUnsigned (extractVar (node COMMA_HERE))  << ") then " ;
    displayBranchCode (inStream, extractThen (node)) ;
    inStream << " else " ;
    displayBranchCode (inStream, extractElse (node)) ;
    inStream << "\n" ;
    ecrireCompositionBDDrecursif (inStream, extractElse (node), inVariablesNames) ;
    ecrireCompositionBDDrecursif (inStream, extractThen (node), inVariablesNames) ;
  }
}

//---------------------------------------------------------------------*

void C_BDD::
printBDDnodes (AC_OutputStream & inStream,
               const C_Display_BDD & inVariablesNames) const {
  inStream << "BDD root: " ;
  displayBranchCode (inStream, mBDDvalue) ;
  inStream << "\n" ;
  if (nodeForRoot (mBDDvalue COMMA_HERE) != 0) {
    unmarkAllExistingBDDnodes () ;
    ecrireCompositionBDDrecursif (inStream, mBDDvalue, inVariablesNames) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Build BDD from value list
#endif

static inline void swapValueArray (PMUInt64 ioValueArray [],
                                   const PMSInt32 inIndex1,
                                   const PMSInt32 inIndex2) {
  const PMUInt64 v = ioValueArray [inIndex1] ;
  ioValueArray [inIndex1] = ioValueArray [inIndex2] ;
  ioValueArray [inIndex2] = v ;
}

//----------------------------------------------------------------

static void sortValueArray (PMUInt64 ioValueArray [],
                            const PMSInt32 inLeftIndex,
                            const PMSInt32 inRightIndex) {
  if (inLeftIndex < inRightIndex) {
    const PMSInt32 pivotIndex = (inRightIndex + inLeftIndex) / 2 ;
    const PMUInt64 pivotValue = ioValueArray [pivotIndex] ;
  //--- Move pivot to the end
    swapValueArray (ioValueArray, pivotIndex, inRightIndex) ;
  //--- storeIndex := left
    PMSInt32 storeIndex = inLeftIndex ;
    for (PMSInt32 i=inLeftIndex ; i<inRightIndex ; i++) {
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

C_BDD C_BDD::buildBDDFromValueList (PMUInt64 ioValueList [],
                                    const PMUInt32 inValueCount,
                                    const PMUInt16 inBitCount) {
//---
  if (0 == inBitCount) {
    printf ("*** error in %s:%d: inBitCount is zero (should be > 0)***\n", __FILE__, __LINE__) ;
    exit (1) ;
  }
  if (inBitCount > 64) {
    printf ("*** error in %s:%d: inBitCount = %hu (should be <= 64)***\n", __FILE__, __LINE__, inBitCount) ;
    exit (1) ;
  }
//---
  C_BDD result ;
  if (inValueCount > 0) {
  //--- Sort value list in ascending order
    sortValueArray (ioValueList, 0, (PMSInt32) (inValueCount - 1)) ;
  //--- Check values are sorted
  //  for (PMUInt32 i=1 ; i<inValueCount ; i++) {
  //    MF_Assert (ioValueList [i-1] < ioValueList [i], "ioValueList [i-1] < ioValueList [i] for i=%lld, inValueCount:%lld", i, inValueCount) ;
  //  }
  //--- Search for duplicates
    PMUInt32 duplicates = 0 ;
    for (PMUInt32 i=1 ; i<inValueCount ; i++) {
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
    PMUInt64 referenceValue = ioValueList [0] ;
    for (PMUInt32 i=0 ; i<inValueCount ; i++) {
      const PMUInt64 currentTransition = ioValueList [i] ;
      PMUInt64 mask = 1ULL << (inBitCount - 1) ;
      PMSInt32 firstDifferentBit = ((PMSInt32) inBitCount) - 1 ;
      while ((firstDifferentBit >= 0) && (((currentTransition ^ referenceValue) & mask) == 0)) {
        firstDifferentBit -- ;
        mask >>=1 ;
      }
      if (firstDifferentBit >= 0) {
        C_BDD accumulatorBDD ; accumulatorBDD.setToTrue () ;
        mask = 1ULL ;
        for (PMSInt32 idx=0 ; idx<=firstDifferentBit ; idx++) {
          accumulatorBDD = (C_BDD ((PMUInt16) (((PMUInt16) idx) & PMUINT16_MAX), (referenceValue & mask) != 0) & accumulatorBDD) | accumulatorArray [idx] ;
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
    PMUInt64 mask = 1ULL ;
    for (PMSInt32 idx=0 ; idx<inBitCount ; idx++) {
      result = (C_BDD ((PMUInt16) (((PMUInt16) idx) & PMUINT16_MAX), (referenceValue & mask) != 0) & result) | accumulatorArray [idx] ;
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

//---------------------------------------------------------------------*

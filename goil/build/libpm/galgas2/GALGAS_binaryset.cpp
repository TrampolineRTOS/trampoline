//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  GALGAS_binaryset                                                                                                   *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Created january 22, 2007.                                                                                          *
//                                                                                                                     *
//  Copyright (C) 2007, ..., 2014 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
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

#include "all-predefined-types.h"
#include "galgas2/C_Compiler.h"

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset::GALGAS_binaryset (void) :
mIsValid (false),
mBDD () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset::GALGAS_binaryset (const C_BDD & inOperand_mBDD) :
mIsValid (true),
mBDD (inOperand_mBDD) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_emptyBinarySet (UNUSED_LOCATION_ARGS) {
  return GALGAS_binaryset (C_BDD ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_fullBinarySet (UNUSED_LOCATION_ARGS) {
  C_BDD bdd ;
  bdd.setToTrue () ;
  return GALGAS_binaryset (bdd) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithBit (const GALGAS_uint & inBitIndex,
                                                                 C_Compiler * /* inCompiler */
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_binaryset result ;
  if (inBitIndex.isValid ()) {
    const uint32_t bitIndex = inBitIndex.uintValue () ;
    const C_BDD bdd (bitIndex, true) ;
    result = GALGAS_binaryset (bdd) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithPredicateString (const GALGAS_string & inBitString,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_binaryset result ;
  if (inBitString.isValid ()) {
    const C_String bitString = inBitString.stringValue () ;
    const int32_t stringLength = bitString.length () ;
    int32_t stringIndex = 0 ;
    bool ok = true ;
    C_BDD resultBDD ;
    while ((stringIndex < stringLength) && ok) {
      utf32 cc = bitString (stringIndex COMMA_HERE) ;
      C_String s ;
      while ((stringIndex < stringLength) && ((UNICODE_VALUE (cc) == '0') || (UNICODE_VALUE (cc) == '1') || (UNICODE_VALUE (cc) == 'X') || (UNICODE_VALUE (cc) == ' '))) {
        s.appendUnicodeCharacter (cc COMMA_HERE) ;
        stringIndex ++ ;
        if (stringIndex < stringLength) {
          cc = bitString (stringIndex COMMA_HERE) ;
        }
      }
      if (s.length () > 0) {
        C_BDD v ; v.setToTrue () ;
        uint32_t bitIndex = 0 ;
        for (int32_t i=s.length () - 1 ; i>=0 ; i--) {
          const utf32 c = s (i COMMA_HERE) ;
          if (UNICODE_VALUE (c) == '0') {
            v &= C_BDD (bitIndex, false) ;
            bitIndex ++ ;
          }else if (UNICODE_VALUE (c) == '1') {
            v &= C_BDD (bitIndex, true) ;
            bitIndex ++ ;
          }else if (UNICODE_VALUE (c) == 'X') {
            bitIndex ++ ;
          }
        }
        resultBDD |= v ;
      }
      if (stringIndex < stringLength) {
        ok = UNICODE_VALUE (cc) == '|' ;
        stringIndex ++ ;
      }
    }
    if (ok) {
      result = GALGAS_binaryset (resultBDD) ;
    }else{
      C_String message ("invalid query string near index ") ;
      message.appendSigned (stringIndex) ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_binaryset binarySetWithComparison (C_Compiler * inCompiler,
                                                 const GALGAS_uint & inLeftFirstIndex,
                                                 const GALGAS_uint & inBitCount,
                                                 const C_BDD::compareEnum inComparison,
                                                 const GALGAS_uint & inRightFirstIndex                                             
                                                 COMMA_LOCATION_ARGS) {
  GALGAS_binaryset result ;
  if ((inLeftFirstIndex.isValid ()) && (inBitCount.isValid ()) && (inRightFirstIndex.isValid ())) {
    const uint64_t maxLeft = ((uint64_t) inLeftFirstIndex.uintValue ()) + inBitCount.uintValue () ;
    const uint64_t maxRight = ((uint64_t) inRightFirstIndex.uintValue ()) + inBitCount.uintValue () ;
    if (maxLeft > UINT32_MAX) {
      inCompiler->onTheFlyRunTimeError ("left operand upper bit is greater than 2**31-1" COMMA_THERE) ;
    }else if (maxRight > UINT32_MAX) {
      inCompiler->onTheFlyRunTimeError ("right operand upper bit is greater than 2**31-1" COMMA_THERE) ;
    }else {
      result = GALGAS_binaryset (C_BDD::varCompareVar (inLeftFirstIndex.uintValue (),
                                 inBitCount.uintValue (),
                                 inComparison,
                                 inRightFirstIndex.uintValue ())) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithEqualComparison (const GALGAS_uint & inLeftFirstIndex,
                                                                             const GALGAS_uint & inBitCount,
                                                                             const GALGAS_uint & inRightFirstIndex,                                           
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) {
  return binarySetWithComparison (inCompiler,
                                  inLeftFirstIndex,
                                  inBitCount,
                                  C_BDD::kEqual,
                                  inRightFirstIndex                                             
                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithNotEqualComparison (const GALGAS_uint & inLeftFirstIndex,
                                                                                const GALGAS_uint & inBitCount,
                                                                                const GALGAS_uint & inRightFirstIndex,                                            
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  return binarySetWithComparison (inCompiler,
                                  inLeftFirstIndex,
                                  inBitCount,
                                  C_BDD::kNotEqual,
                                  inRightFirstIndex                                             
                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithLowerOrEqualComparison (const GALGAS_uint & inLeftFirstIndex,
                                                                                    const GALGAS_uint & inBitCount,
                                                                                    const GALGAS_uint & inRightFirstIndex,                                           
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  return binarySetWithComparison (inCompiler,
                                  inLeftFirstIndex,
                                  inBitCount,
                                  C_BDD::kLowerOrEqual,
                                  inRightFirstIndex                                             
                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithGreaterOrEqualComparison (const GALGAS_uint & inLeftFirstIndex,
                                                                                      const GALGAS_uint & inBitCount,
                                                                                      const GALGAS_uint & inRightFirstIndex,                                          
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  return binarySetWithComparison (inCompiler,
                                  inLeftFirstIndex,
                                  inBitCount,
                                  C_BDD::kGreaterOrEqual,
                                  inRightFirstIndex                                             
                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithStrictLowerComparison (const GALGAS_uint & inLeftFirstIndex,
                                                                                   const GALGAS_uint & inBitCount,
                                                                                   const GALGAS_uint & inRightFirstIndex,                                           
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) {
  return binarySetWithComparison (inCompiler,
                                  inLeftFirstIndex,
                                  inBitCount,
                                  C_BDD::kStrictLower,
                                  inRightFirstIndex                                             
                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithStrictGreaterComparison (const GALGAS_uint & inLeftFirstIndex,
                                                                                     const GALGAS_uint & inBitCount,
                                                                                     const GALGAS_uint & inRightFirstIndex,                                            
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) {
  return binarySetWithComparison (inCompiler,
                                  inLeftFirstIndex,
                                  inBitCount,
                                  C_BDD::kStrictGreater,
                                  inRightFirstIndex                                             
                                  COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_binaryset binarySetWithComparisonWithConstant (C_Compiler * inCompiler,
                                                             const GALGAS_uint & inBitIndex,
                                                             const GALGAS_uint & inBitCount,
                                                             const C_BDD::compareEnum inComparison,
                                                             const GALGAS_uint_36__34_ & inConstant                                             
                                                             COMMA_LOCATION_ARGS) {
  GALGAS_binaryset result ;
  if ((inBitIndex.isValid ()) && (inBitCount.isValid ()) && (inConstant.isValid ())) {
    const uint64_t maxLeft = ((uint64_t) inBitIndex.uintValue ()) + inBitCount.uintValue () ;
    if (maxLeft > UINT32_MAX) {
      inCompiler->onTheFlyRunTimeError ("left operand upper bit is greater than 2**31-1" COMMA_THERE) ;
    }else {
      result = GALGAS_binaryset (C_BDD::varCompareConst (inBitIndex.uintValue (),
                                 inBitCount.uintValue (),
                                 inComparison,
                                 inConstant.uint64Value ())) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithEqualToConstant (const GALGAS_uint & inBitIndex,
                                                                             const GALGAS_uint & inBitCount,
                                                                             const GALGAS_uint_36__34_ & inConstant,                                             
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) {
  return binarySetWithComparisonWithConstant (inCompiler,
                                              inBitIndex,
                                              inBitCount,
                                              C_BDD::kEqual,
                                              inConstant                                             
                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithNotEqualToConstant (const GALGAS_uint & inBitIndex,
                                                                                const GALGAS_uint & inBitCount,
                                                                                const GALGAS_uint_36__34_ & inConstant,                                          
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  return binarySetWithComparisonWithConstant (inCompiler,
                                              inBitIndex,
                                              inBitCount,
                                              C_BDD::kNotEqual,
                                              inConstant                                             
                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithLowerOrEqualToConstant (const GALGAS_uint & inBitIndex,
                                                                                    const GALGAS_uint & inBitCount,
                                                                                    const GALGAS_uint_36__34_ & inConstant,                                             
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  return binarySetWithComparisonWithConstant (inCompiler,
                                              inBitIndex,
                                              inBitCount,
                                              C_BDD::kLowerOrEqual,
                                              inConstant                                             
                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithStrictLowerThanConstant (const GALGAS_uint & inBitIndex,
                                                                                     const GALGAS_uint & inBitCount,
                                                                                     const GALGAS_uint_36__34_ & inConstant,                                             
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) {
  return binarySetWithComparisonWithConstant (inCompiler,
                                              inBitIndex,
                                              inBitCount,
                                              C_BDD::kStrictLower,
                                              inConstant                                             
                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithGreaterOrEqualToConstant (const GALGAS_uint & inBitIndex,
                                                                                      const GALGAS_uint & inBitCount,
                                                                                      const GALGAS_uint_36__34_ & inConstant,                                         
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  return binarySetWithComparisonWithConstant (inCompiler,
                                              inBitIndex,
                                              inBitCount,
                                              C_BDD::kGreaterOrEqual,
                                              inConstant                                             
                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithStrictGreaterThanConstant (const GALGAS_uint & inBitIndex,
                                                                                       const GALGAS_uint & inBitCount,
                                                                                       const GALGAS_uint_36__34_ & inConstant,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) {
  return binarySetWithComparisonWithConstant (inCompiler,
                                              inBitIndex,
                                              inBitCount,
                                              C_BDD::kStrictGreater,
                                              inConstant                                             
                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Operators
#endif

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::operator_xor (const GALGAS_binaryset & inOperand2
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_binaryset (mBDD.notEqualTo (inOperand2.mBDD)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::operator_and (const GALGAS_binaryset & inOperand2
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_binaryset (mBDD & inOperand2.mBDD) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::operator_or (const GALGAS_binaryset & inOperand2
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_binaryset (mBDD | inOperand2.mBDD) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::operator_tilde (UNUSED_LOCATION_ARGS) const {
  return GALGAS_binaryset (~ mBDD) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_binaryset::description (C_String & ioString,
                                    const int32_t /* inIndentation */) const {
  ioString << "<@binaryset: " ;
  if (isValid ()) {
    if (mBDD.isFalse ()){
      ioString << "false" ;
    }else if (mBDD.isTrue ()){
      ioString << "true" ;
    }else{
      TC_UniqueArray <C_String> stringArray ;
      mBDD.buildCompressedBigEndianStringValueArray (stringArray COMMA_HERE) ;
      for (int32_t i=0 ; i<stringArray.count () ; i++) {
        if (i != 0) {
          ioString << ", " ;
        }
        ioString << stringArray (i COMMA_HERE) ;
      }
    }
  }else{
    ioString << "not built" ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_binaryset::getter_containsValue (const GALGAS_uint_36__34_ & inValue,
                                                    const GALGAS_uint & inFirstBit,
                                                    const GALGAS_uint & inBitCount
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if ((inValue.isValid ()) && (inFirstBit.isValid ()) && (inBitCount.isValid ())) {
     const uint64_t value = inValue.uint64Value () ;
     const uint32_t firstBit = inFirstBit.uintValue () ;
     const uint32_t bitCount = inBitCount.uintValue () ;
     result = GALGAS_bool (mBDD.containsValue64 (value, firstBit, bitCount)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_ITE (const GALGAS_binaryset & inTHENoperand,
                                               const GALGAS_binaryset & inELSEoperand                                             
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inTHENoperand.isValid ()) && (inELSEoperand.isValid ())) {
    result = GALGAS_binaryset (C_BDD::ite (mBDD, inTHENoperand.mBDD, inELSEoperand.mBDD)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_implies (const GALGAS_binaryset & inOperand
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset ((~ mBDD) | inOperand.mBDD) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_equalTo (const GALGAS_binaryset & inOperand
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset (mBDD.equalTo (inOperand.mBDD)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_notEqualTo (const GALGAS_binaryset & inOperand
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset (mBDD.notEqualTo (inOperand.mBDD)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_lowerOrEqualTo (const GALGAS_binaryset & inOperand
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset (mBDD.lowerOrEqual (inOperand.mBDD)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_greaterOrEqualTo (const GALGAS_binaryset & inOperand
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset (mBDD.greaterOrEqual (inOperand.mBDD)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_strictLowerThan (const GALGAS_binaryset & inOperand
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset (mBDD.lowerThan (inOperand.mBDD)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_strictGreaterThan (const GALGAS_binaryset & inOperand
                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset (mBDD.greaterThan (inOperand.mBDD)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_binaryset::getter_isFull (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (mBDD.isTrue ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_binaryset::getter_isEmpty (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (mBDD.isFalse ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_binaryset::getter_significantVariableCount (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint (mBDD.significantVariableCount ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_binaryset::getter_valueCount (const GALGAS_uint & inVariableCount,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (inVariableCount.isValid ()) {
    if (mBDD.significantVariableCount () > inVariableCount.uintValue ()) {
      inCompiler->onTheFlyRunTimeError ("needed variable count is greater than variable count argument" COMMA_THERE) ;
    }else{
      result = GALGAS_uint_36__34_ (mBDD.valueCount64 (inVariableCount.uintValue ())) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint GALGAS_binaryset::getter_bigValueCount (const GALGAS_uint & inVariableCount,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_bigint result ;
  if (inVariableCount.isValid ()) {
    if (mBDD.significantVariableCount () > inVariableCount.uintValue ()) {
      inCompiler->onTheFlyRunTimeError ("needed variable count is greater than variable count argument" COMMA_THERE) ;
    }else{
      const PMUInt128 r = mBDD.valueCount128 (inVariableCount.uintValue ()) ;
      result = GALGAS_bigint (C_BigInt (r.high (), r.low (), false)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_binaryset::getter_compressedValueCount (UNUSED_LOCATION_ARGS) const {
  TC_UniqueArray <C_String> valuesArray ;
  mBDD.buildCompressedLittleEndianStringValueArray (valuesArray COMMA_HERE) ;
  return GALGAS_uint_36__34_ ((uint32_t) valuesArray.count ()) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_list GALGAS_binaryset::getter_uint_36__34_ValueList (const GALGAS_uint & inVariableCount
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_list result ;
  if (inVariableCount.isValid ()) {
    TC_UniqueArray <uint64_t> valuesArray ;
    mBDD.buildValue64Array (valuesArray, inVariableCount.uintValue ()) ;
    result = GALGAS_uint_36__34_list::constructor_emptyList (THERE) ;
    for (int32_t i=0 ; i<valuesArray.count () ; i++) {
      const uint64_t v = valuesArray (i COMMA_HERE) ;
      result.addAssign_operation (GALGAS_uint_36__34_ (v) COMMA_HERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_binaryset::getter_stringValueListWithNameList (const GALGAS_uint & inVariableCount,
                                                                        const GALGAS_stringlist & inStringList,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if ((inVariableCount.isValid ()) && (inStringList.isValid ())) {
    TC_UniqueArray <uint64_t> valuesArray ;
    mBDD.buildValue64Array (valuesArray, inVariableCount.uintValue ()) ;
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    for (int32_t i=0 ; i<valuesArray.count () ; i++) {
      const uint32_t v = (uint32_t) (valuesArray (i COMMA_HERE) & UINT32_MAX) ;
      GALGAS_uint object = GALGAS_uint (v) ;
      result.addAssign_operation (inStringList.getter_mValueAtIndex (object, inCompiler COMMA_HERE) COMMA_HERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_binaryset::getter_compressedStringValueList (const GALGAS_uint & inVariableCount,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inVariableCount.isValid ()) {
    const uint32_t variableCount = inVariableCount.uintValue () ;
    const uint32_t actualVariableCount = mBDD.significantVariableCount () ;
    if (actualVariableCount > variableCount) {
      C_String message ;
      message << "variable count argument (" << cStringWithSigned (variableCount)
              << ") is lower than actual variable count ("
              << cStringWithSigned (actualVariableCount) << "); it should be greater or equal" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      TC_UniqueArray <C_String> valuesArray ;
      mBDD.buildCompressedBigEndianStringValueArray (valuesArray, variableCount COMMA_THERE) ;
      result = GALGAS_stringlist::constructor_emptyList (THERE) ;
      for (int32_t i=0 ; i<valuesArray.count () ; i++) {
        const C_String v = valuesArray (i COMMA_HERE) ;
        result.addAssign_operation (GALGAS_string (v) COMMA_HERE) ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_binaryset::getter_stringValueList (const GALGAS_uint & inVariableCount
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inVariableCount.isValid ()) {
    TC_UniqueArray <C_String> valuesArray ;
    mBDD.buildBigEndianStringValueArray (valuesArray, inVariableCount.uintValue ()) ;
    result = GALGAS_stringlist::constructor_emptyList (THERE) ;
    for (int32_t i=0 ; i<valuesArray.count () ; i++) {
      const C_String v = valuesArray (i COMMA_HERE) ;
      result.addAssign_operation (GALGAS_string (v) COMMA_HERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_binaryset::getter_predicateStringValue (LOCATION_ARGS) const {
  return GALGAS_string (mBDD.queryStringValue (THERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_forAllOnBitIndex (const GALGAS_uint & inVariableIndex
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid()) {
    result = GALGAS_binaryset (mBDD.forallOnBitNumber (inVariableIndex.uintValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_forAllOnBitIndexAndBeyond (const GALGAS_uint & inVariableIndex
                                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid ()) {
    result = GALGAS_binaryset (mBDD.forallOnBitsAfterNumber (inVariableIndex.uintValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_existOnBitIndex (const GALGAS_uint & inVariableIndex
                                                           COMMA_UNUSED_LOCATION_ARGS)const  {
  GALGAS_binaryset result ;
  if (isValid ()) {
    result = GALGAS_binaryset (mBDD.existsOnBitNumber (inVariableIndex.uintValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_existOnBitIndexAndBeyond (const GALGAS_uint & inVariableIndex
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inVariableIndex.isValid ()) {
    result = GALGAS_binaryset (mBDD.existsOnBitsAfterNumber (inVariableIndex.uintValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_binaryset::getter_print (const GALGAS_stringlist & inVariableList,
                                              const GALGAS_uintlist & inBDDCount
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid () && inVariableList.isValid () && inBDDCount.isValid ()) {
    TC_UniqueArray <C_String> variablesNames ;
    TC_UniqueArray <int32_t> bitCounts ;
    cEnumerator_stringlist variableEnumerator (inVariableList, kENUMERATION_UP) ;
    cEnumerator_uintlist bddCountEnumerator (inBDDCount, kENUMERATION_UP) ;
    while (variableEnumerator.hasCurrentObject () && bddCountEnumerator.hasCurrentObject ()) {
      const C_String name = variableEnumerator.current_mValue (HERE).stringValue () ;
      variablesNames.appendObject (name) ;
      const uint32_t bddCount = bddCountEnumerator.current_mValue (HERE).uintValue () ;
      bitCounts.appendObject ((int32_t) bddCount) ;
      variableEnumerator.gotoNextObject () ;
      bddCountEnumerator.gotoNextObject () ;
    }
    C_String s ;
    mBDD.print (s, variablesNames, bitCounts) ;
    result = GALGAS_string (s) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_transformedBy (const GALGAS_uintlist & inTransformationArray
                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid () && inTransformationArray.isValid ()) {
    uint32_t * substitutionArray = NULL ;
    macroMyNewPODArray (substitutionArray, uint32_t, inTransformationArray.count ()) ;
    cEnumerator_uintlist enumerator (inTransformationArray, kENUMERATION_UP) ;
    uint32_t idx = 0 ;
    while (enumerator.hasCurrentObject ()) {
      const uint32_t value = enumerator.current_mValue (HERE).uintValue () ;
      substitutionArray [idx] = value ;
      idx ++ ;
      enumerator.gotoNextObject () ;
    }
    result = GALGAS_binaryset (mBDD.substitution (substitutionArray, idx COMMA_THERE)) ;
    macroMyDeletePODArray (substitutionArray) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_binaryset::getter_nodeCount (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (isValid ()) {
    result = GALGAS_uint_36__34_ (mBDD.getBDDnodesCount ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_binaryset::getter_graphviz (const GALGAS_stringlist & inBitNameList
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid () && inBitNameList.isValid ()) {
    TC_UniqueArray <C_String> bitNameArray ;
    cEnumerator_stringlist variableEnumerator (inBitNameList, kENUMERATION_UP) ;
    while (variableEnumerator.hasCurrentObject ()) {
      const C_String name = variableEnumerator.current_mValue (HERE).stringValue () ;
      bitNameArray.appendObject (name) ;
      variableEnumerator.gotoNextObject () ;
    }
    result = GALGAS_string (mBDD.graphvizRepresentationWithNames (bitNameArray)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_binaryset::getter_graphvizDump (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mBDD.graphvizRepresentation ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_swap_31__30_ (const GALGAS_uint & inBitCount1,
                                                        const GALGAS_uint & inBitCount2
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inBitCount1.isValid ()) && (inBitCount2.isValid ())) {
    const uint32_t bitSize1 = inBitCount1.uintValue () ;
    const uint32_t bitSize2 = inBitCount2.uintValue () ;
    result = GALGAS_binaryset (mBDD.swap10 (bitSize1, bitSize2)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_swap_30__32__31_ (const GALGAS_uint & inBitCount1,
                                                            const GALGAS_uint & inBitCount2,
                                                            const GALGAS_uint & inBitCount3
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inBitCount1.isValid ()) && (inBitCount2.isValid ()) && (inBitCount3.isValid ())) {
    const uint32_t bitSize1 = inBitCount1.uintValue () ;
    const uint32_t bitSize2 = inBitCount2.uintValue () ;
    const uint32_t bitSize3 = inBitCount3.uintValue () ;
    result = GALGAS_binaryset (mBDD.swap021  (bitSize1, bitSize2, bitSize3)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_swap_31__30__32_ (const GALGAS_uint & inBitCount1,
                                                            const GALGAS_uint & inBitCount2,
                                                            const GALGAS_uint & inBitCount3
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inBitCount1.isValid ()) && (inBitCount2.isValid ()) && (inBitCount3.isValid ())) {
    const uint32_t bitSize1 = inBitCount1.uintValue () ;
    const uint32_t bitSize2 = inBitCount2.uintValue () ;
    const uint32_t bitSize3 = inBitCount3.uintValue () ;
    result = GALGAS_binaryset (mBDD.swap102 (bitSize1, bitSize2, bitSize3)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_swap_31__32__30_ (const GALGAS_uint & inBitCount1,
                                                            const GALGAS_uint & inBitCount2,
                                                            const GALGAS_uint & inBitCount3
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inBitCount1.isValid ()) && (inBitCount2.isValid ()) && (inBitCount3.isValid ())) {
    const uint32_t bitSize1 = inBitCount1.uintValue () ;
    const uint32_t bitSize2 = inBitCount2.uintValue () ;
    const uint32_t bitSize3 = inBitCount3.uintValue () ;
    result = GALGAS_binaryset (mBDD.swap120 (bitSize1, bitSize2, bitSize3)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_swap_32__30__31_ (const GALGAS_uint & inBitCount1,
                                                            const GALGAS_uint & inBitCount2,
                                                            const GALGAS_uint & inBitCount3
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inBitCount1.isValid ()) && (inBitCount2.isValid ()) && (inBitCount3.isValid ())) {
    const uint32_t bitSize1 = inBitCount1.uintValue () ;
    const uint32_t bitSize2 = inBitCount2.uintValue () ;
    const uint32_t bitSize3 = inBitCount3.uintValue () ;
    result = GALGAS_binaryset (mBDD.swap210 (bitSize1, bitSize2, bitSize3)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_swap_32__31__30_ (const GALGAS_uint & inBitCount1,
                                                            const GALGAS_uint & inBitCount2,
                                                            const GALGAS_uint & inBitCount3
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inBitCount1.isValid ()) && (inBitCount2.isValid ()) && (inBitCount3.isValid ())) {
    const uint32_t bitSize1 = inBitCount1.uintValue () ;
    const uint32_t bitSize2 = inBitCount2.uintValue () ;
    const uint32_t bitSize3 = inBitCount3.uintValue () ;
    result = GALGAS_binaryset (mBDD.swap210 (bitSize1, bitSize2, bitSize3)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_transitiveClosure (const GALGAS_uint & inBitCount
                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inBitCount.isValid ()) {
    const uint32_t bitCount = inBitCount.uintValue () ;
    result = GALGAS_binaryset (mBDD.transitiveClosure (bitCount, NULL)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_accessibleStates (const GALGAS_binaryset & inInitialStateSet,
                                                            const GALGAS_uint & inBitCount
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
//--- Current object is edge [x, y].
//    Accessible states set is computed by:
// accessible [x] += initial [x] | exists y (accessible [y] & edge [y, x]) ;
  GALGAS_binaryset result ;
  if ((inInitialStateSet.isValid ()) && (inBitCount.isValid ())) {
    result = GALGAS_binaryset (mBDD.accessibleStates (inInitialStateSet.mBDD,
                               inBitCount.uintValue (),
                               NULL)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_binarySetByTranslatingFromIndex (const GALGAS_uint & inFirstIndexToTranslate,
                                                                           const GALGAS_uint & inTranslation 
                                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inFirstIndexToTranslate.isValid ()) && (inTranslation.isValid ())) {
    const uint32_t varCount = mBDD.significantVariableCount () ;
    const uint32_t translation = inTranslation.uintValue () ;
    if ((varCount == 0) || (translation == 0)) {
      result = *this ;
    }else{
      const uint32_t firstIndex = inFirstIndexToTranslate.uintValue () ;
      uint32_t * substitionArray = NULL ;
      macroMyNewArray (substitionArray, uint32_t, varCount) ;
      for (uint32_t i=0 ; i<varCount ; i++) {
        substitionArray [i] = i ;
      }
      for (uint32_t i=firstIndex ; i<varCount ; i++) {
        substitionArray [i] = (uint32_t) (substitionArray [i] + translation) ;
      }
      result = GALGAS_binaryset (mBDD.substitution (substitionArray, varCount COMMA_THERE)) ;
      macroMyDeleteArray (substitionArray) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::getter_existsOnBitRange (const GALGAS_uint & inFirstIndex,
                                                            const GALGAS_uint & inCount 
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inFirstIndex.isValid ()) && (inCount.isValid ())) {
    const uint32_t varCount = mBDD.significantVariableCount () ;
    const uint32_t count = inCount.uintValue () ;
    if ((varCount == 0) || (count == 0)) {
      result = *this ;
    }else{
      const uint32_t firstIndex = inFirstIndex.uintValue () ;
      result = GALGAS_binaryset (mBDD.existsOnBitRange (firstIndex, count)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::left_shift_operation (const GALGAS_uint inLeftShiftCount
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid () && (inLeftShiftCount.isValid ())) {
    result = GALGAS_binaryset (mBDD.bddByLeftShifting (inLeftShiftCount.uintValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::right_shift_operation (const GALGAS_uint inRightShiftCount
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid () && (inRightShiftCount.isValid ())) {
    result = GALGAS_binaryset (mBDD.bddByRightShifting (inRightShiftCount.uintValue ())) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_binaryset::objectCompare (const GALGAS_binaryset & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mBDD.integerValue () < inOperand.mBDD.integerValue ()) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mBDD.integerValue () > inOperand.mBDD.integerValue ()) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_binaryset::class_method_setNodeTableSize (class GALGAS_uint inTableSize
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  if (inTableSize.isValid ()) {
    C_BDD::setHashMapMaxSize (inTableSize.uintValue ()) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_binaryset::class_method_setAndTableSize (class GALGAS_uint inTableSize
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  if (inTableSize.isValid ()) {
    C_BDD::setANDOperationCacheMaxSize (inTableSize.uintValue ()) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

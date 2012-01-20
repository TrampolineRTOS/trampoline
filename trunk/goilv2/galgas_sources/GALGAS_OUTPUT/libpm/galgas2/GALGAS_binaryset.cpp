//---------------------------------------------------------------------------*
//                                                                           *
//  GALGAS_binaryset                                                         *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Created january 22, 2007.                                                *
//                                                                           *
//  Copyright (C) 2007, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
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

#include "predefined-types.h"
#include "galgas2/C_Compiler.h"

//---------------------------------------------------------------------------*

GALGAS_binaryset::GALGAS_binaryset (void) :
mIsValid (false),
mBDD () {
}

//---------------------------------------------------------------------------*

GALGAS_binaryset::GALGAS_binaryset (const C_BDD & inOperand_mBDD) :
mIsValid (true),
mBDD (inOperand_mBDD) {
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_emptyBinarySet (UNUSED_LOCATION_ARGS) {
  return GALGAS_binaryset (C_BDD ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_fullBinarySet (UNUSED_LOCATION_ARGS) {
  C_BDD bdd ;
  bdd.setToTrue () ;
  return GALGAS_binaryset (bdd) ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithBit (const GALGAS_uint & inBitIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  GALGAS_binaryset result ;
  if (inBitIndex.isValid ()) {
    const PMUInt32 bitIndex = inBitIndex.uintValue () ;
    if (bitIndex > 32766) {
      inCompiler->onTheFlyRunTimeError ("bit index greater than 32766" COMMA_THERE) ;
    }else{
      const C_BDD bdd ((PMUInt16) (bitIndex & PMUINT16_MAX), true) ;
      result = GALGAS_binaryset (bdd) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::constructor_binarySetWithPredicateString (const GALGAS_string & inBitString,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_binaryset result ;
  if (inBitString.isValid ()) {
    const C_String bitString = inBitString.stringValue () ;
    const PMSInt32 stringLength = bitString.length () ;
    PMSInt32 stringIndex = 0 ;
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
        PMSInt32 bitIndex = 0 ;
        for (PMSInt32 i=s.length () - 1 ; i>=0 ; i--) {
          const utf32 c = s (i COMMA_HERE) ;
          if (UNICODE_VALUE (c) == '0') {
            v &= C_BDD ((PMUInt16) (bitIndex & PMUINT16_MAX), false) ;
            bitIndex ++ ;
          }else if (UNICODE_VALUE (c) == '1') {
            v &= C_BDD ((PMUInt16) (bitIndex & PMUINT16_MAX), true) ;
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

//---------------------------------------------------------------------------*

static GALGAS_binaryset binarySetWithComparison (C_Compiler * inCompiler,
                                                 const GALGAS_uint & inLeftFirstIndex,
                                                 const GALGAS_uint & inBitCount,
                                                 const C_BDD::compareEnum inComparison,
                                                 const GALGAS_uint & inRightFirstIndex                                             
                                                 COMMA_LOCATION_ARGS) {
  GALGAS_binaryset result ;
  if ((inLeftFirstIndex.isValid ()) && (inBitCount.isValid ()) && (inRightFirstIndex.isValid ())) {
    const PMUInt64 maxLeft = ((PMUInt64) inLeftFirstIndex.uintValue ()) + inBitCount.uintValue () ;
    const PMUInt64 maxRight = ((PMUInt64) inRightFirstIndex.uintValue ()) + inBitCount.uintValue () ;
    if (maxLeft > 32766) {
      inCompiler->onTheFlyRunTimeError ("left operand upper bit is greater than 32766" COMMA_THERE) ;
    }else if (maxRight > 32766) {
      inCompiler->onTheFlyRunTimeError ("right operand upper bit is greater than 32766" COMMA_THERE) ;
    }else {
      result = GALGAS_binaryset (C_BDD::varCompareVar ((PMUInt16) (inLeftFirstIndex.uintValue () & PMUINT16_MAX),
                                                                        (PMUInt16) (inBitCount.uintValue () & PMUINT16_MAX),
                                                                        inComparison,
                                                                        (PMUInt16) (inRightFirstIndex.uintValue () & PMUINT16_MAX))
                                ) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

static GALGAS_binaryset binarySetWithComparisonWithConstant (C_Compiler * inCompiler,
                                                             const GALGAS_uint & inBitIndex,
                                                             const GALGAS_uint & inBitCount,
                                                             const C_BDD::compareEnum inComparison,
                                                             const GALGAS_uint_36__34_ & inConstant                                             
                                                             COMMA_LOCATION_ARGS) {
  GALGAS_binaryset result ;
  if ((inBitIndex.isValid ()) && (inBitCount.isValid ()) && (inConstant.isValid ())) {
    const PMUInt64 maxLeft = ((PMUInt64) inBitIndex.uintValue ()) + inBitCount.uintValue () ;
    if (maxLeft > 32766) {
      inCompiler->onTheFlyRunTimeError ("left operand upper bit is greater than 32766" COMMA_THERE) ;
    }else {
      result = GALGAS_binaryset (C_BDD::varCompareConst ((PMUInt16) (inBitIndex.uintValue () & PMUINT16_MAX),
                                                                          (PMUInt16) (inBitCount.uintValue () & PMUINT16_MAX),
                                                                          inComparison,
                                                                          inConstant.uint64Value ())
                                ) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Operators
#endif

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::operator_xor (const GALGAS_binaryset & inOperand2
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_binaryset (mBDD != inOperand2.mBDD) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::operator_and (const GALGAS_binaryset & inOperand2
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_binaryset (mBDD & inOperand2.mBDD) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::operator_or (const GALGAS_binaryset & inOperand2
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid () && inOperand2.isValid ()) {
    result = GALGAS_binaryset (mBDD | inOperand2.mBDD) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::operator_tilde (UNUSED_LOCATION_ARGS) const {
  return GALGAS_binaryset (~ mBDD) ;
}

//---------------------------------------------------------------------------*

void GALGAS_binaryset::description (C_String & ioString,
                               const PMSInt32 /* inIndentation */) const {
  ioString << "<@binaryset: " ;
  if (isValid ()) {
    if (mBDD.isFalse ()){
      ioString << "false" ;
    }else if (mBDD.isTrue ()){
      ioString << "true" ;
    }else{
      TC_UniqueArray <C_String> stringArray ;
      mBDD.buildCompressedBigEndianStringValueArray (stringArray COMMA_HERE) ;
      for (PMSInt32 i=0 ; i<stringArray.count () ; i++) {
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

//---------------------------------------------------------------------------*

GALGAS_bool GALGAS_binaryset::reader_containsValue (const GALGAS_uint_36__34_ & inValue,
                                                      const GALGAS_uint & inFirstBit,
                                                      const GALGAS_uint & inBitCount
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if ((inValue.isValid ()) && (inFirstBit.isValid ()) && (inBitCount.isValid ())) {
     const PMUInt64 value = inValue.uint64Value () ;
     const PMUInt16 firstBit = (PMUInt16) (inFirstBit.uintValue () & PMUINT16_MAX) ;
     const PMUInt16 bitCount = (PMUInt16) (inBitCount.uintValue () & PMUINT16_MAX) ;
     result = GALGAS_bool (mBDD.containsValue (value, firstBit, bitCount)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_ITE (const GALGAS_binaryset & inTHENoperand,
                                                 const GALGAS_binaryset & inELSEoperand                                             
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inTHENoperand.isValid ()) && (inELSEoperand.isValid ())) {
    result = GALGAS_binaryset (C_BDD::ite (mBDD, inTHENoperand.mBDD, inELSEoperand.mBDD)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_equalTo (const GALGAS_binaryset & inOperand
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset (mBDD == inOperand.mBDD) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_notEqualTo (const GALGAS_binaryset & inOperand
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset (mBDD != inOperand.mBDD) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_lowerOrEqualTo (const GALGAS_binaryset & inOperand
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset (mBDD <= inOperand.mBDD) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_greaterOrEqualTo (const GALGAS_binaryset & inOperand
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset (mBDD >= inOperand.mBDD) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_strictLowerThan (const GALGAS_binaryset & inOperand
                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset (mBDD < inOperand.mBDD) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_strictGreaterThan (const GALGAS_binaryset & inOperand
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inOperand.isValid ()) {
    result = GALGAS_binaryset (mBDD > inOperand.mBDD) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_bool GALGAS_binaryset::reader_isFull (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (mBDD.isTrue ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_bool GALGAS_binaryset::reader_isEmpty (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (mBDD.isFalse ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_uint GALGAS_binaryset::reader_significantVariableCount (UNUSED_LOCATION_ARGS) const {
  return GALGAS_uint (mBDD.significantVariableCount ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_binaryset::reader_valueCount (const GALGAS_uint & inVariableCount,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (inVariableCount.isValid ()) {
    if (mBDD.significantVariableCount () > inVariableCount.uintValue ()) {
      inCompiler->onTheFlyRunTimeError ("needed variable count is greater than variable count argument" COMMA_THERE) ;
    }else if (inVariableCount.uintValue () > (((PMSInt32) PMUINT16_MAX) + 1)) {
      inCompiler->onTheFlyRunTimeError ("variable count argument is greater than 32767" COMMA_THERE) ;
    }else{
      result = GALGAS_uint_36__34_ (mBDD.valueCount ((PMUInt16) (inVariableCount.uintValue () & PMUINT16_MAX))) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_binaryset::reader_compressedValueCount (UNUSED_LOCATION_ARGS) const {
  TC_UniqueArray <C_String> valuesArray ;
  mBDD.buildCompressedLittleEndianStringValueArray (valuesArray COMMA_HERE) ;
  return GALGAS_uint_36__34_ ((PMUInt32) valuesArray.count ()) ;
}

//---------------------------------------------------------------------------*

GALGAS_uint_36__34_list GALGAS_binaryset::reader_uint_36__34_ValueList (const GALGAS_uint & inVariableCount,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_uint_36__34_list result ;
  if (inVariableCount.isValid ()) {
    if (inVariableCount.uintValue () > (((PMSInt32) PMUINT16_MAX) + 1)) {
      inCompiler->onTheFlyRunTimeError ("variable count argument is greater than 32767" COMMA_THERE) ;
    }else{
      TC_UniqueArray <PMUInt64> valuesArray ;
      mBDD.buildValueArray (valuesArray, (PMUInt16) (inVariableCount.uintValue () & PMUINT16_MAX)) ;
      result = GALGAS_uint_36__34_list::constructor_emptyList (THERE) ;
      for (PMSInt32 i=0 ; i<valuesArray.count () ; i++) {
        const PMUInt64 v = valuesArray (i COMMA_HERE) ;
        result.addAssign_operation (GALGAS_uint_36__34_ (v) COMMA_HERE) ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_binaryset::reader_stringValueListWithNameList (const GALGAS_uint & inVariableCount,
                                                                        const GALGAS_stringlist & inStringList,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if ((inVariableCount.isValid ()) && (inStringList.isValid ())) {
    if (inVariableCount.uintValue () > (((PMSInt32) PMUINT16_MAX) + 1)) {
      inCompiler->onTheFlyRunTimeError ("variable count argument is greater than 32767" COMMA_THERE) ;
    }else{
      TC_UniqueArray <PMUInt64> valuesArray ;
      mBDD.buildValueArray (valuesArray, (PMUInt16) (inVariableCount.uintValue () & PMUINT16_MAX)) ;
      result = GALGAS_stringlist::constructor_emptyList (THERE) ;
      for (PMSInt32 i=0 ; i<valuesArray.count () ; i++) {
        const PMUInt32 v = (PMUInt32) (valuesArray (i COMMA_HERE) & PMUINT32_MAX) ;
        GALGAS_uint object = GALGAS_uint (v) ;
        result.addAssign_operation (inStringList.reader_mValueAtIndex (object, inCompiler COMMA_HERE) COMMA_HERE) ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_binaryset::reader_compressedStringValueList (const GALGAS_uint & inVariableCount,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inVariableCount.isValid ()) {
    if (inVariableCount.uintValue () > (((PMSInt32) PMUINT16_MAX) + 1)) {
      inCompiler->onTheFlyRunTimeError ("variable count argument is greater than 32767" COMMA_THERE) ;
    }else{
      const PMUInt16 variableCount = (PMUInt16) (inVariableCount.uintValue () & PMUINT16_MAX) ;
      const PMUInt16 actualVariableCount = mBDD.significantVariableCount () ;
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
        for (PMSInt32 i=0 ; i<valuesArray.count () ; i++) {
          const C_String v = valuesArray (i COMMA_HERE) ;
          result.addAssign_operation (GALGAS_string (v) COMMA_HERE) ;
        }
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_binaryset::reader_stringValueList (const GALGAS_uint & inVariableCount,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (inVariableCount.isValid ()) {
    if (inVariableCount.uintValue () > (((PMSInt32) PMUINT16_MAX) + 1)) {
      inCompiler->onTheFlyRunTimeError ("variable count argument is greater than 32767" COMMA_THERE) ;
    }else{
      TC_UniqueArray <C_String> valuesArray ;
      mBDD.buildBigEndianStringValueArray (valuesArray, (PMUInt16) (inVariableCount.uintValue () & PMUINT16_MAX)) ;
      result = GALGAS_stringlist::constructor_emptyList (THERE) ;
      for (PMSInt32 i=0 ; i<valuesArray.count () ; i++) {
        const C_String v = valuesArray (i COMMA_HERE) ;
        result.addAssign_operation (GALGAS_string (v) COMMA_HERE) ;
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_string GALGAS_binaryset::reader_predicateStringValue (LOCATION_ARGS) const {
  return GALGAS_string (mBDD.queryStringValue (THERE)) ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_forAllOnBitIndex (const GALGAS_uint & inVariableIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inVariableIndex.uintValue () > 32766) {
    inCompiler->onTheFlyRunTimeError ("index argument is greater than 32766" COMMA_THERE) ;
  }else{
    result = GALGAS_binaryset (mBDD.forallOnBitNumber ((PMUInt16) (inVariableIndex.uintValue () & PMUINT16_MAX))) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_forAllOnBitIndexAndBeyond (const GALGAS_uint & inVariableIndex,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inVariableIndex.uintValue () > 32766) {
    inCompiler->onTheFlyRunTimeError ("index argument is greater than 32766" COMMA_THERE) ;
  }else{
    result = GALGAS_binaryset (mBDD.forallOnBitsAfterNumber ((PMUInt16) (inVariableIndex.uintValue () & PMUINT16_MAX))) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_existOnBitIndex (const GALGAS_uint & inVariableIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS)const  {
  GALGAS_binaryset result ;
  if (inVariableIndex.uintValue () > 32766) {
    inCompiler->onTheFlyRunTimeError ("index argument is greater than 32766" COMMA_THERE) ;
  }else{
    result = GALGAS_binaryset (mBDD.existsOnBitNumber ((PMUInt16) (inVariableIndex.uintValue () & PMUINT16_MAX))) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_existOnBitIndexAndBeyond (const GALGAS_uint & inVariableIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inVariableIndex.isValid ()) {
    if (inVariableIndex.uintValue () > 32766) {
      inCompiler->onTheFlyRunTimeError ("index argument is greater than 32766" COMMA_THERE) ;
    }else{
      result = GALGAS_binaryset (mBDD.existsOnBitsAfterNumber ((PMUInt16) (inVariableIndex.uintValue () & PMUINT16_MAX))) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_swap_32__31_ (const GALGAS_uint & inBitCount1,
                                                          const GALGAS_uint & inBitCount2
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inBitCount1.isValid ()) && (inBitCount2.isValid ())) {
    const PMUInt16 bitSize1 = (PMUInt16) (inBitCount1.uintValue () & PMUINT16_MAX) ;
    const PMUInt16 bitSize2 = (PMUInt16) (inBitCount2.uintValue () & PMUINT16_MAX) ;
    result = GALGAS_binaryset (mBDD.swap21 (bitSize1, bitSize2)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_swap_31__33__32_ (const GALGAS_uint & inBitCount1,
                                                              const GALGAS_uint & inBitCount2,
                                                              const GALGAS_uint & inBitCount3
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inBitCount1.isValid ()) && (inBitCount2.isValid ()) && (inBitCount3.isValid ())) {
    const PMUInt16 bitSize1 = (PMUInt16) (inBitCount1.uintValue () & PMUINT16_MAX) ;
    const PMUInt16 bitSize2 = (PMUInt16) (inBitCount2.uintValue () & PMUINT16_MAX) ;
    const PMUInt16 bitSize3 = (PMUInt16) (inBitCount3.uintValue () & PMUINT16_MAX) ;
    result = GALGAS_binaryset (mBDD.swap132  (bitSize1, bitSize2, bitSize3)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_swap_32__31__33_ (const GALGAS_uint & inBitCount1,
                                                              const GALGAS_uint & inBitCount2,
                                                              const GALGAS_uint & inBitCount3
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inBitCount1.isValid ()) && (inBitCount2.isValid ()) && (inBitCount3.isValid ())) {
    const PMUInt16 bitSize1 = (PMUInt16) (inBitCount1.uintValue () & PMUINT16_MAX) ;
    const PMUInt16 bitSize2 = (PMUInt16) (inBitCount2.uintValue () & PMUINT16_MAX) ;
    const PMUInt16 bitSize3 = (PMUInt16) (inBitCount3.uintValue () & PMUINT16_MAX) ;
    result = GALGAS_binaryset (mBDD.swap213 (bitSize1, bitSize2, bitSize3)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_swap_32__33__31_ (const GALGAS_uint & inBitCount1,
                                                              const GALGAS_uint & inBitCount2,
                                                              const GALGAS_uint & inBitCount3
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inBitCount1.isValid ()) && (inBitCount2.isValid ()) && (inBitCount3.isValid ())) {
    const PMUInt16 bitSize1 = (PMUInt16) (inBitCount1.uintValue () & PMUINT16_MAX) ;
    const PMUInt16 bitSize2 = (PMUInt16) (inBitCount2.uintValue () & PMUINT16_MAX) ;
    const PMUInt16 bitSize3 = (PMUInt16) (inBitCount3.uintValue () & PMUINT16_MAX) ;
    result = GALGAS_binaryset (mBDD.swap231 (bitSize1, bitSize2, bitSize3)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_swap_33__31__32_ (const GALGAS_uint & inBitCount1,
                                                              const GALGAS_uint & inBitCount2,
                                                              const GALGAS_uint & inBitCount3
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inBitCount1.isValid ()) && (inBitCount2.isValid ()) && (inBitCount3.isValid ())) {
    const PMUInt16 bitSize1 = (PMUInt16) (inBitCount1.uintValue () & PMUINT16_MAX) ;
    const PMUInt16 bitSize2 = (PMUInt16) (inBitCount2.uintValue () & PMUINT16_MAX) ;
    const PMUInt16 bitSize3 = (PMUInt16) (inBitCount3.uintValue () & PMUINT16_MAX) ;
    result = GALGAS_binaryset (mBDD.swap321 (bitSize1, bitSize2, bitSize3)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_swap_33__32__31_ (const GALGAS_uint & inBitCount1,
                                                              const GALGAS_uint & inBitCount2,
                                                              const GALGAS_uint & inBitCount3
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inBitCount1.isValid ()) && (inBitCount2.isValid ()) && (inBitCount3.isValid ())) {
    const PMUInt16 bitSize1 = (PMUInt16) (inBitCount1.uintValue () & PMUINT16_MAX) ;
    const PMUInt16 bitSize2 = (PMUInt16) (inBitCount2.uintValue () & PMUINT16_MAX) ;
    const PMUInt16 bitSize3 = (PMUInt16) (inBitCount3.uintValue () & PMUINT16_MAX) ;
    result = GALGAS_binaryset (mBDD.swap321 (bitSize1, bitSize2, bitSize3)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_transitiveClosure (const GALGAS_uint & inBitCount
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (inBitCount.isValid ()) {
    const PMUInt16 bitCount = (PMUInt16) (inBitCount.uintValue () & PMUINT16_MAX) ;
    result = GALGAS_binaryset (mBDD.transitiveClosure (bitCount, NULL)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_accessibleStates (const GALGAS_binaryset & inInitialStateSet,
                                                              const GALGAS_uint & inBitSize
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
//--- Current object is edge [x, y].
//    Accessible states set is computed by:
// accessible [x] += initial [x] | exists y (accessible [y] & edge [y, x]) ;
  GALGAS_binaryset result ;
  if ((inInitialStateSet.isValid ()) && (inBitSize.isValid ())) {
    result = GALGAS_binaryset (mBDD.accessibleStates (inInitialStateSet.mBDD,
                                                   (PMUInt16) (inBitSize.uintValue () & PMUINT16_MAX),
                                                   NULL)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_binarySetByTranslatingFromIndex (const GALGAS_uint & inFirstIndexToTranslate,
                                                                           const GALGAS_uint & inTranslation 
                                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inFirstIndexToTranslate.isValid ()) && (inTranslation.isValid ())) {
    const PMUInt16 varCount = mBDD.significantVariableCount () ;
    const PMUInt16 translation = (PMUInt16) (inTranslation.uintValue () & PMUINT16_MAX) ;
    if ((varCount == 0) || (translation == 0)) {
      result = *this ;
    }else{
      const PMUInt16 firstIndex = (PMUInt16) (inFirstIndexToTranslate.uintValue () & PMUINT16_MAX) ;
      PMUInt16 * substitionArray = NULL ;
      macroMyNewArray (substitionArray, PMUInt16, varCount) ;
      for (PMUInt16 i=0 ; i<varCount ; i++) {
        substitionArray [i] = i ;
      }
      for (PMUInt16 i=firstIndex ; i<varCount ; i++) {
        substitionArray [i] = (PMUInt16) (substitionArray [i] + translation) ;
      }
      result = GALGAS_binaryset (mBDD.substitution (substitionArray, varCount COMMA_THERE)) ;
      macroMyDeleteArray (substitionArray) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::reader_existsOnBitRange (const GALGAS_uint & inFirstIndex,
                                                              const GALGAS_uint & inCount 
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if ((inFirstIndex.isValid ()) && (inCount.isValid ())) {
    const PMUInt16 varCount = mBDD.significantVariableCount () ;
    const PMUInt16 count = (PMUInt16) (inCount.uintValue () & PMUINT16_MAX) ;
    if ((varCount == 0) || (count == 0)) {
      result = *this ;
    }else{
      const PMUInt16 firstIndex = (PMUInt16) (inFirstIndex.uintValue () & PMUINT16_MAX) ;
      result = GALGAS_binaryset (mBDD.existsOnBitRange (firstIndex, count)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::left_shift_operation (const GALGAS_uint inLeftShiftCount
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid () && (inLeftShiftCount.isValid ())) {
    result = GALGAS_binaryset (mBDD.bddByLeftShifting ((PMUInt16) (inLeftShiftCount.uintValue () & PMUINT16_MAX))) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_binaryset GALGAS_binaryset::right_shift_operation (const GALGAS_uint inRightShiftCount
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_binaryset result ;
  if (isValid () && (inRightShiftCount.isValid ())) {
    result = GALGAS_binaryset (mBDD.bddByRightShifting ((PMUInt16) (inRightShiftCount.uintValue () & PMUINT16_MAX))) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

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

#ifndef BINARY_DECISION_DIAGRAMS_DEFINED
#define BINARY_DECISION_DIAGRAMS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/M_machine.h"
#include "utilities/PMUInt128.h"
#include "collections/TC_UniqueArray.h"
#include "collections/TC_Array.h"

//---------------------------------------------------------------------------------------------------------------------*

#include <stdio.h>

//---------------------------------------------------------------------------------------------------------------------*

class C_bdd_value_traversing ;
class C_String ;
class AC_OutputStream ;

//---------------------------------------------------------------------------------------------------------------------*

class C_BDD {
//--- enum for comparison operators
  public : enum compareEnum {kEqual, kNotEqual, kLowerOrEqual,
                             kStrictLower, kGreaterOrEqual, kStrictGreater} ;

//--- Constructors and destructor
  public : C_BDD (void) ; // Get a false BDD
  private : C_BDD (const uint32_t inInternalValue) ; // Internal, do not use
  public : C_BDD (const uint32_t inVariable, const bool inSign) ;
  public : virtual ~C_BDD (void) ;

//--- Control copy
  public : C_BDD (const C_BDD & inSource) ;
  public : C_BDD & operator = (const C_BDD & inSource) ;

//--- Decision diagram root
  private : uint32_t mBDDvalue ;

//--- Link between existing instances
  private : C_BDD * mPtrToPreviousBDD ;
  private : C_BDD * mPtrToNextBDD ;

//--- Set to false or true
  public : void setToFalse (void) ;
  public : void setToTrue (void) ;

//--- Test BDD
  public : inline bool isFalse (void) const { return mBDDvalue == 0 ; }
  public : inline bool isTrue (void) const { return mBDDvalue == 1 ; }
  public : bool isComplemented (void) const ;

  public : inline bool operator == (const C_BDD & inOperand) const { return mBDDvalue == inOperand.mBDDvalue ; }
  public : inline bool operator != (const C_BDD & inOperand) const { return mBDDvalue != inOperand.mBDDvalue ; }
  public : inline uint32_t integerValue (void) const { return mBDDvalue ; }

//--- Operations on a BDD
  public : void operator &= (const C_BDD & inOperand) ; // And
  public : void operator |= (const C_BDD & inOperand) ; // Or
  public : void negate (void) ; 

//--- Operations between BDDs
  public : C_BDD operator & (const C_BDD & inOperand) const ; // And
  public : C_BDD operator | (const C_BDD & inOperand) const ; // Or
  public : C_BDD equalTo (const C_BDD & inOperand) const ; // Equivalent
  public : C_BDD notEqualTo (const C_BDD & inOperand) const ; // Different
  public : C_BDD lowerOrEqual (const C_BDD & inOperand) const ; 
  public : C_BDD lowerThan (const C_BDD & inOperand) const ;
  public : C_BDD greaterOrEqual (const C_BDD & inOperand) const ;
  public : C_BDD greaterThan (const C_BDD & inOperand) const ;
  public : C_BDD implies (const C_BDD & inOperand) const ; // ->
  public : static C_BDD ite (const C_BDD & f, const C_BDD & g, const C_BDD & h) ; // ite (f, g, h)
  public : C_BDD operator ~ (void) const ; // get complement
  public : C_BDD bddByLeftShifting (const uint32_t inLeftShiftCount) const ;
  public : C_BDD bddByRightShifting (const uint32_t inRightShiftCount) const ;

//--- for all and exists
  public : C_BDD forallOnBitNumber (const uint32_t numeroBit) const ;
  public : C_BDD forallOnBitsAfterNumber (const uint32_t numeroBit) const ;

  public : C_BDD existsOnBitNumber (const uint32_t numeroBit) const ;
  public : C_BDD existsOnBitRange (const uint32_t inFirstBit, const uint32_t inBitCount) const ;
  public : C_BDD existsOnBitsAfterNumber (const uint32_t numeroBit) const ;

//--- Comparison between BDDs
  public : C_BDD compareWithBDD (const compareEnum inComparison, const C_BDD & inOperand) const ;

//--- Build a BDD result of integer comparison
  public : static C_BDD
  varCompareVar (const uint32_t inLeftFirstIndex,
                 const uint32_t inDimension,
                 const compareEnum inComparison,
                 const uint32_t inRightFirstIndex) ;

  public : static
  C_BDD varCompareConst (const uint32_t inFirstIndex,
                         const uint32_t inDimension,
                         const compareEnum inComparison,
                         const uint64_t inComparisonConstant) ;

  public : static
  C_BDD bddWithConstants (const uint32_t inValues [],
                          const uint32_t inBitCount [],
                          const int32_t inEntryCount) ;

//--- Buil a BDD from a value list. This method sorts value list in ascending order
  public : static C_BDD buildBDDFromValueList (uint64_t ioValueList [],
                                               const uint32_t inValueCount,
                                               const uint32_t inBitCount) ;

//--- Get BDD values count
  public : uint64_t valueCount64 (const uint32_t inVariableCount) const ;

  public : PMUInt128 valueCount128 (const uint32_t inVariableCount) const ;

  public : uint64_t valueCount64UsingCache (const uint32_t inVariableCount,
                                            TC_UniqueArray <uint64_t> & ioDirectCacheArray,
                                            TC_UniqueArray <uint64_t> & ioComplementCacheArray) const ;

  public : PMUInt128 valueCount128UsingCache (const uint32_t inVariableCount,
                                              TC_UniqueArray <PMUInt128> & ioDirectCacheArray,
                                              TC_UniqueArray <PMUInt128> & ioComplementCacheArray) const ;

//--- Return highest bit index + 1 
  public : uint32_t significantVariableCount (void) const ;

//--- Get nth BDD value
  public : C_BDD getNthBDD (const uint64_t inNthBDDvalue,
                            const uint32_t inVariableCount) const ;

//--- Get BDD range in 'inOperand' BDD
  public : uint64_t getBDDrange (const C_BDD & inOperand,
                               const uint32_t inVariableCount) const ;

//--- Get BDD absolute value
  public : uint64_t getBDDabsoluteValue (const uint32_t inVariableCount) const ;
  
//--- Get BDD nodes count
  public : uint32_t getBDDnodesCount (void) const ;

//--- Test if a BDD does contain a value
  public : bool containsValue64 (const uint64_t inValue,
                                 const uint32_t inFirstBit,
                                 const uint32_t inBitCount) const ;

  public : bool containsValue (const TC_Array <bool> & inValue,
                               const uint32_t inFirstBit,
                               const uint32_t inBitCount) const ;

//------------------------ Updating a relation
  public : C_BDD updateRelation (const uint32_t inRelationBitNeededCount [], 
                                 uint32_t * inRelationBitCurrentCount [], 
                                 const int32_t inRelationCardinality) const ;

//--- Translate BDD bits
  public : C_BDD translate (const uint32_t inVariableCount,
                            const uint32_t inTranslation) const ;

  public : void getBoolArray (TC_UniqueArray <bool> & outArray,
                              const uint32_t inMaxValues,
                              const uint32_t inBitSize) const ;

//---- Substituing variables
  public : C_BDD substitution (const uint32_t inSubstitutionArray [],
                               const uint32_t inVariableCount
                               COMMA_LOCATION_ARGS) const ;

  public : C_BDD exchangeVariables (const uint32_t var1, const uint32_t var2) const ;

  public : C_BDD rollDownVariables (const uint32_t var1, const uint32_t var2) const ;

  public : C_BDD rollUpVariables (const uint32_t var1, const uint32_t var2) const ;

//--- BDD as 2-relations
  public : C_BDD swap10 (const uint32_t inBitSize1,
                         const uint32_t inBitSize2) const ;

  public : C_BDD accessibleStates (const C_BDD & inInitialStateSet,
                                   const uint32_t inBitSize,
                                   int32_t * outIterationCount) const ;

  public : C_BDD transitiveClosure (const uint32_t inBitSize,
                                    int32_t * outIterationCount) const ;

  public : void getArray2 (TC_UniqueArray <TC_UniqueArray <uint64_t> > & outArray,
                           const uint32_t inMaxValueCount,
                           const uint32_t inBitSize1,
                           const uint32_t inBitSize2) const ;

//--- BDD as 3-relations
  public : C_BDD swap021 (const uint32_t inBitSize1,
                          const uint32_t inBitSize2,
                          const uint32_t inBitSize3) const ;

  public : C_BDD swap102 (const uint32_t inBitSize1,
                          const uint32_t inBitSize2,
                          const uint32_t inBitSize3) const ;

  public : C_BDD swap120 (const uint32_t inBitSize1,
                          const uint32_t inBitSize2,
                          const uint32_t inBitSize3) const ;

  public : C_BDD swap201 (const uint32_t inBitSize1,
                          const uint32_t inBitSize2,
                          const uint32_t inBitSize3) const ;

  public : C_BDD swap210 (const uint32_t inBitSize1,
                          const uint32_t inBitSize2,
                          const uint32_t inBitSize3) const ;



//--- Printing
  public : C_String graphvizRepresentation (void) const ;

  public : void print (AC_OutputStream & outputStream) const ;

  public : void printHeader (AC_OutputStream & outputStream) const ;

  public : void printWithHeader (AC_OutputStream & outputStream) const ;

/*  public : void printWithSeparator (AC_OutputStream & outputStream,
                                    const TC_UniqueArray <C_String> & inSeparatorArray) const ;

  public : void print (AC_OutputStream & outputStream,
                       const TC_UniqueArray <C_String> & inVariablesNames,
                       const int32_t inLeadingSpacesCount) const ;

  public : void print (AC_OutputStream & outputStream,
                       const TC_UniqueArray <C_String> & inVariablesNames,
                       const int32_t inVariableCount,
                       const int32_t inLeadingSpacesCount) const ;

  public : void printHeader (AC_OutputStream & outputStream,
                             const TC_UniqueArray <C_String> & inVariablesNames,
                             const int32_t inVariableCount,
                             const int32_t inLeadingSpacesCount) const ;

  public : void printWithoutHeader (AC_OutputStream & outputStream,
                                    const TC_UniqueArray <C_String> & inVariablesNames,
                                    const int32_t inVariableCount,
                                    const int32_t inLeadingSpacesCount) const ; */

//--- Buid string compressed representation
  public : void buildCompressedLittleEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray
                                                             COMMA_LOCATION_ARGS) const ;

  public : void buildCompressedLittleEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray,
                                                             const uint32_t inVariableCount
                                                             COMMA_LOCATION_ARGS) const ;

  public : void buildCompressedBigEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray
                                                          COMMA_LOCATION_ARGS) const ;

  public : void buildCompressedBigEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray,
                                                          const uint32_t inVariableCount
                                                          COMMA_LOCATION_ARGS) const ;

//--- Mark all nodes 
  public : void markAllBDDnodes (void) ;

//--- Check all BDDs are well formed 
  public : static void checkAllBDDsAreWellFormed (LOCATION_ARGS) ;

//--- Check a BDD is well formed 
  public :  void checkBDDIsWellFormed (LOCATION_ARGS) ;

//--- Traversing BDD : build an array containing all values
  public : void buildValue64Array (TC_UniqueArray <uint64_t> & outValuesArray,
                                   const uint32_t inVariableCount) const ;

  public : void buildValueArray (TC_UniqueArray <TC_Array <bool> > & outValuesArray,
                                  const uint32_t inVariableCount) const ;

  public : void buildLittleEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray,
                                                   const uint32_t inVariableCount) const ;

  public : void buildBigEndianStringValueArray (TC_UniqueArray <C_String> & outStringArray,
                                                const uint32_t inVariableCount) const ;

  public : C_String queryStringValue (LOCATION_ARGS) const ;

//--- Build a BDD from the string returned by 'queryStringValue'
  public : static C_BDD BDDWithPredicateString (const C_String & inPredicateStringValue
                                                COMMA_LOCATION_ARGS) ;

//--- Traversing BBD (call C_bdd_value_traversing::action method for every value) 
  public : void traverseBDDvalues (C_bdd_value_traversing & inTraversing,
                                   const uint32_t inVariableCount) const ;

//--- Internal method
  private : void initLinks (void) ;

//--- Controlling nodes unique map
  public : static void setHashMapMaxSize (const uint32_t inPowerOfTwoSize) ;

//--- Controlling caches (constraints max size of cache to be < 2**inPowerOfTwo)
  public : static void setSingleOperandOperationCacheMaxSize (const uint32_t inPowerOfTwo) ;
  public : static void setANDOperationCacheMaxSize (const uint32_t inPowerOfTwo) ;

//--- Controlling information message display (by default: no display)
  public : static bool displaysInformationMessages (void) ;
  public : static void setDisplaysInformationMessages (const bool inFlag) ;

//--- Memory Usage
  public : static uint32_t currentMemoryUsage (void) ; // In MB
  public : static uint32_t maximumMemoryUsage (void) ; // In MB
  public : static void setMaximumMemoryUsage (const uint32_t inMaxMemoryUsage) ; // In MB

//--- Unmark all BDD nodes
  public : static void unmarkAllExistingBDDnodes (void) ;

//--- Marked nodes count
  public : static uint32_t getMarkedNodesCount (void) ;

//--- Get existing nodes count
  public : static uint32_t getExistingNodesCount (void) ;

//---- Suppress unused nodes
  public : static void markAndSweepUnusedNodes (void) ;

//--- Size of a node 
  public : static uint32_t getBDDnodeSize (void) ;
  public : static uint32_t getBDDinstancesCount (void) ;
  public : static uint32_t getCreatedNodesCount (void)  ;

//--- Print BDD package statistics 
  public : static void printBDDpackageOperationsSummary (AC_OutputStream & inStream) ;

//--- Free BDD data structures
  public : static void freeBDDStataStructures (void) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Abstract class for value traversing of a BDD                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class C_bdd_value_traversing {
//--- Constructor et destructor
  public : C_bdd_value_traversing (void) {}
  public : virtual ~C_bdd_value_traversing (void) {}

//--- Virtual method called for every value
  public : virtual void action (const bool tableauDesValeurs [],
                                const uint32_t inVariableCount) = 0 ;
  
//--- No instance copy
  private : C_bdd_value_traversing (const C_bdd_value_traversing &) ;
  private : C_bdd_value_traversing & operator = (const C_bdd_value_traversing &) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif

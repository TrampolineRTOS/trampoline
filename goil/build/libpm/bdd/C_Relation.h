//
//  C_Relation.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 22/05/14.
//----------------------------------------------------------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "bdd/C_BDD.h"
#include "bdd/C_RelationSingleType.h"
#include "bdd/C_RelationConfiguration.h"

//----------------------------------------------------------------------------------------------------------------------

class C_Relation {
//--- Default constructor (no variable, empty)
  public : C_Relation (void) ;

//--- Constructor (One variable, type, empty or full)
  public : C_Relation (const C_String & inVariableName,
                       const C_RelationSingleType & inVariableType,
                       const bool isFull) ;

//--- Constructor (variables, empty or full)
  public : C_Relation (const C_RelationConfiguration & inConfiguration,
                       const bool isFull) ;

//--- Private constructor (variables, eBDD)
  private : C_Relation (const C_RelationConfiguration & inConfiguration,
                        const C_BDD inBDD) ;

//--- Constructor (Variable compared with constant)
  public : C_Relation (const C_RelationConfiguration & inConfiguration,
                       const int32_t inVariableIndex,
                       const C_BDD::compareEnum inComparaison,
                       const uint64_t inConstant
                       COMMA_LOCATION_ARGS) ;

//--- Destructor
  public : virtual ~ C_Relation (void) ;

//--- Handling copy
  public : C_Relation (const C_Relation & inSource) ;
  public : C_Relation & operator = (const C_Relation & inSource) ;

//--- Add variable
  public : void addVariable (const C_String & inVariableName,
                             const C_RelationSingleType & inType) ;

  public : void appendConfiguration (const C_RelationConfiguration & inConfiguration) ;

//--- Set
  public : void setToEmpty (void) ;
  public : void setToFull (void) ;

//--- Operators
  public : inline bool isEmpty (void) const { return mBDD.isFalse () ; }
  public : inline bool isFull (void) const { return mBDD.isTrue () ; }

  public : bool operator == (const C_Relation & inRelation) const ;
  public : bool operator != (const C_Relation & inRelation) const ;

  public : void andWith (const C_Relation & inRelation COMMA_LOCATION_ARGS) ;
  public : void orWith (const C_Relation & inRelation COMMA_LOCATION_ARGS) ;
  public : C_Relation andOp (const C_Relation & inRelation COMMA_LOCATION_ARGS) const ;
  public : C_Relation orOp (const C_Relation & inRelation COMMA_LOCATION_ARGS) const ;
  public : C_Relation operator ~ (void) const ;

  public : C_Relation accessibleStatesFrom (const C_Relation & inStartStates,
                                            int32_t * outIterationCount
                                            COMMA_LOCATION_ARGS) const ;

  public : C_Relation transitiveClosure (int32_t * outIterationCount) const ;

  public : bool containsValue (const int32_t inVariableIndex,
                               const uint64_t inValue
                               COMMA_LOCATION_ARGS) const ;

  public : void getValueArray (TC_UniqueArray <uint64_t> & outArray) const ;

  public : uint64_t value64Count (void) const ;

  public : void getArray (TC_UniqueArray <TC_UniqueArray <uint64_t> > & outArray
                          COMMA_LOCATION_ARGS) const ;

  public : C_Relation relationByDeletingLastVariable (LOCATION_ARGS) const ;

  public : C_Relation exitsOnVariable (const int32_t inVariableIndex COMMA_LOCATION_ARGS) const ;

//--- Operations on 2 set relations  
  public : C_Relation transposedRelation (LOCATION_ARGS) const ;

//--- Operations on 3 set relations  
  public : C_Relation swap021 (LOCATION_ARGS) const ;

  public : C_Relation swap102 (LOCATION_ARGS) const ;

  public : C_Relation swap120 (LOCATION_ARGS) const ;

  public : C_Relation swap201 (LOCATION_ARGS) const ;

  public : C_Relation swap210 (LOCATION_ARGS) const ;

//--- Accessors
  public : inline int32_t variableCount (void) const {
    return mConfiguration.variableCount () ;
  }
  
  public : inline uint32_t bitCount (void) const {
    return mConfiguration.bitCount () ;
  }
  
  public : C_RelationConfiguration configuration (void) const ;
  public : C_BDD bdd (void) const ;
  
//--- Attributes
  private : C_RelationConfiguration mConfiguration ; 
  private : C_BDD mBDD ;
} ;

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------

class C_RelationConfiguration final {
//--- Default constructor (no variable, empty)
  public: C_RelationConfiguration (void) ;

//--- Destructor
  public: ~ C_RelationConfiguration (void) ;

//--- Handling copy
  public: C_RelationConfiguration (const C_RelationConfiguration & inSource) ;
  public: C_RelationConfiguration & operator = (const C_RelationConfiguration & inSource) ;

//--- Add variable
  public: void addVariable (const C_String & inVariableName,
                             const C_RelationSingleType & inType) ;

  public: void appendConfiguration (const C_RelationConfiguration & inConfiguration) ;

//--- Accessors
  public: int32_t variableCount (void) const ;
  public: uint32_t bitCount (void) const ;
  public: C_String nameForVariable (const int32_t inIndex COMMA_LOCATION_ARGS) const ;
  public: C_RelationSingleType typeForVariable (const int32_t inIndex COMMA_LOCATION_ARGS) const ;
  public: uint32_t constantCountForVariable (const int32_t inIndex COMMA_LOCATION_ARGS) const ;
  public: uint32_t bddStartBitIndexForVariable (const int32_t inIndex COMMA_LOCATION_ARGS) const ;
  public: uint32_t bddBitCountForVariable (const int32_t inIndex COMMA_LOCATION_ARGS) const ;
  public: C_String constantNameForVariableAndValue (const int32_t inIndex,
                                                     const uint32_t inValue
                                                     COMMA_LOCATION_ARGS) const ;
  public: void deleteVariableAtIndex (const int32_t inIndex COMMA_LOCATION_ARGS) ;
  public: void deleteLastVariable (LOCATION_ARGS) ;
  
//---
  public: void checkIdenticalTo (const C_RelationConfiguration & inConfiguration
                                  COMMA_LOCATION_ARGS) const ;

//--- Operations on 3 set configurations  
  public: C_RelationConfiguration swap021 (LOCATION_ARGS) const ;

  public: C_RelationConfiguration swap102 (LOCATION_ARGS) const ;

  public: C_RelationConfiguration swap120 (LOCATION_ARGS) const ;

  public: C_RelationConfiguration swap201 (LOCATION_ARGS) const ;

  public: C_RelationConfiguration swap210 (LOCATION_ARGS) const ;

//--- Private method
  private: void insulate (LOCATION_ARGS) ;

//--- Attributes
  private: class cVariablesInRelationConfiguration * mVariablesPtr ; 
} ;

//----------------------------------------------------------------------------------------------------------------------

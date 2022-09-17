//
//  C_RelationSingleType.h
//  galgas-developer
//
//  Created by Pierre Molinaro on 22/05/14.
//----------------------------------------------------------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "strings/C_String.h"

//----------------------------------------------------------------------------------------------------------------------

class C_RelationSingleType {
//--- Internal class
  public: class cType ;

//--- Default constructor
  public: inline C_RelationSingleType (void) : mTypePtr (NULL) {}

//--- Constructor with an enumerated type
  public: C_RelationSingleType (const C_String & inTypeName,
                                 const TC_UniqueArray <C_String> & inConstantNameArray
                                 COMMA_LOCATION_ARGS) ;

//--- Constructor with an unsigned type
  public: C_RelationSingleType (const C_String & inTypeName,
                                 const uint32_t inValueCount // [0, inValueCount - 1]
                                 COMMA_LOCATION_ARGS) ;

//--- Accessors
  public: C_String typeName (void) const ;
  public: uint32_t BDDBitCount (void) const ;
  public: uint32_t constantCount (void) const ;
  public: C_String nameForValue (const uint32_t inIndex
                                  COMMA_LOCATION_ARGS) const ;

//--- Destructor
  public: virtual ~ C_RelationSingleType (void) ;

//--- Handling copy
  public: C_RelationSingleType (const C_RelationSingleType & inSource) ;
  public: C_RelationSingleType & operator = (const C_RelationSingleType & inSource) ;

//--- Identical type ?
  public: inline bool operator == (const C_RelationSingleType & inOperand) const {
    return mTypePtr == inOperand.mTypePtr ;
  }

//--- Attribute
  private: cType * mTypePtr ;
} ;

//----------------------------------------------------------------------------------------------------------------------

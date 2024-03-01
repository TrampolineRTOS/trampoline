//--------------------------------------------------------------------------------------------------
//
//  UInt32Set : algorithms on sets of uint32_t                                                   
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2013, ..., 2023 Pierre Molinaro.
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

#pragma once

//--------------------------------------------------------------------------------------------------

#include "TC_Array.h"

//--------------------------------------------------------------------------------------------------

class UInt32Set final {
//--- Default constructor
  public: UInt32Set (void) ;

//--- Singleton
  public: UInt32Set (const uint32_t inValue) ;

//--- Methods
  public: void add (const uint32_t inNodeIndex) ;

  public: void remove (const uint32_t inNodeIndex) ;

  public: void operator &= (const UInt32Set & inOther) ;

  public: void operator |= (const UInt32Set & inOther) ;

  public: void operator -= (const UInt32Set & inOther) ;

  public: bool operator == (const UInt32Set & inOther) const ;

  public: bool operator != (const UInt32Set & inOther) const ;

//--- Accessors
  public: void getBoolValueArray (TC_UniqueArray <bool> & outBoolValueArray) const ;
  
  public: void getValueArray (TC_UniqueArray <uint32_t> & outValueArray) const ;
  
  public: bool contains (const uint32_t inNodeIndex) const ;
  
  public: uint32_t firstValueNotIsSet (void) const ;
  
  public: uint32_t count (void) const ;
  
  public: inline bool isEmpty (void) const {
    return mDefinition.count () == 0 ;
  }
  
//--- Attributes
  private: TC_Array <uint64_t> mDefinition ;


  #ifndef DO_NOT_GENERATE_CHECKINGS
    private: void check (void) const ;
  #endif
} ;

//--------------------------------------------------------------------------------------------------

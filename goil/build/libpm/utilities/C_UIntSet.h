//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  C_UIntSet : algorithms on sets of uint32_t                                                                         *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2013, ..., 2013 Pierre Molinaro.                                                                     *
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
//----------------------------------------------------------------------------------------------------------------------

#ifndef C_UINT_SET_CLASS_DEFINED
#define C_UINT_SET_CLASS_DEFINED

//----------------------------------------------------------------------------------------------------------------------

#include "collections/TC_Array.h"

//----------------------------------------------------------------------------------------------------------------------

class C_UIntSet {
//--- Default constructor
  public : C_UIntSet (void) ;

//--- Singleton
  public : C_UIntSet (const uint32_t inValue) ;

//--- Methods
  public : void add (const uint32_t inNodeIndex) ;

  public : void remove (const uint32_t inNodeIndex) ;

  public : void operator &= (const C_UIntSet & inOther) ;

  public : void operator |= (const C_UIntSet & inOther) ;

  public : void operator -= (const C_UIntSet & inOther) ;

  public : bool operator == (const C_UIntSet & inOther) const ;

  public : bool operator != (const C_UIntSet & inOther) const ;

//--- Accessors
  public : void getBoolValueArray (TC_UniqueArray <bool> & outBoolValueArray) const ;
  
  public : void getValueArray (TC_UniqueArray <uint32_t> & outValueArray) const ;
  
  public : bool contains (const uint32_t inNodeIndex) const ;
  
  public : uint32_t firstValueNotIsSet (void) const ;
  
  public : uint32_t count (void) const ;
  
  public : inline bool isEmpty (void) const {
    return mDefinition.count () == 0 ;
  }
  
//--- Attributes
  private : TC_Array <uint64_t> mDefinition ;
} ;

//----------------------------------------------------------------------------------------------------------------------

#endif

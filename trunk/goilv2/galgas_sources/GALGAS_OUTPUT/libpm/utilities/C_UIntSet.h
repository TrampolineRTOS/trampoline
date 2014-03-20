//-----------------------------------------------------------------------------*
//                                                                             *
//  C_UIntSet : algorithms on sets of PMUInt32                               *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2013, ..., 2013 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#ifndef C_UINT_SET_CLASS_DEFINED
#define C_UINT_SET_CLASS_DEFINED

//-----------------------------------------------------------------------------*

#include "collections/TC_Array.h"

//-----------------------------------------------------------------------------*

class C_UIntSet {
//--- Default constructor
  public : C_UIntSet (void) ;

//--- Singleton
  public : C_UIntSet (const PMUInt32 inValue) ;

//--- Methods
  public : void add (const PMUInt32 inNodeIndex) ;

  public : void remove (const PMUInt32 inNodeIndex) ;

  public : void operator &= (const C_UIntSet & inOther) ;

  public : void operator |= (const C_UIntSet & inOther) ;

  public : void operator -= (const C_UIntSet & inOther) ;

  public : bool operator == (const C_UIntSet & inOther) const ;

  public : bool operator != (const C_UIntSet & inOther) const ;

//--- Accessors
  public : void getBoolValueArray (TC_UniqueArray <bool> & outBoolValueArray) const ;
  
  public : void getValueArray (TC_UniqueArray <PMUInt32> & outValueArray) const ;
  
  public : bool contains (const PMUInt32 inNodeIndex) const ;
  
  public : PMUInt32 firstValueNotIsSet (void) const ;
  
  public : PMUInt32 count (void) const ;
  
  public : inline bool isEmpty (void) const {
    return mDefinition.count () == 0 ;
  }
  
//--- Attributes
  private : TC_Array <PMUInt64> mDefinition ;
} ;

//-----------------------------------------------------------------------------*

#endif

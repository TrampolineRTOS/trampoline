//-----------------------------------------------------------------------------*
//                                                                             *
//  Managing a set with BDD                                                  *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2002, ..., 2005 Pierre Molinaro.                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
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

#ifndef BDD_SET1_CLASS_DEFINED
#define BDD_SET1_CLASS_DEFINED

//-----------------------------------------------------------------------------*

#include "bdd/C_BDD.h"
#include "bdd/C_BDD_Descriptor.h"

//-----------------------------------------------------------------------------*

class C_BDD_Set2 ;
template <typename TYPE> class TC_UniqueArray ;

//-----------------------------------------------------------------------------*
//                                                                             *
//  Managing a set with BBD                                                  *
//                                                                             *
//-----------------------------------------------------------------------------*

class C_BDD_Set1 {
  private : C_BDD mBDD ;
  private : C_BDD_Descriptor mDescriptor ;

  public : inline C_BDD bdd (void) const { return mBDD ; }

//--- Constructor (build an empty set)
  public : C_BDD_Set1 (void) ;
  public : C_BDD_Set1 (const C_BDD_Descriptor & inDescriptor) ;
  public : C_BDD_Set1 (const C_BDD_Descriptor & inDescriptor,
                       const C_BDD & inBDD) ;

//--- Destructor
  public : virtual ~C_BDD_Set1 (void) ;

//--- Initialization 
  public : void init (const C_BDD::compareEnum inComparison,
                      const PMUInt32 inValue) ;

//--- Get descriptor
  public : C_BDD_Descriptor getDescriptor (void) const {
    return mDescriptor ;
  }

//--- Set operations
  public : void operator &= (const C_BDD_Set1 & inOperand) ; // Intersection
  public : void operator |= (const C_BDD_Set1 & inOperand) ; // Union

  public : C_BDD_Set1 operator & (const C_BDD_Set1 & inOperand) const ; // Intersection
  public : C_BDD_Set1 operator | (const C_BDD_Set1 & inOperand) const ; // Union
  public : C_BDD_Set1 operator ~ (void) const ; // Complement
  public : C_BDD_Set2 operator * (const C_BDD_Set1 & inOperand) const ; // Cartesian product

//--- Identical sets ?
  public : bool isEqualTo (const C_BDD_Set1 & inOperand
                           COMMA_LOCATION_ARGS) const ;

//--- Make the set empty
  public : void clear (void) ;

//--- Is the set empty ?
  public : inline bool isFalse (void) const { return mBDD.isFalse () ; }
 
//--- Values count
  public : PMUInt32 getValuesCount (void) const ;

//--- Get values array
  public : void getArray (TC_UniqueArray <bool> & outArray) const ;

//--- Friend classes
  friend class C_BDD_Set2 ;
  friend class C_BDD_Set3 ;
} ;


//----------------------------------------------------------------------------*

#endif

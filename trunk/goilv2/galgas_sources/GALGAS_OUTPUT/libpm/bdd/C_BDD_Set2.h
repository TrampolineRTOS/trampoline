//---------------------------------------------------------------------------*
//                                                                           *
//  Managing a set with BDD                                                  *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2002, ..., 2005 Pierre Molinaro.                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
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

#ifndef BDD_SET2_CLASSES_DEFINED
#define BDD_SET2_CLASSES_DEFINED

//---------------------------------------------------------------------------*

#include "bdd/C_BDD_Set1.h"

//---------------------------------------------------------------------------*

template <typename TYPE> class TC_UniqueArray ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   Implementation des ensembles a 2 dimensions             *
//                                                                           *
//---------------------------------------------------------------------------*

class C_BDD_Set2 {
  private : C_BDD mBDD ;
  private : C_BDD mMask2 ;
  private : C_BDD_Descriptor mDescriptor1 ;
  private : C_BDD_Descriptor mDescriptor2 ;

  public : inline C_BDD bdd (void) const { return mBDD ; }

//--- Constructor
  public : C_BDD_Set2 (const C_BDD_Descriptor & inDescriptor1,
                       const C_BDD_Descriptor & inDescriptor2) ;
  public : C_BDD_Set2 (const C_BDD_Descriptor & inDescriptor1,
                       const C_BDD_Descriptor & inDescriptor2,
                       const C_BDD & inBDD) ;

//--- Initialization 
  public : void init (const C_BDD::compareEnum inComparison) ;

  public : void initDimension1 (const C_BDD::compareEnum inComparison1,
                                const PMUInt32 inValue1) ;

  public : void initDimension2 (const C_BDD::compareEnum inComparison2,
                                const PMUInt32 inValue2) ;

  public : void initDimension1 (const C_BDD_Set1 & inSource COMMA_LOCATION_ARGS) ;

  public : void initDimension2 (const C_BDD_Set1 & inSource COMMA_LOCATION_ARGS) ;

//--- Identical sets ?
  public : bool isEqualTo (const C_BDD_Set2 & inOperand COMMA_LOCATION_ARGS) const ;

//--- Set operations
  public : void operator &= (const C_BDD_Set2 & inOperand) ; // Intersection
  public : void operator |= (const C_BDD_Set2 & inOperand) ; // Union

  public : C_BDD_Set2 operator & (const C_BDD_Set2 & inOperand) const ; // Intersection
  public : C_BDD_Set2 operator | (const C_BDD_Set2 & inOperand) const ; // Union
  public : C_BDD_Set2 operator ~ (void) const ; // Complement

//--- Get transposed set
  public : C_BDD_Set2 getTransposedSet (void) const ;

//--- Projection 
  public : C_BDD_Set1 projeterSurAxe1 (void) const ;
  public : C_BDD_Set1 projeterSurAxe2 (void) const ;

//--- Transitive closure
  public : C_BDD_Set2 getTransitiveClosure (PMSInt32 & outIterationsCount) const ;
  public : C_BDD_Set2 getReflexiveTransitiveClosure (PMSInt32 & outIterationsCount) const ;

//--- Accessibility
  public : C_BDD_Set1 getAccessibility (const C_BDD_Set1 & valeurInitiale,
                                        PMSInt32 & outIterationsCount) const ;  

//--- Make set empty
  public : void clear (void) ;

//--- Is the set empty ?
  public : inline bool isFalse (void) const { return mBDD.isFalse () ; }

//--- Get descriptors
  public : C_BDD_Descriptor getDescriptor1 (void) const ;
  public : C_BDD_Descriptor getDescriptor2 (void) const ;

//--- Values count
  public : PMUInt32 getValuesCount (void) const ;

//--- Get values as an array
  public : void getArray (TC_UniqueArray <TC_UniqueArray <PMSInt32> > & outArray) const ;

//--- Friend classes
  friend class C_BDD_Set3 ;
  friend class C_BDD_Set1 ;
} ;

//---------------------------------------------------------------------------*

#endif

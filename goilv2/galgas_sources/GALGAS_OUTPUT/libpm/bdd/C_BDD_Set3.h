//---------------------------------------------------------------------------*
//                                                                           *
//  Managing a set with BDD                                                  *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2001, ..., 2005 Pierre Molinaro.                           *
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

#ifndef BDD_SET3_CLASSES_DEFINED
#define BDD_SET3_CLASSES_DEFINED

//----------------------------------------------------------------------------*

#include "bdd/C_BDD_Set2.h"

//----------------------------------------------------------------------------*
//                                                                            *
//                   Implementation des ensembles a 3 dimensions              *
//                                                                            *
//----------------------------------------------------------------------------*

class C_BDD_Set3 {
  private : C_BDD mBDD ;
  private : C_BDD mMask3 ;
  private : C_BDD_Descriptor mDescriptor1 ;
  private : C_BDD_Descriptor mDescriptor2 ;
  private : C_BDD_Descriptor mDescriptor3 ;

  public : inline C_BDD bdd (void) const { return mBDD ; }
  
//--- Constructor
  public : C_BDD_Set3 (const C_BDD_Descriptor & inDescriptor1,
                       const C_BDD_Descriptor & inDescriptor2,
                       const C_BDD_Descriptor & inDescriptor3) ;
  public : C_BDD_Set3 (const C_BDD_Descriptor & inDescriptor1,
                       const C_BDD_Descriptor & inDescriptor2,
                       const C_BDD_Descriptor & inDescriptor3,
                       const C_BDD & inBDD) ;

//--- Initialization 
  public : void initDimension1 (const C_BDD::compareEnum inComparison1,
                                const PMUInt32 inValue1) ;

  public : void initDimension2 (const C_BDD::compareEnum inComparison2,
                                const PMUInt32 inValue2) ;

  public : void initDimension3 (const C_BDD::compareEnum inComparison3,
                                const PMUInt32 inValue3) ;

  public : void initDimension1 (const C_BDD_Set1 & inSource) ;

  public : void initDimension2 (const C_BDD_Set1 & inSource) ;

  public : void initDimension3 (const C_BDD_Set1 & inSource) ;

  public : void initDimension13 (const C_BDD_Set2 & inSource) ;

  public : void initDimension32 (const C_BDD_Set2 & inSource) ;

  public : void initDimension31 (const C_BDD_Set2 & inSource) ;

//--- Identical sets ?
  public : bool isEqualTo (const C_BDD_Set3 & inOperand) const ;

//--- Sets operations
  public : void operator &= (const C_BDD_Set3 & inOperand) ; // Intersection
  public : void operator |= (const C_BDD_Set3 & inOperand) ; // Union

  public : C_BDD_Set3 operator & (const C_BDD_Set3 & inOperand) const ; // Intersection
  public : C_BDD_Set3 operator | (const C_BDD_Set3 & inOperand) const ; // Union
  public : C_BDD_Set3 operator ~ (void) const ; // Complement

//--- Get transposed set
  public : void swap132 (void) ;
  public : void swap231 (void) ;
  public : void swap213 (void) ;
  public : void swap321 (void) ;
  public : void swap312 (void) ;

//--- Projections 
  public : C_BDD_Set2 projeterSurAxe12 (void) const ;
  public : C_BDD_Set1 projeterSurAxe1 (void) const ;

//--- Make the set empty
  public : void clear (void) ;

//--- Is set empty ?
  public : inline bool isFalse (void) const { return mBDD.isFalse () ; }

//--- Values count
  public : PMUInt32 getValuesCount (void) const ;

//--- Print BDD nodes
 public : void printBDDnodes (C_Display_BDD & tableauDesNoms) ;

//--- Affichage
  public : void traverseBDDvalues (C_bdd_value_traversing & inTraversing) const ;
} ;

//----------------------------------------------------------------------------*

#endif

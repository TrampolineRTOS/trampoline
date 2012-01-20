//---------------------------------------------------------------------------*
//                                                                           *
//  Managing a set with BDD                                                  *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2002, ..., 2010 Pierre Molinaro.                           *
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

#include "bdd/C_BDD_Set1.h"
#include "bdd/C_BDD_Set2.h"
#include "utilities/MF_Assert.h"

//----------------------------------------------------------------------------*
//                                                                            *
//    Constructor (build an empty set)                                        *
//                                                                            *
//----------------------------------------------------------------------------*

C_BDD_Set1::C_BDD_Set1 (void) :
mBDD (),
mDescriptor (C_BDD_Descriptor (0)) {
}

//----------------------------------------------------------------------------*

C_BDD_Set1::C_BDD_Set1 (const C_BDD_Descriptor & inDescriptor) :
mBDD (),
mDescriptor (inDescriptor) {
}

//----------------------------------------------------------------------------*

C_BDD_Set1::C_BDD_Set1 (const C_BDD_Descriptor & inDescriptor,
                        const C_BDD & inBDD) :
mBDD (inBDD),
mDescriptor (inDescriptor) {
}

//----------------------------------------------------------------------------*
//                                                                            *
//    Destructor                                                              *
//                                                                            *
//----------------------------------------------------------------------------*

C_BDD_Set1::~C_BDD_Set1 (void) {
}

//----------------------------------------------------------------------------*

void C_BDD_Set1::init (const C_BDD::compareEnum inComparisonKind,
                       const PMUInt32 inValue) {
  MF_Assert (inValue <= mDescriptor.getMaxValue (),
            "inValue (%lld) > maxValue (%lld)",
            (PMSInt32) inValue,
            (PMSInt32) mDescriptor.getMaxValue ()) ;
  mBDD = C_BDD::varCompareConst (0,
                                 mDescriptor.getBDDbitsSize (),
                                 inComparisonKind,
                                 inValue) ;
  mBDD &= mDescriptor.getMask () ;
}

//----------------------------------------------------------------------------*

bool C_BDD_Set1::isEqualTo (const C_BDD_Set1 & inOperand COMMA_LOCATION_ARGS) const {
  MF_AssertThere (mDescriptor.getMaxValue () == inOperand.mDescriptor.getMaxValue (),
                  "Invalid BDD set (max value : %ld, expected : %ld)",
                  (PMSInt32) inOperand.mDescriptor.getMaxValue (),
                  (PMSInt32) mDescriptor.getMaxValue ()) ;
  return mBDD.isEqualToBDD (inOperand.mBDD) ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set1::clear (void) {
  mBDD.setToFalse () ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set1::operator &= (const C_BDD_Set1 & inOperand) {
  MF_Assert (mDescriptor.getMaxValue () <= inOperand.mDescriptor.getMaxValue (),
            "inValue (%lld) != maxValue (%lld)",
            (PMSInt32) mDescriptor.getMaxValue (),
            (PMSInt32) inOperand.mDescriptor.getMaxValue ()) ;
  mBDD &= inOperand.mBDD ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set1::operator |= (const C_BDD_Set1 & inOperand) {
  MF_Assert (mDescriptor.getMaxValue () <= inOperand.mDescriptor.getMaxValue (),
            "inValue (%lld) != maxValue (%lld)",
            (PMSInt32) mDescriptor.getMaxValue (),
            (PMSInt32) inOperand.mDescriptor.getMaxValue ()) ;
  mBDD |= inOperand.mBDD ;
}

//----------------------------------------------------------------------------*

C_BDD_Set1 C_BDD_Set1::operator & (const C_BDD_Set1 & inOperand) const {
  MF_Assert (mDescriptor.getMaxValue () <= inOperand.mDescriptor.getMaxValue (),
            "inValue (%lld) != maxValue (%lld)",
            (PMSInt32) mDescriptor.getMaxValue (),
            (PMSInt32) inOperand.mDescriptor.getMaxValue ()) ;
  C_BDD_Set1 r = *this ;
  r &= inOperand ;
  return r ;
}

//----------------------------------------------------------------------------*

C_BDD_Set1 C_BDD_Set1::operator | (const C_BDD_Set1 & inOperand) const {
  MF_Assert (mDescriptor.getMaxValue () <= inOperand.mDescriptor.getMaxValue (),
            "inValue (%lld) != maxValue (%lld)",
            (PMSInt32) mDescriptor.getMaxValue (),
            (PMSInt32) inOperand.mDescriptor.getMaxValue ()) ;
  C_BDD_Set1 r = *this ;
  r |= inOperand ;
  return r ;
}

//----------------------------------------------------------------------------*

C_BDD_Set1 C_BDD_Set1::operator ~ (void) const {
  C_BDD_Set1 r = *this ;
  r.mBDD.negate () ;
  r.mBDD &= mDescriptor.getMask () ;
  return r ;
}

//----------------------------------------------------------------------------*

C_BDD_Set2 C_BDD_Set1::operator * (const C_BDD_Set1 & inOperand) const {
  C_BDD_Set2 r (mDescriptor, inOperand.mDescriptor) ;
  r.initDimension2 (inOperand COMMA_HERE) ;
  r.mBDD &= mBDD ;
  return r ;
}

//----------------------------------------------------------------------------*

PMUInt32 C_BDD_Set1::getValuesCount (void) const {
  return (PMUInt32) (mBDD.valueCount (mDescriptor.getBDDbitsSize ()) & PMUINT32_MAX) ;
}

//---------------------------------------------------------------------------*

class cBuildArrayForSet1 : public C_bdd_value_traversing {
//--- Attributs
  protected : TC_UniqueArray <bool> & mArray ;

//--- Constructeur
  public : cBuildArrayForSet1 (TC_UniqueArray <bool> & outArray) ;

//--- Methode virtuelle appelee pour chaque valeur
  public : virtual void action (const bool inValuesArray [],
                                const PMUInt16 inBDDbitsSize) ;
} ;
  
//---------------------------------------------------------------------------*

cBuildArrayForSet1::
cBuildArrayForSet1 (TC_UniqueArray <bool> & outArray) :
mArray (outArray) {
}

//---------------------------------------------------------------------------*

void cBuildArrayForSet1::
action (const bool inValuesArray [],
        const PMUInt16 inBDDbitsSize) {
  PMSInt32 element = 0L ;
  for (PMSInt32 i=inBDDbitsSize - 1 ; i>=0 ; i--) {
    element = (element << 1) + inValuesArray [i] ;
  }
  mArray (element COMMA_HERE) = true ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set1::
getArray (TC_UniqueArray <bool> & outArray) const {
  { const PMSInt32 size = ((PMSInt32) mDescriptor.getMaxValue ()) + 1 ;
    TC_UniqueArray <bool> temp (size, false COMMA_HERE) ;
    swap (temp, outArray) ;
  }
  cBuildArrayForSet1 s (outArray) ;
  mBDD.traverseBDDvalues (s, mDescriptor.getBDDbitsSize ()) ;
}

//----------------------------------------------------------------------------*

//-----------------------------------------------------------------------------*
//                                                                             *
//     C++ functions for using BDD package implemented in 'C_BDD.cpp'        *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2002, ..., 2010 Pierre Molinaro.                             *
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

#include "bdd/C_BDD_Set3.h"
#include "utilities/MF_Assert.h"

//----------------------------------------------------------------------------*
//                                                                            *
//                   Implementation des ensembles a 3 dimensions              *
//                                                                            *
//----------------------------------------------------------------------------*

C_BDD_Set3::
C_BDD_Set3 (const C_BDD_Descriptor & inDescriptor1,
            const C_BDD_Descriptor & inDescriptor2,
            const C_BDD_Descriptor & inDescriptor3) :
mBDD (),
mMask3 (),
mDescriptor1 (inDescriptor1),
mDescriptor2 (inDescriptor2),
mDescriptor3 (inDescriptor3) {
  mMask3 = inDescriptor1.getMask () ;
  mMask3 &= C_BDD::varCompareConst (inDescriptor1.getBDDbitsSize (),
                                    inDescriptor2.getBDDbitsSize (),
                                    C_BDD::kLowerOrEqual,
                                    inDescriptor2.getMaxValue ()) ;
  mMask3 &= C_BDD::varCompareConst ((PMUInt32) (inDescriptor1.getBDDbitsSize ()
                                            + inDescriptor2.getBDDbitsSize ()),
                                    inDescriptor3.getBDDbitsSize (),
                                    C_BDD::kLowerOrEqual,
                                    inDescriptor3.getMaxValue ()) ;
}

//----------------------------------------------------------------------------*

C_BDD_Set3::
C_BDD_Set3 (const C_BDD_Descriptor & inDescriptor1,
            const C_BDD_Descriptor & inDescriptor2,
            const C_BDD_Descriptor & inDescriptor3,
            const C_BDD & inBDD) :
mBDD (inBDD),
mMask3 (),
mDescriptor1 (inDescriptor1),
mDescriptor2 (inDescriptor2),
mDescriptor3 (inDescriptor3) {
  mMask3 = inDescriptor1.getMask () ;
  mMask3 &= C_BDD::varCompareConst (inDescriptor1.getBDDbitsSize (),
                                    inDescriptor2.getBDDbitsSize (),
                                    C_BDD::kLowerOrEqual,
                                    inDescriptor2.getMaxValue ()) ;
  mMask3 &= C_BDD::varCompareConst ((PMUInt32) (inDescriptor1.getBDDbitsSize ()
                                            + inDescriptor2.getBDDbitsSize ()),
                                    inDescriptor3.getBDDbitsSize (),
                                    C_BDD::kLowerOrEqual,
                                    inDescriptor3.getMaxValue ()) ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::clear (void) {
  mBDD.setToFalse () ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::
initDimension1 (const C_BDD::compareEnum inComparison1,
                const PMUInt32 inValue1) {
  mBDD = C_BDD::varCompareConst (0,
                                 mDescriptor1.getBDDbitsSize (),
                                 inComparison1,
                                 inValue1) ;
  mBDD &= mMask3 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::
initDimension2 (const C_BDD::compareEnum inComparison2,
                const PMUInt32 inValue2) {
  mBDD = C_BDD::varCompareConst (mDescriptor1.getBDDbitsSize (),
                                 mDescriptor2.getBDDbitsSize (),
                                 inComparison2,
                                 inValue2) ;
  mBDD &= mMask3 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::
initDimension3 (const C_BDD::compareEnum inComparison3,
                const PMUInt32 inValue3) {
  mBDD = C_BDD::varCompareConst ((PMUInt32) (mDescriptor1.getBDDbitsSize ()
                                         + mDescriptor2.getBDDbitsSize ()),
                                 mDescriptor3.getBDDbitsSize (),
                                 inComparison3,
                                 inValue3) ;
  mBDD &= mMask3 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::initDimension1 (const C_BDD_Set1 & inSource) {
  mBDD = inSource.mBDD ;
  mBDD &= mMask3 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::initDimension2 (const C_BDD_Set1 & inSource) {
  PMUInt32 * tab = NULL ;
  macroMyNewArray (tab, PMUInt32, mDescriptor2.getBDDbitsSize ()) ;
  for (PMUInt32 i=0 ; i<mDescriptor2.getBDDbitsSize () ; i++) {
    tab [i] = (PMUInt32) (i + mDescriptor1.getBDDbitsSize ()) ;
  }
  mBDD = inSource.mBDD.substitution (tab, mDescriptor2.getBDDbitsSize () COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  mBDD &= mMask3 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::initDimension3 (const C_BDD_Set1 & inSource) {
  PMUInt32 * tab = NULL ;
  macroMyNewArray (tab, PMUInt32, mDescriptor3.getBDDbitsSize ()) ;
  for (PMUInt32 i=0 ; i<mDescriptor3.getBDDbitsSize () ; i++) {
    tab [i] = (PMUInt32) (i + mDescriptor1.getBDDbitsSize () + mDescriptor2.getBDDbitsSize ()) ;
  }
  mBDD = inSource.mBDD.substitution (tab, mDescriptor3.getBDDbitsSize () COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  mBDD &= mMask3 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::operator &= (const C_BDD_Set3 & inOperand) {
  mBDD &= inOperand.mBDD ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::operator |= (const C_BDD_Set3 & inOperand) {
  mBDD |= inOperand.mBDD ;
}

//----------------------------------------------------------------------------*

C_BDD_Set3 C_BDD_Set3::operator & (const C_BDD_Set3 & inOperand) const {
  C_BDD_Set3 r = *this ;
  r &= inOperand ;
  return r ;
}

//----------------------------------------------------------------------------*

C_BDD_Set3 C_BDD_Set3::operator | (const C_BDD_Set3 & inOperand) const {
  C_BDD_Set3 r = *this ;
  r |= inOperand ;
  return r ;
}

//----------------------------------------------------------------------------*

C_BDD_Set3 C_BDD_Set3::operator ~ (void) const {
  C_BDD_Set3 r = *this ;
  r.mBDD.negate () ;
  r.mBDD &= r.mMask3 ;
  return r ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::initDimension13 (const C_BDD_Set2 & inSource) {
  const PMUInt32 totalSize = (PMUInt32) (mDescriptor1.getBDDbitsSize () + mDescriptor3.getBDDbitsSize ()) ;
  PMUInt32 * tab = NULL ;
  macroMyNewArray (tab, PMUInt32, totalSize) ;
  for (PMUInt32 i=0 ; i<mDescriptor1.getBDDbitsSize () ; i++) {
    tab [i] = i ;
  }
  for (PMUInt32 j=0 ; j<mDescriptor3.getBDDbitsSize () ; j++) {
    tab [j + mDescriptor1.getBDDbitsSize ()] = (PMUInt32) (j + mDescriptor1.getBDDbitsSize () + mDescriptor2.getBDDbitsSize ()) ;
  }
  mBDD = inSource.mBDD.substitution (tab, totalSize COMMA_HERE) ;
  mBDD &= mMask3 ;
  macroMyDeleteArray (tab) ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::initDimension32 (const C_BDD_Set2 & inSource) {
  const PMUInt32 totalSize = (PMUInt32) (mDescriptor3.getBDDbitsSize () + mDescriptor2.getBDDbitsSize ()) ;
  PMUInt32 * tab = NULL ;
  macroMyNewArray (tab, PMUInt32, totalSize) ;
  for (PMUInt32 i=0 ; i<mDescriptor3.getBDDbitsSize () ; i++) {
    tab [i] = (PMUInt32) (i + mDescriptor1.getBDDbitsSize () + mDescriptor2.getBDDbitsSize ()) ;
  }
  for (PMUInt32 j=0 ; j<mDescriptor2.getBDDbitsSize () ; j++) {
    tab [j + mDescriptor3.getBDDbitsSize ()] = (PMUInt32) (j + mDescriptor1.getBDDbitsSize ()) ;
  }
  mBDD = inSource.mBDD.substitution (tab, totalSize COMMA_HERE) ;
  mBDD &= mMask3 ;
  macroMyDeleteArray (tab) ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::initDimension31 (const C_BDD_Set2 & inSource) {
  const PMUInt32 size1 = mDescriptor1.getBDDbitsSize () ;
  const PMUInt32 size2 = mDescriptor2.getBDDbitsSize () ;
  const PMUInt32 size3 = mDescriptor3.getBDDbitsSize () ;
  const PMUInt32 totalSize = (PMUInt32) (size3 + size1) ;
  PMUInt32 * tab = NULL ;
  macroMyNewArray (tab, PMUInt32, totalSize) ;
  for (PMUInt32 i=0 ; i<size3 ; i++) {
    tab [i] = (PMUInt32) (i + size1 + size2) ;
  }
  for (PMUInt32 j=0 ; j<size1 ; j++) {
    tab [j + size3] = (PMUInt32) (j + size3) ;
  }
  mBDD = inSource.mBDD.substitution (tab, totalSize COMMA_HERE) ;
  mBDD &= mMask3 ;
  macroMyDeleteArray (tab) ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::swap132 (void) {
  const PMUInt32 size1 = mDescriptor1.getBDDbitsSize () ;
  const PMUInt32 size2 = mDescriptor2.getBDDbitsSize () ;
  const PMUInt32 size3 = mDescriptor3.getBDDbitsSize () ;
  const PMUInt32 totalSize = (PMUInt32) (size1 + size2 + size3) ;
  PMUInt32 * tab = NULL ;
  macroMyNewArray (tab, PMUInt32, totalSize) ;
  for (PMUInt32 i=0 ; i<size1 ; i++) {
    tab [i] = i ;
  }
  for (PMUInt32 j=0 ; j<size2 ; j++) {
    tab [j + size1] = (PMUInt32) (j + size1 + size3) ;
  }
  for (PMUInt32 k=0 ; k<size3 ; k++) {
    tab [k + size1 + size2] = (PMUInt32) (k + size1) ;
  }
  mBDD = mBDD.substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  mBDD &= mMask3 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::swap231 (void) {
  const PMUInt32 size1 = mDescriptor1.getBDDbitsSize () ;
  const PMUInt32 size2 = mDescriptor2.getBDDbitsSize () ;
  const PMUInt32 size3 = mDescriptor3.getBDDbitsSize () ;
  const PMUInt32 totalSize = (PMUInt32) (size1 + size2 + size3) ;
  PMUInt32 * tab = NULL ;
  macroMyNewArray (tab, PMUInt32, totalSize) ;
  for (PMUInt32 i=0 ; i<size1 ; i++) {
    tab [i] = (PMUInt32) (i + size1 + size2) ;
  }
  for (PMUInt32 j=0 ; j<size2 ; j++) {
    tab [j + size1] = j ;
  }
  for (PMUInt32 k=0 ; k<size3 ; k++) {
    tab [k + size1 + size2] = (PMUInt32) (k + size2) ;
  }
  mBDD = mBDD.substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  mBDD &= mMask3 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::swap213 (void) {
  const PMUInt32 size1 = mDescriptor1.getBDDbitsSize () ;
  const PMUInt32 size2 = mDescriptor2.getBDDbitsSize () ;
  const PMUInt32 size3 = mDescriptor3.getBDDbitsSize () ;
  const PMUInt32 totalSize = (PMUInt32) (size1 + size2 + size3) ;
  PMUInt32 * tab = NULL ;
  macroMyNewArray (tab, PMUInt32, totalSize) ;
  for (PMUInt32 i=0 ; i<size1 ; i++) {
    tab [i] = (PMUInt32) (i + size2) ;
  }
  for (PMUInt32 j=0 ; j<size2 ; j++) {
    tab [j + size1] = j ;
  }
  for (PMUInt32 k=0 ; k<size3 ; k++) {
    tab [k + size1 + size2] = (PMUInt32) (k + size1 + size2) ;
  }
  mBDD = mBDD.substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  mBDD &= mMask3 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::swap321 (void) {
  const PMUInt32 size1 = mDescriptor1.getBDDbitsSize () ;
  const PMUInt32 size2 = mDescriptor2.getBDDbitsSize () ;
  const PMUInt32 size3 = mDescriptor3.getBDDbitsSize () ;
  const PMUInt32 totalSize = (PMUInt32) (size1 + size2 + size3) ;
  PMUInt32 * tab = NULL ;
  macroMyNewArray (tab, PMUInt32, totalSize) ;
  for (PMUInt32 i=0 ; i<size1 ; i++) {
    tab [i] = (PMUInt32) (i + size1 + size2) ;
  }
  for (PMUInt32 j=0 ; j<size2 ; j++) {
    tab [j + size1] = (PMUInt32) (j + size3) ;
  }
  for (PMUInt32 k=0 ; k<size3 ; k++) {
    tab [k + size1 + size2] = k ;
  }
  mBDD = mBDD.substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  mBDD &= mMask3 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set3::swap312 (void) {
  const PMUInt32 size1 = mDescriptor1.getBDDbitsSize () ;
  const PMUInt32 size2 = mDescriptor2.getBDDbitsSize () ;
  const PMUInt32 size3 = mDescriptor3.getBDDbitsSize () ;
  const PMUInt32 totalSize = (PMUInt32) (size1 + size2 + size3) ;
  PMUInt32 * tab = NULL ;
  macroMyNewArray (tab, PMUInt32, totalSize) ;
  for (PMUInt32 i=0 ; i<size1 ; i++) {
    tab [i] = (PMUInt32) (i + size3) ;
  }
  for (PMUInt32 j=0 ; j<size2 ; j++) {
    tab [j + size1] = (PMUInt32) (j + size1 + size3) ;
  }
  for (PMUInt32 k=0 ; k<size3 ; k++) {
    tab [k + size1 + size2] = k ;
  }
  mBDD = mBDD.substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  mBDD &= mMask3 ;
}

//----------------------------------------------------------------------------*

C_BDD_Set2 C_BDD_Set3::projeterSurAxe12 (void) const {
  C_BDD_Set2 r (mDescriptor1, mDescriptor1) ;
  r.mBDD = mBDD.existsOnBitsAfterNumber ((PMUInt32) (mDescriptor1.getBDDbitsSize ()
                                                 + mDescriptor2.getBDDbitsSize ())) ;
  return r ;
}

//----------------------------------------------------------------------------*

C_BDD_Set1 C_BDD_Set3::projeterSurAxe1 (void) const {
  C_BDD_Set1 r (mDescriptor1) ;
  r.mBDD = mBDD.existsOnBitsAfterNumber (mDescriptor1.getBDDbitsSize ()) ;
  return r ;
}

//----------------------------------------------------------------------------*

PMUInt32 C_BDD_Set3::getValuesCount (void) const {
  return (PMUInt32) (mBDD.valueCount64 ((PMUInt32) (mDescriptor1.getBDDbitsSize ()
                                                  + mDescriptor2.getBDDbitsSize ()
                                                  + mDescriptor3.getBDDbitsSize ())) & PMUINT32_MAX) ;
}

//----------------------------------------------------------------------------*

bool C_BDD_Set3::isEqualTo (const C_BDD_Set3 & inOperand) const {
  return mBDD.isEqualToBDD (inOperand.mBDD) ;
}

//----------------------------------------------------------------------------*

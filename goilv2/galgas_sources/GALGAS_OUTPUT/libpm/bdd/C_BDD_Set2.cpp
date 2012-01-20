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

#include "bdd/C_BDD_Set2.h"
#include "bdd/C_BDD_Set3.h"
#include "utilities/MF_Assert.h"
#include "utilities/TF_Swap.h"

//---------------------------------------------------------------------------*
//                                                                           *
//                   Implementation des ensembles a 2 dimensions             *
//                                                                           *
//---------------------------------------------------------------------------*

C_BDD_Set2::
C_BDD_Set2 (const C_BDD_Descriptor & inDescriptor1,
            const C_BDD_Descriptor & inDescriptor2) :
mBDD (),
mMask2 (),
mDescriptor1 (inDescriptor1),
mDescriptor2 (inDescriptor2) {
  mMask2 = inDescriptor1.getMask () ;
  mMask2 &= C_BDD::varCompareConst (inDescriptor1.getBDDbitsSize (),
                                    inDescriptor2.getBDDbitsSize (),
                                    C_BDD::kLowerOrEqual,
                                    inDescriptor2.getMaxValue ()) ;
}

//---------------------------------------------------------------------------*

C_BDD_Set2::
C_BDD_Set2 (const C_BDD_Descriptor & inDescriptor1,
            const C_BDD_Descriptor & inDescriptor2,
            const C_BDD & inBDD) :
mBDD (inBDD),
mMask2 (),
mDescriptor1 (inDescriptor1),
mDescriptor2 (inDescriptor2) {
  mMask2 = inDescriptor1.getMask () ;
  mMask2 &= C_BDD::varCompareConst (inDescriptor1.getBDDbitsSize (),
                                    inDescriptor2.getBDDbitsSize (),
                                    C_BDD::kLowerOrEqual,
                                    inDescriptor2.getMaxValue ()) ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set2::clear (void) {
  mBDD.setToFalse () ;
}

//----------------------------------------------------------------------------*

C_BDD_Descriptor C_BDD_Set2::getDescriptor1 (void) const {
  return mDescriptor1 ;
}

//----------------------------------------------------------------------------*

C_BDD_Descriptor C_BDD_Set2::getDescriptor2 (void) const {
  return mDescriptor2 ;
}

//----------------------------------------------------------------------------*

bool C_BDD_Set2::isEqualTo (const C_BDD_Set2 & inOperand COMMA_LOCATION_ARGS) const {
  MF_AssertThere (mDescriptor1.getMaxValue () == inOperand.mDescriptor1.getMaxValue (),
                  "Invalid BDD set (max value 1 : %ld, expected : %ld)",
                  (PMSInt32) inOperand.mDescriptor1.getMaxValue (),
                  (PMSInt32) mDescriptor1.getMaxValue ()) ;
  MF_AssertThere (mDescriptor2.getMaxValue () == inOperand.mDescriptor2.getMaxValue (),
                  "Invalid BDD set (max value 2 : %ld, expected : %ld)",
                  (PMSInt32) inOperand.mDescriptor2.getMaxValue (),
                  (PMSInt32) mDescriptor2.getMaxValue ()) ;
  return mBDD.isEqualToBDD (inOperand.mBDD) ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set2::
init (const C_BDD::compareEnum inComparison) {
  mBDD = C_BDD::varCompareVar (0,
                               mDescriptor1.getBDDbitsSize (),
                               inComparison,
                               mDescriptor1.getBDDbitsSize ()) ;
  mBDD &= mMask2 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set2::
initDimension1 (const C_BDD_Set1 & inSource COMMA_LOCATION_ARGS) {
  MF_AssertThere (mDescriptor1.getMaxValue () == inSource.mDescriptor.getMaxValue (),
                  "Invalid BDD set (max value : %ld, expected : %ld)",
                  (PMSInt32) inSource.mDescriptor.getMaxValue (),
                  (PMSInt32) mDescriptor1.getMaxValue ()) ;
  mBDD = inSource.mBDD ;
  mBDD &= mMask2 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set2::
initDimension2 (const C_BDD_Set1 & inSource COMMA_LOCATION_ARGS) {
  MF_AssertThere (mDescriptor2.getMaxValue () == inSource.mDescriptor.getMaxValue (),
                  "Invalid BDD set (max value : %ld, expected : %ld)",
                  (PMSInt32) inSource.mDescriptor.getMaxValue (),
                  (PMSInt32) mDescriptor2.getMaxValue ()) ;
  const PMUInt16 size = mDescriptor2.getBDDbitsSize () ;
  PMUInt16 * tab = NULL ;
  macroMyNewArray (tab, PMUInt16, size) ;
  for (PMUInt16 i=0 ; i<size ; i++) {
    tab [i] = (PMUInt16) (i + mDescriptor1.getBDDbitsSize ()) ;
  }
  mBDD = inSource.mBDD.substitution (tab, size COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  mBDD &= mMask2 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set2::
initDimension1 (const C_BDD::compareEnum inComparison1,
                const PMUInt32 inValue1) {
  mBDD = C_BDD::varCompareConst (0,
                                 mDescriptor1.getBDDbitsSize (),
                                 inComparison1,
                                 inValue1) ;
  mBDD &= mMask2 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set2::
initDimension2 (const C_BDD::compareEnum inComparison2,
                const PMUInt32 inValue2) {
  mBDD = C_BDD::varCompareConst (mDescriptor1.getBDDbitsSize (),
                                 mDescriptor2.getBDDbitsSize (),
                                 inComparison2,
                                 inValue2) ;
  mBDD &= mMask2 ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set2::operator &= (const C_BDD_Set2 & inOperand) {
  mBDD &= inOperand.mBDD ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set2::operator |= (const C_BDD_Set2 & inOperand) {
  mBDD |= inOperand.mBDD ;
}

//----------------------------------------------------------------------------*

C_BDD_Set2 C_BDD_Set2::operator & (const C_BDD_Set2 & inOperand) const {
  C_BDD_Set2 r = *this ;
  r &= inOperand ;
  return r ;
}

//----------------------------------------------------------------------------*

C_BDD_Set2 C_BDD_Set2::operator | (const C_BDD_Set2 & inOperand) const {
  C_BDD_Set2 r = *this ;
  r |= inOperand ;
  return r ;
}

//----------------------------------------------------------------------------*

C_BDD_Set2 C_BDD_Set2::operator ~ (void) const {
  C_BDD_Set2 r = *this ;
  r.mBDD.negate () ;
  r.mBDD &= mDescriptor1.getMask () ;
  r.mBDD &= mDescriptor2.getMask () ;
  return r ;
}

//----------------------------------------------------------------------------*

C_BDD_Set2 C_BDD_Set2::getTransposedSet (void) const {
  C_BDD_Set2 r (mDescriptor2, mDescriptor1) ;
  const PMUInt16 bitSize1 = mDescriptor1.getBDDbitsSize () ;
  const PMUInt16 bitSize2 = mDescriptor2.getBDDbitsSize () ;
  const PMUInt16 totalSize = (PMUInt16) (bitSize1 + bitSize2) ;
  PMUInt16 * tab = NULL ;
  macroMyNewArray (tab, PMUInt16, totalSize) ;
  for (PMUInt16 i=0 ; i<bitSize1 ; i++) {
    tab [i] = (PMUInt16) (i + bitSize2) ;
  }
  for (PMUInt16 j=0 ; j<bitSize2 ; j++) {
    tab [j + bitSize1] = j ;
  }
  r.mBDD = mBDD.substitution (tab, totalSize COMMA_HERE) ;
  macroMyDeleteArray (tab) ;
  return r ;
}

//----------------------------------------------------------------------------*

C_BDD_Set1 C_BDD_Set2::projeterSurAxe1 (void) const {
  C_BDD_Set1 r (mDescriptor1) ;
  r.mBDD = mBDD.existsOnBitsAfterNumber (mDescriptor1.getBDDbitsSize ()) ;
  return r ;
}

//----------------------------------------------------------------------------*

C_BDD_Set1 C_BDD_Set2::projeterSurAxe2 (void) const {
  return getTransposedSet ().projeterSurAxe1 () ;
}

//----------------------------------------------------------------------------*

C_BDD_Set2 C_BDD_Set2::getTransitiveClosure (PMSInt32 & outIterationsCount) const {
  MF_Assert (mDescriptor1.getMaxValue () == mDescriptor2.getMaxValue (),
            "Invalid BDD set (max value : %lld, expected : %lld)",
            (PMSInt32) mDescriptor2.getMaxValue (),
            (PMSInt32) mDescriptor1.getMaxValue ()) ;
  C_BDD_Set2 closure (mDescriptor1, mDescriptor1) ;
//--- La fermeture transitive se calcule ainsi :
// #closure [x, y] += #relationAccessibilite [x, y] | ?z (#closure [x, z] & #closure [z, y]) ;

  C_BDD_Set3 XZclosure (mDescriptor1, mDescriptor1, mDescriptor1) ;
  C_BDD_Set3 ZYclosure (mDescriptor1, mDescriptor1, mDescriptor1) ;
  C_BDD_Set2 v (mDescriptor1, mDescriptor1) ;
  outIterationsCount = 0 ;
  
  do{
    v = closure ;
    outIterationsCount ++ ;
    XZclosure.initDimension13 (v) ;
    ZYclosure.initDimension32 (v) ;
    closure = *this ;
    closure |= (XZclosure & ZYclosure).projeterSurAxe12 () ;
  }while (! closure.isEqualTo (v COMMA_HERE)) ;

  return closure ;
}

//----------------------------------------------------------------------------*

C_BDD_Set2 C_BDD_Set2::getReflexiveTransitiveClosure (PMSInt32 & outIterationsCount) const {
  C_BDD_Set2 e = *this ; 
  e.init (C_BDD::kEqual) ;
  return getTransitiveClosure (outIterationsCount) | e ;
}

//----------------------------------------------------------------------------*

C_BDD_Set1 C_BDD_Set2::getAccessibility (const C_BDD_Set1 & inInitialValue,
                                         PMSInt32 & outIterationsCount) const {  
// etatInitial represente #etatInitial [nt:nombreBitsEtat] ;
// relationAccessibilite represente #RelationAccessibilite [ntg:nombreBitsEtat, ntd:nombreBitsEtat] ;

// L'accessibilite est calculee par :
// #partieAccessible [nt:nombreBitsEtat]
//         += #etatInitial [nt] | ? x:nombreBitsEtat (#partieAccessible [x] & #RelationAccessibilite [x, nt])

//--- Transposition de la relation d'accessibilite
  const C_BDD_Set2 accessibiliteTransposee = getTransposedSet () ;
  
  C_BDD_Set1 partieAccessible = inInitialValue ;
  C_BDD_Set1 v (mDescriptor1) ;
  C_BDD_Set2 tempo (mDescriptor1, mDescriptor1) ;
  outIterationsCount = 0 ;
  
  do{
    outIterationsCount ++ ;
    v = partieAccessible ;
    tempo.initDimension2 (v COMMA_HERE) ;
    partieAccessible = inInitialValue | ((tempo & accessibiliteTransposee).projeterSurAxe1 ()) ;
  }while (! partieAccessible.isEqualTo (v COMMA_HERE)) ;

  return partieAccessible ;
}

//----------------------------------------------------------------------------*

PMUInt32 C_BDD_Set2::getValuesCount (void) const {
  return (PMUInt32) (mBDD.valueCount ((PMUInt16) (mDescriptor1.getBDDbitsSize () + mDescriptor2.getBDDbitsSize ())) & PMUINT32_MAX) ;
}

//---------------------------------------------------------------------------*

class cBuildArrayForSet2 : public C_bdd_value_traversing {
//--- Attributs
  protected : TC_UniqueArray <TC_UniqueArray <PMSInt32> > & mArray ;
  protected : PMUInt16 mBitsSize1 ;

//--- Constructeur
  public : cBuildArrayForSet2 (TC_UniqueArray <TC_UniqueArray <PMSInt32> > & outArray,
                               const PMUInt16 inBitsSize1) ;

//--- Methode virtelle appelee pour chaque valeur
  public : virtual void action (const bool inValuesArray [],
                                const PMUInt16 inBDDbitsSize) ;
} ;
  
//---------------------------------------------------------------------------*

cBuildArrayForSet2::
cBuildArrayForSet2 (TC_UniqueArray <TC_UniqueArray <PMSInt32> > & outArray,
                    const PMUInt16 inBitsSize1) :
mArray (outArray),
mBitsSize1 (inBitsSize1) {
}

//---------------------------------------------------------------------------*

void cBuildArrayForSet2::
action (const bool inValuesArray [],
        const PMUInt16 inBDDbitsSize) {
  PMSInt32 index1 = 0L ;
  PMSInt32 index2 = 0L ;
  for (PMSInt32 i=mBitsSize1 - 1 ; i>=0 ; i--) {
    index1 = (index1 << 1) + inValuesArray [i] ;
  }
  for (PMSInt32 j=inBDDbitsSize - 1 ; j>=mBitsSize1 ; j--) {
    index2 = (index2 << 1) + inValuesArray [j] ;
  }
  mArray (index1 COMMA_HERE).addObject (index2) ;
}

//----------------------------------------------------------------------------*

void C_BDD_Set2::getArray (TC_UniqueArray <TC_UniqueArray <PMSInt32> > & outArray) const {
  const PMSInt32 size1 = ((PMSInt32) mDescriptor1.getMaxValue ()) + 1 ;
  { TC_UniqueArray <TC_UniqueArray <PMSInt32> > temp (size1 COMMA_HERE) ;
    for (PMSInt32 i=0 ; i<size1 ; i++) {
      temp.addDefaultObjectUsingSwap () ;
    }
    swap (temp, outArray) ;
  }
  cBuildArrayForSet2 s (outArray, mDescriptor1.getBDDbitsSize ()) ;
  mBDD.traverseBDDvalues (s, (PMUInt16) (mDescriptor1.getBDDbitsSize () + mDescriptor2.getBDDbitsSize ())) ;
}

//----------------------------------------------------------------------------*

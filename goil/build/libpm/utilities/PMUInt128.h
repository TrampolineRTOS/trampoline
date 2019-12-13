//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  Handing unsigned integer of arbitrary size                                                                         *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2012, ..., 2012 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@ec-nantes.fr                                                                              *
//                                                                                                                     *
//  LS2N, Laboratoire des Sciences du Numérique de Nantes, ECN, École Centrale de Nantes (France)                      *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#pragma once

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "strings/C_String.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class PMUInt128 {
//--- Constructors
  public : PMUInt128 (void) ;
  public : PMUInt128 (const uint64_t inValue) ;

//--- Destructor
  public : virtual ~ PMUInt128 (void) ;

//--- Is Zero
  public : bool isZero (void) const ;

//--- Comparison
  public : bool operator == (const PMUInt128 & inValue) const ;
  public : bool operator != (const PMUInt128 & inValue) const ;
  public : bool operator > (const uint32_t inOperand) const ;

//--- Incrementation, decrementation
  public : PMUInt128 & operator ++ (void) ;
  public : PMUInt128 & operator -- (void) ;
  
//--- Addition
  public : void operator += (const PMUInt128 & inValue) ;
  public : PMUInt128 operator + (const PMUInt128 & inValue) const ;

//--- Multiplication
  public : void operator *= (const uint32_t inMultiplicand) ;

//--- Division
  public : void divideBy (const uint32_t inDivisor,
                          uint32_t & outRemainder) ;
  public : void operator /= (const uint32_t inMultiplicand) ;

//--- Bit access
  public : bool valueAtBitIndex (const uint32_t inIndex) const ;
  public : void setValueAtBitIndex (const bool inValue, const uint32_t inIndex) ;

//--- Value access
  public : inline uint64_t low  (void) const { return mLow ; }
  public : inline uint64_t high (void) const { return mHigh ; }

//--- Example
  public : static void example (void) ;
  
//--- Value as string
  public : C_String decimalString (void) const ;

//--- Attributes
  private : uint64_t mLow ;
  private : uint64_t mHigh ;
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

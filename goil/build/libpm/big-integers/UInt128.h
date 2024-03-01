//--------------------------------------------------------------------------------------------------
//
//  Handling 128-bits unsigned integer                                                   
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2012, ..., 2023 Pierre Molinaro.
//                                           
//  MIT License
//                                           
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//                                           
//--------------------------------------------------------------------------------------------------

#pragma once

//--------------------------------------------------------------------------------------------------

#include "String-class.h"

//--------------------------------------------------------------------------------------------------

class UInt128 final {
//--- Constructors
  public: UInt128 (void) ;
  public: UInt128 (const uint64_t inLow) ;
  public: UInt128 (const uint64_t inHigh, const uint64_t inLow) ;

//--- Is Zero
  public: bool isZero (void) const ;

//--- Comparison
  public: bool operator == (const UInt128 & inValue) const ;
  public: bool operator != (const UInt128 & inValue) const ;
  public: bool operator > (const uint32_t inOperand) const ;

//--- Incrementation, decrementation
  public: UInt128 & operator ++ (void) ;
  public: UInt128 & operator -- (void) ;
  
//--- Addition
  public: void operator += (const UInt128 & inValue) ;
  public: UInt128 operator + (const UInt128 & inValue) const ;

//--- Multiplication
  public: void operator *= (const uint32_t inMultiplicand) ;

//--- Division
  public: void divideBy (const uint32_t inDivisor,
                         uint32_t & outRemainder) ;

  public: void operator /= (const uint32_t inMultiplicand) ;

//--- Bit access
  public: bool bitAtIndex (const uint32_t inIndex) const ;
  public: void setBitAtIndex (const bool inValue, const uint32_t inIndex) ;

//--- Value access
  public: inline uint64_t low  (void) const { return mLow ; }
  public: inline uint64_t high (void) const { return mHigh ; }

//--- Example
  public: static void example (void) ;
  
//--- Value as string
  public: String decimalString (void) const ;

//--- Attributes
  private: uint64_t mLow ;
  private: uint64_t mHigh ;
} ;

//--------------------------------------------------------------------------------------------------

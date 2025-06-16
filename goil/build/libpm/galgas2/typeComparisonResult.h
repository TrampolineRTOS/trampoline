//--------------------------------------------------------------------------------------------------
//
//  Types for comparison results                                                                 
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2010, ..., 2011 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//--------------------------------------------------------------------------------------------------

#pragma once

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  class typeComparisonResult {
    private: typedef enum {
      kPrivateOperandNotValid,
      kPrivateFirstOperandLowerThanSecond,
      kPrivateOperandEqual,
      kPrivateFirstOperandGreaterThanSecond
    } enumComparisonResult ;
  //--- Attribute
    private: enumComparisonResult mComparisonResult ;
  //--- Private constructor
    private: typeComparisonResult (const enumComparisonResult inComparisonResult) ;
  //--- Constructor (static methods)
    public: static typeComparisonResult operandNotValid (void) ;
    public: static typeComparisonResult firstOperandLowerThanSecond (void) ;
    public: static typeComparisonResult operandEqual (void) ;
    public: static typeComparisonResult firstOperandGreaterThanSecond (void) ;
  //--- Comparison operators
    public: bool operator == (const typeComparisonResult & inOperand) const ;
    public: bool operator != (const typeComparisonResult & inOperand) const ;
    public: bool operator >= (const typeComparisonResult & inOperand) const ;
    public: bool operator >  (const typeComparisonResult & inOperand) const ;
    public: bool operator <= (const typeComparisonResult & inOperand) const ;
    public: bool operator <  (const typeComparisonResult & inOperand) const ;
  } ;
  #define kOperandNotValid               typeComparisonResult::operandNotValid ()
  #define kFirstOperandLowerThanSecond   typeComparisonResult::firstOperandLowerThanSecond ()
  #define kOperandEqual                  typeComparisonResult::operandEqual ()
  #define kFirstOperandGreaterThanSecond typeComparisonResult::firstOperandGreaterThanSecond ()
#else
  typedef enum {
    kOperandNotValid,
    kFirstOperandLowerThanSecond,
    kOperandEqual,
    kFirstOperandGreaterThanSecond
  } typeComparisonResult ;
#endif

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  class typeComparisonKind {
    private: typedef enum {
      kPrivateIsEqual,
      kPrivateIsNotEqual,
      kPrivateIsSupOrEqual,
      kPrivateIsInfOrEqual,
      kPrivateIsStrictSup,
      kPrivateIsStrictInf
    } enumComparisonKind ;
  //--- Attribute
    private: enumComparisonKind mComparisonKind ;
  //--- Private constructor
    private: typeComparisonKind (const enumComparisonKind inComparisonKind) ;
  //--- Constructor (static methods)
    public: static typeComparisonKind isEqual (void) ;
    public: static typeComparisonKind isNotEqual (void) ;
    public: static typeComparisonKind isSupOrEqual (void) ;
    public: static typeComparisonKind isInfOrEqual (void) ;
    public: static typeComparisonKind isStrictSup (void) ;
    public: static typeComparisonKind isStrictInf (void) ;
  //--- Friend
    friend bool boolValueFromComparisonKindAndComparisonResult (const typeComparisonKind inComparisonKind,
                                                                const typeComparisonResult inComparisonResult) ;

  } ;
  #define kIsEqual      typeComparisonKind::isEqual ()
  #define kIsNotEqual   typeComparisonKind::isNotEqual ()
  #define kIsSupOrEqual typeComparisonKind::isSupOrEqual ()
  #define kIsInfOrEqual typeComparisonKind::isInfOrEqual ()
  #define kIsStrictSup  typeComparisonKind::isStrictSup ()
  #define kIsStrictInf  typeComparisonKind::isStrictInf ()
#else
  typedef enum {
    kIsEqual,
    kIsNotEqual,
    kIsSupOrEqual,
    kIsInfOrEqual,
    kIsStrictSup,
    kIsStrictInf
  } typeComparisonKind ;
#endif

//--------------------------------------------------------------------------------------------------

bool boolValueFromComparisonKindAndComparisonResult (const typeComparisonKind inComparisonKind,
                                                     const typeComparisonResult inComparisonResult) ;

//--------------------------------------------------------------------------------------------------
//
//    typeEnumerationOrder                                                                       
//
//--------------------------------------------------------------------------------------------------

typedef enum {
  kENUMERATION_DOWN,
  kENUMERATION_UP
} typeEnumerationOrder ;

//--------------------------------------------------------------------------------------------------

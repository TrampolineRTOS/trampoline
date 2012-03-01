//---------------------------------------------------------------------------*
//                                                                           *
//  Types for comparison results                                             *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2010, ..., 2011 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
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

#ifndef COMPARISON_RESULT_ENUMERATION_DEFINED
#define COMPARISON_RESULT_ENUMERATION_DEFINED

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  class typeComparisonResult {
    private : typedef enum {
      kPrivateOperandNotValid,
      kPrivateFirstOperandLowerThanSecond,
      kPrivateOperandEqual,
      kPrivateFirstOperandGreaterThanSecond
    } enumComparisonResult ;
  //--- Attribute
    private : enumComparisonResult mComparisonResult ;
  //--- Private constructor
    private : typeComparisonResult (const enumComparisonResult inComparisonResult) ;
  //--- Constructor (static methods)
    public : static typeComparisonResult operandNotValid (void) ;
    public : static typeComparisonResult firstOperandLowerThanSecond (void) ;
    public : static typeComparisonResult operandEqual (void) ;
    public : static typeComparisonResult firstOperandGreaterThanSecond (void) ;
  //--- Comparison operators
    public : bool operator == (const typeComparisonResult & inOperand) const ;
    public : bool operator != (const typeComparisonResult & inOperand) const ;
    public : bool operator >= (const typeComparisonResult & inOperand) const ;
    public : bool operator >  (const typeComparisonResult & inOperand) const ;
    public : bool operator <= (const typeComparisonResult & inOperand) const ;
    public : bool operator <  (const typeComparisonResult & inOperand) const ;
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

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  class typeComparisonKind {
    private : typedef enum {
      kPrivateIsEqual,
      kPrivateIsNotEqual,
      kPrivateIsSupOrEqual,
      kPrivateIsInfOrEqual,
      kPrivateIsStrictSup,
      kPrivateIsStrictInf
    } enumComparisonKind ;
  //--- Attribute
    private : enumComparisonKind mComparisonKind ;
  //--- Private constructor
    private : typeComparisonKind (const enumComparisonKind inComparisonKind) ;
  //--- Constructor (static methods)
    public : static typeComparisonKind isEqual (void) ;
    public : static typeComparisonKind isNotEqual (void) ;
    public : static typeComparisonKind isSupOrEqual (void) ;
    public : static typeComparisonKind isInfOrEqual (void) ;
    public : static typeComparisonKind isStrictSup (void) ;
    public : static typeComparisonKind isStrictInf (void) ;
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

//---------------------------------------------------------------------------*

bool boolValueFromComparisonKindAndComparisonResult (const typeComparisonKind inComparisonKind,
                                                     const typeComparisonResult inComparisonResult) ;

//---------------------------------------------------------------------------*
//                                                                           *
//    typeEnumerationOrder                                                   *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  class typeEnumerationOrder {
    public : typedef enum {
      kInternalEnumeration_down,
      kInternalEnumeration_up,
      kInternalEnumeration_enterOrder,
      kInternalEnumeration_reverseEnterOrder
    } enumEnumerationOrder ;
  //--- Attribute
    public : enumEnumerationOrder mEnumerationOrder ;
  //--- Private constructor
    private : typeEnumerationOrder (const enumEnumerationOrder inEnumerationOrder) ;
  //--- Constructor (static methods)
    public : static typeEnumerationOrder down (void) ;
    public : static typeEnumerationOrder up (void) ;
    public : static typeEnumerationOrder enterOrder (void) ;
    public : static typeEnumerationOrder reverseEnterOrder (void) ;
  } ;

  #define kEnumeration_down              typeEnumerationOrder::down ()
  #define kEnumeration_up                typeEnumerationOrder::up ()
  #define kEnumeration_enterOrder        typeEnumerationOrder::enterOrder ()
  #define kEnumeration_reverseEnterOrder typeEnumerationOrder::reverseEnterOrder ()

  #define kENUMERATION_DOWN                typeEnumerationOrder::kInternalEnumeration_down
  #define kENUMERATION_UP                  typeEnumerationOrder::kInternalEnumeration_up
  #define kENUMERATION_ENTER_ORDER         typeEnumerationOrder::kInternalEnumeration_enterOrder
  #define kENUMERATION_REVERSE_ENTER_ORDER typeEnumerationOrder::kInternalEnumeration_reverseEnterOrder
  
  inline typeEnumerationOrder::enumEnumerationOrder enumerationOrderValue (const typeEnumerationOrder inEnumerationOrder) {
    return inEnumerationOrder.mEnumerationOrder ;
  }
#else
  typedef enum {
    kEnumeration_down,
    kEnumeration_up,
    kEnumeration_enterOrder,
    kEnumeration_reverseEnterOrder
  } typeEnumerationOrder ;
  
  #define enumerationOrderValue(x) (x)
  #define kENUMERATION_DOWN                kEnumeration_down
  #define kENUMERATION_UP                  kEnumeration_up
  #define kENUMERATION_ENTER_ORDER         kEnumeration_enterOrder
  #define kENUMERATION_REVERSE_ENTER_ORDER kEnumeration_reverseEnterOrder
#endif

//---------------------------------------------------------------------------*

#endif

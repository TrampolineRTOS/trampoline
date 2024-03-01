//----------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/typeComparisonResult.h"

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  typeComparisonResult::typeComparisonResult (const enumComparisonResult inComparisonResult) :
  mComparisonResult (inComparisonResult) {
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  typeComparisonResult typeComparisonResult::operandNotValid (void) {
    return typeComparisonResult (kPrivateOperandNotValid) ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  typeComparisonResult typeComparisonResult::firstOperandLowerThanSecond (void) {
    return typeComparisonResult (kPrivateFirstOperandLowerThanSecond) ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  typeComparisonResult typeComparisonResult::operandEqual (void) {
    return typeComparisonResult (kPrivateOperandEqual) ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  typeComparisonResult typeComparisonResult::firstOperandGreaterThanSecond (void) {
    return typeComparisonResult (kPrivateFirstOperandGreaterThanSecond) ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  bool typeComparisonResult::operator == (const typeComparisonResult & inOperand) const {
    return mComparisonResult == inOperand.mComparisonResult ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  bool typeComparisonResult::operator != (const typeComparisonResult & inOperand) const {
    return mComparisonResult != inOperand.mComparisonResult ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  bool typeComparisonResult::operator <= (const typeComparisonResult & inOperand) const {
    return mComparisonResult <= inOperand.mComparisonResult ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  bool typeComparisonResult::operator >= (const typeComparisonResult & inOperand) const {
    return mComparisonResult >= inOperand.mComparisonResult ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  bool typeComparisonResult::operator < (const typeComparisonResult & inOperand) const {
    return mComparisonResult < inOperand.mComparisonResult ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  bool typeComparisonResult::operator > (const typeComparisonResult & inOperand) const {
    return mComparisonResult > inOperand.mComparisonResult ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------
//
//     typeComparisonKind                              
//
//----------------------------------------------------------------------------------------------------------------------

#ifdef DO_NOT_GENERATE_CHECKINGS
  bool boolValueFromComparisonKindAndComparisonResult (const typeComparisonKind inComparisonKind,
                                                       const typeComparisonResult inComparisonResult) {
    bool result = false ;
    if (kOperandNotValid != inComparisonResult) {
      switch (inComparisonKind) {
      case kIsEqual      : result = inComparisonResult == kOperandEqual ; break ;
      case kIsNotEqual   : result = inComparisonResult != kOperandEqual ; break ;
      case kIsSupOrEqual : result = inComparisonResult >= kOperandEqual ; break ;
      case kIsInfOrEqual : result = inComparisonResult <= kOperandEqual ; break ;
      case kIsStrictSup  : result = inComparisonResult >  kOperandEqual ; break ;
      case kIsStrictInf  : result = inComparisonResult <  kOperandEqual ; break ;
      }
    }
    return result ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  bool boolValueFromComparisonKindAndComparisonResult (const typeComparisonKind inComparisonKind,
                                                       const typeComparisonResult inComparisonResult) {
    bool result = false ;
    if (kOperandNotValid != inComparisonResult) {
      switch (inComparisonKind.mComparisonKind) {
      case typeComparisonKind::kPrivateIsEqual      : result = inComparisonResult == kOperandEqual ; break ;
      case typeComparisonKind::kPrivateIsNotEqual   : result = inComparisonResult != kOperandEqual ; break ;
      case typeComparisonKind::kPrivateIsSupOrEqual : result = inComparisonResult >= kOperandEqual ; break ;
      case typeComparisonKind::kPrivateIsInfOrEqual : result = inComparisonResult <= kOperandEqual ; break ;
      case typeComparisonKind::kPrivateIsStrictSup  : result = inComparisonResult >  kOperandEqual ; break ;
      case typeComparisonKind::kPrivateIsStrictInf  : result = inComparisonResult <  kOperandEqual ; break ;
      }
    }
    return result ;
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  typeComparisonKind::typeComparisonKind (const enumComparisonKind inComparisonKind) :
  mComparisonKind (inComparisonKind) {
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  typeComparisonKind typeComparisonKind::isEqual (void) {
    return typeComparisonKind (kPrivateIsEqual) ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  typeComparisonKind typeComparisonKind::isNotEqual (void) {
    return typeComparisonKind (kPrivateIsNotEqual) ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  typeComparisonKind typeComparisonKind::isSupOrEqual (void) {
    return typeComparisonKind (kPrivateIsSupOrEqual) ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  typeComparisonKind typeComparisonKind::isInfOrEqual (void) {
    return typeComparisonKind (kPrivateIsInfOrEqual) ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  typeComparisonKind typeComparisonKind::isStrictSup (void) {
    return typeComparisonKind (kPrivateIsStrictSup) ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  typeComparisonKind typeComparisonKind::isStrictInf (void) {
    return typeComparisonKind (kPrivateIsStrictInf) ; 
  }
#endif

//----------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//  GALGAS_function : this class implements introspection for GALGAS functions
//
//  This file is part of libpm library
//
//  Copyright (C) 2002, ..., 2011 Pierre Molinaro.
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

#include "all-predefined-types.h"
#include "C_galgas_function_descriptor.h"
#include "C_galgas_type_descriptor.h"
#include "Compiler.h"
#include "cObjectArray.h"

//--------------------------------------------------------------------------------------------------
//
//                     'GALGAS_function' class
//
//--------------------------------------------------------------------------------------------------

GALGAS_function::GALGAS_function (void) :
AC_GALGAS_root (),
mFunctionDescriptor (nullptr) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_function::GALGAS_function (const C_galgas_function_descriptor * inFunctionDescriptor) :
AC_GALGAS_root (),
mFunctionDescriptor (inFunctionDescriptor) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_function::GALGAS_function (const GALGAS_function & inSource) :
AC_GALGAS_root (),
mFunctionDescriptor (inSource.mFunctionDescriptor) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_function & GALGAS_function::operator = (const GALGAS_function & inSource) {
  mFunctionDescriptor = inSource.mFunctionDescriptor ;
  return * this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_function::~ GALGAS_function (void) {
}

//--------------------------------------------------------------------------------------------------

void GALGAS_function::description (String & ioString,
                                   const int32_t /* inIndentation */) const {
  ioString.appendCString ("<@function:") ;
  if (nullptr == mFunctionDescriptor) {
    ioString.appendCString ("not built") ;
  }else{
    ioString.appendString (mFunctionDescriptor->mFunctionName) ;
    ioString.appendCString (" [") ;
    for (uint32_t i=0 ; i<mFunctionDescriptor->mParameterCount ; i++) {
      if (i > 0) {
        ioString.appendCString (" ") ;
      }
      ioString.appendCString ("?@") ;
      ioString.appendString (mFunctionDescriptor->mFormalParameterTypeList [i]->mGalgasTypeName) ;
    }
    ioString.appendCString ("] -> @") ;
    ioString.appendString (mFunctionDescriptor->mResultType->mGalgasTypeName) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_functionlist GALGAS_function::class_func_functionList (LOCATION_ARGS) {
  GALGAS_functionlist result = GALGAS_functionlist::class_func_emptyList (THERE) ;
  const C_galgas_function_descriptor * p = C_galgas_function_descriptor::functionListRoot () ;
  while (nullptr != p) {
    result.addAssign_operation (GALGAS_function (p) COMMA_HERE) ;
    p = p->mNextFunction ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_function::class_func_isFunctionDefined (const GALGAS_string & inFunctionName
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (inFunctionName.isValid ()) {
    bool resultValue = false ;
    const String functionName = inFunctionName.stringValue () ;
    const C_galgas_function_descriptor * p = C_galgas_function_descriptor::functionListRoot () ;
    while ((nullptr != p) && ! resultValue) {
      resultValue = functionName == p->mFunctionName ;
      p = p->mNextFunction ;
    }
    result = GALGAS_bool (resultValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_function GALGAS_function::class_func_functionWithName (const GALGAS_string & inFunctionName
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_function result ;
  if (inFunctionName.isValid ()) {
    const String functionName = inFunctionName.stringValue () ;
    const C_galgas_function_descriptor * p = C_galgas_function_descriptor::functionListRoot () ;
    while ((nullptr != p) && ! result.isValid ()) {
      if (functionName == p->mFunctionName) {
        result = GALGAS_function (p) ;
      }
      p = p->mNextFunction ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typelist GALGAS_function::getter_formalParameterTypeList (LOCATION_ARGS) const {
  GALGAS_typelist result = GALGAS_typelist::class_func_emptyList (THERE) ;
  for (uint32_t i=0 ; i<mFunctionDescriptor->mParameterCount ; i++) {
    result.addAssign_operation (GALGAS_type (mFunctionDescriptor->mFormalParameterTypeList [i]) COMMA_HERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_function::getter_name (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mFunctionDescriptor->mFunctionName) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_type GALGAS_function::getter_resultType (UNUSED_LOCATION_ARGS) const {
  return GALGAS_type (mFunctionDescriptor->mResultType) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_object GALGAS_function::getter_invoke (const GALGAS_objectlist & inObjectList,
                                              const GALGAS_location & inErrorLocation,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  const cObjectArray argumentsArray (inObjectList, inCompiler COMMA_THERE) ;
//--- Check parameter count
  bool ok = mFunctionDescriptor->mParameterCount == argumentsArray.count () ;
  if (! ok) {
    String errorMessage ;
    errorMessage.appendCString ("the '") ;
    errorMessage.appendString (mFunctionDescriptor->mFunctionName) ;
    errorMessage.appendCString ("' function is called with ") ;
    errorMessage.appendUnsigned (argumentsArray.count ()) ;
    errorMessage.appendCString (" actual parameter") ;
    errorMessage.appendString ((argumentsArray.count () > 1) ? "s" : "") ;
    errorMessage.appendCString (", but its header requires ") ;
    errorMessage.appendUnsigned (mFunctionDescriptor->mParameterCount) ;
    inCompiler->semanticErrorAtLocation (inErrorLocation, errorMessage, TC_Array <C_FixItDescription> () COMMA_THERE) ;
  }
//--- Check parameters
  for (uint32_t i=0 ; (i<mFunctionDescriptor->mParameterCount) && ok ; i++) {
    const GALGAS_object parameter = argumentsArray.objectAtIndex (i COMMA_HERE) ;
    ok = parameter.isValid () ;
    if (ok) {
      const C_galgas_type_descriptor * t = parameter.getter_objectStaticType (HERE).typeValue () ;
      ok = t == mFunctionDescriptor->mFormalParameterTypeList [i] ;
      while ((! ok) && (nullptr != t->mSuperclassDescriptor)) {
        t = t->mSuperclassDescriptor ;
        ok = t == mFunctionDescriptor->mFormalParameterTypeList [i] ;
      }
      if (! ok) {
        String errorMessage ;
        errorMessage.appendCString ("the actual parameter #") ;
        errorMessage.appendUnsigned (i) ;
        errorMessage.appendCString (" of the '") ;
        errorMessage.appendString (mFunctionDescriptor->mFunctionName) ;
        errorMessage.appendCString ("' function call has the '@") ;
        errorMessage.appendString (parameter.staticTypeDescriptor ()->mGalgasTypeName) ;
        errorMessage.appendCString ("', but the function header requires an instance of '@") ;
        errorMessage.appendString (mFunctionDescriptor->mFormalParameterTypeList [i]->mGalgasTypeName) ;
        errorMessage.appendCString ("'") ;
        inCompiler->semanticErrorAtLocation (inErrorLocation, errorMessage, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
    }
  }
//--- Invoke function
  GALGAS_object result ;
  if (ok) {
    result = mFunctionDescriptor->mFunctionPointer (inCompiler, argumentsArray, inErrorLocation COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_function::objectCompare (const GALGAS_function & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const ptrdiff_t diff = mFunctionDescriptor - inOperand.mFunctionDescriptor ;
    if (diff < 0) {
      result = kFirstOperandLowerThanSecond ;
    }else if (diff > 0) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

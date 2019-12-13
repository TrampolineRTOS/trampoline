//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  GALGAS_function : this class implements introspection for GALGAS functions                                         *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2002, ..., 2011 Pierre Molinaro.                                                                     *
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

#include "all-predefined-types.h"
#include "galgas2/C_galgas_function_descriptor.h"
#include "galgas2/C_galgas_type_descriptor.h"
#include "galgas2/C_Compiler.h"
#include "galgas2/cObjectArray.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                     'GALGAS_function' class                                                                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_function::GALGAS_function (void) :
AC_GALGAS_root (),
mFunctionDescriptor (NULL) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_function::GALGAS_function (const C_galgas_function_descriptor * inFunctionDescriptor) :
AC_GALGAS_root (),
mFunctionDescriptor (inFunctionDescriptor) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_function::GALGAS_function (const GALGAS_function & inSource) :
AC_GALGAS_root (),
mFunctionDescriptor (inSource.mFunctionDescriptor) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_function & GALGAS_function::operator = (const GALGAS_function & inSource) {
  mFunctionDescriptor = inSource.mFunctionDescriptor ;
  return * this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_function::~ GALGAS_function (void) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void GALGAS_function::description (C_String & ioString,
                                   const int32_t /* inIndentation */) const {
  ioString << "<@function:" ;
  if (NULL == mFunctionDescriptor) {
    ioString << "not built" ;
  }else{
    ioString << mFunctionDescriptor->mFunctionName << " [" ;
    for (uint32_t i=0 ; i<mFunctionDescriptor->mParameterCount ; i++) {
      if (i > 0) {
        ioString << " " ;
      }
      ioString << "?@" << mFunctionDescriptor->mFormalParameterTypeList [i]->mGalgasTypeName ;
    }
    ioString << "] -> @" << mFunctionDescriptor->mResultType->mGalgasTypeName ;
  }
  ioString << ">" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_functionlist GALGAS_function::constructor_functionList (LOCATION_ARGS) {
  GALGAS_functionlist result = GALGAS_functionlist::constructor_emptyList (THERE) ;
  const C_galgas_function_descriptor * p = C_galgas_function_descriptor::functionListRoot () ;
  while (NULL != p) {
    result.addAssign_operation (GALGAS_function (p) COMMA_HERE) ;
    p = p->mNextFunction ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_bool GALGAS_function::constructor_isFunctionDefined (const GALGAS_string & inFunctionName
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (inFunctionName.isValid ()) {
    bool resultValue = false ;
    const C_String functionName = inFunctionName.stringValue () ;
    const C_galgas_function_descriptor * p = C_galgas_function_descriptor::functionListRoot () ;
    while ((NULL != p) && ! resultValue) {
      resultValue = functionName == p->mFunctionName ;
      p = p->mNextFunction ;
    }
    result = GALGAS_bool (resultValue) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_function GALGAS_function::constructor_functionWithName (const GALGAS_string & inFunctionName
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_function result ;
  if (inFunctionName.isValid ()) {
    const C_String functionName = inFunctionName.stringValue () ;
    const C_galgas_function_descriptor * p = C_galgas_function_descriptor::functionListRoot () ;
    while ((NULL != p) && ! result.isValid ()) {
      if (functionName == p->mFunctionName) {
        result = GALGAS_function (p) ;
      }
      p = p->mNextFunction ;
    }
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_typelist GALGAS_function::getter_formalParameterTypeList (LOCATION_ARGS) const {
  GALGAS_typelist result = GALGAS_typelist::constructor_emptyList (THERE) ;
  for (uint32_t i=0 ; i<mFunctionDescriptor->mParameterCount ; i++) {
    result.addAssign_operation (GALGAS_type (mFunctionDescriptor->mFormalParameterTypeList [i]) COMMA_HERE) ;
  }
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_string GALGAS_function::getter_name (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mFunctionDescriptor->mFunctionName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_type GALGAS_function::getter_resultType (UNUSED_LOCATION_ARGS) const {
  return GALGAS_type (mFunctionDescriptor->mResultType) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

GALGAS_object GALGAS_function::getter_invoke (const GALGAS_objectlist & inObjectList,
                                              const GALGAS_location & inErrorLocation,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  const cObjectArray argumentsArray (inObjectList, inCompiler COMMA_THERE) ;
//--- Check parameter count
  bool ok = mFunctionDescriptor->mParameterCount == argumentsArray.count () ;
  if (! ok) {
    C_String errorMessage ;
    errorMessage << "the '" << mFunctionDescriptor->mFunctionName << "' function is called with " 
                 << cStringWithUnsigned (argumentsArray.count ())
                 << " actual parameter"
                 << ((argumentsArray.count () > 1) ? "s" : "")
                 << ", but its header requires "
                 << cStringWithUnsigned (mFunctionDescriptor->mParameterCount) ;
    inCompiler->semanticErrorAtLocation (inErrorLocation, errorMessage, TC_Array <C_FixItDescription> () COMMA_THERE) ;
  }
//--- Check parameters
  for (uint32_t i=0 ; (i<mFunctionDescriptor->mParameterCount) && ok ; i++) {
    const GALGAS_object parameter = argumentsArray.objectAtIndex (i COMMA_HERE) ;
    ok = parameter.isValid () ;
    if (ok) {
      const C_galgas_type_descriptor * t = parameter.getter_objectStaticType (HERE).typeValue () ;
      ok = t == mFunctionDescriptor->mFormalParameterTypeList [i] ;
      while ((! ok) && (NULL != t->mSuperclassDescriptor)) {
        t = t->mSuperclassDescriptor ;
        ok = t == mFunctionDescriptor->mFormalParameterTypeList [i] ;
      }
      if (! ok) {
        C_String errorMessage ;
        errorMessage << "the actual parameter #"
                     << cStringWithUnsigned (i)
                     << " of the '" << mFunctionDescriptor->mFunctionName << "' function call has the '@"
                     << parameter.staticTypeDescriptor ()->mGalgasTypeName
                     << "', but the function header requires an instance of '@"
                     << mFunctionDescriptor->mFormalParameterTypeList [i]->mGalgasTypeName
                     << "'" ;
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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

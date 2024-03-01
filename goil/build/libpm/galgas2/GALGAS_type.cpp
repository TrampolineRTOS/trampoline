//--------------------------------------------------------------------------------------------------
//
//  GALGAS_bool : this class implements introspection for GALGAS types
//
//  This file is part of libpm library
//
//  Copyright (C) 2009, ..., 2023 Pierre Molinaro.
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
#include "Compiler.h"

//--------------------------------------------------------------------------------------------------
//
//                     'GALGAS_type' class
//
//--------------------------------------------------------------------------------------------------

GALGAS_type::GALGAS_type (void) :
AC_GALGAS_root (),
mTypeDescriptor (nullptr) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_type::GALGAS_type (const C_galgas_type_descriptor * inTypeReference) :
AC_GALGAS_root (),
mTypeDescriptor (inTypeReference) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_type::GALGAS_type (const GALGAS_type & inSource) :
AC_GALGAS_root (),
mTypeDescriptor (inSource.mTypeDescriptor) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_type & GALGAS_type::operator = (const GALGAS_type & inSource) {
  mTypeDescriptor = inSource.mTypeDescriptor ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_type::~ GALGAS_type (void) {
}

//--------------------------------------------------------------------------------------------------

void GALGAS_type::description (String & ioString,
                               const int32_t /* inIndentation */) const {
  ioString.appendCString ("<@type: ") ;
  if (nullptr == mTypeDescriptor) {
    ioString.appendCString ("not built") ;
  }else{
    ioString.appendCString ("@") ;
    ioString.appendString (mTypeDescriptor->mGalgasTypeName) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typelist GALGAS_type::class_func_typeList (LOCATION_ARGS) {
  TC_UniqueArray <C_galgas_type_descriptor *> typeList ;
  C_galgas_type_descriptor::typeListRoot (typeList) ;
  GALGAS_typelist result = GALGAS_typelist::class_func_emptyList (THERE) ;
  for (int32_t i=0 ; i<typeList.count () ; i++) {
    result.addAssign_operation (GALGAS_type (typeList (i COMMA_THERE)) COMMA_HERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_type::getter_name (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mTypeDescriptor->mGalgasTypeName) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_type::getter_hasSuperclass (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (nullptr != mTypeDescriptor->mSuperclassDescriptor) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_type GALGAS_type::getter_superclass (Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  GALGAS_type result ;
  if (mTypeDescriptor != nullptr) {
    if (nullptr == mTypeDescriptor->mSuperclassDescriptor) {
      String s = "'superclass' reader invoked on class type value '@" ;
      s.appendString (mTypeDescriptor->mGalgasTypeName) ;
      s.appendCString ("', without super class") ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      result = GALGAS_type (mTypeDescriptor->mSuperclassDescriptor) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_type::objectCompare (const GALGAS_type & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const ptrdiff_t diff = mTypeDescriptor - inOperand.mTypeDescriptor ;
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

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  GALGAS_bool : this class implements introspection for GALGAS types         *
//                                                                                                                     *
//  This file is part of libpm library                                         *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2009 Pierre Molinaro.                             *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes                                          *
//  ECN, École Centrale de Nantes (France)                                                                             *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it                                            *
//  under the terms of the GNU Lesser General Public License as published                                              *
//  by the Free Software Foundation; either version 2 of the License, or                                               *
//  (at your option) any later version.                                                                                *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT                                             *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or                                              *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for                                           *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"
#include "galgas2/C_Compiler.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     'GALGAS_type' class                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type::GALGAS_type (void) :
AC_GALGAS_root (),
mTypeDescriptor (NULL) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type::GALGAS_type (const C_galgas_type_descriptor * inTypeReference) :
AC_GALGAS_root (),
mTypeDescriptor (inTypeReference) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type::GALGAS_type (const GALGAS_type & inSource) :
AC_GALGAS_root (),
mTypeDescriptor (inSource.mTypeDescriptor) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type & GALGAS_type::operator = (const GALGAS_type & inSource) {
  mTypeDescriptor = inSource.mTypeDescriptor ;
  return *this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type::~ GALGAS_type (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_type::description (C_String & ioString,
                               const int32_t /* inIndentation */) const {
  ioString << "<@type: " ;
  if (NULL == mTypeDescriptor) {
    ioString << "not built" ;
  }else{
    ioString << "@" << mTypeDescriptor->mGalgasTypeName ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_typelist GALGAS_type::constructor_typeList (LOCATION_ARGS) {
  TC_UniqueArray <C_galgas_type_descriptor *> typeList ;
  C_galgas_type_descriptor::typeListRoot (typeList) ;
  GALGAS_typelist result = GALGAS_typelist::constructor_emptyList (THERE) ;
  for (int32_t i=0 ; i<typeList.count () ; i++) {
    result.addAssign_operation (GALGAS_type (typeList (i COMMA_THERE)) COMMA_HERE) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_type::reader_name (UNUSED_LOCATION_ARGS) const {
  return GALGAS_string (mTypeDescriptor->mGalgasTypeName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_type::reader_hasSuperclass (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (NULL != mTypeDescriptor->mSuperclassDescriptor) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type GALGAS_type::reader_superclass (C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  GALGAS_type result ;
  if (mTypeDescriptor != NULL) {
    if (NULL == mTypeDescriptor->mSuperclassDescriptor) {
      C_String s ;
      s << "'superclass' reader invoked on class type value '@"
        << mTypeDescriptor->mGalgasTypeName << "', without super class"
      ;
      inCompiler->onTheFlyRunTimeError (s COMMA_THERE) ;
    }else{
      result = GALGAS_type (mTypeDescriptor->mSuperclassDescriptor) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_type::objectCompare (const GALGAS_type & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const ptrdiff_t diff = mTypeDescriptor - inOperand.mTypeDescriptor ;
    // printf ("GALGAS_type::objectCompare %p, %p, diff %d\n", inOperand1.mTypeDescriptor, inOperand2.mTypeDescriptor, diff) ;
    if (diff < 0) {
      result = kFirstOperandLowerThanSecond ;
    }else if (diff > 0) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
      // printf ("EQUAL\n") ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

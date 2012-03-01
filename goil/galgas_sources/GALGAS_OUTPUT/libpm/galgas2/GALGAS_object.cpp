//---------------------------------------------------------------------------*
//                                                                           *
//  GALGAS_object : Base class for GALGAS object handling                      *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2009, ..., 2010 Pierre Molinaro.                           *
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

#include "predefined-types.h"
#include "cPtr_object.h"

//---------------------------------------------------------------------------*

GALGAS_object::GALGAS_object (void) :
AC_GALGAS_root (),
mSharedObject (NULL) {
}

//---------------------------------------------------------------------------*

GALGAS_object::GALGAS_object (AC_GALGAS_root * inObjectPointer
                              COMMA_LOCATION_ARGS) :
AC_GALGAS_root (),
mSharedObject (NULL) {
  macroMyNew (mSharedObject, cPtr_object (inObjectPointer COMMA_THERE)) ;
} 

//---------------------------------------------------------------------------*

GALGAS_object::GALGAS_object (const GALGAS_object & inSource) :
AC_GALGAS_root (),
mSharedObject (NULL) {
  macroAssignSharedObject (mSharedObject, inSource.mSharedObject) ;
}

//---------------------------------------------------------------------------*

GALGAS_object & GALGAS_object::operator = (const GALGAS_object & inSource) {
  macroAssignSharedObject (mSharedObject, inSource.mSharedObject) ;
  return * this ;
}

//---------------------------------------------------------------------------*

GALGAS_object::~ GALGAS_object (void) {
  macroDetachSharedObject (mSharedObject) ;
}

//---------------------------------------------------------------------------*

void GALGAS_object::drop (void) {
  macroDetachSharedObject (mSharedObject) ;
}

//---------------------------------------------------------------------------*

const AC_GALGAS_root * GALGAS_object::embeddedObject (void) const {
  const AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    result = mSharedObject->embeddedObjectPtr () ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

void GALGAS_object::description (C_String & /* ioString */,
                                 const PMSInt32 /* inIndentation */) const {
}

//---------------------------------------------------------------------------*

typeComparisonResult GALGAS_object::objectCompare (const GALGAS_object & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const ptrdiff_t diff = mSharedObject - inOperand.mSharedObject ;
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

//---------------------------------------------------------------------------*

GALGAS_type GALGAS_object::reader_objectStaticType (UNUSED_LOCATION_ARGS) const {
  GALGAS_type result ;
  if (isValid ()) {
    result = mSharedObject->objectStaticType () ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GALGAS_type GALGAS_object::reader_objectDynamicType (UNUSED_LOCATION_ARGS) const {
  GALGAS_type result ;
  if (isValid ()) {
    result = mSharedObject->objectDynamicType () ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

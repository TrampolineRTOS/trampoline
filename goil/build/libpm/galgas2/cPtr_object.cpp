//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  acPtr_class : Base class for GALGAS class                                                                          *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2010 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/cPtr_object.h"
#include "galgas2/predefined-types.h"
#include "utilities/MF_MemoryControl.h"

//----------------------------------------------------------------------------------------------------------------------

cPtr_object::cPtr_object (LOCATION_ARGS) :
C_SharedObject (THERE),
mEmbeddedObjectPtr (NULL) {
}

//----------------------------------------------------------------------------------------------------------------------

cPtr_object::cPtr_object (AC_GALGAS_root * inObjectPointer
                          COMMA_LOCATION_ARGS) :
C_SharedObject (THERE),
mEmbeddedObjectPtr (NULL) {
  mEmbeddedObjectPtr = inObjectPointer ;
} 

//----------------------------------------------------------------------------------------------------------------------

cPtr_object::~cPtr_object (void) {
  macroMyDelete (mEmbeddedObjectPtr) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_object::objectStaticType (void) const {
  GALGAS_type result ;
  if (NULL != mEmbeddedObjectPtr) {
    result = mEmbeddedObjectPtr->getter_staticType (HERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_type cPtr_object::objectDynamicType (void) const {
  GALGAS_type result ;
  if (NULL != mEmbeddedObjectPtr) {
    result = mEmbeddedObjectPtr->getter_dynamicType (HERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  GALGAS_enumerable : Base class for GALGAS enumerable object                                                        *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2010, ..., 2013 Pierre Molinaro.                                                                     *
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
//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/capCollectionElement.h"
#include "galgas2/cCollectionElement.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------------------------------------------------*

capCollectionElement::capCollectionElement (void) :
mPtr (NULL) {
}

//---------------------------------------------------------------------------------------------------------------------*

void capCollectionElement::setPointer (cCollectionElement * inObjectPointer) {
  macroAssignSharedObject (mPtr, inObjectPointer) ;
}

//---------------------------------------------------------------------------------------------------------------------*

capCollectionElement:: ~capCollectionElement (void) {
  macroDetachSharedObject (mPtr) ;
}

//---------------------------------------------------------------------------------------------------------------------*

capCollectionElement::capCollectionElement (const capCollectionElement & inSource) :
mPtr (NULL) {
  macroAssignSharedObject (mPtr, inSource.mPtr) ;
}

//---------------------------------------------------------------------------------------------------------------------*

capCollectionElement & capCollectionElement::operator = (const capCollectionElement & inSource) {
  macroAssignSharedObject (mPtr, inSource.mPtr) ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool capCollectionElement::isValid (void) const {
  bool result = NULL != mPtr ;
  if (result) {
    result = mPtr->isValid () ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult capCollectionElement::compare (const capCollectionElement & inOperand) const {
  macroValidSharedObject (mPtr, cCollectionElement) ;
  macroValidSharedObject (inOperand.mPtr, cCollectionElement) ;
  return mPtr->compare (inOperand.mPtr) ;
}

//---------------------------------------------------------------------------------------------------------------------*

capCollectionElement capCollectionElement::copy (void) {
  capCollectionElement result ;
  cCollectionElement * p = mPtr->copy () ;
  result.setPointer (p) ;
  macroDetachSharedObject (p) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void capCollectionElement::drop (void) {
  macroDetachSharedObject (mPtr) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void capCollectionElement::insulate (void) {
  if ((NULL != mPtr) && (mPtr->retainCount () > 1)) {
    cCollectionElement * p = mPtr->copy () ;
    macroAssignSharedObject (mPtr, p) ;  
    macroDetachSharedObject (p) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void capCollectionElement::description (C_String & ioString, const int32_t inIndentation) const {
  if (NULL == mPtr) {
    ioString << "NULL" ;
  }else{
    mPtr->description (ioString, inIndentation) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

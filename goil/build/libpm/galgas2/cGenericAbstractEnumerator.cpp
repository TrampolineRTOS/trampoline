//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  GALGAS_enumerable : Base class for GALGAS enumerable object                                                        *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2010, ..., 2016 Pierre Molinaro.                                                                     *
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

#include "galgas2/cGenericAbstractEnumerator.h"

//---------------------------------------------------------------------------------------------------------------------*

cGenericAbstractEnumerator::~ cGenericAbstractEnumerator (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

const cCollectionElement * cGenericAbstractEnumerator::currentObjectPtr (LOCATION_ARGS) const {
  const uint32_t idx = (mOrder == kENUMERATION_UP)
    ? mIndex
    : mEnumerationArray.count () - 1 - mIndex
  ;
  return mEnumerationArray.pointerAtIndexForReadAccess (idx COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

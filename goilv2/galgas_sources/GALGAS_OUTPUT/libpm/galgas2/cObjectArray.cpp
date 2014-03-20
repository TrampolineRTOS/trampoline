//-----------------------------------------------------------------------------*
//                                                                             *
//  cObjectArray                                                             *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2010, ..., 2010 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#include "cObjectArray.h"
#include "galgas2/predefined-types.h"

//-----------------------------------------------------------------------------*

cObjectArray::cObjectArray (const GALGAS_objectlist & inObjectList,
                            C_Compiler * inCompiler
                            COMMA_LOCATION_ARGS) :
mArray (NULL),
mCount (0) {
  mCount = inObjectList.count () ;
  macroMyNewArray (mArray, GALGAS_object, mCount) ;
  for (PMUInt32 i=0 ; i<mCount ; i++) {
    mArray [i] = inObjectList.reader_mValueAtIndex (GALGAS_uint (i), inCompiler COMMA_THERE) ;
  }
}

//-----------------------------------------------------------------------------*

cObjectArray::~cObjectArray (void) {
  macroMyDeleteArray (mArray) ;
  mCount = 0 ;
}

//-----------------------------------------------------------------------------*

GALGAS_object cObjectArray::objectAtIndex (const PMUInt32 inIndex
                                           COMMA_LOCATION_ARGS) const {
  MF_AssertThere (inIndex < mCount, "inIndex (%ld) >= mCount (%ld)", inIndex, mCount) ;
  return mArray [inIndex] ;
}

//-----------------------------------------------------------------------------*

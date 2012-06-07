//---------------------------------------------------------------------------*
//                                                                           *
//  C_Data : a class for handling arbitrary data array                       *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2012, ..., 2012 Pierre Molinaro.                           *
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

#include "utilities/C_Data.h"

//---------------------------------------------------------------------------*

C_Data::C_Data (void) :
mBinaryData () {
}

//---------------------------------------------------------------------------*

void C_Data::setDataFromPointer (PMUInt8 * & ioDataPtr,
                                 const PMSInt32 inDataLength) {
  mBinaryData.setDataFromPointer (ioDataPtr, inDataLength) ;
}

//---------------------------------------------------------------------------*

void C_Data::appendDataFromPointer (const PMUInt8 * inDataPtr,
                                    const PMSInt32 inDataLength) {
  mBinaryData.appendDataFromPointer (inDataPtr, inDataLength) ;
}

//---------------------------------------------------------------------------*

C_Data::~C_Data (void) {
}

//---------------------------------------------------------------------------*

void C_Data::appendData (const C_Data & inData) {
  for (PMSInt32 i=0 ; i<inData.mBinaryData.count () ; i++) {
    mBinaryData.addObject (inData.mBinaryData (i COMMA_HERE)) ;
  }
}

//---------------------------------------------------------------------------*

void C_Data::appendByte (const PMUInt8 inByte) {
  mBinaryData.addObject (inByte) ;
}

//---------------------------------------------------------------------------*

void C_Data::setLengthToZero (void) {
  mBinaryData.setCountToZero () ;
}

//---------------------------------------------------------------------------*

void C_Data::free (void) {
  mBinaryData.free () ;
}

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  PMUInt8 & C_Data::operator () (const PMSInt32 inIndex
                                 COMMA_LOCATION_ARGS) {
    return mBinaryData (inIndex COMMA_THERE) ;
  }
#endif

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  PMUInt8 & C_Data::operator () (const PMSInt32 inIndex
                                 COMMA_LOCATION_ARGS) const {
    return mBinaryData (inIndex COMMA_THERE) ;
  }
#endif

//---------------------------------------------------------------------------*

PMSInt32 C_Data::compareWithData (const C_Data & inData) const {
  PMSInt32 result = length () - inData.length () ;
  for (PMSInt32 i=0 ; (i<length ()) && (result == 0) ; i++) {
    result = ((PMSInt32) this->operator () (i COMMA_HERE)) - ((PMSInt32) inData (i COMMA_HERE)) ;  
  }  
  return result ;
}

//---------------------------------------------------------------------------*

bool C_Data::operator == (const C_Data & inData) const {
  bool equal = length () == inData.length () ;
  for (PMSInt32 i=0 ; (i<length ()) && equal ; i++) {
    equal = this->operator () (i COMMA_HERE) == inData (i COMMA_HERE) ;  
  }  
  return equal ;

}

//---------------------------------------------------------------------------*

bool C_Data::operator != (const C_Data & inData) const {
  bool equal = length () == inData.length () ;
  for (PMSInt32 i=0 ; (i<length ()) && equal ; i++) {
    equal = this->operator () (i COMMA_HERE) == inData (i COMMA_HERE) ;  
  }  
  return ! equal ;
}

//---------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  C_Data : a class for handling arbitrary data array                         *
//                                                                                                                     *
//  This file is part of libpm library                                         *
//                                                                                                                     *
//  Copyright (C) 2012, ..., 2012 Pierre Molinaro.                             *
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

#include "utilities/C_Data.h"

//---------------------------------------------------------------------------------------------------------------------*

C_Data::C_Data (void) :
mBinaryData () {
}

//---------------------------------------------------------------------------------------------------------------------*

void C_Data::setDataFromPointer (uint8_t * & ioDataPtr,
                                 const int32_t inDataLength) {
  mBinaryData.setDataFromPointer (ioDataPtr, inDataLength) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_Data::appendDataFromPointer (const uint8_t * inDataPtr,
                                    const int32_t inDataLength) {
  mBinaryData.appendDataFromPointer (inDataPtr, inDataLength) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_Data::~C_Data (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

void C_Data::appendData (const C_Data & inData) {
  for (int32_t i=0 ; i<inData.mBinaryData.count () ; i++) {
    mBinaryData.addObject (inData.mBinaryData (i COMMA_HERE)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_Data::appendByte (const uint8_t inByte) {
  mBinaryData.addObject (inByte) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_Data::setLengthToZero (void) {
  mBinaryData.setCountToZero () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_Data::free (void) {
  mBinaryData.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint8_t C_Data::operator () (const int32_t inIndex
                             COMMA_LOCATION_ARGS) const {
  return mBinaryData (inIndex COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

int32_t C_Data::compareWithData (const C_Data & inData) const {
  int32_t result = length () - inData.length () ;
  for (int32_t i=0 ; (i<length ()) && (result == 0) ; i++) {
    result = ((int32_t) this->operator () (i COMMA_HERE)) - ((int32_t) inData (i COMMA_HERE)) ;  
  }  
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_Data::removeLengthFromStart (const uint32_t inLength) {
  mBinaryData.removeObjectsAtIndex ((int32_t) inLength, 0 COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool C_Data::operator == (const C_Data & inData) const {
  bool equal = length () == inData.length () ;
  for (int32_t i=0 ; (i<length ()) && equal ; i++) {
    equal = this->operator () (i COMMA_HERE) == inData (i COMMA_HERE) ;  
  }  
  return equal ;

}

//---------------------------------------------------------------------------------------------------------------------*

bool C_Data::operator != (const C_Data & inData) const {
  bool equal = length () == inData.length () ;
  for (int32_t i=0 ; (i<length ()) && equal ; i++) {
    equal = this->operator () (i COMMA_HERE) == inData (i COMMA_HERE) ;  
  }  
  return ! equal ;
}

//---------------------------------------------------------------------------------------------------------------------*

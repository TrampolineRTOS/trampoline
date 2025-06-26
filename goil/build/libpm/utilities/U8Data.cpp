//--------------------------------------------------------------------------------------------------
//
//  U8Data : a class for handling arbitrary data array                                           
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2012, ..., 2016 Pierre Molinaro.
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

#include "U8Data.h"
#include "unicode_character_base.h"

//--------------------------------------------------------------------------------------------------

#include <string.h>

//--------------------------------------------------------------------------------------------------

U8Data::U8Data (void) :
mBinaryData () {
}

//--------------------------------------------------------------------------------------------------

void U8Data::setDataFromPointer (uint8_t * & ioDataPtr,
                                 const int32_t inDataLength) {
  mBinaryData.setDataFromPointer (ioDataPtr, inDataLength) ;
}

//--------------------------------------------------------------------------------------------------

void U8Data::appendDataFromPointer (const uint8_t * inDataPtr,
                                    const int32_t inDataLength) {
  mBinaryData.appendDataFromPointer (inDataPtr, inDataLength) ;
}

//--------------------------------------------------------------------------------------------------

U8Data::~U8Data (void) {
}

//--------------------------------------------------------------------------------------------------

void U8Data::setCapacity (const int32_t inNewCapacity) {
  mBinaryData.setCapacity (inNewCapacity) ;
}

//--------------------------------------------------------------------------------------------------

void U8Data::appendData (const U8Data & inData) {
  for (int32_t i=0 ; i<inData.mBinaryData.count () ; i++) {
    mBinaryData.appendObject (inData.mBinaryData (i COMMA_HERE)) ;
  }
}

//--------------------------------------------------------------------------------------------------

void U8Data::appendByte (const uint8_t inByte) {
  mBinaryData.appendObject (inByte) ;
}

//--------------------------------------------------------------------------------------------------

void U8Data::appendString (const String & inString) {
  for (int32_t i = 0 ; i < inString.length () ; i++) {
    appendUTF32Character (inString.charAtIndex (i COMMA_HERE)) ;
  }
}

//--------------------------------------------------------------------------------------------------

void U8Data::appendUTF32Character (const utf32 inUnicodeChar) {
  uint32_t codePoint = UNICODE_VALUE (inUnicodeChar) ;
  if (codePoint > UNICODE_VALUE (UNICODE_MAX_LEGAL_UTF32_CHARACTER)) {
    codePoint = UNICODE_VALUE (UNICODE_REPLACEMENT_CHARACTER) ;
  }
  if (codePoint < 0x80) {
    appendByte ((uint8_t) (codePoint & 255)) ;
  }else if (codePoint < 0x0800) {
    appendByte ((uint8_t) (((codePoint >> 6) | 0xC0) & 255)) ;
    appendByte ((uint8_t) ((codePoint & 0x3F) | 0x80)) ;
  }else if (codePoint < 0x10000) {
    appendByte ((uint8_t) (((codePoint >> 12) | 0xE0) & 255)) ;
    appendByte ((uint8_t) (((codePoint >> 6) & 0x3F) | 0x80)) ;
    appendByte ((uint8_t) ((codePoint & 0x3F) | 0x80)) ;
  }else{
    appendByte ((uint8_t) (((codePoint >> 18) | 0xF0) & 255)) ;
    appendByte ((uint8_t) (((codePoint >> 12) & 0x3F) | 0x80)) ;
    appendByte ((uint8_t) (((codePoint >> 6) & 0x3F) | 0x80)) ;
    appendByte ((uint8_t) ((codePoint & 0x3F) | 0x80)) ;
  }
}

//--------------------------------------------------------------------------------------------------

void U8Data::removeAllKeepingCapacity (void) {
  mBinaryData.removeAllKeepingCapacity () ;
}

//--------------------------------------------------------------------------------------------------

void U8Data::free (void) {
  mBinaryData.free () ;
}

//--------------------------------------------------------------------------------------------------

uint8_t U8Data::operator () (const int32_t inIndex
                             COMMA_LOCATION_ARGS) const {
  return mBinaryData (inIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

int32_t U8Data::compareWithData (const U8Data & inData) const {
  int32_t result = count () - inData.count () ;
  for (int32_t i=0 ; (i<count ()) && (result == 0) ; i++) {
    result = ((int32_t) this->operator () (i COMMA_HERE)) - ((int32_t) inData (i COMMA_HERE)) ;  
  }  
  return result ;
}

//--------------------------------------------------------------------------------------------------

void U8Data::removeLengthFromStart (const uint32_t inLength COMMA_LOCATION_ARGS) {
  mBinaryData.removeObjectsAtIndex ((int32_t) inLength, 0 COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void U8Data::removeLastByte (LOCATION_ARGS) {
  mBinaryData.removeObjectsAtIndex (1, mBinaryData.count () - 1 COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

bool U8Data::operator == (const U8Data & inData) const {
  bool equal = count () == inData.count () ;
  if (equal) {
    equal = ::memcmp (mBinaryData.unsafeArrayPointer(), inData.mBinaryData.unsafeArrayPointer(), (size_t) count ()) == 0 ;
  }
  return equal ;
}

//--------------------------------------------------------------------------------------------------

bool U8Data::operator != (const U8Data & inData) const {
  return ! ((*this) == inData) ;
}

//--------------------------------------------------------------------------------------------------

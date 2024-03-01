//--------------------------------------------------------------------------------------------------
//
//  U8Data : a class for handling arbitrary data array                                           
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2012, ..., 2023 Pierre Molinaro.
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

#pragma once

//--------------------------------------------------------------------------------------------------

#include "TC_Array.h"

//--------------------------------------------------------------------------------------------------

class U8Data final {
//--- Data
  private: TC_Array <uint8_t> mBinaryData ;

//--- Constructors
  public: U8Data (void) ;

//--- Destructor
  public: ~U8Data (void) ;
  
//--- Length
  public: inline int32_t count (void) const { return mBinaryData.count () ; }

  public: void removeAllKeepingCapacity (void) ;

  public: const uint8_t * unsafeDataPointer (void) const { return mBinaryData.unsafeArrayPointer () ; }

//--- Capacity
  public: void setCapacity (const int32_t inNewCapacity) ;

//--- Free
  public: void free (void) ;

//--- Append data
  public: void appendData (const U8Data & inData) ;
  public: void appendString (const class String & inString) ;
  public: void appendUTF32Character (const utf32 inUnicodeChar) ;
  
//---
  public: uint8_t operator () (const int32_t inIndex
                                COMMA_LOCATION_ARGS) const ;


//--- Data from pointer
  public: void setDataFromPointer (uint8_t * & ioDataPtr,
                                    const int32_t inDataLength) ;

  public: void appendDataFromPointer (const uint8_t * inDataPtr,
                                       const int32_t inDataLength) ;

  public: void appendByte (const uint8_t inByte) ;

  public: int32_t compareWithData (const U8Data & inData) const ;

//---
  public: void removeLengthFromStart (const uint32_t inLength COMMA_LOCATION_ARGS) ;

//---
  public: void removeLastByte (LOCATION_ARGS) ;

//---
  public: bool operator == (const U8Data & inData) const ;
  public: bool operator != (const U8Data & inData) const ;
} ;

//--------------------------------------------------------------------------------------------------

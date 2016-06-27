//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  C_Data : a class for handling arbitrary data array                                                                 *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2012, ..., 2013 Pierre Molinaro.                                                                     *
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

#ifndef DATA_CLASS_DEFINED
#define DATA_CLASS_DEFINED

//----------------------------------------------------------------------------------------------------------------------

#include "collections/TC_Array.h"

//----------------------------------------------------------------------------------------------------------------------

class C_Data {
//--- Data
  private : TC_Array <uint8_t> mBinaryData ;

//--- Constructors
  public : C_Data (void) ;

//--- Destructor
  public : virtual ~C_Data (void) ;
  
//--- Length
  public : inline int32_t length (void) const { return mBinaryData.count () ; }
  
  public : void setLengthToZero (void) ;

  public : const uint8_t * unsafeDataPointer (void) const { return mBinaryData.unsafeArrayPointer () ; }

//--- Free
  public : void free (void) ;

//--- Append data
  public : void appendData (const C_Data & inData) ;
  
//---
  public : uint8_t operator () (const int32_t inIndex
                                COMMA_LOCATION_ARGS) const ;


//--- Data from pointer
  public : void setDataFromPointer (uint8_t * & ioDataPtr,
                                    const int32_t inDataLength) ;

  public : void appendDataFromPointer (const uint8_t * inDataPtr,
                                       const int32_t inDataLength) ;

  public : void appendByte (const uint8_t inByte) ;

  public : int32_t compareWithData (const C_Data & inData) const ;

//---
  public : void removeLengthFromStart (const uint32_t inLength) ;

//--- 
  public : bool operator == (const C_Data & inData) const ;
  public : bool operator != (const C_Data & inData) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

#endif

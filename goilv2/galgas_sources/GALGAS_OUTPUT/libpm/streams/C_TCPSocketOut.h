//-----------------------------------------------------------------------------*
//                                                                             *
//  'C_TCPSocketOut' : a class for sending data as TCP socket client           *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2011, ..., 2011 Pierre Molinaro.                             *
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

#ifndef CLASS_TCP_SOCKET_OUTPUT_DEFINED
#define CLASS_TCP_SOCKET_OUTPUT_DEFINED

//-----------------------------------------------------------------------------*

#include "streams/AC_OutputStream.h"

//-----------------------------------------------------------------------------*

class C_TCPSocketOut : public AC_OutputStream {
//--- Constructor
  public : C_TCPSocketOut (void) ; // No connection

//--- Destructor
  public : virtual ~ C_TCPSocketOut (void) ;

//--- Connect (call it once)
  public : bool connect (const uint16_t inServerPort,
                         const C_String & inHostName) ;

//--- General stream methods
  protected : virtual void performActualCharArrayOutput (const char * inCharArray,
                                                         const int32_t inArrayCount) ;

  protected : virtual void performActualUnicodeArrayOutput (const utf32 * inCharArray,
                                                            const int32_t inArrayCount) ;

//---
  private : int mSocket ;
} ;

//-----------------------------------------------------------------------------*

#endif

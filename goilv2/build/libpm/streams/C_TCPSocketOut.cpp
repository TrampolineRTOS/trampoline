//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'C_TCPSocketOut' : a class for sending data as TCP socket client           *
//                                                                                                                     *
//  This file is part of libpm library                                         *
//                                                                                                                     *
//  Copyright (C) 2011, ..., 2011 Pierre Molinaro.                             *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes                                          *
//  ECN, École Centrale de Nantes (France)                                                                             *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it                                            *
//  under the terms of the GNU Lesser General Public License as published                                              *
//  by the Free Software Foundation; either version 2 of the License, or                                               *
//  (at your option) any later version.                                                                                *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT                                             *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or                                              *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for                                           *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "streams/C_TCPSocketOut.h"
#include "strings/unicode_character_cpp.h"
#include "strings/C_String.h"

//---------------------------------------------------------------------------------------------------------------------*

#ifdef COMPILE_FOR_WIN32
  #include <winsock2.h>
  #include <ws2tcpip.h>
  #include <stdio.h>
#else
  #include <stdio.h>
  #include <string.h>
  #include <sys/types.h>
  #include <netinet/in.h>
  #include <sys/socket.h>
  #include <arpa/inet.h>
  #include <netdb.h>
  #include <unistd.h>
#endif

//---------------------------------------------------------------------------------------------------------------------*

C_TCPSocketOut::C_TCPSocketOut (void) :
mSocket (-1) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool C_TCPSocketOut::connect (const uint16_t inServerPort,
                              const C_String & inHostName) {
  bool ok = mSocket == -1 ;
//---
  if (ok) {
    struct addrinfo hints, *res;
  //---
    memset (& hints, 0, sizeof (hints)) ;
    hints.ai_family = AF_INET ;
    hints.ai_socktype = SOCK_STREAM ;
    char portString [10] ;
    sprintf (portString, "%hu", inServerPort) ;
    getaddrinfo (inHostName.cString (HERE), portString, & hints, & res) ;
  //---
    mSocket = socket (res->ai_family, res->ai_socktype, res->ai_protocol) ;
  //---
    ok = ::connect (mSocket, res->ai_addr, res->ai_addrlen) != -1 ;
  //---
    if (! ok) {
      printf ("SOCKET CONNECTION ERROR\n") ;
      perror ("connect") ;
      close (mSocket) ;
      mSocket = -1 ;
    }
  }
//---
  return ok ;
}

//---------------------------------------------------------------------------------------------------------------------*

void C_TCPSocketOut::performActualCharArrayOutput (const char * inCharArray,
                                                   const int32_t inArrayCount) {
  if ((mSocket >=0) && (inArrayCount > 0)) {
    ssize_t sentByteCount = 0 ;
    bool ok = true ;
    while (ok && (sentByteCount < inArrayCount)) {
      ssize_t numbytes = send (mSocket, & inCharArray [sentByteCount], (size_t) (inArrayCount - sentByteCount), 0) ;
      sentByteCount += numbytes ;
      ok = numbytes >= 0 ;
    }
    if (! ok) {
      printf ("SOCKET SEND ERROR\n") ;
      perror ("send") ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void C_TCPSocketOut::performActualUnicodeArrayOutput (const utf32 * inCharArray,
                                                      const int32_t inArrayCount) {
  for (int32_t i=0 ; i<inArrayCount ; i++) {
    char buffer [5] ;
    UTF8StringFromUTF32Character (inCharArray [i], buffer) ;
    performActualCharArrayOutput (buffer, (int32_t) strlen (buffer)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

C_TCPSocketOut::~C_TCPSocketOut (void) {
  if (mSocket >=0) {
    // printf ("CLOSE SOCKET\n") ;
    close (mSocket) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

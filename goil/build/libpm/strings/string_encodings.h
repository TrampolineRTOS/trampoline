//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  string_encodings: enum that defines all handled string encodings                                                   *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2009 Pierre Molinaro.                                                                     *
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

#ifndef STRING_ENCODING_ENUM_DEFINED
#define STRING_ENCODING_ENUM_DEFINED

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   S T R I N G    E N C O D I N G S                                                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef enum {
  k8859_1_encoding  =  0,
  k8859_10_encoding =  1,
  k8859_11_encoding =  2,
  k8859_13_encoding =  3,
  k8859_14_encoding =  4,
  k8859_15_encoding =  5,
  k8859_16_encoding =  6,
  k8859_2_encoding  =  7,
  k8859_3_encoding  =  8,
  k8859_4_encoding  =  9,
  k8859_5_encoding  = 10,
  k8859_6_encoding  = 11,
  k8859_7_encoding  = 12,
  k8859_8_encoding  = 13,
  k8859_9_encoding  = 14,
  kCP1252_encoding  = 15,
  kCP437_DOS_encoding = 16,
  kMacRoman_encoding  = 17
} PMStringEncoding ;

//---------------------------------------------------------------------------------------------------------------------*

#endif

//---------------------------------------------------------------------------*
//                                                                           *
//     Get a prime integer                                                   *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1999, ..., 2010 Pierre Molinaro.                           *
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

#include "utilities/F_GetPrime.h"

//---------------------------------------------------------------------------*
//                                                                           *
//           Get a prime integer greater than argument                       *
//                                                                           *
//---------------------------------------------------------------------------*

PMUInt32 getPrimeGreaterThan (const PMUInt32 inValue) {
  const PMSInt32 ARRAY_SIZE = 39 ;
  const PMUInt32 array [ARRAY_SIZE] = {
          3,
        727,
       1031, // > 2**10
       1453,
       2053, // > 2**11
       2909,
       4099, // > 2**12
       5813,
       8209, // > 2**13
      11621,
      16411, // > 2**14
      23251,
      32771, // > 2**15
      46489,
      64537, // > 2**16
      92959,
     131101, // > 2**17
     185923,
     262145, // > 2**18
     371837,
     524309, // > 2**19
     743671,
    1048583, // > 2**20
    1487351,
    2097169, // > 2**21
    2974691,
    4194319, // > 2**22
    5949373,
    8388617, // > 2**23
   11898739,
   16777259, // > 2**24
   23797471,
   33554467, // > 2**25
   47594941,
   67108879, // > 2**26
   95189879,
  134217757, // > 2**27
  201326611,
  402653189  // > 2**28
} ;
  PMSInt32 i = 0 ;
  bool notFound = true ;
  while (notFound && (i<ARRAY_SIZE)) {
    notFound = inValue > array [i] ;
    i ++ ;
  }
  return array [i - 1] ;
}

//---------------------------------------------------------------------------*

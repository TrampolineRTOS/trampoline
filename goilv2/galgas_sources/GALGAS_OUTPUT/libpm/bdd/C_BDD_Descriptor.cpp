//-----------------------------------------------------------------------------*
//                                                                             *
//     C++ class for descripting BDD variables                               *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2001, ..., 2005 Pierre Molinaro.                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
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

#include "bdd/C_BDD_Descriptor.h"
#include "utilities/MF_Assert.h"

//-----------------------------------------------------------------------------*
//                                                                             *
//        Constructor                                                        *
//                                                                             *
//-----------------------------------------------------------------------------*

C_BDD_Descriptor::C_BDD_Descriptor (const PMUInt32 inMaxValue) :
mMaxValue (inMaxValue),
mBDDbits (0),
mMask () {
  PMUInt32 temp = inMaxValue ;
  while (temp != 0) {
    temp >>= 1 ;
    mBDDbits ++ ;
  }
  if (inMaxValue > 0) {
    mMask = C_BDD::varCompareConst (0,
                                    mBDDbits,
                                    C_BDD::kLowerOrEqual,
                                    mMaxValue) ;
  }
}

//-----------------------------------------------------------------------------*
//                                                                             *
//       Destructor                                                          *
//                                                                             *
//-----------------------------------------------------------------------------*

C_BDD_Descriptor::~C_BDD_Descriptor (void) {
}

//-----------------------------------------------------------------------------*


//-----------------------------------------------------------------------------*
//                                                                             *
//     C++ class for descripting BDD sets                                    *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2002, ..., 2005 Pierre Molinaro.                             *
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

#ifndef C_BDD_DESCRIPTOR_DEFINED
#define C_BDD_DESCRIPTOR_DEFINED

//-----------------------------------------------------------------------------*

#include "utilities/M_machine.h"
#include "utilities/M_SourceLocation.h"
#include "bdd/C_BDD.h"

//-----------------------------------------------------------------------------*

class C_BDD_Descriptor {
//--- Constructor et destructor
  public : C_BDD_Descriptor (const PMUInt32 inMaxValue) ;
  public : virtual ~C_BDD_Descriptor (void) ;

//--- Getters
  public : PMUInt32 getMaxValue (void) const {
    return mMaxValue ;
  }

  public : PMUInt16 getBDDbitsSize (void) const {
    return mBDDbits ;
  }
  
  public : C_BDD getMask (void) const {
    return mMask ;
  }

//--- Private attributes
  private : PMUInt32 mMaxValue ;
  private : PMUInt16 mBDDbits ;
  private : C_BDD mMask ;
} ;

//-----------------------------------------------------------------------------*

#endif

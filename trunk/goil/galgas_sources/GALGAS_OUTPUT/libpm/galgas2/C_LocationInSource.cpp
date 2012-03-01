//---------------------------------------------------------------------------*
//                                                                           *
//  'C_LocationInSource'                                                     *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1996, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
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

#include "galgas2/C_LocationInSource.h"

//---------------------------------------------------------------------------*

C_LocationInSource::C_LocationInSource (void) :
mIndex (0),
mLineNumber (0),
mColumnNumber (0) {
}

//---------------------------------------------------------------------------*

C_LocationInSource::C_LocationInSource (const PMSInt32 inIndex,
                                        const PMSInt32 inLine,
                                        const PMSInt32 inColumn) :
mIndex (inIndex),
mLineNumber (inLine),
mColumnNumber (inColumn) {
}

//---------------------------------------------------------------------------*

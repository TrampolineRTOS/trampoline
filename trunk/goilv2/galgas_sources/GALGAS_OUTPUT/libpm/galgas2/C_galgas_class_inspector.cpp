//-----------------------------------------------------------------------------*
//                                                                             *
//  GALGAS introspection classes                                               *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2009, ..., 2009 Pierre Molinaro.                             *
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

#include "galgas2/C_galgas_class_inspector.h"

//-----------------------------------------------------------------------------*

#include <stddef.h>

//-----------------------------------------------------------------------------*

static C_galgas_class_inspector * gClassListRoot = NULL ;

//-----------------------------------------------------------------------------*

C_galgas_class_inspector::
C_galgas_class_inspector (const std::type_info * inClassID,
                          const std::type_info * inSuperClassID,
                          const char * inClassMessage) :
mNextClass (gClassListRoot),
mClassID (inClassID),
mSuperClassID (inSuperClassID),
mClassMessage (inClassMessage) {
  gClassListRoot = this ;
}

//-----------------------------------------------------------------------------*

C_galgas_class_inspector * C_galgas_class_inspector::root (void) {
  return gClassListRoot ;
}

//-----------------------------------------------------------------------------*

//---------------------------------------------------------------------------*
//                                                                           *
//                               GALGAS header                               *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1999, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                             *
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

#include <stdio.h>
#include <string.h>

#include "command_line_interface/C_builtin_CLI_Options.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"

#include "files/C_TextFileWrite.h"

#include "galgas2/C_galgas_class_inspector.h"
#include "galgas2/predefined-types.h"

#include "utilities/MF_MemoryControl.h"
#include "utilities/C_PrologueEpilogue.h"

#include "streams/AC_OutputStream.h"
#include "streams/C_ConsoleOut.h"

#include "time/C_Timer.h"
#include "time/C_DateTime.h"

#include "strings/C_String.h"
#include "utilities/F_DisplayException.h"
#include "utilities/MF_Assert.h"
#include "utilities/F_GetPrime.h"

//---------------------------------------------------------------------------*

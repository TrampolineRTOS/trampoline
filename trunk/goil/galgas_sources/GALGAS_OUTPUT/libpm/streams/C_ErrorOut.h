//---------------------------------------------------------------------------*
//                                                                           *
//  'C_ErrorOut' : a class for console output                                *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2006, ..., 2011 Pierre Molinaro.                           *
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

#ifndef CLASS_CONSOLE_ERROR_OUTPUT_DEFINED
#define CLASS_CONSOLE_ERROR_OUTPUT_DEFINED

//---------------------------------------------------------------------------*

#include "streams/C_ColoredConsole.h"

//---------------------------------------------------------------------------*

class C_ErrorOut : public C_ColoredConsole {
//--- Constructor
  public : C_ErrorOut (void) ;

//--- Flush output
  public : virtual void flush (void) ;
  
//--- General stream method
  protected : virtual void
  performActualCharArrayOutput (const char * inCharArray,
                                const PMSInt32 inArrayCount) ;

  protected : virtual void
  performActualUnicodeArrayOutput (const utf32 * inCharArray,
                                   const PMSInt32 inArrayCount) ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//  C O N S O L E    O U T    G L O B A L   V A R I A B L E                  *
//                                                                           *
//---------------------------------------------------------------------------*

extern C_ErrorOut ce ;

//---------------------------------------------------------------------------*

#endif

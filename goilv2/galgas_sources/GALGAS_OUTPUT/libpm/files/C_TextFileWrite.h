//-----------------------------------------------------------------------------*
//                                                                             *
//  'C_TextFileWrite' : a class for stream writing text files                *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 1999, ..., 2010 Pierre Molinaro.                             *
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

#ifndef CLASS_WRITE_TEXT_FILE_DEFINED
#define CLASS_WRITE_TEXT_FILE_DEFINED

//-----------------------------------------------------------------------------*

#include "strings/C_String.h"
#include "streams/AC_OutputStream.h"
#include "files/AC_FileHandleForWriting.h"

//-----------------------------------------------------------------------------*

#include <stdio.h>

//-----------------------------------------------------------------------------*

const PMSInt32 kFileBufferSize = 10000 ;

//-----------------------------------------------------------------------------*

class C_TextFileWrite : public AC_OutputStream, public AC_FileHandleForWriting {
//--- Constructor : if inFileName is the empty string, no file is opened.
//    Otherwise, it tries to open the file for writing;
//    The destructor will close the file (is successfully opened)
  public : C_TextFileWrite (const C_String & inFileName) ;

//--- Destructor closes the file
  public : virtual ~C_TextFileWrite (void) ;

//--- No copy
  private : C_TextFileWrite (C_TextFileWrite &) ;
  private : C_TextFileWrite & operator = (C_TextFileWrite &) ;
  
//--- General stream methods
  protected : virtual void performActualCharArrayOutput (const char * inCharArray,
                                                         const PMSInt32 inArrayCount) ;

  protected : virtual void performActualUnicodeArrayOutput (const utf32 * inCharArray,
                                                            const PMSInt32 inArrayCount) ;

//--- Flush print
  public : virtual void flush (void) ;

//--- Close file (does nothing is file is not open)
  public : virtual bool close (void) ;

//--- Private attributes
  private : PMSInt32 mBufferLength ;
  private : char mBuffer [kFileBufferSize + 1] ;
} ;

//-----------------------------------------------------------------------------*

#endif

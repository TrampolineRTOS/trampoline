//---------------------------------------------------------------------------*
//                                                                           *
//  'C_TextFileWrite' : a class for stream writing text files                *
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

#ifndef CLASS_WRITE_TEXT_FILE_DEFINED
#define CLASS_WRITE_TEXT_FILE_DEFINED

//---------------------------------------------------------------------------*

#include "strings/C_String.h"
#include "streams/AC_OutputStream.h"

//---------------------------------------------------------------------------*

#include <stdio.h>

//---------------------------------------------------------------------------*

const PMSInt32 kFileBufferSize = 10000 ;

//---------------------------------------------------------------------------*

class C_TextFileWrite : public AC_OutputStream {
//--- Constructor : if inFileName is the empty string, no file is opened.
//    Otherwise, it tries to open the file for writing;
//    outSuccessfullyOpened is returned true is inFileName is empty or if file is successfully opened
//    outSuccessfullyOpened is returned false is inFileName is not empty and file cannot be successfully opened
//    The destructor will close the file (is successfully opened)
  public : C_TextFileWrite (const C_String & inFileName
                            COMMA_MAC_OS_CREATOR_FORMAL_ARGUMENT,
                            bool & outSuccessfullyOpened) ;

//--- Destructor closes the file
  public : virtual ~C_TextFileWrite (void) ;

//--- No copy
  private : C_TextFileWrite (C_TextFileWrite &) ;
  private : C_TextFileWrite & operator = (C_TextFileWrite &) ;
  
//--- General stream methods
  protected : virtual void
  performActualCharArrayOutput (const char * inCharArray,
                                const PMSInt32 inArrayCount) ;

  protected : virtual void
  performActualUnicodeArrayOutput (const utf32 * inCharArray,
                                   const PMSInt32 inArrayCount) ;

//--- Get file name
  public : C_String getFileName (void) const { return mFileName ; }

//--- Flush print
  public : virtual void flush (void) ;

//--- Close file (does nothing is file is not open)
  public : virtual bool close (void) ;

//--- Private attributes
  private : C_String mFileName ;
  private : FILE * mFilePtr ;
  private : PMSInt32 mBufferLength ;
  private : char mBuffer [kFileBufferSize + 1] ;
} ;

//---------------------------------------------------------------------------*

#endif

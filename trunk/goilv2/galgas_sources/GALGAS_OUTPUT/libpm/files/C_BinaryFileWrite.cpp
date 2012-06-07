//---------------------------------------------------------------------------*
//                                                                           *
//  'C_TextFileWrite' : a class for stream writing text files                *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1999, ..., 2011 Pierre Molinaro.                           *
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

#include "files/C_BinaryFileWrite.h"
#include "time/C_DateTime.h"
#include "files/C_FileManager.h"

//---------------------------------------------------------------------------*

#include <string.h>
#include <ctype.h>

//---------------------------------------------------------------------------*

C_BinaryFileWrite::C_BinaryFileWrite (const C_String & inFileName) :
AC_FileHandleForWriting (inFileName, "wb") {
}

//---------------------------------------------------------------------------*
//                                Close                                      *
//---------------------------------------------------------------------------*

bool C_BinaryFileWrite::close (void) {
  bool ok = true ;
  if (mFilePtr != NULL) {
    ok = ::fclose (mFilePtr) == 0 ; // Flushes the file, then closes it
    mFilePtr = NULL ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*

void C_BinaryFileWrite::flush (void) {
  if (NULL != mFilePtr) {
    ::fflush (mFilePtr) ;
  }
}

//---------------------------------------------------------------------------*
//                             Destructor                                    *
// Cannot call the virtual 'close' method in destructor                      *
//---------------------------------------------------------------------------*

C_BinaryFileWrite::~C_BinaryFileWrite (void) {
  if (NULL != mFilePtr) {
    ::fflush (mFilePtr) ;
  }
}

//---------------------------------------------------------------------------*

void C_BinaryFileWrite::appendData (const C_Data & inData) {
  if (NULL != mFilePtr) {
    ::fwrite (inData.dataPointer (), 1, inData.length (), mFilePtr) ;
  }
}

//---------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'AC_FileHandle' : an abstract class for handling files handles             *
//                                                                                                                     *
//  This file is part of libpm library                                         *
//                                                                                                                     *
//  Copyright (C) 2012, ..., 2012 Pierre Molinaro.                             *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes                                          *
//  ECN, École Centrale de Nantes (France)                                                                             *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it                                            *
//  under the terms of the GNU Lesser General Public License as published                                              *
//  by the Free Software Foundation; either version 2 of the License, or                                               *
//  (at your option) any later version.                                                                                *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT                                             *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or                                              *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for                                           *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "files/AC_FileHandle.h"

//---------------------------------------------------------------------------------------------------------------------*

AC_FileHandle::AC_FileHandle (const C_String & inFilePath,
                              const char * inMode) :
mFilePtr ((inFilePath.length () == 0) ? NULL : ::fopen (C_FileManager::nativePathWithUnixPath (inFilePath).cString (HERE), inMode)),
mFilePath (inFilePath) {
}


//---------------------------------------------------------------------------------------------------------------------*

AC_FileHandle::~AC_FileHandle (void) {
  if (NULL != mFilePtr) {
    fclose (mFilePtr) ;
    mFilePtr = NULL ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*

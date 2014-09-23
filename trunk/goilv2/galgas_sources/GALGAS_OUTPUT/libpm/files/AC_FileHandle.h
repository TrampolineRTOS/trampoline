//-----------------------------------------------------------------------------*
//                                                                             *
//  'AC_FileHandle' : an abstract class for handling files handles             *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2012, ..., 2012 Pierre Molinaro.                             *
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

#ifndef ABSTRACT_FILE_HANDLE_CLASS_DEFINED
#define ABSTRACT_FILE_HANDLE_CLASS_DEFINED

//-----------------------------------------------------------------------------*

#include "files/C_FileManager.h"

//-----------------------------------------------------------------------------*

class AC_FileHandle {
//--- 
  protected : FILE * mFilePtr ;
  protected : C_String mFilePath ;

//--- Protected constructor
  protected : AC_FileHandle (const C_String & inFilePath,
                             const char * inMode) ;

//--- No copy
  private : AC_FileHandle (const AC_FileHandle &) ;
  private : AC_FileHandle & operator = (const AC_FileHandle &) ;

//--- Virtual destructor
  public : virtual ~ AC_FileHandle (void) ;

//---
  public : inline bool isOpened (void) const { return NULL != mFilePtr ; }
  public : inline C_String filePath (void) const { return mFilePath ; }
} ;


//-----------------------------------------------------------------------------*

#endif

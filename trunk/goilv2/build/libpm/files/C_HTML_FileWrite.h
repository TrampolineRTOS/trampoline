//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'C_HTML_FileWrite' : a class for stream writing html text files            *
//    (with facility for outputing C++ code)                                   *
//                                                                                                                     *
//  This file is part of libpm library                                         *
//                                                                                                                     *
//  Copyright (C) 2003, ..., 2010 Pierre Molinaro.                             *
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

#ifndef CLASS_WRITE_HTML_FILE_DEFINED
#define CLASS_WRITE_HTML_FILE_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "files/C_TextFileWrite.h"

//---------------------------------------------------------------------------------------------------------------------*

class C_String ;

//---------------------------------------------------------------------------------------------------------------------*

class C_HTML_FileWrite : public C_TextFileWrite {
//--- Constructor : if inFileName is the empty string, no file is opened.
//    Otherwise, it tries to open the file for writing;
//    The destructor will close the file (is successfully opened)
  public : C_HTML_FileWrite (const C_String & inFileName,
                             const C_String & inWindowTitle,
                             const C_String & inCSSFileName,
                             const C_String & inCSSContents) ;

//--- Destructor
  public : virtual ~C_HTML_FileWrite (void) ;

//--- No copy
  private : C_HTML_FileWrite & operator = (C_HTML_FileWrite &) ;
  private : C_HTML_FileWrite (C_HTML_FileWrite &) ;

//--- Output data, without HTML formatting
  public : void outputRawData (const char * in_Cstring) ;

//--- General stream methods
  protected : virtual void performActualCharArrayOutput (const char * inCharArray,
                                                         const int32_t inArrayCount) ;

  protected : virtual void performActualUnicodeArrayOutput (const utf32 * inCharArray,
                                                            const int32_t inArrayCount) ;

//--- Method for writing a HTML table
  public : void appendCppTitleComment (const C_String & inCommentString,
                                       const C_String & inTableStyleClass) ;

//--- Close file (does nothing is file is not open)
  public : virtual bool close (void) ;

//--- Private attributes
  private : typedef C_TextFileWrite inherited ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif

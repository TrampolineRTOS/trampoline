//-----------------------------------------------------------------------------*
//                                                                             *
//  'C_HTML_FileWrite' : a class for stream writing html text files            *
//    (with facility for outputing C++ code)                                   *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2003, ..., 2014 Pierre Molinaro.                             *
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

#include "files/C_HTML_FileWrite.h"
#include "strings/C_String.h"
#include "time/C_DateTime.h"

//-----------------------------------------------------------------------------*

#include <string.h>

//-----------------------------------------------------------------------------*

C_HTML_FileWrite::C_HTML_FileWrite (const C_String & inFileName,
                                    const C_String & inWindowTitle,
                                    const C_String & inCSSFileName,
                                    const C_String & inCSSContents) :
C_TextFileWrite (inFileName) {
  outputRawData ("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n"
                 "<html>"
                 "<head>\n"
                 "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\">\n"
                 "<title>\n") ;
  *this << inWindowTitle ;
  outputRawData ("</title>") ;
  if (inCSSFileName.length () > 0) {
    outputRawData ("<link rel=stylesheet type=\"text/css\" href=\"") ;
    outputRawData (inCSSFileName.cString (HERE)) ;
    outputRawData ("\">") ;
  }  
  if (inCSSContents.length () > 0) {
    outputRawData ("<style type=\"text/css\">") ;
    outputRawData (inCSSContents.cString (HERE)) ;
    outputRawData ("</style>") ;
  }
  outputRawData ("</head>"
                 "<body><div>\n") ;
}

//-----------------------------------------------------------------------------*
//                     Close                                                   *
//-----------------------------------------------------------------------------*

bool C_HTML_FileWrite::close (void) {
  outputRawData ("</div></body></html>\n") ;
  return inherited::close () ;
}

//-----------------------------------------------------------------------------*
//  Destructor writes html ending code, the closes the file                    *
//-----------------------------------------------------------------------------*

C_HTML_FileWrite::~C_HTML_FileWrite (void) {
  outputRawData ("</div></body></html>\n") ;
}

//-----------------------------------------------------------------------------*
//  Write a character string into the file WITHOUT any translation             *
//-----------------------------------------------------------------------------*

void C_HTML_FileWrite::outputRawData (const char * in_Cstring) {
  inherited::performActualCharArrayOutput (in_Cstring, (int32_t) (strlen (in_Cstring) & UINT32_MAX)) ;
}

//-----------------------------------------------------------------------------*
//                  Write a character string into the file                     *
//  Performs HTML character translation (i.e. '<' --> '&lt;', ...)             *
//-----------------------------------------------------------------------------*

void C_HTML_FileWrite::performActualCharArrayOutput (const char * inCharArray,
                                                     const int32_t inArrayCount) {
  for (int32_t i=0 ; i<inArrayCount ; i++) {
    const char c = inCharArray [i] ;
    switch (c) {
    case '<' :
      inherited::performActualCharArrayOutput ("&lt;", 4) ;
      break ;
    case '>' :
      inherited::performActualCharArrayOutput ("&gt;", 4) ;
      break ;
    case '&' :
      inherited::performActualCharArrayOutput ("&amp;", 4) ;
      break ;
    default :
      inherited::performActualCharArrayOutput (& c, 1) ;
      break ;
    }
  }
}

//-----------------------------------------------------------------------------*

void C_HTML_FileWrite::performActualUnicodeArrayOutput (const utf32 * inCharArray,
                                                        const int32_t inArrayCount) {
  for (int32_t i=0 ; i<inArrayCount ; i++) {
    const utf32 codePoint = inCharArray [i] ;
    switch (UNICODE_VALUE (codePoint)) {
    case '<' :
      inherited::performActualCharArrayOutput ("&lt;", 4) ;
      break ;
    case '>' :
      inherited::performActualCharArrayOutput ("&gt;", 4) ;
      break ;
    case '&' :
      inherited::performActualCharArrayOutput ("&amp;", 4) ;
      break ;
    default :
      inherited::performActualUnicodeArrayOutput (& codePoint, 1) ;
      break ;
    }
  }
}

//-----------------------------------------------------------------------------*
//                 Comments as a table                                         *
//-----------------------------------------------------------------------------*

void C_HTML_FileWrite::appendCppTitleComment (const C_String & inCommentString,
                                              const C_String & inTableStyleClass) {
  outputRawData ("<table") ;
  if (inTableStyleClass.length () > 0) {
    outputRawData (" class=\"") ;
    outputRawData (inTableStyleClass.cString (HERE)) ;
    outputRawData ("\"") ;
  }
  outputRawData ("><tr><td>\n") ;
  *this << inCommentString ;
  outputRawData ("\n</td></tr></table>\n") ;
}

//-----------------------------------------------------------------------------*

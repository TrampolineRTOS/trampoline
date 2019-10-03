//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  C_String : an implementation of fully dynamic character string                                                     *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1997, ..., 2014 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@ec-nantes.fr                                                                              *
//                                                                                                                     *
//  LS2N, Laboratoire des Sciences du Numérique de Nantes, ECN, École Centrale de Nantes (France)                      *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "strings/C_HTMLString.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include <string.h>

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//   C O N S T R U C T O R S                                                                                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_HTMLString::C_HTMLString (void) :
C_String () {
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_HTMLString::writeStartCode (const C_String & inWindowTitle,
                                   const C_String & inCSSFileName,
                                   const C_String & inCSSContents) {
  outputRawData ("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n"
                 "<html>"
                 "<head>\n"
                 "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n"
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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_HTMLString::writeEndCode (void) {
  outputRawData ("</div></body></html>\n") ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//   A S S I G N M E N T    O P E R A T O R S                                                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

/*C_HTMLString & C_HTMLString::operator = (const C_HTMLString & inSource) {
  macroAssignSharedObject (mEmbeddedString, inSource.mEmbeddedString) ;
  return * this ;
}*/

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_HTMLString::outputRawData (const char * in_Cstring) {
  inherited::performActualCharArrayOutput (in_Cstring, (int32_t) (strlen (in_Cstring) & UINT32_MAX)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                  Write a character string into the file                                                             *
//  Performs HTML character translation (i.e. '<' --> '&lt;', ...)                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_HTMLString::performActualCharArrayOutput (const char * inCharArray,
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
      inherited::performActualCharArrayOutput ("&amp;", 5) ;
      break ;
    default :
      inherited::performActualCharArrayOutput (& c, 1) ;
      break ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_HTMLString::performActualUnicodeArrayOutput (const utf32 * inCharArray,
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
      inherited::performActualCharArrayOutput ("&amp;", 5) ;
      break ;
    default :
      inherited::performActualUnicodeArrayOutput (& codePoint, 1) ;
      break ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                 Comments as a table                                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void C_HTMLString::appendCppTitleComment (const C_String & inCommentString,
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

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

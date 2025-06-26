//--------------------------------------------------------------------------------------------------
//
//  'HTMLFileWrite' : a class for stream writing html text files                              
//    (with facility for outputing C++ code)                                                     
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2003, ..., 2014 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//--------------------------------------------------------------------------------------------------

#include "HTMLFileWrite.h"
#include "String-class.h"
#include "DateTime.h"

//--------------------------------------------------------------------------------------------------

#include <string.h>

//--------------------------------------------------------------------------------------------------

HTMLFileWrite::HTMLFileWrite (const String & inFileName,
                                    const String & inWindowTitle,
                                    const String & inCSSFileName,
                                    const String & inCSSContents) :
TextFileWrite (inFileName) {
  appendRawData ("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n"
                 "<html>"
                 "<head>\n"
                 "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n"
                 "<title>\n") ;
  appendString (inWindowTitle) ;
  appendRawData ("</title>") ;
  if (inCSSFileName.length () > 0) {
    appendRawData ("<link rel=stylesheet type=\"text/css\" href=\"") ;
    appendRawData (inCSSFileName.cString ()) ;
    appendRawData ("\">") ;
  }  
  if (inCSSContents.length () > 0) {
    appendRawData ("<style type=\"text/css\">") ;
    appendRawData (inCSSContents.cString ()) ;
    appendRawData ("</style>") ;
  }
  appendRawData ("</head>\n<body><div>\n") ;
}

//--------------------------------------------------------------------------------------------------
//                     Close                             
//--------------------------------------------------------------------------------------------------

bool HTMLFileWrite::close (void) {
  appendRawData ("</div></body></html>\n") ;
  return Super::close () ;
}

//--------------------------------------------------------------------------------------------------
//  Destructor writes html ending code, the closes the file
//--------------------------------------------------------------------------------------------------

HTMLFileWrite::~HTMLFileWrite (void) {
  appendRawData ("</div></body></html>\n") ;
}

//--------------------------------------------------------------------------------------------------
//  Write a character string into the file WITHOUT any translation
//--------------------------------------------------------------------------------------------------

void HTMLFileWrite::appendRawData (const char * in_Cstring) {
  if (nullptr != in_Cstring) {
    Super::handleAppendUTF8Array (in_Cstring, int32_t (strlen (in_Cstring))) ;
  }
}

//--------------------------------------------------------------------------------------------------
//                  Write a character string into the file
//  Performs HTML character translation (i.e. '<' --> '&lt;', ...)
//--------------------------------------------------------------------------------------------------

void HTMLFileWrite::handleAppendUTF8Array (const char * inCharArray,
                                                  const int32_t inArrayCount) {
  for (int32_t i=0 ; i<inArrayCount ; i++) {
    const char c = inCharArray [i] ;
    switch (c) {
    case '<' :
      Super::handleAppendUTF8Array ("&lt;", 4) ;
      break ;
    case '>' :
      Super::handleAppendUTF8Array ("&gt;", 4) ;
      break ;
    case '&' :
      Super::handleAppendUTF8Array ("&amp;", 5) ;
      break ;
    default :
      Super::handleAppendUTF8Array (& c, 1) ;
      break ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void HTMLFileWrite::handleAppendCharacter (const utf32 inCharacter) {
  switch (UNICODE_VALUE (inCharacter)) {
  case '<' :
    Super::handleAppendUTF8Array ("&lt;", 4) ;
    break ;
  case '>' :
    Super::handleAppendUTF8Array ("&gt;", 4) ;
    break ;
  case '&' :
    Super::handleAppendUTF8Array ("&amp;", 5) ;
    break ;
  default :
    Super::handleAppendCharacter (inCharacter) ;
    break ;
  }
}

//--------------------------------------------------------------------------------------------------
//                 Comments as a table                   
//--------------------------------------------------------------------------------------------------

void HTMLFileWrite::appendCppTitleComment (const String & inCommentString,
                                           const String & inTableStyleClass) {
  appendRawData ("<table") ;
  if (inTableStyleClass.length () > 0) {
    appendRawData (" class=\"") ;
    appendRawData (inTableStyleClass.cString ()) ;
    appendRawData ("\"") ;
  }
  appendRawData ("><tr><td>\n") ;
  appendString (inCommentString) ;
  appendRawData ("\n</td></tr></table>\n") ;
}

//--------------------------------------------------------------------------------------------------

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  AC_OutputStream : an abstract output stream class                                                                  *
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

#include "streams/AC_OutputStream.h"
#include "strings/C_String.h"
#include "strings/unicode_character_cpp.h"
#include "strings/unicode_string_routines.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include <string.h>
#include <ctype.h>

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_OutputStream::AC_OutputStream (void) :
mIndentation (0),
mStartingLine (true) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_OutputStream::~AC_OutputStream (void) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::flush (void) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCString (const char * inCstring) {
  if (inCstring != NULL) {
    genericCharArrayOutput (inCstring, (int32_t) (strlen (inCstring) & UINT32_MAX)) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::genericCharArrayOutput (const char * inCharArray, const int32_t inArrayCount) {
  if (mIndentation == 0) {
    performActualCharArrayOutput (inCharArray, inArrayCount) ;
  }else if (inArrayCount > 0) {
    for (int32_t i=0 ; i<inArrayCount ; i++) {
      if (mStartingLine) {
        for (int32_t j=0 ; j<mIndentation ; j++) {
          performActualCharArrayOutput (" ", 1) ;
        }
      }
      performActualCharArrayOutput (& (inCharArray [i]) , 1) ;
      mStartingLine = inCharArray [i] == '\n' ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::genericUnicodeArrayOutput (const utf32 * inCharArray, const int32_t inArrayCount) {
  if (mIndentation == 0) {
    performActualUnicodeArrayOutput (inCharArray, inArrayCount) ;
  }else if (inArrayCount > 0) {
    for (int32_t i=0 ; i<inArrayCount ; i++) {
      if (mStartingLine) {
        for (int32_t j=0 ; j<mIndentation ; j++) {
          const utf32 space [1] = {TO_UNICODE (' ')} ;
          performActualUnicodeArrayOutput (space, 1) ;
        }
      }
      performActualUnicodeArrayOutput (& (inCharArray [i]) , 1) ;
      mStartingLine = UNICODE_VALUE (inCharArray [i]) == '\n' ;
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << C_String
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendString (const C_String inString) {
  genericUnicodeArrayOutput (inString.utf32String (HERE), inString.length ()) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_OutputStream & AC_OutputStream::operator << (const C_String inString) {
  genericUnicodeArrayOutput (inString.utf32String (HERE), inString.length ()) ;
  return *this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << char *
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_OutputStream & AC_OutputStream::operator << (const char * inCstring) {
  appendCString (inCstring) ;
  return *this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCString (const char * inCstring, const int32_t inCount) {
  genericCharArrayOutput (inCstring, inCount) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

AC_OutputStream & AC_OutputStream::operator << (const utf32 * inUTF32String) {
  genericUnicodeArrayOutput (inUTF32String, utf32_strlen (inUTF32String)) ;
  return * this ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendUTF32String (const utf32 * inUTF32String) {
  genericUnicodeArrayOutput (inUTF32String, utf32_strlen (inUTF32String)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendUTF32LiteralStringConstant (const C_String & inString) {
  const utf32 * str = inString.utf32String (HERE) ;
  appendUnicodeCharacter (TO_UNICODE ('{') COMMA_HERE) ;
  while (UNICODE_VALUE (* str) != 0) {
    const utf32 c = * str ;
    appendCString ("\n  TO_UNICODE (") ;
    if (isprint ((int) UNICODE_VALUE (c))) {
      appendCLiteralCharConstant (c) ;
    }else{
      appendUnsigned (UNICODE_VALUE (c)) ;
    }
    appendCString ("),") ;
    str ++ ;
  }
  appendCString ("\n  TO_UNICODE (0)\n}") ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << char
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendUnicodeCharacter (const utf32 inUnicodeCharacter COMMA_UNUSED_LOCATION_ARGS) {
  genericUnicodeArrayOutput (& inUnicodeCharacter, 1) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << double
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendDouble (const double inValue) {
  char s [40] = "" ;
  snprintf (s, 40, "%g", inValue) ;
  genericCharArrayOutput (s, (int32_t) (strlen (s) & UINT32_MAX)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark uint64_t
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  WARNING: in gcc 3.x printf for 64-bit integer crashes!                                                             *
//  So we use an auxiliary function printfUINT64 and only 32-bit printing                                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void printfUINT64 (char ioString [],
                          const uint64_t inValue,
                          int32_t & ioLength) {
  const uint64_t quotient = inValue / 10UL ;
  if (quotient != 0) {
    printfUINT64 (ioString, quotient, ioLength) ;
  }
  const uint32_t v = (uint32_t) ((inValue % 10UL) & UINT32_MAX) ;
  ioString [ioLength] = (char) (('0' + v) & 255) ;
  ioLength ++ ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendUnsigned (const uint64_t inValue) {
  char s [30] = "" ;
  int32_t length = 0 ;
  printfUINT64 (s, inValue, length) ;
  s [length] = '\0' ;
  MF_Assert (length < 30, "C string overflow", 0, 0) ;
  genericCharArrayOutput (s, length) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void printfUINT64Hex (char ioString [],
                             const uint64_t inValue,
                             int & ioLength) {
  const uint64_t quotient = inValue >> 4 ;
  if (quotient != 0) {
    printfUINT64Hex (ioString, quotient, ioLength) ;
  }
  const uint32_t v = (uint32_t) (inValue & 15UL) ;
  sprintf (& ioString [ioLength], "%X", v) ;
  ioLength ++ ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendUnsignedHex16 (const uint64_t inValue) {
  int length = 0 ;
  char s [32] ;
  printfUINT64Hex (s, (uint64_t) inValue, length) ;
  MF_Assert (length < 32, "C string overflow", 0, 0) ;
  genericCharArrayOutput (s, length) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << int64_t
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendSigned (const int64_t inValue) {
  int32_t length = 0 ;
  char s [30] = "" ;
  if (inValue >= 0) {
    printfUINT64 (s, (uint64_t) inValue, length) ;
  }else if (inValue == INT64_MIN) {
    s [0] = '-' ;
    length = 1 ;
    printfUINT64 (s, (uint64_t) INT64_MIN, length) ;
  }else{
    s [0] = '-' ;
    length = 1 ;
    printfUINT64 (s, (uint64_t) (- inValue), length) ;
  }
  s [length] = '\0' ;
  MF_Assert (length < 30, "C string overflow", 0, 0) ;
  genericCharArrayOutput (s, length) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Bool
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendBool (const bool inValue) {
  appendCString (inValue ? "true" : "false") ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << uint32_t
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendUnsignedWithZeroFill (const uint64_t inValue, const uint32_t inWidth) {
  char s [32] = "" ;
  snprintf (s, 31, "%0*llu", inWidth, (unsigned long long) inValue) ;
  appendCString (s) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendUnsignedHex (const uint64_t inValue) {
  char s [32] = "" ;
  snprintf (s, 31, "%llX", (unsigned long long) inValue) ;
  genericCharArrayOutput (s, (int32_t) (strlen (s) & UINT32_MAX)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendUnsignedHex2 (const uint64_t inValue) {
  char s [32] = "" ;
  snprintf (s, 31, "%02llX", (unsigned long long) (inValue & 0xFF)) ;
  genericCharArrayOutput (s, (int32_t) (strlen (s) & UINT32_MAX)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendUnsignedHex4 (const uint64_t inValue) {
  char s [32] = "" ;
  snprintf (s, 31, "%04llX", (unsigned long long) (inValue & 0xFFFF)) ;
  genericCharArrayOutput (s, (int32_t) (strlen (s) & UINT32_MAX)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendUnsignedHex8 (const uint64_t inValue) {
  char s [32] = "" ;
  snprintf (s, 31, "%08llX", (unsigned long long) (inValue)) ;
  genericCharArrayOutput (s, (int32_t) (strlen (s) & UINT32_MAX)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << void *
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendPointer (const void * inValue) {
  char s [30] = "" ;
  snprintf (s, 29, "%p", inValue) ;
  genericCharArrayOutput (s, (int32_t) (strlen (s) & UINT32_MAX)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendSpaces (const int32_t inSpaceCount) {
  for (int32_t i=0 ; i<inSpaceCount ; i++) {
    appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::writeStringMultiple (const C_String & inString, const int32_t inRepeatCount) {
  for (int32_t i=0 ; i<inRepeatCount ; i++) {
    *this << inString ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                          Comments                                                                                   *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const int32_t kCommentMaxLength = 119 ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendHyphenLineCommentWithoutExtraBlankLine (const C_String & inLineCommentPrefix) {
  *this << inLineCommentPrefix ;
  for (int32_t i=2 ; i<kCommentMaxLength ; i++) {
    *this << "-" ;
  }
  *this << "*\n";
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendTitleComment (const C_String & inLineCommentPrefix,
                                          const C_String & inCommentString) {
  appendHyphenLineCommentWithoutExtraBlankLine (inLineCommentPrefix) ;
  appendSpaceLineComment (inLineCommentPrefix) ;
  appendCenterJustifiedComment (inLineCommentPrefix, inCommentString) ;
  appendSpaceLineComment (inLineCommentPrefix) ;
  appendCppHyphenLineComment (inLineCommentPrefix) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendComment (const C_String & inLineCommentPrefix,
                                     const C_String & inCommentString) {
  *this << inLineCommentPrefix << " " << inCommentString << "\n" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCenterJustifiedComment (const C_String & inLineCommentPrefix,
                                                    const C_String & inCommentString) {
  const int32_t commentLength = inCommentString.length () ;
  const int32_t n = (kCommentMaxLength - 3 - commentLength) / 2 ;
  
  *this << inLineCommentPrefix ;
  for (int32_t i=0 ; i<n ; i++) {
   *this << " " ;
  }
  *this << inCommentString ;
  const int32_t fin = kCommentMaxLength - n - commentLength - 2 ;
  for (int32_t j=0 ; j<=fin ; j++) {
    *this << " " ;
  }
  *this << "\n" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendSpaceLineComment (const C_String & inLineCommentPrefix) {
  *this << inLineCommentPrefix ;
  for (int32_t i=1 ; i<kCommentMaxLength ; i++) {
    *this << " " ;
  }
  *this << "\n";
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCppHyphenLineComment (const C_String & inLineCommentPrefix) {
  appendHyphenLineCommentWithoutExtraBlankLine (inLineCommentPrefix) ;
  *this << "\n" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                          C Comments                                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::append_C_HyphenLineComment (void) {
  *this << "/*" ;
  for (int32_t i=0 ; i<(kCommentMaxLength-4) ; i++) {
    *this << "-" ;
  }
  *this << "*/\n" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::append_C_SpaceLineComment (void) {
  *this << "/*" ;
  for (int32_t i=0 ; i<(kCommentMaxLength-4) ; i++) {
    *this << " " ;
  }
  *this << "*/\n" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                        C++ Comments                                                                                 *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCppHyphenLineCommentWithoutExtraBlankLine (void) {
  appendHyphenLineCommentWithoutExtraBlankLine ("//") ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCppTitleComment (const C_String & inCommentString) {
  appendTitleComment ("//", inCommentString) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCppTitleComment (const char * inCommentString) {
  appendTitleComment ("//", inCommentString) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCppComment (const C_String & inCommentString) {
  appendComment ("//", inCommentString) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCppCenterJustifiedComment (const C_String & inCommentString) {
  appendCenterJustifiedComment ("//", inCommentString) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCppSpaceLineComment (void) {
  appendSpaceLineComment ("//") ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCppHyphenLineComment (void) {
  appendCppHyphenLineComment ("//") ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void internalWriteCstringConstantWithoutDelimiters (AC_OutputStream & ioStream,
                                                           const C_String & inString,
                                                           const int32_t inStringLength,
                                                           const int32_t inLineMaxLength) {
  int32_t currentColumn = 0 ;
  for (int32_t i=0 ; i<inStringLength ; i++) {
    if (currentColumn > inLineMaxLength) {
      ioStream << "\"\n  \"" ;
      currentColumn = 0 ;
    }
    currentColumn ++ ;
    const utf32 c = inString (i COMMA_HERE) ;
    switch (UNICODE_VALUE (c)) {
    case '\0' :
      break ;
    case '\a' :
      ioStream << "\\a" ;
      break ;
    case '\b' :
      ioStream << "\\b" ;
      break ;
    case '\f' :
      ioStream << "\\f" ;
      break ;
    case '\n' :
      ioStream << "\\n" ;
      if (i < (inStringLength - 1)) {
        ioStream << "\"\n  \"" ;
        currentColumn = 1 ;
      }
      break ;
    case '\r' :
      ioStream << "\\r" ;
      break ;
    case '\t' :
      ioStream << "\\t" ;
      break ;
    case '\v' :
      ioStream << "\\v" ;
      break ;
    case '\\' :
      ioStream << "\\\\" ;
      break ;
    case '\"' :
      ioStream << "\\\"" ;
      break ;
    case '\?' :
      ioStream << "\\?" ;
      break ;
    default :
      if ((UNICODE_VALUE (c) >= ' ') && (UNICODE_VALUE (c) < 127)) {
        ioStream.appendUnicodeCharacter (c COMMA_HERE) ;
      }else{
        char buffer [5] ;
        const int32_t n = UTF8StringFromUTF32Character (c, buffer) ;
        for (int32_t j=0 ; j<n ; j++) {
          ioStream << "\\x" ;
          ioStream.appendUnsignedHex2 ((uint32_t) buffer [j]) ;
          ioStream << "\"\""  ;
        }
      }
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void internalWriteCstringConstant (AC_OutputStream & ioStream,
                                          const C_String & inString,
                                          const int32_t inStringLength,
                                          const int32_t inLineMaxLength) {
  ioStream << "\"" ;
  internalWriteCstringConstantWithoutDelimiters (ioStream, inString, inStringLength, inLineMaxLength) ;
  ioStream << "\"" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCLiteralStringConstant (const C_String & inString) {
  internalWriteCstringConstant (*this, inString, inString.length (), 150) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCLiteralStringConstantWithoutDelimiters (const C_String & inString) {
  internalWriteCstringConstantWithoutDelimiters (*this, inString, inString.length (), 150) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCLiteralStringConstant (const C_String & inString,
                                                    const int32_t inLineMaxLength) {
  internalWriteCstringConstant (*this, inString, inString.length (), inLineMaxLength) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendCLiteralCharConstant (const utf32 c) {
  switch (UNICODE_VALUE (c)) {
  case '\0' :
    *this << ("'\\0'") ;
    break ;
  case '\a' :
    *this << ("'\\a'") ;
    break ;
  case '\b' :
    *this << ("'\\b'") ;
    break ;
  case '\f' :
    *this << ("'\\f'") ;
    break ;
  case '\n' :
    *this << ("'\\n'") ;
    break ;
  case '\r' :
    *this << ("'\\r'") ;
    break ;
  case '\t' :
    *this << ("'\\t'") ;
    break ;
  case '\v' :
    *this << ("'\\v'") ;
    break ;
  case '\\' :
    *this << ("'\\\\'") ;
    break ;
  case '\'' :
    *this << ("'\\''") ;
    break ;
  case '\"' :
    *this << ("'\\\"'") ;
    break ;
  case '\?' :
    *this << ("'\\\?'") ;
    break ;
  default :
    if ((UNICODE_VALUE (c) >= ' ') && (UNICODE_VALUE (c) <= '~')) {
      appendCString ("'") ;
      appendUnicodeCharacter (c COMMA_HERE) ;
      appendCString ("'") ;
    }else{
      appendUnsigned (UNICODE_VALUE (c)) ;
    }
    break ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void AC_OutputStream::appendFileHeaderComment (const C_String & inLineCommentPrefix,
                                               const C_String & inTitle,
                                               const C_String & in_generatedBy_subtitle,
                                               const bool inIncludeLGPLtext) {
  if (inLineCommentPrefix.length () > 0) {
    appendCppHyphenLineCommentWithoutExtraBlankLine () ;
    appendCppSpaceLineComment () ;
    appendCppCenterJustifiedComment (inTitle) ;
    C_String subTitle ;
    if (in_generatedBy_subtitle.length () != 0) {
      subTitle << "Generated by " << in_generatedBy_subtitle ;
      appendCppCenterJustifiedComment (subTitle) ;
      subTitle.setLengthToZero () ;
    }
    C_DateTime today ;
    subTitle << today ;
    appendCppCenterJustifiedComment (subTitle) ;
    if (inIncludeLGPLtext) {
      appendCppSpaceLineComment () ;
      *this << inLineCommentPrefix << " This file is free software; you can redistribute it and/or modify it                                              *\n"
            << inLineCommentPrefix << " under the terms of the GNU Lesser General Public License as published                                             *\n"
            << inLineCommentPrefix << " by the Free Software Foundation; either version 2 of the License, or                                              *\n"
            << inLineCommentPrefix << " (at your option) any later version.                                                                               *\n"
            << inLineCommentPrefix << "                                                                                                                   *\n"
            << inLineCommentPrefix << " This file is distributed in the hope it will be useful, but WITHOUT                                               *\n"
            << inLineCommentPrefix << " ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or                                             *\n"
            << inLineCommentPrefix << " FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public                                               *\n"
            << inLineCommentPrefix << " License for more details.                                                                                         *\n"
            << inLineCommentPrefix << "                                                                                                                   *\n"
            << inLineCommentPrefix << " You should have received a copy of the GNU General Public License along                                           *\n"
            << inLineCommentPrefix << " with this program; if not, write to the Free Software Foundation                                                  *\n"
            << inLineCommentPrefix << " Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA                                                    *\n" ;
    }
    appendCppSpaceLineComment () ;
    appendCppHyphenLineComment () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cStringWithUnsigned
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String cStringWithUnsigned (const uint64_t inValue) {
  C_String result ;
  result.appendUnsigned (inValue) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cHexStringWithUnsigned
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String cHexStringWithUnsigned (const uint64_t inValue) {
  C_String result = "0x" ;
  result.appendUnsignedHex16 (inValue) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cStringWithSigned
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String cStringWithSigned (const int64_t inValue) {
  C_String result ;
  result.appendSigned (inValue) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cStringWithCharacter
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String cStringWithCharacter (const char inValue) {
  C_String result ;
  result.appendUnicodeCharacter (TO_UNICODE ((uint32_t) inValue) COMMA_HERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cStringWithUnicodeCharacter
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String cStringWithUnicodeCharacter (const utf32 inValue) {
  C_String result ;
  result.appendUnicodeCharacter (inValue COMMA_HERE) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cStringWithPointer
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String cStringWithPointer (const void * inValue) {
  C_String result ;
  result.appendPointer (inValue) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cStringWithDouble
#endif

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_String cStringWithDouble (const double inValue) {
  C_String result ;
  result.appendDouble (inValue) ;
  return result ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

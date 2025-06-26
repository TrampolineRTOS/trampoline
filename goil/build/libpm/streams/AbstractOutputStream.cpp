//--------------------------------------------------------------------------------------------------
//
//  AbstractOutputStream : an abstract output stream class
//
//  This file is part of libpm library
//
//  Copyright (C) 1997, ..., 2024 Pierre Molinaro.
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

#include "AbstractOutputStream.h"
#include "String-class.h"
#include "DateTime.h"
#include "unicode_character_cpp.h"

//--------------------------------------------------------------------------------------------------

#include <string.h>
#include <ctype.h>

#define __STDC_FORMAT_MACROS // This is required for GCC for windows
#include <inttypes.h>

//--------------------------------------------------------------------------------------------------

AbstractOutputStream::AbstractOutputStream (void) :
mIndentation (0),
mStartingLine (true) {
}

//--------------------------------------------------------------------------------------------------

AbstractOutputStream::~AbstractOutputStream (void) {
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendCString (const char * inCstring) {
  if (inCstring != nullptr) {
    performAppendCString (inCstring, int32_t (strlen (inCstring))) ;
  }
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::performAppendCString (const char * inCharArray, const int32_t inArrayCount) {
  if (mIndentation == 0) {
    handleAppendUTF8Array (inCharArray, inArrayCount) ;
  }else if (inArrayCount > 0) {
    for (int32_t i=0 ; i<inArrayCount ; i++) {
      if (mStartingLine) {
        for (int32_t j=0 ; j<mIndentation ; j++) {
          handleAppendUTF8Array (" ", 1) ;
        }
      }
      handleAppendUTF8Array (& inCharArray [i], 1) ;
      mStartingLine = inCharArray [i] == '\n' ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::performAppendCharacter (const utf32 inCharacter) {
  if (mIndentation == 0) {
    handleAppendCharacter (inCharacter) ;
  }else{
    if (mStartingLine) {
      for (int32_t j=0 ; j<mIndentation ; j++) {
        handleAppendCharacter (TO_UNICODE (' ')) ;
      }
    }
    handleAppendCharacter (inCharacter) ;
    mStartingLine = UNICODE_VALUE (inCharacter) == '\n' ;
  }
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendNewLine (void) {
  appendCString ("\n") ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendString (const String inString) {
  for (int32_t i = 0 ; i < inString.length () ; i++) {
    performAppendCharacter (inString.charAtIndex (i COMMA_HERE)) ;
  }
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendString (const std::initializer_list <utf32> & inSource) {
  for (auto it = inSource.begin () ; it != inSource.end () ; it++) {
    performAppendCharacter (*it) ;
  }
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendString (const char * inCString, const int32_t inCount) {
  performAppendCString (inCString, inCount) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendUTF32LiteralStringConstant (const String inString,
                                                             const bool inAppendZeroTerminator) {
  appendChar (TO_UNICODE ('{')) ;
  for (int32_t i=0 ; i < inString.length () ; i++) {
    const utf32 c = inString.charAtIndex (i COMMA_HERE) ;
    appendCString ("\n  TO_UNICODE (") ;
    if (isprint (int (UNICODE_VALUE (c)))) {
      appendStringAsCLiteralCharConstant (c) ;
    }else{
      appendUnsigned (UNICODE_VALUE (c)) ;
    }
    appendCString ("),") ;
  }
  if (inAppendZeroTerminator) {
    appendCString ("\n  TO_UNICODE (0)") ;
  }
  appendCString ("\n}") ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendASCIIChar (const char inValue) {
  appendChar (TO_UNICODE (uint32_t (inValue))) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendChar (const utf32 inUnicodeCharacter) {
  performAppendCharacter (inUnicodeCharacter) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendDouble (const double inValue) {
  char s [40] ;
  snprintf (s, 40, "%g", inValue) ;
  appendCString (s) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendUnsigned (const uint64_t inValue) {
  char s [32] ;
  snprintf (s, 31, "%" PRIu64, inValue) ;
  appendCString (s) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendUnsignedHex16 (const uint64_t inValue) {
  char s [32] ;
  snprintf (s, 31, "%016" PRIX64, inValue) ;
  appendCString (s) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendSigned (const int64_t inValue) {
  char s [32] ;
  snprintf (s, 31, "%" PRId64, inValue) ;
  appendCString (s) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendBool (const bool inValue) {
  appendCString (inValue ? "true" : "false") ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendUnsignedWithZeroFill (const uint64_t inValue, const uint32_t inWidth) {
  char s [32] ;
  snprintf (s, 31, "%" PRIu64, inValue) ;
  for (uint32_t i = uint32_t (strlen (s)) ; i < inWidth ; i++) {
    appendCString (" ") ;
  }
  appendCString (s) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendUnsignedHex (const uint64_t inValue) {
  char s [32] ;
  snprintf (s, 31, "%" PRIX64, inValue) ;
  appendCString (s) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendUnsigned0xHex (const uint64_t inValue) {
  char s [32] ;
  snprintf (s, 31, "0x%" PRIX64, inValue) ;
  appendCString (s) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendUnsignedHex2 (const uint64_t inValue) {
  char s [32] ;
  snprintf (s, 31, "%02" PRIX64, inValue & 0xFF) ;
  appendCString (s) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendUnsignedHex4 (const uint64_t inValue) {
  char s [32] ;
  snprintf (s, 31, "%04" PRIX64, inValue & 0xFFFF) ;
  appendCString (s) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendUnsignedHex8 (const uint64_t inValue) {
  char s [32] ;
  snprintf (s, 31, "%08" PRIX64, inValue) ;
  appendCString (s) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendPointer (const void * inValue) {
  char s [32] ;
  snprintf (s, 29, "%p", inValue) ;
  appendCString (s) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendSpaces (const int32_t inSpaceCount) {
  for (int32_t i=0 ; i<inSpaceCount ; i++) {
    appendChar (TO_UNICODE (' ')) ;
  }
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendStringMultiple (const String & inString,
                                                 const int32_t inRepeatCount) {
  for (int32_t i=0 ; i<inRepeatCount ; i++) {
    appendString (inString) ;
  }
}

//--------------------------------------------------------------------------------------------------
//                          Comments
//--------------------------------------------------------------------------------------------------

static const int32_t kCommentMaxLength = 99 ;

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendHyphenLineCommentWithoutExtraBlankLine (const char * inLineCommentPrefix) {
  appendCString (inLineCommentPrefix) ;
  for (int32_t i=1 ; i<kCommentMaxLength ; i++) {
    appendCString ("-") ;
  }
  appendCString ("\n") ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendTitleComment (const char * inLineCommentPrefix,
                                               const String & inCommentString) {
  appendHyphenLineCommentWithoutExtraBlankLine (inLineCommentPrefix) ;
  appendSpaceLineComment (inLineCommentPrefix) ;
  appendCenterJustifiedComment (inLineCommentPrefix, inCommentString) ;
  appendSpaceLineComment (inLineCommentPrefix) ;
  appendHyphenLineComment (inLineCommentPrefix) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendComment (const char * inLineCommentPrefix,
                                          const String & inCommentString) {
  appendCString (inLineCommentPrefix) ;
  appendCString (" ") ;
  appendString (inCommentString) ;
  appendCString ("\n") ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendCenterJustifiedComment (const char * inLineCommentPrefix,
                                                         const String & inCommentString) {
  const int32_t commentLength = inCommentString.length () ;
  const int32_t n = (kCommentMaxLength - 3 - commentLength) / 2 ;

  appendCString (inLineCommentPrefix) ;
  for (int32_t i=0 ; i<n ; i++) {
   appendCString (" ") ;
  }
  appendString (inCommentString) ;
  const int32_t fin = kCommentMaxLength - n - commentLength - 2 ;
  for (int32_t j=0 ; j<=fin ; j++) {
    appendCString (" ") ;
  }
  appendCString ("\n") ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendSpaceLineComment (const char * inLineCommentPrefix) {
  appendCString (inLineCommentPrefix) ;
  appendCString ("\n") ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendHyphenLineComment (const char * inLineCommentPrefix) {
  appendHyphenLineCommentWithoutExtraBlankLine (inLineCommentPrefix) ;
  appendCString ("\n") ;
}

//--------------------------------------------------------------------------------------------------
//                          C Comments
//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::append_C_HyphenLineComment (void) {
  appendCString ("/*") ;
  for (int32_t i=0 ; i<(kCommentMaxLength-4) ; i++) {
    appendCString ("-") ;
  }
  appendCString ("*/\n") ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::append_C_SpaceLineComment (void) {
  appendCString ("/*") ;
  for (int32_t i=0 ; i<(kCommentMaxLength-4) ; i++) {
    appendCString (" ") ;
  }
  appendCString ("*/\n") ;
}

//--------------------------------------------------------------------------------------------------
//                        C++ Comments
//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendCppHyphenLineCommentWithoutExtraBlankLine (void) {
  appendHyphenLineCommentWithoutExtraBlankLine ("//") ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendCppTitleComment (const String & inCommentString) {
  appendTitleComment ("//", inCommentString) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendCppComment (const String & inCommentString) {
  appendComment ("//", inCommentString) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendCppCenterJustifiedComment (const String & inCommentString) {
  appendCenterJustifiedComment ("//", inCommentString) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendCppSpaceLineComment (void) {
  appendSpaceLineComment ("//") ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendCppHyphenLineComment (void) {
  appendHyphenLineComment ("//") ;
}

//--------------------------------------------------------------------------------------------------

static void internalWriteCstringConstantWithoutDelimiters (AbstractOutputStream & ioStream,
                                                           const String & inString,
                                                           const int32_t inStringLength,
                                                           const int32_t inLineMaxLength) {
  int32_t currentColumn = 0 ;
  for (int32_t i=0 ; i<inStringLength ; i++) {
    if (currentColumn > inLineMaxLength) {
      ioStream.appendCString ("\"\n  \"") ;
      currentColumn = 0 ;
    }
    currentColumn ++ ;
    const utf32 c = inString.charAtIndex (i COMMA_HERE) ;
    switch (UNICODE_VALUE (c)) {
    case '\0' :
      break ;
    case '\a' :
      ioStream.appendCString ("\\a") ;
      break ;
    case '\b' :
      ioStream.appendCString ("\\b") ;
      break ;
    case '\f' :
      ioStream.appendCString ("\\f") ;
      break ;
    case '\n' :
      ioStream.appendCString ("\\n") ;
      if (i < (inStringLength - 1)) {
        ioStream.appendCString ("\"\n  \"") ;
        currentColumn = 1 ;
      }
      break ;
    case '\r' :
      ioStream.appendCString ("\\r") ;
      break ;
    case '\t' :
      ioStream.appendCString ("\\t") ;
      break ;
    case '\v' :
      ioStream.appendCString ("\\v") ;
      break ;
    case '\\' :
      ioStream.appendCString ("\\\\") ;
      break ;
    case '\"' :
      ioStream.appendCString ("\\\"") ;
      break ;
    default :
      if ((UNICODE_VALUE (c) >= ' ') && (UNICODE_VALUE (c) < 127)) {
        ioStream.appendChar (c) ;
      }else{
        char buffer [5] ;
        const int32_t n = UTF8StringFromUTF32Character (c, buffer) ;
        for (int32_t j=0 ; j<n ; j++) {
          ioStream.appendCString ("\\x") ;
          ioStream.appendUnsignedHex2 ((uint32_t) buffer [j]) ;
          ioStream.appendCString ("\"\"")  ;
        }
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

static void internalWriteCstringConstant (AbstractOutputStream & ioStream,
                                          const String & inString,
                                          const int32_t inStringLength,
                                          const int32_t inLineMaxLength) {
  ioStream.appendCString ("\"") ;
  internalWriteCstringConstantWithoutDelimiters (ioStream, inString, inStringLength, inLineMaxLength) ;
  ioStream.appendCString ("\"") ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendStringAsCLiteralStringConstant (const String & inString) {
  internalWriteCstringConstant (*this, inString, inString.length (), 150) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendStringAsCLiteralStringConstantWithoutDelimiters (const String & inString) {
  internalWriteCstringConstantWithoutDelimiters (*this, inString, inString.length (), 150) ;
}

//--------------------------------------------------------------------------------------------------

void AbstractOutputStream::appendStringAsCLiteralCharConstant (const utf32 c) {
  switch (UNICODE_VALUE (c)) {
  case '\0' :
    appendCString ("'\\0'") ;
    break ;
  case '\a' :
    appendCString ("'\\a'") ;
    break ;
  case '\b' :
    appendCString ("'\\b'") ;
    break ;
  case '\f' :
    appendCString ("'\\f'") ;
    break ;
  case '\n' :
    appendCString ("'\\n'") ;
    break ;
  case '\r' :
    appendCString ("'\\r'") ;
    break ;
  case '\t' :
    appendCString ("'\\t'") ;
    break ;
  case '\v' :
    appendCString ("'\\v'") ;
    break ;
  case '\\' :
    appendCString ("'\\\\'") ;
    break ;
  case '\'' :
    appendCString ("'\\''") ;
    break ;
  case '\"' :
    appendCString ("'\\\"'") ;
    break ;
  case '\?' :
    appendCString ("'\\\?'") ;
    break ;
  default :
    if ((UNICODE_VALUE (c) >= ' ') && (UNICODE_VALUE (c) <= '~')) {
      appendCString ("'") ;
      appendChar (c) ;
      appendCString ("'") ;
    }else{
      appendUnsigned (UNICODE_VALUE (c)) ;
    }
    break ;
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark stringWith...
#endif

//--------------------------------------------------------------------------------------------------

String stringWithUnsigned (const uint64_t inValue) {
  String result ;
  result.appendUnsigned (inValue) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

String stringWithUnsigned0xHex (const uint64_t inValue) {
  String s ;
  s.appendUnsigned0xHex (inValue) ;
  return s ;
}

//--------------------------------------------------------------------------------------------------

String stringWithSigned (const int64_t inValue) {
  String result ;
  result.appendSigned (inValue) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

String stringWithCharacter (const char inValue) {
  String result ;
  result.appendChar (TO_UNICODE (uint32_t (inValue))) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

String stringWithUnicodeCharacter (const utf32 inValue) {
  String result ;
  result.appendChar (inValue) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

String stringWithPointer (const void * inValue) {
  String result ;
  result.appendPointer (inValue) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

String stringWithDouble (const double inValue) {
  String result ;
  result.appendDouble (inValue) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

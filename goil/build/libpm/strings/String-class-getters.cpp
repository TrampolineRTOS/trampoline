//--------------------------------------------------------------------------------------------------
//
//  String : an implementation of fully dynamic character string
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

#include "MF_MemoryControl.h"
#include "md5.h"
#include "SHA256.h"
#include "SharedObject.h"
#include "unicode_character_cpp.h"
#include "TC_UniqueArray2.h"

//--------------------------------------------------------------------------------------------------

#include <math.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

//--------------------------------------------------------------------------------------------------

#ifndef COMPILE_FOR_WINDOWS
  #error COMPILE_FOR_WINDOWS is undefined
#endif

//--------------------------------------------------------------------------------------------------

#if COMPILE_FOR_WINDOWS == 1
  #include <sys/stat.h>
#endif

#if COMPILE_FOR_WINDOWS == 0
  #include <unistd.h>
#endif

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Getters
#endif

//--------------------------------------------------------------------------------------------------

LineColumnContents String::lineAndColumnFromIndex (const int32_t inIndex) const {
  LineColumnContents result ;
  const int32_t receiverLength = length () ;
  if (inIndex < receiverLength) {
    int32_t lineNumber = 0 ;
    int32_t startOfLineIndex = 0 ;
    int32_t idx = 0 ;
    bool parseLine = true ;
    while ((idx < receiverLength) && parseLine) {
      while ((idx < receiverLength) && parseLine) {
        parseLine = UNICODE_VALUE (charAtIndex (idx COMMA_HERE)) != '\n' ;
        idx += parseLine ;
      }
      if (idx < inIndex) {
        parseLine = true ;
        idx ++ ; // Pass '\n'
        startOfLineIndex = idx ;
        lineNumber ++ ;
      }
    }
  //---
    const int32_t columnNumber = inIndex - startOfLineIndex ;
    const String lineContents = subString (startOfLineIndex, idx - startOfLineIndex) ;
    result = LineColumnContents (lineNumber, columnNumber, lineContents) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

int32_t String::indexFromLineAndColumn (const int32_t inLineNumber,
                                        const int32_t inColumnNumber) const {
  int32_t idx = 0 ;
  int32_t line = 1 ;
  while (line < inLineNumber) {
    while ((idx < length ()) && (UNICODE_VALUE (charAtIndex (idx COMMA_HERE)) != '\n')) {
      idx += 1 ;
    }
    line += 1 ;
  }
  return idx + inColumnNumber ;
}

//--------------------------------------------------------------------------------------------------
//   containsString
//--------------------------------------------------------------------------------------------------

bool String::containsString (const String & inSearchedString) const {
  const int32_t searchedStringLength = inSearchedString.length () ;
  bool contains = searchedStringLength == 0 ;
  if (!contains) {
    const int32_t sourceLength = length () ;
    if (sourceLength != 0) {
      int32_t searchedStringIdx = 0 ;
      for (int32_t i = 0 ; (i < sourceLength) && !contains ; i++) {
        const utf32 c = charAtIndex (i COMMA_HERE) ;
        if (c == inSearchedString.charAtIndex (searchedStringIdx COMMA_HERE)) {
          searchedStringIdx += 1 ;
          contains = searchedStringIdx == searchedStringLength ;
        }else{
          searchedStringIdx = 0 ;
        }
      }
    }
  }
  return contains ;
}

//--------------------------------------------------------------------------------------------------
//   componentsSeparatedByString
//--------------------------------------------------------------------------------------------------

void String::componentsSeparatedByString (const String & inSeparatorString,
                                          TC_UniqueArray <String> & outResult) const {
  outResult.removeAllKeepingCapacity () ;
  const int32_t sourceLength = length () ;
  const int32_t splitStringLength = inSeparatorString.length () ;
  if ((sourceLength == 0) || (splitStringLength == 0)) {
    outResult.appendObject (String ()) ;
  }else{
    int32_t splitStringIndex = 0 ;
    String s ;
    for (int32_t i = 0 ; i < sourceLength ; i++) {
      const utf32 c = charAtIndex (i COMMA_HERE) ;
      if (c == inSeparatorString.charAtIndex (splitStringIndex COMMA_HERE)) {
        splitStringIndex += 1 ;
        if (splitStringIndex == splitStringLength) {
          outResult.appendObject (s) ;
          s.removeAll () ;
          splitStringIndex = 0 ;
        }
      }else{
        for (int32_t j = 0 ; j <= splitStringIndex ; j++) {
          s.appendChar (charAtIndex (i + j - splitStringIndex COMMA_HERE)) ;
        }
        splitStringIndex = 0 ;
      }
    }
    outResult.appendObject (s) ;
  }
}

//--------------------------------------------------------------------------------------------------
//   componentsJoinedByString
//--------------------------------------------------------------------------------------------------

String String::componentsJoinedByString (const TC_UniqueArray <String> & inComponentArray,
                                         const String & inSeparator) {
  String result ;
  if (inComponentArray.count () > 0) {
    result.appendString (inComponentArray (0 COMMA_HERE)) ;
    for (int32_t i=1 ; i<inComponentArray.count () ; i++) {
      result.appendString (inSeparator) ;
      result.appendString (inComponentArray (i COMMA_HERE)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   endsWithString
//--------------------------------------------------------------------------------------------------

bool String::endsWithString (const String & inString) const {
  const int32_t offset = length () - inString.length () ;
  bool result = offset >= 0 ;
  for (int32_t i=0 ; (i<inString.length ()) && result ; i++) {
    result = charAtIndex (i + offset COMMA_HERE) == inString.charAtIndex (i COMMA_HERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   stringByReplacingCharacterByString
//--------------------------------------------------------------------------------------------------

//--- Substitute 'inCharacter' by 'inString' ; if the character occurs twice, suppress one

String String::stringByReplacingCharacterByString (const utf32 inCharacter,
                                                   const String & inString) const {
  const int32_t stringLength = length () ;
  String resultingString ;
  bool previousCharIsSubstituteChar = false ;
  for (int32_t i=0 ; i<stringLength ; i++) {
    const utf32 c = (charAtIndex (i COMMA_HERE)) ;
    if (previousCharIsSubstituteChar) {
      if (UNICODE_VALUE (c) == UNICODE_VALUE (inCharacter)) {
        resultingString.appendChar (inCharacter) ;
      }else{
        resultingString.appendString (inString) ;
        resultingString.appendChar (c) ;
      }
      previousCharIsSubstituteChar = false ;
    }else if (UNICODE_VALUE (c) == UNICODE_VALUE (inCharacter)) {
      previousCharIsSubstituteChar = true ;
    }else{
      resultingString.appendChar (c) ;
    }
  }
  if (previousCharIsSubstituteChar) {
    resultingString.appendString (inString) ;
  }
//--- Return
  return resultingString ;
}

//--------------------------------------------------------------------------------------------------
//   stringByReplacingStringByString
//  if inSearchedString is empty, returns the receiver
//--------------------------------------------------------------------------------------------------

String String::stringByReplacingStringByString (const String inSearchedString,
                                                const String inReplacementString,
                                                uint32_t & outReplacementCount) const {
  String result ;
  outReplacementCount = 0 ;
  if (inSearchedString.length () == 0) {
    result = *this ;
  }else{
    const int32_t sourceLength = length () ;
    const int32_t searchedStringLength = inSearchedString.length () ;
    int32_t searchedStringIdx = 0 ;
    for (int32_t i = 0 ; i < sourceLength ; i++) {
      const utf32 c = charAtIndex (i COMMA_HERE) ;
      if (c == inSearchedString.charAtIndex (searchedStringIdx COMMA_HERE)) {
        searchedStringIdx += 1 ;
        if (searchedStringIdx == searchedStringLength) { // Searched string found
          result.appendString (inReplacementString) ;
          searchedStringIdx = 0 ;
        }
      }else{
        for (int32_t j=0 ; j <= searchedStringIdx ; j++) {
          result.appendChar (charAtIndex (i + j - searchedStringIdx COMMA_HERE)) ;
        }
        outReplacementCount += 1 ;
        searchedStringIdx = 0 ;
      }
    }
  //--- Append trailing characters, if any
    for (int32_t j = 0 ; j < searchedStringIdx ; j++) {
      result.appendChar (charAtIndex (sourceLength + j - searchedStringIdx COMMA_HERE)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String String::stringByReplacingStringByString (const String inSearchedString,
                                                const String inReplacementString) const {
  uint32_t unusedReplacementCount = 0 ;
  return stringByReplacingStringByString (inSearchedString, inReplacementString, unusedReplacementCount) ;
}

//--------------------------------------------------------------------------------------------------
//   lastOccurrenceIndexOfChar
//--------------------------------------------------------------------------------------------------

int32_t String::lastOccurrenceIndexOfChar (const utf32 inChar) const {
  int32_t result = length () ;
  bool notFound = true ;
  while ((result > 0) && notFound) {
    result -- ;
    notFound = UNICODE_VALUE (charAtIndex (result COMMA_HERE)) != UNICODE_VALUE (inChar) ;
  }
  if (notFound) {
    result = -1 ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String String::subString (const int32_t inStartIndex,
                          const int32_t inLength) const {
  String s ;
  if (inLength > 0) {
    int32_t last = inStartIndex + inLength ;
    const int32_t receiver_length = length () ;
    if (last > receiver_length) {
      last = receiver_length ;
    }
    for (int32_t i=inStartIndex ; i<last ; i++) {
      s.appendChar (charAtIndex (i COMMA_HERE)) ;
    }
  }
  return s ;
}

//--------------------------------------------------------------------------------------------------

String String::stringByCapitalizingFirstCharacter (void) const {
  String s ;
  const int32_t receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  if (receiver_length > 0) {
    s.appendChar (unicodeToUpper (charAtIndex (0 COMMA_HERE))) ;
    for (int32_t i=1 ; i<receiver_length ; i++) {
      s.appendChar (charAtIndex (i COMMA_HERE)) ;
    }
  }
  return s ;
}

//--------------------------------------------------------------------------------------------------

String String::lowercaseString (void) const {
  String s ;
  const int32_t receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  for (int32_t i=0 ; i<receiver_length ; i++) {
    s.appendChar (unicodeToLower (charAtIndex (i COMMA_HERE))) ;
  }
  return s ;
}

//--------------------------------------------------------------------------------------------------

String String::stringByTrimmingSeparators (void) const {
  String s ;
  const int32_t receiver_length = length () ;
  s.setCapacity (receiver_length) ;
//--- Trim left
  int32_t idx = 0 ;
  while ((idx < receiver_length) && ((UNICODE_VALUE (charAtIndex (idx COMMA_HERE)) == ' ') || (UNICODE_VALUE (charAtIndex (idx COMMA_HERE)) == '\n'))) {
    idx += 1 ;
  }
//--- Trim and replace
  bool isCurrentlyTrimming = false ;
  while (idx < receiver_length) {
    const utf32 c = charAtIndex (idx COMMA_HERE) ;
    if ((UNICODE_VALUE (c) == ' ') || (UNICODE_VALUE (c) == '\n')) {
      isCurrentlyTrimming = true ;
    }else{
      if (isCurrentlyTrimming) {
        s.appendChar (TO_UNICODE (' ')) ;
        isCurrentlyTrimming = false ;
      }
      s.appendChar (c) ;
    }
    idx += 1 ;
  }
  return s ;
}

//--------------------------------------------------------------------------------------------------

String String::uppercaseString (void) const {
  String s ;
  const int32_t receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  for (int32_t i=0 ; i<receiver_length ; i++) {
    s.appendChar (unicodeToUpper (charAtIndex (i COMMA_HERE))) ;
  }
  return s ;
}

//--------------------------------------------------------------------------------------------------

String String::reversedString (void) const {
  String s = *this ;
  s.reverseStringInPlace () ;
  return s ;
}

//--------------------------------------------------------------------------------------------------

bool String::isUnsignedInteger (void) const {
  bool ok = length () > 0 ;
  for (int32_t i=0 ; (i < length ()) && ok ; i++) {
    const uint32_t c = UNICODE_VALUE (charAtIndex (i COMMA_HERE)) ;
    ok = (c >= '0') && (c <= '9') ;
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

uint32_t String::unsignedIntegerValue (void) const {
  uint32_t result = 0 ;
  bool ok = true ;
  for (int32_t i=0 ; (i < length ()) && ok ; i++) {
    const uint32_t c = UNICODE_VALUE (charAtIndex (i COMMA_HERE)) ;
    ok = (c >= '0') && (c <= '9') ;
    if (ok) {
      result *= 10 ;
      result += c - '0' ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

uint32_t String::currentColumn (void) const {
  uint32_t result = 0 ;
  bool found = false ;
  const int32_t receiver_length = length () ;
  for (int32_t i=receiver_length-1 ; (i>=0) && ! found ; i--) {
    found = UNICODE_VALUE (charAtIndex (i COMMA_HERE)) == '\n' ;
    if (! found) {
      result ++ ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void String::appendSpacesUntilColumn (const uint32_t inColumn) {
  for (uint32_t i=currentColumn () ; i<inColumn ; i++) {
    appendChar (TO_UNICODE (' ')) ;
  }
}

//--------------------------------------------------------------------------------------------------

String String::stringWithRepeatedCharacter (const utf32 inRepeatedCharacter,
                                                const uint32_t inCount) {
  String result ;
  for (uint32_t i=0 ; i<inCount ; i++) {
    result.appendChar (inRepeatedCharacter) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void String::convertToUInt32 (uint32_t & outResult,
                                bool & outOk) const {
  outResult = 0 ;
  outOk = length () > 0 ;
  int32_t idx = 0 ;
  while ((idx < length ()) && outOk) {
    const utf32 c = charAtIndex (idx COMMA_HERE) ;
    idx ++ ;
    const uint32_t r = outResult ;
    outResult = outResult * 10 + (UNICODE_VALUE (c) - '0') ;
    outOk = (UNICODE_VALUE (c) >= '0') && (UNICODE_VALUE (c) <= '9') && (r <= outResult) ;
  }
  if (outOk) {
    outOk = idx == length () ;
  }
}

//--------------------------------------------------------------------------------------------------

void String::convertToUInt64 (uint64_t & outResult,
                                bool & outOk) const {
  outResult = 0 ;
  outOk = length () > 0 ;
  int32_t idx = 0 ;
  while ((idx < length ()) && outOk) {
    const utf32 c = charAtIndex (idx COMMA_HERE) ;
    idx ++ ;
    const uint64_t r = outResult ;
    outResult = outResult * 10 + (UNICODE_VALUE (c) - '0') ;
    outOk = (UNICODE_VALUE (c) >= '0') && (UNICODE_VALUE (c) <= '9') && (r <= outResult) ;
  }
  if (outOk) {
    outOk = idx == length () ;
  }
}

//--------------------------------------------------------------------------------------------------

void String::convertToSInt32 (int32_t & outResult,
                                bool & outOk) const {
  bool isPositive = true ;
  int32_t idx = 0 ;
  if (length () > 0) {
    const utf32 c = charAtIndex (0 COMMA_HERE) ;
    if (UNICODE_VALUE (c) == '-') {
      isPositive = false ;
      idx = 1 ;
    }else if (UNICODE_VALUE (c) == '+') {
      idx = 1 ;
    }
  }
  uint32_t decimalUnsignedValue = 0 ;
  outOk = length () > 0 ;
  while ((idx < length ()) && outOk) {
    const utf32 c = charAtIndex (idx COMMA_HERE) ;
    idx ++ ;
    const uint32_t r = decimalUnsignedValue ;
    decimalUnsignedValue = decimalUnsignedValue * 10 + (UNICODE_VALUE (c) - '0') ;
    outOk = r < decimalUnsignedValue ;
  }
  if (outOk) {
    outOk = idx == length () ;
  }
  if (outOk) {
    if (isPositive) {
      outOk = decimalUnsignedValue <= (uint32_t) INT32_MAX ;
      if (outOk) {
        outResult = (int32_t) decimalUnsignedValue ;
      }
    }else{
      outOk = decimalUnsignedValue <= ((uint32_t) INT32_MAX) + 1 ;
      if (outOk) {
        outResult = - (int32_t) decimalUnsignedValue ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void String::convertToSInt64 (int64_t & outResult,
                                bool & outOk) const {
  bool isPositive = true ;
  int32_t idx = 0 ;
  if (length () > 0) {
    const utf32 c = charAtIndex (0 COMMA_HERE) ;
    if (UNICODE_VALUE (c) == '-') {
      isPositive = false ;
      idx = 1 ;
    }else if (UNICODE_VALUE (c) == '+') {
      idx = 1 ;
    }
  }
  uint64_t decimalUnsignedValue = 0 ;
  outOk = length () > 0 ;
  while ((idx < length ()) && outOk) {
    const utf32 c = charAtIndex (idx COMMA_HERE) ;
    idx ++ ;
    const uint64_t r = decimalUnsignedValue ;
    decimalUnsignedValue = decimalUnsignedValue * 10 + (UNICODE_VALUE (c) - '0') ;
    outOk = r < decimalUnsignedValue ;
  }
  if (outOk) {
    outOk = idx == length () ;
  }
  if (outOk) {
    if (isPositive) {
      outOk = decimalUnsignedValue <= (uint64_t) INT64_MAX ;
      if (outOk) {
        outResult = (int64_t) decimalUnsignedValue ;
      }
    }else{
      outOk = decimalUnsignedValue <= ((uint64_t) INT64_MAX) + 1 ;
      if (outOk) {
        outResult = - (int64_t) decimalUnsignedValue ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

void String::convertToDouble (double & outDoubleValue,
                              bool & outOk) const {
  outDoubleValue = 0.0 ;
  int32_t idx = 0 ;
//--- Sign
  bool positive = true ;
  if (idx < length ()) {
    const utf32 c = charAtIndex (idx COMMA_HERE) ;
    if (UNICODE_VALUE (c) == '-') {
      positive = false ;
      idx ++ ;
    }else if (UNICODE_VALUE (c) == '+') {
      idx ++ ;
    }
  }
//--- Mantissa
  while ((idx < length ()) && isdigit ((int) UNICODE_VALUE (charAtIndex (idx COMMA_HERE)))) {
    outDoubleValue *= 10.0 ;
    outDoubleValue += (double) (UNICODE_VALUE (charAtIndex (idx COMMA_HERE)) - '0') ;
    idx ++ ;
  }
//--- Fractional part
  double divisor = 1.0 ;
  if ((idx < length ()) && (UNICODE_VALUE (charAtIndex (idx COMMA_HERE)) == '.')) { // Dot
    idx ++ ;
    while ((idx < length ()) && isdigit ((int) UNICODE_VALUE (charAtIndex (idx COMMA_HERE)))) {
      divisor *= 10.0 ;
      outDoubleValue *= 10.0 ;
      outDoubleValue += (double) (UNICODE_VALUE (charAtIndex (idx COMMA_HERE)) - '0') ;
      idx ++ ;
    }
  }
  outDoubleValue /= divisor ;
//--- Exponent ?
  if (idx < length ()) {
    switch (UNICODE_VALUE (charAtIndex (idx COMMA_HERE))) {
    case 'E' : case 'e' : case 'd' : case 'D' : {
      idx ++ ;
    //--- Exponent sign
      bool exponentIsPositive = true ;
      if (idx < length ()) {
        const utf32 c = charAtIndex (idx COMMA_HERE) ;
        if (UNICODE_VALUE (c) == '-') {
          exponentIsPositive = false ;
          idx ++ ;
        }else if (UNICODE_VALUE (c) == '+') {
          idx ++ ;
        }
      }
      double exponentValue = 0.0 ;
      while ((idx < length ()) && isdigit ((int) UNICODE_VALUE (charAtIndex (idx COMMA_HERE)))) {
        exponentValue *= 10.0 ;
        exponentValue += (double) (UNICODE_VALUE (charAtIndex (idx COMMA_HERE)) - '0') ;
        idx ++ ;
      }
      outDoubleValue *= ::pow (10.0, exponentIsPositive ? exponentValue : - exponentValue) ;
    }
    break ;
    default :
    break ;
    }
  }
  if (!positive) {
    outDoubleValue = - outDoubleValue ;
  }
//--- Reached end of string ?
  outOk = idx == length () ;
}

//--------------------------------------------------------------------------------------------------

String String::identifierRepresentation (void) const {
  String s ;
  const int32_t receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  for (int32_t i=0 ; i<receiver_length ; i++) {
    const utf32 c = charAtIndex (i COMMA_HERE) ;
    if (isalpha ((int) UNICODE_VALUE (c))) {
      s.appendChar (c) ;
    }else{
      s.appendChar (TO_UNICODE ('_')) ;
      s.appendUnsignedHex (UNICODE_VALUE (c)) ;
      s.appendChar (TO_UNICODE ('_')) ;
    }
  }
  return s ;
}

//--------------------------------------------------------------------------------------------------

String String::nameRepresentation (void) const {
  String s ;
  const int32_t receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  for (int32_t i=0 ; i<receiver_length ; i++) {
    const utf32 c = charAtIndex (i COMMA_HERE) ;
    if (isalnum ((int) UNICODE_VALUE (c))) {
      s.appendChar (c) ;
    }else{
      s.appendChar (TO_UNICODE ('_')) ;
      s.appendUnsignedHex (UNICODE_VALUE (c)) ;
      s.appendChar (TO_UNICODE ('_')) ;
    }
  }
  return s ;
}

//--------------------------------------------------------------------------------------------------

String String::fileNameRepresentation (void) const {
  String s ;
  const int32_t receiverLength = length () ;
  s.setCapacity (receiverLength) ;
  for (int32_t i=0 ; i<receiverLength ; i++) {
    const utf32 c = charAtIndex (i COMMA_HERE) ;
    const int nc = int (UNICODE_VALUE (c)) ;
    if (isdigit (nc) || islower (nc)) {
      s.appendChar (c) ;
    }else if (isupper (nc)) {
      s.appendChar (TO_UNICODE ('+')) ;
      s.appendChar (TO_UNICODE (uint32_t (tolower (nc)))) ;
    }else{
      const uint32_t unicodePoint = UNICODE_VALUE (c) ;
      if (unicodePoint < 0x100) {
        s.appendChar (TO_UNICODE ('-')) ;
        s.appendUnsignedHex (unicodePoint) ;
      }else{
        s.appendChar (TO_UNICODE ('(')) ;
        s.appendUnsignedHex (unicodePoint) ;
        s.appendChar (TO_UNICODE (')')) ;
      }
    }
  }
  return s ;
}

//--------------------------------------------------------------------------------------------------

String String::assemblerRepresentation (void) const {
  String s ;
  const int32_t receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  for (int32_t i=0 ; i<receiver_length ; i++) {
    const utf32 c = charAtIndex (i COMMA_HERE) ;
    if (isalnum ((int) UNICODE_VALUE (c)) || (UNICODE_VALUE (c) == '.')  || (UNICODE_VALUE (c) == '-') || (UNICODE_VALUE (c) == '$')) {
      s.appendChar (c) ;
    }else{
      s.appendChar (TO_UNICODE ('_')) ;
      s.appendUnsignedHex (UNICODE_VALUE (c)) ;
      s.appendChar (TO_UNICODE ('_')) ;
    }
  }
  return s ;
}

//--------------------------------------------------------------------------------------------------

String String::utf8RepresentationEnclosedWithin (const utf32 inCharacter, const bool inEscapeQuestionMark) const {
  String s ;
  const int32_t receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  s.appendChar  (inCharacter) ;
  for (int32_t i=0 ; i<receiver_length ; i++) {
    const utf32 c = charAtIndex (i COMMA_HERE) ;
    if (UNICODE_VALUE (c) == '\\') {
      s.appendChar ('\\') ;
      s.appendChar ('\\') ;
    }else if (UNICODE_VALUE (c) == '\n') {
      s.appendChar ('\\') ;
      s.appendChar ('n') ;
    }else if (UNICODE_VALUE (c) == '\r') {
      s.appendChar ('\\') ;
      s.appendChar ('r') ;
    }else if (inEscapeQuestionMark && (UNICODE_VALUE (c) == '?')) { // Trigraph protection !!!
      s.appendChar ('\\') ;
      s.appendChar ('?') ;
    }else if (c == inCharacter) {
      s.appendChar ('\\') ;
      s.appendChar (inCharacter) ;
    }else{
      s.appendChar (c) ;
    }
  }
  s.appendChar (inCharacter) ;
  return s ;
}

//--------------------------------------------------------------------------------------------------

static String hex4 (const uint32_t inValue) {
  static const uint8_t digit [16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'} ;
  String result = "" ;
  result.appendChar (TO_UNICODE (digit [(inValue >> 12) & 15])) ;
  result.appendChar (TO_UNICODE (digit [(inValue >>  8) & 15])) ;
  result.appendChar (TO_UNICODE (digit [(inValue >>  4) & 15])) ;
  result.appendChar (TO_UNICODE (digit [(inValue >>  0) & 15])) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

static String hex8 (const uint32_t inValue) {
  String result = "" ;
  result.appendString (hex4 (inValue >> 16)) ;
  result.appendString (hex4 (inValue >>  0)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

String String::utf8RepresentationWithUnicodeEscaping (void) const {
  String s ;
  const int32_t receiver_length = length () ;
  s.setCapacity (receiver_length) ;
  s.appendChar  ('\"') ;
  for (int32_t i=0 ; i<receiver_length ; i++) {
    const utf32 c = charAtIndex (i COMMA_HERE) ;
    if (UNICODE_VALUE (c) == '\\') {
      s.appendChar ('\\') ;
      s.appendChar ('\\') ;
    }else if (c == '\"') {
      s.appendChar ('\\') ;
      s.appendChar ('\"') ;
    }else if (UNICODE_VALUE (c) < ' ') {
      s.appendChar ('\\') ;
      s.appendChar ('u') ;
      s.appendString (hex4 (UNICODE_VALUE (c))) ;
    }else if (UNICODE_VALUE (c) < '~') {
      s.appendChar (c) ;
    }else if (UNICODE_VALUE (c) < 0x800) {
      s.appendChar ('\\') ;
      s.appendChar ('u') ;
      s.appendString (hex4 (UNICODE_VALUE (c))) ;
    }else{
      s.appendChar ('\\') ;
      s.appendChar ('U') ;
      s.appendString (hex8 (UNICODE_VALUE (c))) ;
    }
  }
  s.appendChar  ('\"') ;
  return s ;
}

//--------------------------------------------------------------------------------------------------

String String::decodedStringFromRepresentation (bool & outOk) const {
  TC_UniqueArray <String> components ;
  componentsSeparatedByString ("_", components) ;
  String result ;
  outOk = true ;
  for (int32_t i=0 ; i<components.count () ; i++) {
    if ((i & 1) == 0) {
      result.appendString (components (i COMMA_HERE)) ;
    }else{
      uint32_t codePoint = 0 ;
      for (int32_t j=0 ; j<components (i COMMA_HERE).length () ; j++) {
        codePoint *= 16 ;
        const uint32_t c = UNICODE_VALUE (components (i COMMA_HERE).charAtIndex (j COMMA_HERE)) ;
        if ((c >= '0') && (c <= '9')) {
          codePoint += c - '0' ;
        }else if ((c >= 'a') && (c <= 'f')) {
          codePoint += c + 10 - 'a' ;
        }else if ((c >= 'A') && (c <= 'F')) {
          codePoint += c + 10 - 'A' ;
        }else{
          outOk = false ;
        }
      }
      result.appendChar (codePoint) ;
    }
  }
  return outOk ? result : "" ;
}

//--------------------------------------------------------------------------------------------------

String String::HTMLRepresentation (void) const {
  String result ;
  for (int32_t i=0 ; i<length () ; i++) {
    const utf32 c = charAtIndex (i COMMA_HERE) ;
    if (UNICODE_VALUE (c) == '&') {
      result.appendCString ("&amp;") ;
    }else if (UNICODE_VALUE (c) == '"') {
      result.appendCString ("&quot;") ;
    }else if (UNICODE_VALUE (c) == '<') {
      result.appendCString ("&lt;") ;
    }else if (UNICODE_VALUE (c) == '>') {
      result.appendCString ("&gt;") ;
    }else{
      result.appendChar (c) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   String compare
//--------------------------------------------------------------------------------------------------

int32_t String::compareWithCString (const char * const inCString) const {
  const int32_t sourceLength  = length () ;
  const int32_t operandLength = (inCString == nullptr) ? 0 : int32_t (strlen (inCString)) ;
  const int32_t minLength = std::min (sourceLength, operandLength) ;
  int32_t result = 0 ;
  for (int32_t i = 0 ; (i < minLength) && (result == 0) ; i++) {
    const uint32_t left  = UNICODE_VALUE (charAtIndex (i COMMA_HERE)) ;
    const uint32_t right = uint32_t (inCString [i]) ;
    if (left < right) {
      result = -1 ;
    }else if (left > right) {
      result = 1 ;
    }
  }
  if (result == 0) {
    if (sourceLength < operandLength) {
      result = -1 ;
    }else if (sourceLength > operandLength) {
      result = 1 ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

int32_t String::compare (const String & inString) const {
  int32_t result = 0 ;
  const int32_t minLength = std::min (length (), inString.length ()) ;
  for (int32_t i=0 ; (i < minLength) && (result == 0) ; i++) {
    const uint32_t left  = UNICODE_VALUE (charAtIndex (i COMMA_HERE)) ;
    const uint32_t right = UNICODE_VALUE (inString.charAtIndex (i COMMA_HERE)) ;
    if (left < right) {
      result = -1 ;
    }else if (left > right) {
      result = 1 ;
    }
  }
  if (result == 0) {
    if (length () < inString.length ()) {
      result = -1 ;
    }else if (length () > inString.length ()) {
      result = 1 ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

int32_t String::compareWithInitializerList (const std::initializer_list <utf32> & inString) const {
  const int32_t operandLength = int32_t (inString.size ()) ;
  int32_t result = 0 ;
  if (length () < operandLength) {
    result = -1 ;
  }else if (length () > operandLength) {
    result = 1 ;
  }else{
    int32_t i = 0 ;
    for (auto it = inString.begin () ; (it != inString.end ()) && (result == 0) ; it++) {
      const uint32_t left = UNICODE_VALUE (charAtIndex (i COMMA_HERE)) ;
      i += 1 ;
      const uint32_t right = UNICODE_VALUE (*it) ;
      if (left < right) {
        result = -1 ;
      }else if (left > right) {
        result = 1 ;
      }
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

int32_t String::compareStringByLength (const String & inString) const {
  const int32_t sourceLength = length () ;
  const int32_t operandLength = inString.length () ;
  int32_t result = 0 ;
  if (sourceLength < operandLength) {
    result = -1 ;
  }else if (sourceLength > operandLength) {
    result = 1 ;
  }else{
    for (int32_t i=0 ; (i < length ()) && (result == 0) ; i++) {
      const uint32_t left = UNICODE_VALUE (charAtIndex (i COMMA_HERE)) ;
      const uint32_t right = UNICODE_VALUE (inString.charAtIndex (i COMMA_HERE)) ;
      if (left < right) {
        result = -1 ;
      }else if (left > right) {
        result = 1 ;
      }
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   pathExtension
//--------------------------------------------------------------------------------------------------

String String::pathExtension (void) const {
  int32_t receiver_length = length ();
//--- Suppress training '/'
  while ((receiver_length > 1) && (UNICODE_VALUE (charAtIndex (receiver_length - 1 COMMA_HERE)) == '/')) {
    receiver_length -= 1 ;
  }
//--- Search last '.'
  bool found = false ;
  int32_t lastOccurrenceIndex = receiver_length ;
  while ((lastOccurrenceIndex > 0) && ! found) {
    lastOccurrenceIndex -= 1 ;
    found = UNICODE_VALUE (charAtIndex (lastOccurrenceIndex COMMA_HERE)) == '.' ;
  }
  String result ;
  if (found && (lastOccurrenceIndex < (receiver_length - 1))) {
    result = subString (lastOccurrenceIndex + 1, receiver_length - 1 - lastOccurrenceIndex) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   stringByDeletingPathExtension
//--------------------------------------------------------------------------------------------------

String String::stringByDeletingPathExtension (void) const {
  int32_t receiver_length = length ();
//--- Suppress training '/'
  while ((receiver_length > 1) && (UNICODE_VALUE (charAtIndex (receiver_length - 1 COMMA_HERE)) == '/')) {
    receiver_length -= 1 ;
  }
//--- Search last '.'
  bool found = false ;
  int32_t lastOccurrenceIndex = receiver_length ;
  while ((lastOccurrenceIndex > 0) && ! found) {
    lastOccurrenceIndex -= 1 ;
    found = UNICODE_VALUE (charAtIndex (lastOccurrenceIndex COMMA_HERE)) == '.' ;
  }
  String result ;
  if (found) {
    result = subString (0, lastOccurrenceIndex) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   stringByDeletingLastPathComponent
//--------------------------------------------------------------------------------------------------

String String::stringByDeletingLastPathComponent (void) const {
  String result ;
  int32_t receiver_length = length () ;
//--- Suppress training '/'
  while ((receiver_length > 1) && (UNICODE_VALUE (charAtIndex (receiver_length - 1 COMMA_HERE)) == '/')) {
    receiver_length -= 1 ;
  }
//--- Search last '/'
  bool found = false ;
  int32_t lastOccurrenceIndex = receiver_length ;
  while ((lastOccurrenceIndex > 0) && ! found) {
    lastOccurrenceIndex -= 1 ;
    found = UNICODE_VALUE (charAtIndex (lastOccurrenceIndex COMMA_HERE)) == '/' ;
  }
  if (found) {
    result = subString (0, lastOccurrenceIndex) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   stringByAppendingPathComponent
//--------------------------------------------------------------------------------------------------

String String::stringByAppendingPathComponent (const String & inPathComponent) const {
  String result = *this ;
  if (result.length () == 0) {
    result = inPathComponent ;
  }else if (UNICODE_VALUE (result.lastChar (HERE)) != '/') {
    result.appendChar (TO_UNICODE ('/')) ;
    result.appendString (inPathComponent) ;
  }else{
    result.appendString (inPathComponent) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   lastPathComponent
//--------------------------------------------------------------------------------------------------

String String::lastPathComponent (void) const {
  int32_t usefulLength = length ();
//--- Suppress training '/'
  while ((usefulLength > 1) && (UNICODE_VALUE (charAtIndex (usefulLength - 1 COMMA_HERE)) == '/')) {
    usefulLength -= 1 ;
  }
//--- Search last '/'
  bool found = false ;
  int32_t lastOccurrenceIndex = usefulLength ;
  while ((lastOccurrenceIndex > 0) && ! found) {
    lastOccurrenceIndex -= 1 ;
    found = UNICODE_VALUE (charAtIndex (lastOccurrenceIndex COMMA_HERE)) == '/' ;
  }
  String result ;
  if (found) {
    result = subString (lastOccurrenceIndex + 1, usefulLength - lastOccurrenceIndex - 1) ;
  }else{
    result = subString (0, usefulLength) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String String::lastPathComponentWithoutExtension (void) const {
  const String fileNameWithExtension = lastPathComponent () ;
  return fileNameWithExtension.stringByDeletingPathExtension () ;
}

//--------------------------------------------------------------------------------------------------
//   MD5
//--------------------------------------------------------------------------------------------------

String String::md5 (void) const {
  MD5pm md5 ;
  md5.appendData ((uint8_t *) cString (), size_t (length ())) ;
  const MD5Digest digest = md5.finalizeAndGetDigest () ;
  String result ;
  char s [4] ;
  for (uint32_t i=0 ; i<16 ; i++) {
    snprintf (s, 4, "%02X", digest [i]) ;
    result.appendString (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   SHA256
//--------------------------------------------------------------------------------------------------

String String::sha256 (void) const {
  SHA256 sha ;
  sha.update ((uint8_t *) cString (), size_t (length ())) ;
  const std::array <uint8_t, 32> digest = sha.digest () ;
  String result ;
  char s [4] ;
  for (uint32_t i=0 ; i<32 ; i++) {
    snprintf (s, 4, "%02X", digest [i]) ;
    result.appendString (s) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   S U B    S T R I N G    F R O M    I N D E X
//--------------------------------------------------------------------------------------------------

String String::subStringFromIndex (const int32_t inStartIndex) const  {
  String result ;
  if (inStartIndex < length ()) {
    result = subString (inStartIndex, length () - inStartIndex) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   R I G H T    S U B    S T R I N G
//--------------------------------------------------------------------------------------------------

String String::rightSubString (const int32_t inLength) const  {
  String result ;
  if (length () <= inLength) {
    result = *this ;
  }else{
    result = subString (length () - inLength, inLength) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   L E F T    S U B    S T R I N G
//--------------------------------------------------------------------------------------------------

String String::leftSubString (const int32_t inLength) const  {
  String result ;
  if (length () <= inLength) {
    result = *this ;
  }else{
    result = subString (0, inLength) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//   X M L    E S C A P E D    S T R I N G
//--------------------------------------------------------------------------------------------------

//--- Returns a string where ", ', <, > and & have been replaced by &quot;, &apos;, &lt;, &gt; and &amp;
String String::XMLEscapedString (void) const {
  String result ;
  for (int32_t i=0 ; i<length () ; i++) {
    const utf32 c = charAtIndex (i COMMA_HERE) ;
    switch (UNICODE_VALUE (c)) {
    case '"'  : result.appendCString ("&quot;") ; break ;
    case '\'' : result.appendCString ("&apos;") ; break ;
    case '<'  : result.appendCString ("&lt;")   ; break ;
    case '>'  : result.appendCString ("&gt;")   ; break ;
    case '&'  : result.appendCString ("&amp;")  ; break ;
    case '\n' : result.appendCString ("&#10;") ; break ;
    default   : result.appendChar (c) ; break;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String String::stringByStandardizingPath (void) const {
  #ifdef COMPILE_FOR_WINDOWS
    String path = stringByReplacingCharacterByString (TO_UNICODE ('\\'), "/") ;
  #else
    String path = * this ;
  #endif
  if (path.length () == 0) {
    path.appendCString (".") ;
  }else{
  //--- Decompose path
    TC_UniqueArray <String> componentArray ;
    path.componentsSeparatedByString ("/", componentArray) ;
  //--- Remove empty components (but the first one)
    int32_t componentIndex = 1 ;
    while (componentIndex < componentArray.count ()) {
      if (componentArray (componentIndex COMMA_HERE).length () == 0) {
        componentArray.removeObjectAtIndex (componentIndex COMMA_HERE) ;
      }else{
        componentIndex ++ ;
      }
    }
  //--- Remove '.' components
    componentIndex = 0 ;
    while (componentIndex < componentArray.count ()) {
      if (componentArray (componentIndex COMMA_HERE) == ".") {
        componentArray.removeObjectAtIndex (componentIndex COMMA_HERE) ;
      }else{
        componentIndex ++ ;
      }
    }
  //--- Remove '..' components
    componentIndex = 1 ;
    while (componentIndex < componentArray.count ()) {
      if ((componentArray (componentIndex COMMA_HERE) == "..") && (componentArray (componentIndex-1 COMMA_HERE) != "..")) {
        componentArray.removeObjectAtIndex (componentIndex COMMA_HERE) ;
        componentIndex -- ;
        componentArray.removeObjectAtIndex (componentIndex COMMA_HERE) ;
        if (componentIndex == 0) {
          componentIndex = 1 ;
        }
      }else{
        componentIndex ++ ;
      }
    }
  //--- Recompose path
    path = componentsJoinedByString (componentArray, "/") ;
  }
//---
  return path ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark LevenshteinDistanceFromString
#endif

//--------------------------------------------------------------------------------------------------

uint32_t String::LevenshteinDistanceFromString (const String & inOperand) const {
  const int32_t myLength = length () ;
  const int32_t operandLength = inOperand.length () ;
  // for all i and j, d[i,j] will hold the Levenshtein distance between
  // the first i characters of s and the first j characters of t;
  // note that d has (m+1)x(n+1) values
  TC_UniqueArray2 <uint32_t> distance (myLength + 1, operandLength + 1) ;

  for (int32_t i=0 ; i<=myLength ; i++) {
    distance.setObjectAtIndexes ((uint32_t) i, i, 0 COMMA_HERE) ;
  }

  for (int32_t j=0 ; j<=operandLength ; j++) {
    distance.setObjectAtIndexes ((uint32_t) j, 0, j COMMA_HERE) ;
  }

  for (int32_t j=1 ; j<=operandLength ; j++) {
    for (int32_t i=1 ; i<=myLength ; i++) {
      if (UNICODE_VALUE (charAtIndex (i-1 COMMA_HERE)) == UNICODE_VALUE (inOperand.charAtIndex (j-1 COMMA_HERE))) {
        distance (i, j COMMA_HERE) = distance (i-1, j-1 COMMA_HERE) ;       // no operation required
      }else{
        distance (i, j COMMA_HERE) = std::min (std::min (
          distance (i-1, j COMMA_HERE) + 1,  // a deletion
          distance (i, j-1 COMMA_HERE) + 1),  // an insertion
          distance (i-1, j-1 COMMA_HERE) + 1 // a substitution
        ) ;
      }
    }
  }
  return distance (myLength, operandLength COMMA_HERE) ;
}

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//  unicode_character : an implementation of Unicode character                                   
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2008, ..., 2015 Pierre Molinaro.
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

#pragma once

//--------------------------------------------------------------------------------------------------

//--- Character assigned ?
bool isUnicodeCharacterAssigned (const utf32 inUnicodeCharacterCode) ;

//--- Returns character name, or empty string if not assigned
#ifdef __cplusplus
  #include "String-class.h"
  String unicodeName (const utf32 inUnicodeCharacter) ;
#endif
#ifdef __OBJC__
  NSString * unicodeName (const utf32 inUnicodeCharacter) ;
#endif

//--- Returns to lower letter, or returns argument
utf32 unicodeToLower (const utf32 inUnicodeCharacter) ;

//--- Returns to upper letter, or returns argument
utf32 unicodeToUpper (const utf32 inUnicodeCharacter) ;

//--- Returns true if unicode letter
bool isUnicodeLetter (const utf32 inUnicodeCharacter) ;

//--- Returns true if unicode mark
bool isUnicodeMark (const utf32 inUnicodeCharacter) ;

//--- Returns true if unicode number
bool isUnicodeNumber (const utf32 inUnicodeCharacter) ;

//--- Returns true if unicode decimal digit
bool isUnicodeDecimalDigit (const utf32 inUnicodeCharacter) ;

//--- Returns decimal value, or zero
uint32_t unicodeDecimalValue (const utf32 inUnicodeCharacter) ;

//--- Returns true if ascii hex digit
bool isUnicodeASCIIHexDigit (const utf32 inUnicodeCharacter) ;

//--- Returns hex value, or zero
uint32_t ASCIIHexValue (const utf32 inUnicodeCharacter) ;

//--- Returns true if unicode separator
bool isUnicodeSeparator (const utf32 inUnicodeCharacter) ;

//--- Returns true if unicode command
bool isUnicodeCommand (const utf32 inUnicodeCharacter) ;

//--- Returns true if unicode punctuation
bool isUnicodePunctuation (const utf32 inUnicodeCharacter) ;

//--- Returns true if unicode symbol
bool isUnicodeSymbol (const utf32 inUnicodeCharacter) ;

//--- Returns the number of bytes needed for encoding this character in UTF8
uint32_t utf8Length (const utf32 inUnicodeCharacter) ;

//--------------------------------------------------------------------------------------------------

extern const utf32 UNICODE_REPLACEMENT_CHARACTER ;
extern const utf32 UNICODE_MAX_LEGAL_UTF32_CHARACTER ;

//--- Returns true if unicode letter
bool isRestrictedUnicodeLetter (const utf32 inUnicodeCharacter) ;

//--------------------------------------------------------------------------------------------------
//
//   D E C O D E    H T M L    E N C O D I N G                                                   
//
//--------------------------------------------------------------------------------------------------

//--- Decode HTML in string, return Unicode (or NULL if not found)
#ifdef __cplusplus
  utf32 unicodeCharacterFromHTMLSequence (const String & inString) ;
#endif

#ifdef __OBJC__
  utf32 unicodeCharacterFromHTMLSequence (NSString * inString) ;
#endif

//--------------------------------------------------------------------------------------------------

utf32 unicodeCharacterForSingleByteCharacter (const char inChar, const PMStringEncoding inStringEncoding) ;

char singleByteCharacterForUnicodeCharacter (const utf32 inUnicodeChar, const PMStringEncoding inStringEncoding) ;

int32_t UTF8StringFromUTF32Character (const utf32 inUnicodeChar, char outSequence [5]) ;

//--- inEndOfStringPtr points just beyond the last available byte
#ifdef __cplusplus
  class U8Data ;
  utf32 utf32CharacterForPointer (const uint8_t * inDataString,
                                  int32_t & ioIndex,
                                  const int32_t inLength,
                                  bool & ioOK) ;
#endif

//--------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------*
//                                                                           *
//  unicode_character : an implementation of Unicode character               *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2008, ..., 2009 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Character assigned ?
bool isUnicodeCharacterAssigned (const utf32 inUnicodeCharacterCode) ;

//--- Returns character name, or empty string if not assigned
#ifdef __cplusplus
  C_String unicodeName (const utf32 inUnicodeCharacter) ;
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
PMUInt32 unicodeDecimalValue (const utf32 inUnicodeCharacter) ;

//--- Returns true if ascii hex digit
bool isUnicodeASCIIHexDigit (const utf32 inUnicodeCharacter) ;

//--- Returns hex value, or zero
PMUInt32 ASCIIHexValue (const utf32 inUnicodeCharacter) ;

//--- Returns true if unicode separator
bool isUnicodeSeparator (const utf32 inUnicodeCharacter) ;

//--- Returns true if unicode command
bool isUnicodeCommand (const utf32 inUnicodeCharacter) ;

//--- Returns true if unicode punctuation
bool isUnicodePunctuation (const utf32 inUnicodeCharacter) ;

//--- Returns true if unicode symbol
bool isUnicodeSymbol (const utf32 inUnicodeCharacter) ;

//---------------------------------------------------------------------------*

extern const utf32 UNICODE_REPLACEMENT_CHARACTER ;
extern const utf32 UNICODE_MAX_LEGAL_UTF32_CHARACTER ;

//---------------------------------------------------------------------------*
//                                                                           *
//   D E C O D E    H T M L    E N C O D I N G                               *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Decode HTML in string, return Unicode (or NULL if not found)
#ifdef __cplusplus
  utf32 unicodeCharacterFromHTMLSequence (const C_String & inString) ;
#endif
#ifdef __OBJC__
  utf32 unicodeCharacterFromHTMLSequence (NSString * inString) ;
#endif

//---------------------------------------------------------------------------*

utf32 unicodeCharacterForSingleByteCharacter (const char inChar, const PMStringEncoding inStringEncoding) ;

char singleByteCharacterForUnicodeCharacter (const utf32 inUnicodeChar, const PMStringEncoding inStringEncoding) ;

PMSInt32 UTF8StringFromUTF32Character (const utf32 inUnicodeChar, char outSequence [5]) ;

//--- inEndOfStringPtr points just beyond the last available byte
#ifdef __cplusplus
  class C_Data ;
  utf32 utf32CharacterForPointer (const PMUInt8 * inDataString,
                                  PMSInt32 & ioIndex,
                                  const PMSInt32 inLength,
                                  bool & ioOK) ;
#endif

//---------------------------------------------------------------------------*

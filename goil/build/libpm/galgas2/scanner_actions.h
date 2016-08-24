//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  scanner_actions:  hand-coded routines for building attribute values during scanning.                               *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2016 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef SCANNER_ACTIONS_DEFINED
#define SCANNER_ACTIONS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/C_Lexique.h"

//---------------------------------------------------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define LINE_AND_SOURCE_FILE sourceText ()->sourceFilePath ().cString (HERE), lineNumber ()
  #define COMMA_LINE_AND_SOURCE_FILE , LINE_AND_SOURCE_FILE
#else
  #define LINE_AND_SOURCE_FILE
  #define COMMA_LINE_AND_SOURCE_FILE
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  S C A N N E R    A C T I O N S                                                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//--- Predefined scanner actions: see http://galgas.rts-software.org/doku.php?id=lex#predefined_lexical_actions

void scanner_routine_multiplyUInt (C_Lexique & inLexique,
                                  const uint32_t inFactor,
                                  uint32_t & ioValue,
                                  const char * inResultTooLargeError) ;

void scanner_routine_multiplyUInt64 (C_Lexique & inLexique,
                                    const uint64_t inFactor,
                                    uint64_t & ioValue,
                                    const char * inResultTooLargeError) ;

void scanner_routine_enterCharacterIntoCharacter (C_Lexique & inLexique,
                                                 utf32 & outCharacter,
                                                 const utf32 inCharacter) ;

void scanner_routine_convertStringToDouble (C_Lexique & inLexique,
                                           const C_String & inString,
                                           double & outValue,
                                           const char * inConversionError) ;

void scanner_routine_enterCharacterIntoString (C_Lexique & inLexique,
                                              C_String & ioString,
                                              const utf32 inCharacter) ;

void scanner_routine_enterHexDigitIntoASCIIcharacter (C_Lexique & inLexique,
                                                     utf32 & ioValue,
                                                     const utf32 inCharacter,
                                                     const char * inNumberTooLargeError,
                                                     const char * inCharacterIsNotHexDigitError) ;

void scanner_routine_enterDigitIntoASCIIcharacter (C_Lexique & inLexique,
                                                  utf32 & ioValue,
                                                  const utf32 inCharacter,
                                                  const char * inNumberTooLargeError,
                                                  const char * inCharacterIsNotDigitError) ;

//--- Methods introduced in GALGAS 1.4.0

void scanner_routine_convertDecimalStringIntoUInt (C_Lexique & inLexique,
                                                  const C_String & inDecimalString,
                                                  uint32_t & outValue,
                                                  const char * inNumberTooLargeError,
                                                  const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertDecimalStringIntoSInt (C_Lexique & inLexique,
                                                  const C_String & inDecimalString,
                                                  int32_t & outValue,
                                                  const char * inNumberTooLargeError,
                                                  const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertDecimalStringIntoUInt64 (C_Lexique & inLexique,
                                                    const C_String & inDecimalString,
                                                    uint64_t & outValue,
                                                    const char * inNumberTooLargeError,
                                                    const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertDecimalStringIntoSInt64 (C_Lexique & inLexique,
                                                    const C_String & inDecimalString,
                                                    int64_t & outValue,
                                                    const char * inNumberTooLargeError,
                                                    const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_enterDigitIntoUInt (C_Lexique & inLexique,
                                        const utf32 inCharacter,
                                        uint32_t & ioValue,
                                        const char * inNumberTooLargeError,
                                        const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_enterDigitIntoUInt64 (C_Lexique & inLexique,
                                          const utf32 inCharacter,
                                          uint64_t & ioValue,
                                          const char * inNumberTooLargeError,
                                          const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_enterHexDigitIntoUInt (C_Lexique & inLexique,
                                           const utf32 inCharacter,
                                           uint32_t & ioValue,
                                           const char * inNumberTooLargeError,
                                           const char * inCharacterIsNotHexDigitError) ;
                             
void scanner_routine_enterHexDigitIntoUInt64 (C_Lexique & inLexique,
                                             const utf32 inCharacter,
                                             uint64_t & ioValue,
                                             const char * inNumberTooLargeError,
                                             const char * inCharacterIsNotHexDigitError) ;
                               
void scanner_routine_convertUIntToSInt (C_Lexique & inLexique,
                                        const uint32_t inValue,
                                        int32_t & outValue,
                                        const char * inNumberTooLargeError) ;

void scanner_routine_convertUInt64ToSInt64 (C_Lexique & inLexique,
                                           const uint64_t inValue,
                                           int64_t & outValue,
                                           const char * inNumberTooLargeError) ;

void scanner_routine_negateSInt (C_Lexique & inLexique,
                                int32_t & ioValue,
                                const char * inNumberTooLargeError) ;

void scanner_routine_negateSInt64 (C_Lexique & inLexique,
                                  int64_t & ioValue,
                                  const char * inNumberTooLargeError) ;

//--- Methods introduced in GALGAS 1.4.3 (thanks to Mikael Briday)

void scanner_routine_enterBinDigitIntoUInt (C_Lexique & inLexique,
                                           const utf32 inCharacter,
                                           uint32_t & ioValue,
                                           const char * inNumberTooLargeError,
                                           const char * inCharacterIsNotBinDigitError) ;
                            
void scanner_routine_enterBinDigitIntoUInt64 (C_Lexique & inLexique,
                                              const utf32 inCharacter,
                                              uint64_t & ioValue,
                                              const char * inNumberTooLargeError,
                                              const char * inCharacterIsNotBinDigitError) ;

//--- Methods introduced in GALGAS 1.4.7 (thanks to Mikael Briday)

void scanner_routine_enterOctDigitIntoUInt (C_Lexique & inLexique,
                                           const utf32 inCharacter,
                                           uint32_t & ioValue,
                                           const char * inNumberTooLargeError,
                                           const char * inCharacterIsNotOctDigitError) ;
                            
void scanner_routine_enterOctDigitIntoUInt64 (C_Lexique & inLexique,
                                             const utf32 inCharacter,
                                             uint64_t & ioValue,
                                             const char * inNumberTooLargeError,
                                             const char * inCharacterIsNotOctDigitError) ;

//--- Methods introduced in GALGAS 1.7.7
void scanner_routine_convertHexStringIntoUInt (C_Lexique & inLexique,
                                              const C_String & inDecimalString,
                                              uint32_t & outValue,
                                              const char * inNumberTooLargeError,
                                              const char * inCharacterIsNotHexDigitError) ;

void scanner_routine_convertHexStringIntoUInt64 (C_Lexique & inLexique,
                                                const C_String & inDecimalString,
                                                uint64_t & outValue,
                                                const char * inNumberTooLargeError,
                                                const char * inCharacterIsNotHexDigitError) ;

void scanner_routine_convertHexStringIntoSInt (C_Lexique & inLexique,
                                              const C_String & inDecimalString,
                                              int32_t & outValue,
                                              const char * inNumberTooLargeError,
                                              const char * inCharacterIsNotHexDigitError) ;

void scanner_routine_convertHexStringIntoSInt64 (C_Lexique & inLexique,
                                                const C_String & inHexString,
                                                int64_t & outValue,
                                                const char * inNumberTooLargeError,
                                                const char * inCharacterIsNotHexDigitError) ;

//--- Methods introduced in GALGAS 1.8.3
void scanner_routine_convertUnsignedNumberToUnicodeChar (C_Lexique & inLexique,
                                                        uint32_t & ioValue,
                                                        utf32 & outUnicodeCharacter,
                                                        const char * inUnassignedUnicodeValueError) ;

void scanner_routine_convertHTMLSequenceToUnicodeCharacter (C_Lexique & inLexique,
                                                          C_String & ioStringValue,
                                                          utf32 & outUnicodeCharacter,
                                                          const char * inUnassignedHTMLSequenceError) ;

void
scanner_routine_codePointToUnicode (C_Lexique & inLexique, 
                                   const C_String & inElementString,
                                   C_String & ioTemplateString) ;

//--- Methods introduced in GALGAS 3.0.0
void scanner_routine_resetString (C_Lexique & inLexique,
                                  C_String & ioString) ;

//--- Methods introduced in GALGAS 3.1.0
void scanner_routine_enterDecimalDigitIntoBigInt (C_Lexique & inLexique,
                                                  const utf32 inCharacter,
                                                  class C_BigInt & ioBigInt,
                                                  const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_enterHexDigitIntoBigInt (C_Lexique & inLexique,
                                              const utf32 inCharacter,
                                              class C_BigInt & ioBigInt,
                                              const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertDecimalStringIntoBigInt (C_Lexique & inLexique,
                                                     const C_String & inDecimalString,
                                                     C_BigInt & outValue,
                                                     const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertHexStringIntoBigInt (C_Lexique & inLexique,
                                                 const C_String & inHexString,
                                                 C_BigInt & outValue,
                                                 const char * inCharacterIsNotHexDigitError) ;

//--- Methods introduced in GALGAS 3.1.6
void scanner_routine_enterBinaryDigitIntoBigInt (C_Lexique & inLexique,
                                                 const utf32 inCharacter,
                                                 class C_BigInt & ioBigInt,
                                                 const char * inCharacterIsNotBinaryDigitError) ;

void scanner_routine_convertBinaryStringIntoBigInt (C_Lexique & inLexique,
                                                    const C_String & inBinaryString,
                                                    C_BigInt & outValue,
                                                    const char * inCharacterIsNotBinaryDigitError) ;


//---------------------------------------------------------------------------------------------------------------------*

//--- Predefined scanner functions: see http://galgas.rts-software.org/doku.php?id=lex#predefined_lexical_functions
utf32 scanner_function_toLower (C_Lexique & inLexique, const utf32 inCharacter) ;

utf32 scanner_function_toUpper (C_Lexique & inLexique, const utf32 inCharacter) ;

//---------------------------------------------------------------------------------------------------------------------*

#endif

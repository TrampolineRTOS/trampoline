//--------------------------------------------------------------------------------------------------
//
//  scanner_actions:  hand-coded routines for building attribute values during scanning.         
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2009, ..., 2023 Pierre Molinaro.
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

#include "Lexique.h"

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define LINE_AND_SOURCE_FILE sourceText ().sourceFilePath ().cString (), lineNumber ()
  #define COMMA_LINE_AND_SOURCE_FILE , LINE_AND_SOURCE_FILE
#else
  #define LINE_AND_SOURCE_FILE
  #define COMMA_LINE_AND_SOURCE_FILE
#endif

//--------------------------------------------------------------------------------------------------
//
//  S C A N N E R    A C T I O N S                                                               
//
//--------------------------------------------------------------------------------------------------

void scanner_routine_multiplyUInt (Lexique & inLexique,
                                  const uint32_t inFactor,
                                  uint32_t & ioValue,
                                  const char * inResultTooLargeError) ;

void scanner_routine_multiplyUInt64 (Lexique & inLexique,
                                    const uint64_t inFactor,
                                    uint64_t & ioValue,
                                    const char * inResultTooLargeError) ;

void scanner_routine_enterCharacterIntoCharacter (Lexique & inLexique,
                                                 utf32 & outCharacter,
                                                 const utf32 inCharacter) ;

void scanner_routine_convertStringToDouble (Lexique & inLexique,
                                           const String & inString,
                                           double & outValue,
                                           const char * inConversionError) ;

void scanner_routine_enterCharacterIntoString (Lexique & inLexique,
                                              String & ioString,
                                              const utf32 inCharacter) ;

void scanner_routine_enterHexDigitIntoASCIIcharacter (Lexique & inLexique,
                                                     utf32 & ioValue,
                                                     const utf32 inCharacter,
                                                     const char * inNumberTooLargeError,
                                                     const char * inCharacterIsNotHexDigitError) ;

void scanner_routine_enterDigitIntoASCIIcharacter (Lexique & inLexique,
                                                  utf32 & ioValue,
                                                  const utf32 inCharacter,
                                                  const char * inNumberTooLargeError,
                                                  const char * inCharacterIsNotDigitError) ;

//--- Methods introduced in GALGAS 1.4.0

void scanner_routine_convertDecimalStringIntoUInt (Lexique & inLexique,
                                                  const String & inDecimalString,
                                                  uint32_t & outValue,
                                                  const char * inNumberTooLargeError,
                                                  const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertDecimalStringIntoSInt (Lexique & inLexique,
                                                  const String & inDecimalString,
                                                  int32_t & outValue,
                                                  const char * inNumberTooLargeError,
                                                  const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertDecimalStringIntoUInt64 (Lexique & inLexique,
                                                    const String & inDecimalString,
                                                    uint64_t & outValue,
                                                    const char * inNumberTooLargeError,
                                                    const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertDecimalStringIntoSInt64 (Lexique & inLexique,
                                                    const String & inDecimalString,
                                                    int64_t & outValue,
                                                    const char * inNumberTooLargeError,
                                                    const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_enterDigitIntoUInt (Lexique & inLexique,
                                        const utf32 inCharacter,
                                        uint32_t & ioValue,
                                        const char * inNumberTooLargeError,
                                        const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_enterDigitIntoUInt64 (Lexique & inLexique,
                                          const utf32 inCharacter,
                                          uint64_t & ioValue,
                                          const char * inNumberTooLargeError,
                                          const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_enterHexDigitIntoUInt (Lexique & inLexique,
                                           const utf32 inCharacter,
                                           uint32_t & ioValue,
                                           const char * inNumberTooLargeError,
                                           const char * inCharacterIsNotHexDigitError) ;
                             
void scanner_routine_enterHexDigitIntoUInt64 (Lexique & inLexique,
                                             const utf32 inCharacter,
                                             uint64_t & ioValue,
                                             const char * inNumberTooLargeError,
                                             const char * inCharacterIsNotHexDigitError) ;
                               
void scanner_routine_convertUIntToSInt (Lexique & inLexique,
                                        const uint32_t inValue,
                                        int32_t & outValue,
                                        const char * inNumberTooLargeError) ;

void scanner_routine_convertUInt64ToSInt64 (Lexique & inLexique,
                                           const uint64_t inValue,
                                           int64_t & outValue,
                                           const char * inNumberTooLargeError) ;

void scanner_routine_negateSInt (Lexique & inLexique,
                                int32_t & ioValue,
                                const char * inNumberTooLargeError) ;

void scanner_routine_negateSInt64 (Lexique & inLexique,
                                  int64_t & ioValue,
                                  const char * inNumberTooLargeError) ;

//--- Methods introduced in GALGAS 1.4.3 (thanks to Mikael Briday)

void scanner_routine_enterBinDigitIntoUInt (Lexique & inLexique,
                                           const utf32 inCharacter,
                                           uint32_t & ioValue,
                                           const char * inNumberTooLargeError,
                                           const char * inCharacterIsNotBinDigitError) ;
                            
void scanner_routine_enterBinDigitIntoUInt64 (Lexique & inLexique,
                                              const utf32 inCharacter,
                                              uint64_t & ioValue,
                                              const char * inNumberTooLargeError,
                                              const char * inCharacterIsNotBinDigitError) ;

//--- Methods introduced in GALGAS 1.4.7 (thanks to Mikael Briday)

void scanner_routine_enterOctDigitIntoUInt (Lexique & inLexique,
                                           const utf32 inCharacter,
                                           uint32_t & ioValue,
                                           const char * inNumberTooLargeError,
                                           const char * inCharacterIsNotOctDigitError) ;
                            
void scanner_routine_enterOctDigitIntoUInt64 (Lexique & inLexique,
                                             const utf32 inCharacter,
                                             uint64_t & ioValue,
                                             const char * inNumberTooLargeError,
                                             const char * inCharacterIsNotOctDigitError) ;

//--- Methods introduced in GALGAS 1.7.7
void scanner_routine_convertHexStringIntoUInt (Lexique & inLexique,
                                              const String & inDecimalString,
                                              uint32_t & outValue,
                                              const char * inNumberTooLargeError,
                                              const char * inCharacterIsNotHexDigitError) ;

void scanner_routine_convertHexStringIntoUInt64 (Lexique & inLexique,
                                                const String & inDecimalString,
                                                uint64_t & outValue,
                                                const char * inNumberTooLargeError,
                                                const char * inCharacterIsNotHexDigitError) ;

void scanner_routine_convertHexStringIntoSInt (Lexique & inLexique,
                                              const String & inDecimalString,
                                              int32_t & outValue,
                                              const char * inNumberTooLargeError,
                                              const char * inCharacterIsNotHexDigitError) ;

void scanner_routine_convertHexStringIntoSInt64 (Lexique & inLexique,
                                                const String & inHexString,
                                                int64_t & outValue,
                                                const char * inNumberTooLargeError,
                                                const char * inCharacterIsNotHexDigitError) ;

//--- Methods introduced in GALGAS 1.8.3
void scanner_routine_convertUnsignedNumberToUnicodeChar (Lexique & inLexique,
                                                        uint32_t & ioValue,
                                                        utf32 & outUnicodeCharacter,
                                                        const char * inUnassignedUnicodeValueError) ;

void scanner_routine_convertHTMLSequenceToUnicodeCharacter (Lexique & inLexique,
                                                          String & ioStringValue,
                                                          utf32 & outUnicodeCharacter,
                                                          const char * inUnassignedHTMLSequenceError) ;

void
scanner_routine_codePointToUnicode (Lexique & inLexique, 
                                   const String & inElementString,
                                   String & ioTemplateString) ;

//--- Methods introduced in GALGAS 3.0.0
void scanner_routine_resetString (Lexique & inLexique,
                                  String & ioString) ;

//--- Methods introduced in GALGAS 3.1.0
void scanner_routine_enterDecimalDigitIntoBigInt (Lexique & inLexique,
                                                  const utf32 inCharacter,
                                                  class BigSigned & ioBigInt,
                                                  const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_enterHexDigitIntoBigInt (Lexique & inLexique,
                                              const utf32 inCharacter,
                                              class BigSigned & ioBigInt,
                                              const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertDecimalStringIntoBigInt (Lexique & inLexique,
                                                     const String & inDecimalString,
                                                     BigSigned & outValue,
                                                     const char * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertHexStringIntoBigInt (Lexique & inLexique,
                                                 const String & inHexString,
                                                 BigSigned & outValue,
                                                 const char * inCharacterIsNotHexDigitError) ;

//--- Methods introduced in GALGAS 3.1.6
void scanner_routine_enterBinaryDigitIntoBigInt (Lexique & inLexique,
                                                 const utf32 inCharacter,
                                                 class BigSigned & ioBigInt,
                                                 const char * inCharacterIsNotBinaryDigitError) ;

void scanner_routine_convertBinaryStringIntoBigInt (Lexique & inLexique,
                                                    const String & inBinaryString,
                                                    BigSigned & outValue,
                                                    const char * inCharacterIsNotBinaryDigitError) ;


//--------------------------------------------------------------------------------------------------

utf32 scanner_function_toLower (Lexique & inLexique, const utf32 inCharacter) ;

utf32 scanner_function_toUpper (Lexique & inLexique, const utf32 inCharacter) ;

void scanner_routine_negateBigInt (Lexique & inLexique,
                                   BigSigned & ioValue) ;

//--------------------------------------------------------------------------------------------------

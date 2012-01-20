//---------------------------------------------------------------------------*
//                                                                           *
//  scanner_actions:                                                         *
//  hand-coded routines for building attribute values during scanning.       *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2009, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
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

#ifndef SCANNER_ACTIONS_DEFINED
#define SCANNER_ACTIONS_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/C_Lexique.h"

//---------------------------------------------------------------------------*
//                                                                           *
//  S C A N N E R    A C T I O N S                                           *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Predefined scanner actions: see http://galgas.rts-software.org/doku.php?id=lex#predefined_lexical_actions

void scanner_routine_multiplyUInt (C_Lexique & inLexique,
                                  const PMUInt32 inFactor,
                                  PMUInt32 & ioValue,
                                  const utf32 * inResultTooLargeError) ;

void scanner_routine_multiplyUInt64 (C_Lexique & inLexique,
                                    const PMUInt64 inFactor,
                                    PMUInt64 & ioValue,
                                    const utf32 * inResultTooLargeError) ;

void scanner_routine_enterCharacterIntoCharacter (C_Lexique & inLexique,
                                                 utf32 & outCharacter,
                                                 const utf32 inCharacter) ;

void scanner_routine_convertStringToDouble (C_Lexique & inLexique,
                                           const C_String & inString,
                                           double & outValue,
                                           const utf32 * inConversionError) ;

void scanner_routine_enterCharacterIntoString (C_Lexique & inLexique,
                                              C_String & ioString,
                                              const utf32 inCharacter) ;

void scanner_routine_enterHexDigitIntoASCIIcharacter (C_Lexique & inLexique,
                                                     utf32 & ioValue,
                                                     const utf32 inCharacter,
                                                     const utf32 * inNumberTooLargeError,
                                                     const utf32 * inCharacterIsNotHexDigitError) ;

void scanner_routine_enterDigitIntoASCIIcharacter (C_Lexique & inLexique,
                                                  utf32 & ioValue,
                                                  const utf32 inCharacter,
                                                  const utf32 * inNumberTooLargeError,
                                                  const utf32 * inCharacterIsNotDigitError) ;

//--- Methods introduced in GALGAS 1.4.0

void scanner_routine_convertDecimalStringIntoUInt (C_Lexique & inLexique,
                                                  const C_String & inDecimalString,
                                                  PMUInt32 & outValue,
                                                  const utf32 * inNumberTooLargeError,
                                                  const utf32 * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertDecimalStringIntoSInt (C_Lexique & inLexique,
                                                  const C_String & inDecimalString,
                                                  PMSInt32 & outValue,
                                                  const utf32 * inNumberTooLargeError,
                                                  const utf32 * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertDecimalStringIntoUInt64 (C_Lexique & inLexique,
                                                    const C_String & inDecimalString,
                                                    PMUInt64 & outValue,
                                                    const utf32 * inNumberTooLargeError,
                                                    const utf32 * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_convertDecimalStringIntoSInt64 (C_Lexique & inLexique,
                                                    const C_String & inDecimalString,
                                                    PMSInt64 & outValue,
                                                    const utf32 * inNumberTooLargeError,
                                                    const utf32 * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_enterDigitIntoUInt (C_Lexique & inLexique,
                                        const utf32 inCharacter,
                                        PMUInt32 & ioValue,
                                        const utf32 * inNumberTooLargeError,
                                        const utf32 * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_enterDigitIntoUInt64 (C_Lexique & inLexique,
                                          const utf32 inCharacter,
                                          PMUInt64 & ioValue,
                                          const utf32 * inNumberTooLargeError,
                                          const utf32 * inCharacterIsNotDecimalDigitError) ;

void scanner_routine_enterHexDigitIntoUInt (C_Lexique & inLexique,
                                           const utf32 inCharacter,
                                           PMUInt32 & ioValue,
                                           const utf32 * inNumberTooLargeError,
                                           const utf32 * inCharacterIsNotHexDigitError) ;
                             
void scanner_routine_enterHexDigitIntoUInt64 (C_Lexique & inLexique,
                                             const utf32 inCharacter,
                                             PMUInt64 & ioValue,
                                             const utf32 * inNumberTooLargeError,
                                             const utf32 * inCharacterIsNotHexDigitError) ;
                               
void scanner_routine_convertUIntToSInt (C_Lexique & inLexique,
                                        const PMUInt32 inValue,
                                        PMSInt32 & outValue,
                                        const utf32 * inNumberTooLargeError) ;

void scanner_routine_convertUInt64ToSInt64 (C_Lexique & inLexique,
                                           const PMUInt64 inValue,
                                           PMSInt64 & outValue,
                                           const utf32 * inNumberTooLargeError) ;

void scanner_routine_negateSInt (C_Lexique & inLexique,
                                PMSInt32 & ioValue,
                                const utf32 * inNumberTooLargeError) ;

void scanner_routine_negateSInt64 (C_Lexique & inLexique,
                                  PMSInt64 & ioValue,
                                  const utf32 * inNumberTooLargeError) ;

//--- Methods introduced in GALGAS 1.4.3 (thanks to Mikael Briday)

void scanner_routine_enterBinDigitIntoUInt (C_Lexique & inLexique,
                                           const utf32 inCharacter,
                                           PMUInt32 & ioValue,
                                           const utf32 * inNumberTooLargeError,
                                           const utf32 * inCharacterIsNotBinDigitError) ;
                            
void scanner_routine_enterBinDigitIntoUInt64 (C_Lexique & inLexique,
                                              const utf32 inCharacter,
                                              PMUInt64 & ioValue,
                                              const utf32 * inNumberTooLargeError,
                                              const utf32 * inCharacterIsNotBinDigitError) ;

//--- Methods introduced in GALGAS 1.4.7 (thanks to Mikael Briday)

void scanner_routine_enterOctDigitIntoUInt (C_Lexique & inLexique,
                                           const utf32 inCharacter,
                                           PMUInt32 & ioValue,
                                           const utf32 * inNumberTooLargeError,
                                           const utf32 * inCharacterIsNotOctDigitError) ;
                            
void scanner_routine_enterOctDigitIntoUInt64 (C_Lexique & inLexique,
                                             const utf32 inCharacter,
                                             PMUInt64 & ioValue,
                                             const utf32 * inNumberTooLargeError,
                                             const utf32 * inCharacterIsNotOctDigitError) ;

//--- Methods introduced in GALGAS 1.7.7
void scanner_routine_convertHexStringIntoUInt (C_Lexique & inLexique,
                                              const C_String & inDecimalString,
                                              PMUInt32 & outValue,
                                              const utf32 * inNumberTooLargeError,
                                              const utf32 * inCharacterIsNotHexDigitError) ;

void scanner_routine_convertHexStringIntoUInt64 (C_Lexique & inLexique,
                                                const C_String & inDecimalString,
                                                PMUInt64 & outValue,
                                                const utf32 * inNumberTooLargeError,
                                                const utf32 * inCharacterIsNotHexDigitError) ;

void scanner_routine_convertHexStringIntoSInt (C_Lexique & inLexique,
                                              const C_String & inDecimalString,
                                              PMSInt32 & outValue,
                                              const utf32 * inNumberTooLargeError,
                                              const utf32 * inCharacterIsNotHexDigitError) ;

void scanner_routine_convertHexStringIntoSInt64 (C_Lexique & inLexique,
                                                const C_String & inDecimalString,
                                                PMSInt64 & outValue,
                                                const utf32 * inNumberTooLargeError,
                                                const utf32 * inCharacterIsNotHexDigitError) ;

//--- Methods introduced in GALGAS 1.8.3
void scanner_routine_convertUnsignedNumberToUnicodeChar (C_Lexique & inLexique,
                                                        PMUInt32 & ioValue,
                                                        utf32 & outUnicodeCharacter,
                                                        const utf32 * inUnassignedUnicodeValueError) ;

void scanner_routine_convertHTMLSequenceToUnicodeCharacter (C_Lexique & inLexique,
                                                          C_String & ioStringValue,
                                                          utf32 & outUnicodeCharacter,
                                                          const utf32 * inUnassignedHTMLSequenceError) ;

void
scanner_routine_codePointToUnicode (C_Lexique & inLexique, 
                                   const C_String & inElementString,
                                   C_String & ioTemplateString) ;

//---------------------------------------------------------------------------*

//--- Predefined scanner functions: see http://galgas.rts-software.org/doku.php?id=lex#predefined_lexical_functions
utf32 scanner_function_toLower (C_Lexique & inLexique, const utf32 inCharacter) ;

utf32 scanner_function_toUpper (C_Lexique & inLexique, const utf32 inCharacter) ;

//---------------------------------------------------------------------------*

#endif

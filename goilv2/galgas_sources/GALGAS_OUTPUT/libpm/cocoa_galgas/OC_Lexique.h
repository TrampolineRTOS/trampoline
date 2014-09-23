//-----------------------------------------------------------------------------*
//                                                                             *
//  'OC_Lexique'                                                               *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  Copyright (C) 2009, ..., 2009 Pierre Molinaro.                             *
//                                                                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//                                                                             *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#import "unicode_character_m.h"

//-----------------------------------------------------------------------------*
//                                                                             *
//  T E M P L A T E    D E L I M I T E R     C L A S S                         *
//                                                                             *
//-----------------------------------------------------------------------------*

@interface OC_GGS_TemplateDelimiter : NSObject

@property (assign, readonly PROPERTY_COMMA_ATOMIC) NSString * startString ;
@property (assign, readonly PROPERTY_COMMA_ATOMIC) NSString * endString ;
@property (assign, readonly PROPERTY_COMMA_ATOMIC) BOOL discardStartString ;

- (id) initWithStartString: (NSString *) inStartString
       endString: (NSString *) inEndString
       discardStartString: (BOOL) inDiscardStartString ;
@end

//-----------------------------------------------------------------------------*
//                                                                             *
//              S C A N N I N G   P O I N T   S T R U C T                      *
//                                                                             *
//-----------------------------------------------------------------------------*

typedef struct {
  utf32 mPreviousChar ; 
  utf32 mCurrentChar ; 
  NSUInteger mCurrentLocation ;
} scanningPointStructForCocoa ;

//-----------------------------------------------------------------------------*
//                                                                             *
//                       O C   L E X I Q U E                                   *
//                                                                             *
//-----------------------------------------------------------------------------*

@interface OC_Lexique : NSObject {
  @protected NSString * mSourceString ;
  @protected NSInteger mTokenCode ;
  @protected utf32 mPreviousChar ; 
  @protected utf32 mCurrentChar ; 
  @protected NSUInteger mTokenStartLocation ;
  @protected NSUInteger mCurrentLocation ;
  @protected BOOL mLoop ;
  @protected NSInteger mMatchedTemplateDelimiterIndex ; //--- Scanner mode for template scanner
  @private NSDictionary * mCustomSyntaxColoringDictionary ;
}

@property (retain, readonly PROPERTY_COMMA_ATOMIC) NSMenu * menuForEntryPopUpButton ;

- (void) detach ;

- (void) searchForReplacementPattern:(NSArray *) inReplacementPatternArray ;

- (void) advance ;

- (BOOL) testForInputChar: (utf32) inUnicodeCharacter ;

- (BOOL) testForInputFromChar:(utf32) inUnicodeLowerBound toChar:(utf32) inUnicodeUpperBound ;

- (BOOL) testForInputString:(NSString *) inString advance:(BOOL) inFlag ;

- (BOOL) notTestForInputString: (NSString *) inTestedString error: (BOOL *) ioNoLexicalError ;

- (BOOL) testForCharWithFunction: (bool (*) (const utf32 inUnicodeCharacter)) inFunction ;

- (void) saveScanningPoint: (scanningPointStructForCocoa *) outScanningPoint ;

- (void) restoreScanningPoint: (scanningPointStructForCocoa *) inScanningPoint ;

- (SInt32) findTemplateDelimiterIndex: (NSArray *)  inTemplateDelimiterArray ; // Array of OC_GGS_TemplateDelimiter

- (NSString *) blockComment ;

- (NSUInteger) styleCount ;

- (NSString *) styleIdentifierForStyleIndex: (const NSInteger) inIndex ;

- (NSString *) styleNameForStyleIndex: (const NSInteger) inIndex ;

- (NSUInteger) textMacroCount ;

- (NSString *) textMacroTitleAtIndex: (const NSUInteger) inIndex ;

- (NSString *) textMacroContentAtIndex: (const NSUInteger) inIndex ;

- (NSString *) tabItemTitle ;

- (const UInt16 **) popupListData ;

- (BOOL) isTemplateLexique ; // Return NO by default

- (void) parseLexicalTokenForLexicalColoring ;

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal ;

- (void) tokenizeForSourceString: (NSString *) inSourceString
         tokenArray: (NSMutableArray *) ioTokenArray // Array of OC_Token
         editedRange: (const NSRange) inEditedRange
         changeInLength: (const NSInteger) inChangeInLength
         firstIndexToRedraw: (NSInteger *) outLowerIndexToRedrawInStyleArray
         lastIndexToRedraw: (NSInteger *) outUpperIndexToRedrawInStyleArray
         eraseRangeStart: (NSInteger *) outEraseRangeStart
         eraseRangeEnd: (NSInteger *) outEraseRangeEnd ;

- (NSString *) indexingDirectory ;

- (NSArray *) indexingTitles ; // Array of NSString

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex ;
@end

//-----------------------------------------------------------------------------*

typedef struct {
  const char * mEntry ;
  UInt32 mTokenCode ;
} C_cocoa_lexique_table_entry ;

//-----------------------------------------------------------------------------*

NSInteger searchStringInTable (NSString * inSearchedString,
                               const C_cocoa_lexique_table_entry * inTable,
                               const NSUInteger inTableSize) ;

//-----------------------------------------------------------------------------*
//                                                                             *
//  S C A N N E R    A C T I O N S                                             *
//                                                                             *
//-----------------------------------------------------------------------------*

//--- Predefined scanner actions: see http://galgas.rts-software.org/doku.php?id=lex#predefined_lexical_actions

void scanner_cocoa_routine_multiplyUInt (BOOL * ioNoLexicalError,
                                         const UInt32 inFactor,
                                         UInt32 * ioValue) ;

void scanner_cocoa_routine_multiplyUInt64 (BOOL * ioNoLexicalError,
                                           const UInt64 inFactor,
                                           UInt64 * ioValue) ;

void scanner_cocoa_routine_enterCharacterIntoCharacter (BOOL * ioNoLexicalError,
                                                        utf32 * outCharacter,
                                                        const utf32 inCharacter) ;

void scanner_cocoa_routine_convertStringToDouble (BOOL * ioNoLexicalError,
                                                  NSMutableString * inString,
                                                  double * outValue) ;

void scanner_cocoa_routine_enterCharacterIntoString (BOOL * ioNoLexicalError,
                                                     NSMutableString * ioString,
                                                     const utf32 inCharacter) ;

void scanner_cocoa_routine_enterHexDigitIntoASCIIcharacter (BOOL * ioNoLexicalError,
                                                            UInt32 * ioValue,
                                                            const utf32 inCharacter) ;

void scanner_cocoa_routine_enterDigitIntoASCIIcharacter (BOOL * ioNoLexicalError,
                                                         UInt32 * ioValue,
                                                         const utf32 inCharacter) ;

//--- Methods introduced in GALGAS 1.4.0

void scanner_cocoa_routine_convertDecimalStringIntoUInt (BOOL * ioNoLexicalError,
                                                         NSString * inDecimalString,
                                                         UInt32 * outValue) ;

void scanner_cocoa_routine_convertDecimalStringIntoSInt (BOOL * ioNoLexicalError,
                                                         NSString * inDecimalString,
                                                         SInt32 * outValue) ;

void scanner_cocoa_routine_convertDecimalStringIntoUInt64 (BOOL * ioNoLexicalError,
                                                           NSString * inDecimalString,
                                                           UInt64 * outValue) ;

void scanner_cocoa_routine_convertDecimalStringIntoSInt64 (BOOL * ioNoLexicalError,
                                                           NSString * inDecimalString,
                                                           SInt64 * outValue) ;

void scanner_cocoa_routine_enterDigitIntoUInt (BOOL * ioNoLexicalError,
                                               const utf32 inCharacter,
                                               UInt32 * ioValue) ;

void scanner_cocoa_routine_enterDigitIntoUInt64 (BOOL * ioNoLexicalError,
                                                 const utf32 inCharacter,
                                                 UInt64 * ioValue) ;

void scanner_cocoa_routine_enterHexDigitIntoUInt (BOOL * ioNoLexicalError,
                                                  const utf32 inCharacter,
                                                  UInt32 * ioValue) ;
                             
void scanner_cocoa_routine_enterHexDigitIntoUInt64 (BOOL * ioNoLexicalError,
                                                    const utf32 inCharacter,
                                                    UInt64 * ioValue) ;
                               
void scanner_cocoa_routine_convertUIntToSInt (BOOL * ioNoLexicalError,
                                              const UInt32 inValue,
                                              SInt32 * outValue) ;

void scanner_cocoa_routine_convertUInt64ToSInt64 (BOOL * ioNoLexicalError,
                                                  const UInt64 inValue,
                                                  SInt64 * outValue) ;

void scanner_cocoa_routine_negateSInt (BOOL * ioNoLexicalError,
                                       SInt32 * ioValue) ;

void scanner_cocoa_routine_negateSInt64 (BOOL * ioNoLexicalError,
                                         SInt64 * ioValue) ;

//--- Methods introduced in GALGAS 1.4.3 (thanks to Mikael Briday)

void scanner_cocoa_routine_enterBinDigitIntoUInt (BOOL * ioNoLexicalError,
                                                  const utf32 inCharacter,
                                                  UInt32 * ioValue) ;
                            
void scanner_cocoa_routine_enterBinDigitIntoUInt64 (BOOL * ioNoLexicalError,
                                                    const utf32 inCharacter,
                                                    UInt64 * ioValue) ;

//--- Methods introduced in GALGAS 1.4.7 (thanks to Mikael Briday)

void scanner_cocoa_routine_enterOctDigitIntoUInt (BOOL * ioNoLexicalError,
                                                  const utf32 inCharacter,
                                                  UInt32 * ioValue) ;
                            
void scanner_cocoa_routine_enterOctDigitIntoUInt64 (BOOL * ioNoLexicalError,
                                                    const utf32 inCharacter,
                                                    UInt64 * ioValue) ;

//--- Methods introduced in GALGAS 1.7.7
void scanner_cocoa_routine_convertHexStringIntoUInt (BOOL * ioNoLexicalError,
                                                     NSString * inDecimalString,
                                                     UInt32 * outValue) ;

void scanner_cocoa_routine_convertHexStringIntoUInt64 (BOOL * ioNoLexicalError,
                                                       NSString * inDecimalString,
                                                       UInt64 * outValue) ;

void scanner_cocoa_routine_convertHexStringIntoSInt (BOOL * ioNoLexicalError,
                                                     NSString * inDecimalString,
                                                     SInt32 * outValue) ;

void scanner_cocoa_routine_convertHexStringIntoSInt64 (BOOL * ioNoLexicalError,
                                                       NSString * inDecimalString,
                                                       SInt64 * outValue) ;

//--- Methods introduced in GALGAS 1.8.3
void scanner_cocoa_routine_convertUnsignedNumberToUnicodeChar (BOOL * ioNoLexicalError,
                                                               UInt32 * ioValue,
                                                               utf32 * outUnicodeCharacter) ;

void scanner_cocoa_routine_convertHTMLSequenceToUnicodeCharacter (BOOL * ioNoLexicalError,
                                                                  NSMutableString * ioStringValue,
                                                                  utf32 * outUnicodeCharacter) ;

void
scanner_cocoa_routine_codePointToUnicode (BOOL * ioNoLexicalError, 
                                          NSString * inElementString,
                                          NSMutableString * ioTemplateString) ;

//-----------------------------------------------------------------------------*

//--- Predefined scanner functions: see http://galgas.rts-software.org/doku.php?id=lex#predefined_lexical_functions
utf32 scanner_cocoa_function_toLower (const utf32 inCharacter) ;

utf32 scanner_cocoa_function_toUpper (const utf32 inCharacter) ;

//-----------------------------------------------------------------------------*


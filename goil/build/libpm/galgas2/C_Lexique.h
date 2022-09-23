//----------------------------------------------------------------------------------------------------------------------
//
//  'C_Lexique' : an abstract lexique class ;                                                    
//  Galgas generated scanner classes inherit from this class.                                    
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1996, ..., 2022 Pierre Molinaro.
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
//----------------------------------------------------------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/C_Compiler.h"
#include "galgas2/cProductionNameDescriptor.h"
#include "galgas2/cTemplateDelimiter.h"
#include "galgas2/C_galgas_io.h"

//----------------------------------------------------------------------------------------------------------------------

class cIndexingDictionary ;

//----------------------------------------------------------------------------------------------------------------------
//
//                 Lexique class                                                                 
//
//----------------------------------------------------------------------------------------------------------------------

class C_Lexique : public C_Compiler {
//--- Constructors and destructor
  public: C_Lexique (C_Compiler * inCallerCompiler,
                     const C_String & inSourceFileName
                     COMMA_LOCATION_ARGS) ;

  public: C_Lexique (C_Compiler * inCallerCompiler,
                     const C_String & inSourceString,
                     const C_String & inStringForError
                     COMMA_LOCATION_ARGS) ;

  public: virtual ~C_Lexique (void) ;

//--- No copy
  private: C_Lexique (const C_Lexique &) ;
  private: C_Lexique & operator = (const C_Lexique &) ;

//--- Indexing
  public: void enterIndexing (const uint32_t inIndexingKind,
                              const char * inIndexedKeyPosfix) ;
  public: void enableIndexing (void) ;
  public: void generateIndexFile (void) ;
  protected: cIndexingDictionary * mIndexingDictionary ;

//--- Indexing directory
  protected: virtual C_String indexingDirectory (void) const = 0 ;

//--- Template String
  protected: int32_t findTemplateDelimiterIndex (const cTemplateDelimiter inTemplateDelimiterArray [],
                                                 const int32_t inTemplateDelimiterArrayLength) ;

//--- Token list
  private: cToken * mFirstToken ;
  private: cToken * mLastToken ;
  private: cToken * mCurrentTokenPtr ;
  protected: void enterTokenFromPointer (cToken * inToken) ;
  private: int32_t mLastSeparatorIndex ;
  public: void appendLastSeparatorTo (C_String & ioString) const ;

  protected: cToken * currentTokenPtr (LOCATION_ARGS) const {
    macroValidPointerThere (mCurrentTokenPtr) ;
    return mCurrentTokenPtr ;
  }

//--- Syntax directed translation : accessing current token
  public: virtual C_String separatorString (void) const ;
  public: C_String tokenString (void) const ;

//--- Current character
  protected: utf32 mCurrentChar ;

//--- Previous character
  protected: utf32 mPreviousChar ;
  public: inline utf32 previousChar (void) const {
    return mPreviousChar ;
  }

//--- Locations for current token (significant only during lexical analysis phase)
  protected: C_LocationInSource mTokenStartLocation ;
  protected: C_LocationInSource mTokenEndLocation ;

//--- Advance
  protected: void advance (void) ; // One character
  protected: void advance (const int32_t inCount) ; // Several characters

//--- For Debugging parser
  private: C_String mTriggerNonTerminalSymbolList ;
  private: uint16_t mDebugDepthCounter ;
  private: bool mDebugIsRunning ;

  public: void enterProduction (const char * inProductionName,
                                const char * inLabel,
                                const char * inTag) ;

  public: void didParseTerminal (const char * inTerminalName,
                                const C_String & inValue) ;

  public: void exitProduction (void) ;

//--- Reset Scanner for performing second pass
  private: void resetForSecondPass (void) ;

//--- Handling parsing context (for parse ... rewind ... end parse ; instruction)
  public: C_parsingContext parsingContext (void) const ;
  public: void setParsingContext (const C_parsingContext & inContext) ;

//--- Internal error during bottom-up parsing
  public: void internalBottomUpParserError (LOCATION_ARGS) ;

//--- Handling lexical error
  protected: void unknownCharacterLexicalError (LOCATION_ARGS) ;

  public: void lexicalError (const C_String & inLexicalErrorMessage
                             COMMA_LOCATION_ARGS) ;

//--- Signal a lexical warning
  protected: void lexicalWarning (const C_String & messageAlerte COMMA_LOCATION_ARGS) ;

//--- Handling syntax error
  private: void parsingError (const TC_UniqueArray <int16_t> & inExpectedTerminalsArray,
                              const cToken * inPreviousTokenPtr,
                              const cToken * inCurrentTokenPtr,
                              const int16_t inCurrentTokenCode
                              COMMA_LOCATION_ARGS) ;

//--- Get message for terminal
  protected: virtual C_String getMessageForTerminal (const int16_t inTerminalSymbol) const = 0 ;

//--- Static method for searching a string in an ordered list
//    returns -1 if not found, and associated code if found
  protected: static int16_t searchInList (const C_String & inString,
                                          const C_unicode_lexique_table_entry inTable [],
                                          const int16_t inTableSize) ;

//--- Get Token String
  public: virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const = 0 ;

//--- Lexical analysis methods
  public: void performLexicalAnalysis (void) ;

  protected: bool testForCharWithFunction (bool (*inFunction) (const utf32 inUnicodeCharacter)) ;

  protected: bool testForInputUTF32CharRange (const utf32 inLowerBound,
                                              const utf32 inHigherBound) ;

  protected: bool testForInputUTF32Char (const utf32 inTestCharacter) ;

  protected: bool testForInputUTF32String (const utf32 * inTestString,
                                           const int32_t inStringLength,
                                           const bool inAdvanceOnMatch) ;

  protected: bool notTestForInputUTF32String (const utf32 * inTestString,
                                              const int32_t inStringLength,
                                              const char * inEndOfFileErrorMessage
                                              COMMA_LOCATION_ARGS) ;

  protected: void lexicalLog (LOCATION_ARGS) ;

//--- Methods for parsing during second pass
  public: void acceptTerminal (const int16_t inExpectedTerminal COMMA_LOCATION_ARGS) ;
  public: int16_t nextProductionIndex (void) ;
  public: virtual int16_t terminalVocabularyCount (void) const = 0 ;

//--- Perform top down parsing (called by LL (1) parser)
  public: bool performTopDownParsing (const int16_t inProductions [],
                                      const cProductionNameDescriptor inProductionNames [],
                                      const int16_t inProductionIndexes [],
                                      const int16_t inFirstProductionIndex [],
                                      const int16_t inDecisionTable [],
                                      const int16_t inDecisionTableIndexes [],
                                      const int16_t inProgramCounterInitialValue) ;

  private: void buildExpectedTerminalsArrayOnSyntaxError (const int16_t inErrorProgramCounter,
                                                          const int32_t inErrorStackCount,
                                                          const TC_Array <int16_t> & inCurrentStack,
                                                          const TC_Array <int16_t> & inErrorStack,
                                                          const int16_t inProductions [],
                                                          const int16_t inProductionIndexes [],
                                                          const int16_t inFirstProductionIndex [],
                                                          const int16_t inDecisionTable [],
                                                          const int16_t inDecisionTableIndexes [],
                                                          TC_UniqueArray <int16_t> & outExpectedTerminalsArray) ;

  private: bool acceptTerminalForErrorSignaling (const int16_t inTerminal,
                                                 const int16_t inProductions [],
                                                 const int16_t inProductionIndexes [],
                                                 const int16_t inFirstProductionIndex [],
                                                 const int16_t inDecisionTable [],
                                                 const int16_t inDecisionTableIndexes [],
                                                 const TC_Array <int16_t> & inErrorStack,
                                                 const int16_t inErrorProgramCounter) ;

//--- Perform bottom up parsing (called by SLR and LR(1) parsers)
  public: bool performBottomUpParsing (const int16_t inActionTable [],
                                       const char * inNonTerminalSymbolNames [],
                                       const uint32_t inActionTableIndex [],
                                       const int16_t * inSuccessorTable [],
                                       const int16_t inProductionsTable []) ;

//--- Scanner pure virtual methods
  protected: virtual bool parseLexicalToken (void) = 0 ;

//--- Execution array built during first pass, and used by second pass parsing
  private: TC_UniqueArray <int16_t> mArrayForSecondPassParsing ;
  private: int32_t mIndexForSecondPassParsing ;

//--- Latex string (for --mode=latex command line option)
  private: C_String mLatexOutputString ;
  private: int32_t mLatexNextCharacterToEnterIndex ;
  private: void generateLatexFile (void) ;
  private: void appendCharacterToLatexFile (const utf32 inUnicodeCharacter) ;
  protected: void enterDroppedTerminal (const int32_t inTerminalIndex) ;
  protected: void signalLexicalErrorInLatexOutput (void) ;
//--- Style name 
  protected: virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const = 0 ;
  protected: virtual C_String styleNameForIndex (const uint32_t inStyleIndex) const = 0 ;
} ;

//----------------------------------------------------------------------------------------------------------------------

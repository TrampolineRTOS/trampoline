//--------------------------------------------------------------------------------------------------
//
//  'Lexique' : an abstract lexique class ;                                                    
//  Galgas generated scanner classes inherit from this class.                                    
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1996, ..., 2023 Pierre Molinaro.
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

#include "Compiler.h"
#include "cProductionNameDescriptor.h"
#include "cTemplateDelimiter.h"
#include "C_galgas_io.h"

//--------------------------------------------------------------------------------------------------

class cIndexingDictionary ;

//--------------------------------------------------------------------------------------------------
//                 Top Down parsing utilities
//--------------------------------------------------------------------------------------------------

inline int32_t TOP_DOWN_TERMINAL (const int32_t inSymbol) { return inSymbol + 1 ; }

inline int32_t TOP_DOWN_NONTERMINAL (const int32_t inSymbol) { return - inSymbol - 1 ; }

inline int32_t TOP_DOWN_END_PRODUCTION (void) { return 0 ; }

//--------------------------------------------------------------------------------------------------
//                 Bottom Up parsing utilities
//--------------------------------------------------------------------------------------------------

inline int32_t BOTTOM_UP_SHIFT (const int32_t inSymbol) { return inSymbol + 2 ; }

inline int32_t BOTTOM_UP_REDUCE (const int32_t inSymbol) { return - inSymbol - 1 ; }

inline int32_t BOTTOM_UP_ACCEPT (void) { return 1 ; }

inline int32_t BOTTOM_UP_END (void) { return -1 ; }

//--------------------------------------------------------------------------------------------------
//                 Lexique class
//--------------------------------------------------------------------------------------------------

class Lexique : public Compiler {
//--- Constructors and destructor
  public: Lexique (Compiler * inCallerCompiler,
                   const String & inSourceFileName
                   COMMA_LOCATION_ARGS) ;

  public: Lexique (Compiler * inCallerCompiler,
                   const String & inSourceString,
                   const String & inStringForError
                   COMMA_LOCATION_ARGS) ;

  public: virtual ~Lexique (void) ;

//--- No copy
  private: Lexique (const Lexique &) = delete ;
  private: Lexique & operator = (const Lexique &) = delete ;

//--- Indexing
  public: void enterIndexing (const uint32_t inIndexingKind,
                              const char * inIndexedKeyPosfix) ;
  public: void enableIndexing (void) ;
  public: void generateIndexFile (void) ;
  protected: cIndexingDictionary * mIndexingDictionary ;

//--- Template String
  protected: int32_t findTemplateDelimiterIndex (const cTemplateDelimiter * inTemplateDelimiterArray,
                                                 const int32_t inTemplateDelimiterArrayLength) ;

//--- Token list
  private: cToken * mFirstToken ;
  private: cToken * mLastToken ;
  private: cToken * mCurrentTokenPtr ;
  protected: void enterTokenFromPointer (cToken * inToken) ;
  private: int32_t mLastSeparatorIndex ;
  public: void appendLastSeparatorTo (String & ioString) const ;

  protected: cToken * currentTokenPtr (LOCATION_ARGS) const {
    macroValidPointerThere (mCurrentTokenPtr) ;
    return mCurrentTokenPtr ;
  }

//--- Syntax directed translation : accessing current token
  public: virtual String separatorString (void) const ;
  public: String tokenString (void) const ;

//--- Current character
  protected: utf32 mCurrentChar ;

//--- Previous character
  protected: utf32 mPreviousChar ;
  public: inline utf32 previousChar (void) const {
    return mPreviousChar ;
  }

//--- Locations for current token (significant only during lexical analysis phase)
  protected: LocationInSource mTokenStartLocation ;
  protected: LocationInSource mTokenEndLocation ;

//--- Advance
  protected: void advance (void) ; // One character
  protected: void advance (const int32_t inCount) ; // Several characters

//--- For Debugging parser
  private: String mTriggerNonTerminalSymbolList ;
  private: uint16_t mDebugDepthCounter ;
  private: bool mDebugIsRunning ;

  public: void enterProduction (const char * inProductionName,
                                const char * inLabel,
                                const char * inTag) ;

  public: void didParseTerminal (const char * inTerminalName,
                                 const String & inValue) ;

  public: void exitProduction (void) ;

//--- Reset Scanner for performing second pass
  private: void resetForSecondPass (void) ;

//--- Handling parsing context (for parse ... rewind ... end parse ; instruction)
  public: ParsingContext parsingContext (void) const ;
  public: void setParsingContext (const ParsingContext & inContext) ;

//--- Internal error during bottom-up parsing
  public: void internalBottomUpParserError (LOCATION_ARGS) ;

//--- Handling lexical error
  protected: void unknownCharacterLexicalError (LOCATION_ARGS) ;

  public: void lexicalError (const String & inLexicalErrorMessage
                             COMMA_LOCATION_ARGS) ;

//--- Signal a lexical warning
  protected: void lexicalWarning (const String & messageAlerte COMMA_LOCATION_ARGS) ;

//--- Handling syntax error
  private: void parsingError (const TC_UniqueArray <int32_t> & inExpectedTerminalsArray,
                              const cToken * inPreviousTokenPtr,
                              const cToken * inCurrentTokenPtr,
                              const int32_t inCurrentTokenCode
                              COMMA_LOCATION_ARGS) ;

//--- Get message for terminal
  protected: virtual String getMessageForTerminal (const int32_t inTerminalSymbol) const = 0 ;

//--- Static method for searching a string in an ordered list
//    returns -1 if not found, and associated code if found
  protected: static int32_t searchInList (const String & inString,
                                          const C_unicode_lexique_table_entry * inTableArray,
                                          const int32_t inTableSize) ;

//--- Get Token String
  public: virtual String getCurrentTokenString (const cToken * inTokenPtr) const = 0 ;

//--- Lexical analysis methods
  public: void performLexicalAnalysis (void) ;

  protected: bool testForCharWithFunction (bool (*inFunction) (const utf32 inUnicodeCharacter)) ;

  protected: bool testForInputUTF32CharRange (const utf32 inLowerBound,
                                              const utf32 inHigherBound) ;

  protected: bool testForInputUTF32Char (const utf32 inTestCharacter) ;

  protected: bool testForInputUTF32String (const std::initializer_list <utf32> & inTestString,
                                           const bool inAdvanceOnMatch) ;

  protected: bool notTestForInputUTF32String (const std::initializer_list <utf32> & inTestString,
                                              const char * inEndOfFileErrorMessage
                                              COMMA_LOCATION_ARGS) ;

  protected: void lexicalLog (LOCATION_ARGS) ;

//--- Methods for parsing during second pass
  public: void acceptTerminal (const int32_t inExpectedTerminal COMMA_LOCATION_ARGS) ;
  public: int32_t nextProductionIndex (void) ;
  public: virtual int32_t terminalVocabularyCount (void) const = 0 ;

//--- Perform top down parsing (called by LL (1) parser)
  public: bool performTopDownParsing (const int32_t * inProductionArray,
                                      const cProductionNameDescriptor * inProductionNameArray,
                                      const int32_t * inProductionIndexnArray,
                                      const int32_t * inFirstProductionIndexArray,
                                      const int32_t * inDecisionTableArray,
                                      const int32_t * inDecisionTableIndexArray,
                                      const int32_t inProgramCounterInitialValue) ;

  private: void buildExpectedTerminalsArrayOnSyntaxError (const int32_t inErrorProgramCounter,
                                                          const int32_t inErrorStackCount,
                                                          const TC_Array <int32_t> & inCurrentStack,
                                                          const TC_Array <int32_t> & inErrorStack,
                                                          const int32_t * inProductionArray,
                                                          const int32_t * inProductionIndexArray,
                                                          const int32_t * inFirstProductionIndexArray,
                                                          const int32_t * inDecisionTableArray,
                                                          const int32_t * inDecisionTableIndexArray,
                                                          TC_UniqueArray <int32_t> & outExpectedTerminalsArray) ;

  private: bool acceptTerminalForErrorSignaling (const int32_t inTerminal,
                                                 const int32_t * inProductionArray,
                                                 const int32_t * inProductionIndexArray,
                                                 const int32_t * inFirstProductionIndexArray,
                                                 const int32_t * inDecisionTableArray,
                                                 const int32_t * inDecisionTableIndexArray,
                                                 const TC_Array <int32_t> & inErrorStack,
                                                 const int32_t inErrorProgramCounter) ;

//--- Perform bottom up parsing (called by SLR and LR(1) parsers)
  public: bool performBottomUpParsing (const int32_t * inActionTableArray,
                                       const char * * inNonTerminalSymbolNameArray,
                                       const uint32_t * inActionTableIndexArray,
                                       const int32_t * * inSuccessorTableArray,
                                       const int32_t * inProductionsTableArray) ;

//--- Scanner pure virtual methods
  protected: virtual bool parseLexicalToken (void) = 0 ;

//--- Execution array built during first pass, and used by second pass parsing
  private: TC_UniqueArray <int32_t> mArrayForSecondPassParsing ;
  private: int32_t mIndexForSecondPassParsing ;

//--- Latex string (for --mode=latex command line option)
  private: String mLatexOutputString ;
  private: int32_t mLatexNextCharacterToEnterIndex ;
  private: void generateLatexFile (void) ;
  private: void appendCharacterToLatexFile (const utf32 inUnicodeCharacter) ;
  protected: void enterDroppedTerminal (const int32_t inTerminalIndex) ;
  protected: void signalLexicalErrorInLatexOutput (void) ;
//--- Style name 
  protected: virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const = 0 ;
  protected: virtual String styleNameForIndex (const uint32_t inStyleIndex) const = 0 ;
} ;

//--------------------------------------------------------------------------------------------------

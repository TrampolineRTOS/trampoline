//---------------------------------------------------------------------------*
//                                                                           *
//  'C_Lexique' : an abstract lexique class ;                                *
//  Galgas generated scanner classes inherit from this class.                *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1996, ..., 2010 Pierre Molinaro.                           *
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

#ifndef GALGAS_LEXIQUE_CLASS_DEFINED
#define GALGAS_LEXIQUE_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/C_Compiler.h"
#include "galgas2/cProductionNameDescriptor.h"
#include "galgas2/cTemplateDelimiter.h"
#include "galgas2/C_galgas_io.h"

//---------------------------------------------------------------------------*

class cIndexingDictionary ;

//---------------------------------------------------------------------------*
//                                                                           *
//                 Lexique class                                             *
//                                                                           *
//---------------------------------------------------------------------------*

class C_Lexique : public C_Compiler {
//--- Constructors and destructor
  public : C_Lexique (C_Compiler * inCallerCompiler,
                      const C_String & inDependencyFileExtension,
                      const C_String & inDependencyFilePath,
                      const C_String & inSourceFileName
                      COMMA_LOCATION_ARGS) ;

  public : C_Lexique (C_Compiler * inCallerCompiler,
                      const C_String & inSourceString,
                      const C_String & inStringForError
                      COMMA_LOCATION_ARGS) ;

  public : virtual ~C_Lexique (void) ;

//--- No copy
  private : C_Lexique (const C_Lexique &) ;
  private : C_Lexique & operator = (const C_Lexique &) ;

//--- Indexing
  public : void enterIndexing (const PMUInt32 inIndexingKind) ;
  public : void enableIndexing (void) ;
  public : void generateIndexFile (void) ;
  protected : cIndexingDictionary * mIndexingDictionary ;

//--- Indexing directory
  protected : virtual C_String indexingDirectory (void) const = 0 ;

//--- Template String
  protected : PMSInt32 findTemplateDelimiterIndex (const cTemplateDelimiter inTemplateDelimiterArray [],
                                                   const PMSInt32 inTemplateDelimiterArrayLength) ;
  
//--- Token list
  private : cToken * mFirstToken ;
  private : cToken * mLastToken ;
  protected : cToken * mCurrentTokenPtr ;
  protected : void enterTokenFromPointer (cToken * inToken) ;

//--- Current character
  protected : utf32 mCurrentChar ;

//--- Previous character
  protected : utf32 mPreviousChar ;
  public : inline utf32 previousChar (void) const {
    return mPreviousChar ;
  }

//--- Locations for current token (significant only during lexical analysis phase)
  protected : C_LocationInSource mTokenStartLocation ;
  protected : C_LocationInSource mTokenEndLocation ;

//--- Advance
  protected : void advance (void) ; // One character
  protected : void advance (const PMSInt32 inCount) ; // Several characters

//--- For Debugging parser
  private : C_String mTriggerNonTerminalSymbolList ;
  private : PMUInt16 mDebugDepthCounter ;
  private : bool mDebugIsRunning ;

  public : void enterProduction (const char * inProductionName,
                                 const char * inLabel,
                                 const char * inTag) ;

  public : void didParseTerminal (const char * inTerminalName,
                                  const C_String & inValue) ;

  public : void exitProduction (void) ;

//--- Protected attribute used for handling lexical loops
//    (in parseLexicalToken methods in inherited classes)
  protected : bool mLoop ;

//--- Reset Scanner for performing second pass
  private : void resetForSecondPass (void) ;

//--- Handling parsing context (for parse ... rewind ... end parse ; instruction)
  public : C_parsingContext parsingContext (void) const ;
  public : void setParsingContext (const C_parsingContext & inContext) ;

//--- Internal error during bottom-up parsing
  public : void internalBottomUpParserError (LOCATION_ARGS) ;

//--- Handling lexical error
  protected : void unknownCharacterLexicalError (LOCATION_ARGS) ;

  public : void lexicalError (const C_String & inLexicalErrorMessage
                              COMMA_LOCATION_ARGS) ;

  public : void lexicalErrorAtLocation (const C_String & inLexicalErrorMessage,
                                        const C_LocationInSource & inErrorLocation
                                        COMMA_LOCATION_ARGS) ;

//--- Signal a lexical warning
  protected : void lexicalWarning (const C_String & messageAlerte COMMA_LOCATION_ARGS) ;

//--- Handling syntax error
  protected : void parsingError (const TC_UniqueArray <PMSInt16> & inExpectedTerminalsArray,
                                 const PMSInt16 inCurrentTokenCode
                                 COMMA_LOCATION_ARGS) ;

  protected : virtual void appendTerminalMessageToSyntaxErrorMessage (const PMSInt16 inTerminalSymbol,
                                                                      C_String & ioErrorMessage) = 0 ;

//--- Static method for searching a string in an ordered list
//    returns -1 if not found, and associated code if found
  protected : static PMSInt16 searchInList (const C_String & inString,
                                            const C_unicode_lexique_table_entry inTable [],
                                            const PMSInt16 inTableSize) ;

//--- Get Token String
  public : virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const = 0 ;

//--- Lexical analysis methods
  protected : void performLexicalAnalysis (void) ;

  protected : bool testForCharWithFunction (bool (*inFunction) (const utf32 inUnicodeCharacter)) ;

  protected : bool testForInputUTF32CharRange (const utf32 inLowerBound,
                                               const utf32 inHigherBound) ;

  protected : bool testForInputUTF32Char (const utf32 inTestCharacter) ;

  protected : bool testForInputUTF32String (const utf32 * inTestString,
                                            const PMSInt32 inStringLength,
                                            const bool inAdvanceOnMatch) ;

  protected : bool notTestForInputUTF32String (const utf32 * inTestString,
                                               const PMSInt32 inStringLength,
                                               const utf32 * inEndOfFileErrorMessage
                                               COMMA_LOCATION_ARGS) ;

  protected : void lexicalLog (LOCATION_ARGS) ;

//--- Methods for parsing during second pass
  public : void acceptTerminal (FORMAL_ARG_ACCEPT_TERMINAL COMMA_LOCATION_ARGS) ;
  public : PMSInt16 nextProductionIndex (void) ;
  public : virtual PMSInt16 terminalVocabularyCount (void) const = 0 ;

//--- Perform top down parsing (called by LL (1) parser)
  public : bool performTopDownParsing (const PMSInt16 inProductions [],
                                       const cProductionNameDescriptor inProductionNames [],
                                       const PMSInt16 inProductionIndexes [],
                                       const PMSInt16 inFirstProductionIndex [],
                                       const PMSInt16 inDecisionTable [],
                                       const PMSInt16 inDecisionTableIndexes [],
                                       const PMSInt16 inProgramCounterInitialValue) ;

  private : void buildExpectedTerminalsArrayOnSyntaxError (const PMSInt16 inErrorProgramCounter,
                                                           const PMSInt32 inErrorStackCount,
                                                           const TC_Array <PMSInt16> & inCurrentStack,
                                                           const TC_Array <PMSInt16> & inErrorStack,
                                                           const PMSInt16 inProductions [],
                                                           const PMSInt16 inProductionIndexes [],
                                                           const PMSInt16 inFirstProductionIndex [],
                                                           const PMSInt16 inDecisionTable [],
                                                           const PMSInt16 inDecisionTableIndexes [],
                                                           TC_UniqueArray <PMSInt16> & outExpectedTerminalsArray) ;

  private : bool acceptTerminalForErrorSignaling (const PMSInt16 inTerminal,
                                                  const PMSInt16 inProductions [],
                                                  const PMSInt16 inProductionIndexes [],
                                                  const PMSInt16 inFirstProductionIndex [],
                                                  const PMSInt16 inDecisionTable [],
                                                  const PMSInt16 inDecisionTableIndexes [],
                                                  const TC_Array <PMSInt16> & inErrorStack,
                                                  const PMSInt16 inErrorProgramCounter) ;

//--- Perform bottom up parsing (called by SLR and LR(1) parsers)
  public : bool performBottomUpParsing (const PMSInt16 inActionTable [],
                                        const char * inNonTerminalSymbolNames [],
                                        const PMUInt32 inActionTableIndex [],
                                        const PMSInt16 * inSuccessorTable [],
                                        const PMSInt16 inProductionsTable []) ;

//--- Scanner pure virtual methods
  protected : virtual bool parseLexicalToken (void) = 0 ;

//--- Execution array built during first pass, and used by second pass parsing
  private : TC_UniqueArray <PMSInt16> mArrayForSecondPassParsing ;
  private : PMSInt32 mIndexForSecondPassParsing ;
} ;

//---------------------------------------------------------------------------*

#endif

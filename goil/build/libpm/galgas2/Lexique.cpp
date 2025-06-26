//--------------------------------------------------------------------------------------------------
//
//  'Lexique' : an abstract lexique class ;
//  Galgas generated scanner classes inherit from this class.
//
//  This file is part of libpm library
//
//  Copyright (C) 1996, ..., 2024 Pierre Molinaro.
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

#include "Lexique.h"
#include "all-predefined-types.h"
#include "MF_MemoryControl.h"
#include "unicode_character_cpp.h"
#include "C_galgas_CLI_Options.h"
#include "cIndexingDictionary.h"
#include "FileManager.h"
#include "F_verbose_output.h"

//--------------------------------------------------------------------------------------------------

#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors, Destructor
#endif

//--------------------------------------------------------------------------------------------------

cTemplateDelimiter::cTemplateDelimiter (const std::initializer_list <utf32> & inStartString,
    const int32_t inStartStringLength,
    const std::initializer_list <utf32> & inEndString,
    const int32_t inEndStringLength,
    void (* inReplacementFunction) (Lexique & inLexique, const String & inElementString, String & ioTemplateString),
    const bool inDiscardStartString) :
mStartString (inStartString),
mStartStringLength (inStartStringLength),
mEndString (inEndString),
mEndStringLength (inEndStringLength),
mReplacementFunction (inReplacementFunction),
mDiscardStartString (inDiscardStartString) {
}

//--------------------------------------------------------------------------------------------------

cTemplateDelimiter::cTemplateDelimiter (const cTemplateDelimiter & inOperand) :
mStartString (inOperand.mStartString),
mStartStringLength (inOperand.mStartStringLength),
mEndString (inOperand.mEndString),
mEndStringLength (inOperand.mEndStringLength),
mReplacementFunction (inOperand.mReplacementFunction),
mDiscardStartString (inOperand.mDiscardStartString) {
}

//--------------------------------------------------------------------------------------------------

Lexique::Lexique (Compiler * inCallerCompiler,
                  const String & inSourceFileName
                  COMMA_LOCATION_ARGS) :
Compiler (inCallerCompiler COMMA_THERE),
mIndexingDictionary (nullptr),
mFirstToken (nullptr),
mLastToken (nullptr),
mCurrentTokenPtr (nullptr),
mLastSeparatorIndex (0),
mCurrentChar (TO_UNICODE ('\0')),
mPreviousChar (TO_UNICODE ('\0')),
mTokenStartLocation (),
mTokenEndLocation (),
mTriggerNonTerminalSymbolList (),
mDebugDepthCounter (0),
mDebugIsRunning (false),
mArrayForSecondPassParsing (),
mIndexForSecondPassParsing (0),
mLatexOutputString (),
mLatexNextCharacterToEnterIndex (0) {
//---
  if (inSourceFileName.length () > 0) {
    logFileRead (inSourceFileName) ;
    bool ok = false ;
    PMTextFileEncoding textFileEncoding ;
    const String sourceString = FileManager::stringWithContentOfFile (inSourceFileName, textFileEncoding, ok) ;
    if (ok) {
      const SourceTextInString source (sourceString,
                                         inSourceFileName,
                                         false) ; // Do not print source string
      resetAndLoadSourceFromText (source) ;
      mTokenStartLocation.resetWithSourceText (source) ;
      mTokenEndLocation.resetWithSourceText (source) ;
    }else if (inCallerCompiler != nullptr) {
      String errorMessage = "cannot read '" ;
      errorMessage.appendString (inSourceFileName) ;
      errorMessage.appendCString ("': this file does not exist or is not encoded in UTF8") ;
      inCallerCompiler->onTheFlyRunTimeError (errorMessage COMMA_THERE)  ;
    }
  }
  mCurrentChar = sourceText ().readCharOrNul (0 COMMA_HERE) ;
}

//--------------------------------------------------------------------------------------------------

Lexique::Lexique (Compiler * inCallerCompiler,
                  const String & inSourceString,
                  const String & inStringForError
                  COMMA_LOCATION_ARGS) :
Compiler (inCallerCompiler COMMA_THERE),
mIndexingDictionary (nullptr),
mFirstToken (nullptr),
mLastToken (nullptr),
mCurrentTokenPtr (nullptr),
mLastSeparatorIndex (0),
mCurrentChar (TO_UNICODE ('\0')),
mPreviousChar (TO_UNICODE ('\0')),
mTokenStartLocation (),
mTokenEndLocation (),
mTriggerNonTerminalSymbolList (),
mDebugDepthCounter (0),
mDebugIsRunning (false),
mArrayForSecondPassParsing (),
mIndexForSecondPassParsing (0),
mLatexOutputString (),
mLatexNextCharacterToEnterIndex (0) {
  const SourceTextInString source (inSourceString, inStringForError, verboseOutput ()) ;
  resetAndLoadSourceFromText (source) ;
  mTokenStartLocation.resetWithSourceText (source) ;
  mTokenEndLocation.resetWithSourceText (source) ;
  mCurrentChar = sourceText ().readCharOrNul (0 COMMA_HERE) ;
}

//--------------------------------------------------------------------------------------------------

Lexique::~Lexique (void) {
  macroMyDelete (mIndexingDictionary) ;
  mLastToken = nullptr ;
  mCurrentTokenPtr = nullptr ;
  while (mFirstToken != nullptr) {
    cToken * p = mFirstToken->mNextToken ;
    macroMyDelete (mFirstToken) ;
    mFirstToken = p ;
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Scanner configuration
#endif

//--------------------------------------------------------------------------------------------------

void Lexique::appendLastSeparatorTo (String & ioString) const {
  if (nullptr != mLastToken) {
    const int32_t lastSeparatorStart = mLastToken->mEndLocation.index () + 1 ;
    const String lastSeparatorString = sourceText ().sourceString ().subStringFromIndex (lastSeparatorStart) ;
    ioString.appendString (lastSeparatorString) ;
  }
}

//--------------------------------------------------------------------------------------------------

void Lexique::enterTokenFromPointer (cToken * inToken) {
  macroValidPointer (inToken) ;
//--- Append separator and comments
  const int32_t tokenStart = mTokenStartLocation.index () ;
  if (tokenStart > mLastSeparatorIndex) {
    const String sep = sourceText ().sourceString ().subString (mLastSeparatorIndex, tokenStart -mLastSeparatorIndex) ;
    inToken->mSeparatorStringBeforeToken.appendString (sep) ;
  }
  mLastSeparatorIndex = mTokenEndLocation.index () + 1 ;
//--- Enter token in token list
  if (mLastToken == nullptr) {
    mFirstToken = inToken ;
  }else{
    mLastToken->mNextToken = inToken ;
  }
  mLastToken = inToken ;
//---
  if (executionModeIsLexicalAnalysisOnly ()) {
    String s ;
    for (int32_t i=inToken->mStartLocation.index () ; i<=inToken->mEndLocation.index () ; i++) {
      const utf32 c = sourceText ().readCharOrNul (i COMMA_HERE) ;
      if (UNICODE_VALUE (c) != '\0') {
        s.appendChar (c) ;
      }
    }
    gCout.appendCString ("  ") ;
    gCout.appendString (getCurrentTokenString (inToken)) ;
    gCout.appendCString (", from location ") ;
    gCout.appendSigned (inToken->mStartLocation.index ()) ;
    gCout.appendCString (" (line ") ;
    gCout.appendSigned (inToken->mStartLocation.lineNumber ()) ;
    gCout.appendCString (", column ") ;
    gCout.appendSigned (inToken->mStartLocation.columnNumber ()) ;
    gCout.appendCString (")") ;
    gCout.appendCString (" to location ") ;
    gCout.appendSigned (inToken->mEndLocation.index ()) ;
    gCout.appendCString (" (line ") ;
    gCout.appendSigned (inToken->mEndLocation.lineNumber ()) ;
    gCout.appendCString (", column ") ;
    gCout.appendSigned (inToken->mEndLocation.columnNumber ()) ;
    gCout.appendCString (")") ;
    if (inToken->mTemplateStringBeforeToken.length () > 0) {
      gCout.appendCString (", template '") ;
      gCout.appendString (inToken->mTemplateStringBeforeToken) ;
      gCout.appendCString ("'") ;
    }
    gCout.appendNewLine () ; ;
  }else if (executionModeIsLatex ()) {
    while (mLatexNextCharacterToEnterIndex < inToken->mStartLocation.index ()) {
      const utf32 c = sourceText ().readCharOrNul (mLatexNextCharacterToEnterIndex COMMA_HERE) ;
      appendCharacterToLatexFile (c) ;
      mLatexNextCharacterToEnterIndex += 1 ;
    }
    const String styleName = styleNameForIndex (styleIndexForTerminal (inToken->mTokenCode)) ;
    if (styleName.length () > 0) {
      mLatexOutputString.appendCString ("\\") ;
      mLatexOutputString.appendString (styleName) ;
      mLatexOutputString.appendString (latexModeStyleSuffixString ()) ;
      mLatexOutputString.appendCString ("{") ;
    }
    for (int32_t i=inToken->mStartLocation.index () ; i<=inToken->mEndLocation.index () ; i++) {
      const utf32 c = sourceText ().readCharOrNul (i COMMA_HERE) ;
      if (UNICODE_VALUE (c) != '\0') {
        appendCharacterToLatexFile (c) ;
      }
    }
    if (styleName.length () > 0) {
      mLatexOutputString.appendCString ("}") ;
    }
  //---
    mLatexNextCharacterToEnterIndex = inToken->mEndLocation.index () + 1 ;
  }
}

//--------------------------------------------------------------------------------------------------

void Lexique::resetForSecondPass (void) {
  mCurrentLocation.resetWithSourceText (sourceText ()) ;
  mCurrentChar = sourceText ().readCharOrNul (0 COMMA_HERE) ;
  mPreviousChar = TO_UNICODE ('\0') ;
  mCurrentTokenPtr = mFirstToken ;
  if (mCurrentTokenPtr != nullptr) {
    mStartLocationForHere = mCurrentTokenPtr->mStartLocation ;
    mEndLocationForHere = mCurrentTokenPtr->mEndLocation ;
    mStartLocationForNext = mCurrentTokenPtr->mStartLocation ;
    mEndLocationForNext = mCurrentTokenPtr->mEndLocation ;
    mTemplateString.appendString (mCurrentTokenPtr->mTemplateStringBeforeToken) ;
    mCurrentLocation = mCurrentTokenPtr->mEndLocation ;
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Template Delimiter Scanning
#endif

//--------------------------------------------------------------------------------------------------

int32_t Lexique::findTemplateDelimiterIndex (const cTemplateDelimiter * inTemplateDelimiterArray,
                                             const int32_t inTemplateDelimiterArrayLength) {
  int32_t templateIndex = 0 ;
  bool found = false ;

  while ((templateIndex < inTemplateDelimiterArrayLength) && ! found) {
    found = testForInputUTF32String (inTemplateDelimiterArray [templateIndex].mStartString,
                                     inTemplateDelimiterArray [templateIndex].mDiscardStartString) ;
    templateIndex += 1 ;
  }
  templateIndex -= 1 ;
  if (! found) {
    templateIndex = -1 ;
  }
  return templateIndex ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Lexical Analysis
#endif

//--------------------------------------------------------------------------------------------------
//
//   performLexicalAnalysis
//
//--------------------------------------------------------------------------------------------------

void Lexique::performLexicalAnalysis (void) {
  if (executionModeIsLexicalAnalysisOnly ()) {
    gCout.appendCString ("*** PERFORM LEXICAL ANALYSIS ONLY (--mode=lexical-only option) ***\n") ;
  }
  bool loop = true ;
  while (loop) {
    loop = parseLexicalToken () ;
  }
  if (executionModeIsLexicalAnalysisOnly ()) {
    gCout.appendCString ("*** END OF LEXICAL ANALYSIS ***\n") ;
  }else if (executionModeIsLatex ()) {
    generateLatexFile () ;
  }
}

//--------------------------------------------------------------------------------------------------
//
//        Methods for scanning
//
//--------------------------------------------------------------------------------------------------

void Lexique::advance (void) {
  mTokenEndLocation = mCurrentLocation ;
  mPreviousChar = mCurrentChar ;
  if (UNICODE_VALUE (mCurrentChar) != '\0') {
    mCurrentLocation.gotoNextLocation () ;
    mCurrentChar = sourceText ().readCharOrNul (mCurrentLocation.index () COMMA_HERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

void Lexique::advance (const int32_t inCount) {
  for (int32_t i=0 ; i<inCount ; i++) {
    advance () ;
  }
}

//--------------------------------------------------------------------------------------------------

bool Lexique::testForInputUTF32CharRange (const utf32 inLowBound,
                                          const utf32 inHighBound) {
  const bool ok = (UNICODE_VALUE (inLowBound) <= UNICODE_VALUE (mCurrentChar))
     && (UNICODE_VALUE (mCurrentChar) <= UNICODE_VALUE (inHighBound)) ;
  if (ok) {
    advance () ;
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

bool Lexique::testForInputUTF32Char (const utf32 inChar) {
  const bool ok = UNICODE_VALUE (inChar) == UNICODE_VALUE (mCurrentChar) ;
  if (ok) {
    advance () ;
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

bool Lexique::testForCharWithFunction (bool (*inFunction) (const utf32 inUnicodeCharacter)) {
  const bool ok = inFunction (mCurrentChar) ;
  if (ok) {
    advance () ;
  }
  return ok ;
}

//--------------------------------------------------------------------------------------------------

bool Lexique::testForInputUTF32String (const std::initializer_list <utf32> & inTestCstring,
                                       const bool inAdvanceOnMatch) {
//--- Test
  bool ok = true ;
  int32_t i = 0 ;
  for (auto it = inTestCstring.begin () ; (it != inTestCstring.end ()) && ok ; it++) {
    ok = UNICODE_VALUE (sourceText ().readCharOrNul (mCurrentLocation.index () + i COMMA_HERE)) == UNICODE_VALUE (* it) ;
    i += 1 ;
  }
//--- Avancer dans la lecture si test ok et fin de source non atteinte
  if (ok && inAdvanceOnMatch) {
    advance (int32_t (inTestCstring.size ())) ;
  }
//---
  return ok ;
}

//--------------------------------------------------------------------------------------------------

bool Lexique::notTestForInputUTF32String (const std::initializer_list <utf32> & inTestCstring,
                                          const char * inEndOfFileErrorMessage
                                          COMMA_LOCATION_ARGS) {
  bool ok = UNICODE_VALUE (sourceText ().readCharOrNul (mCurrentLocation.index () COMMA_HERE)) != '\0' ;
  if (! ok) { // End of input file reached
    lexicalError (inEndOfFileErrorMessage COMMA_THERE) ;
  }else{
  //--- Test
    ok = false ;
    int32_t i = 0 ;
    for (auto it = inTestCstring.begin () ; (it != inTestCstring.end ()) && ! ok ; it++) {
      ok = UNICODE_VALUE (sourceText ().readCharOrNul (mCurrentLocation.index () + i COMMA_HERE)) != UNICODE_VALUE (* it) ;
      i += 1 ;
    }
    if (ok) {
      advance () ;
    }else{
      advance (int32_t (inTestCstring.size ())) ;
    }
  }
//---
  return ok ;
}

//--------------------------------------------------------------------------------------------------

void Lexique::lexicalLog (LOCATION_ARGS) {
  String message ;
  message.appendCString ("LEXICAL LOG:'") ;
  message.appendStringAsCLiteralCharConstant (mCurrentChar) ;
  message.appendCString ("'\n") ;
  printMessage (message COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------
//
//    Search in an ordered list (used for searching into scanner generated tables)
//
//--------------------------------------------------------------------------------------------------

int32_t Lexique::searchInList (const String & inString,
                               const C_unicode_lexique_table_entry * inTableArray,
                               const int32_t inTableSize) {
  const int32_t searchedStringLength = inString.length () ;
  int32_t code = -1 ; // -1 means 'not found'
  int32_t bottom = 0 ;
  int32_t top = inTableSize - 1 ;

  while ((code < 0) && (top >= bottom)) {
    const int32_t index = (bottom + top) / 2 ;
    int32_t result = searchedStringLength - int32_t (inTableArray [index].mEntryString.size ()) ;
    if (result == 0) {
      result = inString.compareWithInitializerList (inTableArray [index].mEntryString) ;
    }
    if (result < 0) { // <
      top = index - 1 ;
    }else if (result > 0) { // >
      bottom = index + 1 ;
    }else{
      code = inTableArray [index].mTokenCode ;
    }
  }
  return code ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Handling an error
#endif

//--------------------------------------------------------------------------------------------------

void Lexique::internalBottomUpParserError (LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    printf ("*** Fatal error: Internal bottom-up parser error at line %d of file '%s'.\n", IN_SOURCE_LINE, IN_SOURCE_FILE) ;
  #else
    printf ("*** Fatal error: Internal bottom-up parser error.\n") ;
  #endif
  exit (1) ;
}

//--------------------------------------------------------------------------------------------------
//
//           Lexical error
//
//--------------------------------------------------------------------------------------------------

void Lexique::unknownCharacterLexicalError (LOCATION_ARGS) {
  String errorMessage ;
  errorMessage.appendCString ("Unknown character: ") ;
  errorMessage.appendString (unicodeName (mCurrentChar)) ;
  errorMessage.appendCString (" (Unicode ") ;
  errorMessage.appendUnsigned0xHex (UNICODE_VALUE (mCurrentChar)) ;
  errorMessage.appendCString (")") ;
  lexicalError (errorMessage COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void Lexique::lexicalError (const String & inLexicalErrorMessage
                            COMMA_LOCATION_ARGS) {
  signalLexicalError (this, sourceText (), C_IssueWithFixIt (mCurrentLocation, mCurrentLocation, TC_Array <C_FixItDescription> ()), inLexicalErrorMessage COMMA_THERE) ;
  if (executionModeIsLatex ()) {
    signalLexicalErrorInLatexOutput () ;
  }
  throw C_lexicalErrorException () ;
}

//--------------------------------------------------------------------------------------------------
//
//                Signaler une erreur syntaxique
//
//--------------------------------------------------------------------------------------------------

void Lexique::parsingError (const TC_UniqueArray <int32_t> & inExpectedTerminalsArray,
                            const cToken * inPreviousTokenPtr,
                            const cToken * inCurrentTokenPtr,
                            const int32_t inCurrentTokenCode
                            COMMA_LOCATION_ARGS) {
//--- Build error message
  String foundTokenMessage = getMessageForTerminal (inCurrentTokenCode) ;
  const int32_t expectedTerminalsCount = inExpectedTerminalsArray.count () ;
  TC_UniqueArray <String> expectedTokenNames (expectedTerminalsCount, String () COMMA_HERE) ;
  for (int32_t i=0 ; i<expectedTerminalsCount ; i++) {
    expectedTokenNames (i COMMA_HERE) = getMessageForTerminal (inExpectedTerminalsArray (i COMMA_HERE)) ;
  }
//--- Sort expected token name array
  expectedTokenNames.sortArrayUsingCompareMethod () ;
//--- Signal error
  signalParsingError (
    this,
    sourceText (),
    (inPreviousTokenPtr == nullptr) ? LocationInSource () : inPreviousTokenPtr->mEndLocation,
    C_IssueWithFixIt (inCurrentTokenPtr->mStartLocation, inCurrentTokenPtr->mEndLocation, TC_Array <C_FixItDescription> ()),
    foundTokenMessage,
    expectedTokenNames
    COMMA_THERE
  ) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Scanner warning
#endif

//--------------------------------------------------------------------------------------------------

void Lexique::lexicalWarning (const String & inLexicalWarningMessage
                              COMMA_LOCATION_ARGS) {
  signalLexicalWarning (
    this,
    sourceText (),
    C_IssueWithFixIt (mCurrentLocation, mCurrentLocation, TC_Array <C_FixItDescription> ()),
    inLexicalWarningMessage
    COMMA_THERE
  ) ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Second pass methods
#endif

//--------------------------------------------------------------------------------------------------
//
//                         Get next production index
//
//--------------------------------------------------------------------------------------------------

int32_t Lexique::nextProductionIndex (void) {
  int32_t result = 0 ;
  if (mIndexForSecondPassParsing < mArrayForSecondPassParsing.count ()) {
    result = mArrayForSecondPassParsing (mIndexForSecondPassParsing COMMA_HERE) ;
    mIndexForSecondPassParsing += 1 ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String Lexique::separatorString (void) const {
  String result ;
  if (mCurrentTokenPtr != nullptr) {
    result = mCurrentTokenPtr->mSeparatorStringBeforeToken ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

String Lexique::tokenString (void) const {
  String result ;
  if (mCurrentTokenPtr != nullptr) {
    const int32_t tokenStart = mCurrentTokenPtr->mStartLocation.index () ;
    const int32_t tokenLength = mCurrentTokenPtr->mEndLocation.index () - tokenStart + 1 ;
    result = sourceText ().sourceString ().subString (tokenStart, tokenLength) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//   Accept current token by shifting it
//
//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define IN_EXPECTED_TERMINAL inExpectedTerminal
#else
  #define IN_EXPECTED_TERMINAL
#endif

//--------------------------------------------------------------------------------------------------

void Lexique::acceptTerminal (const int32_t IN_EXPECTED_TERMINAL
                              COMMA_LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    int32_t currentTokenCode = 0 ;
  #endif
  if (mCurrentTokenPtr != nullptr) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      currentTokenCode = mCurrentTokenPtr->mTokenCode ;
    #endif
    mStartLocationForHere = mCurrentTokenPtr->mStartLocation ;
    mEndLocationForHere = mCurrentTokenPtr->mEndLocation ;
    mCurrentTokenPtr = mCurrentTokenPtr->mNextToken ;
    if (mCurrentTokenPtr != nullptr) {
      macroValidPointer (mCurrentTokenPtr) ;
      mStartLocationForNext = mCurrentTokenPtr->mStartLocation ;
      mEndLocationForNext = mCurrentTokenPtr->mEndLocation ;
      mTemplateString.appendString (mCurrentTokenPtr->mTemplateStringBeforeToken) ;
      mTemplateStringLocation = mCurrentTokenPtr->mStartLocation ;
      mCurrentLocation = mCurrentTokenPtr->mEndLocation ;
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    if (currentTokenCode != inExpectedTerminal) {
      const String currentTokenString = getMessageForTerminal (currentTokenCode) ;
      const String expectedTokenString = getMessageForTerminal (inExpectedTerminal) ;
      macroAssertThere (false,
                      "Internal second pass parsing error (current token:%s, expected token:%s)",
                      (intptr_t) currentTokenString.cString (),
                      (intptr_t) expectedTokenString.cString ()) ;
    }
  #endif
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Indexing
#endif

//--------------------------------------------------------------------------------------------------

void Lexique::enterIndexing (const uint32_t inIndexingKind,
                             const char * inIndexedKeyPosfix) {
  if ((nullptr != mIndexingDictionary) && (sourceText ().sourceFilePath ().length () > 0)) {
    const uint32_t tokenStartLocation = (uint32_t) mCurrentTokenPtr->mStartLocation.index () ;
    const uint32_t tokenLine = (uint32_t) mCurrentTokenPtr->mStartLocation.lineNumber () ;
    const uint32_t tokenLength  = ((uint32_t) mCurrentTokenPtr->mEndLocation.index ()) - tokenStartLocation + 1 ;
    String indexedKey = sourceText ().sourceString ().subString ((int32_t) tokenStartLocation, (int32_t) tokenLength) + inIndexedKeyPosfix ;
    mIndexingDictionary->addIndexedKey (inIndexingKind,
                                        indexedKey,
                                        sourceText ().sourceFilePath (),
                                        tokenLine,
                                        tokenStartLocation,
                                        tokenLength) ;
  }
}

//--------------------------------------------------------------------------------------------------

void Lexique::enableIndexing (void) {
  macroMyNew (mIndexingDictionary, cIndexingDictionary) ;
}

//--------------------------------------------------------------------------------------------------

void Lexique::generateIndexFile (void) {
  if (nullptr != mIndexingDictionary) {
    mIndexingDictionary->generateIndexFile (indexingModeOutputFilePath ()) ;
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Handling Parsing context
#endif

//--------------------------------------------------------------------------------------------------

ParsingContext Lexique::parsingContext (void) const {
  ParsingContext context ;
  context.mParsingArrayIndex = mIndexForSecondPassParsing ;
  context.mLocation = mCurrentLocation ;
  context.mCurrentChar = mCurrentChar ;
  context.mPreviousChar = mPreviousChar ;
  context.mCurrentTokenPtr = mCurrentTokenPtr ;
  context.mTemplateString = mTemplateString ;
  return context ;
}

//--------------------------------------------------------------------------------------------------

void Lexique::setParsingContext (const ParsingContext & inContext) {
  mIndexForSecondPassParsing = inContext.mParsingArrayIndex ;
  mCurrentTokenPtr = inContext.mCurrentTokenPtr ;
  mCurrentLocation = inContext.mLocation ;
  mCurrentChar = inContext.mCurrentChar ;
  mPreviousChar = inContext.mPreviousChar ;
  mTemplateString = inContext.mTemplateString ;
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark For Debugging parser
#endif

//--------------------------------------------------------------------------------------------------
//
//  For Debugging parser
//
//--------------------------------------------------------------------------------------------------

void Lexique::enterProduction (const char * inProductionName,
                               const char * inLabel,
                               const char * inTag) {
//--- If Debug is not running, check if trigger list contains non terminal
  if (! mDebugIsRunning) {
    TC_UniqueArray <String> stringArray ;
    mTriggerNonTerminalSymbolList.componentsSeparatedByString (inProductionName, stringArray) ;
    mDebugIsRunning = stringArray.count () > 1 ;
  }
  if (mDebugIsRunning) {
    String message ;
    for (uint16_t i=1 ; i<mDebugDepthCounter ; i++) {
      message.appendCString ("|  ") ;
    }
    message.appendString ((mDebugDepthCounter > 0) ? "|- " : "") ;
    message.appendString (inProductionName) ;
    if (inLabel != nullptr) {
      message.appendCString (" label '") ;
      message.appendString (inLabel) ;
      message.appendCString ("'") ;
    }
    if ((inTag != nullptr) && (inTag [0] != '\0')) {
      message.appendCString (" tag '") ;
      message.appendString (inTag) ;
      message.appendCString ("'") ;
    }
    message.appendCString ("\n") ;
    ggs_printMessage (message COMMA_HERE) ;
    mDebugDepthCounter ++ ;
  }
}

//--------------------------------------------------------------------------------------------------

void Lexique::exitProduction (void) {
  if (mDebugIsRunning) {
    mDebugDepthCounter -- ;
    mDebugIsRunning = mDebugDepthCounter > 0 ;
  }
}

//--------------------------------------------------------------------------------------------------

void Lexique::didParseTerminal (const char * inTerminalName,
                                const String & inValue) {
  if (mDebugIsRunning) {
    String message ;
    for (uint16_t i=1 ; i<mDebugDepthCounter ; i++) {
      message.appendCString ("|  ") ;
    }
    message.appendString ((mDebugDepthCounter > 0) ? "|- " : "") ;
    message.appendString (inTerminalName) ;
    if (inValue.length () > 0) {
      message.appendString (inValue) ;
    }
    message.appendCString ("\n") ;
    ggs_printMessage (message COMMA_HERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Generate Latex file
#endif

//--------------------------------------------------------------------------------------------------

void Lexique::enterDroppedTerminal (const int32_t inTerminalIndex) {
  if (executionModeIsLatex ()) {
    while (mLatexNextCharacterToEnterIndex < mTokenStartLocation.index ()) {
      const utf32 c = sourceText ().readCharOrNul (mLatexNextCharacterToEnterIndex COMMA_HERE) ;
      appendCharacterToLatexFile (c) ;
      mLatexNextCharacterToEnterIndex += 1 ;
    }
    const String styleName = styleNameForIndex (styleIndexForTerminal (inTerminalIndex)) ;
    if (styleName.length () > 0) {
      mLatexOutputString.appendCString ("\\") ;
      mLatexOutputString.appendString (styleName) ;
      mLatexOutputString.appendString (latexModeStyleSuffixString ()) ;
      mLatexOutputString.appendCString ("{") ;
    }
    for (int32_t i=mTokenStartLocation.index () ; i<=mTokenEndLocation.index () ; i++) {
      const utf32 c = sourceText ().readCharOrNul (i COMMA_HERE) ;
      if (UNICODE_VALUE (c) != '\0') {
        appendCharacterToLatexFile (c) ;
      }
    }
    if (styleName.length () > 0) {
      mLatexOutputString.appendCString ("}") ;
    }
  //---
    mLatexNextCharacterToEnterIndex = mTokenEndLocation.index () + 1 ;
  }
}

//--------------------------------------------------------------------------------------------------

void Lexique::appendCharacterToLatexFile (const utf32 inUnicodeCharacter) {
  switch (UNICODE_VALUE (inUnicodeCharacter)) {
  case '>' : mLatexOutputString.appendCString ("\\textgreater{}") ; break ;
  case '<' : mLatexOutputString.appendCString ("\\textless{}") ; break ;
  case '~' : mLatexOutputString.appendCString ("$\\sim$") ; break ;
  case '^' : mLatexOutputString.appendCString ("$\\wedge$") ; break ;
  case '|' : mLatexOutputString.appendCString ("\\textbar{}") ; break ;
  case '&' : mLatexOutputString.appendCString ("\\&") ; break ;
  case '%' : mLatexOutputString.appendCString ("\\%") ; break ;
  case '#' : mLatexOutputString.appendCString ("\\#") ; break ;
  case '$' : mLatexOutputString.appendCString ("\\$") ; break ;
  case ' ' : mLatexOutputString.appendCString ("\\hspace*{.6em}") ; break ;
  case '\n' : mLatexOutputString.appendCString ("\\newline\n") ; break ;
  case '{' : mLatexOutputString.appendCString ("\\{") ; break ;
  case '}' : mLatexOutputString.appendCString ("\\}") ; break ;
  case '_' : mLatexOutputString.appendCString ("\\_") ; break ;
  case '\\' : mLatexOutputString.appendCString ("\\textbackslash{}")  ; break ;
  case '\'' : mLatexOutputString.appendCString ("\\textquotesingle{}") ; break ;
  case '"' : mLatexOutputString.appendCString ("\"") ; break ;
  default:
    mLatexOutputString.appendChar (inUnicodeCharacter) ;
    mLatexOutputString.appendCString ("{}") ;
    break ;
  }
}

//--------------------------------------------------------------------------------------------------

void Lexique::signalLexicalErrorInLatexOutput (void) {
  mLatexOutputString.appendCString ("\\lexicalError") ;
  mLatexOutputString.appendString (latexModeStyleSuffixString ()) ;
}

//--------------------------------------------------------------------------------------------------

void Lexique::generateLatexFile (void) {
  const String latexFilePath = sourceText ().sourceFilePath () + ".tex" ;
//--- Suppress last '\newline'
  const String newLine = "\\newline\n" ;
  if (mLatexOutputString.endsWithString (newLine)) {
    mLatexOutputString = mLatexOutputString.subString (0, mLatexOutputString.length () - newLine.length ()) ;
  }
  FileManager::writeStringToFile (mLatexOutputString, latexFilePath) ;
}

//--------------------------------------------------------------------------------------------------
